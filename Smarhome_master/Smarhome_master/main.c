/*
 * Smarhome_master.c
 *
 * Created: 05-Nov-20 9:33:19 PM
 * Author : Khaled
 */ 


#include "UART.h"
#include <avr/io.h>
#include "LCD.h"
#define F_CPU 16000000UL
#define miniCount 250
#define maxCount 500
#define miniAngle 0
#define maxAngle 180
#include "ADC.h"
#include <stdlib.h>
#include "SPI.h"

int main(void) {
	char buffer[0];
	uint8 order ;
	//LCD initiating
	DIO_Init();
	LCD_init();
	LCD_char(' ');
	//______________________________________________-
	
	//LM35 initiating
	
	DIO_Init();
	ADC_init();
	unsigned short temp =0;
	//UATR initiating
	UART_init();
	UARTSendString("welcome");	
	//_________________________-
	LCD_startpos(1,0);
	LCD_String("welcome Sir");
	_delay_ms(1000);
	LCD_startpos(1,0);
	LCD_String("insert action");
	_delay_ms(1000);
	LCD_startpos(1,0);
	LCD_String(" 1-lights on ");
	_delay_ms(1000);
	LCD_startpos(1,0);
	LCD_String(" 2-lights off ");
	_delay_ms(1000);
	LCD_startpos(1,0);
	LCD_String(" 3-doors open ");
	_delay_ms(1000);
	LCD_startpos(1,0);
	LCD_String(" 4-doors off ");
	_delay_ms(1000);
	LCD_startpos(1,0);
	LCD_String(" 5-temprature ");
	
		SPI_init('M');
		slave_EN();
		
	while(1){
	
			order= UART_recieve();
			
			//___________________________________
			
			//turning lights on.........................
			if(order == '1'){
				UARTSendString("wait"); 
				if(SPI_TX_RX('1') == (0x55)){
					UARTSendString("Done"); 
				}
			}
	
			//.....................................
			
			
			//_______________________________
			
			

			
			//turning lights off.................................
			if(order == '2'){
				UARTSendString("wait");
				if(SPI_TX_RX('2') == 0x55){
					UARTSendString("done");
				}
			}
			//..................................................
			
			//__________________________________________________
			
			//opening doors.................................
			
			if(order == '3'){
				UARTSendString("wait");
				if(SPI_TX_RX('3') == 0x55){
					UARTSendString("done");
				}
			}
			//.............................................
			
			//____________________________________________
			
			//closing doors...............................
			if(order == '4'){
				UARTSendString("wait");
				if(SPI_TX_RX('4') == 0x55){
					UARTSendString("done");
				}
			}
			//............................................
			
			//____________________________________________
			
						 //temprature......................................
						 else if(order == '5' ){
							UARTSendString("wait");
	
							 if(SPI_TX_RX('5') == (0x55)){
								  
								 _delay_ms(400);
								 temp = SPI_TX_RX('5');
								 if(temp==27){
									
								 }
								 
							 }
							 LCD_startpos(1,0);
							 LCD_String("temperature: ");
							 itoa(temp,buffer,10);
							 LCD_String(buffer);
							 _delay_ms(1000);
							//LCD_CMD(0x01);
							 UARTSendString("done");
						 }
						 //...................................................
						 
						 //__________________________________________________
			
			
	}
}