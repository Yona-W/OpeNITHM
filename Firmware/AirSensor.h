// AirSensor.h

#ifndef _AIRSENSOR_h
#define _AIRSENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "PinConfig.h"
#include <EEPROM.h>

#ifndef IR_SENSOR_MULTIPLEXED
	int ir_sensor_pins[6] = {AIR_SENSOR_0_PIN, AIR_SENSOR_1_PIN, AIR_SENSOR_2_PIN, AIR_SENSOR_3_PIN, AIR_SENSOR_4_PIN, AIR_SENSOR_5_PIN};
#endif

class AirSensor
{
private:
	void changeLight(int light);
	void turnOffLight();

	int thresholds[6];
	int calibrationSamples[6];
	int skippedSamples[6];
	float sensorValues[6];
	int samplesToAcquire;
	int samplesToSkip;

	bool calibrated[6];
	bool allCalibrated;

	uint16_t deadzone;
	float alpha;
public:
	AirSensor(int requiredSamples, int skippedSamples);
	bool isCalibrated();
	bool getSensorState(int sensor);
	int getValue(int sensor, bool light);
	float getHandPosition();

	void setDeadzone(int deadzone);
	void setAlpha(float alpha);
	int getDeadzone();
	float getAlpha();
	void recalibrate();
};


#endif

