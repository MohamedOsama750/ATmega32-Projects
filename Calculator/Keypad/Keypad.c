/*
 * Keypad.c
 *
 * Created: 10/26/2023 1:24:34 PM
 *  Author: Mohamed Osama
 */ 

#include "../Lib/STD_types.h"
#include "../mcal/dio.h"
#include "Keypad.h"

u8 KPD_u8GetPressedKey(){
	u8 Local_u8PressedKey = NO_PRESSED_KEY;
	u8 Local_u8ColIndex;
	u8 Local_u8RowIndex;
	u8 Local_u8KPDArr[ROW_NUMBER][COL_NUMBER] = {KPD_ARR_VAL};
	u8 Local_u8ColArr[COL_NUMBER] = {KPD_COL0_PIN, KPD_COL1_PIN, KPD_COL2_PIN, KPD_COL3_PIN};
	u8 Local_u8RowArr[ROW_NUMBER] = {KPD_ROW0_PIN, KPD_ROW1_PIN, KPD_ROW2_PIN, KPD_ROW3_PIN};
	for(Local_u8ColIndex = 0; Local_u8ColIndex < COL_NUMBER; Local_u8ColIndex++){
		/*Activate current column by clearing it*/
		DIO_voidSetPinValue(KPD_COL_PORT,Local_u8ColArr[Local_u8ColIndex],Low);

		for(Local_u8RowIndex = 0; Local_u8RowIndex < ROW_NUMBER; Local_u8RowIndex++){
			if(DIO_u8GetPinValue(KPD_ROW_PORT,Local_u8RowArr[Local_u8RowIndex]) == Low){
				Local_u8PressedKey = Local_u8KPDArr[Local_u8RowIndex][Local_u8ColIndex];
				while(DIO_u8GetPinValue(KPD_ROW_PORT,Local_u8RowArr[Local_u8RowIndex]) == Low){

				}
				DIO_voidSetPinValue(KPD_COL_PORT,Local_u8ColArr[Local_u8ColIndex],High);
				return Local_u8PressedKey;
			}
		}

		/*Deactivate current column by setting it*/
		DIO_voidSetPinValue(KPD_COL_PORT,Local_u8ColArr[Local_u8ColIndex],High);

	}
	return Local_u8PressedKey;
}

