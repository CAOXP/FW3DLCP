
#include "Powder_0.h"

//Three parts listed
//	1. StepperMovement Controlling
//	2. voidControlling
//	3. printMovements
//


//=====================================================================================
//=====================================================================================
//
//							Part1: Basic StepperFunctions
//
//=====================================================================================
//=====================================================================================
#define		__BASIC_STEPPER_FUNCTIONS__useless_definition
// Reset the positions of the steppers. This acts as a margin
// for the printer, making it possible to fill the pistons with
// powder and stopping the
inline void setXYpositionZero()
{
    stepperX.setCurrentPosition(0);
    stepperY.setCurrentPosition(0);
    SERIAL_CMD_ACK("X:0 Y:0 ");
}

inline void enableXYZoutputs()
{
    stepperX.enableOutputs();
    stepperY.enableOutputs();
    stepperZA.enableOutputs();
    stepperZB.enableOutputs();
    stepperZC.enableOutputs();
    stepperZD.enableOutputs();
}

inline void enableAllOutputs()
{
    enableXYZoutputs();
    stepperR.enableOutputs();
}

inline void disableXYZoutputs()
{

    stepperX.disableOutputs();
    stepperY.disableOutputs();
    stepperZA.disableOutputs();
    stepperZB.disableOutputs();
    stepperZC.disableOutputs();
    stepperZD.disableOutputs();

}

inline void disableAllOutputs()
{
    disableXYZoutputs();
    stepperR.disableOutputs();
}

void initialSteppers()
{
    //set if pins inverted.
    stepperX. setPinsInverted(false, false, false);
    stepperY. setPinsInverted(false, false, false);

    stepperZA.setPinsInverted(true, false, false);
    stepperZB.setPinsInverted(true, false, false);
    stepperZC.setPinsInverted(true, false, false);
    stepperZD.setPinsInverted(true, false, false);

    stepperR. setPinsInverted(false, false, false);

    //set enable-pins
    stepperX. setEnablePin(MOTOR_IO_X_ENABLE );
    stepperY. setEnablePin(MOTOR_IO_Y_ENABLE );
    stepperZA.setEnablePin(MOTOR_IO_ZA_ENABLE);
    stepperZB.setEnablePin(MOTOR_IO_ZB_ENABLE);
    stepperZC.setEnablePin(MOTOR_IO_ZC_ENABLE);
    stepperZD.setEnablePin(MOTOR_IO_ZD_ENABLE);
    stepperR. setEnablePin(MOTOR_IO_R_ENABLE );


    // Initialize stepper motors
    stepperX.setMaxSpeed(STEPER_X_MAXSPEED);
    stepperX.setAcceleration(STEPER_X_MAXACCEL);

    stepperY.setMaxSpeed(STEPER_Y_MAXSPEED);
    stepperY.setAcceleration(STEPER_Y_MAXACCEL);

    stepperZA.setMaxSpeed(STEPER_Z_MAXSPEED);
    stepperZA.setAcceleration(STEPER_Z_MAXACCEL);

    stepperZB.setMaxSpeed(STEPER_Z_MAXSPEED);
    stepperZB.setAcceleration(STEPER_Z_MAXACCEL);

    stepperZC.setMaxSpeed(STEPER_Z_MAXSPEED);
    stepperZC.setAcceleration(STEPER_Z_MAXACCEL);

    stepperZD.setMaxSpeed(STEPER_Z_MAXSPEED);
    stepperZD.setAcceleration(STEPER_Z_MAXACCEL);

    stepperR.setMaxSpeed(STEPER_R_MAXSPEED);
    stepperR.setAcceleration(STEPER_R_MAXACCEL);
    stepperR.setSpeed(STEPER_R_MAXSPEED);

    //Enable pins
    pinMode(MOTOR_IO_X_ENABLE, OUTPUT);
    pinMode(MOTOR_IO_Y_ENABLE, OUTPUT);
    pinMode(MOTOR_IO_ZA_ENABLE, OUTPUT);
    pinMode(MOTOR_IO_ZB_ENABLE, OUTPUT);
    pinMode(MOTOR_IO_ZC_ENABLE, OUTPUT);
    pinMode(MOTOR_IO_ZD_ENABLE, OUTPUT);
    pinMode(MOTOR_IO_R_ENABLE, OUTPUT);


    //disable all motors
    disableAllOutputs();

    //for motor driver status reading pins
    pinMode(MOTOR_IO_Y_IN_PND , INPUT_PULLUP);
    pinMode(MOTOR_IO_Y_IN_ALM , INPUT_PULLUP);
    pinMode(MOTOR_IO_ZA_IN_PND, INPUT_PULLUP);
    pinMode(MOTOR_IO_ZA_IN_ALM, INPUT_PULLUP);
    pinMode(MOTOR_IO_ZB_IN_PND, INPUT_PULLUP);
    pinMode(MOTOR_IO_ZB_IN_ALM, INPUT_PULLUP);
    pinMode(MOTOR_IO_ZC_IN_PND, INPUT_PULLUP);
    pinMode(MOTOR_IO_ZC_IN_ALM, INPUT_PULLUP);
    pinMode(MOTOR_IO_ZD_IN_PND, INPUT_PULLUP);
    pinMode(MOTOR_IO_ZD_IN_ALM, INPUT_PULLUP);

    //
    setXYpositionZero();
}


