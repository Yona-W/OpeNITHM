// Output.h

#ifndef _OUTPUT_h
#define _OUTPUT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Output
{
 public:
	virtual void sendKeyEvent(int key, bool pressed, bool doublePressed);
	virtual void sendSensorEvent(float position);
};

#endif

