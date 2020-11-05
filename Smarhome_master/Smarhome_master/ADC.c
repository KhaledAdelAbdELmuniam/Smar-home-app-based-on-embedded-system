/*
 * ADC.c
 *
 * Created: 29-Oct-20 6:31:13 PM
 *  Author: Khaled
 */ 
#include "ADC.h"
void ADC_init(void){
	ADMUX= (1<<REFS1)|(1<<REFS0); //INTERNAL REF VOLTAGE
	ADCSRA= (1<<ADEN)|(1<<ADPS0)|(1<<ADPS1)|(ADPS2); //ENABLE ADC AND 128 PRESCALE
}
unsigned short ADC_Read(unsigned char Channel){
	unsigned short data;
	ADMUX= (ADMUX & 0xE0) | (Channel & 0x1F);
	ADCSRA |= (1<<ADSC); //START CONVERT
	//WAIT 25 PR 13 ADC CYCLE 
	while (!(ADCSRA & (1<<ADIF)));
	ADCSRA |= (1<<ADIF);
	data = ADCL;
	data |=ADCH <<8;
	return data;
}