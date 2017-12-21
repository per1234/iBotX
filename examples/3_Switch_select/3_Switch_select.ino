#include <iBotX.h>

int program = 0;

void setup()
{
  iBotX();
  program = SW_Select();
}

void loop()
{
  if (program == 1)
  { 
    laser_on();
    delay(1000);
    laser_off();
    delay(1000);
  }
  else if (program == 2) 
  { 
    laser_on();
    delay(500);
    laser_off();
    delay(500);
  }
  else
  { 
    laser_on();
    delay(100);
    laser_off();
    delay(100);
  }
}
