#include "SerialProcessor.h"

SerialProcessor::SerialProcessor()
{ }

void SerialProcessor::processConfigCommand(uint8_t* buf)
{
  // figure out which command we're running
  switch (buf[2]) 
  {
    case CMD_CHANGE_LIGHT_MODE:
      if (buf[3] == LIGHT_MODE_SERIAL)
      {
        useSerialLeds = true;

        // Set LEDs blue for "ready"
        for (CRGB& led : leds)
          led = CRGB::Blue;
          
        FastLED.show();
      }
      else if (buf[3] == LIGHT_MODE_REACTIVE)
      {
        useSerialLeds = false;
      }
        
      break;
    case CMD_CHANGE_ON_COLOR:
      led_on.r = buf[3];
      led_on.g = buf[4];
      led_on.b = buf[5];
      break;
    case CMD_CHANGE_OFF_COLOR:
      led_off.r = buf[3];
      led_off.g = buf[4];
      led_off.b = buf[5];
      break;
    case CMD_CALIBRATE_SLIDER:
      touchboard->setSensitivity(buf[3]);
      touchboard->calibrateKeys(true);
      break;
    case CMD_CALIBRATE_AIR_SENSORS:
      sensor->setAnalogSensitivity(buf[3]);
      sensor->recalibrate();
      break;
    default:
      break;
  }
}

void SerialProcessor::processBulk(uint8_t *buf)
{
  if (buf[0] == LED_FLAG && buf[1] == LED_FLAG)
  {
    serialLeds->processBulk(buf);
    useSerialLeds = true;
    serialLightsCounter = 0;
  }
  else if (buf[0] == CONFIG_FLAG && buf[1] == CONFIG_FLAG)
  {
    processConfigCommand(buf);
  }
}
