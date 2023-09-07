/********************************************************/
/************** Name : Youssef Moghazy ******************/
/************** Date : 27/4/2023       ******************/
/************** SWC  : LCD             ******************/
/************** Version : 1.0          ******************/
/********************************************************/
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H
/***************************************************************************************/
/********************************** Macros Definition **********************************/
/***************************************************************************************/
#define LCD_u8_Line1			1
#define LCD_u8_Line2			2
#define LCD_u8_ShiftToRight		0b00011100
#define LCD_u8_ShiftToLeft		0b00011000
#define LCD_u8_FirstPostion		 0
#define LCD_u8_LastPostion		 15
/***************************************************************************************/
/********************************** Function Definition ********************************/
/***************************************************************************************/


/***************************************************************************************/
/* Description! Apply initialisation sequence for LCD module                           */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_voidInit(void);
/***************************************************************************************/
/* Description! Interface to send the configuration commands to the LCD Driver         */
/* Input      ! Command number                                                         */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_voidSendCmnd(u8 Copy_u8Cmnd);
/***************************************************************************************/
/* Description! Interface to write character on LCD screen                             */
/* Input      ! Data to send                                                           */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_voidSendChar(u8 Copy_u8Char);
/***************************************************************************************/
/* Description! Interface to go to specific position on LCD screen                     */
/* Input      ! Data to send                                                           */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
u8 LCD_u8GoToXY(u8 Copy_u8LineNum , u8 Copy_u8Location);
/***************************************************************************************/
/* Description! Interface to write string on LCD screen                                */
/* Input      ! Pointer to the string                                                  */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_voidSendString(const u8 *Copy_pu8String);
/***************************************************************************************/
/* Description! Interface to clear LCD screen		                                   */
/* Input      ! Nothing													               */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_voidClear(void);

void LCD_Send_Number(u32 num);
#endif

