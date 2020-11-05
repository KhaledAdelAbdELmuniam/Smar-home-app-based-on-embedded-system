/*
 * SPI_SLAVE.c
 *
 * Created: 04-Nov-20 7:21:03 PM
 * Author : Khaled
 */ 

#include "SPI.h"


int main(void)
{
 DDRC |= (1<<7);
 SPI_init('S');
    while (1) 
    {
		if(SPI_TX_RX(0X55)==0X01){
			PORTC ^= (1<<7);
		}
		
    }
}

