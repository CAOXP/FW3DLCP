
/*
 * ledbuzzer.h
 *
 *  Created on: 2014-11-18
 *      Author: CIVL2013
 */


#ifdef	KEYPAD_FUNCTION

extern void initialLEDbuzzerPins();
extern void clearAllLED(void);
extern void beep();

#define		setSingleLED(led_no)	digitalWrite((led_no), HIGH)

#endif /* LEDBUZZER_H_ */
