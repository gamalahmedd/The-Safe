#include "KEYPAD.h"

void KEYPAD_vInit(unsigned char portname)
{
	DIO_vSetPortDirection(portname, 0x0F);
	DIO_vConnectInternalPullUp(portname, PIN4, ENABLE);
	DIO_vConnectInternalPullUp(portname, PIN5, ENABLE);
	DIO_vConnectInternalPullUp(portname, PIN6, ENABLE);
	DIO_vConnectInternalPullUp(portname, PIN7, ENABLE);
}

unsigned char KEYPAD_u8Read(unsigned char portname)
{
	unsigned char arr[4][4] = { {'7','8','9','/'}, {'4','5','6','*'}, {'1','2','3','+'}, {'A', '0', '=', '-'} };
	char row, col;
	char return_val = NOTPRESSED;
	for(row = 0; row <= 3; row++)
	{
		DIO_vWriteLowNibble(portname, 0x0F);
		DIO_vWritePin(portname, row, 0);
		for(col = 0; col <= 3; col++)
		{
			if(DIO_u8ReadPin(portname, col + 4) == 0)
			{
				while(!DIO_u8ReadPin(portname, col + 4));
				return_val = arr[row][col];
				break;
			}
			else
			{
				
			}
		}
		if(return_val != NOTPRESSED)
		{
			break;
		}			
		else
		{
			
		}
	}
	return return_val;
}