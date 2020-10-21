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

  for (int i = 0; i < 6; i++) {
    maxReadings[i] = 0;
  }
  
#ifndef IR_SENSOR_ANALOG
  for (int i = 0; i < 6; i++) {
    pinMode(ir_sensor_pins[i], INPUT);
  }
#endif
}

void AirSensor::analogCalibrate() {

#ifdef IR_SENSOR_ANALOG
  for (CRGB& led : leds)
    led = CRGB::Red;
    
  FastLED.show();

  // Skip some samples, for some reason the first few readings tend to give wild values that can skew min/max tracking
  for (int i = 0; i < SKIP_SAMPLES; i++) {
    for (int sensor = 0; sensor < 6; sensor++) {
      getValue(sensor);
      touchboard -> scan();
    }
  }

  // begin calibration
  for (int i = 0; i < CALIBRATION_SAMPLES; i++) {
    for (int sensor = 0; sensor < 6; sensor++) {
      uint16_t value = getValue(sensor);

      if (value > maxReadings[sensor])
        maxReadings[sensor] = value;
    }

    // after sweeping the LEDs, scan the touchboard to simulate the delay between
    // IR sweeps during actual gameplay so we calibrate accurately
    touchboard -> scan();
  }

  for (int i = 0; i < 6; i++) {
    thresholds[i] = (AIR_INPUT_DETECTION * maxReadings[i]);
  }
#endif

  for (CRGB& led : leds)
    led = CRGB::Green;
    
  FastLED.show();
  delay(3000);
    
  calibrated = true;
}

bool AirSensor::getSensorState(int sensor) {
  uint16_t value = getValue(sensor);

  
  Serial.print(sensor);
  Serial.print("\t");
  Serial.print(value);
  Serial.print("\t");
  Serial.print(maxReadings[sensor]);
  Serial.print("\t");
  Serial.print(thresholds[sensor]);
  Serial.println();
  

#ifndef IR_SENSOR_ANALOG
  return value == LOW ? true : false;
#else
  return value < thresholds[sensor];
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
