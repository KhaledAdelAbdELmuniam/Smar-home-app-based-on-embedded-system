/*
 * UART.c
 *
 * Created: 03-Nov-20 8:33:09 PM
 *  Author: Khaled
 */ 
#include "UART.h"

void UART_init(){
	UCSRB |= (1<<TXEN) | (1<<RXEN); // EN  TX&RX
	UCSRC |= (1<<URSEL) | (1<<UCSZ0) | (UCSZ1); // 8BIT -0 PAR - 1 STOP 
	UBRRL = MyUBRR; //LOW 8BIT
	UBRRH =MyUBRR >>8;
	
}

void UART_send(unsigned char data){
	while (!(UCSRA & (1<<UDRE)));
	UDR = data;
}
unsigned char UART_recieve(){
	while (!(UCSRA & (1<<RXC)));
	return UDR;
}
void UARTSendString(char *string){
	unsigned char i=0;
	while(string[i] != '\0'){
		UART_send(string[i]);
		i++;
	}
}