#ifndef __SERIALLEDS_h
#define __SERIALLEDS_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

typedef struct {
  uint8_t b;
  uint8_t r;
  uint8_t g;
} RGBLed;

class SerialLeds
{
  private:
    enum state
    {
      headerSearch,
      headerConfirm,
      dataRead
    };

    uint8_t dataBuffer[100];
    uint8_t lastBuffer[100];
    state currentState = headerSearch;
    uint8_t currentReadNum = 0;

  public:
    SerialLeds();
    bool process(uint8_t in);
    bool processBulk(uint8_t *buf, size_t length);
    RGBLed getKey(uint8_t key); // Left to Right

    union {
      RGBLed rgb[32];
      uint8_t raw[96];
    } ledData;
};

#endif
