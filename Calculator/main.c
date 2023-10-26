/*
 * Test.c
 *
 * Created: 10/25/2023 11:41:54 PM
 * Author : Mohamed Osama
 */ 

#include "Lib/STD_types.h"
#include "Lib/bit_math.h"
#include "mcal/dio.h"
#include "LCD/lcd.h"
#include "Keypad/Keypad.h"
#include "util/delay.h"

void CheckPriority();
void CalculateResult();

u8 Global_index;
f32 numArr[20] = {0};
u8  opArr[20] = {0};
f32 oldNum = -1;
u8 oldOperation = 0;
u8 currentOperation = 0;
u8 key = NO_PRESSED_KEY;
u8 errorFlag = 0;
int main(){
	DIO_voidInit();
	DIO_voidSetPortValue(DIO_PortC, 0xFF);
	DIO_voidSetPortValue(DIO_PortB, 0xFF);
	LCD_voidInit();
	while(1){
		key = KPD_u8GetPressedKey();
		if(key != NO_PRESSED_KEY){
			if(currentOperation == '=' || errorFlag == 1){
				errorFlag = 0;
				LCD_voidSendCommand(LCD_ClearDisplay);
				currentOperation = 0;
			}
			if(key < 10){
				if(oldNum < 0){
					oldNum = 0;
				}
				LCD_voidWriteIntData(key);
				oldNum = (oldNum * 10) + key;
			}
			else{
				if(oldNum >= 0 || key == 'C'){
					switch(key){
						case '/':
						CheckPriority();
						if(errorFlag != -1){
							LCD_voidWriteChar(key);
							oldOperation = '/';
						}
						break;
						case '*':
						CheckPriority();
						if(errorFlag != -1){
							LCD_voidWriteChar(key);
							oldOperation = '*';
						}
						break;

						case '-':
						currentOperation = '-';
						LCD_voidWriteChar(key);
						CheckPriority();
						break;

						case '+':
						currentOperation = '+';
						LCD_voidWriteChar(key);
						CheckPriority();
						break;

						case '=':
						currentOperation = '=';
						CheckPriority();
						CalculateResult();
						if(errorFlag != 1){
							LCD_voidGoToPosition(3, 0);
							LCD_voidWriteChar(key);
							LCD_voidWriteFloatData(numArr[Global_index-1]);
							Global_index = 0;
						}
						break;

						case 'C':
						LCD_voidSendCommand(LCD_ClearDisplay);
						Global_index = 0;
						oldNum = -1;
						oldOperation = 0;
						break;

					}
				}
			}
		}
	}
	return 0;
}

void CheckPriority(){
	if(oldOperation == '/'){
		oldOperation = 0;
		if(oldNum > 0){
			oldNum = numArr[Global_index - 1] / oldNum;
			Global_index--;
		}
		else{
			LCD_voidSendCommand(LCD_ClearDisplay);
			LCD_voidWriteString((u8*)"Error: Div. by 0!");
			oldNum = -1;
			Global_index = 0;
			errorFlag = 1;
			return;
		}

	}
	else if(oldOperation == '*'){
		oldOperation = 0;
		oldNum = numArr[Global_index - 1] * oldNum;
		Global_index--;
	}
	if(currentOperation == '+' || currentOperation == '-'){
		opArr[Global_index] = key;
		currentOperation = 0;
	}

	numArr[Global_index] = oldNum;
	Global_index++;
	oldNum = -1;
}

void CalculateResult(){
	u8 counter = 0;
	for(counter = 0; counter+1 < Global_index; counter++){
		if(opArr[counter] == '+'){
			numArr[counter+1] = numArr[counter] + numArr[counter + 1];
		}
		else if(opArr[counter] == '-'){
			numArr[counter+1] = numArr[counter] - numArr[counter + 1];
		}
	}
}