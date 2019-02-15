// 
// 
// 
#include "AirSensor.h"


// Sets the output pins to switch the charlieplexed array of LEDs.
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

// Sets all output pins to high-impedance to turn off all LEDs
void AirSensor::turnOffLight()
{
	pinMode(IR_A, INPUT);
	pinMode(IR_B, INPUT);
	pinMode(IR_C, INPUT);
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
	return analogRead(SENSOR_IN);
#else
	return analogRead(ir_sensor_pins[sensor]);
#endif
}


AirSensor::AirSensor(int requiredSamples, int skippedSamples) : thresholds{ 10000, 10000, 10000, 10000, 10000, 10000 }, calibrationSamples{ 0, 0, 0, 0, 0, 0 }, skippedSamples{ 0, 0, 0, 0, 0, 0 }, samplesToAcquire(requiredSamples), samplesToSkip(skippedSamples), calibrated{ 0, 0, 0, 0, 0, 0 }, allCalibrated(false)
{
	// Load config values
	EEPROM.get(12, deadzone);
	EEPROM.get(16, alpha);
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
}

// Using data from air sensors, compute the height of the player's hand, from 0 (not present) to 1 (highest possible position).
float AirSensor::getHandPosition()
{
	float total = 0;
	float sensorsTriggered = 0;
	for (int i = 0; i < 6; i++)
	{
		if (getSensorState(i))
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
