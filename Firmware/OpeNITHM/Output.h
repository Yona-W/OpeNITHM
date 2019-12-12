// Output.h

#ifndef _OUTPUT_h
#define _OUTPUT_h

class Output
{
  public:
    virtual void sendKeyEvent(int key, bool pressed, bool doublePressed);
    virtual void sendSensorEvent(float position);
    virtual void sendSensor(int sensor);
    virtual void sendUpdate();
};

#endif
