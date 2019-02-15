#define USBCON
#include <HID-Project.h>

// USBOutput.h

#ifndef _USBOUTPUT_h
#define _USBOUTPUT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "Output.h"


class USBOutput : public Output
{
private:
  float lastPosition;
public:
	void sendKeyEvent(int key, bool pressed, bool doublePressed) override;
	void sendSensorEvent(float position) override;
  USBOutput();
};

#endif

