#ifndef _PINCONFIG_h
#define _PINCONFIG_h

#if defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega32u4__)
#define USB
#endif

//#define IR_SENSOR_MULTIPLEXED
//#define IR_SENSOR_ANALOG        // Uncomment if IR sensors are hooked up to analog pins
#define CALIBRATION_SAMPLES 500

// Multiplexer pin settings
#define MUX_0 20
#define MUX_1 19
#define MUX_2 18

// Sensor pin settings
#define LED_0 0
#define LED_1 2
#define LED_2 3

#ifdef IR_SENSOR_MULTIPLEXED
#define SENSOR_IN A0
#else
#define AIR_SENSOR_0_PIN 4
#define AIR_SENSOR_1_PIN 5
#define AIR_SENSOR_2_PIN 6
#define AIR_SENSOR_3_PIN 7
#define AIR_SENSOR_4_PIN 8
#define AIR_SENSOR_5_PIN 9
#endif

// Capsense pin settings
#define RECEIVE_1 21
#define RECEIVE_2 1
#define SEND 10

// Lighting pin settings
#define LED_TYPE    WS2812B
#define LED_ORDER   GRB
#define RGBPIN 16

#endif
