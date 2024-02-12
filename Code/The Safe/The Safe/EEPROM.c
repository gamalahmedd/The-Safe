#include "MACROS.h"
#include <avr/io.h>

void EEPROM_vWrite(unsigned short address, unsigned char data)
{
	// Put the given address in the EEPROM Address Register
	EEAR = address;
	// Put the given data in the EEPROM Data Register
	EEDR = data;
	//Enable EEPROM Master Write Enable pin in EECR
	SET_BIT(EECR, EEMWE);
	//Enable EEPROM Write Enable pin in EECR
	SET_BIT(EECR, EEWE);
	//Checking if EEPROM Write Enable pin returned to 0
	while(READ_BIT(EECR, EEWE));
}

unsigned char EEPROM_vRead(unsigned short address)
{
	//Put the given address in the EEPROM Address Register
	EEAR = address;
	//Enable EEPROM Read Enable pin in EECR
	SET_BIT(EECR, EERE);
	//Return the data from EEPROM Data Register
	return EEDR;
}