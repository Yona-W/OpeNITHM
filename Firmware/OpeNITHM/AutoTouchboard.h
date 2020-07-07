// Touchboard.h

#ifndef _TOUCHBOARD_h
#define _TOUCHBOARD_h

#include "Config.h"
#include "Output.h"
#include "PinConfig.h"
#ifndef TEENSY
#include "CapacitiveSensor.h"
#endif
#include <EEPROM.h>

#include <WS2812Serial.h>
#define USE_WS2812SERIAL
#include <FastLED.h>

#define CALIBRATION_SAMPLES 200
#define CALIBRATION_DETECTION_THRESHOLD 10
#define CALIBRATION_FLAG 0xA2
#define TOUCH_INPUT_THRESHOLD 0.85

#ifndef KEY_DIVIDERS
extern CRGB leds[16];
#else
extern CRGB leds[31];
#endif

class AutoTouchboard
{
  private:
#ifndef TEENSY
    CapacitiveSensor sensor;
#endif
    uint16_t key_values[16];
    uint16_t single_thresholds[16];
    uint16_t double_thresholds[16];

  public:
    AutoTouchboard();
    void scan();
    void loadConfig();
    void saveConfig();
    KeyState update(int key);
    uint16_t getRawValue(int key);
    void calibrateKeys(bool forceCalibrate = false);
};

#endif
