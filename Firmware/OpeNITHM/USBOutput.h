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
    bool wasAirHeld;
    void writeKey(uint16_t key);
    void pressKey(uint16_t key);
    void releaseKey(uint16_t key);
  public:
    void sendKeyEvent(int key, bool pressed, bool doublePressed) override;
    void sendKeyEvent(int key, KeyState keyState) override;
    void sendSensorEvent(float position) override;
    void sendSensor(int sensor) override;
    void sendUpdate() override;
    USBOutput();
};

#endif
