/*
 * UART.h
 *
 * Created: 03-Nov-20 8:33:26 PM
 *  Author: Khaled
 */ 

#include <avr/io.h>

#ifndef UART_H_
#define UART_H_
#define F_CPU 16000000UL
#define BAUD_rate 9600

#ifndef DoubleSpeed
#define MyUBRR ((F_CPU /(16UL*BAUD_rate))-1)
#else 
#define MyUBRR ((F_CPU /(8UL*BAUD_rate))-1)
#endif 

void UART_init();
void UART_send(unsigned char data);
unsigned char UART_recieve();
void UARTSendString(char *string);




#endif /* UART_H_ */