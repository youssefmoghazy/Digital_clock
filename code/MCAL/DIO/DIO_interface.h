/********************************************************/
/************** Name : Youssef Moghazy ******************/
/************** Date : 21/3/2023       ******************/
/************** SWC  : DIO             ******************/
/************** Version : 1.0          ******************/
/********************************************************/
#include "../../lib/STD_TYPES/STD_TYPES.h"
#ifndef DIO_Interface_h
#define DIO_Interface_h

/*Macros for ports*/
#define DIO_u8_PORTA		0
#define DIO_u8_PORTB		1
#define DIO_u8_PORTC		2
#define DIO_u8_PORTD		3

/*Macros for PINS*/
#define DIO_u8_PIN0			0
#define DIO_u8_PIN1			1
#define DIO_u8_PIN2			2
#define DIO_u8_PIN3			3
#define DIO_u8_PIN4			4
#define DIO_u8_PIN5			5
#define DIO_u8_PIN6			6
#define DIO_u8_PIN7			7

/*Macros for Direction*/
#define DIO_u8_OUTPUT		1
#define DIO_u8_INPUT		0

/*Macros for pin value*/
#define DIO_u8_HIGH			1
#define DIO_u8_LOW			0
#define DIO_u8_CONDITION_IS_TRUE	1

void DIO_voidInit	      (void);
//typedef unsigned char u8;
u8 DIO_u8SetPinDirection  (u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinDirection );

u8 DIO_u8SetPinValue      (u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinValue );

u8 DIO_u8GetPinValue      (u8 Copy_u8PortId , u8 Copy_u8PinId , u8 * Copy_pu8ReturnPinValue);

u8 DIO_u8SetPortDirection (u8 Copy_u8PortId , u8 Copy_u8PortDirection);

u8 DIO_u8SetPortValue     (u8 Copy_u8PortId , u8 Copy_u8PortValue);

u8 DIO_u8GetPortValue     (u8 Copy_u8PortId , u8 * Copy_pu8ReturnPortValue);

#endif
