/*
 * Utils.h
 *
 * Created: 11/2/2023 3:11:32 PM
 *  Author: mohamed osama
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define  READ_BIT(reg,bit)       ((reg>>bit)&1)     //(reg &(1<<bit))
#define  SET_BIT(reg,bit)        (reg=reg|(1<<bit))
#define  CLR_BIT(reg,bit)        (reg=reg&~(1<<bit))
#define  TOGGLE_BIT(reg,bit)     (reg=reg^(1<<bit))

#endif /* UTILS_H_ */