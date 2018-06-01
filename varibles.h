
/*
 * varibles.h
 *
 *  Created on: 2014-9-25
 *      Author: CIVL2013
 */

#ifndef VARIBLES_H_
#define VARIBLES_H_

//#define		SD_ENABLE		//enable the SD function



//==================================================================================
//						Temperature Setting
//==================================================================================
#ifdef	TEMPERATURE_MONITOR_Y_MOTOR
extern DS18B20_S  yMotorTempDS;//pin A3
#endif

//==================================================================================
//						Mechanical definition
//==================================================================================

// Initialize stepper driver
extern AccelStepper stepperX;
extern AccelStepper stepperY;
extern AccelStepper stepperZA;
extern AccelStepper stepperZB;
extern AccelStepper stepperZC;
extern AccelStepper stepperZD;
extern AccelStepper stepperR;

extern WaitTimeMSec heartbeat;

extern SoftwareSerial sSComm; // RX, TX

#endif /* VARIBLES_H_ */
