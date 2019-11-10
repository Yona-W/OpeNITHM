// This file is for setting how the board will operate
// The top section is user-editable, the bottom section is not

#ifndef _CONFIG_h
#define _CONFIG_h

// *** USER EDITABLE CONFIG OPTIONS ***

// Uncomment this line to force the processor to use Serial Output
//#define FORCE_SERIAL

// Uncomment this line if your IR sensors are multiplexed (Confirm pinout on PinConfig.h)
//#define IR_SENSOR_MULTIPLEXED

// Uncomment this line if your IR sensors will be used in analog mode (Confirm pinout on PinConfig.h)
//#define IR_SENSOR_ANALOG

// Comment this line for default Seaurchin air sensor bindings
// Uncomment this line if your IR sensors will each be mapped to separate keyboard key
//#define IR_SENSOR_KEY

// Comment this line to use reactive LEDs (i.e. they will react to touch input)
// Uncomment this line to receive LED instructions via serial
//#define LED_SERIAL

// Uncomment this line if your LED lights are mirrored
//#define LED_REVERSE

// Uncomment this line to output the RAW touch values to the Serial port (for use with Arduino's Serial Plotter)
//#define SERIAL_PLOT
// Define PLOT_PIN as -1 to print all key's values, otherwise define as 0-15 for an individual key
#define PLOT_PIN -1




// *** DO NOT CHANGE BELOW THIS LINE ***

// Determine if we're compiling on Teensy
#if defined(__MKL26Z64__)  // Teensy LC
#define TEENSY
#define bitRead(value, bit) (((value) >> (bit)) & 0x01) // For some reason, bitRead isn't defined in the Teensy core (might be in Wiring.h?)
#ifndef FORCE_SERIAL
#define USB
#endif
#endif

// Comment out these lines to force Serial output
#if defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega32u4__)
#ifndef FORCE_SERIAL
#define USB
#endif
#endif

#endif // _CONFIG_h
