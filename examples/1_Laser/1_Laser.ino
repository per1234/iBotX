#include <iBotX.h>

void setup() 
{
  iBotX();
}

void loop() 
{
  laser_on();
  delay(1000);
  laser_off();
  delay(1000);
}
