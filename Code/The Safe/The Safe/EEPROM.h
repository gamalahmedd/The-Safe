#ifndef EEPROM_H_
#define EEPROM_H_
/*
	Function Name        : EEPROM_vWrite
	Function Returns     : void
	Function Arguments   : unsigned short address, unsigned char data
	Function Description : it's to write in a specific location with the given address and store the given data
*/
void EEPROM_vWrite(unsigned short address, unsigned char data);
/*
	Function Name        : EEPROM_vRead
	Function Returns     : void
	Function Arguments   : unsigned short address
	Function Description : it's to read from a specific location with the given address
*/
unsigned char EEPROM_vRead(unsigned short address);

#endif