#include <iBotX.h>

int distance;

void setup()
{
  iBotX();
  Serial.begin(9600);
}

void read_sonar()
{
  distance = sonar_cm();
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");
}

void loop()
{
  SW1();
  servo(130);
  SW3();
  read_sonar();

  SW2();
  servo(50);
  SW3();
  read_sonar();
}