#include "Config.h"

#ifndef _PINCONFIG_h
#define _PINCONFIG_h

// Multiplexer pin settings
#if defined(OPENITHM_V1_0)
#define MUX_0 20
#define MUX_1 19
#define MUX_2 18
#elif defined(OPENITHM_V1_1)
#define MUX_0 2
#define MUX_1 1
#define MUX_2 0
#elif defined(OPENITHM_V2_0)
#define MUX_0 0
#define MUX_1 1
#define MUX_2 2
#elif defined(OPENITHM_V2_1)
#define MUX_0 2
#define MUX_1 3
#define MUX_2 4
#endif

// Sensor pin settings
#if defined(OPENITHM_V1_0)
#define LED_0 16
#define LED_1 21
#define LED_2 5
#elif defined(OPENITHM_V1_1) || defined(OPENITHM_V2_0)
#define LED_0 7
#define LED_1 6
#define LED_2 5
#elif defined(OPENITHM_V2_1)
#define LED_0 8
#define LED_1 7
#define LED_2 6
#endif

#ifdef IR_SENSOR_MULTIPLEXED
#define SENSOR_IN A0
#else
#if defined(OPENITHM_V1_0)
#define AIR_SENSOR_0_PIN 10
#define AIR_SENSOR_1_PIN 11
#define AIR_SENSOR_2_PIN 12
#define AIR_SENSOR_3_PIN 6
#define AIR_SENSOR_4_PIN 8
#define AIR_SENSOR_5_PIN 9
#elif defined(OPENITHM_V1_1)
#define AIR_SENSOR_0_PIN 20
#define AIR_SENSOR_1_PIN 19
#define AIR_SENSOR_2_PIN 18
#define AIR_SENSOR_3_PIN 23
#define AIR_SENSOR_4_PIN 22
#define AIR_SENSOR_5_PIN 21
#elif defined(OPENITHM_V2_0) || defined(OPENITHM_V2_1)
#define AIR_SENSOR_0_PIN 18
#define AIR_SENSOR_1_PIN 20
#define AIR_SENSOR_2_PIN 22
#define AIR_SENSOR_3_PIN 19
#define AIR_SENSOR_4_PIN 21
#define AIR_SENSOR_5_PIN 23
#endif
#endif

// Capsense pin settings
#if defined(OPENITHM_V1_0)
#define TOUCH_0 22
#define TOUCH_1 23
#elif defined(OPENITHM_V1_1)
#define TOUCH_0 16
#define TOUCH_1 3
#elif defined(OPENITHM_V2_0)
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
#ifdef USE_DMA_RGB
  #define LED_TYPE    WS2812SERIAL
  #define LED_ORDER   BRG
#else
  #define LED_TYPE    WS2812B
  #define LED_ORDER   GRB
#endif

#if defined(OPENITHM_V1_0)
  #define RGBPIN 4
#elif defined(OPENITHM_V1_1) || defined(OPENITHM_V2_0)
    #ifdef USE_DMA_RGB
       #define RGBPIN 24
    #else
       #define RGBPIN 11
    #endif
#elif defined(OPENITHM_V2_1)
  #define RGBPIN 5
#endif

#endif  // _PINCONFIG_h
