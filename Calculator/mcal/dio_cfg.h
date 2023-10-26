/*
 * dio_cfg.h
 *
 * Created: 10/26/2023 2:34:59 PM
 *  Author: Mohamed Osama
 */ 


#ifndef DIO_CFG_H_
#define DIO_CFG_H_

#define DIO_PINA0		Output
#define DIO_PINA1		Output
#define DIO_PINA2		Output
#define DIO_PINA3		Output
#define DIO_PINA4		Output
#define DIO_PINA5		Output
#define DIO_PINA6		Output
#define DIO_PINA7		Output

#define DIO_PINB0		Output
#define DIO_PINB1		Output
#define DIO_PINB2		Output
#define DIO_PINB3		Output
#define DIO_PINB4		Output
#define DIO_PINB5		Output
#define DIO_PINB6		Output
#define DIO_PINB7		Output

#define DIO_PINC0		Input
#define DIO_PINC1		Input
#define DIO_PINC2		Input
#define DIO_PINC3		Input
#define DIO_PINC4		Input
#define DIO_PINC5		Input
#define DIO_PINC6		Input
#define DIO_PINC7		Input

#define DIO_PIND0		Output
#define DIO_PIND1		Output
#define DIO_PIND2		Output
#define DIO_PIND3		Output
#define DIO_PIND4		Output
#define DIO_PIND5		Output
#define DIO_PIND6		Output
#define DIO_PIND7		Output

#define helper(b7,b6,b5,b4,b3,b2,b1,b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0
#define concate(b7,b6,b5,b4,b3,b2,b1,b0) helper(b7,b6,b5,b4,b3,b2,b1,b0)


#endif /* DIO_CFG_H_ */