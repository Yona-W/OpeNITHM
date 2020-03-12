#include "SerialLeds.h"

SerialLeds::SerialLeds()
{ }

void SerialLeds::processBulk(uint8_t *buf)
{
  if (memcmp(buf + 2, lastBuffer + 2, 98) != 0)
  {
    memcpy(ledData.raw, buf + 2, 96);
    updateLeds = true;
  }
  
  memcpy(lastBuffer, buf, 100);
}

// Left to Right
RGBLed SerialLeds::getKey(uint8_t key)
{
  return ledData.rgb[30 - (key * 2)];
}