void homeXaxis()
{
    //enable X motor
    stepperX.enableOutputs();

    // if near  ZERO, move + , then back to zero
    if(    digitalRead(MOTOR_IO_X_ESTP_MIN)  == LOW )
    {
        stepperX.setCurrentPosition(0);
        stepperX.move(  250  *  X_STEP_PER_MM);        //without loop
        stepperX.runToPosition();
    }

    //moving to X-MIN
    stepperX.setCurrentPosition(0);
    stepperX.move( 0 -  X_AXIS_LENGTH_STEP - X_AXIS_LENGTH_STEP);


    while( digitalRead(MOTOR_IO_X_ESTP_MIN) )
    {
        stepperX.run();
        if(stepperX.currentPosition() == stepperX.targetPosition())
        {
            SERIAL_ERROR_STR("Err: homing X unreachable. ");
            SERIAL_ERROR_STR("Err: Reconnect the printer.");
            while(1) {}
        }
    }

    stepperX.setCurrentPosition(0);

    stepperX.move( 0- 10  *  X_STEP_PER_MM   );  
    stepperX.runToPosition();
    
    stepperX.setCurrentPosition(0);

    delay(1000);

#if X_HOME_RETRACT_MM >0
    stepperX.move(   X_STEP_PER_MM * X_HOME_RETRACT_MM   );
    stepperX.runToPosition();
#endif

    stepperX.setCurrentPosition(0);

    //disable X motor
    stepperX.disableOutputs();
}

void homeYaxis()
{
    //enable Y motor
    stepperY.enableOutputs();

    // if near  ZERO, move + , then back to zero
    if(   (  digitalRead(MOTOR_IO_Y_ENDSTOP1) && digitalRead(MOTOR_IO_Y_ENDSTOP2)     )  == false )
    {
        stepperY.setCurrentPosition(0);
        stepperY.move(  500  *  Y_STEP_PER_MM);        //without loop
        stepperY.runToPosition();
    }

    stepperY.setCurrentPosition(0);
    stepperY.setSpeed(STEPER_Y_MAXSPEED / 5);
    stepperY.move( - Y_AXIS_LENGTH_STEP - Y_AXIS_LENGTH_STEP);

    while( digitalRead(MOTOR_IO_Y_ENDSTOP1) && digitalRead(MOTOR_IO_Y_ENDSTOP2) )
    {
        stepperY.run();
        if(stepperY.currentPosition() == stepperY.targetPosition())
        {
            SERIAL_ERROR_STR("Err: homing Y unreachable.");
            SERIAL_ERROR_STR("Err: Reconnect the printer.");
            while(1) {}
        }
    }

    stepperY.move(  0 -200  *  Y_STEP_PER_MM);        //without loop
    stepperY.runToPosition();

    stepperY.setCurrentPosition(0);     //Clear the last steps


    delay(100);

#if Y_HOME_RETRACT_MM >0
    stepperY.move(Y_STEP_PER_MM * Y_HOME_RETRACT_MM);
    stepperY.runToPosition();
#endif

    stepperY.setCurrentPosition(0);

    //disable Y motor
    stepperY.disableOutputs();

    stepperY.setSpeed(STEPER_Y_MAXSPEED);
}


