/*
 * LDR.h
 *
 * Created: 11/2/2023 3:16:00 PM
 *  Author: mohamed osama
 */ 
#include "../mcal/adc.h"

#ifndef LDR_H_
#define LDR_H_
/*Function Prototype*/
u16 LDR_U16Read(u8  Copy_u8readchannel);
void LDR_VoidInit(void);

#endif /* LDR_H_ */