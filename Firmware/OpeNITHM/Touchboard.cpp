#include "Touchboard.h"

void Touchboard::scan()
{
  // For each key, set multiplexers and poll both capacitive sensors simultaneously
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(MUX_0, bitRead(i, 0));
    digitalWrite(MUX_1, bitRead(i, 1));
    digitalWrite(MUX_2, bitRead(i, 2));

#ifndef TEENSY
    unsigned int* values = sensor.sense(3);

    // Store the values received from the sensor poll into their respective positions
    keys[i] = values[0];
    keys[i + 8] = values[1];
#else
    keys[i] = (unsigned int)touchRead(TOUCH_0);
    keys[i+8] = (unsigned int)touchRead(TOUCH_1);
#endif
  }
}

void Touchboard::calibrateKeys()
{
  // Reset calibration data for all keys
  for (int i = 0; i < 16; i++)
  {
    em_averages[i] = 0;
    neutral_values[i] = 0;
    key_states[i] = false;
    keys[i] = false;
  }

  for (int i = 0; i < CALIBRATION_SAMPLES; i++) {
    // Repeatedly scan all keys
    scan();
    // Store the lowest read value as our baseline
    for (int j = 0; j < 16; j++) {
      if (keys[j] > neutral_values[j]) neutral_values[j] = keys[j];
    }
  }
  // After calibration is complete, initialize the averages to the baseline values established previously
  for (int i = 0; i < 16; i++) {
    em_averages[i] = neutral_values[i];
  }
}

bool Touchboard::update(int key)
{
  int read_value = keys[key];
  float new_average = alpha * read_value + (1 - alpha) * em_averages[key];
  if (read_value - neutral_values[key] < deadzone)
  {
    // If we are in the deadzone, ignore any touch events, set the key to be untouched and update the moving average.
    if (key_states[key])
      em_averages[key] = neutral_values[key];
    else
      em_averages[key] = new_average;
    key_states[key] = false;
  }
  else
  {
    //If we are outside of the deadzone:
    if (read_value > em_averages[key] + threshold)
    {
      // If we just detected a touch, make the key touched, discard the previous moving average and trigger the callback.
      em_averages[key] = read_value;
      onKeyPress(key, key_states[key]);
      key_states[key] = true;
    }
    else
    {
      // Otherwise, just update the average.
      em_averages[key] = new_average;
    }
  }
  return key_states[key];
}

void Touchboard::setThreshold(uint16_t threshold)
{
  this->threshold = threshold;
  EEPROM.put(0, threshold);
}

void Touchboard::setDeadzone(uint16_t deadzone)
{
  this->deadzone = deadzone;
  EEPROM.put(4, deadzone);
}

void Touchboard::setAlpha(float alpha)
{
  this->alpha = alpha;
  EEPROM.put(8, alpha);
}

int Touchboard::getThreshold()
{
  return threshold;
}

int Touchboard::getDeadzone()
{
  return deadzone;
}

float Touchboard::getAlpha()
{
  return alpha;
}

float Touchboard::getNeutralValue(int key)
{
  return neutral_values[key];
}

float Touchboard::getEmAverages(int key)
{
  return em_averages[key];
}

float Touchboard::getRawValue(int key)
{
  return keys[key];
}

Touchboard::Touchboard(void(*keyPressCallback)(int, bool)) :
#ifndef TEENSY
  sensor(CapacitiveSensor(SEND, RECEIVE_1, RECEIVE_2)),
#endif
  onKeyPress(keyPressCallback)
{
  EEPROM.get(0, threshold);
  EEPROM.get(4, deadzone);
  EEPROM.get(8, alpha);

  pinMode(MUX_0, OUTPUT);
  pinMode(MUX_1, OUTPUT);
  pinMode(MUX_2, OUTPUT);

  calibrateKeys();
}
