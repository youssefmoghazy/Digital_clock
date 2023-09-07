/***********************************************************/
/************** Name    : Youssef Moghazy ******************/
/************** Date    : 26/7/2023       ******************/
/************** SWC     : DC_motor        ******************/
/************** Version : 1.0             ******************/
/***********************************************************/
#include "DC_motor_config.h"
#include "DC_motor_interface.h"

u8 DC_motor_u8Inti(u8 Motor)
{
    u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Motor == DC_MOTOR1)
	{
		DIO_u8SetPinDirection(DC_MOTOR_PORT,DC_MOTOR_CONTROL_PIN2,DIO_u8_OUTPUT);
		DIO_u8SetPinDirection(DC_MOTOR_PORT,DC_MOTOR_CONTROL_PIN1,DIO_u8_OUTPUT);
	}
	else if(Motor==DC_MOTOR2)
	{
		DIO_u8SetPinDirection(DC_MOTOR_PORT,DC_MOTOR_CONTROL_PIN3,DIO_u8_OUTPUT);
		DIO_u8SetPinDirection(DC_MOTOR_PORT,DC_MOTOR_CONTROL_PIN4,DIO_u8_OUTPUT);
	}
	else
	{
		Local_u8ErrorState=STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8 DC_motor_u8Move(u8 Motor, u8 Direction)
{
    u8 Local_u8ErrorState = STD_TYPES_OK;

    if (Direction == DC_MOTOR_ROTATE_CW )
    {
        if (Motor == DC_MOTOR1){
        	DIO_u8SetPinValue(DC_MOTOR_PORT, DC_MOTOR_CONTROL_PIN1, DIO_u8_HIGH);
        	DIO_u8SetPinValue(DC_MOTOR_PORT, DC_MOTOR_CONTROL_PIN2, DIO_u8_LOW);
        }
        else if (Motor == DC_MOTOR2){
        	DIO_u8SetPinValue(DC_MOTOR_PORT, DC_MOTOR_CONTROL_PIN3, DIO_u8_HIGH);
        	DIO_u8SetPinValue(DC_MOTOR_PORT, DC_MOTOR_CONTROL_PIN4, DIO_u8_LOW);
        }
        else{
            Local_u8ErrorState = STD_TYPES_NOK;
        }
    }
    else if (Direction == DC_MOTOR_ROTATE_CCW)
    {
        if (Motor == DC_MOTOR1)
        {
        	DIO_u8SetPinValue(DC_MOTOR_PORT, DC_MOTOR_CONTROL_PIN1, DIO_u8_LOW);
        	DIO_u8SetPinValue(DC_MOTOR_PORT, DC_MOTOR_CONTROL_PIN2, DIO_u8_HIGH);
        }
        else if (Motor == DC_MOTOR2)
        {
        	DIO_u8SetPinValue(DC_MOTOR_PORT, DC_MOTOR_CONTROL_PIN3, DIO_u8_LOW);
        	DIO_u8SetPinValue(DC_MOTOR_PORT, DC_MOTOR_CONTROL_PIN4, DIO_u8_HIGH);
        }
        else
            Local_u8ErrorState = STD_TYPES_NOK;
    }else
        Local_u8ErrorState = STD_TYPES_NOK;

    return Local_u8ErrorState;
}


u8 DC_motor_u8Stop(u8 Motor)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if (Motor==DC_MOTOR1)
	{
		DIO_u8SetPinValue(DC_MOTOR_PORT,DC_MOTOR_CONTROL_PIN1,DIO_u8_LOW);
		DIO_u8SetPinValue(DC_MOTOR_PORT,DC_MOTOR_CONTROL_PIN2,DIO_u8_LOW);
	}
	else if (Motor==DC_MOTOR2)
	{
		DIO_u8SetPinValue(DC_MOTOR_PORT,DC_MOTOR_CONTROL_PIN3,DIO_u8_LOW);
		DIO_u8SetPinValue(DC_MOTOR_PORT,DC_MOTOR_CONTROL_PIN4,DIO_u8_LOW);
	}
	else
	{
		Local_u8ErrorState=STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}
