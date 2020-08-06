#include "PinConfig.h"

#include "AirSensor.h"
#include "AutoTouchboard.h"
#include "LightsUtils.h"
#include "SerialLeds.h"
#include "SerialProcessor.h"
#include "USBOutput.h"

#ifdef USE_DMA_RGB
  #include <WS2812Serial.h>
  #define USE_WS2812SERIAL
#endif

#include <FastLED.h>

SerialProcessor serialProcessor;

KeyState key_states[16];
#ifndef KEY_DIVIDERS
CRGB leds[16];
#else
CRGB leds[31]; 
#endif

// Buffer for receiving serial input, either lights or config updates
byte serialBuffer[200];
// Flag that says whether the RGB strip needs to be refreshed
bool updateLeds = false;
// Flag that says whether to let serial input control the RGB strip, or make them reactively lit
bool useSerialLeds = false;
// A counter for how many loops we've run without having received any serial light updates. If
// this counter reaches a pre-defined threshold, we fall back to reactive lighting
int serialLightsCounter;
// Used for benchmarking the input polling rate
long lastMillis = 0;
// Count how many times we updated input in the last second
int pollCount = 0;
// Keep track of the maximum polling rate we achieved
int maxPollCount = 0;
// Keep track of the minimum polling rate we achieved
int minPollCount = 1000;

// The colors to light the slider keys when they're on and off in reactive lighting mode
CRGB led_on;
CRGB led_off;
// The intensity of the lights in reactive lighting mode
float lightIntensity[16];

// Whether the controller is currently active. 
bool activated = true;

AutoTouchboard *touchboard;
AirSensor *sensor;
USBOutput *output;
SerialLeds *serialLeds;

void initializeController();

/**
 * Teensy setup. Initialize FastLED and start the timer for
 * determining if we're using serial light output.
 */
void setup() {
  Serial.begin(115200);
  #ifndef KEY_DIVIDERS
  
  FastLED.addLeds<LED_TYPE, RGBPIN, LED_ORDER>(leds, 16);
  #else
  //Uncomment and tune this value if you're having power issues
  FastLED.setBrightness(170);
  FastLED.addLeds<LED_TYPE, RGBPIN, LED_ORDER>(leds, 31);
  #endif

  // Uncomment this to clear EEPROM, flash once, then comment and re-flash
  // for(int i = 0; i < 128; i++) EEPROM.put(i, 0);
  
  initializeController();
  lastMillis = millis();
}

/**
 * Do the actual setup of our classes for input and output. This is broken
 * out into a separate function so that if we update any config values over
 * serial, everything can be re-initialized without needing a Teensy reboot.
 */
void initializeController() {
  // Flash LEDs orange 3 times
  for (int i = 0; i < 3; i++)
  {
    for (CRGB& led : leds)
      led = CRGB::Orange;
      
    FastLED.show();
    delay(1000);
    
    for (CRGB& led : leds)
      led = CRGB::Black;
      
    FastLED.show();
    delay(1000);
  }

  // Initialize and calibrate touch sensors
  if (touchboard != NULL) delete touchboard;
  touchboard = new AutoTouchboard();

  // Initialize the serial LED processor
  if (serialLeds != NULL) delete serialLeds;
  serialLeds = new SerialLeds();

  // Initialize the reactive lighting colors, and if they're not in EEPROM, save them
  byte lightsFlag;
  EEPROM.get(67, lightsFlag);

  if (lightsFlag == LIGHTS_FLAG) 
  {
    serialLeds->loadLights();
  } 
  else 
  {
    led_on = CRGB::Purple;
    led_off = CRGB::Yellow;
    serialLeds->saveLights();
  }

  // Initialize air sensor
  if (sensor != NULL) delete sensor;
  sensor = new AirSensor(1000, 200);

  // Display the number of air sensors that were calibrated
  for (CRGB& led : leds)
    led = CRGB::Black;
    
  for (int i = 0; i < 6; i++)
  {
    if (sensor->getSensorCalibrated(i))
#ifndef KEY_DIVIDERS
      leds[i] = CRGB::Green;
#else
      leds[i*2] = CRGB::Green;
#endif
    else
#ifndef KEY_DIVIDERS
      leds[i] = CRGB::Red;
#else
      leds[i*2] = CRGB::Red;
#endif
  }
  
  FastLED.show();
  delay(3000);
  serialLightsCounter = 0;

  // Initialize the USB output
  if (output != NULL) delete output;
  output = new USBOutput();
}

/**
 * Helps check the polling rate of the controller and benchmark its input.
 */
void checkPollRate() {
  pollCount++;
  
  if ((millis() - lastMillis) > 1000)
  {
    if (pollCount > maxPollCount)
      maxPollCount = pollCount;
    if (pollCount < minPollCount)
      minPollCount = pollCount;
      
    Serial.print(pollCount);
    Serial.print("\t");
    Serial.print(minPollCount);
    Serial.print("\t");
    Serial.println(maxPollCount);
    
    pollCount = 0;
    lastMillis = millis();
  }
}

/**
 * Main loop, checks all sensor states and updates the outputs as well as receive
 * serial packets for light and config updates.
 */
