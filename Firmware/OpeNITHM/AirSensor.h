// AirSensor.h

#ifndef _AIRSENSOR_h
#define _AIRSENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "PinConfig.h"
#include <EEPROM.h>

#define DEFAULT_SENSITIVITY 85

class AirSensor
{
  private:
    void changeLight(int light);
    void turnOffLight();

    uint8_t analogSensitivity;
    int thresholds[6];
    int samplesToAcquire;
    int samplesToSkip;

    bool calibrated[6];
    bool digitalMode;
    
  public:
    AirSensor(int requiredSamples, int skippedSamples);
    void analogCalibrate();
    bool isCalibrated();
    bool isDigital();
    bool getSensorState(int sensor);
    int getValue(int sensor, bool light);
    float getHandPosition();
    uint8_t getSensorReadings();
    bool getSensorCalibrated(int i);
    void setAnalogSensitivity(uint8_t analogSensitivity);
    uint8_t getAnalogSensitivity();
    void recalibrate();
};


#endif
