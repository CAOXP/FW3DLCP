
/*
 * varibles.cpp
 *
 *  Created on: 2014-9-25
 *      Author: CIVL2013
 */

#include "Powder_0.h"


//==================================================================================
//						Keypad Setting
//==================================================================================
#ifdef	KEYPAD_FUNCTION
paraKeypad keypad(keyPins, KEYNUMBERS, keyCodes);
#endif

//==================================================================================
//						Temperature Setting
//==================================================================================
#ifdef	TEMPERATURE_MONITOR_Y_MOTOR
DS18B20_S  yMotorTempDS(A3);//pin A3
#endif


//==================================================================================
//						Mechanical Setting
//==================================================================================

// Initilize stepper driver, 11 Direction and 12 Step
//					   type,	step,			direction
AccelStepper stepperX (1, 	MOTOR_IO_X_STEP, 	MOTOR_IO_X_DIR);
AccelStepper stepperY (1, 	MOTOR_IO_Y_STEP, 	MOTOR_IO_Y_DIR);
AccelStepper stepperZA(1, 	MOTOR_IO_ZA_STEP, 	MOTOR_IO_ZA_DIR);
AccelStepper stepperZB(1, 	MOTOR_IO_ZB_STEP, 	MOTOR_IO_ZB_DIR);
AccelStepper stepperZC(1, 	MOTOR_IO_ZC_STEP, 	MOTOR_IO_ZC_DIR);
AccelStepper stepperZD(1, 	MOTOR_IO_ZD_STEP, 	MOTOR_IO_ZD_DIR);
AccelStepper stepperR (1, 	MOTOR_IO_R_STEP, 	MOTOR_IO_R_DIR);



WaitTimeMSec heartbeat(HEART_BEAT_INTERVAL_MS);

