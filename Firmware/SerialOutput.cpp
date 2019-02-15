// 
// 
// 

#include "SerialOutput.h"

// Workaround for microcontrollers without USB functionality
// use a serial line to talk to a UC with USB, which will then act as a USB peripheral
// Only needed because I didn't receive my Atmega328p until late in the project

void SerialOutput::sendKeyEvent(int key, bool pressed, bool doublePressed)
{
	builtPacket.data = 0;
	builtPacket.keyEvent.isKeyboard = true;
	builtPacket.keyEvent.isPressed = pressed;
	builtPacket.keyEvent.isDoublePressed = doublePressed;
	builtPacket.keyEvent.key = key;

	Serial.write(builtPacket.data);
}

void SerialOutput::sendSensorEvent(float position)
{
	builtPacket.data = 0;
	builtPacket.sensorEvent.isKeyboard = false;
	builtPacket.sensorEvent.position = position * 127;

	Serial.write(builtPacket.data);
}
