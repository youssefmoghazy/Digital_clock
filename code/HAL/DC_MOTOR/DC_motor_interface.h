/***********************************************************/
/************** Name    : Youssef Moghazy ******************/
/************** Date    : 26/7/2023       ******************/
/************** SWC     : DC_motor        ******************/
/************** Version : 1.0             ******************/
/***********************************************************/

#ifndef HAL_DC_MOTOR_DC_MOTOR_INTERFACE_H_
#define HAL_DC_MOTOR_DC_MOTOR_INTERFACE_H_

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../lib/STD_TYPES/STD_TYPES.h"

#define DC_MOTOR1				1
#define DC_MOTOR2				2

#define DC_MOTOR_ROTATE_CW		1
#define DC_MOTOR_ROTATE_CCW		2

u8 DC_motor_u8Inti(u8 Motor);

u8 DC_motor_u8Move(u8 Motor,u8 Direction);

u8 DC_motor_u8Stop(u8 Motor);

#endif /* HAL_DC_MOTOR_DC_MOTOR_INTERFACE_H_ */
