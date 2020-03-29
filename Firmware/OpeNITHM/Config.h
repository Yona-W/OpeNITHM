// This file is for setting how the board will operate
// The top section is user-editable, the bottom section is not

#ifndef _CONFIG_h
#define _CONFIG_h

// *** USER EDITABLE CONFIG OPTIONS ***

// Select which board you're using (ignore if not using Teensy)
//#define TEENSY_V1_0   // Version 1.0 (No version number on board)
//#define TEENSY_V1_1   // Version 1.1 (v1.1 on board under logo)

// Uncomment this line to force the processor to use Serial Output
//#define FORCE_SERIAL

// Uncomment this line if your IR sensors are multiplexed (Confirm pinout on PinConfig.h)
//#define IR_SENSOR_MULTIPLEXED

// Uncomment this line if your IR sensors will be used in analog mode (Confirm pinout on PinConfig.h)
//#define IR_SENSOR_ANALOG

// Comment this line for default Seaurchin air sensor bindings
// Uncomment this line if your IR sensors will each be mapped to separate keyboard key
//#define IR_SENSOR_KEY

// Uncomment this line if your LED lights are mirrored
//#define LED_REVERSE

// *** FOR CALIBRATING AND DEBUGGING

// Uncomment this line to output the touch values to the Serial port (for use with Arduino's Serial Plotter)
//#define SERIAL_PLOT
// Uncomment this line if you want RAW touch values (vs. normalized)
//#define SERIAL_RAW_VALUE
// Define PLOT_PIN as -1 to print all key's values, otherwise define as 0-15 for an individual key
#define PLOT_PIN -1

// Uncomment this if you wish to ignore a falsly calibrated air sensor
//#define IGNORE_AIR_CALIBRATION


// *** DO NOT CHANGE BELOW THIS LINE ***

// Determine if we're compiling on Teensy
#if defined(__MKL26Z64__)  // Teensy LC
#define TEENSY
#define bitRead(value, bit) (((value) >> (bit)) & 0x01) // For some reason, bitRead isn't defined in the Teensy core (might be in Wiring.h?)
#ifndef FORCE_SERIAL
#define USB
#endif

// Spit out errors for board definitions
#if !defined(TEENSY_V1_0) && !defined(TEENSY_V1_1)
#error "For Teensy, EITHER v1.0 OR v1.1 must be defined in Config.h"
#elif defined(TEENSY_V1_0) && defined(TEENSY_V1_1)
#error "For Teensy, cannot define BOTH v1.0 AND v1.1 in Config.h"
#endif
#endif

// Comment out these lines to force Serial output
#if defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega32u4__)
#ifndef FORCE_SERIAL
#define USB
#endif
#endif

#endif // _CONFIG_h
