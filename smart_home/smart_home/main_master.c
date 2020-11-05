/*
 * SPI_master.c
 *
 * Created: 04-Nov-20 6:56:34 PM
 * Author : Khaled
 */ 

#include "SPI.h"
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
	DDRC |=(1<<7);
	
	SPI_init('M');
	slave_EN();
    while (1) 
    {
		if(SPI_TX_RX(0x01)==0x55){
			PORTC ^=(1<<7);
			_delay_ms(500);
		}
    }
}

