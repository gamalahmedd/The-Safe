#include "LCD.h"
#include "MACROS.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void LCD_vInit()
{
	_delay_ms(200);
	#if defined eight_bit_mode
	DIO_vSetPortDirection(LCD_PORT, 0xFF);
	DIO_vsetPinDir(CONTROL_PORT, EN, OUTPUT);
	DIO_vsetPinDir(CONTROL_PORT, RS, OUTPUT);
	DIO_vsetPinDir(CONTROL_PORT, RW, OUTPUT);
	DIO_vWritePin(CONTROL_PORT, RW, DISABLE);
	LCD_vSendCMD(EIGHT_BITS);
	_delay_ms(1);
	LCD_vSendCMD(DISPLAY_ON_CURSOR_ON);
	_delay_ms(1);
	LCD_vSendCMD(CLR_SCREEN);
	_delay_ms(10);
	LCD_vSendCMD(ENTRY_MODE);
	_delay_ms(1);
	
	#elif defined four_bit_mode
	DIO_vsetPinDir(LCD_PORT, PIN4, OUTPUT);
	DIO_vsetPinDir(LCD_PORT, PIN5, OUTPUT);
	DIO_vsetPinDir(LCD_PORT, PIN6, OUTPUT);
	DIO_vsetPinDir(LCD_PORT, PIN7, OUTPUT);
	DIO_vsetPinDir(CONTROL_PORT, EN, OUTPUT);
	DIO_vsetPinDir(CONTROL_PORT, RS, OUTPUT);
	DIO_vsetPinDir(CONTROL_PORT, RW, OUTPUT);
	DIO_vWritePin(CONTROL_PORT, RW, DISABLE);
	LCD_vSendCMD(RETURN_HOME);
	_delay_ms(10);
	LCD_vSendCMD(FOUR_BITS);
	_delay_ms(1);
	LCD_vSendCMD(DISPLAY_ON_CURSOR_ON);
	_delay_ms(1);
	LCD_vSendCMD(CLR_SCREEN);
	_delay_ms(10);
	LCD_vSendCMD(ENTRY_MODE);
	_delay_ms(1);
	#endif
}

static void LCD_vSendPulse(void)
{
	DIO_vWritePin(CONTROL_PORT, EN, ENABLE);
	_delay_ms(2);
	DIO_vWritePin(CONTROL_PORT, EN, DISABLE);
	_delay_ms(2);
}

void LCD_vSendCMD(unsigned char cmd)
{
	#if defined eight_bit_mode
	DIO_vWritePin(CONTROL_PORT, RS, DISABLE);
	DIO_vWritePort(LCD_PORT, cmd);
	LCD_vSendPulse();
	
	#elif defined four_bit_mode
	DIO_vWritePin(CONTROL_PORT, RS, DISABLE);
	DIO_vWriteHighNibble(LCD_PORT, cmd >> 4);
	LCD_vSendPulse();
	DIO_vWriteHighNibble(LCD_PORT, cmd);
	LCD_vSendPulse();
	#endif
	_delay_ms(1);
}

LCD_vSendChar(unsigned char data)
{
	#if defined eight_bit_mode
	DIO_vWritePin(CONTROL_PORT, RS, ENABLE);
	DIO_vWritePort(LCD_PORT, data);
	LCD_vSendPulse();
	
	#elif defined four_bit_mode
	DIO_vWritePin(CONTROL_PORT, RS, ENABLE);
	DIO_vWriteHighNibble(LCD_PORT, data >> 4);
	LCD_vSendPulse();
	DIO_vWriteHighNibble(LCD_PORT, data);
	LCD_vSendPulse();
	#endif
}

void LCD_vSendString(unsigned char *data)
{
	while((*data) != 0)
	{
		LCD_vSendChar(*data);
		data++;
	}
}

void LCD_vClearScreen()
{
	LCD_vSendCMD(CLR_SCREEN);
	_delay_ms(10);
}

void LCD_vMoveCursor(char row, char column)
{
	unsigned char data;
	if(row < 1 || row > 2 || column > 20 || column < 1)
	{
		data = 0x80;
	}
	else
	{
		if(row == 1)
		{
			data = 0x80 + column - 1;
		}
		else
		{
			data = 0xC0 + column - 1;
		}
		LCD_vSendCMD(data);
	}
}

void LCD_vSetCGRAMAddress(unsigned char address)
{
	if(address > 0x3F)
	{
		address = 0x80;
		LCD_vSendCMD(address);
	}
	else
	{
		SET_BIT(address, 6);
		CLR_BIT(address, 7);
		LCD_vSendCMD(address);
	}
}