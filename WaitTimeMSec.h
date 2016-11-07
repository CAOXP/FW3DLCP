/*
 * WaitTimeMSec.h
 *
 *  Created on: 2015-5-6
 *      Author: CIVL2013
 */

#ifndef WAITTIMEMSEC_H_
#define WAITTIMEMSEC_H_


#include "Arduino.h"

class WaitTimeMSec
{
private:
	long TimeToWaitMSec;
	long lastTimeMSec;
public:
	WaitTimeMSec(long _time2wait);
	bool bCheckTimeUp();
};




#endif /* WAITTIMEMSEC_H_ */
