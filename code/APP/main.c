//MCAL Layer
#include"../MCAL/DIO/DIO_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/Timer/Timer_interface.h"
//LIB Layer
#include"../lib/STD_TYPES/STD_TYPES.h"
#include<util/delay.h>
#define F_CPU 8000000UL
//HAL Layer
#include "../HAL/LCD/LCD_interface.h"
// Main function
typedef struct my_time{
	u8 sec;
	u8 min;
	u8 hour;
}Time;
typedef struct my_alarm{
	u8 sec;
	u8 min;
	u8 hour;
}Alarm;
int main(){
	Time time;
	time.hour=0;
	time.min=0;
	time.sec=0;
	Alarm alarm;
	alarm.hour=0;
	alarm.min=0;
	alarm.sec=10;
	u16 DigitalValue1=0,DigitalValue2=0,AnalogValue,AnalogValue2;
	u8 btn1,btn2;
	DIO_voidInit();
	ADC_voidInit();
	LCD_voidInit();
	while(1)
	{
		ADC_GetDigitalValueSynchNonBlocking(ADC_u8_CHANNAL_0, &DigitalValue1);
		AnalogValue = (DigitalValue1 * 5000UL) / 1024;
		/***************************************************************/
		ADC_GetDigitalValueSynchNonBlocking(ADC_u8_CHANNAL_1, &DigitalValue2);
		AnalogValue2 = (DigitalValue2 * 5000UL) / 1024;
		/***************************************************************/
		DIO_u8GetPinValue(DIO_u8_PORTA,DIO_u8_PIN3,&btn1);
		DIO_u8GetPinValue(DIO_u8_PORTA,DIO_u8_PIN4,&btn2);
		if(!btn1)
		{
			if(!btn2)
			{
				time.min = (AnalogValue*60UL)/4995;
				time.hour = (AnalogValue2 *23UL) / 4995;
			}
			else
			{
				alarm.min = (AnalogValue*60UL)/4995;
				alarm.hour = (AnalogValue2 *23UL) / 4995;
			}

		}

		/***************************************************************/
		LCD_u8GoToXY(LCD_u8_Line1,0);
		LCD_Send_Number(time.hour);
		LCD_voidSendChar(':');
		LCD_Send_Number(time.min);
		LCD_voidSendChar(':');
		LCD_Send_Number(time.sec);
		LCD_u8GoToXY(LCD_u8_Line2,0);
		LCD_voidSendString("ALARM ");
		LCD_Send_Number(alarm.hour);
		LCD_voidSendChar(':');
		LCD_Send_Number(alarm.min);
		u16 delay =1000;
		Timers_enudelayms(delay);
		LCD_voidClear();
		if(time.sec==59)
		{
			time.sec=0;
			if(time.min==59)
			{
				time.min=0;
				if(time.hour==23)
				{
					time.hour=0;
				}
				else
				{
					time.hour++;
				}
			}
			else
			{
				time.min++;
			}
		}
		else
		{
			time.sec++;
		}
		/**********************************************************************/
		if(time.hour==alarm.hour&&btn1)
		{
			if(time.min==alarm.min)
			{
				DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_HIGH);
			}
		}






	}

    return 0;
}
