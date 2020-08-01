// USBOutput.h

#ifndef _USBOUTPUT_h
#define _USBOUTPUT_h

#include "Config.h"

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

enum KeyState 
{
  UNPRESSED,
  SINGLE_PRESS,
  DOUBLE_PRESS
};

class USBOutput
{
  private:
    float lastPosition;
    bool wasAirHeld;
    void writeKey(uint16_t key);
    void pressKey(uint16_t key);
    void releaseKey(uint16_t key);
  public:
    void sendKeyEvent(int key, bool pressed, bool doublePressed);
    void sendKeyEvent(int key, KeyState keyState);
    void sendSensorEvent(float position);
    void sendSensor(int sensor);
    void sendUpdate();
    USBOutput();
};

#endif
