/*
 * LM35.h
 *
 * Created: 11/2/2023 3:14:40 PM
 *  Author: mohamed osama
 */ 


#ifndef LM35_H_
#define LM35_H_

#include "../mcal/adc.h"

/*Function Prototype*/
u16 LM35_U16Read(u8  Copy_u8readchannel);
void LM35_VoidInit(void);

#endif /* LM35_H_ */