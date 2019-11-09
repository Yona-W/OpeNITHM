//
//
//
#include "AirSensor.h"

#ifndef IR_SENSOR_MULTIPLEXED
int ir_sensor_pins[6] = {AIR_SENSOR_0_PIN, AIR_SENSOR_1_PIN, AIR_SENSOR_2_PIN, AIR_SENSOR_3_PIN, AIR_SENSOR_4_PIN, AIR_SENSOR_5_PIN};
#endif

// Sets the output pins to switch the charlieplexed array of LEDs.
// 0 is the bottom-most LED and 5 is the top-most
void AirSensor::changeLight(int light)
{
  switch (light)
  {
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
void AirSensor::turnOffLight()
{
  pinMode(LED_0, INPUT);
  pinMode(LED_1, INPUT);
  pinMode(LED_2, INPUT);
}

int AirSensor::getValue(int sensor, bool light)
{
  // Turn on light corresponding to read sensor
  if (light)
  {
    changeLight(sensor);
  }
  else
  {
    turnOffLight();
  }

#ifdef IR_SENSOR_MULTIPLEXED
  // Set multiplexer to corresponding sensor
  digitalWrite(MUX_A, bitRead(sensor, 0));
  digitalWrite(MUX_B, bitRead(sensor, 1));
  digitalWrite(MUX_C, bitRead(sensor, 2));
  // Return sensor value
#ifdef IR_SENSOR_ANALOG
  return analogRead(SENSOR_IN);
#else
  delay(1);
  return digitalRead(SENSOR_IN);
#endif
#else
#ifdef IR_SENSOR_ANALOG
  return analogRead(ir_sensor_pins[sensor]);
#else
  delay(1);
  return digitalRead(ir_sensor_pins[sensor]);
#endif
#endif
}


AirSensor::AirSensor(int requiredSamples, int skippedSamples) : thresholds{ 10000, 10000, 10000, 10000, 10000, 10000 }, calibrationSamples{ 0, 0, 0, 0, 0, 0 }, skippedSamples{ 0, 0, 0, 0, 0, 0 }, samplesToAcquire(requiredSamples), samplesToSkip(skippedSamples), calibrated{ 0, 0, 0, 0, 0, 0 }, allCalibrated(false)
{
  // Load config values
  EEPROM.get(12, deadzone);
  EEPROM.get(16, alpha);

#ifndef IR_SENSOR_ANALOG
  // No calibration required in digital mode
  for (int i = 0; i < 6; i++)
  {
#ifndef IR_SENSOR_MULTIPLEXED
    pinMode(ir_sensor_pins[i], INPUT);
#endif
    calibrated[i] = true;
  }
  allCalibrated = true;
#endif
}

// Check if all IR sensors are calibrated. If they are, set a flag to not need to re-check it
bool AirSensor::isCalibrated()
{
  if (!allCalibrated)
  {
    for (int i = 0; i < 6; i++)
    {
      if (!calibrated[i])
        return false;
    }
    allCalibrated = true;
  }
  return allCalibrated;
}

bool AirSensor::getSensorState(int sensor)
{
  // Flash the LED and read the IR sensor
  int value = getValue(sensor, true);
  turnOffLight();

#ifdef IR_SENSOR_ANALOG
  // If the sensor is calibrated, Store its current filtered value.
  // We are using an exponential moving average to filter out environmental noise. Setting alpha to 1 disables it.
  if (allCalibrated || calibrated[sensor]) {
    sensorValues[sensor] = (float)value * alpha + sensorValues[sensor] * (1 - alpha);
    return sensorValues[sensor] < thresholds[sensor];
  }
  else
  {
    // If it is not calibrated, perform calibration:
    // Skip the first few samples. This might not be required, but improved performance in my case.
    // This might be due to wiring mistakes I made - I'm leaving the code in either way as it can't hurt.
    if (skippedSamples[sensor] > samplesToSkip)
    {
      // Keep the minimum value seen by the sensor
      if (value < thresholds[sensor]) thresholds[sensor] = value;
      // If we have enough samples:
      if (++calibrationSamples[sensor] > samplesToAcquire)
      {
        // Consider the sensor calibrated. Finalize calibration for this sensor.
        sensorValues[sensor] = value;
        calibrated[sensor] = true;
        thresholds[sensor] -= deadzone;
      };
    }
    else
    {
      skippedSamples[sensor]++;
    }
    return false;
  }
#else
  return value == LOW ? true : false;
#endif
}

// Using data from air sensors, compute the height of the player's hand, from 0 (not present) to 1 (highest possible position).
float AirSensor::getHandPosition()
{
  int highestTriggered = -1;
  for (int i = 0; i < 6; i++)
  {
    if (getSensorState(i))
    {
      if ((i + 1) > highestTriggered)
        highestTriggered = i + 1;
    }
  }
  return highestTriggered == -1 ? 0 : ((float)highestTriggered / 6.0f);
}

uint8_t AirSensor::getSensorReadings()
{
  uint8_t reading = 0;
  for (int i = 0; i < 6; i++)
  {
    reading |= ((int)getSensorState(i) << i);
  }
  return reading;
}

void AirSensor::setDeadzone(int deadzone)
{
  this->deadzone = deadzone;
  EEPROM.put(12, deadzone);
}

void AirSensor::setAlpha(float alpha)
{
  this->alpha = alpha;
  EEPROM.put(16, alpha);
}

int AirSensor::getDeadzone()
{
  return deadzone;
}

float AirSensor::getAlpha()
{
  return alpha;
}

void AirSensor::recalibrate()
{
  for (int i = 0; i < 6; i++)
  {
    thresholds[i] = 0;
    calibrationSamples[i] = 0;
    skippedSamples[i] = 0;
    sensorValues[i] = 0;
    calibrated[i] = false;
  }
  allCalibrated = false;
}
