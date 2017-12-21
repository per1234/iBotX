#include <iBotX.h>

void setup() 
{
  iBotX();
  Serial.begin(9600);
}

void loop() 
{
  int s1 = sensor1();
  int s2 = sensor2();
  int s3 = sensor3();
  int s4 = sensor4();
  int s5 = sensor5();
  Serial.print(s1); Serial.print("\t,");
  Serial.print(s2); Serial.print("\t,");
  Serial.print(s3); Serial.print("\t,");
  Serial.print(s4); Serial.print("\t,");
  Serial.println(s5); 
  delay(100); 
}
