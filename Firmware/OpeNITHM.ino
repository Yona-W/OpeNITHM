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

CRGB leds[16];

CRGB led_on = 0xFF00FF; // purple
CRGB led_off = 0xFFFF00; // yellow

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

// Parse configuration command. For now, a serial terminal is required (like the monitor in Arduino IDE)
// Eventually I will make a config tool
void parseCommand()
{
	char input1 = Serial.read();
	char input2;
	switch (input1)
	{
	case 't': // touchboard
		while(!Serial.available());
		input2 = Serial.read();
		while(!Serial.available());
		switch (input2)
		{
		case 't': // threshold
			touchboard->setThreshold(Serial.parseInt());
			break;
		case 'd': // dead zone
			touchboard->setDeadzone(Serial.parseInt());
			break;
		case 'a': // alpha
			touchboard->setAlpha(Serial.parseFloat());
			break;
		case 'c': // calibrate
			touchboard->calibrateKeys();
		}
		break;
	case 'i': // ir sensors
		while(!Serial.available());
		input2 = Serial.read();
		while(!Serial.available());
		switch (input2)
		{
		case 'd': // dead zone
			sensor->setDeadzone(Serial.parseInt());
			break;
		case 'a': // alpha
			sensor->setAlpha(Serial.parseFloat());
			break;
		case 'c': // calibrate
			sensor->recalibrate();
		}
		break;
	case 'p': // pause
		activated = false;
		break;
	case 'r': // resume
		activated = true;
		break;
	case 'g': // print values
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
		Serial.print("lor \t");
		Serial.println(led_on.r);
		Serial.print("log \t");
		Serial.println(led_on.g);
		Serial.print("lob \t");
		Serial.println(led_on.b);
		Serial.print("lfr \t");
		Serial.println(led_off.r);
		Serial.print("lfg \t");
		Serial.println(led_off.g);
		Serial.print("lfb \t");
		Serial.println(led_off.b);
		Serial.print(";");
		break;
	case 'a': // check if activated
		Serial.println(activated);
		Serial.print(";");
		break;
	case 'l': // change led color
		while(!Serial.available());
		input2 = Serial.read();
		while(!Serial.available());
		switch (input2)
		{
		case 'o': // on
			while(!Serial.available());
			switch ((char)Serial.read())
			{
			case 'r': // red
				led_on.r = Serial.parseInt(); // for now this has to be expressed in decimal
				break;
			case 'g': // green
				led_on.g = Serial.parseInt();
				break;
			case 'b': // blue
				led_on.b = Serial.parseInt();
				break;
			case 'e': // everything
				led_on = Serial.parseInt();
			}
			break;
		case 'f': // off
			while(!Serial.available());
			switch ((char)Serial.read())
			{
			case 'r': // red
				led_off.r = Serial.parseInt(); // for now this has to be expressed in decimal
				break;
			case 'g': // green
				led_off.g = Serial.parseInt();
				break;
			case 'b': // blue
				led_off.b = Serial.parseInt();
				break;
			case 'e': // everything
				led_off = Serial.parseInt();
			}
			break;
		}
		break;
	}
}

void setup() {
	Serial.begin(115200);
	command = malloc(32);

	FastLED.addLeds<LED_TYPE, RGBPIN, LED_ORDER>(leds, 16);

	// Set LEDs blue
	for (CRGB& led : leds)
	{
		led = 0x0000FF;
		FastLED.show();
	}

	// Initialize and calibrate touch sensors
	touchboard = new Touchboard(onKeyPress);

	// Set LEDs red
	for (CRGB& led : leds)
	{
		led = 0xFF0000;
		FastLED.show();
	}

	// Initialize air sensor - will automatically calibrate as it starts being read
	sensor = new AirSensor(500, 50);

	// Initialize relevant output method / USB or serial
	#ifdef USB
		output = new USBOutput();
	#else
		output = new SerialOutput();
	#endif
}

void loop() {
	// Process config commands
	if (Serial.available())
	{
		parseCommand();
	}

	// If currently paused through a config command, do not execute main loop
	if (!activated) return;

	// Scan touch keyboard and update lights
	touchboard->scan();
	for (int i = 0; i < 16; i++)
	{
		if (lightIntensity[i] > 0.05f)
			lightIntensity[i] -= 0.05f;

		// If the key is currently being held, set its color to purple
		if (touchboard->update(i))
		{
			leds[i].setRGB(min(led_on.r / 2 + led_on.r / 2 * lightIntensity[i], 255), min(led_on.g / 2 + led_on.g / 2 * lightIntensity[i], 255), min(led_on.b / 2 + led_on.b / 2 * lightIntensity[i], 255));
		}
		else
		{
			// If not, make it yellow and send the "key released" event if it was previously pressed
			leds[i].setRGB(led_off.r/2, led_off.g/2, led_off.b/2);
			if (keyStates[i])
			{
				output->sendKeyEvent(i, false, false);
				keyStates[i] = false;
			}
		}
	}

	// Process air sensor hand position
	const float newPosition = sensor->getHandPosition();
	if (newPosition != sensorPosition)
	{
		output->sendSensorEvent(newPosition);
		sensorPosition = newPosition;
	}


	// If the air sensor is calibrated, update lights. The lights will stay red as long as the air sensor is not calibrated. 
	if (sensor->isCalibrated())
		FastLED.show();
}