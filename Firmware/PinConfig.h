#pragma once

#define IR_SENSOR_MULTIPLEXED
#define CALIBRATION_SAMPLES 500

// Multiplexer pin settings
#define MUX_A 9
#define MUX_B 8
#define MUX_C 7

// Sensor pin settings
#define IR_A 5
#define IR_B 4
#define IR_C 3

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
#define KEYBOARDPIN_1 10 
#define KEYBOARDPIN_2 12
#define KEYBOARDPIN_COM 11

// Lighting pin settings
#define LED_TYPE    WS2812B
#define LED_ORDER   GRB
#define RGBPIN 2
