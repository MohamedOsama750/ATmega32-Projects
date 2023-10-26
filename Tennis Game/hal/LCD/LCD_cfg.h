/*
 * LCD_cfg.h
 *
 * Created: 10/26/2023 3:16:21 PM
 *  Author: Mohamed Osama
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#define LCD_4_BIT_MODE	0
#define LCD_8_BIT_MODE	1

#define LCD_BITS	LCD_4_BIT_MODE

#if LCD_BITS == LCD_8_BIT_MODE
#define LCD_D0	DIO_PIN0
#define LCD_D1	DIO_PIN1
#define LCD_D2	DIO_PIN2
#define LCD_D3	DIO_PIN3
#endif

#define LCD_D4	DIO_PIN0
#define LCD_D5	DIO_PIN1
#define LCD_D6	DIO_PIN2
#define LCD_D7	DIO_PIN4

#define LCD_RS				DIO_PIN3
#define LCD_EN				DIO_PIN2
#define LCD_CONTROL_PORT  DIO_PortA
#define LCD_DATA_PORT  	  DIO_PortB

#endif /* LCD_CFG_H_ */