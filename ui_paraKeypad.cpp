
/*
 * paraKeypad.cpp
 *
 *  Created on: Jan 8, 2015
 *      Author: caoxp
 */

#include "ui_paraKeypad.h"


#ifdef	KEYPAD_FUNCTION

//set default values
void paraKeypad::setDefault()
{
	keyScanTimeInterval=KEY_DETECT_TIME_INTERVAL_DEFAULT;	//unit:ms

	keyBurstFirst = KEY_BURST_FIRST_DEFAULT;
	keyBurstSpace = KEY_BURST_INTERVAL_DEFAULT;
}

void paraKeypad::initalPins()
{
	uint8_t i=0;
	for(i=0; i<this->keyNumbers ; i++)
	{
		pinMode(*(keyPins+i), INPUT_PULLUP);
	}
}


paraKeypad::paraKeypad() {
	keyNumbers	= 0;
	this->setDefault();
	this->initalPins();
}

paraKeypad::paraKeypad(const uint8_t keyPins_[], const uint8_t key_numbers_)
{
	keyPins		=	keyPins_;
	keyCodes	=	0;
	keyNumbers	=	key_numbers_;
	this->setDefault();
	this->initalPins();
}

paraKeypad::paraKeypad(const uint8_t keyPins_[], const uint8_t key_numbers_, const uint8_t keyCodes_[])
{
	keyPins		=	keyPins_;
	keyCodes	=	keyCodes_;
	keyNumbers	=	key_numbers_;

	this->setDefault();
	this->initalPins();
}

paraKeypad::~paraKeypad() {
	// TODO Auto-generated destructor stub
}


uint8_t paraKeypad::getKeyCode()
{
	uint8_t i=0;
	for(i=0; i<keyNumbers ; i++)
	{
#if KEY_PIN_INVERT
		if( digitalRead( *(keyPins+i) )== true)
#else
		if( digitalRead( *(keyPins+i) )== false)
#endif
		{
			if(keyCodes)return keyCodes[i];
			else 
				return i;
		}
	}
	return NO_KEY;
}


uint8_t paraKeypad::getKey()
{
	static uint8_t KeyState   = 0;        //按键状态,状态机使用.
	static uint8_t KeyPrev    = 0;        //保存上一次按键,防止出现乱码现象.
	static uint8_t KeyHoldDly = 0;        //按键连发时间
	static boolean bKeyBurst  = false;    //标志连发开始

	#ifdef KEY_DOUBLE_DETECT_ENABLE
	static uint8_t KeyDbleTmp;            //处理按键双击事件.
	static uint8_t KeyDbleDly = 0;        //按键双击间隔时间
	#endif


	uint8_t KeyPress  = NO_KEY;           //按键值
	uint8_t KeyReturn = NO_KEY;           //按键返回值

	KeyPress = getKeyCode();

	#ifdef KEY_DOUBLE_DETECT_ENABLE
	if(KeyDbleDly>0)
	{//处理双击按键的.
		KeyDbleDly --;
		if(KeyDbleDly ==0) KeyDbleTmp= NO_KEY;
	}
	#endif

	switch(KeyState)
	{
		//按键初始态00
		case 0:
			if( KeyPress !=NO_KEY )
			{
				KeyState = 1;
				KeyPrev  = KeyPress;
			}
			break;
		//按键确认态01
		case 1:
			if( KeyPress !=NO_KEY  )
			{
				//与上次按键不同,是乱码
				if(KeyPrev  != KeyPress)
				{
					KeyState  = 0;
				}
				else
				{
					//双击处理在按键按下之前.
					#ifdef KEY_DOUBLE_DETECT_ENABLE
					if(KeyPress == KeyDbleTmp)
					{
						KeyReturn   = KEY_PR_DB | KeyPress;
						KeyDbleTmp  = NO_KEY;
						KeyDbleDly  = 0;
						break;
					}
					#endif

					//以下为按键按下处理
					KeyState  = 2;
					KeyReturn = KEY_PR_DW | KeyPress;         //返回按键按下键值

					//保存上次按键按下的键,处理双击用.
					#ifdef KEY_DOUBLE_DETECT_ENABLE
					KeyDbleTmp  = KeyPress;
					KeyDbleDly  = KEY_DOUBLE_INTERVAL;
					#endif
				}
			}
			else
			{//按键抬起,是抖动,不响应按键
				KeyState = 0;
			}
			break;
		//按键连续态11
		case 2:
			if( KeyPress !=NO_KEY )
			{//这个地方也可以添加 (KeyPress == KEY_1) || (KeyPress == KEY_2)
			 //这样可以对产生连发的按键进行限制
				KeyHoldDly++;
				if( (bKeyBurst ==true) && (KeyHoldDly>keyBurstSpace) )
				{
					KeyHoldDly = 0;
					KeyReturn  = KEY_PR_BR | KeyPress;      //返回连发的值
					KeyPrev    = KeyPress;                  //记住上次的按键.
					break;
				}
				if(KeyHoldDly>keyBurstFirst)
				{
					bKeyBurst  = true;
					KeyHoldDly = 0;
					KeyReturn  = KEY_PR_HD | KeyPress;       //返回长按后的值
					break;
				}
			}
		//按键释放态10
		case 3:
			if(KeyPress == NO_KEY )
			{
				KeyState   = 0;
				KeyHoldDly = 0;
				bKeyBurst  = false;
				KeyReturn  = KEY_PR_UP | KeyPrev;              //返回按键抬起值
			}
			break;
		default :break;
	}


	return KeyReturn;
}


uint8_t paraKeypad::scanKey()
{
	static int32_t 	time_ms_prev=0;
	static int32_t  time_ms_curr=0;
	static int32_t  timepace_ms=0;

	time_ms_curr = millis();
	timepace_ms = time_ms_curr - time_ms_prev;


	if(timepace_ms> (keyScanTimeInterval-1) )
	{
		time_ms_prev  =  time_ms_curr;
		return getKey();

	}
	return NO_KEY;
}



#endif
