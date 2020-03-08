#include "PinConfig.h"

#ifdef USB
#include "USBOutput.h"

char bottomRow[] = {KEY_A, KEY_Z, KEY_S, KEY_X, KEY_D, KEY_C, KEY_F, KEY_V, KEY_G, KEY_B, KEY_H, KEY_N, KEY_J, KEY_M, KEY_K, KEY_COMMA};
char topRow[] = {KEY_1, KEY_Q, KEY_2, KEY_W, KEY_3, KEY_E, KEY_4, KEY_R, KEY_5, KEY_T, KEY_6, KEY_Y, KEY_7, KEY_U, KEY_8, KEY_I};

uint16_t airKeys[] = { KEY_SLASH, KEY_PERIOD, KEY_QUOTE , KEY_SEMICOLON, KEY_RIGHT_BRACE , KEY_LEFT_BRACE };

void USBOutput::sendKeyEvent(int key, bool pressed, bool doublePressed)
{
  if (pressed) {
    if (doublePressed) {
      pressKey(topRow[key]);
    }
    else {
      pressKey(bottomRow[key]);
      releaseKey(topRow[key]);
    }
  }
  else {
    releaseKey(bottomRow[key]);
    releaseKey(topRow[key]);
  }
}

void USBOutput::sendKeyEvent(int key, KeyState keyState)
{
  switch (keyState) 
  {
    case UNPRESSED:
      releaseKey(bottomRow[key]);
      releaseKey(topRow[key]);
      break;
    case SINGLE_PRESS:
      pressKey(bottomRow[key]);
      releaseKey(topRow[key]);
      break;
    case DOUBLE_PRESS:
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
#ifndef TEENSY
  NKROKeyboard.begin();
#endif
  lastPosition = 0;
}

void USBOutput::writeKey(uint16_t key)
{
#ifndef TEENSY
  NKROKeyboard.write(key);
#else
  Nkro.set_key(key);
  Nkro.send_nkro_now();
  Nkro.reset_key(key);
  Nkro.send_nkro_now();
#endif
}

void USBOutput::pressKey(uint16_t key)
{
#ifndef TEENSY
  pressKey(key);
#else
  Nkro.set_key(key);
#endif
}

void USBOutput::releaseKey(uint16_t key)
{
#ifndef TEENSY
  NKROKeyboard.release(key);
#else
  Nkro.reset_key(key);
#endif
}

void USBOutput::sendUpdate()
{
  Nkro.send_nkro_now();
}

#endif
