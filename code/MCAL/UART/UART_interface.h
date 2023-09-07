/********************************************************/
/************** Name : Youssef Moghazy ******************/
/************** Date : 25/8/2023       ******************/
/************** SWC  : UART            ******************/
/************** Version : 1.0          ******************/
/********************************************************/

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

#include "../../lib/STD_TYPES/STD_TYPES.h"
// the initial the UART to work for boudrate 9800
void UART_voidinit(void);
// the  function to sent dATA
void UART_void_sent_databyte(u8 data_sent );
//FUNCATION TO RECIVE DATA
u8 UART_void_resive_databyte(u8 *copy_pu8recive );

#endif /* MCAL_UART_UART_INTERFACE_H_ */
