
#ifndef __MOVE_FUNCTIONS_H_
#define __MOVE_FUNCTIONS_H_

//

//=====================================================================================
//					Stepper Basic movements
//=====================================================================================


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
                            unsigned int n						//laying times
                        );

extern void SetNewLayer180508(float ytemp, float rtemp);

//not used, 20170704
extern void SetNewLayer0704(   long  back_Y_mm_relative,
                            float       up_ZA_mm_relative,
                            float     down_ZB_mm_relative,
                            float       up_ZB_mm_relative,
                            long      back_Y2_mm_relative,
                            unsigned int n                      //laying times
                        );
// Line print function with repeated times
extern void LinePrintRepeat(float ystepmm, float xspeedmm, uint16_t repeat);

// Circle Print
extern void circlePrint(float circle_width_mm_x, float circle_width_mm_y, float nozzle_size_mm);


extern void MultiPrinterTest1(uint16_t ylength);

#endif