void loop() {
  // Uncomment this code to see benchmark in serial (in Hz)
  checkPollRate();
  
  // Check for serial messages
  if (Serial.available() >= 100)
  {
    Serial.readBytes(serialBuffer, 100);
    serialProcessor.processBulk(serialBuffer);
  }
  else 
  {
    serialLightsCounter++;  
  }

  // If currently paused through a config command, do not execute main loop
  if (!activated) 
    return;

  // If we haven't received any serial light updates in 5 seconds, just fallback to reactive lighting
  if (serialLightsCounter > 300) 
    useSerialLeds = false;

  // Process air sensor hand position
#if !defined(SERIAL_PLOT) && defined(USB)
#ifdef IR_SENSOR_KEY
    output->sendSensor(sensor->getSensorReadings());
#else
    output->sendSensorEvent(sensor->getHandPosition());
#endif
#endif

  // Scan touch keyboard and update lights
  touchboard->scan();
  int index = 0;
  
  for (int i = 0; i < 16; i++)
  {
#ifndef LED_REVERSE
    index = i;
#else
    index = 15 - i;
#endif

#if NUM_SENSORS == 16
    KeyState keyState = touchboard->update(i);
#elif NUM_SENSORS == 32
    KeyState stateTop = touchboard->update(i * 2);
    KeyState stateBot = touchboard->update(i * 2 + 1);
    KeyState keyState = (KeyState) stateTop + stateBot;
#endif

    // handle changing key colors for non-serial LED updates
    if (!useSerialLeds)
    {
      if (lightIntensity[index] > 0.05f)
        lightIntensity[index] -= 0.05f;
  
      // If the key is currently being held, set its color to the on color
      if (keyState == SINGLE_PRESS || keyState == DOUBLE_PRESS)
      {
        lightIntensity[index] = 1.0f;
#ifndef KEY_DIVIDERS
        leds[index].setRGB(min(led_on.r / 2 + led_on.r / 2 * lightIntensity[index], 255), min(led_on.g / 2 + led_on.g / 2 * lightIntensity[index], 255), min(led_on.b / 2 + led_on.b / 2 * lightIntensity[index], 255));
#else
        leds[index*2].setRGB(min(led_on.r / 2 + led_on.r / 2 * lightIntensity[index], 255), min(led_on.g / 2 + led_on.g / 2 * lightIntensity[index], 255), min(led_on.b / 2 + led_on.b / 2 * lightIntensity[index], 255));
#endif
      }
      else
      {
        // If not, make it the off color
#ifndef KEY_DIVIDERS
        leds[index].setRGB(led_off.r / 2, led_off.g / 2, led_off.b / 2);
#else
        leds[index*2].setRGB(led_off.r / 2, led_off.g / 2, led_off.b / 2);
#endif
      }

#ifdef KEY_DIVIDERS     
      lightIntensity[index] = 1.0f;
      leds[index*2-1].setRGB(min(led_on.r / 2 + led_on.r / 2 * lightIntensity[index], 255), min(led_on.g / 2 + led_on.g / 2 * lightIntensity[index], 255), min(led_on.b / 2 + led_on.b / 2 * lightIntensity[index], 255));
#endif

      updateLeds = true;  
    }
    // handle changing key colors for serial LED updates
    else 
    {
      if (updateLeds)
      {
        RGBLed temp = serialLeds->getKey(i);
#ifndef KEY_DIVIDERS
        leds[index].setRGB(temp.r, temp.g, temp.b);
#else
        leds[index*2].setRGB(temp.r, temp.g, temp.b);
        if (i < 15){
          temp = serialLeds->getDivider(i);
          index = LightsUtils::getDividerIndex(i);
          leds[index].setRGB(temp.r, temp.g, temp.b);
        }
#endif
      }
    }

#if !defined(SERIAL_PLOT) && defined(USB)
    if (key_states[i] != keyState)
      output->sendKeyEvent(i, keyState);
#endif

    key_states[i] = keyState;
  }

#ifdef SERIAL_PLOT
  if (PLOT_PIN == -1)
  {
    for (int i = 0; i < NUM_SENSORS; i++)
    {
#ifdef SERIAL_RAW_VALUES
      // Print values
      Serial.print(touchboard->getRawValue(i));
#else
      // Print normalized values
      Serial.print(touchboard->getRawValue(i) - touchboard->getNeutralValue(i));
#endif
      Serial.print("\t");
    }
    Serial.println();
  }
  else
  {
    Serial.print(touchboard->getRawValue(PLOT_PIN));
    Serial.println();
  }
#endif

  // Send update
#if !defined(SERIAL_PLOT) && defined(USB)
  output->sendUpdate();
#endif

  //#if defined(SERIAL_PLOT)
  //  Serial.print("\t");
  //  Serial.println(sensor->getSensorReadings());
  //#endif

  // If the air sensor is calibrated, update lights. The lights will stay red as long as the air sensor is not calibrated.
  if (sensor->isCalibrated() && updateLeds)
  {
    FastLED.show();
    updateLeds = false;
  }
}
