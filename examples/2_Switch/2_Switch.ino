#include <iBotX.h>            // Include the i-Bot X's library.

void setup() 
{
  iBotX();                    // Set-up the board for i-Bot X's Hardware.
  SW3();                      // Do nothing until you press the SW3
}

void loop() 
{
  int x = sw1();              // Read the value of SW1. 
                              // (It's 1 if the SW1 is pressed, or 0 if the SW1 is released.)
  if(x == 1)                  // Check that the SW1 is pressed or not?
  {
    laser_on();               // If yes, Then turn the laser on.
  }
  else 
  {
    laser_off();              // Otherwise, Turn the laser off.
  }
}
