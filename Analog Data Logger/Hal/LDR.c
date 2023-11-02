/*
 * LDR.c
 *
 * Created: 11/2/2023 3:15:43 PM
 *  Author: mohamed osama
 */ 
#include "ldr.h"
void LDR_VoidInit(void)
{
	ADC_Init(VREF_VCC,ADC_SCALER_64);

}


u16 LDR_U16Read(u8 Copy_u8readchannel)
{
	u16 light = 0;
	ADC_Read(Copy_u8readchannel,&light); /* read channel two where the temp sensor is connect */
	/* calculate the temp from the ADC value*/

	return light;
}