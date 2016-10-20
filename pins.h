/*
 * pins.h
 *
 *  Created on: 2015-3-26
 *      Author: CIVL2013
 */

#ifndef PINS_H_
#define PINS_H_



 //      D ------------------------------  B
 //      |                                |
 //      |                                |
 //      |                                |
 //      |                                |
 //      |                                |
 //      |                                |
 //      |                                |
 //      |                                |
 //      |                                |
 //      |                                |
 //      C ------------------------------  A
 //                 | Contrl-Box|          



#define	MOTOR_IO_ZA_ENDSTOP	A1 		//confirmed on 13OCT
#define	MOTOR_IO_ZB_ENDSTOP	A1
#define	MOTOR_IO_ZC_ENDSTOP	A2
#define	MOTOR_IO_ZD_ENDSTOP	A3

#define	MOTOR_IO_Y_ENDSTOP1	A4		//confirmed on 13OCT
#define	MOTOR_IO_Y_ENDSTOP2	A5

#define	MOTOR_IO_X_ENDSTOP	A6		//not confirmed. 13oct, not installed
#define	MOTOR_IO_X_STTSTOP	A7

 //PUL = STEP

 // X axis, is normal stepper, driver: ZD-2HD542
	//	PUL+
	//	PUL-
	//	DIR+
	//	DIR-
 	//	ENA+		high				?propably?
 	//	ENA-		high means enable

// X-driver CONFIG  13oct2016
 //	1004-367 mm  for 3000 steps
 //	DIR = HIGH:  moving to the control box
 //	ENA= HIGH:  motor enable, lock
 // switch config :   5.7.8 = on,   800-division：4


#define	MOTOR_IO_X_STEP		41	//x motor IO definition			Normal stepper
#define	MOTOR_IO_X_DIR		40
#define	MOTOR_IO_X_ENABLE	39	


//Y and  ZA ZB ZC ZD are servo motors with driver: ZDM-2HA860
	//	PUL+
	//	PUL-
	//	DIR+
	//	DIR-
 	//	ENA+		high
 	//	ENA-		high means enable


 
 //Y config now
 //	DIR = HIGH ; moving to MOTOR A
 //          moving 2000steps for 885mm
 // switch : 4 division, switch 1 off

#define	MOTOR_IO_Y_STEP		14	//Y motor IO definition				SERVO motor
#define	MOTOR_IO_Y_DIR		15
#define	MOTOR_IO_Y_ENABLE	16	
#define	MOTOR_IO_Y_IN_PND	17
#define	MOTOR_IO_Y_IN_ALM	18	


 //Z config now
 //	DIR = HIGH ; moving 
 //          moving 1000steps for  12mm
 // switch : all on, no division

#define	MOTOR_IO_ZA_STEP	38	//ZA motor IO definition			SERVO motor
#define	MOTOR_IO_ZA_DIR		37
#define	MOTOR_IO_ZA_ENABLE	36	
#define	MOTOR_IO_ZA_IN_PND	35
#define	MOTOR_IO_ZA_IN_ALM	34	

#define	MOTOR_IO_ZB_STEP	33	//ZB motor IO definition			SERVO motor
#define	MOTOR_IO_ZB_DIR		32
#define	MOTOR_IO_ZB_ENABLE	31	
#define	MOTOR_IO_ZB_IN_PND	30
#define	MOTOR_IO_ZB_IN_ALM	29	

#define	MOTOR_IO_ZC_STEP	24	//ZC motor IO definition			SERVO motor
#define	MOTOR_IO_ZC_DIR		25
#define	MOTOR_IO_ZC_ENABLE	26	
#define	MOTOR_IO_ZC_IN_PND	27
#define	MOTOR_IO_ZC_IN_ALM	28	

#define	MOTOR_IO_ZD_STEP	19	//ZD motor IO definition			SERVO motor
#define	MOTOR_IO_ZD_DIR		20
#define	MOTOR_IO_ZD_ENABLE	21	
#define	MOTOR_IO_ZD_IN_PND	22
#define	MOTOR_IO_ZD_IN_ALM	23	

 // R axis, is normal stepper, driver: 		Micro Stepper driver, in reverse squance
 	//	ENA-		high means enable
 	//	ENA+		high		
	//	DIR-	
	//	DIR+
	//	PUL-
	//	PUL+

#define	MOTOR_IO_R_STEP		44	//R motor IO definition				Normal stepper
#define	MOTOR_IO_R_DIR		43
#define	MOTOR_IO_R_ENABLE	42	


//IO configuration  ;   previous version
#define HOME_IO_X    12	//Home of X axis
#define HOME_IO_Y    13	//home of Y axis

#define KEY_IO_UP		37	// up and down
#define KEY_IO_DW		35
#define KEY_IO_XYZ		39
#define KEY_IO_SET		41
#define KEY_IO_STOP		43 

#define LED_IO_1	13	//LEDs for instructions
#define LED_IO_2	12
#define LED_IO_3	11
#define BUZZER_IO	10	//


#endif /* PINS_H_ */
