#ifndef __SERIALLEDS_h
#define __SERIALLEDS_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

extern bool updateLeds;

typedef struct {
  uint8_t b;
  uint8_t r;
  uint8_t g;
} RGBLed;

class SerialLeds
{
  private:
    uint8_t lastBuffer[100];

  public:
    SerialLeds();
    void processBulk(uint8_t *buf);
    RGBLed getKey(uint8_t key); // Left to Right

    union {
      RGBLed rgb[32];
      uint8_t raw[96];
    } ledData;
};

#endif
