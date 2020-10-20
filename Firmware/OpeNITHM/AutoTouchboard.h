// Touchboard.h

#ifndef _TOUCHBOARD_h
#define _TOUCHBOARD_h

#include "Config.h"
#include "PinConfig.h"
#include "USBOutput.h"

#include <EEPROM.h>

#ifdef USE_DMA_RGB
  #include <WS2812Serial.h>
  #define USE_WS2812SERIAL
#endif

#include <FastLED.h>

// for hit detection, we keep a running record of the last X number
// of arrow readings and the deltas from their last readings

#ifndef KEY_DIVIDERS
extern CRGB leds[16];
#else
extern CRGB leds[31];
#endif

class AutoTouchboard
{
  private:
    // these will be tunable / need to be experimented with
#if NUM_SENSORS == 32
    int deltaThreshold = 5;
    double releaseThreshold = 0.8;
#else
    int deltaThreshold = 6;
    double releaseThreshold = 0.8;
#endif
    
    uint16_t key_values[NUM_SENSORS];
    KeyState states[NUM_SENSORS];
    int triggerThresholdsSingle[NUM_SENSORS];
    int releaseThresholdsSingle[NUM_SENSORS];
    int triggerThresholdsDouble[NUM_SENSORS];
    int releaseThresholdsDouble[NUM_SENSORS];
    
    void calcThresholds(int key, int pressure);

  public:
    AutoTouchboard();
    void scan();
    KeyState update(int key);
    uint16_t getRawValue(int key);
    void calibrateKeys();
};

#endif
