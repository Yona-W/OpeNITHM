#include "PinConfig.h"

#ifdef USB
#include "USBOutput.h"

char bottomRow[] = {'a', 'z', 's', 'x', 'd', 'c', 'f', 'v', 'g', 'b', 'h', 'n', 'j', 'm', 'k', ','};
char topRow[] = {'1', 'q', '2', 'w', '3', 'e', '4', 'r', '5', 't', '6', 'y', '7', 'u', '8', 'i'};

void USBOutput::sendKeyEvent(int key, bool pressed, bool doublePressed)
{
  if (pressed) {
    if (doublePressed) {
      writeKey(topRow[key]);
    }
    else {
      pressKey(bottomRow[key]);
    }
  }
  else {
    releaseKey(bottomRow[key]);
  }
}

void USBOutput::sendSensorEvent(float position)
{
  // Send hand up / hand down key
  if (position > lastPosition) {
    writeKey(KEY_PAGE_UP);
  }
  if (position < lastPosition) {
    writeKey(KEY_PAGE_DOWN);
  }

  // Send hand seen / unseen key
  if (position > 0.05f) {
    pressKey(KEY_HOME);
  }
  else {
    releaseKey(KEY_HOME);
  }

  // Send hand moved key
  writeKey(KEY_END);

}

USBOutput::USBOutput() {
#ifndef TEENSY
  NKROKeyboard.begin();
#endif
  lastPosition = 0;
}

void USBOutput::writeKey(char key)
{
#ifndef TEENSY
  NKROKeyboard.write(key);
#else
  Nkro.set_key_ascii((uint8_t)key);
  Nkro.send_nkro_now();
  Nkro.reset_key_ascii((uint8_t)key);
  Nkro.send_nkro_now();
#endif
}

void USBOutput::pressKey(char key)
{
#ifndef TEENSY
  pressKey(key);
#else
  Nkro.set_key_ascii((uint8_t)key);
  Nkro.send_nkro_now();
#endif
}

void USBOutput::releaseKey(char key)
{
#ifndef TEENSY
  NKROKeyboard.release(key);
#else
  Nkro.reset_key_ascii((uint8_t)key);
  Nkro.send_nkro_now();
#endif
}

#endif
