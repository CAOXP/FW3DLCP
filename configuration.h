
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
//#define		TEMPERATURE_MONITOR_Y_MOTOR

//===============================================================================
//							Function Enables
//===============================================================================
#define		HEART_BEAT_INTERVAL_MS	1000	//主控板的心跳信号时间间隔

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
#define	STEPER_X_MAXSPEED	(long)5000		//max speed
#define	STEPER_X_MAXACCEL	(long)5000		//max acceleration

#define	STEPER_Y_MAXSPEED	(long)2000 		//max speed
#define	STEPER_Y_MAXACCEL	(long)3000		//max acceleration

#define	STEPER_Z_MAXSPEED	(long)30000		//max speed
#define	STEPER_Z_MAXACCEL	(long)20000		//max acceleration

#define	STEPER_R_MAXSPEED	(long)30000 	//max speed
#define	STEPER_R_MAXACCEL	(long)50000		//max acceleration

//============================================================================================
//
#define	X_STEP_CORRECTION	1.0
#define	Y_STEP_CORRECTION	1.0
#define	Z_STEP_CORRECTION	1.0


// subdivison of the drivers.
//if none subdivision, 200 steps per round

#define	R_DRIVER_MS_CFG		8
#define	X_DRIVER_MS_CFG		8
#define	Y_DRIVER_MS_CFG		4
#define	Z_DRIVER_MS_CFG		4
//
#define 	X_MM_PER_ROUND		(57.2*3.14)
#define 	Y_MM_PER_ROUND		(177.9)				//齿轮直径后的周长？？？？这个要重新再量,  (测量得直径62.8  @20161020)
#define 	Z_MM_PER_ROUND			(5.0) 			//螺杆是 5005的尺寸，齿轮是1:1

//                                               修正                 细分       电机转一圈前进长度mm(加入齿轮转换后)
#define	X_STEP_PER_MM		(float)( (X_STEP_CORRECTION)*(200.0* (X_DRIVER_MS_CFG) ) /      (X_MM_PER_ROUND)    )
#define	Y_STEP_PER_MM		(float)( (Y_STEP_CORRECTION)*(200.0* (Y_DRIVER_MS_CFG) ) /      (Y_MM_PER_ROUND)    )
#define	Z_STEP_PER_MM		(float)( (Z_STEP_CORRECTION)*(200.0* (Z_DRIVER_MS_CFG) ) /      (Z_MM_PER_ROUND)    )


//============================================================================================



//retracting after homing
#define	X_HOME_RETRACT_MM 	10
#define	Y_HOME_RETRACT_MM 	30
//===============================================================================

#define	X_AXIS_LENGTH_MM	((long)1300)	//mm
#define	Y_AXIS_LENGTH_MM	((long)1700)	//mm

#define	X_AXIS_LENGTH_STEP			(long)((X_STEP_PER_MM) * (X_AXIS_LENGTH_MM) )	//X-AXIS length 160mm
#define	Y_AXIS_LENGTH_STEP			(long)((Y_STEP_PER_MM) * (Y_AXIS_LENGTH_MM) )	//y-AXIS length 400mm


#endif /* CONF_H_ */
