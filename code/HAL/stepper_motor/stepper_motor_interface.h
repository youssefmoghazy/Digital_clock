/***********************************************************/
/************** Name    : Youssef Moghazy ******************/
/************** Date    : 26/7/2023       ******************/
/************** SWC     : stepper_motor   ******************/
/************** Version : 1.0             ******************/
/***********************************************************/
#ifndef HAL_STEPPER_MOTOR_STEPPER_MOTOR_INTERFACE_H_
#define HAL_STEPPER_MOTOR_STEPPER_MOTOR_INTERFACE_H_

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../lib/STD_TYPES/STD_TYPES.h"
#include <util/delay.h>

#define F_CPU 8000000UL

#define ROTATE_CW		1
#define ROTATE_CCW		2

void stepperMotor_VoidInti(void);
u8 stepperMotor_u8RotateBy(u8 degree,u8 direction);


#endif /* HAL_STEPPER_MOTOR_STEPPER_MOTOR_INTERFACE_H_ */
