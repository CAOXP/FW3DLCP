
// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef Powder_0_H_
#define Powder_0_H_
#include "Arduino.h"
extern HardwareSerial Serial;

#include "Streaming.h"	//serial streaming
//add your includes for the project Powder_0 here

#include "pins.h"
#include "configuration.h"
#include "motor_AccelStepper.h"
#include "SoftwareSerial.h"

#include "WaitTimeMSec.h"

#include "ui_paraKeypad.h"
#include "ui_ledbuzzer.h"
#include "ui_temperature.h"
#include "ui_paraSerialCommand.h"
#include "serial_output_func.h"

#include "varibles.h"
#include "motor_head.h"


//end of add your includes here
#ifdef __cplusplus
extern "C" {
#endif
void loop();
void setup();
#ifdef __cplusplus
} // extern "C"
#endif

//add your function definitions for the project Powder_0 here




//Do not add code below this line
#endif /* Powder_0_H_ */
