// Touchboard.h

#ifndef _TOUCHBOARD_h
#define _TOUCHBOARD_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "PinConfig.h"
#include "CapacitiveSensor.h"
#include <EEPROM.h>
#define EMA_TOUCHDETECT_ALPHA 0.1f

class Touchboard
{
private:
	CapacitiveSensor sensor;


	uint16_t threshold;
	uint16_t deadzone;
	float alpha;

	float em_averages[16];
	unsigned int keys[16];
	int neutral_values[16];
	void (*onKeyPress)(int, bool);


public:
	boolean key_states[16];

	Touchboard(void(*keyPressCallback)(int, bool));
	void scan();
	bool update(int key);
	void setThreshold(uint16_t threshold);
	void setDeadzone(uint16_t deadzone);
	void setAlpha(float alpha);
	int getThreshold();
	int getDeadzone();
	float getAlpha();
	void calibrateKeys();
};

#endif

