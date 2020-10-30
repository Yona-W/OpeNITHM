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
#define AIR_INPUT_DETECTION 0.90
#define CALIBRATION_SAMPLES 200
#define SKIP_SAMPLES 40

#ifndef KEY_DIVIDERS
extern CRGB leds[16];
#else
extern CRGB leds[31];
#endif

extern AutoTouchboard *touchboard;

class AirSensor {
  private:
    int calibrationCounter;
    bool calibrated;
    uint16_t thresholds[6];
    uint16_t maxReadings[6];
    
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
