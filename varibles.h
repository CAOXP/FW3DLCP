
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
//						Keypad definition
//==================================================================================
#ifdef	KEYPAD_FUNCTION

	#define		KEY_VL_UP		0x01
	#define		KEY_VL_DW		0x02
	#define		KEY_VL_XYZ		0x03
	#define		KEY_VL_SET		0x04
	#define		KEY_VL_STOP		0x05


#define		KEYNUMBERS		5		//define numbers of key
const uint8_t	keyPins[KEYNUMBERS]  = {
								KEY_IO_UP,
								KEY_IO_DW,
								KEY_IO_XYZ,
								KEY_IO_SET,
								KEY_IO_STOP,};

const uint8_t	keyCodes[KEYNUMBERS]  = {
								KEY_VL_UP,
								KEY_VL_DW,
								KEY_VL_XYZ,
								KEY_VL_SET,
								KEY_VL_STOP,};

extern paraKeypad keypad;
#endif

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


#endif /* VARIBLES_H_ */
