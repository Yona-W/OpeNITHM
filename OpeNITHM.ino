#if defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega32u4__)
#include "USBOutput.h"
#define USB
#endif

#ifdef USB
#include "USBOutput.h"
#else
#include "SerialOutput.h"
#endif
#include "AirSensor.h"
#include "Touchboard.h"
#include <FastLED.h>
#include <Keyboard.h>

CRGB leds[16];

float lightIntensity[16];
bool keyStates[16];
bool activated = true;
float sensorPosition = -1;

Touchboard *touchboard;
AirSensor *sensor;
Output *output;

char *command;

void onKeyPress(int key, bool wasHeld)
{
	lightIntensity[key] = 1.0f;
	output->sendKeyEvent(key, true, wasHeld);
	keyStates[key] = true;
}

void parseCommand()
{
	char input1 = Serial.read();
	char input2 = Serial.read();
	switch (input1)
	{
	case 't':
		switch (input2)
		{
		case 't':
			touchboard->setThreshold(Serial.parseInt());
			break;
		case 'd':
			touchboard->setDeadzone(Serial.parseInt());
			break;
		case 'a':
			touchboard->setAlpha(Serial.parseFloat());
			break;
		case 'c':
			touchboard->calibrateKeys();
		}
		break;
	case 'i':
		switch (input2)
		{
		case 'd':
			sensor->setDeadzone(Serial.parseInt());
			break;
		case 'a':
			sensor->setAlpha(Serial.parseFloat());
			break;
		case 'c':
			sensor->recalibrate();
		}
		break;
	case 'p':
		activated = false;
		break;
	case 'r':
		activated = true;
		break;
	}

	Serial.print("tt \t");
	Serial.println(touchboard->getThreshold());
	Serial.print("td \t");
	Serial.println(touchboard->getDeadzone());
	Serial.print("ta \t");
	Serial.println(touchboard->getAlpha());
	Serial.print("id \t");
	Serial.println(sensor->getDeadzone());
	Serial.print("ia \t");
	Serial.println(sensor->getAlpha());
	Serial.print(";");
}

void setup() {
	Serial.begin(112500);
	command = malloc(32);

	FastLED.addLeds<LED_TYPE, RGBPIN, LED_ORDER>(leds, 16);

	for (CRGB& led : leds)
	{
		led = 0x0000FF;
		FastLED.show();
	}

	touchboard = new Touchboard(onKeyPress);

	for (CRGB& led : leds)
	{
		led = 0xFF0000;
		FastLED.show();
	}

	sensor = new AirSensor(500, 50);
	#ifdef USB
		output = new USBOutput();
	#else
		output = new SerialOutput();
	#endif
}

void loop() {
	if (!activated) return;

	// Scan touch keyboard and update lights
	touchboard->scan();
	for (int i = 0; i < 16; i++)
	{
		if (lightIntensity[i] > 0.05f)
			lightIntensity[i] -= 0.05f;
		if (touchboard->update(i))
		{
			leds[i].setRGB(128 + 127 * lightIntensity[i], 0, 128 + 127 * lightIntensity[i]);
		}
		else
		{
			leds[i].setRGB(128, 128, 0);
			if (keyStates[i])
			{
				output->sendKeyEvent(i, false, false);
				keyStates[i] = false;
			}
		}
	}

	const float newPosition = sensor->getHandPosition();
	if (newPosition != sensorPosition)
	{
		output->sendSensorEvent(newPosition);
		sensorPosition = newPosition;
	}


	// If the air sensor is calibrated, begin updating lights. The air sensor will automatically calibrate as it is being polled.
	if (sensor->isCalibrated())
		FastLED.show();

	if (Serial.available())
	{
		parseCommand();
	}
}

