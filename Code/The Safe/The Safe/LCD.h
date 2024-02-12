#ifndef LCD_H_
#define LCD_H_
#include "DIO.h"
#include "LCD_Config.h"
/*
	Function Name        : LCD_vInit
	Function Returns     : void
	Function Arguments   : void
	Function Description : Initialize LCD 8-bit Mode or 4-Bit Mode
*/
void LCD_vInit(void);
/*
	Function Name        : LCD_vSendPulse
	Function Returns     : void
	Function Arguments   : void
	Function Description : Send pulse to enable bit with 2 ms width
*/
static void LCD_vSendPulse(void);
/*
	Function Name        : LCD_vSendCMD
	Function Returns     : void
	Function Arguments   : unsigned char cmd
	Function Description : Send a cmd to data lines in LCD to execute it with control unit
*/
void LCD_vSendCMD(unsigned char cmd);
/*
	Function Name        : LCD_vSendChar
	Function Returns     : void
	Function Arguments   : unsigned char data
	Function Description : Send a one letter to data lines in LCD to show it in screen
*/
void LCD_vSendChar(unsigned char data);
/*
	Function Name        : LCD_vSendString
	Function Returns     : void
	Function Arguments   : unsigned char *data
	Function Description : Send a string to data lines in LCD to show it in screen
*/
void LCD_vSendString(unsigned char *data);
/*
	Function Name        : LCD_vClearScreen
	Function Returns     : void
	Function Arguments   : void
	Function Description : Send clear screen command to LCD to clear the screen
*/
void LCD_vClearScreen(void);
/*
	Function Name        : LCD_vMoveCursor
	Function Returns     : void
	Function Arguments   : char row, char column
	Function Description : Move cursor of LCD to the position you want
*/
void LCD_vMoveCursor(char row, char column);
/*
	Function Name        : LCD_vSetCGRAMAddress
	Function Returns     : void
	Function Arguments   : unsigned char address
	Function Description : Set the cursor to CGRAM location
*/
void LCD_vSetCGRAMAddress(unsigned char address);
#endif