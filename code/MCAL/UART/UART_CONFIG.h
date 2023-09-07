/********************************************************/
/************** Name : Youssef Moghazy ******************/
/************** Date : 25/8/2023       ******************/
/************** SWC  : UART            ******************/
/************** Version : 1.0          ******************/
/********************************************************/
#ifndef MCAL_UART_UART_CONFIG_H_
#define MCAL_UART_UART_CONFIG_H_

#define UART_u8_UDR_REG           *((volatile u8*)0x2c)
#define UART_u8_UCSRA_REG         *((volatile u8*)0x2B)
#define UART_u8_UCSRB_REG         *((volatile u8*)0x2A)
#define UART_u8_UCSRC_REG         *((volatile u8*)0x40)

#define UART_u8_UBRRH_REG         *((volatile u8*)0x40)
#define UART_u8_UBRRL_REG         *((volatile u8*)0x29 )

#endif /* MCAL_UART_UART_CONFIG_H_ */
