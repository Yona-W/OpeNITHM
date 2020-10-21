#include "AirSensor.h"

int ir_sensor_pins[6] = { AIR_SENSOR_0_PIN, AIR_SENSOR_1_PIN, AIR_SENSOR_2_PIN, AIR_SENSOR_3_PIN, AIR_SENSOR_4_PIN, AIR_SENSOR_5_PIN };

// Sets the output pins to switch the charlieplexed array of LEDs.
// 0 is the bottom-most LED and 5 is the top-most
void AirSensor::changeLight(int light) {
  switch (light) {
    case 0:
      pinMode(LED_0, OUTPUT);
      pinMode(LED_1, OUTPUT);
      pinMode(LED_2, INPUT);

      digitalWrite(LED_0, HIGH);
      digitalWrite(LED_1, LOW);
      digitalWrite(LED_2, LOW);
      break;
    case 1:
      pinMode(LED_0, OUTPUT);
      pinMode(LED_1, OUTPUT);
      pinMode(LED_2, INPUT);

      digitalWrite(LED_0, LOW);
      digitalWrite(LED_1, HIGH);
      digitalWrite(LED_2, LOW);
      break;
    case 2:
      pinMode(LED_0, INPUT);
      pinMode(LED_1, OUTPUT);
      pinMode(LED_2, OUTPUT);

      digitalWrite(LED_0, LOW);
      digitalWrite(LED_1, HIGH);
      digitalWrite(LED_2, LOW);
      break;
    case 3:
      pinMode(LED_0, INPUT);
      pinMode(LED_1, OUTPUT);
      pinMode(LED_2, OUTPUT);

      digitalWrite(LED_0, LOW);
      digitalWrite(LED_1, LOW);
      digitalWrite(LED_2, HIGH);
      break;
    case 4:
      pinMode(LED_0, OUTPUT);
      pinMode(LED_1, INPUT);
      pinMode(LED_2, OUTPUT);

      digitalWrite(LED_0, HIGH);
      digitalWrite(LED_1, LOW);
      digitalWrite(LED_2, LOW);
      break;
    case 5:
      pinMode(LED_0, OUTPUT);
      pinMode(LED_1, INPUT);
      pinMode(LED_2, OUTPUT);

      digitalWrite(LED_0, LOW);
      digitalWrite(LED_1, LOW);
      digitalWrite(LED_2, HIGH);
      break;
    default:
      turnOffLight();
      break;
  }
}

// Sets all output pins to high-impedance to turn off all LEDs
void AirSensor::turnOffLight() {
  pinMode(LED_0, INPUT);
  pinMode(LED_1, INPUT);
  pinMode(LED_2, INPUT);
}

uint16_t AirSensor::getValue(int sensor) {
  // Turn on light corresponding to read sensor
  changeLight(sensor);

  // Delay required because the read may occur faster than the physical light turning on
  delayMicroseconds(AIR_LED_DELAY);

#ifndef IR_SENSOR_ANALOG
    return digitalRead(ir_sensor_pins[sensor]);
#else
    return analogRead(ir_sensor_pins[sensor]);
#endif

  // Turn the lights off when we're done reading
  turnOffLight();
}


AirSensor::AirSensor() {
  calibrationCounter = 10;
  calibrated = false;
  
#ifndef IR_SENSOR_ANALOG
  for (int i = 0; i < 6; i++) {
    pinMode(ir_sensor_pins[i], INPUT);
  }
#endif
}

void AirSensor::analogCalibrate() {
#ifdef IR_SENSOR_ANALOG
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
  for (int i = 0; i < 6; i++) {
    // determine the current thresholds for trigger
    // and release based on the configured delta threhsold
    // and the current readings
    uint16_t value = getValue(i);
    
    states[i] = false;
    calcThresholds(i, value);
  }
#endif

  calibrated = true;
}

bool AirSensor::getSensorState(int sensor) {
  uint16_t value = getValue(sensor);
  
/*
  Serial.print(sensor);
  Serial.print("\t");
  Serial.print(value);
  Serial.print("\t");
  Serial.print(triggerThresholds[sensor]);
  Serial.println();
*/

#ifndef IR_SENSOR_ANALOG
  return value == LOW ? true : false;
#else
  if (!states[sensor]) {
    if (value <= triggerThresholds[sensor]) {
      states[sensor] = true;
    }
  } else if (states[sensor] && (value >= releaseThresholds[sensor])) {
    states[sensor] = false;
  }

  return states[sensor];
#endif
}

// Using data from air sensors, compute the height of the player's hand, from 0 (not present) to 1 (highest possible position).
float AirSensor::getHandPosition() {
  int highestTriggered = -1;
  
  for (int i = 0; i < 6; i++) {
    if (getSensorState(i)) {
      if ((i + 1) > highestTriggered) {
        highestTriggered = i + 1;
      }
    }
  }

  if (calibrated) {
    return highestTriggered == -1 ? 0 : ((float) highestTriggered / 6.0f);
  } else {
    calibrationCounter--;
    
    if (calibrationCounter <= 0) {
      analogCalibrate();
      calibrated = true;
    }

    return 0;
  }
}

uint8_t AirSensor::getSensorReadings() {
  uint8_t reading = 0;

  for (int i = 0; i < 6; i++) {
    reading |= ((int) getSensorState(i) << i);
  }

  // skip the first N readings and then calibrate
  if (calibrated) {
    return reading;
  } else {
    calibrationCounter--;
    
    if (calibrationCounter <= 0) {
      analogCalibrate();
      calibrated = true;
    }

    return 0;
  }
  
}

void AirSensor::calcThresholds(int sensor, int value) {
  triggerThresholds[sensor] = value - deltaThreshold;
  releaseThresholds[sensor] = value - (deltaThreshold * releaseThreshold);
}
