#include "SerialProcessor.h"

SerialProcessor::SerialProcessor()
{ }

void SerialProcessor::processConfigCommand(uint8_t* buf)
{
  // figure out which command we're running
  switch (buf[2]) 
  {
    // print the controller info
    case CMD_PRINT_INFO:
      byte bytes[200];
      
          // whether the air sensor is analog or not
#ifdef IR_SENSOR_ANALOG
      bytes[0] = 0x11;
#else
      bytes[0] = 0x00;
#endif
      // slider on color
      bytes[1] = led_on.r;
      bytes[2] = led_on.g;
      bytes[3] = led_on.b;
      
      // slider off color
      bytes[4] = led_off.r;
      bytes[5] = led_off.g;
      bytes[6] = led_off.b;

      Serial.write(bytes, 200);
      break;
    case CMD_CHANGE_ON_COLOR:
      led_on.r = buf[3];
      led_on.g = buf[4];
      led_on.b = buf[5];
      serialLeds->saveLights();
      break;
    case CMD_CHANGE_OFF_COLOR:
      led_off.r = buf[3];
      led_off.g = buf[4];
      led_off.b = buf[5];
      serialLeds->saveLights();
      break;
    case CMD_CALIBRATE_SLIDER:
      touchboard->calibrateKeys(true);
      break;
    case CMD_CALIBRATE_AIR_SENSORS:
      sensor->recalibrate();
    case CMD_FACTORY_RESET:
      // clear EEPROM and then reset the controller
      for (int i = 0 ; i < EEPROM.length() ; i++) 
      {
        EEPROM.write(i, 0);
      }

      delay(500);

      initializeController();
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
