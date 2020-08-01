#include "PinConfig.h"

#ifdef USB
#include "USBOutput.h"

/*
   In 16 sensor mode, the intended keys are:
   Left                                                             Right
     0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15

   In 32 sensor mode, the intended keys are:
   Left                                                             Right
     0 | 2 | 4 | 6 | 8 | 10 | 12 | 14 | 16 | 18 | 20 | 22 | 24 | 26 | 28 | 30
     1 | 3 | 5 | 7 | 9 | 11 | 13 | 15 | 17 | 19 | 21 | 23 | 25 | 27 | 29 | 31

*/

char bottomRow[] = {KEY_A, KEY_Z, KEY_S, KEY_X, KEY_D, KEY_C, KEY_F, KEY_V, KEY_G, KEY_B, KEY_H, KEY_N, KEY_J, KEY_M, KEY_K, KEY_COMMA};
char topRow[] = {KEY_1, KEY_Q, KEY_2, KEY_W, KEY_3, KEY_E, KEY_4, KEY_R, KEY_5, KEY_T, KEY_6, KEY_Y, KEY_7, KEY_U, KEY_8, KEY_I};

uint16_t airKeys[] = { KEY_SLASH, KEY_PERIOD, KEY_QUOTE , KEY_SEMICOLON, KEY_RIGHT_BRACE , KEY_LEFT_BRACE };

void USBOutput::sendKeyEvent(int key, KeyState state)
{
  switch (state)
  {
    case KeyState::UNPRESSED:
      releaseKey(bottomRow[key]);
      releaseKey(topRow[key]);
      break;
    case KeyState::SINGLE_PRESS:
      pressKey(bottomRow[key]);
      releaseKey(topRow[key]);
      break;
    case KeyState::DOUBLE_PRESS:
      pressKey(bottomRow[key]);
      pressKey(topRow[key]);
      break;
  }
}

void USBOutput::sendSensorEvent(float position)
{
  // Send hand up / hand down key
  if (position > lastPosition)
  {
    writeKey(KEY_PAGE_UP);
    if (wasAirHeld)
    {
      // Send Air Action
      writeKey(KEY_END);
    }
  }
  if (position < lastPosition)
  {
    writeKey(KEY_PAGE_DOWN);
    if (wasAirHeld)
    {
      // Send Air Action
      writeKey(KEY_END);
    }
  }

  // Send hand seen / unseen key
  if (position > 0.05f)
  {
    pressKey(KEY_HOME);
    wasAirHeld = true;
  }
  else {
    releaseKey(KEY_HOME);
    wasAirHeld = false;
  }

  // Save last position for next loop
  lastPosition = position;
}

void USBOutput::sendSensor(int sensor)
{
  for (int i = 0; i < 6; i++)
  {
    if (bitRead(sensor, i))
      pressKey(airKeys[i]);
    else
      releaseKey(airKeys[i]);
  }
}

USBOutput::USBOutput()
{
  lastPosition = 0;
}

void USBOutput::writeKey(uint16_t key)
{
  Nkro.set_key(key);
  Nkro.send_nkro_now();
  Nkro.reset_key(key);
  Nkro.send_nkro_now();
}

void USBOutput::pressKey(uint16_t key)
{
  Nkro.set_key(key);
}

void USBOutput::releaseKey(uint16_t key)
{
  Nkro.reset_key(key);
}

void USBOutput::sendUpdate()
{
  Nkro.send_nkro_now();
}

#endif
