#include <iBotX.h>

int x = 0;

void setup() 
{
  iBotX();
  Serial.begin(9600);

  SW3();
  Serial.print("Hello!!! ");
  Serial.println("My name is I-BOT X!");
  Serial.println("Nice to meet you. ");
  
  SW3();
}

void loop() 
{
  x = sw1(); 
  Serial.print("SW1 = ");
  Serial.println(x);
  delay(200);
}