//=====================================================================================
//=====================================================================================
//
//							Part2: voidMovements
//
//=====================================================================================
//=====================================================================================
#define		__VOID_MOVEMENTS__useless_definition

//speed: mm per second
void jogXmmSpeed(float Xmm_relative, uint8_t Speed_mm_s)
{
    //with a stable speed.

    long jogXsteps  = Xmm_relative * X_STEP_PER_MM;
    long jogspeed	=	Speed_mm_s * X_STEP_PER_MM;

    long destPosStep = stepperX.currentPosition() + jogXsteps;

    //check out of the X axis
    if( destPosStep >  ((long)X_AXIS_LENGTH_STEP) )
    {
        //absolute running
        destPosStep = X_AXIS_LENGTH_STEP;
        SERIAL_ERROR_STR("ERR: X-MAX");
    }
    else if (destPosStep < 0)
    {
        //absolute running
        destPosStep = 0;
        SERIAL_ERROR_STR("ERR: X-MIN" );
    }

    if(Xmm_relative < 0)
    {
        jogspeed = 0 - jogspeed;
    }

    stepperX.moveTo(destPosStep);
    stepperX.setSpeed(jogspeed);

    while(stepperX.distanceToGo())
    {
        stepperX.runSpeed();
    }


    //Display the new position of X
#ifdef	CMD_DEBUG_ECHO_X_POS
    float xPosmm = stepperX.currentPosition() / ((float)X_STEP_PER_MM) ;
    SERIAL_ECHO_STR_FLT("X:", xPosmm, 1);
#endif
}

//speed will be changed during stepping
inline void jogXmm(float Xmm_relative)
{

    long jogXsteps   = Xmm_relative * X_STEP_PER_MM;

    long destPosStep = stepperX.currentPosition() + jogXsteps;

    //check out of the X axis
    if( destPosStep >  ((long)X_AXIS_LENGTH_STEP) )
    {
        //absolute running
        destPosStep = X_AXIS_LENGTH_STEP;
        SERIAL_ERROR_STR("ERR: X-MAX" );
    }
    else if (destPosStep < 0)
    {
        //absolute running
        destPosStep = 0;
        SERIAL_ERROR_STR("ERR: X-MIN" );
    }

    //absolute running
    stepperX.runToNewPosition(destPosStep);

    //Display the new position of X
#ifdef	CMD_DEBUG_ECHO_X_POS
    float xPosmm = stepperX.currentPosition() / ((float)X_STEP_PER_MM) ;
    SERIAL_ECHO_STR_FLT("X:", xPosmm, 1);
#endif

}

//speed will be changed during stepping
inline void jogYmm(float Ymm_relative)
{
    long jogYsteps = Ymm_relative * Y_STEP_PER_MM;
    long destPosStep = stepperY.currentPosition() + jogYsteps;

    //check out of the Y axis
    if( destPosStep >  ((long)Y_AXIS_LENGTH_STEP) )
    {
        //absolute running
        stepperY.runToNewPosition((long)Y_AXIS_LENGTH_STEP);
        SERIAL_ERROR_STR("ERR: Y-MAX" );
    }
    else if (destPosStep < 0)
    {
        //absolute running
        stepperY.runToNewPosition(0);
        SERIAL_ERROR_STR("ERR: Y-MIN" );
    }
    else
    {
        //relative running
        stepperY.move(jogYsteps);
        stepperY.runToPosition();
    }

    //Display the new position of Y
#ifdef	CMD_DEBUG_ECHO_Y_POS
    float yPosmm = stepperY.currentPosition() / ((float)Y_STEP_PER_MM) ;
    SERIAL_ECHO_STR_FLT("Y:", yPosmm, 1);
#endif
}


inline void jogZmm(float z_mm_relative)
{
    long tmp = Z_STEP_PER_MM * z_mm_relative;
    bool runFlag = true;
    bool runFlagA = false;
    bool runFlagB = false;
    bool runFlagC = false;
    bool runFlagD = false;
    stepperZA.move(tmp);
    stepperZB.move(tmp);
    stepperZC.move(tmp);
    stepperZD.move(tmp);

    while(runFlag)
    {
        runFlagA = stepperZA.run();
        runFlagB = stepperZB.run();
        runFlagC = stepperZC.run();
        runFlagD = stepperZD.run();

        runFlag = runFlagA && runFlagB && runFlagC && runFlagD;

        //check the position of each sensor.
        if(1)
        {}
    }
}
#define   FLOAT_ZERO_GAP	0.0001

