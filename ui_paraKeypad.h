
/*
 * ParaKeyPad.h
 *
 *  Created on: Jan 8, 2015
 *      Author: CaoXP
 *
 *      Update Log:
 *			1. 2015Jan08: Migrated from C51 to Arduino
 *			2. 2015Jan15: bug fixing
 *
 *		Function description
 *			1.detect not only the key pressed but the key up and bursting.
 *			2.return values contains information of two parts
 *				0b xxx yyyyy
 *					   yyyyy:----indicate the key value, from 0-31
 *				   xxx-----------indicate the key parameter:
 *				   									1. key pressed down
 *				   									2. key pressed hold
 *				   									3. then key bursting
 *				   									4. key pressed up
 *      Limitation:
 *      	1.At most 32 keys detection, due to '0b000yyyyy'
 *      	2.All key are needed to connected to HIGH or LOW
 *
 *      Extension:
 *      	1.changing the return type from BYTE to WORD can detect more keys. fix limitation 1.
 *      	2.rewriting the function getKeyCode() can detect matrix key pad. fix limitation 2.
 */
 
#ifdef	KEYPAD_FUNCTION


//===========================================================================
//============================= KeyPad Config  ==============================
//===========================================================================

//Key detecting time interval, unit: ms
#define     KEY_DETECT_TIME_INTERVAL_DEFAULT        50

//Bursting key setting, multiple of the detecting time interval
#define     KEY_BURST_FIRST_DEFAULT      			15		//first burst key
#define     KEY_BURST_INTERVAL_DEFAULT       		5     	//next interval

//Double key detection setting
#define		KEY_DOUBLE_DETECT_ENABLE
#define     KEY_DOUBLE_INTERVAL     				10     	//

//Invert the pins
#define		KEY_PIN_INVERT		false	// false: LOW  as key pressed
										// true : HIGH as key pressed.


//===========================================================================
//=============================No need change    ============================
//===========================================================================

//key parameters
#define		KEY_PR_MASK			0b11100000
#define     KEY_PR_DW           0b00100000     //key down
#define     KEY_PR_HD           0b01000000     //key hold to burst
#define     KEY_PR_BR           0b01100000     //bursting keys
#define     KEY_PR_UP           0b10000000     //key up
#define     KEY_PR_DB           0b10100000     //double key down detection

#define     NO_KEY              0b11100000	  //no key pressed

//key values
#define		KEY_VL_MASK		0b00011111
#define		KEY_VL_0		0X00
#define		KEY_VL_1		0X01
#define		KEY_VL_2		0X02
#define		KEY_VL_3		0X03
#define		KEY_VL_4		0X04
#define		KEY_VL_5		0X05
#define		KEY_VL_6		0X06
#define		KEY_VL_7		0X07
#define		KEY_VL_8		0X08
#define		KEY_VL_9		0X0A
#define		KEY_VL_10		0X0B
#define		KEY_VL_11		0X0C
#define		KEY_VL_12		0X0D
#define		KEY_VL_13		0X0E
#define		KEY_VL_14		0X0F
//..


class paraKeypad
{
public:
	paraKeypad();
	paraKeypad(const uint8_t keyPins_[], const uint8_t key_numbers_ );
	paraKeypad(const uint8_t keyPins_[], const uint8_t key_numbers_ , const uint8_t keyCodes_[]);
	virtual ~paraKeypad();

	// scanning key
	// 	1.return the format of KEY_PARA and KEY_VALUE in BYTE
	//  2.no loop included
	//  3.need to be called in a loop
	//	KEY_PARA	the 3 high bits			0bxxx00000
	//		#define     KEY_PR_DW           0b00100000
	//		#define     KEY_PR_HD           0b01000000
	//		#define     KEY_PR_BR          	0b01100000
	//		#define     KEY_PR_UP           0b10000000
	//		#define     KEY_PR_DB         	0b10100000
	//		#define     NO_KEY             	0b11100000
	//	KEY_VALUE	the 5 low bits			0b000xxxxx
	//		#define		KEY_VL_1			0b00000001
	uint8_t scanKey();

private:
	uint8_t keyNumbers;			//how many keys
	const uint8_t * keyPins;			//what are their pins
	const uint8_t * keyCodes;			//what are their values

	uint8_t keyScanTimeInterval;//key detection time interval		unit:ms

	uint8_t keyBurstFirst;		//the first interval to BURST KEY	uint:keyScanTimeInterval
	uint8_t keyBurstSpace;		//the next intervals				uint:keyScanTimeInterval

	//default setting of above varieties
	void setDefault();

	//initial the pins as INPUT with PULLUP
	void initalPins();

	//get the original key code
	uint8_t getKeyCode();

	//detect key with parameters and value
	// using a state-machine to detect different key status
	uint8_t getKey();
};


#endif


