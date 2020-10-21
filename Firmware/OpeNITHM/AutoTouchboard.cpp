#include "AutoTouchboard.h"

#if NUM_SENSORS == 32
static const int sensorMap[] = {
  11, 3, 10, 2, 9, 1, 8, 0,
  31, 23, 30, 22, 29, 21, 28, 20,
  27, 19, 26, 18, 25, 17, 24, 16,
  15, 7, 14, 6, 13, 5, 12, 4
};                             
#endif

void AutoTouchboard::scan() {
  // For each key, set multiplexers and poll both capacitive sensors simultaneously
  for (int i = 0; i < 8; i++) {
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

  
  for (int i = 0; i < 4; i++) {
    Serial.print(key_values[i]);
    Serial.print("\t");
  }

  for (int i = 0; i < 4; i++) {
    Serial.print(triggerThresholdsSingle[i]);
    Serial.print("\t");
  }

  Serial.println();
  
}

void AutoTouchboard::calibrateKeys() {
  // Flash the slider red and purple so the user doesn't get near the controller during calibration
  for (int i = 0; i < 3; i++) {
    for (CRGB& led : leds)
      led = CRGB::Red;
      
    FastLED.show();
    delay(500);

    for (CRGB& led : leds)
      led = CRGB::Purple;
      
    FastLED.show();
    delay(500);
  }
  
  // take some initial readings before the main loop so we can establish baselines
  scan();
  
  int value;
  for (int i = 0; i < NUM_SENSORS; i++) {
    // determine the current thresholds for trigger
    // and release based on the configured delta threhsold
    // and the current readings
    value = key_values[i];
    
    states[i] = UNPRESSED;
    calcThresholds(i, value);
  }

  calibrated = true;
}

KeyState AutoTouchboard::update(int key) {
  // check if the button is pressed
  // keep a running record of the last X deltas and the latest readings
  int pressure = key_values[key];
  unsigned long currMillis = millis();

  if (states[key] == UNPRESSED) {
    // new press detected
    if (pressure > triggerThresholdsDouble[key]) {
      states[key] = DOUBLE_PRESS;
    } else if (pressure > triggerThresholdsSingle[key]) {
      states[key] = SINGLE_PRESS;
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

  if (calibrated) {
    return states[key];
  } else {
    calibrationCounter--;
    
    if (calibrationCounter <= 0) {
      calibrateKeys();
      calibrated = true;
    }

    return UNPRESSED;
  }
}

uint16_t AutoTouchboard::getRawValue(int key) {
  return key_values[key];
}

void AutoTouchboard::calcThresholds(int key, int pressure) {
  triggerThresholdsSingle[key] = pressure + deltaThreshold;
  releaseThresholdsSingle[key] = pressure + (deltaThreshold * releaseThreshold);
  triggerThresholdsDouble[key] = triggerThresholdsSingle[key] + (deltaThreshold);
  releaseThresholdsDouble[key] = triggerThresholdsSingle[key] + (deltaThreshold * releaseThreshold);
}

AutoTouchboard::AutoTouchboard() {
  pinMode(MUX_0, OUTPUT);
  pinMode(MUX_1, OUTPUT);
  pinMode(MUX_2, OUTPUT);
  
  calibrateKeys();
}
