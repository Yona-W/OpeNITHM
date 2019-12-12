#include "PinConfig.h"

#ifdef USB
#include "USBOutput.h"
#else
#include "SerialOutput.h"
#endif

#ifdef LED_SERIAL
#include "SerialLeds.h"
bool updateLeds = false;
byte serialBuffer[200];
SerialLeds serialLeds;
#endif

#include "AirSensor.h"
#include "Touchboard.h"
#include <FastLED.h>

CRGB leds[16];

CRGB led_on = 0xFF00FF; // purple
CRGB led_off = 0xFFFF00; // yellow

float lightIntensity[16];
bool keyStates[16];
bool activated = true;
float sensorPosition = -1;

Touchboard *touchboard;
AirSensor *sensor;
Output *output;

char command[32];

// Triggered when Touchboard determines a key was pressed
void onKeyPress(int key, bool wasHeld)
{
  lightIntensity[key] = 1.0f;
#if !defined(SERIAL_PLOT) && defined(USB)
  output->sendKeyEvent(key, true, wasHeld);
#endif
  keyStates[key] = true;
}

// Parse configuration command. For now, a serial terminal is required (like the monitor in Arduino IDE)
// Eventually I will make a config tool
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
        case 't': // threshold
          touchboard->setThreshold(Serial.parseInt());
          break;
        case 'd': // dead zone
          touchboard->setDeadzone(Serial.parseInt());
          break;
        case 'a': // alpha
          touchboard->setAlpha(Serial.parseFloat());
          break;
        case 'c': // calibrate
          touchboard->calibrateKeys();
          break;
        case 'n': // print neutral values
          Serial.println("Neutral Values");
          for (i = 0; i < 16; i++)
          {
            Serial.print("Key: ");
            Serial.print(i);
            Serial.print("\t");
            Serial.println(touchboard->getNeutralValue(i));
          }
          break;
        case 'e': // print moving average values
          Serial.println("Moving Average Values");
          for (i = 0; i < 16; i++)
          {
            Serial.print("Key: ");
            Serial.print(i);
            Serial.print("\t");
            Serial.println(touchboard->getEmAverages(i));
          }
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
      Serial.print("tt \t");
      Serial.println(touchboard->getThreshold());
      Serial.print("td \t");
      Serial.println(touchboard->getDeadzone());
      Serial.print("ta \t");
      Serial.println(touchboard->getAlpha());
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
    {
      led = 0xFF5F00;
      FastLED.show();
    }
    delay(1000);
    for (CRGB& led : leds)
    {
      led = 0x000000;
      FastLED.show();
    }
    delay(1000);
  }

  // Set LEDS to red prior to intialize
  for (CRGB& led : leds)
  {
    led = CRGB::Red;
    FastLED.show();
  }

  // Initialize and calibrate touch sensors
  touchboard = new Touchboard(onKeyPress);

  // Set LEDs blue for "ready, waiting for air sensor"
  for (CRGB& led : leds)
  {
    led = 0x0000FF;
    FastLED.show();
  }

  // Initialize air sensor - will automatically calibrate as it starts being read
  sensor = new AirSensor(500, 50);

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
#else
  // Wait until have at least one message
  // For the sake of processing time we'll be discarding every other message
  if (Serial.available() > 200)
  {
    Serial.readBytes(serialBuffer, 200);
    updateLeds = serialLeds.processBulk(serialBuffer, 200);
  }
  else
    updateLeds = false;
#endif

  // If currently paused through a config command, do not execute main loop
  if (!activated) return;

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

    // If the key is currently being held, set its color to purple
    if (touchboard->update(i))
    {
#ifndef LED_SERIAL
      leds[index].setRGB(min(led_on.r / 2 + led_on.r / 2 * lightIntensity[index], 255), min(led_on.g / 2 + led_on.g / 2 * lightIntensity[index], 255), min(led_on.b / 2 + led_on.b / 2 * lightIntensity[index], 255));
#endif
    }
    else
    {
#ifndef LED_SERIAL
      // If not, make it yellow and send the "key released" event if it was previously pressed
      leds[index].setRGB(led_off.r / 2, led_off.g / 2, led_off.b / 2);
#endif
      if (keyStates[i])
      {
#if !defined(SERIAL_PLOT) && defined(USB)
        output->sendKeyEvent(i, false, false);
#endif
        keyStates[i] = false;
      }
    }

#ifdef LED_SERIAL
    if (updateLeds)
    {
      RGBLed temp = serialLeds.getKey(i);
      leds[index].setRGB(temp.r, temp.g, temp.b);
    }
#endif
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
    Serial.print(touchboard->getDeadzone());
    Serial.println();
  }
  else
  {
    Serial.print(touchboard->getRawValue(PLOT_PIN));
    Serial.print("\t");
    Serial.print(touchboard->getEmAverages(PLOT_PIN));
    Serial.print("\t");
    Serial.print(touchboard->getEmAverages(PLOT_PIN) + touchboard->getThreshold());
    Serial.print("\t");
    Serial.print(touchboard->getNeutralValue(PLOT_PIN));
    Serial.print("\t");
    Serial.print(touchboard->getNeutralValue(PLOT_PIN) + touchboard->getDeadzone());
  }
#endif

  // Process air sensor hand position
  const float newPosition = sensor->getHandPosition();
  if (newPosition != sensorPosition)
  {
#if !defined(SERIAL_PLOT) && defined(USB)
#ifdef IR_SENSOR_KEY
    output->sendSensor(sensor->getSensorReadings());
#else
    output->sendSensorEvent(newPosition);
#endif
#endif
    sensorPosition = newPosition;
  }

  // Send update
#if !defined(SERIAL_PLOT) && defined(USB)
  output->sendUpdate();
#endif

  //#if defined(SERIAL_PLOT)
  //  Serial.print("\t");
  //  Serial.println(sensor->getSensorReadings());
  //#endif

  // If the air sensor is calibrated, update lights. The lights will stay red as long as the air sensor is not calibrated.
  if (sensor->isCalibrated())
    FastLED.show();

}
