/*
 * LCD_Conf.h
 *
 * Created: 10/23/2023 3:15:39 PM
 *  Author: Mohamed Osama
 */ 


#ifndef LCD_CONF_H_
#define LCD_CONF_H_

#define M_5X7_2lines          0x38
#define Display_ON_No_C       0x0c
#define Display_ON_C          0x0e
#define Display_ON_C_Blanking 0x0f
#define CLR_INS               0x01
#define increment_No_shift    0X06

#define _4_BIT   0
#define _8_BIT   1

/* _4_BIT OR _8_BIT*/
#define  LCD_MODE  _4_BIT

#define  RS   PINA3
//#define  RW   PINA2
#define  EN   PINA2
#define  D7   PINB4
#define  D6   PINB2
#define  D5   PINB1
#define  D4   PINB0

#define LCD_PORT  PB

#endif /* LCD_CONF_H_ */