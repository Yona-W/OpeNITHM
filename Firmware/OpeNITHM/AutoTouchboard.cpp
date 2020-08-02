#include "AutoTouchboard.h"

#if NUM_SENSORS == 32
static const int sensorMap[] = {
  11, 3, 10, 2, 9, 1, 8, 0,
  31, 23, 30, 22, 29, 21, 28, 20,
  27, 19, 26, 18, 25, 17, 24, 16,
  15, 7, 14, 6, 13, 5, 12, 4
};                             
#endif

void AutoTouchboard::scan()
{
  // For each key, set multiplexers and poll both capacitive sensors simultaneously
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(MUX_0, bitRead(i, 0));
    digitalWrite(MUX_1, bitRead(i, 1));
    digitalWrite(MUX_2, bitRead(i, 2));

#if NUM_SENSORS == 16
    key_values[i] = (unsigned int) touchRead(TOUCH_0);
    key_values[i + 8] = (unsigned int) touchRead(TOUCH_1);
#elif NUM_SENSORS == 32
    key_values[sensorMap[i]] = (unsigned int) touchRead(TOUCH_0); 
    key_values[sensorMap[i + 8]] = (unsigned int) touchRead(TOUCH_1);
    key_values[sensorMap[i + 16]] = (unsigned int) touchRead(TOUCH_2);
    key_values[sensorMap[i + 24]] = (unsigned int) touchRead(TOUCH_3);
#endif
  }
}

void AutoTouchboard::loadConfig()
{
  for (int i = 0; i < NUM_SENSORS; i++) 
  {
    EEPROM.get(i * 2, single_thresholds[i]);
#if NUM_SENSORS == 16
    EEPROM.get((i * 2) + 32, double_thresholds[i]);
#endif
  }
}

void AutoTouchboard::saveConfig()
{
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    EEPROM.put(i * 2, single_thresholds[i]);
#if NUM_SENSORS == 16
    EEPROM.put((i * 2) + 32, double_thresholds[i]);
#endif
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

#if NUM_SENSORS == 16
    for (int i = 12; i < 16; i++) 
    {
      if (update(i) != UNPRESSED) touched++;
    }
#elif NUM_SENSORS == 32
    for (int i = 24; i < 31; i += 2)
    {
      if (update(i) != UNPRESSED || update(i + 1) != UNPRESSED) touched++;
    }
#endif

    // force re-calibration if the last 4 keys are being held
    needsCalibration = (touched == 4);
  }
  else 
  {
    needsCalibration = true;
  }

  if (needsCalibration)
  {
    uint16_t baselines[NUM_SENSORS];
    uint16_t maxReadings[NUM_SENSORS];
    
    // Reset calibration data for all keys
    for (int i = 0; i < NUM_SENSORS; i++)
    {
      key_values[i] = 0;
      single_thresholds[i] = 0xFFFF;
      double_thresholds[i] = 0xFFFF;
      maxReadings[i] = 0;
    }

    // Flash every key red a few times so they know to let go of the slider
    for (int i = 0; i < 5; i++) 
    {
      for (int j = 0; j < 16; j++)
      {
#ifndef KEY_DIVIDERS
        leds[j] = CRGB::Red; 
#else
        leds[j*2] = CRGB::Red;
#endif
      }

      FastLED.show();
      delay(500);

      for (int j = 0; j < 16; j++)
      {
#ifndef KEY_DIVIDERS
        leds[j] = CRGB::Purple; 
#else
        leds[j*2] = CRGB::Purple;
#endif
      }

      FastLED.show();
      delay(500);
    }
  
    // Figure out the baselines for each key
    for (int i = 0; i < CALIBRATION_SAMPLES; i++) 
    {
      scan();
    }
  
    for (int i = 0; i < NUM_SENSORS; i++) 
    {
      baselines[i] = key_values[i];
    }
  
    // Iterate over each key and have the user single press to calculate
    // our threshold windows. Since each finger raises the value by roughly
    // the same amount, we have the single double press each key, obtain the
    // average readout, then use the baselines to calculate a window for singles
    // and doubles
    for (int i = 0; i < NUM_SENSORS; i++) 
    {
      CRGB color;
      int lightIndex;

      // In 16-key mode, the key stays red until we detect a touch, then turns silver while the readings
      // are being taken, then turns green. In 32-key mode, the key stays red until it detects the top
      // sensor touched, then the key turns purple during readings for the top sensor, then turns yellow.
      // Once it's yellow, it performs the same process for the bottom sensor, then turns green and moves
      // to the next key.
#if NUM_SENSORS == 16
      color = CRGB::Red;
      lightIndex = i;
#elif NUM_SENSORS == 32
      color = (i % 2 == 0) ? CRGB::Red : CRGB::Yellow;
      lightIndex = i / 2;
#endif

#ifndef KEY_DIVIDERS
        leds[lightIndex] = color; 
#else
        leds[lightIndex * 2] = color;
#endif

      FastLED.show();
  
      // wait until we detect a touch, then start measuring to determine the average
      while (key_values[i] < baselines[i] + CALIBRATION_DETECTION_THRESHOLD) 
      {
        scan();
      }
  
#ifndef KEY_DIVIDERS
        leds[lightIndex] = CRGB::Silver; 
#else
        leds[lightIndex * 2] = CRGB::Silver;
#endif      

      FastLED.show();
      
      for (int j = 0; j < CALIBRATION_SAMPLES; j++) 
      {
        scan();
        maxReadings[i] = max(maxReadings[i], key_values[i]);
      }
      
#if NUM_SENSORS == 16
      color = CRGB::Green;
#elif NUM_SENSORS == 32
      color = (i % 2 == 0) ? CRGB::Yellow : CRGB::Green;
#endif

#ifndef KEY_DIVIDERS
        leds[lightIndex] = color; 
#else
        leds[lightIndex * 2] = color;
#endif

      FastLED.show();
  
      uint16_t window = (maxReadings[i] - baselines[i]) * TOUCH_INPUT_THRESHOLD;
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
#ifndef KEY_DIVIDERS
        leds[i] = CRGB::Green; 
#else
        leds[i * 2] = CRGB::Green;
#endif
      FastLED.show();
    }
  }
}

KeyState AutoTouchboard::update(int key)
{
#if NUM_SENSORS == 16
  if (key_values[key] > double_thresholds[key])
    return DOUBLE_PRESS;
  else if (key_values[key] > single_thresholds[key])
    return SINGLE_PRESS;
#elif NUM_SENSORS == 32
  if (key_values[key] > single_thresholds[key])
    return SINGLE_PRESS;
#endif
  else
    return UNPRESSED;
}

uint16_t AutoTouchboard::getRawValue(int key)
{
  return key_values[key];
}

AutoTouchboard::AutoTouchboard()
{
  pinMode(MUX_0, OUTPUT);
  pinMode(MUX_1, OUTPUT);
  pinMode(MUX_2, OUTPUT);

  calibrateKeys();
}
