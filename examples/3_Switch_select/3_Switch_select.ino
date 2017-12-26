#include <iBotX.h>            // Include the i-Bot X's library.

int program = 0;              // Variable for storing the program number

void setup()
{
  iBotX();                    // Set-up the board for i-Bot X's Hardware.
  program = SW_Select();      // Do nothing until SW1 or SW2 or SW3 is pressed. Then store the number of that SW into "program"
                              // program = 1 if it was SW1, 2 if it's SW2 and 3 when it's SW3
}

void loop()
{
  if (program == 1)           // If program = 1 (SW1 is pressed), Do this task.
  { 
    laser_on();
    delay(1000);
    laser_off();
    delay(1000);
  }
  else if (program == 2)      // If program = 2 (SW2 is pressed), Do this task.
  { 
    laser_on();
    delay(500);
    laser_off();
    delay(500);
  }
  else                        // If program = 3 (SW3 is pressed), Do this task.
  { 
    laser_on();
    delay(100);
    laser_off();
    delay(100);
  }
}
