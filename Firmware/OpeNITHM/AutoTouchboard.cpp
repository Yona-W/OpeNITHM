#include "AutoTouchboard.h"

void AutoTouchboard::scan()
{
  // For each key, set multiplexers and poll both capacitive sensors simultaneously
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(MUX_0, bitRead(i, 0));
    digitalWrite(MUX_1, bitRead(i, 1));
    digitalWrite(MUX_2, bitRead(i, 2));

#ifndef TEENSY
    unsigned int* values = sensor.sense(3);

    // Store the values received from the sensor poll into their respective positions
    key_values[i] = values[0];
    key_values[i + 8] = values[1];
#else
    key_values[i] = touchRead(TOUCH_0);
    key_values[i+8] = touchRead(TOUCH_1);
#endif
  }
}

void AutoTouchboard::loadConfig()
{
  for (int i = 0; i < 16; i++) 
  {
    EEPROM.get(i * 2, single_thresholds[i]);
    EEPROM.get((i * 2) + 32, double_thresholds[i]);
  }
}

void AutoTouchboard::saveConfig()
{
  for (int i = 0; i < 16; i++)
  {
    EEPROM.put(i * 2, single_thresholds[i]);
    EEPROM.put((i * 2) + 32, double_thresholds[i]);
  }

  EEPROM.put(64, (byte) CALIBRATION_FLAG);
}

void AutoTouchboard::calibrateKeys(bool forceCalibrate = false)
{
  // we'll only calibrate if:
  //   * the user is holding the last 4 keys
  //   * the calibration flag is not set in EEPROM
  bool needsCalibration = forceCalibrate;
  
  byte calibrationFlag;
  EEPROM.get(64, calibrationFlag);

  // only check the last 4 keys if we've calibrated at least once
  if (calibrationFlag == CALIBRATION_FLAG) 
  {
    loadConfig();
    
    int touched = 0;
    scan();

    for (int i = 12; i < 16; i++) 
    {
      if (update(i) != UNPRESSED) touched++;
    }

    if (touched == 4) needsCalibration = true;
  }
  else 
  {
    needsCalibration = true;
  }

  if (needsCalibration)
  {
    uint16_t baselines[16];
    
    // Reset calibration data for all keys
    for (int i = 0; i < 16; i++)
    {
      key_values[i] = 0;
      single_thresholds[i] = 0xFFFF;
      double_thresholds[i] = 0xFFFF;
    }

    // Flash every key red a few times so they know to let go of the slider
    for (int i = 0; i < 5; i++) 
    {
      for (int j = 0; j < 16; j++)
      {
        leds[j] = CRGB::Red;
      }

      FastLED.show();
      delay(500);

      for (int j = 0; j < 16; j++)
      {
        leds[j] = CRGB::Purple;
      }

      FastLED.show();
      delay(500);
    }
  
    // Figure out the baselines for each key
    for (int i = 0; i < CALIBRATION_SAMPLES; i++) 
    {
      scan();
    }
  
    // figure out the baseline for each key
    for (int i = 0; i < 16; i++) 
    {
      baselines[i] = key_values[i];
    }
  
    // Iterate over each key and have the user single press to calculate
    // our threshold windows. Since each finger raises the value by roughly
    // the same amount, we have the single double press each key, obtain the
    // average readout, then use the baselines to calculate a window for singles
    // and doubles
    for (int i = 0; i < 16; i++) 
    {
      leds[i] = CRGB::Red;
      FastLED.show();
  
      // wait until we detect a touch, then start measuring to determine the average
      while (key_values[i] < baselines[i] + CALIBRATION_DETECTION_THRESHOLD) 
      {
        scan();
      }
  
      leds[i] = CRGB::Blue;
      FastLED.show();
      
      for (int j = 0; j < CALIBRATION_SAMPLES; j++) 
      {
        scan();
      }
  
      leds[i] = CRGB::Green;
      FastLED.show();
  
      uint16_t window = (key_values[i] - baselines[i]) * (sensitivity / 100.0f);
      single_thresholds[i] = baselines[i] + window;
      double_thresholds[i] = baselines[i] + (2 * window);
    }

    saveConfig();
  }
  else 
  {
    // just set the keys green
    for (int i = 0; i < 16; i++) 
    {
      leds[i] = CRGB::Green;
      FastLED.show();
    }
  }
}

KeyState AutoTouchboard::update(int key)
{
  if (key_values[key] > double_thresholds[key])
    return DOUBLE_PRESS;
  else if (key_values[key] > single_thresholds[key])
    return SINGLE_PRESS;
  else
    return UNPRESSED;
}

uint16_t AutoTouchboard::getRawValue(int key)
{
  return key_values[key];
}

void AutoTouchboard::setSensitivity(uint8_t sensitivity)
{
  this->sensitivity = sensitivity;
  EEPROM.put(65, sensitivity);
}

uint8_t AutoTouchboard::getSensitivity()
{
  return sensitivity;
}

AutoTouchboard::AutoTouchboard()
#ifndef TEENSY
  sensor(CapacitiveSensor(SEND, RECEIVE_1, RECEIVE_2)),
#endif
{
  pinMode(MUX_0, OUTPUT);
  pinMode(MUX_1, OUTPUT);
  pinMode(MUX_2, OUTPUT);

  EEPROM.get(65, sensitivity);
  
  if (sensitivity == 0)
    setSensitivity(DEFAULT_SENSITIVITY);

  calibrateKeys();
}