inline bool isFloatZero(float dat)
{
    return abs(dat) < FLOAT_ZERO_GAP ;
}

inline void jogZAmm(float ZA_mm_relative)
{
    stepperZA.move(Z_STEP_PER_MM * ZA_mm_relative);
    stepperZA.runToPosition();
}

inline void jogZBmm(float ZB_mm_relative)
{
    stepperZB.move(Z_STEP_PER_MM * ZB_mm_relative);
    stepperZB.runToPosition();
}

inline void jogZCmm(float ZC_mm_relative)
{
    stepperZC.move(Z_STEP_PER_MM * ZC_mm_relative);
    stepperZC.runToPosition();
}

inline void jogZDmm(float ZD_mm_relative)
{
    stepperZD.move(Z_STEP_PER_MM * ZD_mm_relative);
    stepperZD.runToPosition();
}


void jogMove_ex_mm(	float x_mm_relative, 	float y_mm_relative,
                    float z_mm_relative,
                    float ZA_mm_relative, 	float ZB_mm_relative,
                    float ZC_mm_relative, 	float ZD_mm_relative)
{
    //enable XYZ motors
    enableXYZoutputs();

    SERIAL_DEBUG_STR_FLT("  ZA_mm_relative:", ZA_mm_relative, 2);
    SERIAL_DEBUG_STR_FLT("  ZB_mm_relative:", ZB_mm_relative, 2);
    SERIAL_DEBUG_STR_FLT("  ZC_mm_relative:", ZC_mm_relative, 2);
    SERIAL_DEBUG_STR_FLT("  ZD_mm_relative:", ZD_mm_relative, 2);


    if( abs(x_mm_relative)  >    FLOAT_ZERO_GAP)
    {
        jogXmm(x_mm_relative);
    }

    if( abs(y_mm_relative)  >  FLOAT_ZERO_GAP  )
    {
        jogYmm(y_mm_relative);
    }

    if(  abs(z_mm_relative) >  FLOAT_ZERO_GAP )
    {
        jogZmm(z_mm_relative);
    }
    else
    {
        SERIAL_DEBUG_STR(" sdfelativ");

        if(  abs(ZA_mm_relative) > FLOAT_ZERO_GAP )
        {
            jogZAmm(ZA_mm_relative);
        }

        if(  abs(ZB_mm_relative) > FLOAT_ZERO_GAP )
        {
            jogZBmm(ZB_mm_relative);
        }

        if(  abs(ZC_mm_relative) > FLOAT_ZERO_GAP )
        {
            jogZCmm(ZC_mm_relative);
        }

        if(  abs(ZD_mm_relative) > FLOAT_ZERO_GAP )
        {
            jogZDmm(ZD_mm_relative);
        }
    }

    //disable all motors
    //disableXYZoutputs();
}




//=====================================================================================
//=====================================================================================
//
//							Part3: Printing Movements
//
//=====================================================================================
//=====================================================================================
#define		__PRINTING_MOVEMENTS_useless_definition

void homeXYaxis()
{
    homeXaxis();
    homeYaxis();
    //reset the positions of each motor.
    setXYpositionZero();
}


void ClearRod()
{
    stepperR.enableOutputs();
    stepperR.move(10000);
    stepperR.runToPosition();
    stepperR.disableOutputs();
}

