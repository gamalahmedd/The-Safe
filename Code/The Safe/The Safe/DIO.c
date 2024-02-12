#include "MACROS.h"
#include <avr/io.h>

void DIO_vsetPinDir(unsigned char portname, unsigned char pinnumber, unsigned char direction)
{
	switch(portname)
	{
		case 'A':
		case 'a':
			if(direction == 1)
			{
				SET_BIT(DDRA, pinnumber);
			}
			else
			{
				CLR_BIT(DDRA, pinnumber);
			}
			break;
		case 'B':
		case 'b':
			if(direction == 1)
			{
				SET_BIT(DDRB, pinnumber);
			}
			else 
			{
				CLR_BIT(DDRB, pinnumber);
			}
			break;
		case 'C':
		case 'c':
			if(direction == 1)
			{
				SET_BIT(DDRC, pinnumber);
			}
			else
			{
				CLR_BIT(DDRC, pinnumber);
			}
			break;
		case 'D':
		case 'd':
			if(direction == 1)
			{
				SET_BIT(DDRD, pinnumber);
			}
			else
			{
				CLR_BIT(DDRD, pinnumber);
			}
			break;
		default:
			break;
	}
}

void DIO_vWritePin(unsigned char portname, unsigned char pinnumber, unsigned char output_value)
{
	switch(portname)
	{
		case 'A':
		case 'a':
			if(output_value == 1)
			{
				SET_BIT(PORTA, pinnumber);
			}
			else
			{
				CLR_BIT(PORTA, pinnumber);
			}
			break;
		case 'B':
		case 'b':
			if(output_value == 1)
			{
				SET_BIT(PORTB, pinnumber);
			}
			else
			{
				CLR_BIT(PORTB, pinnumber);
			}
			break;
		case 'C':
		case 'c':
			if(output_value == 1)
			{
				SET_BIT(PORTC, pinnumber);
			}
			else
			{
				CLR_BIT(PORTC, pinnumber);
			}	
			break;
		case 'D':
		case 'd':
			if(output_value == 1)
			{
				SET_BIT(PORTD, pinnumber);
			}			
			else
			{
				CLR_BIT(PORTD, pinnumber);
			}
			break;
		default:
			break;
	}
}

void DIO_vTogglePin(unsigned char portname, unsigned char pinnumber)
{
	switch(portname)
	{
		case 'A':
		case 'a':
			TOG_BIT(PORTA, pinnumber);
			break;
		case 'B':
		case 'b':
			TOG_BIT(PORTB, pinnumber);
			break;
		case 'C':
		case 'c':
			TOG_BIT(PORTC, pinnumber);
			break;
		case 'D':
		case 'd':
			TOG_BIT(PORTD, pinnumber);
			break;
		default:
			break;
	}
}

unsigned char DIO_u8ReadPin(unsigned char portname, unsigned char pinnumber)
{
	unsigned char return_value = 0;
	switch(portname)
	{
		case 'A':
		case 'a':
			return_value = READ_BIT(PINA, pinnumber);
			break;
		case 'B':
		case 'b':
			return_value = READ_BIT(PINB, pinnumber);
			break;
		case 'C':
		case 'c':
			return_value = READ_BIT(PINC, pinnumber);
			break;
		case 'D':
		case 'd':
			return_value = READ_BIT(PIND, pinnumber);
			break;
		default:
			break;
	}
	return return_value;
}

void DIO_vSetPortDirection(unsigned char portname, unsigned char direction)
{
	switch(portname)
	{
		case 'A':
		case 'a':
			DDRA = direction;
			break;
		case 'B':
		case 'b':
			DDRB = direction;
			break;
		case 'C':
		case 'c':
			DDRC = direction;
			break;
		case 'D':
		case 'd':
			DDRD = direction;
			break;
		default:
			break;
	}
}

void DIO_vWritePort(unsigned char portname, unsigned char portvalue)
{
	switch(portname)
	{
		case 'A':
		case 'a':
			PORTA = portvalue;
			break;
		case 'B':
		case 'b':
			PORTB = portvalue;
			break;
		case 'C':
		case 'c':
			PORTC = portvalue;
			break;
		case 'D':
		case 'd':
			PORTD = portvalue;
			break;
		default:
			break;
	}
}

unsigned char DIO_u8ReadPort(unsigned char portname)
{
	unsigned char return_value = 0;
	switch(portname)
	{
		case 'A':
		case 'a':
			return_value = PINA;
			break;
		case 'B':
		case 'b':
			return_value = PINB;
			break;
		case 'C':
		case 'c':
			return_value = PINC;
			break;
		case 'D':
		case 'd':
			return_value = PIND;
			break;
		default:
			break;
	}
	return return_value;
}

void DIO_vTogglePort(unsigned char portname)
{
	switch (portname)
	{
		case 'A':
		case 'a':
			PORTA = ~PORTA;
			break;
		case 'B':
		case 'b':
			PORTB = ~PORTB;
			break;
		case 'C':
		case 'c':
			PORTC = ~PORTC;
			break;
		case 'D':
		case 'd':
			PORTD = ~PORTD;
			break;
		default:
			break;
	}
}

void DIO_vConnectInternalPullUp(unsigned char portname, unsigned char pinnumber, unsigned char enable)
{
	switch(portname)
	{
		case 'A':
		case 'a':
			if(enable == 1)
			{
				SET_BIT(PORTA, pinnumber);
			}
			else
			{
				CLR_BIT(PORTA, pinnumber);
			}
			break;
		case 'B':
		case 'b':
			if(enable == 1)
			{
				SET_BIT(PORTB, pinnumber);
			}
			else
			{
				CLR_BIT(PORTB, pinnumber);
			}
			break;
		case 'C':
		case 'c':
			if(enable == 1)
			{
				SET_BIT(PORTC, pinnumber);
			}
			else
			{
				CLR_BIT(PORTC, pinnumber);
			}
			break;
		case 'D':
		case 'd':
			if(enable == 1)
			{
				SET_BIT(PORTD, pinnumber);
			}
			else
			{
				CLR_BIT(PORTD, pinnumber);
			}
			break;
		default:
			break;
	}
	
}

void DIO_vWriteLowNibble(unsigned char portname, unsigned char nibblevalue)
{
	nibblevalue &= 0x0F;
	switch(portname)
	{
		case 'A':
		case 'a':
			PORTA &= 0xF0;
			PORTA |= nibblevalue;
			break;
		case 'B':
		case 'b':
			PORTB &= 0xF0;
			PORTB |= nibblevalue;
			break;
		case 'C':
		case 'c':
			PORTC &= 0xF0;
			PORTC |= nibblevalue;
			break;
		case 'D':
		case 'd':
			PORTD &= 0xF0;
			PORTD |= nibblevalue;
			break;
		default:
			break;
	}
}

void DIO_vWriteHighNibble(unsigned char portname, unsigned char nibblevalue)
{
	nibblevalue <<= 4;
	switch(portname)
	{
		case 'A':
		case 'a':
		PORTA &= 0x0F;
		PORTA |= nibblevalue;
		break;
		case 'B':
		case 'b':
		PORTB &= 0x0F;
		PORTB |= nibblevalue;
		break;
		case 'C':
		case 'c':
		PORTC &= 0x0F;
		PORTC |= nibblevalue;
		break;
		case 'D':
		case 'd':
		PORTD &= 0x0F;
		PORTD |= nibblevalue;
		break;
		default:
		break;
	}
}