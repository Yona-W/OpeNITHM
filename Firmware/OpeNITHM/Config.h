// This file is for setting how the board will operate
// The top section is user-editable, the bottom section is not

#ifndef _CONFIG_h
#define _CONFIG_h

// *** USER EDITABLE CONFIG OPTIONS ***

// Select which OpeNITHM board you're using. If you are not using an OpeNITHM
// board and have hand-wired your controller, it's strongly advised to use 
// the pinout and configurations for OPENITHM_V1_1
#define OPENITHM_V2_0   // Version 2.0 (v2.0 in upper left of board)
// #define OPENITHM_V2_1   // Version 2.1 (v2.1 in upper left of board)

// Comment this line for default Seaurchin air sensor bindings
// Uncomment this line if your IR sensors will each be mapped to separate keyboard key
// Most users should leave this uncommented by default.
#define IR_SENSOR_KEY

// Uncomment this line if your RGB LED lights are backwards
// #define LED_REVERSE

// Uncomment this if you have lighted separators between the keys in your controller.
// This option is *not* applicable to the standard 3D printed controller builds.
#define KEY_DIVIDERS



// *** FOR CALIBRATING AND DEBUGGING

// Uncomment this line to output the touch values to the Serial port (for use with Arduino's Serial Plotter)
//#define SERIAL_PLOT

// Uncomment this line if you want RAW touch values (vs. normalized)
//#define SERIAL_RAW_VALUE

// Define PLOT_PIN as -1 to print all key's values, otherwise define as 0-15 for an individual key
#define PLOT_PIN -1

// Uncomment this if you wish to ignore a falsely calibrated air sensor
// #define IGNORE_AIR_CALIBRATION




// *** DO NOT CHANGE BELOW THIS LINE ***

#if defined(__AVR__)
#error "You cannot use any Arduino boards with this code. You must use a Teensy LC (recommended), or switch to the Pro Micro + MPR121 branch (not recommended)."
#endif

// Determine if we're compiling on Teensy
#if defined(__MKL26Z64__)  // Teensy LC
#define TEENSY
#define bitRead(value, bit) (((value) >> (bit)) & 0x01) // For some reason, bitRead isn't defined in the Teensy core (might be in Wiring.h?)
#define USB

// Spit out errors for board definitions
#if (defined(OPENITHM_V1_0) + defined(OPENITHM_V1_1) + defined(OPENITHM_V2_0) + defined(OPENITHM_V2_1)) == 0
#error "Must define ONE Teensy board in Config.h"
#elif (defined(OPENITHM_V1_0) + defined(OPENITHM_V1_1) + defined(OPENITHM_V2_0) + defined(OPENITHM_V2_1)) > 1
#error "Cannot define multiple Teensy boards in Config.h"
#endif
#endif

#define NUM_SENSORS  32

#endif // _CONFIG_h
