#include "hc-sr04.h"

float TpInit(void)
{
	float fDistance;
	int nStartTime, nEndTime;
	
	digitalWrite(TP, LOW);
	delayMicroseconds(2);
	digitalWrite(TP, HIGH);   // pull the Trig pin to high level for more than 10us impulse
	delayMicroseconds(10);
	digitalWrite(TP, LOW);

	while(digitalRead(EP) == LOW);
	nStartTime = micros();

	while(digitalRead(EP) == HIGH);
	nEndTime = micros();
	
	fDistance = (nEndTime - nStartTime) / 29. / 2.;
	
	return fDistance;
}

int initSR04(void)
{
#if 0
	if(wiringPiSetupGpio() == -1){
		return 1;
	}
#endif	
	pinMode(TP,OUTPUT);
	pinMode(EP,INPUT);	
	return 0;
}

float controlSR04(void)
{
	float fDistance = TpInit();
	
	delay(1000);
	return fDistance;
}
