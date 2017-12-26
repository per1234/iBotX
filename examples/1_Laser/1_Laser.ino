#include <iBotX.h>            // Include the i-Bot X's library.

void setup() 
{
  iBotX();                    // Set-up the board for i-Bot X's Hardware.
}

void loop() 
{
  laser_on();                 // Turn the laser on.
  delay(1000);                // Wait for 1 sec.
  laser_off();                // Turn the laser off.
  delay(1000);                // Wait for 1 sec. and then loop back to laser_on();
}
