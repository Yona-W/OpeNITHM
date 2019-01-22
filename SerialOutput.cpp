// 
// 
// 

#include "SerialOutput.h"

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