// Function: set a new layer 						all unit: mm
//
// 1. scroll back the Y axis with a relative value,
// 2. up the ZA by with a relative value,
// 3. down the ZB by with a relative value,
// 4. roll back
// 5. up the ZB for pressure
// 6. Scroll back , press the ZB
// 7. up again , for second pressure.
void SetNewLayer(	long   		back_Y_mm_relative,
                    float       up_ZA_mm_relative,
                    float     down_ZB_mm_relative,
                    float       up_ZB_mm_relative,
                    long   	  back_Y2_mm_relative)
{

    //enable ALL motors
    enableAllOutputs();

    //1.scroll back the start of Y axis.
    stepperR.setCurrentPosition(0);
    stepperY.setSpeed(STEPER_Y_MAXSPEED * (2 / 4));					//set the Y speed
    stepperY.move( 0 - Y_AXIS_LENGTH_STEP * Y_STEP_PER_MM);
    stepperR.moveTo(200000);

    while( digitalRead(HOME_IO_Y) && (stepperY.distanceToGo()) )
    {
        stepperY.run();
        stepperR.run();
    }
    stepperY.stop();
    stepperY.setCurrentPosition(0);		//Clear the last steps

#if Y_HOME_RETRACT_MM >0
    stepperY.move(Y_STEP_PER_MM * Y_HOME_RETRACT_MM);
    stepperY.runToPosition();
    stepperY.setCurrentPosition(0);		//Clear the last steps
#endif

    //2.ZA up  for a new layer
    //3.ZB down for a new layer
#ifdef	PRINT_PREVENT_SWEPT_MM
    jogZAmm( PRINT_PREVENT_SWEPT_MM +   up_ZA_mm_relative );
    jogZBmm( PRINT_PREVENT_SWEPT_MM - down_ZB_mm_relative );
#else
    jogZAmm(		up_ZA_mm_relative );
    jogZBmm( 0 -  down_ZB_mm_relative );
#endif

    //4.rolling back to set a new layer of powder.
    stepperY.move( back_Y_mm_relative * Y_STEP_PER_MM );
    stepperR.setCurrentPosition(0);
    stepperR.moveTo(200000);
    while(stepperY.distanceToGo())
    {
        stepperR.run();
        stepperY.run();
    }


    //=================================
    //5.6.  5.7 two times of press
    if(back_Y2_mm_relative && up_ZB_mm_relative)
    {
        //5.ZB up, in order to make PRESSURE.
        jogZBmm( up_ZB_mm_relative );

        //6.scroll back the Y2 axis.
        stepperY.move( 0 - back_Y2_mm_relative * Y_STEP_PER_MM);
        stepperR.setCurrentPosition(0);
        stepperR.moveTo(100000);
        while( digitalRead(HOME_IO_Y) && (stepperY.distanceToGo()) )
        {
            stepperY.run();
            stepperR.run();
        }

        //5.2.ZB up, in order to make PRESSURE.
        jogZBmm( up_ZB_mm_relative );

        //7.rolling back
        stepperY.move( back_Y2_mm_relative * Y_STEP_PER_MM );
        stepperR.setCurrentPosition(0);
        stepperR.moveTo(-100000);
        while(stepperY.distanceToGo())
        {
            stepperR.run();
            stepperY.run();
        }

    }// press movement above
    //==============================



    //lower both of the ZA ZB to prevent being swept
#ifdef	PRINT_PREVENT_SWEPT_MM
    jogZAmm( 0 - PRINT_PREVENT_SWEPT_MM );
    jogZBmm( 0 - PRINT_PREVENT_SWEPT_MM );
#endif

    //稍微转动，抖灰
    stepperR.setCurrentPosition(0);
    stepperR.move(-300);
    stepperR.runToPosition();

    //disable motors
    disableAllOutputs();

}

