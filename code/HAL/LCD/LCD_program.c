/********************************************************/
/************** Name : Youssef Moghazy ******************/
/************** Date : 21/3/2023       ******************/
/************** SWC  : LCD             ******************/
/************** Version : 1.0          ******************/
/********************************************************/


/********************************** Header Files INCLUSIONS ****************************/
/* Lib layer */
#include "../../lib/STD_TYPES/STD_TYPES.h"
#include "../../lib/BIT_Math/BIT_MATH.h"
#include <util/delay.h>
/*MCAL*/
#include "../../MCAL/DIO/DIO_interface.h" //to config pins

/*HAL*/
#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"
/***************************************************************************************/

/*
 -----------                   ----------
 | ATmega32  |                 |   LCD    |
 |           |                 |          |
 |        PD7|---------------->|D7        |
 |        PD6|---------------->|D6        |
 |        PD5|---------------->|D5        |
 |        PD4|---------------->|D4        |
 |        PD3|---------------->|D3        |
 |        PD2|---------------->|D2        |
 |        PD1|---------------->|D1        |
 |        PD0|---------------->|D0        |
 |           |                 |          |
 |        PA2|---------------->|E         |
 |        PA1|---------------->|RW        |
 |        PA0|---------------->|RS        |
 -----------                   ----------
 */



/***************************************************************************************/
/********************************** Fucntion Definition ********************************/
/***************************************************************************************/

