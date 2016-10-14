
/*
 * conf.h
 *
 *  Created on: 2014-9-26
 *      Author: CIVL2013
 */

#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

//===============================================================================
//
//===============================================================================
#define STRING_VERSION 		"0.1.0"
#define STRING_AUTHOR 		"CAO.XP"

//===============================================================================
//							Printing Parameters
//===============================================================================

	// LOW the Z1,Z2 to prevent being swept by the scroller during printing.
	// LIFT back before setNewLayer()
#define		PRINT_PREVENT_SWEPT_MM		1.0

//==================================================================================
//						Temperature Monitor
//==================================================================================
#define	TEMPERATURE_MONITOR_Y_MOTOR

//===============================================================================
//							Function Enables
//===============================================================================

//Enable keypad function, which controls LEDs, Buzzer, and Keys.
//#define		KEYPAD_FUNCTION

#ifdef	KEYPAD_FUNCTION
#define		ADJUST_XYZ_BY_HAND
#endif

//Enable Circle_Print function
//#define	CIRCLE_PRINT_FUNCTION

//Command lines compatible to Repetier-Host software
#define		REPETIER_COMPATIBLE

//output the errors when occuring
#define		CMD_ERROR_OUTPUT 

//enable the serial output the information when printing
#define		CMD_DEBUG_OUTPUT
#ifdef		CMD_DEBUG_OUTPUT

	#define		CMD_DEBUG_ECHO_X_POS
	#define		CMD_DEBUG_ECHO_Y_POS

	//send back the command information
	#define		CMD_DEBUG_ECHO_CMDINFO

#endif




#define		SET_NEW_LAYER_DEFAULT_BACK		315
#define		SET_NEW_LAYER_DEFAULT_BACK2		160


//===============================================================================
// 							Stepper Configurations
//===============================================================================

//all units below are step
#define	STEPER_X_MAXSPEED	(long)40000		//max speed
#define	STEPER_X_MAXACCEL	(long)400000	//max acceleration

#define	STEPER_Y_MAXSPEED	(long)30000 	//max speed
#define	STEPER_Y_MAXACCEL	(long)20000		//max acceleration

#define	STEPER_Z_MAXSPEED	(long)30000		//max speed
#define	STEPER_Z_MAXACCEL	(long)20000		//max acceleration

#define	STEPER_R_MAXSPEED	(long)30000 	//max speed
#define	STEPER_R_MAXACCEL	(long)50000		//max acceleration

//===============================================================================
//
#define	X_STEP_CORRECTION	1.000
#define	Y_STEP_CORRECTION	1.000
#define	Z_STEP_CORRECTION	1.000




//													修正		细分      一圈前进长度mm
#define	X_STEP_PER_MM		(float)( (X_STEP_CORRECTION)*(200.0* 8) / (40.0) )	//20-2GT齿轮
#define	Y_STEP_PER_MM		(float)( (Y_STEP_CORRECTION)*(200.0* 8) / (40.0) )	//20-2GT齿轮
#define	Z_STEP_PER_MM		(float)( (Z_STEP_CORRECTION)*(200.0* 8) / (2.0)  )	//丝杆

//retracting after homing
#define	X_HOME_RETRACT_MM 	1
#define	Y_HOME_RETRACT_MM 	5
//===============================================================================

#define	X_AXIS_LENGTH_MM	130	//mm
#define	Y_AXIS_LENGTH_MM	320	//mm

#define	X_AXIS_LENGTH_STEP			(long)((X_STEP_PER_MM) * (X_AXIS_LENGTH_MM) )	//X-AXIS length 160mm
#define	Y_AXIS_LENGTH_STEP			(long)((Y_STEP_PER_MM) * (Y_AXIS_LENGTH_MM) )	//y-AXIS length 400mm



#endif /* CONF_H_ */
