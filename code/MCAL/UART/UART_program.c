/********************************************************/
/************** Name : Youssef Moghazy ******************/
/************** Date : 25/8/2023       ******************/
/************** SWC  : UART            ******************/
/************** Version : 1.0          ******************/
/********************************************************/
#include "UART_interface.h"
#include "UART_CONFIG.h"
#include "UART_private.h"

#include "../../lib/BIT_Math/BIT_MATH.h"
#include "../../lib/STD_TYPES/STD_TYPES.h"

// the initial the UART to work for boudrate 9600
void UART_voidinit(void)
{
	u16 Baud_Rate_value=51;
	u8 local_u8_UCSRC=0b10000000;
	//TO WORK NORAMAL SPEED
	CLR_BIT(UART_u8_UCSRA_REG,1);
	//TO work sync and disable the MPCM
	CLR_BIT(UART_u8_UCSRA_REG,0);
	// Receiver Enable
	SET_BIT(UART_u8_UCSRB_REG,4);
	//Transmitter Enable
	SET_BIT(UART_u8_UCSRB_REG,3);
	// TO WORK DATA frame 8 bit
	CLR_BIT(UART_u8_UCSRB_REG,2);
	SET_BIT(local_u8_UCSRC,2);
	SET_BIT(local_u8_UCSRC,1);
	//to work Asynchronous operation
	CLR_BIT(local_u8_UCSRC,6);
	// TO WORK NOT parity bit mode
	CLR_BIT(local_u8_UCSRC,5);
	CLR_BIT(local_u8_UCSRC,4);
	//Stop Bit Select TOW (2) BIT MODE
	SET_BIT(local_u8_UCSRC,3);
    //update the value of register ucsrc
	UART_u8_UCSRC_REG=local_u8_UCSRC;
    //Baud Rate Registers UBRRL and UBRRH to select 9600 t0 write 51
	UART_u8_UBRRL_REG=(u8)Baud_Rate_value;
	UART_u8_UBRRH_REG=(u8)(Baud_Rate_value>>8);
}
// the  function to sent dATA
void UART_void_sent_databyte(u8 data_sent )
{
	// cheek the buffer translation no busy END empty flag ==0
    while(GET_BIT(UART_u8_UCSRA_REG,5)==0);
	// sent data
    UART_u8_UDR_REG=data_sent;


}
//FUNCATION TO RECIVE DATA
u8 UART_void_resive_databyte(u8 *copy_pu8recive )
{
	u8 local_error_state=STD_TYPES_OK;
	if(copy_pu8recive!=NULL)
	{ // wAIT THE DATA IS resived finished
	  while(GET_BIT(UART_u8_UCSRA_REG,7)==0);
	  //read data from register to variable pointer
	  *copy_pu8recive=UART_u8_UDR_REG;
	}
    else {
		local_error_state=STD_TYPES_NOK;
	}

     return local_error_state;

}






