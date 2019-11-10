#include "SerialLeds.h"

SerialLeds::SerialLeds()
{ }

bool SerialLeds::process(byte in)
{
  bool readyToProcess = false;
  switch (currentState)
  {
    case headerSearch:
      // Search for header
      if (in == 0xAA)
      {
        dataBuffer[0] = in;
        currentState = headerConfirm;
      }
      break;
    case headerConfirm:
      // Confirm header
      if (in == 0xAA)
      {
        dataBuffer[1] = in;
        currentState = dataRead;
        currentReadNum = 2;
      }
      else
      {
        currentState = headerSearch;
      }
      break;
    case dataRead:
      {
        dataBuffer[currentReadNum] = in;
        currentReadNum++;
        if (currentReadNum == 100)
        {
          if (memcmp(dataBuffer, lastBuffer, 100) != 0)
            readyToProcess = true;
          memcpy(lastBuffer, dataBuffer, 100);
          currentState = headerSearch;
        }
      }
      break;
  }

  return readyToProcess;
}

bool SerialLeds::processBulk(uint8_t *buf, size_t length)
{
  bool readyToProcess = false;
  currentState = headerSearch;

  for (int i = 0; i < length - 100; i++)
  {
    switch (currentState)
    {
      case headerSearch:
        if (buf[i] == 0xAA)
        {
          currentState = headerConfirm;
          dataBuffer[0] = buf[i];
        }
        break;
      case headerConfirm:
        if (buf[i] == 0xAA)
        {
          currentState = dataRead;
          dataBuffer[1] = buf[i];
        }
        else
        {
          currentState = headerSearch;
        }
        break;
      case dataRead:
        memcpy(dataBuffer + 2, buf + i, 98);
        if (memcmp(dataBuffer, lastBuffer, 100) != 0)
        {
          memcpy(ledData.raw, dataBuffer + 2, 96);
          readyToProcess = true;
        }
        memcpy(lastBuffer, dataBuffer, 100);
        currentState = headerSearch;
        return readyToProcess;
    }
  }
  return readyToProcess;
}

// Left to Right
RGBLed SerialLeds::getKey(uint8_t key)
{
  return ledData.rgb[30 - (key * 2)];
}
