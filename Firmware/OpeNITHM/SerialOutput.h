// SerialOutput.h

#ifndef _SERIALOUTPUT_h
#define _SERIALOUTPUT_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#include "Output.h"

//All events can fit within one byte to save time sending over serial
union Packet
{
  uint8_t data;
  struct
  {
    bool isKeyboard : 1;
    bool isPressed : 1;
    bool isDoublePressed : 1;
    unsigned int key : 5;
  } keyEvent;
  struct
  {
    bool isKeyboard : 1;
    int position : 7;
  } sensorEvent;
};


class SerialOutput : public Output
{
  private:
    Packet builtPacket = Packet();
  public:
    void sendKeyEvent(int key, bool pressed, bool doublePressed) override;
    void sendSensorEvent(float position) override;
    void sendSensor(int sensor) override;
};

#endif
