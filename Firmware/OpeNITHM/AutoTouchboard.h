// Touchboard.h

#ifndef _TOUCHBOARD_h
#define _TOUCHBOARD_h

#include "Config.h"
#include "PinConfig.h"
#include "RunningSum.h"
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

// the size of the buffer of deltas to keep for each key
#define NUM_READINGS 10

class AutoTouchboard
{
  private:
    // these will be tunable / need to be experimented with
#if NUM_SENSORS == 32
    int deltaThreshold = 4;
    int releaseHysteresis = 1;
#else
    int deltaThreshold = 6;
    int releaseHysteresis = 2;
#endif
    
    uint16_t key_values[NUM_SENSORS];
    KeyState states[NUM_SENSORS];
    int releaseThresholdsSingle[NUM_SENSORS];
    int releaseThresholdsDouble[NUM_SENSORS];
    int lastReadings[NUM_SENSORS];
    RunningSum* deltas[NUM_SENSORS];

  public:
    AutoTouchboard();
    void scan();
    KeyState update(int key);
    uint16_t getRawValue(int key);
    void calibrateKeys();
};

#endif
