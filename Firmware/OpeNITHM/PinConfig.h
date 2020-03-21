#include "Config.h"

#ifndef _PINCONFIG_h
#define _PINCONFIG_h


// Multiplexer pin settings
#ifdef TEENSY               // Teensy LC
#if defined(TEENSY_V1_0)
#define MUX_0 20
#define MUX_1 19
#define MUX_2 18
#elif defined(TEENSY_V1_1)
#define MUX_0 2
#define MUX_1 1
#define MUX_2 0
#endif
#else                       // Pro Micro
#define MUX_0 20
#define MUX_1 19
#define MUX_2 18
#endif

// Sensor pin settings
#ifdef TEENSY
#if defined(TEENSY_V1_0)
#define LED_0 16
#define LED_1 21
#define LED_2 5
#elif defined(TEENSY_V1_1)
#define LED_0 7
#define LED_1 6
#define LED_2 5
#endif
#else
#define LED_0 0
#define LED_1 2
#define LED_2 3
#endif

#ifdef IR_SENSOR_MULTIPLEXED
#define SENSOR_IN A0
#else
#ifdef TEENSY
#if defined(TEENSY_V1_0)
#define AIR_SENSOR_0_PIN 10
#define AIR_SENSOR_1_PIN 11
#define AIR_SENSOR_2_PIN 12
#define AIR_SENSOR_3_PIN 6
#define AIR_SENSOR_4_PIN 8
#define AIR_SENSOR_5_PIN 9
#elif defined(TEENSY_V1_1)
#define AIR_SENSOR_0_PIN 20
#define AIR_SENSOR_1_PIN 19
#define AIR_SENSOR_2_PIN 18
#define AIR_SENSOR_3_PIN 23
#define AIR_SENSOR_4_PIN 22
#define AIR_SENSOR_5_PIN 21
#endif
#else
#define AIR_SENSOR_0_PIN 4
#define AIR_SENSOR_1_PIN 5
#define AIR_SENSOR_2_PIN 6
#define AIR_SENSOR_3_PIN 7
#define AIR_SENSOR_4_PIN 8
#define AIR_SENSOR_5_PIN 9
#endif
#endif

// Capsense pin settings
#define RECEIVE_1 21
#define RECEIVE_2 1
#define SEND 10

#ifdef TEENSY               // Teensy LC
#if defined(TEENSY_V1_0)
#define TOUCH_0 22
#define TOUCH_1 23
#elif defined(TEENSY_V1_1)
#define TOUCH_0 16
#define TOUCH_1 3
#endif
#endif

// Lighting pin settings
#define LED_TYPE    WS2812B
#define LED_ORDER   GRB
#ifdef TEENSY               // Teensy LC
#if defined(TEENSY_V1_0)
#define RGBPIN 4
#elif defined(TEENSY_V1_1)
#define RGBPIN 11
#endif
#else
#define RGBPIN 16           // Pro Micro
#endif

#endif  // _PINCONFIG_h
