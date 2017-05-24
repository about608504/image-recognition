#ifndef _FRAMESTRUCT_H
#define _FRAMESTRUCT_H
#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"	 
#include "usmart.h"	
#include "driver.h"
#include "FrameStruct.h"
typedef struct{
	u8 par;
/*|1 0 1 _|_ _ _ 1|*/
//bit1: DIR		0->CW | 1->CCW;
//bit2: AXC		0->X  | 1->Y;
//bit[3:4]: SPD 00->100Hz | 01->200Hz | 10->350Hz | 11->500Hz;

	u8 step;
}Frame;



#endif
