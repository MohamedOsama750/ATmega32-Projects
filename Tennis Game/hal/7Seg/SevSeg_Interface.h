/*
 * _SevSeg_Interface.h
 *
 * Created: 10/26/2023 3:13:41 PM
 *  Author: Mohamed Osama
 */ 


#ifndef SevSEG_INTERFACE_H_
#define SevSEG_INTERFACE_H_

#include "SevSeg_cfg.h"
#include "SevSeg_private.h"

void SevSeg_voidSingleInit();
void SevSeg_voidDoubleInit();
void SevSeg_voidDisplayNumber(u8 number);
void SevSeg_voidSingleAutoCounter();
void SevSeg_voidDoubleAutoCounter();
void SevSeg_voidSingleRangeCounter(s8 start,s8 end);
void SevSeg_voidDoubleRangeCounter(s8 start,s8 end);
void SevSeg_voidBCDDoubleDisplay(s8 start,s8 end);
void SevSeg_voidBCDDisplay(u8 port, u8 number);
void SevSeg_voidMulBCD(s8 start,s8 end);

#endif /* SevSEG_INTERFACE_H_ */