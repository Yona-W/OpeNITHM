#include "PinConfig.h"

#ifdef USB
#include "USBOutput.h"
#else
#include "SerialOutput.h"
#endif

#ifdef LED_SERIAL
#include "SerialLeds.h"
byte serialBuffer[200];
SerialLeds serialLeds;
#endif

#include "AirSensor.h"
#include "AutoTouchboard.h"
#include <FastLED.h>

KeyState key_states[16];
CRGB leds[16];
bool updateLeds = false;

CRGB led_on = CRGB::Purple;
CRGB led_off = CRGB::Yellow;

float lightIntensity[16];
bool activated = true;

AutoTouchboard *touchboard;
AirSensor *sensor;
Output *output;

char command[32];

void parseCommand()
{
  char input1 = Serial.read();
  char input2;
  int i;
  switch (input1)
  {
    case 't': // touchboard
      while (!Serial.available());
      input2 = Serial.read();
      switch (input2)
      {
        case 'c': // calibrate
          touchboard->calibrateKeys(true);
          break;
        case 'r': // print raw values
          Serial.println("Raw Values");
          for (i = 0; i < 16; i++)
          {
            Serial.print("Key: ");
            Serial.print(i);
            Serial.print("\t");
            Serial.println(touchboard->getRawValue(i));
          }
          break;
      }
      break;
    case 'i': // ir sensors
      while (!Serial.available());
      input2 = Serial.read();
      switch (input2)
      {
        case 'd': // dead zone
          sensor->setDeadzone(Serial.parseInt());
          break;
        case 'a': // alpha
          sensor->setAlpha(Serial.parseFloat());
          break;
        case 'c': // calibrate
          sensor->recalibrate();
      }
      break;
    case 'p': // pause
      activated = false;
      break;
    case 'r': // resume
      activated = true;
      break;
    case 'g': // print values
      Serial.print("id \t");
      Serial.println(sensor->getDeadzone());
      Serial.print("ia \t");
      Serial.println(sensor->getAlpha());
      Serial.print("lor \t");
      Serial.println(led_on.r);
      Serial.print("log \t");
      Serial.println(led_on.g);
      Serial.print("lob \t");
      Serial.println(led_on.b);
      Serial.print("lfr \t");
      Serial.println(led_off.r);
      Serial.print("lfg \t");
      Serial.println(led_off.g);
      Serial.print("lfb \t");
      Serial.println(led_off.b);
      Serial.print(";");
      break;
    case 'a': // check if activated
      Serial.println(activated);
      Serial.print(";");
      break;
    case 'l': // change led color
      while (!Serial.available());
      input2 = Serial.read();
      switch (input2)
      {
        case 'o': // on
          while (!Serial.available());
          switch ((char)Serial.read())
          {
            case 'r': // red
              led_on.r = Serial.parseInt(); // for now this has to be expressed in decimal
              break;
            case 'g': // green
              led_on.g = Serial.parseInt();
              break;
            case 'b': // blue
              led_on.b = Serial.parseInt();
              break;
            case 'e': // everything
              led_on = Serial.parseInt();
          }
          break;
        case 'f': // off
          while (!Serial.available());
          switch ((char)Serial.read())
          {
            case 'r': // red
              led_off.r = Serial.parseInt(); // for now this has to be expressed in decimal
              break;
            case 'g': // green
              led_off.g = Serial.parseInt();
              break;
            case 'b': // blue
              led_off.b = Serial.parseInt();
              break;
            case 'e': // everything
              led_off = Serial.parseInt();
          }
          break;
      }
      break;
  }
}

void setup() {
  Serial.begin(115200);
  FastLED.addLeds<LED_TYPE, RGBPIN, LED_ORDER>(leds, 16);

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

  // Set LEDS to red prior to intialize
  for (CRGB& led : leds)
  {
    led = CRGB::Red;
    FastLED.show();
  }

  // Initialize and calibrate touch sensors
  touchboard = new AutoTouchboard();

  // Initialize air sensor
  // Digital mode calibrations in the constructor
  // Analog mode will automatically calibrate as it starts being read
  sensor = new AirSensor(500, 50);

  // Display the number of air sensors that were calibrated
  for (CRGB& led : leds)
    led = CFGB::Black;
    
  for (int i = 0; i < 6; i++)
  {
    if (sensor->getSensorCalibrated(i))
      leds[i] = CRGB::Green;
    else
      leds[i] = CRGB::Red;
  }
  
  FastLED.show();
  delay(3000);

  // Set LEDs blue for "ready"
  for (CRGB& led : leds)
    led = CFGB::Blue;
    
  FastLED.show();

  // Initialize relevant output method / USB or serial
#ifdef USB
  output = new USBOutput();
#else
  output = new SerialOutput();
#endif
}

void loop() {

#ifndef LED_SERIAL
  // Config commands can only be sent when the LEDs aren't being updated via serial
  if (Serial.available())
  {
    parseCommand();
  }

  updateLeds = true;
#else
  // Wait until have at least one message
  if (Serial.available() >= 100)
  {
    Serial.readBytes(serialBuffer, 100);
    updateLeds = serialLeds.processBulk(serialBuffer, 100);
  }
  else
    updateLeds = false;
#endif

  // If currently paused through a config command, do not execute main loop
  if (!activated) 
    return;

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
    if (lightIntensity[index] > 0.05f)
      lightIntensity[index] -= 0.05f;

    KeyState keyState = touchboard->update(i);

    // If the key is currently being held, set its color to purple
    if (keyState == SINGLE_PRESS ||
          keyState == DOUBLE_PRESS)
    {
#ifndef LED_SERIAL
      lightIntensity[index] = 1.0f;
      leds[index].setRGB(min(led_on.r / 2 + led_on.r / 2 * lightIntensity[index], 255), min(led_on.g / 2 + led_on.g / 2 * lightIntensity[index], 255), min(led_on.b / 2 + led_on.b / 2 * lightIntensity[index], 255));
#endif
    }
    else
    {
#ifndef LED_SERIAL
      // If not, make it yellow and send the "key released" event if it was previously pressed
      leds[index].setRGB(led_off.r / 2, led_off.g / 2, led_off.b / 2);
#endif
    }

#ifdef LED_SERIAL
    if (updateLeds)
    {
      RGBLed temp = serialLeds.getKey(i);
      leds[index].setRGB(temp.r, temp.g, temp.b);
    }
#endif

#if !defined(SERIAL_PLOT) && defined(USB)
    if (key_states[i] != keyState)
      output->sendKeyEvent(i, keyState);
#endif

    key_states[i] = keyState;
  }

#ifdef SERIAL_PLOT
  if (PLOT_PIN == -1)
  {
    for (int i = 0; i < 16; i++)
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

  // Process air sensor hand position
#if !defined(SERIAL_PLOT) && defined(USB)
#ifdef IR_SENSOR_KEY
    output->sendSensor(sensor->getSensorReadings());
#else
    output->sendSensorEvent(sensor->getHandPosition());
#endif
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
    FastLED.show();
}
