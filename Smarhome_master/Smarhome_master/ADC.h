/*
 * ADC.h
 *
 * Created: 29-Oct-20 6:31:31 PM
 *  Author: Khaled
 */ 


#ifndef ADC_H_
#define ADC_H_
#include <avr/io.h>
void ADC_init(void);
unsigned short ADC_Read(unsigned char Channel);




#endif /* ADC_H_ */