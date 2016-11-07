
/*
 * ledbuzzer.cpp
 *
 *  Created on: 2014-11-18
 *      Author: CIVL2013
 */


#include "Powder_0.h"



void initialLEDbuzzerPins()
{
    pinMode(LED_IO_1,	OUTPUT);
    pinMode(LED_IO_2,	OUTPUT);
    pinMode(LED_IO_3,	OUTPUT);
}

void clearAllLED(void)
{
    digitalWrite(LED_IO_1, HIGH);
    digitalWrite(LED_IO_2, HIGH);
    digitalWrite(LED_IO_3, HIGH);
}

void beep()
{
}


WaitTimeMSec wait100mSec(100);

unsigned int flashcnt=0;
unsigned int timecnt=0;

void ledBuz_in_loop()
{
	if( wait100mSec.bCheckTimeUp() ) 
	{
		timecnt ++;
		if(timecnt > 19) 
		{
			digitalWrite(LED_IO_2, LOW);
		}

		if(timecnt > 20)
		{
			digitalWrite(LED_IO_2, HIGH);
			timecnt = 0;
		}
	}

	//if(heartbeat.bCheckTimeUp())
	{
		//SERIAL_ECHO_STRln("o");
	}
}