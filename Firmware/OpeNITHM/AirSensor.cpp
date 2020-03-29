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

  // Delay required because the read may occur faster than the physical light turning on
  delayMicroseconds(125);

#ifdef IR_SENSOR_MULTIPLEXED
  // Set multiplexer to corresponding sensor
  digitalWrite(MUX_A, bitRead(sensor, 0));
  digitalWrite(MUX_B, bitRead(sensor, 1));
  digitalWrite(MUX_C, bitRead(sensor, 2));
  // Return sensor value
  if (digitalMode)
    return digitalRead(SENSOR_IN);
  else
    return analogRead(SENSOR_IN);
#else
  if (digitalMode)
    return digitalRead(ir_sensor_pins[sensor]);
  else
    return analogRead(ir_sensor_pins[sensor]);
#endif
}


AirSensor::AirSensor(int requiredSamples, int skippedSamples) : thresholds{ 10000, 10000, 10000, 10000, 10000, 10000 }, samplesToAcquire(requiredSamples), samplesToSkip(skippedSamples), calibrated{ 0, 0, 0, 0, 0, 0 }
{
#ifdef IR_SENSOR_ANALOG
  digitalMode = false;
#else
  digitalMode = true;
#endif

  if (digitalMode)
  {
    for (int i = 0; i < 6; i++)
    {
#ifndef IR_SENSOR_MULTIPLEXED
      pinMode(ir_sensor_pins[i], INPUT);
#endif
      calibrated[i] = getValue(i, true);
    }
  }
  else 
  { 
    
    EEPROM.get(66, analogSensitivity);

    if (analogSensitivity == 0 || analogSensitivity >= 100)
      setAnalogSensitivity(DEFAULT_SENSITIVITY);
      
    analogCalibrate();
  }

 
}

void AirSensor::analogCalibrate() 
{
#ifdef IR_SENSOR_ANALOG
  for (int sensor = 0; sensor < 6; sensor++)
  {
    // first, skip samplesToSkip number of readings
    for (int i = 0; i < samplesToSkip; i++)
    {
      getValue(sensor, true);
      turnOffLight();
    }
    
    // now gather the calibration samples for this sensor
    for (int i = 0; i < samplesToAcquire; i++)
    {
      int value = getValue(sensor, true);
      turnOffLight();

      //keep the minimum value seen by the sensor
      if (value < thresholds[sensor])
        thresholds[sensor] = value;
    }

    // consider the sensor calibrated, finalize calibration for this sensor.
    calibrated[sensor] = true;
    thresholds[sensor] *= (analogSensitivity / 100.0f);
  }
#endif
}

bool AirSensor::isCalibrated()
{
#ifdef IGNORE_AIR_CALIBRATION
  return true;
#else
    for (int i = 0; i < 6; i++)
    {
      if (!calibrated[i])
        return false;
    }
    
    return true;
#endif
}

bool AirSensor::getSensorState(int sensor) {
  // Flash the LED and read the IR sensor
  int value = getValue(sensor, true);
  turnOffLight();

  if (digitalMode) 
  {
    return value == LOW ? true : false;
  }
  else 
  {
    if (calibrated[sensor]) 
    {
      return value < thresholds[sensor];
    } 
    else 
    {
      return false;
    }
  }
}

bool AirSensor::isDigital()
{
  return digitalMode;
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

bool AirSensor::getSensorCalibrated(int i)
{
  return calibrated[i];
}

void AirSensor::setAnalogSensitivity(uint8_t analogSensitivity)
{
  this->analogSensitivity = analogSensitivity;
  EEPROM.put(66, analogSensitivity);
}

uint8_t AirSensor::getAnalogSensitivity()
{
  return analogSensitivity;
}

void AirSensor::recalibrate()
{
  for (int i = 0; i < 6; i++)
  {
    thresholds[i] = 0;
    calibrated[i] = false;
  }
}