/***************************************************************************************/
/* Description! Apply initialization sequence for LCD module                           */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_voidInit(void)   
{
	#if LCD_u8_MODE == LCD_u8_MODE_8_BIT
	/* Delay 30ms to ensure the initialization of the LCD driver */
	_delay_ms(35);

	/* Return Home  */
	LCD_voidSendCmnd(lcd_Home);
	_delay_ms(1);

	/* Function Set  */
	LCD_voidSendCmnd(lcd_FunctionSet8bit);
	_delay_ms(1);

	/* Display ON OFF Control */
	LCD_voidSendCmnd(lcd_DisplayOn);
	_delay_ms(1);

	/* Clear Display */
	LCD_voidSendCmnd(lcd_Clear);
	_delay_ms(1);

	/* Entry Mode Set  */
	LCD_voidSendCmnd(lcd_EntryMode);
	_delay_ms(2);

	#elif LCD_u8_MODE == LCD_u8_MODE_4_BIT
	/* Delay 30ms to ensure the initialization of the LCD driver */
	_delay_ms(35);

	/* Return Home  */
	LCD_voidSendCmnd(lcd_Home);
	_delay_ms(1);

	/* Function Set  */
	LCD_voidSendCmnd(lcd_FunctionSet4bit);
	_delay_ms(1);

	/* Display ON OFF Control */
	LCD_voidSendCmnd(lcd_DisplayOn);
	_delay_ms(1);

	/* Clear Display */
	LCD_voidSendCmnd(lcd_Clear);
	_delay_ms(1);

	/* Entry Mode Set  */
	LCD_voidSendCmnd(lcd_EntryMode);
	_delay_ms(2);
	#endif
}
/***************************************************************************************/
/* Description! Interface to send the configuration commands to the LCD Driver         */
/* Input      ! Command number                                                         */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_voidSendCmnd(u8 Copy_u8Cmnd)
{
    #if LCD_u8_MODE == LCD_u8_MODE_8_BIT

    /* Set RS to DIO_u8_LOW */
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_RS_PIN, DIO_u8_LOW);

    /* Set R/W to DIO_u8_LOW */
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_RW_PIN, DIO_u8_LOW);

    /* Load Command on Data bus */
    DIO_u8SetPortValue(LCD_u8_DATA_PORT, Copy_u8Cmnd);

    /* Set E to DIO_u8_HIGH  */
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_E_PIN, DIO_u8_HIGH);

    /* Wait for E to settle */
    _delay_ms(2);

    /* Set E to DIO_u8_LOW */
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_E_PIN, DIO_u8_LOW);

    #elif LCD_u8_MODE == LCD_u8_MODE_4_BIT

    /* Set RS to DIO_u8_LOW */
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_RS_PIN, DIO_u8_LOW);

    /* Set R/W to DIO_u8_LOW */
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_RW_PIN, DIO_u8_LOW);

    /* Load Command on Data bus */
    DIO_u8SetPortValue(LCD_u8_DATA_PORT, Copy_u8Cmnd);

    /* Set E to DIO_u8_HIGH  */
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_E_PIN, DIO_u8_HIGH);

    /* Wait for E to settle */
    _delay_ms(2);

    /* Set E to DIO_u8_LOW */
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_E_PIN, DIO_u8_LOW);

    /*write the rest of the command */
    DIO_u8SetPortValue(LCD_u8_DATA_PORT, Copy_u8Cmnd << 4);

    /* Set E to DIO_u8_HIGH  */
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_E_PIN, DIO_u8_HIGH);

    /* Wait for E to settle */
    _delay_ms(2);

    /* Set E to DIO_u8_LOW */
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_E_PIN, DIO_u8_LOW);
    #endif
}
/***************************************************************************************/
/* Description! Interface to write character on LCD screen                             */
/* Input      ! Data to send                                                           */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_voidSendChar(u8 Copy_u8Char)
{
	#if LCD_u8_MODE == LCD_u8_MODE_8_BIT
   /* Set RS to HIG */
   DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_RS_PIN, DIO_u8_HIGH);

   /* Set R/W to DIO_u8_LOW */
   DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_RW_PIN, DIO_u8_LOW);

   /* Set E to DIO_u8_HIGH */
   DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_E_PIN, DIO_u8_HIGH);

   /* Load Command on Data bus */
   DIO_u8SetPortValue(LCD_u8_DATA_PORT, Copy_u8Char);

   /* Set E to DIO_u8_LOW */
   DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_E_PIN, DIO_u8_LOW);

   /* Wait for E to settle */
   _delay_ms(2);

   /* Set E to DIO_u8_HIGH */
   DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_E_PIN, DIO_u8_HIGH);

   /* Delay to let the LCD Display the character */
   _delay_ms(2);

   #elif LCD_u8_MODE == LCD_u8_MODE_4_BIT
   /* Set RS to HIG */
   DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_RS_PIN, DIO_u8_HIGH);

   /* Set R/W to DIO_u8_LOW */
   DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_RW_PIN, DIO_u8_LOW);

   /* Set E to DIO_u8_HIGH */
   DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_E_PIN, DIO_u8_HIGH);

   /* Load Command on Data bus */
   DIO_u8SetPortValue(LCD_u8_DATA_PORT, Copy_u8Char);

   /* Set E to DIO_u8_LOW */
   DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_E_PIN, DIO_u8_LOW);

   /* Wait for E to settle */
   _delay_ms(2);

   /* Set E to DIO_u8_HIGH */
   DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_E_PIN, DIO_u8_HIGH);

   /*Load the rest of the command on Data bus */
   DIO_u8SetPortValue(LCD_u8_DATA_PORT, Copy_u8Char << 4);

   /* Set E to DIO_u8_LOW */
   DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_E_PIN, DIO_u8_LOW);

   /* Wait for E to settle */
   _delay_ms(2);

   /* Set E to DIO_u8_HIGH */
   DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_E_PIN, DIO_u8_HIGH);

   /* Delay to let the LCD Display the character */
   _delay_ms(2);

   #endif
}
/***************************************************************************************/
/* Description! Interface to go to specific position on LCD screen                     */
/* Input      ! Data to send                                                           */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
u8 LCD_u8GoToXY(u8 Copy_u8LineNum, u8 Copy_u8Location)
{
    u8 Local_u8ErrorState = STD_TYPES_OK; // Initialize with a default value.

    if (Copy_u8Location <= 39)
    {
        switch (Copy_u8LineNum)
        {
        case LCD_u8_Line1:
            LCD_voidSendCmnd(0x80 + Copy_u8Location);
            break;
        case LCD_u8_Line2:
            LCD_voidSendCmnd(0xc0 + Copy_u8Location);
            break;
        default:
            Local_u8ErrorState = STD_TYPES_NOK;
        }
    }
    else
    {
        Local_u8ErrorState = STD_TYPES_NOK;
    }

    return Local_u8ErrorState;
}

/***************************************************************************************/
/* Description! Interface to write string on LCD screen                                */
/* Input      ! Pointer to the string                                                  */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_voidSendString(const u8 *Copy_pu8String) {
    u8 iteration = 0;
    while (Copy_pu8String[iteration] != '\0') {
        /* Write Character on LCD */
        LCD_voidSendChar(Copy_pu8String[iteration]);
        iteration++;
    }
}
/***************************************************************************************/
/* Description! Interface to clear LCD screen		                                   */
/* Input      ! Nothing													               */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_voidClear(){
	LCD_voidSendCmnd(lcd_Clear);
	_delay_ms(2);
}
void LCD_Send_Number(u32 num)
{
	u8 arr[10], i = 0, j = 0;
    if (num == 0)
    {
    	LCD_voidSendChar('0');
    }
    else
    {
        while (num)
        {
            arr[i] = num % 10 + '0';
            num /= 10;
            i++;
        }
        for (j = i; j > 0; j--)
        {
        	LCD_voidSendChar(arr[j - 1]);
        }
    }
}
