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

#define AIR_LED_DELAY 125
#define AIR_INPUT_DETECTION 0.85
#define AIR_INPUT_THRESHOLD 0.50
#define CALIBRATION_FLAG 0xF6

#ifndef KEY_DIVIDERS
extern CRGB leds[16];
#else
extern CRGB leds[31];
#endif

extern AutoTouchboard *touchboard;

class AirSensor
{
  private:
    void changeLight(int light);
    void turnOffLight();
    void setHalfLEDs(CRGB color, int side);

    uint16_t thresholds[6];
    int samplesToAcquire;
    int samplesToSkip;

    bool calibrated[6];
    bool digitalMode;
    
  public:
    AirSensor(int requiredSamples, int skippedSamples);
    void loadConfig();
    void saveConfig();
    void analogCalibrate();
    bool isCalibrated();
    bool isDigital();
    bool getSensorState(int sensor);
    uint16_t getValue(int sensor);
    float getHandPosition();
    uint8_t getSensorReadings();
    bool getSensorCalibrated(int i);
    void recalibrate();
};


#endif
