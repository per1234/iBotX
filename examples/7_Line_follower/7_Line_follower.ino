#include <iBotX.h>

int sl,sr;

void setup()
{
  iBotX();
  SW3();
}

void followline()
{
  while (true)
  {
    sl = sensor1();
    sr = sensor5();

    if (sl < 500 && sr < 500)
    {
      motor(200, 200, 50);
    }
    else if (sl > 500 && sr < 500)
    {
      motor(0, 200, 50);
    }
    else if (sl < 500 && sr > 500)
    {
      motor(200, 0, 50);
    }
    else if (sl > 500 && sr > 500)
    {
      motor(0, 0, 50);
      break;
    }
  }
}

void loop()
{
  motor(200,200,500);
	followline();
	SW1();
}
