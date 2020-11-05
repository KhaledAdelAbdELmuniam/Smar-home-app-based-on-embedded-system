/*
 * DIO_confg.c
 *
 * Created: 17-Oct-20 8:11:11 PM
 *  Author: Khaled
 */ 


#include "DIO_confg.h"

const PIN_CFG ChannelsInit[] = {
	//portA
	{OUTPUT,std_low},
	{OUTPUT,std_low},
	{OUTPUT,std_low},
	{OUTPUT,std_low},
	{OUTPUT,std_low},
	{OUTPUT,std_low},
	{OUTPUT,std_low},
	{OUTPUT,std_low},
	
	//portB
	{OUTPUT,std_low},
	{OUTPUT,std_low},
	{OUTPUT,std_low},
	{OUTPUT,std_low},
	{OUTPUT,std_low},
	{OUTPUT,std_low},
	{OUTPUT,std_low},
	{OUTPUT,std_low},
	
	//portC
	{OUTPUT,std_low},
	{OUTPUT,std_low},
	{OUTPUT,std_low},
	{OUTPUT,std_low},
	{OUTPUT,std_low},
	{OUTPUT,std_low},
	{OUTPUT,std_low},
	{OUTPUT,std_low},
	
	//portD
	{OUTPUT,std_low},
	{OUTPUT,std_low},
	{OUTPUT,std_low},
	{OUTPUT,std_low},
	{OUTPUT,std_low},
	{OUTPUT,std_low},
	{OUTPUT,std_low},
	{OUTPUT,std_low}
};


void DIO_Init(){
	DIO_PORT_types PORTx;
	uint8 BitNo, count;
	
	//DDR_Reg initialization
	for(count=DIO_channelA0; count<PIN_Num;count++){
		PORTx=count/8;
		BitNo=count%8;
		
		switch (PORTx){
			case DIO_portA:
			if (ChannelsInit[count].ChannelDir == OUTPUT){
				set_bit(DDRA_Reg,BitNo);
			}
			else{
				clear_bit(DDRA_Reg,BitNo);
			}
			break;
			
			case DIO_portB:
			if (ChannelsInit[count].ChannelDir == OUTPUT){
				set_bit(DDRB_Reg,BitNo);
			}
			else{
				clear_bit(DDRB_Reg,BitNo);
			}
			break;
			
			case DIO_portC:
			if (ChannelsInit[count].ChannelDir == OUTPUT){
				set_bit(DDRC_Reg,BitNo);
			}
			else{
				clear_bit(DDRC_Reg,BitNo);
			}
			break;
			
			case DIO_portD:
			if (ChannelsInit[count].ChannelDir == OUTPUT){
				set_bit(DDRD_Reg,BitNo);
			}
			else{
				clear_bit(DDRD_Reg,BitNo);
			}
			break;
		}
		
	}
	
	//PORT_Reg initialization
	for(count=DIO_channelA0; count<PIN_Num;count++){
		PORTx=count/8;
		BitNo=count%8;
		
		switch (PORTx){
			case DIO_portA:
			if (ChannelsInit[count].ChannelLevel == std_high){
				set_bit(PORTA_Reg,BitNo);
			}
			else{
				clear_bit(PORTA_Reg,BitNo);
			}
			break;
			
			case DIO_portB:
			if (ChannelsInit[count].ChannelLevel == std_high){
				set_bit(PORTB_Reg,BitNo);
			}
			else{
				clear_bit(PORTB_Reg,BitNo);
			}
			break;
			
			case DIO_portC:
			if (ChannelsInit[count].ChannelLevel == std_high){
				set_bit(PORTC_Reg,BitNo);
			}
			else{
				clear_bit(PORTC_Reg,BitNo);
			}
			break;
			
			case DIO_portD:
			if (ChannelsInit[count].ChannelLevel == std_high){
				set_bit(PORTD_Reg,BitNo);
			}
			else{
				clear_bit(PORTD_Reg,BitNo);
			}
			break;
		}
		
	}
	
	
}
