// USBOutput.h

#ifndef _USBOUTPUT_h
#define _USBOUTPUT_h

#include "Config.h"
#include "Output.h"

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#ifndef TEENSY
#include <HID-Project.h>
#endif

class USBOutput : public Output
{
  private:
    float lastPosition;
    void writeKey(char key);
    void pressKey(char key);
    void releaseKey(char key);
  public:
    void sendKeyEvent(int key, bool pressed, bool doublePressed) override;
    void sendSensorEvent(float position) override;
    USBOutput();
};

#endif
