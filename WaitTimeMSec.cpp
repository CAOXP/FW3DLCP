/*
 * WaitTimeMSec.cpp
 *
 *  Created on: 2015-5-6
 *      Author: CIVL2013
 */

#include "WaitTimeMSec.h"



WaitTimeMSec::WaitTimeMSec(long _time2wait)
{
	if(_time2wait<1) 	TimeToWaitMSec = 0;
	else 				TimeToWaitMSec = _time2wait-1;

	lastTimeMSec   = 0;
}

bool WaitTimeMSec::bCheckTimeUp()
{
	long currentMiSecond;
	currentMiSecond	=	millis();
	if ( (currentMiSecond-lastTimeMSec ) > TimeToWaitMSec )
	{
		lastTimeMSec = currentMiSecond;
		return true;
	}
	else
		return false;
}

