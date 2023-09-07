/********************************************************/
/************** Name : Youssef Moghazy ******************/
/************** Date : 28/7/2023       ******************/
/************** SWC  : EXTI            ******************/
/************** Version : 1.0          ******************/
/********************************************************/
#include "../../lib/STD_TYPES/STD_TYPES.h"
#include "../../lib/BIT_Math/BIT_MATH.h"

#ifndef EXTI_Interface_h
#define EXTI_Interface_h

#define EXTI_u8_INTI0				0
#define EXTI_u8_INTI1				1
#define EXTI_u8_INTI2				2

#define EXTI_u8_INTI_NUM			3

/*Macros for Edge source*/

#define EXTI_u8_RAISING_ADGE		0
#define EXTI_u8_FALLING_ADGE		1
#define EXTI_u8_ANY_LOGICAL_CHANGE	2
#define EXTI_u8_LOW_LEVEL			3

u8 EXTI_u8EXTIEnable(u8 copy_u8EXTIIndex, u8 copy_u8EdgeIndex);

u8 EXTI_u8EXTIDisable(u8 copy_u8EXTIIndex);

u8 EXTI_u8EXTISetCallBack(u8 copy_u8EXTIIndex,void(*copy_pf)(void));

#endif
