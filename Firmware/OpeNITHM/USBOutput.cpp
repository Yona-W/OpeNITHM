#include "PinConfig.h"

#ifdef USB
#include "USBOutput.h"

char bottomRow[] = {'a', 'z', 's', 'x', 'd', 'c', 'f', 'v', 'g', 'b', 'h', 'n', 'j', 'm', 'k', ','};
char topRow[] = {'1', 'q', '2', 'w', '3', 'e', '4', 'r', '5', 't', '6', 'y', '7', 'u', '8', 'i'};

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
  switch (key)
  {
    case KEY_PAGE_UP:
    case KEY_PAGE_DOWN:
    case KEY_HOME:
    case KEY_END:
    case KEY_SLASH:
    case KEY_PERIOD:
    case KEY_QUOTE:
    case KEY_SEMICOLON:
    case KEY_RIGHT_BRACE:
    case KEY_LEFT_BRACE:
      // Don't use ASCII method
      Nkro.set_key(key);
      Nkro.send_nkro_now();
      Nkro.reset_key(key);
      Nkro.send_nkro_now();
      break;
    default:
      // Use NKRO for ASCII
      Nkro.set_key_ascii(key);
      Nkro.send_nkro_now();
      Nkro.reset_key_ascii(key);
      Nkro.send_nkro_now();
      break;
  }
#endif
}

void USBOutput::pressKey(uint16_t key)
{
#ifndef TEENSY
  pressKey(key);
#else
  switch (key)
  {
    case KEY_PAGE_UP:
    case KEY_PAGE_DOWN:
    case KEY_HOME:
    case KEY_END:
    case KEY_SLASH:
    case KEY_PERIOD:
    case KEY_QUOTE:
    case KEY_SEMICOLON:
    case KEY_RIGHT_BRACE:
    case KEY_LEFT_BRACE:
      // Don't use ASCII method
      Nkro.set_key(key);
      Nkro.send_nkro_now();
      break;
    default:
      // Use NKRO for ASCII
      Nkro.set_key_ascii(key);
      Nkro.send_nkro_now();
      break;
  }
#endif
}

void USBOutput::releaseKey(uint16_t key)
{
#ifndef TEENSY
  NKROKeyboard.release(key);
#else
  switch (key)
  {
    case KEY_PAGE_UP:
    case KEY_PAGE_DOWN:
    case KEY_HOME:
    case KEY_END:
    case KEY_SLASH:
    case KEY_PERIOD:
    case KEY_QUOTE:
    case KEY_SEMICOLON:
    case KEY_RIGHT_BRACE:
    case KEY_LEFT_BRACE:
      // Don't use ASCII method
      Nkro.reset_key(key);
      Nkro.send_nkro_now();
      break;
    default:
      // Use NKRO for ASCII
      Nkro.reset_key_ascii(key);
      Nkro.send_nkro_now();
      break;
  }
#endif
}

#endif
