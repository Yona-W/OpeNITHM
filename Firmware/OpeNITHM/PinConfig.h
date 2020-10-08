#include "Config.h"

#ifndef _PINCONFIG_h
#define _PINCONFIG_h

// Multiplexer pin settings
#if defined(OPENITHM_V2_0)
#define MUX_0 0
#define MUX_1 1
#define MUX_2 2
#elif defined(OPENITHM_V2_1)
#define MUX_0 2
#define MUX_1 3
#define MUX_2 4
#endif

// Sensor pin settings
#if defined(OPENITHM_V2_0)
#define LED_0 7
#define LED_1 6
#define LED_2 5
#elif defined(OPENITHM_V2_1)
#define LED_0 8
#define LED_1 7
#define LED_2 6
#endif

#define AIR_SENSOR_0_PIN 18
#define AIR_SENSOR_1_PIN 20
#define AIR_SENSOR_2_PIN 22
#define AIR_SENSOR_3_PIN 19
#define AIR_SENSOR_4_PIN 21
#define AIR_SENSOR_5_PIN 23

// Capsense pin settings
#if defined(OPENITHM_V2_0)
#define TOUCH_0 16
#define TOUCH_1 3
#define TOUCH_2 4
#define TOUCH_3 15
#elif defined(OPENITHM_V2_1)
#define TOUCH_0 16
#define TOUCH_1 0
#define TOUCH_2 1
#define TOUCH_3 15
#endif

// Lighting pin settings
#define LED_TYPE    WS2812SERIAL
#define LED_ORDER   BRG

#if defined(OPENITHM_V2_0)
  #define RGBPIN 24
#elif defined(OPENITHM_V2_1)
  #define RGBPIN 5
#endif

#endif  // _PINCONFIG_h
