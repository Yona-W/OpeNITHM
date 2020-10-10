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

void AutoTouchboard::calibrateKeys()
{
  // Flash every key red a few times so they know to let go of the slider while we self-calibrate
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

  // Take the initial baseline readings so we can populate our delta buffer
  scan();
  
  int value;
  // take some initial readings before the main loop so we can establish baselines
  for (int i = 0; i < NUM_SENSORS; i++) {
    // determine the current thresholds for trigger
    // and release based on the configured delta threhsold
    // and the current readings
    value = key_values[i];
    
    states[i] = UNPRESSED;
    calcThresholds(i, value);
  }

  // Flash the slider green for a couple of seconds to show success
  for (int j = 0; j < 16; j++)
  {
#ifndef KEY_DIVIDERS
    leds[j] = CRGB::Green;
#else
    leds[j * 2] = CRGB::Green;
#endif
  }

  FastLED.show();
  delay(1000);
}

KeyState AutoTouchboard::update(int key)
{
  // check if the button is pressed
  // keep a running record of the last X deltas and the latest readings
  int pressure = key_values[key];
  unsigned long currMillis = millis();

  if (states[key] == UNPRESSED) {
    // new press detected
    if (pressure > triggerThresholdsDouble[key]) {
      lastTriggerTimes[key] = currMillis;
      states[key] = DOUBLE_PRESS;
    } else if (pressure > triggerThresholdsSingle[key]) {
      lastTriggerTimes[key] = currMillis;
      states[key] = SINGLE_PRESS;
    // the key hasn't been triggered, so we'll check how long it's been since
    // the last trigger. if it's been more than the configured period, re-establish
    // baselines for thresholds
    } else if (currMillis - lastTriggerTimes[key] > CALIBRATION_PERIOD) {
      calcThresholds(key, pressure);
    }
  // new release detected
  } else if (states[key] != UNPRESSED) {
    if (pressure < releaseThresholdsSingle[key]) {
      states[key] = UNPRESSED;
    } else if (pressure < releaseThresholdsDouble[key]) {
      states[key] = SINGLE_PRESS;
    }
  }
  
#if NUM_SENSORS == 32
  if (states[key] == DOUBLE_PRESS) {
    states[key] == SINGLE_PRESS;
  }
#endif
  
  return states[key];
}

uint16_t AutoTouchboard::getRawValue(int key)
{
  return key_values[key];
}

void AutoTouchboard::calcThresholds(int key, int pressure)
{
  triggerThresholdsSingle[key] = pressure + deltaThreshold;
  releaseThresholdsSingle[key] = pressure + (deltaThreshold * releaseThreshold);
  triggerThresholdsDouble[key] = triggerThresholdsSingle[key] + (0.8 * deltaThreshold);
  releaseThresholdsDouble[key] = triggerThresholdsSingle[key] + (0.8 * deltaThreshold * releaseThreshold);
  lastTriggerTimes[key] = millis();
}

AutoTouchboard::AutoTouchboard()
{
  pinMode(MUX_0, OUTPUT);
  pinMode(MUX_1, OUTPUT);
  pinMode(MUX_2, OUTPUT);
  
  calibrateKeys();
}
