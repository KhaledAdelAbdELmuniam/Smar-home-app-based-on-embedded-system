/*
 * LCD.c
 *
 * Created: 18-Oct-20 8:04:07 PM
 *  Author: Khaled
 */ 
#include "LCD.h"
void LCD_init(void){
	DIO_write(LCD_RW,std_low);
	_delay_ms(20);
	LCD_CMD(0x33);
	_delay_ms(2);
	LCD_CMD(0x32);
	LCD_CMD(0x28);//set function
	LCD_CMD(0x06);//entry mode
	LCD_CMD(0x0C);//Display on
	LCD_CMD(0x01);//Clear LCD
	_delay_ms(2);
	
	
}
void LCD_CMD(uint8 cmd){
	uint8 sendcmd;
	//send 3 (High nipple)
	 
sendcmd=(LCD_DATAREG & 0x0f)|(cmd &0xf0);
DIOWritePort(LCD_DATAPORTS, sendcmd);
	DIO_write(LCD_RS,std_low);
	DIO_write(LCD_E,std_high);
    _delay_us(50);
	DIO_write(LCD_E,std_low);
	//delay 
	_delay_ms(5);
	//send 3  (Low nipple)
	sendcmd=(LCD_DATAREG & 0x0f)|(cmd <<4);
	DIOWritePort(LCD_DATAPORTS, sendcmd);
	DIO_write(LCD_RS,std_low);
	DIO_write(LCD_E,std_high);
	_delay_ms(2);
	DIO_write(LCD_E,std_low);
	_delay_ms(2);
}
void LCD_char(char DATA) {
	char senddata;
	//send 3 (High nipple)
	senddata=(LCD_DATAREG & 0x0f)|(DATA &0xf0);
	DIOWritePort(LCD_DATAPORTS , senddata);
	DIO_write(LCD_RS,std_high);
	DIO_write(LCD_E,std_high);
	_delay_us(50);
	DIO_write(LCD_E,std_low);
	//delay
	_delay_ms(2);
	//send 3  (Low nipple)
	senddata=(LCD_DATAREG & 0x0f)|(DATA <<4);
	DIOWritePort(LCD_DATAPORTS , senddata);
	DIO_write(LCD_RS,std_high);
	DIO_write(LCD_E,std_high);
	_delay_us(50);
	DIO_write(LCD_E,std_low);
	_delay_ms(2);
}
void DIOWritePort(DIO_PORT_types PORTID, uint8 data){
	switch(PORTID){
		case DIO_portA:
		PORTA_Reg=data;
		break;
		
		case DIO_portB:
		PORTB_Reg=data;
		break;
		
		case DIO_portC:
		PORTC_Reg=data;
		break;
		
		case DIO_portD:
		PORTD_Reg=data;
		break;
		
	}
}
void LCD_String(char * string) {
	uint8 count=0;
	while(string[count] != '\0'){
		LCD_char(string[count]);
		count++;
	}
}
void LCD_startpos(uint8 line, uint8 position){
	uint8 SendCmd;
	switch(line){
		case 1:
		SendCmd=0x80 | (position & 0x0F);
		LCD_CMD(SendCmd);
		break;
		case 2:
		SendCmd=0x0C | (position & 0x0F);
		LCD_CMD(SendCmd);
		break;
	}
}