
#include "parking.h"
#include "hc-sr04.h"
#include "led.h"

int getSensorData(void)
{
	float fDistance;

	initSR04();
	
	fDistance = controlSR04();
	printf("Distance:%.2fcm\n", fDistance);

	return fDistance;
}

int g_nLedOnValue = 100;
int controlLed(int distance)
{
	if(distance < g_nLedOnValue) {
		LedOn(RED);			//Red On
		LedOff(GREEN);
	}
	else {
		LedOn(GREEN);	//Green On
		LedOff(RED);
	}
}
