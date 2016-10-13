
#ifndef __MOVE_FUNCTIONS_H_
#define __MOVE_FUNCTIONS_H_

//

//=====================================================================================
//					Stepper Basic movements
//=====================================================================================

#define	 ENABLE_X_MOTOR_DRIVE		digitalWrite(MOTOR_IO_X_ENABLE, LOW);
#define	DISABLE_X_MOTOR_DRIVE		digitalWrite(MOTOR_IO_X_ENABLE, HIGH);

#define	 ENABLE_Y_MOTOR_DRIVE		digitalWrite(MOTOR_IO_Y_ENABLE, LOW);
#define	DISABLE_Y_MOTOR_DRIVE		digitalWrite(MOTOR_IO_Y_ENABLE, HIGH);

#define	 ENABLE_R_MOTOR_DRIVE		digitalWrite(MOTOR_IO_R_ENABLE, LOW);
#define	DISABLE_R_MOTOR_DRIVE		digitalWrite(MOTOR_IO_R_ENABLE, HIGH);


#define	 ENABLE_ZA_MOTOR_DRIVE		digitalWrite(MOTOR_IO_ZA_ENABLE, LOW);
#define	DISABLE_ZA_MOTOR_DRIVE		digitalWrite(MOTOR_IO_ZA_ENABLE, HIGH);

#define	 ENABLE_ZB_MOTOR_DRIVE		digitalWrite(MOTOR_IO_ZB_ENABLE, LOW);
#define	DISABLE_ZB_MOTOR_DRIVE		digitalWrite(MOTOR_IO_ZB_ENABLE, HIGH);

#define	 ENABLE_ZC_MOTOR_DRIVE		digitalWrite(MOTOR_IO_ZC_ENABLE, LOW);
#define	DISABLE_ZC_MOTOR_DRIVE		digitalWrite(MOTOR_IO_ZC_ENABLE, HIGH);

#define	 ENABLE_ZD_MOTOR_DRIVE		digitalWrite(MOTOR_IO_ZD_ENABLE, LOW);
#define	DISABLE_ZD_MOTOR_DRIVE		digitalWrite(MOTOR_IO_ZD_ENABLE, HIGH);


extern void initialSteppers();

	// Reset the positions of the steppers. This acts as a margin
	// for the printer, making it possible to fill the pistons with
	// powder and stopping the
extern void setXYpositionZero();

//=====================================================================================
//					System movements
//=====================================================================================
extern void homeXaxis();
extern void homeYaxis();


#define		CMD_DEBUG__DISPLAY_XY_POSITION		// when jog moving

extern void jogXmmSpeed(float Xmm_relative, uint8_t Speed_mm_s);
//extern inline void jogXmm(float Xmm_relative);
//extern inline void jogYmm(float Ymm_relative);
//extern inline void jogZAmm(float ZA_mm_relative);
//extern inline void jogZBmm(float ZB_mm_relative);



#ifdef	ADJUST_XYZ_BY_HAND
extern void adjustXYZ();
#endif
extern void abortPrint();

extern void jogMove_mm(	float x_mm_relative, float y_mm_relative,
						float ZA_mm_relative, float ZB_mm_relative);

extern void jogMove_ex_mm(	float x_mm_relative, 	float y_mm_relative,
							float z_mm_relative,
							float ZA_mm_relative, 	float ZB_mm_relative,
							float ZC_mm_relative, 	float ZD_mm_relative);

//=====================================================================================
//					Printing movements
//=====================================================================================
extern void homeXYaxis();
extern void ClearRod();

//set up a new layer
extern void SetNewLayer(	long       back_Y_mm_relative,
							float       up_ZA_mm_relative,
							float     down_ZB_mm_relative,
							float       up_ZB_mm_relative,		//up for pressure
							long      back_Y2_mm_relative		//back for pressure
						);
extern void SetNewLayerN(	long   		back_Y_mm_relative,
							float       up_ZA_mm_relative,
							float     down_ZB_mm_relative,
							float       up_ZB_mm_relative,
							long   	  back_Y2_mm_relative,
							unsigned int n					//laying times
							);

// Line print function with repeated times
extern void LinePrintRepeat(float ystepmm, float xspeedmm, uint16_t repeat);

// Circle Print
extern void circlePrint(float circle_width_mm_x, float circle_width_mm_y, float nozzle_size_mm);




#endif
