#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "DIO.h"
#include "MACROS.h"
#define NOTPRESSED 0xFF
/*
	Function Name        : KEYPAD_vInit
	Function Returns     : void
	Function Arguments   : unsigned char portname
	Function Description : Set the port direction to initialize keypad
*/
void KEYPAD_vInit(unsigned char portname);
/*
	Function Name        : KEY_u8Read
	Function Returns     : unsigned char
	Function Arguments   : void
	Function Description : Return the selected button value
*/
unsigned char KEYPAD_u8Read(unsigned char portname);

#endif