#include <iBotX.h>

void setup() 
{
  iBotX();
  SW3();
}

void loop() 
{
  int x = sw1();
  
  if(x == 1) 
  {
    laser_on();
  }
  else 
  {
    laser_off();
  }
}
