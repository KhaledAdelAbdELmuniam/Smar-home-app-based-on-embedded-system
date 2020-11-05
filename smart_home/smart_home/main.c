/*
 * smart_home.c
 *
 * Created: 05-Nov-20 6:25:04 PM
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

void ServoMotor(unsigned short angle){
	OCR1A =(((angle-miniAngle)*(maxCount-miniCount))/(maxAngle-miniAngle))+miniCount-1;
	
}

int main(void)
{
	uint8 order;
	int j;
	
	//lights initiating
	DDRD |= (1<<3);
	//____________________________________________________-
	
	//Motor Initiating
	DDRD |= (1<<5);
	
	ICR1 =4999;
	
	TCCR1A |= (1<<COM1A1)|(1<<WGM11); // N=64 -FPWM MODE 14 - NON INVERTING
	TCCR1B |= (1<<WGM12) | (1<<WGM13) | (1<<CS01) | (1<<CS00);
	
	//LCD initiating
	DIO_Init();
	LCD_init();
	LCD_char(' ');
	//______________________________________________-
	
	//LM35 initiating 
	 
	 DIO_Init();
	 ADC_init();
	 unsigned short temp =0;
	 char buffer[0];

	 //______________________________________________________-
	 
	SPI_init('S');
	
	while (1)
	{
	
		 order= SPI_TX_RX(0x55);

		//Lights control
      if(order == '1'){
		 
	set_bit(PORTD,3);
      }
	  else if(order == '2')	{
		  clear_bit(PORTD,3);
	  }
	  // Motors control for opening doors,so angle will be between 0 & 90
	  
	   else if(order == '3'){	  
		   ServoMotor(90);
		   LCD_startpos(1,0);
		   LCD_String(" angle=90");
	   }
	   	   else if(order == '4')	{
		   	   ServoMotor(0);
		   	   LCD_startpos(1,0);
		   	   LCD_String(" angle=0");
	   	   }
		//_____________________________________________________________________________________________________________
		
		else if(order == '5')	{
				temp= ADC_Read(1);
				temp /=4;
				SPI_TX_RX(temp);
	
			
		}
		

		
	
		
		
	
		
		
		
		
	}
}

