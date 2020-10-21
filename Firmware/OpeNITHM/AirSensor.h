// AirSensor.h

#ifndef _AIRSENSOR_h
#define _AIRSENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "AutoTouchboard.h"
#include "PinConfig.h"
#include <EEPROM.h>

#ifdef USE_DMA_RGB
  #include <WS2812Serial.h>
  #define USE_WS2812SERIAL
#endif

#include <FastLED.h>

#define AIR_LED_DELAY 135

#ifndef KEY_DIVIDERS
extern CRGB leds[16];
#else
extern CRGB leds[31];
#endif

class AirSensor {
  private:
    int deltaThreshold = 80;
    double releaseThreshold = 0.5;
    int calibrationCounter;
    bool calibrated;
    bool states[6];
    int triggerThresholds[6];
    int releaseThresholds[6];
    
    void calcThresholds(int sensor, int value);
    void changeLight(int light);
    void turnOffLight();
    
  public:
    AirSensor();
    void analogCalibrate();
    bool isCalibrated() { return calibrated; }
    bool getSensorState(int sensor);
    uint16_t getValue(int sensor);
    float getHandPosition();
    uint8_t getSensorReadings();
};


#endif
