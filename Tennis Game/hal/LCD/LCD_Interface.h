/*
 * LCD_Interface.h
 *
 * Created: 10/26/2023 3:17:08 PM
 *  Author: Mohamed Osama
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "LCD_Private.h"
#include "LCD_cfg.h"

void LCD_voidInit();
void LCD_voidSendCommand(u8 command);
void LCD_voidSendInitCommand(u8 command);
void LCD_voidWriteChar(u8 data);
void LCD_voidWriteString(u8* Local_Data);
void LCD_voidWriteIntData(s32 Data);
void LCD_voidWriteFloatData(f32 Data);
u8* LCD_ptrIntToString(s32 anInteger,u8 *str);
void LCD_voidGoToPosition(u8 X_Position, u8 Y_Position);
void LCD_voidDisplaySpecialChar(u8 *char_ptr,u8 CGRam_index,u8 row,u8 column);

#endif /* LCD_INTERFACE_H_ */