// Function: set a new layer 						all unit: mm
//
// 1. scroll back the Y axis with a relative value,
// 2. up the ZA by with a relative value,
// 3. down the ZB by with a relative value,
// 4. roll back
// 5. up the ZB for pressure
// 6. Scroll back , press the ZB
// 7. up again , for second pressure.
void SetNewLayerN(	long   		back_Y_mm_relative,
                    float       up_ZA_mm_relative,
                    float     down_ZB_mm_relative,
                    float       up_ZB_mm_relative,
                    long   	  back_Y2_mm_relative,
                    unsigned int n					//laying times
                 )
{

    unsigned int i = 0;	//laying time index

    //enable ALL motors
    enableAllOutputs();

startlaying:

    //1.scroll back the start of Y axis.
    stepperR.setCurrentPosition(0);
    stepperR.moveTo(200000);

    stepperY.setSpeed(STEPER_Y_MAXSPEED * (2 / 4));					//set the Y speed
    stepperY.move( 0 - Y_AXIS_LENGTH_STEP * Y_STEP_PER_MM);

    while( digitalRead(HOME_IO_Y) && (stepperY.distanceToGo()) )
    {
        stepperY.run();
        stepperR.run();
    }
    stepperY.stop();
    stepperY.setCurrentPosition(0);		//Clear the last steps

#if Y_HOME_RETRACT_MM >0
    stepperY.move(Y_STEP_PER_MM * Y_HOME_RETRACT_MM);
    stepperY.runToPosition();
    stepperY.setCurrentPosition(0);		//Clear the last steps
#endif



    //2.ZA up  for a new layer
    //3.ZB down for a new layer
#ifdef	PRINT_PREVENT_SWEPT_MM

    if (i == 0)	//the first time laying needs
    {
        jogZAmm( PRINT_PREVENT_SWEPT_MM +   up_ZA_mm_relative );
        jogZBmm( PRINT_PREVENT_SWEPT_MM - down_ZB_mm_relative );
    }
    else
    {
        jogZAmm(		up_ZA_mm_relative );
        jogZBmm( 0 -  down_ZB_mm_relative );
    }

#else
    jogZAmm(		up_ZA_mm_relative );
    jogZBmm( 0 -  down_ZB_mm_relative );
#endif


    //4.rolling back to set a new layer of powder.
    stepperY.move( back_Y_mm_relative * Y_STEP_PER_MM );
    stepperR.setCurrentPosition(0);
    stepperR.moveTo(200000);
    while(stepperY.distanceToGo())
    {
        stepperR.run();
        stepperY.run();
    }


    //=================================
    //5.6.  5.7 two times of press
    if(back_Y2_mm_relative && up_ZB_mm_relative)
    {
        //5.ZB up, in order to make PRESSURE.
        jogZBmm( up_ZB_mm_relative );

        //6.scroll back the Y2 axis.
        stepperY.move( 0 - back_Y2_mm_relative * Y_STEP_PER_MM);
        stepperR.setCurrentPosition(0);
        stepperR.moveTo(100000);
        while( digitalRead(HOME_IO_Y) && (stepperY.distanceToGo()) )
        {
            stepperY.run();
            stepperR.run();
        }

        //5.2.ZB up, in order to make PRESSURE.
        jogZBmm( up_ZB_mm_relative );

        //7.rolling back
        stepperY.move( back_Y2_mm_relative * Y_STEP_PER_MM );
        stepperR.setCurrentPosition(0);
        stepperR.moveTo(-100000);
        while(stepperY.distanceToGo())
        {
            stepperR.run();
            stepperY.run();
        }

    }// press movement above
    //==============================


    i++;
    if(i < n)
    {
        goto startlaying;
    }

    //lower both of the ZA ZB to prevent being swept
#ifdef	PRINT_PREVENT_SWEPT_MM
    jogZAmm( 0 - PRINT_PREVENT_SWEPT_MM );
    jogZBmm( 0 - PRINT_PREVENT_SWEPT_MM );
#endif

    //稍微转动，抖灰
    stepperR.setCurrentPosition(0);
    stepperR.move(-300);
    stepperR.runToPosition();

    //disable motors
    disableAllOutputs();
}


//Line-printing function, with repeated times, fixed running X speed.
void LinePrintRepeat(float ystepmm, float xspeedmm, uint16_t repeat)
{
    stepperX.enableOutputs();
    stepperY.enableOutputs();
    while(repeat--)
    {
        jogXmmSpeed(130, xspeedmm);
        jogYmm(ystepmm);
        jogXmmSpeed(-130, xspeedmm);
        jogYmm(ystepmm);
        SERIAL_DEBUG_STR_INT("left:", repeat);
    }
    stepperX.disableOutputs();
    stepperY.disableOutputs();
}

//=========================================================================
#ifdef	CIRCLE_PRINT_FUNCTION
void runSpeedtoPositionX(long pos_rel)
{
}
void runSpeedtoPositionY(long pos_rel)
{
}
//==========================================================================
//      画一个螺旋回字形的。由外及内
//==========================================================================

#define	PRINT_SPEED			   100 	//unit: mm/sec

void circlePrint(float circle_width_mm_x, float circle_width_mm_y, float nozzle_size_mm)
{

}
#endif
