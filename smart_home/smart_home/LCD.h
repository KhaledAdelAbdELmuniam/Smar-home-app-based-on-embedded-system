/*
 * LCD.h
 *
 * Created: 18-Oct-20 8:10:18 PM
 *  Author: Khaled
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "DIO_confg.h"
#define F_CPU 16000000UL
#include <util/delay.h>
#define LCD_RS DIO_channelB1
#define LCD_RW DIO_channelB2
#define LCD_E DIO_channelB3

#define LCD_DATAPORTS DIO_portA
#define LCD_CMDPORT DIO_portB

#define LCD_DATAREG PORTA_Reg
#define LCD_CMDREG PORTB_Reg
void LCD_init();
void LCD_CMD(uint8 cmd);
void LCD_char(char DATA);
void LCD_String(char * string);
void LCD_startpos(uint8 line, uint8 position);
void DIOWritePort(DIO_PORT_types PORTID, uint8 data);




#endif /* LCD_H_ */