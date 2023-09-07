/********************************************************/
/************** Name : Youssef Moghazy ******************/
/************** Date : 1/8/2023        ******************/
/************** SWC  : ADC             ******************/
/************** Version : 1.0          ******************/
/********************************************************/
#include "../../lib/STD_TYPES/STD_TYPES.h"
#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_private.h"
static u8 ADC_u8BUSY_FLAG=0;
static void(*ADC_PFNotification)(u16)=NULL;
/****************************************************************************************************/
void ADC_voidInit(void)
{
	/* 1- select Vref = AVCC
	 * 2- Right adjust
	 * 3- Disable AutoTrigger
	 * 4- Select CLK/64 ->8 MHZ
	 * 5- Enable ADC
	 * */
	ADC_u8_ADMUX_REG&=~(STD_TYPES_TRUE<<ADC_u8_ADMUX_REFS1);
	ADC_u8_ADMUX_REG|=(STD_TYPES_TRUE<<ADC_u8_ADMUX_REFS0);

	ADC_u8_ADMUX_REG&=~(STD_TYPES_TRUE<<ADC_u8_ADMUX_ADLAR);

	ADC_u8_ADCSRA_REG&=~(STD_TYPES_TRUE<<ADC_u8_ADCSRA_ADATA);

	ADC_u8_ADCSRA_REG|=(STD_TYPES_TRUE<<ADC_u8_ADCSRA_ADPS2);
	ADC_u8_ADCSRA_REG|=(STD_TYPES_TRUE<<ADC_u8_ADCSRA_ADPS1);
	ADC_u8_ADCSRA_REG&=~(STD_TYPES_TRUE<<ADC_u8_ADCSRA_ADPS0);

	ADC_u8_ADCSRA_REG|=(STD_TYPES_TRUE<<ADC_u8_ADCSRA_ADEN);
}
/****************************************************************************************************/
u8 ADC_GetDigitalValueSynchNonBlocking(u8 copy_u8ChannelNum,u16* copy_pu16DigitalValue)
{
	u8 Local_u8ErrorState= STD_TYPES_OK;
	u32 Local_u32TimeOutCounter=0;
	if(copy_u8ChannelNum< ADC_u8_CHANNAL_NUM && copy_pu16DigitalValue!=NULL)
	{
		/*Clear MUX4....0*/
		ADC_u8_ADMUX_REG&=ADC_u8_CLEAR_ADMUX;
		/*Select channel */
		ADC_u8_ADMUX_REG|=copy_u8ChannelNum;
		/*Start conversion mode*/
		ADC_u8_ADCSRA_REG|=(STD_TYPES_TRUE<<ADC_u8_ADCSRA_ADSC);
		/*Wait flag =1*/
		while((!((ADC_u8_ADCSRA_REG>>ADC_u8_ADCSRA_ADIF)&STD_TYPES_TRUE))&&(Local_u32TimeOutCounter<ADC_u32_TIME_OUT_MAX_VALUE))
		{
			Local_u32TimeOutCounter++;
		}
		/*Check for flag change*/
		if((((ADC_u8_ADCSRA_REG>>ADC_u8_ADCSRA_ADIF)&STD_TYPES_TRUE)!=0))
		{
			/*Clear flag*/
			ADC_u8_ADCSRA_REG|=(STD_TYPES_TRUE<<ADC_u8_ADCSRA_ADIF);
			/*Read digital value */
			* copy_pu16DigitalValue=ADC_u16_ADC_REG;
		}
		else
		{
			Local_u8ErrorState=STD_TYPES_NOK;
		}
	}
	else
	{
		Local_u8ErrorState=STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}
/****************************************************************************************************/
u8 ADC_u8GetDigitalValueAsynch(u8 copy_u8ChannelNI,void(*copy_PFNotification)(u16))
{
	u8 Local_u8ErrorState= STD_TYPES_OK;

	if((copy_u8ChannelNI<ADC_u8_CHANNAL_NUM)&&(copy_PFNotification!=NULL)&&(ADC_u8BUSY_FLAG==0))
	{
		/*Set flag to make ADC is busy*/
		ADC_u8BUSY_FLAG=1;
		/* update Global Pointer to a function */
		ADC_PFNotification=copy_PFNotification;
		/*Enable ADC interrupt*/
		ADC_u8_ADCSRA_REG|=(STD_TYPES_TRUE<<ADC_u8_ADCSRA_ADIE);
		/*Clear MUX4....0*/
		ADC_u8_ADMUX_REG&=ADC_u8_CLEAR_ADMUX;
		/*Select channel */
		ADC_u8_ADMUX_REG|=copy_u8ChannelNI;
		/*Start conversion mode*/
		ADC_u8_ADCSRA_REG|=(STD_TYPES_TRUE<<ADC_u8_ADCSRA_ADSC);
	}
	else
	{
		Local_u8ErrorState=STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}
/****************************************************************************************************/
u8 ADC_u8_GetADCREGValue(u16*copy_pu16ADCValue)
{
	u8 Local_u8ErrorState= STD_TYPES_OK;
	if(copy_pu16ADCValue!=NULL)
	{
		/*Read ADC Register*/
		*copy_pu16ADCValue = ADC_u16_ADC_REG;
	}
	else
	{
		Local_u8ErrorState=STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}
/****************************************************************************************************/
/*Prototype for ADC ISR*/
void __vector_16(void)		__attribute__((signal));
void __vector_16(void)
{
	if(ADC_PFNotification!=NULL)
	{
		/*CLEAR FLAG*/
		ADC_u8BUSY_FLAG=0;
		/*Clear PIN of ADC*/
		ADC_u8_ADCSRA_REG&=~(STD_TYPES_TRUE<<ADC_u8_ADCSRA_ADIE);
		/*Call Notification function */
		ADC_PFNotification(ADC_u16_ADC_REG);
	}
}




