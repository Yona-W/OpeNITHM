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

void AirSensor::setHalfLEDs(CRGB color, int side)
{
  for (int i = 0; i < 8; i++) 
  {
#ifndef KEY_DIVIDERS
    leds[i] = (side == 0) ? color : CRGB::Black; 
#else
    leds[i * 2] = (side == 0) ? color : CRGB::Black;
#endif
  }

  for (int i = 8; i < 16; i++) 
  {
#ifndef KEY_DIVIDERS
      leds[i] = (side == 1) ? color : CRGB::Black; 
#else
      leds[i * 2] = (side == 1) ? color : CRGB::Black;
#endif
  }

  FastLED.show();
}

uint16_t AirSensor::getValue(int sensor)
{
  // Turn on light corresponding to read sensor
  changeLight(sensor);

  // Delay required because the read may occur faster than the physical light turning on
  delayMicroseconds(AIR_LED_DELAY);

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
      calibrated[i] = getValue(i);
    }
  }
  else 
  { 
    analogCalibrate();
  }
}

void AirSensor::loadConfig()
{
  for (int i = 0; i < 6; i++) 
  {
    EEPROM.get(74 + (i * 2), thresholds[i]);
    calibrated[i] = true;
  }
}

void AirSensor::saveConfig()
{
  for (int i = 0; i < 6; i++)
  {
    EEPROM.put(74 + (i * 2), thresholds[i]);
  }

  EEPROM.put(66, (byte) CALIBRATION_FLAG);
}

void AirSensor::analogCalibrate() 
{
#ifdef IR_SENSOR_ANALOG
  // we'll only calibrate if:
  //   * the user is holding the first 4 keys
  //   * the calibration flag is not set in EEPROM
  bool needsCalibration = false;
  
  byte calibrationFlag;
  EEPROM.get(66, calibrationFlag);

  // only check the first 4 keys if we've calibrated at least once
  if (calibrationFlag == CALIBRATION_FLAG) 
  {
    loadConfig();
    
    int touched = 0;
    touchboard->scan();
    
#if NUM_SENSORS == 16
    for (int i = 0; i < 4; i++) 
    {
      if (touchboard->update(i) != UNPRESSED) touched++;
    }
#elif NUM_SENSORS == 32
    for (int i = 0; i < 7; i += 2)
    {
      if (touchboard->update(i) != UNPRESSED || touchboard->update(i + 1) != UNPRESSED) touched++;
    }
#endif

    // force re-calibration if the first 4 keys are being held
    needsCalibration = (touched == 4);
  }
  else 
  {
    needsCalibration = true;
  }

  if (needsCalibration)
  {
    // first, skip samplesToSkip number of readings
    for (int i = 0; i < samplesToSkip; i++)
    {
      for (int sensor = 0; sensor < 6; sensor++)
      {
        getValue(sensor);
        turnOffLight();
      }
    }
    
    // Now gather the calibration samples for each sensor. We split the calibration
    // into two parts -- left half of the slider and right half of the slider. We
    // do this because the controllers' air space tends to be less sensitive on the
    // side that contains the IR LEDs themselves, so we wanna take the 'max' of the
    // overall calibration process for each sensor, between the two halves
    int leftSideMins[6] = { 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF };
    int rightSideMins[6] = { 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF };
    int lastReadings[6] = { 0 };
    bool inputDetected = false;
  
    for (int side = 0; side < 2; side++) 
    {
      for (int j = 0; j < 6; j++) lastReadings[j] = 0;
      
      // first, set the correct half of the slider red, and wait for some air input
      setHalfLEDs(CRGB::Red, side);
  
      // wait for air inputs before we begin calibration
      while (!inputDetected) 
      {
        for (int i = 0; i < 6; i++) 
        {
          uint16_t value = getValue(i);
          turnOffLight();
          
          if (value < (AIR_INPUT_DETECTION * lastReadings[i]))
            inputDetected = true;
          else
            lastReadings[i] = value;
        }
        
        // after sweeping the LEDs, scan the touchboard to simulate the delay between
        // IR sweeps during actual gameplay so we calibrate accurately
        touchboard -> scan();
      }
  
      // set the correct half of the slider yellow
      setHalfLEDs(CRGB::Yellow, side);
  
      // begin calibration
      for (int i = 0; i < samplesToAcquire; i++)
      {
        for (int sensor = 0; sensor < 6; sensor++)
        {
          uint16_t value = getValue(sensor);
          turnOffLight();
  
          // keep the minimum value seen by the sensor
          if (side == 0) 
          {
            if (value < leftSideMins[sensor])
              leftSideMins[sensor] = value;
          }
          else
          {
            if (value < rightSideMins[sensor])
              rightSideMins[sensor] = value;
          }
        }
  
        // after sweeping the LEDs, scan the touchboard to simulate the delay between
        // IR sweeps during actual gameplay so we calibrate accurately
        touchboard -> scan();
      }
  
      // set the correct half of the slider green
      setHalfLEDs(CRGB::Green, side);
      delay(3000);
      inputDetected = false;
    }

    for (int i = 0; i < 6; i++) 
    {
      // we'll take the threshold to be 50% (default) of the window between the baseline readings and the "threshold" readings
      int bottom = max(leftSideMins[i], rightSideMins[i]);
      thresholds[i] = bottom + ((lastReadings[i] - bottom) * AIR_INPUT_THRESHOLD);
      calibrated[i] = true;
    }
    
    saveConfig();
  }
  else 
  {
    loadConfig();
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
  uint16_t value = getValue(sensor);
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

void AirSensor::recalibrate()
{
  for (int i = 0; i < 6; i++)
  {
    thresholds[i] = 0;
    calibrated[i] = false;
  }
}
