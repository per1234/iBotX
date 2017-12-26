#include <iBotX.h>            // Include the i-Bot X's library.

int x = 0;                    // A variable to store SW1's status.

void setup() 
{
  iBotX();                    // Set-up the board for i-Bot X's Hardware.
  Serial.begin(9600);         // Set-up the Serial communication with a buad rate of 9600.

  SW3();                                        // Do nothing until SW3 is pressed.
  Serial.print("Hello!!! ");                    // Prints out "Hello!!! " on Serial monitor. Without starting the new line.
  Serial.println("My name is I-BOT X!");        // Prints out "My name is I-BOT X!" on Serial monitor. Then starts the new line.
  Serial.println("Nice to meet you. ");         // Prints out "Nice to meet you. " on Serial monitor. Then starts the new line.
  
  SW3();                      // Do nothing until SW3 is pressed. After that, It'll go to do the task in void loop().
}

void loop() 
{
  x = sw1();                  // Reads the SW1's status and store it in the variable x
  Serial.print("SW1 = ");     // Prints out the status of SW1
  Serial.println(x);          // You'll see SW1 = 1 if it's pressed. or SW1 = 0 if it's released.
  delay(200);                 // Some delays, For slowing down the process and the data outputs on Serial monitor.
}
