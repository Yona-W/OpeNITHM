/*
 CapacitiveSense.h - Capacitive Sensing Library for 'duino / Wiring
 https://github.com/PaulStoffregen/CapacitiveSensor
 http://www.pjrc.com/teensy/td_libs_CapacitiveSensor.html
 http://playground.arduino.cc/Main/CapacitiveSensor
 Copyright (c) 2009 Paul Bagder
 Updates for other hardare by Paul Stoffregen, 2010-2016
 Several modifications to better suit OpeNITHM by Jonathan Montineri, 2019
 vim: set ts=4:

 Permission is hereby granted, free of charge, to any person obtaining a
 copy of this software and associated documentation files (the "Software"),
 to deal in the Software without restriction, including without limitation
 the rights to use, copy, modify, merge, publish, distribute, sublicense,
 and/or sell copies of the Software, and to permit persons to whom the
 Software is furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 DEALINGS IN THE SOFTWARE.
*/

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#include "WConstants.h"
#endif

#include "CapacitiveSensor.h"

// Constructor /////////////////////////////////////////////////////////////////
// Function that handles the creation and setup of instances

CapacitiveSensor::CapacitiveSensor(uint8_t sendPin, uint8_t receivePin1, uint8_t receivePin2)
{
  // initialize this instance's variables
  error = 1;
  retVal = new unsigned int[2];

  loopTimingFactor = 310;   // determined empirically -  a hack
  CS_Timeout_Millis = (200 * (float)loopTimingFactor * (float)F_CPU) / 16000000;

  // get pin mapping and port for send Pin - from PinMode function in core

#ifdef NUM_DIGITAL_PINS
  if (sendPin >= NUM_DIGITAL_PINS) error = -1;
  if (receivePin1 >= NUM_DIGITAL_PINS) error = -1;
  if (receivePin2 >= NUM_DIGITAL_PINS) error = -1;
#endif

  pinMode(sendPin, OUTPUT);           // sendpin to OUTPUT
  pinMode(receivePin1, INPUT);            // receivePins to INPUT
  pinMode(receivePin2, INPUT);

  // Get pin bitmask and registers

  sBit = PIN_TO_BITMASK(sendPin); 
  sReg = PIN_TO_BASEREG(sendPin);

  r1Bit = PIN_TO_BITMASK(receivePin1);
  r1Reg = PIN_TO_BASEREG(receivePin1);

  r2Bit = PIN_TO_BITMASK(receivePin2);
  r2Reg = PIN_TO_BASEREG(receivePin2);
}

// Public Methods //////////////////////////////////////////////////////////////
// Functions available in Wiring sketches, this library, and other libraries

unsigned int* CapacitiveSensor::sense(uint8_t samples)
{
  total1 = 0;
  total2 = 0;

  // This code has very strict timing - disable interrupts
  //noInterrupts();
  for (uint8_t i = 0; i < samples; i++) {
    if (!SenseOneCycle())  return nullptr;   // Poll capacitive sensors repeatedly
  }
  //interrupts();

  retVal[0] = total1;
  retVal[1] = total2;

  // Return the pair of values for the 2 sensors that were polled
  return retVal;
}

// Private Methods /////////////////////////////////////////////////////////////
// Functions only available to other functions in this library

int CapacitiveSensor::SenseOneCycle(void)
{

  DIRECT_WRITE_LOW(sReg, sBit); // sendPin Register low
  DIRECT_MODE_INPUT(r1Reg, r1Bit);  // receivePin to input (pullups ar1e off)
  DIRECT_MODE_OUTPUT(r1Reg, r1Bit); // receivePin to OUTPUT
  DIRECT_WRITE_LOW(r1Reg, r1Bit); // pin is now LOW AND OUTPUT
  delayMicroseconds(10);
  DIRECT_MODE_INPUT(r1Reg, r1Bit);  // receivePin to input (pullups ar1e off)

  DIRECT_MODE_INPUT(r2Reg, r2Bit);  // receivePin to input (pullups ar2e off)
  DIRECT_MODE_OUTPUT(r2Reg, r2Bit); // receivePin to OUTPUT
  DIRECT_WRITE_LOW(r2Reg, r2Bit); // pin is now LOW AND OUTPUT
  delayMicroseconds(10);
  DIRECT_MODE_INPUT(r2Reg, r2Bit);  // receivePin to input (pullups ar2e off)
  DIRECT_WRITE_HIGH(sReg, sBit);  // sendPin High

  while (total1 < CS_Timeout_Millis) {  // while total is positive value
    // Poll both pins at once
    pin1State = DIRECT_READ(r1Reg, r1Bit);
    pin2State = DIRECT_READ(r2Reg, r2Bit);

    total1 += !pin1State;
    total2 += !pin2State;

    // Break once both pins are high
    if(pin1State && pin2State) break;
  }

  if (total1 > CS_Timeout_Millis) {
    return -2;         // We timed out - should never happen with this implementation
  }

  // set receive pin HIGH briefly to charge up fully - because the while loop above will exit when pin is ~ 2.5V
  DIRECT_WRITE_HIGH(r1Reg, r1Bit);
  DIRECT_MODE_OUTPUT(r1Reg, r1Bit);  // receivePin to OUTPUT - pin is now HIGH AND OUTPUT
  DIRECT_MODE_OUTPUT(r2Reg, r2Bit);  // receivePin to OUTPUT - pin is now HIGH AND OUTPUT
  DIRECT_WRITE_HIGH(r1Reg, r1Bit);
  DIRECT_WRITE_HIGH(r2Reg, r2Bit);
  DIRECT_MODE_INPUT(r1Reg, r1Bit);  // receivePin to INPUT (pullup is off)
  DIRECT_MODE_INPUT(r2Reg, r2Bit);  // receivePin to INPUT (pullup is off)
  DIRECT_WRITE_LOW(sReg, sBit); // sendPin LOW

  // Same loop as above, but measuring capacitor discharge time instead
  while ( (total1 < CS_Timeout_Millis) ) {  
    pin1State = DIRECT_READ(r1Reg, r1Bit);
    pin2State = DIRECT_READ(r2Reg, r2Bit);

    total1 += pin1State;
    total2 += pin2State;

    if(!(pin1State || pin2State)) break;
  }

  if (total1 >= CS_Timeout_Millis) {
    return -2;    
  } else {
    return 1;
  }
}
