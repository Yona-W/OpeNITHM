// Touchboard.h

#ifndef _TOUCHBOARD_h
#define _TOUCHBOARD_h

#include "Config.h"
#include "PinConfig.h"
#include "RunningSum.h"
#include "USBOutput.h"

#include <EEPROM.h>
#include <WS2812Serial.h>
#define USE_WS2812SERIAL
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
    // these will be tunable / need to be experimented ith
    int deltaThreshold = 5;
    int releaseHysteresis = 2;
    
    uint16_t key_values[NUM_SENSORS];
    bool states[NUM_SENSORS];
    int releaseThresholds[NUM_SENSORS];
    int lastReadings[NUM_SENSORS];
    RunningSum* deltas[NUM_SENSORS];

  public:
    AutoTouchboard();
    void scan();
    bool update(int key);
    uint16_t getRawValue(int key);
    void calibrateKeys();
};

#endif
