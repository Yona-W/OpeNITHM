// Touchboard.h

#ifndef _TOUCHBOARD_h
#define _TOUCHBOARD_h

#include "Config.h"
#include "PinConfig.h"
#include "USBOutput.h"

#include <EEPROM.h>
#include <WS2812Serial.h>
#define USE_WS2812SERIAL
#include <FastLED.h>

#define CALIBRATION_SAMPLES 80
#define CALIBRATION_DETECTION_THRESHOLD 6
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
    uint16_t key_values[NUM_SENSORS];
    uint16_t thresholds[NUM_SENSORS];

  public:
    AutoTouchboard();
    void scan();
    void loadConfig();
    void saveConfig();
    bool update(int key);
    uint16_t getRawValue(int key);
    void calibrateKeys(bool forceCalibrate = false);
};

#endif
