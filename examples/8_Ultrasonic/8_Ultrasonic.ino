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
  read_sonar();
  delay(250);
}
