/*
 * Keypad_Config.h
 *
 * Created: 10/26/2023 1:23:06 PM
 *  Author: Mohamed Osama
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define KPD_COL0_PIN	DIO_PIN7
#define KPD_COL1_PIN	DIO_PIN6
#define KPD_COL2_PIN	DIO_PIN5
#define KPD_COL3_PIN	DIO_PIN3

#define KPD_ROW0_PIN	DIO_PIN5
#define KPD_ROW1_PIN	DIO_PIN4
#define KPD_ROW2_PIN	DIO_PIN3
#define KPD_ROW3_PIN	DIO_PIN2

#define KPD_ROW_PORT		DIO_PortC
#define KPD_COL_PORT		DIO_PortD

#define KPD_ARR_VAL      { 7 , 8 , 9, '/' },{ 4 , 5 , 6, '*' },{ 1 , 2 , 3, '-' },{ 'C' , 0 , '=', '+' }
#define ROW_NUMBER 4
#define COL_NUMBER 4

#endif /* KEYPAD_CONFIG_H_ */