/***********************************************************/
/************** Name    : Youssef Moghazy ******************/
/************** Date    : 26/7/2023       ******************/
/************** SWC     : stepper_motor   ******************/
/************** Version : 1.0             ******************/
/***********************************************************/


#include "../../lib/STD_TYPES/STD_TYPES.h"
#include "../../lib/BIT_Math/BIT_MATH.h"
#include <util/delay.h>

/* MCAL */
#include "../../MCAL/DIO/DIO_interface.h"
/* HAL */
#include "stepper_motor_interface.h"
#include "stepper_motor_config.h"

void stepperMotor_VoidInti(void)
{
	DIO_u8SetPinDirection(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN1,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN2,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN3,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN4,DIO_u8_OUTPUT);
	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN1,DIO_u8_LOW);
	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN2,DIO_u8_LOW);
	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN3,DIO_u8_LOW);
	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN4,DIO_u8_LOW);
}
u8 stepperMotor_u8RotateBy(u8 degree,u8 direction)
{
    u8 Local_u8ErrorState = STD_TYPES_OK;
    u16 local_u16StepNum = (degree * 2048UL) / 360;;
    u16 local_u16IterationsNum = local_u16StepNum / 4;
    if (degree >= 0 && degree <= 360)
    {

        if(direction==ROTATE_CW)
        {
                for (u16 integration = 0; integration < local_u16IterationsNum; integration++)
                {
                	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN1,DIO_u8_LOW);
                	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN2,DIO_u8_HIGH);
                	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN3,DIO_u8_HIGH);
                	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN4,DIO_u8_HIGH);
                	_delay_ms(20);

        			DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN1,DIO_u8_HIGH);
                	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN2,DIO_u8_LOW);
                	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN3,DIO_u8_HIGH);
                	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN4,DIO_u8_HIGH);
             		_delay_ms(20);

                	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN1,DIO_u8_HIGH);
                	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN2,DIO_u8_HIGH);
                	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN3,DIO_u8_LOW);
                	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN4,DIO_u8_HIGH);
                	_delay_ms(20);

                	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN1,DIO_u8_HIGH);
                	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN2,DIO_u8_HIGH);
                	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN3,DIO_u8_HIGH);
                	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN4,DIO_u8_LOW);
                	_delay_ms(20);
                }
        }
        else if(direction== ROTATE_CCW)
        {
        	for (u16 integration = 0; integration < local_u16IterationsNum; integration++)
               {
                	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN1,DIO_u8_HIGH);
                	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN2,DIO_u8_HIGH);
                	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN3,DIO_u8_HIGH);
                	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN4,DIO_u8_LOW);
                	_delay_ms(20);

                	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN1,DIO_u8_HIGH);
                	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN2,DIO_u8_HIGH);
                	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN3,DIO_u8_LOW);
                	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN4,DIO_u8_HIGH);
                	_delay_ms(20);

                	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN1,DIO_u8_HIGH);
                	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN2,DIO_u8_LOW);
                	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN3,DIO_u8_HIGH);
                	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN4,DIO_u8_HIGH);
                	_delay_ms(20);


                	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN1,DIO_u8_LOW);
                	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN2,DIO_u8_HIGH);
                	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN3,DIO_u8_HIGH);
                	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_CONTROL_PIN4,DIO_u8_HIGH);
                	_delay_ms(20);
                }
        }
        else
        {
        	Local_u8ErrorState = STD_TYPES_NOK;

        }
    }
    else
    {
        Local_u8ErrorState = STD_TYPES_NOK;
    }
    return Local_u8ErrorState;
}




