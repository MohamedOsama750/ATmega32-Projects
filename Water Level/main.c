/*
 * Water Level.c
 *
 * Created: 10/26/2023 7:01:12 PM
 * Author : Mohamed Osama
 */ 

#include "lib/STD_types.h"
#include "lib/bit_math.h"
#include "mcal/dio_interface.h"
int main(){
	DIO_voidInit();
	DIO_voidSetPortValue(DIO_PortA,0xFF);
	while(1){
		DIO_voidSetPinValue(DIO_PortB, DIO_PIN0,!DIO_u8GetPinValue(DIO_PortA,DIO_PIN0));
		DIO_voidSetPinValue(DIO_PortB, DIO_PIN1,!DIO_u8GetPinValue(DIO_PortA,DIO_PIN1));
		DIO_voidSetPinValue(DIO_PortB, DIO_PIN2,!DIO_u8GetPinValue(DIO_PortA,DIO_PIN2));
		DIO_voidSetPinValue(DIO_PortB, DIO_PIN3,!DIO_u8GetPinValue(DIO_PortA,DIO_PIN3));
	}
	return 0;
}

