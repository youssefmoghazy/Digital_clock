/********************************************************/
/************** Name : Youssef Moghazy ******************/
/************** Date : 1/8/2023        ******************/
/************** SWC  : ADC             ******************/
/************** Version : 1.0          ******************/
/********************************************************/
#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_
/**/
#define ADC_u8_ADMUX_REG		*((volatile u8 *)0x27)
#define ADC_u8_ADCSRA_REG		*((volatile u8 *)0x26)
#define ADC_u8_ADCH_REG			*((volatile u8 *)0x25)
#define ADC_u8_ADCL_REG			*((volatile u8 *)0x24)

#define ADC_u16_ADC_REG			*((volatile u16 *)0x24)

#define ADC_u8_SFIOR0_REG		*((volatile u8 *)0x50)

#define ADC_u8_ADMUX_REFS1		7
#define ADC_u8_ADMUX_REFS0		6
#define ADC_u8_ADMUX_ADLAR		5

#define ADC_u8_ADCSRA_ADEN		7
#define ADC_u8_ADCSRA_ADSC		6
#define ADC_u8_ADCSRA_ADATA		5
#define ADC_u8_ADCSRA_ADIF		4
#define ADC_u8_ADCSRA_ADIE		3
#define ADC_u8_ADCSRA_ADPS2		2
#define ADC_u8_ADCSRA_ADPS1		1
#define ADC_u8_ADCSRA_ADPS0		0

#define ADC_u8_CLEAR_ADMUX		0b11100000
#define ADC_u8_CHANNAL_NUM		32
#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
