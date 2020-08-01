// SerialProcessor.h

#ifndef _SERIALPROCESSOR_h
#define _SERIALPROCESSOR_h

#include "AirSensor.h"
#include "AutoTouchboard.h"
#include "Config.h"
#include "SerialLeds.h"

#ifdef USE_DMA_RGB
  #include <WS2812Serial.h>
  #define USE_WS2812SERIAL
#endif
#include <FastLED.h>

// magic bytes we look for in the packet headers to identify whether it's LED updates or config commands
#define LED_FLAG 0xAA
#define CONFIG_FLAG 0xBB

// config command opcodes
#define CMD_PRINT_INFO 0x11
#define CMD_CHANGE_ON_COLOR 0x22
#define CMD_CHANGE_OFF_COLOR 0x33
#define CMD_CALIBRATE_SLIDER 0x44
#define CMD_CALIBRATE_AIR_SENSORS 0x55
#define CMD_FACTORY_RESET 0x66

extern AirSensor *sensor;
extern AutoTouchboard *touchboard;
extern SerialLeds *serialLeds;
extern bool useSerialLeds;
#ifndef KEY_DIVIDERS
extern CRGB leds[16];
#else
extern CRGB leds[31];
#endif
extern CRGB led_on;
extern CRGB led_off;
extern int serialLightsCounter;

extern void initializeController();

class SerialProcessor
{
  private:
    void processConfigCommand(uint8_t* buf);
  public:
    SerialProcessor();
    void processBulk(uint8_t* buf);
};

#endif
