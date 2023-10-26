/*
 * bit_math.h
 *
 * Created: 10/26/2023 3:22:12 PM
 *  Author: Mohamed Osama
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define Set_Bit(Reg,Bit)     (Reg|=(1<<Bit))
#define Clear_Bit(Reg,Bit)   (Reg&=~(1<<Bit))
#define Toggle_Bit(Reg,Bit)  (Reg^=(1<<Bit))
#define Get_Bit(Reg,Bit)     ((Reg>>Bit) & 0x01)

#define SET_BIT(Reg,Bit)     (Reg|=(1<<Bit))
#define CLR_BIT(Reg,Bit)   	 (Reg&=~(1<<Bit))
#define GET_BIT(Reg,Bit)     ((Reg>>Bit) & 0x01)


#endif /* BIT_MATH_H_ */