/********************************************************/
/************** Name : Youssef Moghazy ******************/
/************** Date : 1/8/2023        ******************/
/************** SWC  : ADC             ******************/
/************** Version : 1.0          ******************/
/********************************************************/

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

#define ADC_u8_CHANNAL_0		0
#define ADC_u8_CHANNAL_1		1
#define ADC_u8_CHANNAL_2		2
#define ADC_u8_CHANNAL_3		3
#define ADC_u8_CHANNAL_4		4
#define ADC_u8_CHANNAL_5		5
#define ADC_u8_CHANNAL_6		6
#define ADC_u8_CHANNAL_7		7


void ADC_voidInit(void);

u8 ADC_GetDigitalValueSynchNonBlocking(u8 copy_u8ChannelNum,u16* copy_pu16DigitalValue);

u8 ADC_u8GetDigitalValueAsynch(u8 copy_u8ChannelNI,void(*copy_PFNotification)(u16));

u8 ADC_u8_GetADCREGValue(u16*copy_pu16ADCValue);

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
