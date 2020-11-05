/*
 * DIO.c
 *
 * Created: 17-Oct-20 7:17:18 PM
 *  Author: Khaled
 */ 
#include "DIO.h"

void DIO_write(DIO_Channel_types channelID, STD_leveltypes level){
	
DIO_PORT_types PORTX= channelID/8;
DIO_Channel_types BIT_NUMBER=channelID%8;
switch (PORTX){
	case DIO_portA:
	   if (level == std_high){
		   set_bit(PORTA_Reg,BIT_NUMBER);
	   }
	   else {clear_bit(PORTA_Reg,BIT_NUMBER);}
		   break;
		   
		   case DIO_portB:
		   if (level == std_high){
			   set_bit(PORTB_Reg,BIT_NUMBER);
		   }
		   else {clear_bit(PORTB_Reg,BIT_NUMBER);}
		   break;
		   
		   case DIO_portC:
		   if (level == std_high){
			   set_bit(PORTC_Reg,BIT_NUMBER);
		   }
		   else {clear_bit(PORTC_Reg,BIT_NUMBER);}
		   break;
		   case DIO_portD:
		   if (level == std_high){
			   set_bit(PORTD_Reg,BIT_NUMBER);
		   }
		   else {clear_bit(PORTD_Reg,BIT_NUMBER);}
		   break;
		   }
		   
		   }

