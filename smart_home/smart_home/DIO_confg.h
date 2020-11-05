/*
 * DIO_confg.h
 *
 * Created: 17-Oct-20 8:11:25 PM
 *  Author: Khaled
 */ 


#ifndef DIO_CONFG_H_
#define DIO_CONFG_H_

#include "DIO.h"

typedef struct{
	DIO_Dir ChannelDir;
	STD_leveltypes ChannelLevel;
	}PIN_CFG;

#define PIN_Num 32


void DIO_Init(void);




#endif /* DIO_CONFG_H_ */