#include "LCD.h"
#include "KEYPAD.h"
#include "EEPROM.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#define EEPROM_STATUS 0x20
#define EEPROM_LOCATION1 0x21
#define EEPROM_LOCATION2 0x22
#define EEPROM_LOCATION3 0x23
#define EEPROM_LOCATION4 0x24
#define MAX_TRIES 3

int main(void)
{
	LCD_vInit();
	KEYPAD_vInit('D');
	char arr[4] = {0xFF, 0xFF, 0xFF, 0xFF};
	unsigned char val = 0xFF;
	unsigned char flag = 0;
	int i;
	unsigned char tries = MAX_TRIES;
	if (EEPROM_vRead(EEPROM_STATUS) == 0xFF)
	{
		LCD_vSendString("SetPassword:");
		for(i = 0; i <= 3; i++)
		{
			do 
			{
				val = KEYPAD_u8Read('D');
			} while (val == NOTPRESSED);
			LCD_vSendChar(val);
			LCD_vSendCMD(SHIFT_AC_LEFT);
			_delay_ms(100);
			LCD_vSendChar('*');
			EEPROM_vWrite(EEPROM_LOCATION1 + i, val);
		}
		EEPROM_vWrite(EEPROM_STATUS, 0x00);
	}
	while(flag == 0)
	{
		LCD_vClearScreen();
		LCD_vSendString("EnterPassword:");
		for(i = 0; i <= 3; i++)
		{
			do 
			{
				arr[i] = KEYPAD_u8Read('D');
			} while (arr[i] == 0xFF);
			LCD_vSendChar(arr[i]);
			LCD_vSendCMD(SHIFT_AC_LEFT);
			_delay_ms(100);
			LCD_vSendChar('*');
		}
		if(EEPROM_vRead(EEPROM_LOCATION1) == arr[0] && EEPROM_vRead(EEPROM_LOCATION2) == arr[1] && EEPROM_vRead(EEPROM_LOCATION3) == arr[2] && EEPROM_vRead(EEPROM_LOCATION4) == arr[3])
		{
			LCD_vClearScreen();
			LCD_vSendString("Correct Password");
			LCD_vMoveCursor(2, 1);
			LCD_vSendString("Safe is opened");
			flag = 1;
		}
		else
		{
			tries--;
			if(tries == 0)
			{
				LCD_vClearScreen();
				LCD_vSendString("Tries are over");
				LCD_vMoveCursor(2, 1);
				LCD_vSendString("Safe is closed");
				flag = 1;
			}
			else
			{
				LCD_vClearScreen();
				LCD_vSendString("You have ");
				LCD_vSendChar(tries + 48);
				LCD_vSendString(" left");
				LCD_vMoveCursor(2, 1);
				LCD_vSendString("Try Again!");
				_delay_ms(2000);
			}
		}
	}
}