// Touchboard.h

#ifndef _TOUCHBOARD_h
#define _TOUCHBOARD_h

#include "PinConfig.h"
#ifndef TEENSY
#include "CapacitiveSensor.h"
#endif
#include <EEPROM.h>

#define EMA_TOUCHDETECT_ALPHA 0.1f
#define CALIBRATION_SAMPLES 25

class Touchboard
{
  private:
#ifndef TEENSY
    CapacitiveSensor sensor;
#endif

    uint16_t threshold;
    uint16_t deadzone;
    float alpha;

    float em_averages[16];
    unsigned int keys[16];
    int neutral_values[16];
    void (*onKeyPress)(int, bool);

  public:
    bool key_states[16];

    Touchboard(void(*keyPressCallback)(int, bool));
    void scan();
    bool update(int key);
    void setThreshold(uint16_t threshold);
    void setDeadzone(uint16_t deadzone);
    void setAlpha(float alpha);
    int getThreshold();
    int getDeadzone();
    float getAlpha();
    float getNeutralValue(int key);
    float getEmAverages(int key);
    float getRawValue(int key);
    void calibrateKeys();
};

#endif
