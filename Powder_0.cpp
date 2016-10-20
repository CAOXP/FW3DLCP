
// Do not remove the include below
#include "Powder_0.h"


void setup()
{
    // Start serial communication, baud rate 115200
    Serial.begin(115200);


    // Initialize ALL the pins
    for (int i = 2; i <= 53; i++)
    {
    	pinMode(i, OUTPUT);
    	digitalWrite(i, HIGH);
    }

    //for X Y Z end stops
    pinMode(MOTOR_IO_X_ENDSTOP , INPUT_PULLUP);
    pinMode(MOTOR_IO_X_STTSTOP , INPUT_PULLUP);
    pinMode(MOTOR_IO_Y_ENDSTOP1, INPUT_PULLUP);
    pinMode(MOTOR_IO_Y_ENDSTOP2, INPUT_PULLUP);
    pinMode(MOTOR_IO_ZA_ENDSTOP, INPUT_PULLUP);
    pinMode(MOTOR_IO_ZB_ENDSTOP, INPUT_PULLUP);
    pinMode(MOTOR_IO_ZC_ENDSTOP, INPUT_PULLUP);
    pinMode(MOTOR_IO_ZD_ENDSTOP, INPUT_PULLUP);


#ifdef  KEYPAD_FUNCTION
    initialLEDbuzzerPins();
#endif

    // Initialize stepper motors
    initialSteppers();

    //echo status
    SERIAL_ECHO_STRln("==== Powder Printer ====");
    SERIAL_ECHO_STR  (" Author  : ");SERIAL_ECHO_STRln(STRING_AUTHOR);
    SERIAL_ECHO_STR  (" Version : ");SERIAL_ECHO_STRln(STRING_VERSION);
    SERIAL_ECHO_STR  (" Compiled: ");SERIAL_ECHO_STRln(__DATE__);
    SERIAL_ECHO_STR  ("           ");SERIAL_ECHO_STRln(__TIME__);
    SERIAL_ECHO_STRln("========================");
    SERIAL_ECHO_STRln("start");



    jogMove_mm(10, 0,  0, 0);

    delay(1000);

    //stepperY.enableOutputs();
    //stepperY.move(-100);
    //stepperY.runToPosition();

}





void loop()
{
	cmd_in_loop();			//receive serial commands.process the serial commands.
}



//=======================================================================
//                      ProcessCommand   need change dependently
//
//			called by processSerialCommands() in paraSericalCommandLib;
//=======================================================================

