/****************************************************************/
/***************  Name   : Youssef Moghazy **********************/
/***************  Date   : 21/3/2023       **********************/
/***************  SWC    : LCD      	   **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

#define LCD_u8_MODE_8_BIT			0
#define LCD_u8_MODE_4_BIT			1
#define lcd_Clear           		 0x01          // replace all characters with ASCII 'space'
#define lcd_Home           			 0x02          // return cursor to first position on first line
#define lcd_EntryMode       	     0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOff     			 0x08          // turn display off
#define lcd_DisplayOn      			 0x0F          // display on, cursor off, don't blink character
#define lcd_FunctionReset   		 0x30          // reset the LCD
#define lcd_FunctionSet8bit 		 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_FunctionSet4bit 		 0x2F          // 4-bit data, 2-line display, 5 x 7 font
#define lcd_u8SetCursor     		 0x80          // set cursor position

#endif /* LCD_PRIVATE_H_ */