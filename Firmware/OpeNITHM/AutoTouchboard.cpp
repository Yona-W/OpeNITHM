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
  int value;
  
  for (int r = 0; r < NUM_READINGS; r++) {
    scan();

    for (int i = 0; i < NUM_SENSORS; i++) {
      value = key_values[i];

      // calculate the newest delta if it's not the first reading
      if (r > 0) {
        deltas[i]->addValue(value - lastReadings[i]);
      }

      lastReadings[i] = value;
    }
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
  int value = key_values[key];
  deltas[key]->addValue(value - lastReadings[key]);
  lastReadings[key] = value;
  bool deltaTriggered = (deltas[key]->getSum() > deltaThreshold);

#if NUM_SENSORS == 32
  // check the readout data and the running sum of the deltas;
  // if running sum of deltas goes above our defined threshold,
  // trigger a press and set new lower bounds for release,
  // otherwise, check for a release
  if (states[key] == UNPRESSED && deltaTriggered) {
    // set a new release threshold based on the reading at the time we detected
    // the press (minus the threshold + a small hysteresis factor)
    releaseThresholdsSingle[key] = value - deltaThreshold + releaseHysteresis;
    states[key] = SINGLE_PRESS;
  } else if (states[key] != UNPRESSED && (value < releaseThresholdsSingle[key])) {
    // new release
    states[key] = UNPRESSED;
    releaseThresholdsSingle[key] = 0;
  }
#elif NUM_SENSORS == 16
  // check for new single press
  if (states[key] == UNPRESSED && deltaTriggered) {
    // set a new single release threshold based on the reading at the time we detected
    // the press (minus the threshold + a small hysteresis factor)
    releaseThresholdsSingle[key] = value - deltaThreshold + releaseHysteresis;
    states[key] = SINGLE_PRESS;
  }
  // check for new double press
  else if (states[key] == SINGLE_PRESS && deltaTriggered) {
    // set a new release threshold based on the reading at the time we detected
    // the press (minus the threshold + a small hysteresis factor)
    releaseThresholdsDouble[key] = value - deltaThreshold + releaseHysteresis;
    states[key] = DOUBLE_PRESS;
  }
  // check for double -> single release
  else if (states[key] == DOUBLE_PRESS && (value < releaseThresholdsDouble[key]) && (value > releaseThresholdsSingle[key])) {
    states[key] = SINGLE_PRESS;
    releaseThresholdsDouble[key] = 0;
  } 
  // check for any press (single or double) to no press)
  else if (states[key] != UNPRESSED && value < releaseThresholdsSingle[key]) {
    states[key] = UNPRESSED;
    releaseThresholdsSingle[key] = 0;
    releaseThresholdsDouble[key] = 0;
  }
#endif
  
  return states[key];
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

  for (int i = 0; i < NUM_SENSORS; i++) {
    deltas[i] = new RunningSum(NUM_READINGS);
    states[i] = UNPRESSED;
  }

  calibrateKeys();
}
