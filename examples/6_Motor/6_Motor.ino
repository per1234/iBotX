#include <iBotX.h>

void setup()
{
  iBotX();
  SW3();
}

void loop()
{
	motor(200,200,3000); 	// forward for 3 seconds and stop
	motor(-200,200,3000); 	// turn left for 3 seconds and stop
	motor(200,-200,3000); 	// turn right for 3 seconds and stop
	motor(-200,-200);	 	// backward (no time assigned)
	SW1();					// start again when SW1 is pressed
}
