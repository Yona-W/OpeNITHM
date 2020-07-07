#include "SerialLeds.h"

SerialLeds::SerialLeds()
{ }

void SerialLeds::saveLights() {
  EEPROM.put(67, (byte) LIGHTS_FLAG);
  EEPROM.put(68, led_on.r);
  EEPROM.put(69, led_on.g);
  EEPROM.put(70, led_on.b);
  EEPROM.put(71, led_off.r);
  EEPROM.put(72, led_off.g);
  EEPROM.put(73, led_off.b);
}

void SerialLeds::loadLights() {
  EEPROM.get(68, led_on.r);
  EEPROM.get(69, led_on.g);
  EEPROM.get(70, led_on.b);
  EEPROM.get(71, led_off.r);
  EEPROM.get(72, led_off.g);
  EEPROM.get(73, led_off.b);
}

void SerialLeds::processBulk(uint8_t *buf)
{
  if (memcmp(buf + 2, lastBuffer + 2, 98) != 0)
  {
    memcpy(ledData.raw, buf + 2, 96);
    updateLeds = true;
  }
  
  memcpy(lastBuffer, buf, 100);
}

// Left to Right, zero index
RGBLed SerialLeds::getKey(uint8_t key)
{
  if (key > 15)
    key = 15;
  return ledData.rgb[30 - (key * 2)];
}

// Left to Right, zero index
RGBLed SerialLeds::getDivider(uint8_t divider)
{
  if (divider > 14)
    divider = 14;
  return ledData.rgb[29 - (divider * 2)];
}
