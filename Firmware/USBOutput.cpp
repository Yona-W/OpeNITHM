#ifdef USB

#include "USBOutput.h"

char bottomRow[] = {'a', 'z', 's', 'x', 'd', 'c', 'f', 'v', 'g', 'b', 'h', 'n', 'j', 'm', 'k', ','};
char topRow[] = {'1', 'q', '2', 'w', '3', 'e', '4', 'r', '5', 't', '6', 'y', '7', 'u', '8', 'i'};

void USBOutput::sendKeyEvent(int key, bool pressed, bool doublePressed)
{
  if(pressed){
    if(doublePressed){
      NKROKeyboard.write(topRow[key]);
    }
    else{
      NKROKeyboard.press(bottomRow[key]);
    }
  }
  else{
    NKROKeyboard.release(bottomRow[key]);
  }
}

void USBOutput::sendSensorEvent(float position)
{
  // Send hand up / hand down key
  if(position > lastPosition){
    NKROKeyboard.write(KEY_PAGE_UP);
  }
  if(position < lastPosition){
    NKROKeyboard.write(KEY_PAGE_DOWN);
  }

  // Send hand seen / unseen key
  if(position > 0.05f){
    NKROKeyboard.press(KEY_HOME);
  }
  else{
    NKROKeyboard.release(KEY_HOME);
  }

  // Send hand moved key
  NKROKeyboard.write(KEY_END);
  
}

USBOutput::USBOutput(){
  NKROKeyboard.begin();
  lastPosition = 0;
}

#endif
