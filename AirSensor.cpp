// 
// 
// 

#include "AirSensor.h"


void AirSensor::changeLight(int light)
{
	switch (light)
	{
		case 0:
			pinMode(IR_A, OUTPUT);
			pinMode(IR_B, OUTPUT);
			pinMode(IR_C, INPUT);

			digitalWrite(IR_A, LOW);
			digitalWrite(IR_B, HIGH);
			digitalWrite(IR_C, LOW);
			break;
		case 1:
			pinMode(IR_A, OUTPUT);
			pinMode(IR_B, OUTPUT);
			pinMode(IR_C, INPUT);

			digitalWrite(IR_A, HIGH);
			digitalWrite(IR_B, LOW);
			digitalWrite(IR_C, LOW);
			break;
		case 2:
			pinMode(IR_A, INPUT);
			pinMode(IR_B, OUTPUT);
			pinMode(IR_C, OUTPUT);

			digitalWrite(IR_A, LOW);
			digitalWrite(IR_B, LOW);
			digitalWrite(IR_C, HIGH);
			break;
		case 3:
			pinMode(IR_A, INPUT);
			pinMode(IR_B, OUTPUT);
			pinMode(IR_C, OUTPUT);

			digitalWrite(IR_A, LOW);
			digitalWrite(IR_B, HIGH);
			digitalWrite(IR_C, LOW);
			break;
		case 4:
			pinMode(IR_A, OUTPUT);
			pinMode(IR_B, INPUT);
			pinMode(IR_C, OUTPUT);

			digitalWrite(IR_A, LOW);
			digitalWrite(IR_B, LOW);
			digitalWrite(IR_C, HIGH);
			break;
		case 5:
			pinMode(IR_A, OUTPUT);
			pinMode(IR_B, INPUT);
			pinMode(IR_C, OUTPUT);

			digitalWrite(IR_A, HIGH);
			digitalWrite(IR_B, LOW);
			digitalWrite(IR_C, LOW);
			break;
		default:
			turnOffLight();
			break;
	}
}

void AirSensor::turnOffLight()
{
	pinMode(IR_A, INPUT);
	pinMode(IR_B, INPUT);
	pinMode(IR_C, INPUT);
}

int AirSensor::getValue(int sensor, bool light)
{
  digitalWrite(MUX_A, bitRead(sensor, 0));
  digitalWrite(MUX_B, bitRead(sensor, 1));
  digitalWrite(MUX_C, bitRead(sensor, 2));

  if(light)
  {
	  changeLight(sensor);
  }
  else
  {
	  turnOffLight();
  }
	return analogRead(SENSOR_IN);
}


AirSensor::AirSensor(int requiredSamples, int skippedSamples) : thresholds{10000, 10000, 10000, 10000, 10000, 10000}, calibrationSamples{0, 0, 0, 0, 0, 0}, skippedSamples{0, 0, 0, 0, 0, 0}, samplesToAcquire(requiredSamples), samplesToSkip(skippedSamples), calibrated{0, 0, 0, 0, 0, 0}, allCalibrated(false)
{
	EEPROM.get(12, deadzone);
	EEPROM.get(16, alpha);
}

bool AirSensor::isCalibrated()
{
	if(!allCalibrated)
	{
		for(int i = 0; i < 6; i++)
		{
			if(!calibrated[i])
				return false;
		}
		allCalibrated = true;
	}
	return allCalibrated;
}

bool AirSensor::getSensorState(int sensor)
{
	int value = getValue(sensor, true);
	turnOffLight();

	if(allCalibrated || calibrated[sensor]){
		sensorValues[sensor] = (float) value * EMA_AIRSENSOR_ALPHA + sensorValues[sensor] * (1 - EMA_AIRSENSOR_ALPHA); 
		return sensorValues[sensor] < thresholds[sensor];
	}
	else
	{
		if(skippedSamples[sensor] > samplesToSkip)
		{
			if(value < thresholds[sensor]) thresholds[sensor] = value;
			if(++calibrationSamples[sensor] > samplesToAcquire)
			{
				sensorValues[sensor] = value;
				calibrated[sensor] = true;
				thresholds[sensor] -= AIR_SENSOR_THRESHOLD_SUBTRACT;
			};
		}
		else
		{
			skippedSamples[sensor]++;
		}
		return false;
	}
}

float AirSensor::getHandPosition()
{
	float total = 0;
	float sensorsTriggered = 0;
	for(int i = 0; i < 6; i++)
	{
		if(getSensorState(i))
		{
			sensorsTriggered++;
			total += i + 1;
		}
	}
	return sensorsTriggered == 0 ? 0 : (total / (sensorsTriggered)) / 6;
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
	for(int i = 0; i < 6; i++)
	{
		thresholds[i] = 0;
		calibrationSamples[i] = 0;
		skippedSamples[i] = 0;
		sensorValues[i] = 0;
		calibrated[i] = false;
	}
	allCalibrated = false;
}
