/*
 * SPI.c
 *
 * Created: 04-Nov-20 6:58:45 PM
 *  Author: Khaled
 */ 
#include "SPI.h"
#include "Bit_math.h"
void SPI_init(unsigned char status){
	switch(status){
		case'M' :
		SPIDDR |= (1<<MOSI) | (1<<SS) | (1<<SCK);
		SPIDDR &=~ (1<<MISO);
		SPCR |= (1<<MSTR)| (1<<SPE);
		slave_DIS();
		
		
		break;
		
		
		case'S':
		SPIDDR &=~ (1<<MOSI) | (1<<SS) | (1<<SCK);
		SPIDDR |= (1<<MISO);
		SPCR |= (1<<SPE);
		break;	
		}
	//SPCR |= (1<<SPE);
	
}

unsigned char SPI_TX_RX(unsigned char data){
	SPDR =data;
	while (!get_bit(SPSR,SPIF));
	return SPDR;
	
}