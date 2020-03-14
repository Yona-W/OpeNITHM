// SerialProcessor.h

#ifndef _SERIALPROCESSOR_h
#define _SERIALPROCESSOR_h

#include "AirSensor.h"
#include "AutoTouchboard.h"
#include "Config.h"
#include "SerialLeds.h"

#include <FastLED.h>

// magic bytes we look for in the packet headers to identify whether it's LED updates or config commands
#define LED_FLAG 0xAA
#define CONFIG_FLAG 0xBB

// config command opcodes
#define CMD_CHANGE_LIGHT_MODE 0x11
#define CMD_CHANGE_ON_COLOR 0x22
#define CMD_CHANGE_OFF_COLOR 0x33
#define CMD_CALIBRATE_SLIDER 0x44
#define CMD_CALIBRATE_AIR_SENSORS 0x55

// light modes for the change light mode command
#define LIGHT_MODE_SERIAL 0x00
#define LIGHT_MODE_REACTIVE 0x01

extern AirSensor *sensor;
extern AutoTouchboard *touchboard;
extern SerialLeds *serialLeds;
extern bool useSerialLeds;
extern CRGB leds[16];
extern CRGB led_on;
extern CRGB led_off;
extern int serialLightsCounter;

class SerialProcessor
{
  private:
    void processConfigCommand(uint8_t* buf);
  public:
    SerialProcessor();
    void processBulk(uint8_t* buf);
};

#endif