void commandProcess()
{
	//Printing command symbols
	//
	//				!!!!!!!!!!ALL SYMBOLS SHOULD BE UNIQUE!!!!!!!!!!
	//
	// CommandHead:	    G	: printing operation
	//			        M	: Management. jogmoving, adjusting
	//
	//					*	: CRC value follows					Reserved for CMD receiving process
	//					N   : Command line number if needed		Reserved for CMD receiving process
	//
	// Parameter Symbols:
    //
	//					X	:	x axis
	//					Y	:	y axis
	//					C	: 	container box
	//					P	: 	printing box
	//					n	:	nozzle tip size
	//					U	:   moving up
	//					B	:   set new layer moving back
    //                  b   :   moving back secondly, for layer pressure.
	//					S   :   moving speed, mm/s
	//					R   :   running repeatedly for R times
    //
	//
	// Commands:
    //
	//		G0	: Set a new layer			G0 U1 B200 C2 P1 R3;	(unit:mm)
	//		G1 	: CirclePrint				G1 X30 Y20 n3;			(unit:mm)
    //		G7  : Line Printing Test		G7 S60 Y0.2	R2			(unit:mm)
	//
	//
	//		M0	: Adjust XYZ by hand 		M0;						(uint:step)
	//		M1	: JogMovements,[Relatively]	M1 X2 Y3 C-5 P8;		(unit:mm)
	//		M2	: Home XY,and set zero	    M2;
	//		M3  : Set XY zero               M3;
	//		M4  : Clear Rod					M4;
    //
    //		M11 : JogXspeedMovement			M1 X2 S23				(unit:mm,mm/s)
    //

	float 	utemp,	//printing piston for pressing
			xtemp,	//
			ytemp,	//
            ztemp, //
            z1temp, //
            z2temp, //
            z3temp, //
            z4temp, //
			ntemp,	//nozzle
			stemp;	//speed

	long 	rtemp,	//repeat times
			btemp,	//back for new layer
			b2temp;	//back for pressing

	bool bHomeX, bHomeY;

    if(cmd_seen('G'))
    {
        switch((int)cmd_value())
        {
		//========================================================
		//			G0	: Set a new layer
        //	CMD: G0 U1 B200 C2 P1: SetNewLayer
        case 0:
        	utemp=z1temp=z2temp=0.0;
        	btemp=b2temp=0;

            if(cmd_seen('B')) btemp=cmd_value_long();	//		 Back
            if(cmd_seen('C')) z1temp=cmd_value();		//powder Container
            if(cmd_seen('P')) z2temp=cmd_value();		//powder Printing
            if(cmd_seen('U')) utemp=cmd_value();		//		 Up
            if(cmd_seen('R')) rtemp=cmd_value();		//		 Up
            if(btemp<1)	btemp	= SET_NEW_LAYER_DEFAULT_BACK;


            if(cmd_seen('b'))	{	b2temp = cmd_value_long();           	}
            else				{	b2temp = SET_NEW_LAYER_DEFAULT_BACK2;	}


        	SERIAL_DEBUG_STR("CMD RCV: SetNewLayer");
        	SERIAL_DEBUG_STR_INT("  bk_mm:", btemp);
        	SERIAL_DEBUG_STR_FLT("  z1_mm:", z1temp,2);
        	SERIAL_DEBUG_STR_FLT("  z2_mm:", z2temp,2);
        	SERIAL_DEBUG_STR_FLT("  up_mm:", utemp,2);
        	SERIAL_DEBUG_STR_INT("  b2_mm:", b2temp);

        	if( (btemp ==0) || (z1temp==0) || (z2temp==0) )
        	{
        		SERIAL_ERROR_STR("ERR: Wrong Data,ZERO");
        	}
        	else
        	{
                SERIAL_DEBUG_STR("  Start a layer...");

            	SetNewLayerN(btemp, z1temp, z2temp,utemp,b2temp,rtemp);

//report Y-Motor temperature
#ifdef	TEMPERATURE_MONITOR_Y_MOTOR
	SERIAL_ECHO_STR_FLT("YmtrTmp:", yMotorTempDS.getTemp(), 2);
#endif
                SERIAL_DEBUG_STR("Done!");
        	}
        	break;

#ifdef	CIRCLE_PRINT_FUNCTION
        //========================================================
        //			G1	: Circle printing with water drops
        //	CMD: G1 X30 Y20 n3:  CirclePrint
        case 1:
        	xtemp = ytemp = ntemp=0.0;

            if(cmd_seen('X')) xtemp=cmd_value();
            if(cmd_seen('Y')) ytemp=cmd_value();
            if(cmd_seen('n')) ntemp=cmd_value();

        	SERIAL_DEBUG_STR("CMD RCV: Circle Print");
        	SERIAL_DEBUG_STR_FLT("  x_mm:", xtemp,2);
        	SERIAL_DEBUG_STR_FLT("  y_mm:", ytemp,2);
        	SERIAL_DEBUG_STR_FLT("  n_mm:", ntemp,2);

        	if( (xtemp <=0.0) || (ytemp<=0.0) || (ntemp<=0.0) )
        	{
        		SERIAL_ERROR_STR("ERR: Wrong Data:ZERO");
        	}
        	else
        	{
            	SERIAL_DEBUG_STR("  Start printing ... ");
        		circlePrint(xtemp, ytemp, ntemp);        		
                SERIAL_DEBUG_STR("Done!");
        	}
        	break;
#endif
        //========================================================
        // G7  : Line Printing Test		G7 S60 Y0.2 R2
        case 7:
			ytemp = stemp=0.0;rtemp=1;

			if(cmd_seen('Y')) ytemp=cmd_value();
			if(cmd_seen('S')) stemp=cmd_value();
			if(cmd_seen('R')) rtemp=cmd_value();

			if(rtemp<0)rtemp=1;

            SERIAL_DEBUG_STR("CMD RCV: LinePrinting");
			SERIAL_DEBUG_STR_FLT("  y_mm :", ytemp,2);
			SERIAL_DEBUG_STR_FLT("  s_mms:", stemp,2);
			SERIAL_DEBUG_STR_INT("  r_   :", rtemp);
        	SERIAL_DEBUG_STR(" Start printing ...");

        	//call line print
        	LinePrintRepeat(ytemp,stemp,rtemp);

			SERIAL_DEBUG_STR("Done!");

			break;
        }
    }
    //System setting
    else if(cmd_seen('M'))
    {
        switch( (int)cmd_value() )
        {

		//========================================================
		//			M1:		JogMovements, relative value, unit:mm
        //	CMD : M1 X2 Y3 C-5 P8
        case 1:	//all data are  type : float
        	xtemp=ytemp=z1temp=z2temp=0.0;

            if(cmd_seen('X')) xtemp =cmd_value();		//
            if(cmd_seen('Y')) ytemp =cmd_value();		//
            if(cmd_seen('Z')) ztemp =cmd_value();       //
            if(cmd_seen('A')) z1temp=cmd_value();       //
            if(cmd_seen('B')) z2temp=cmd_value();       //
            if(cmd_seen('C')) z3temp=cmd_value();       //
            if(cmd_seen('D')) z4temp=cmd_value();       //

        	SERIAL_DEBUG_STR("CMD RCV: JogMove");
        	SERIAL_DEBUG_STR_FLT("  X_mm :", xtemp,2);
            SERIAL_DEBUG_STR_FLT("  Y_mm :", ytemp,2);
            SERIAL_DEBUG_STR_FLT("  Z_mm :", ztemp,2);
            SERIAL_DEBUG_STR_FLT("  ZA_mm:", z1temp,2);
            SERIAL_DEBUG_STR_FLT("  ZB_mm:", z2temp,2);
            SERIAL_DEBUG_STR_FLT("  ZC_mm:", z3temp,2);
            SERIAL_DEBUG_STR_FLT("  ZD_mm:", z4temp,2);
			SERIAL_DEBUG_STR("  Moving... ");

            jogMove_mm(xtemp, ytemp, z1temp, z2temp);
            jogMove_ex_mm(xtemp, ytemp, ztemp, z1temp, z2temp, z3temp, z4temp);

			SERIAL_DEBUG_STR("Done!");

            break;

        case 11: //jogXspeed  M11 X2 S23
        	xtemp=stemp=0.0;
            if(cmd_seen('X')) xtemp =cmd_value();		//
            if(cmd_seen('S')) stemp =cmd_value();		//

        	SERIAL_DEBUG_STR("CMD RCV: JogXspeedMovement");
        	SERIAL_DEBUG_STR_FLT("  X_mm :", xtemp,2);
        	SERIAL_DEBUG_STR_FLT("  S_mms:", stemp,2);
			SERIAL_DEBUG_STR("  Moving... ");

			jogXmmSpeed(xtemp, stemp );

			SERIAL_DEBUG_STR("Done!");

            break;
		//========================================================
		//			M2:		Homing X Y
        case 2:
        	bHomeX = cmd_seen('X');
        	bHomeY = cmd_seen('Y');

        	SERIAL_DEBUG_STR("CMD RCV: Homing");
        	if(bHomeX)
        	{
            	SERIAL_DEBUG_STR("  Homing X ...");
            	homeXaxis();
        	}
        	else if(bHomeY)
        	{
            	SERIAL_DEBUG_STR("  Homing Y ...");
            	homeYaxis();
        	}
        	else
        	{
            	SERIAL_DEBUG_STR("  Homing XY...");
        		homeXYaxis();
        	}

            SERIAL_DEBUG_STR("Done!");

        	break;
        //========================================================
        //          M3:     Set XYZ zero
        case 3:
            SERIAL_DEBUG_STR("CMD RCV: Set XYZ zero");
            setXYpositionZero();
            SERIAL_DEBUG_STR("Done!");
        	break;
		//========================================================
       	//		M4	：Clear Rod					M4;
        case 4:
        	SERIAL_DEBUG_STR("CMD RCV: Clear Rod");
        	SERIAL_DEBUG_STR("  Rolling...");
        	ClearRod();
            SERIAL_DEBUG_STR("Done!");
        	break;
//=================================================
#ifdef	REPETIER_COMPATIBLE
		// compatible to Repetier-Host
		case 115:SERIAL_ECHO_STR("FIRMWARE_NAME:rrp UUID:0000");
			break;
		case 105:SERIAL_ECHO_STR("ok T:18 B:21");
			break;
		case 114:SERIAL_ECHO_STR("X:0.00Y:0.00Z:0.00E:0.00");
			break;
		case 20:
		case 80:
		case 110:
		case 111:
			break;
		}
	}
	else if(cmd_seen('T'))
	{
		switch( (int)cmd_value() )
		{
		case 0:break;
#endif
//=================================================

        }
    }
    else
    {
    	SERIAL_ERROR_STR("ERR: Unknown CMD");
    }

}





