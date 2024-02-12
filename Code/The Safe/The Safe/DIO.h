#ifndef DIO_H_
#define DIO_H_
/*
	Function Name        : DIO_vsetPINDir
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char pinnumber,unsigned char direction
	Function Description : Set the direction of the given pin in the given port (direction 0 = input : 1 = output)
*/
void DIO_vsetPinDir(unsigned char portname, unsigned char pinnumber, unsigned char direction);
/*
	Function Name		 : DIO_vWritePin
	Function Returns	 : void
	Function Arguments	 : unsigned char portname,unsigned char pinnumber,unsigned char output value
	Function Description : Set the value of the given pin in the given port (outputvalue 0 = low : 1 = high) 
*/
void DIO_vWritePin(unsigned char portname, unsigned char pinnumber, unsigned char output_value);
/*
	Function Name        : DIO_vTogglePin
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : Reverse the value of the given pin in the given port.
*/
void DIO_vTogglePin(unsigned char portname, unsigned char pinnumber);
/*
	Function Name        : DIO_u8ReadPin
	Function Returns     : unsigned char
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : Returns 1 if the value of the given pin is high and zero if the value is low
*/
unsigned char DIO_u8ReadPin(unsigned char portname, unsigned char pinnumber);
/*
	Function Name        : DIO_vSetPortDirection
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char direction
	Function Description : set the direction of whole port .
*/
void DIO_vSetPortDirection(unsigned char portname, unsigned char direction);
/*
	Function Name        : DIO_uWritePort
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char portvalue
	Function Description : Write the value to all port pins.
*/
void DIO_vWritePort(unsigned char portname, unsigned char portvalue);
/*
	Function Name        : DIO_uReadPort
	Function Returns     : unsigned char
	Function Arguments   : unsigned char portname
	Function Description : read the value of the port .
*/
unsigned char DIO_u8ReadPort(unsigned char portname);
/*
	Function Name        : DIO_uTogglePort
	Function Returns     : void
	Function Arguments   : unsigned char portname
	Function Description : toggle all bits of port.
*/
void DIO_vTogglePort(unsigned char portname);
/*
	Function Name        : DIO_vConnectInternalPullUp
	Function Returns     : void
	Function Arguments   : unsigned char portname, unsigned char pinnumber, unsigned char enable
	Function Description : control internal pull up of given pin.
*/
void DIO_vConnectInternalPullUp(unsigned char portname, unsigned char pinnumber, unsigned char enable);
/*
	Function Name        : DIO_vWriteLowNibble
	Function Returns     : void
	Function Arguments   : unsigned char portname, unsigned char number
	Function Description : write a given number in the lowest 4 four bits in the given port
*/
void DIO_vWriteLowNibble(unsigned char portname, unsigned char nibblevalue);
/*
	Function Name        : DIO_vWriteHighNibble
	Function Returns     : void
	Function Arguments   : unsigned char portname, unsigned char number
	Function Description : write a given number in the highest 4 four bits in the given port
*/
void DIO_vWriteHighNibble(unsigned char portname, unsigned char nibblevalue);
#endif