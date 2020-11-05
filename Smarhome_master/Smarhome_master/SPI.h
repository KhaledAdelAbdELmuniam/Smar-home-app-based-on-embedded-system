/*
 * SPI.h
 *
 * Created: 04-Nov-20 6:58:55 PM
 *  Author: Khaled
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>
#define SPIPORT PORTB 
#define SPIDDR DDRB

#define SS       4
#define MOSI     5
#define MISO     6
#define SCK      7 
#define slave_EN() (SPIPORT &=~ (1<<SS))
#define slave_DIS() (SPIPORT |= (1<<SS))

void SPI_init(unsigned char status);
unsigned char SPI_TX_RX(unsigned char data);





#endif /* SPI_H_ */