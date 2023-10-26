/*
 * Tennis Game.c
 *
 * Created: 10/26/2023 3:09:38 PM
 * Author : Mohamed Osama
 */ 

#include "lib/STD_types.h"
#include "lib/bit_math.h"
#include "mcal/dio_interface.h"
#include "hal/LCD/LCD_Interface.h"
#include "hal/Keypad/Keypad_Interface.h"
#include "util/delay.h"

#define PAD1	 0b00011,0b00011,0b00011,0b00011,0b00011,0b00011,0b00011,0b00011
#define PAD2	 0b11000,0b11000,0b11000,0b11000,0b11000,0b11000,0b11000,0b11000
#define BALL	 0b00000,0b00000,0b01110,0b01110,0b01110,0b01110,0b00000,0b00000

#define END 	(19 + 0x80)
#define START 	0x80

u8 ballX = 1;
u8 ballY = START + 10;
u8 pad1X = 1;
u8 pad2X = 1;
u8 moveLeft = 1;

void AdjustMovements();

int main(){
	DIO_voidInit();
	DIO_voidSetPortValue(DIO_PortC, 0xFF);
	LCD_voidInit();
	u8 pad1[] = {PAD1};
	u8 pad2[] = {PAD2};
	u8 ball[] = {BALL};
	u8 player1[] = "Mohamed ";
	u8 player2[] = " Osama ";

	u8 player1Score = 0;
	u8 player2Score = 0;
	DIO_voidSetPinValue(DIO_PortC, DIO_PIN6, Low);
	LCD_voidGoToPosition(0,0);

	while(1){
		LCD_voidSendCommand(LCD_ClearDisplay);
		LCD_voidGoToPosition(0,0);
		LCD_voidWriteString(player1);
		LCD_voidWriteChar(':');
		LCD_voidWriteIntData(player1Score);
		LCD_voidGoToPosition(0,0x80 + 10);
		LCD_voidWriteString(player2);
		LCD_voidWriteChar(':');
		LCD_voidWriteIntData(player2Score);
		LCD_voidDisplaySpecialChar(pad1,7,pad1X,START);
		LCD_voidDisplaySpecialChar(pad2,6,pad2X,END);
		LCD_voidDisplaySpecialChar(ball,5,ballX,ballY);
		if(moveLeft){
			ballY--;
			if(ballY == START){
				if(ballX == pad1X){
					ballY+=2;
					moveLeft = 0;
				}
				else{
					DIO_voidSetPinValue(DIO_PortC,DIO_PIN6, High);
					player2Score++;
					ballY = START + 10;
					ballX = 2;

					LCD_voidSendCommand(LCD_ClearDisplay);
					LCD_voidGoToPosition(1, START + 5);
					LCD_voidWriteString(player2);
					LCD_voidWriteString((u8*)"Scored!");
					_delay_ms(200);
					DIO_voidSetPinValue(DIO_PortC,DIO_PIN6, Low);
					_delay_ms(800);
					if(player2Score == 3){
						LCD_voidSendCommand(LCD_ClearDisplay);
						LCD_voidGoToPosition(1, START + 5);
						LCD_voidWriteString(player2);
						LCD_voidWriteString((u8*)"Wins!");
						player1Score = 0;
						player2Score = 0;
						_delay_ms(1000);
					}
				}
			}
		}
		else{
			ballY++;
			if(ballY == END){
				if(ballX == pad2X){
					ballY-=2;
					moveLeft = 1;
				}
				else{
					DIO_voidSetPinValue(DIO_PortC,DIO_PIN6, High);
					player1Score++;
					ballY = START + 10;
					ballX = 2;

					LCD_voidSendCommand(LCD_ClearDisplay);
					LCD_voidGoToPosition(1, START + 5);
					LCD_voidWriteString(player1);
					LCD_voidWriteString((u8*)"Scored!");
					_delay_ms(200);
					DIO_voidSetPinValue(DIO_PortC,DIO_PIN6, Low);
					_delay_ms(800);
					if(player1Score == 3){
						LCD_voidSendCommand(LCD_ClearDisplay);
						LCD_voidGoToPosition(1, START + 5);
						LCD_voidWriteString(player1);
						LCD_voidWriteString((u8*)"Wins!");
						player1Score = 0;
						player2Score = 0;
					}
					_delay_ms(1000);
				}
			}
		}
		AdjustMovements();
		_delay_ms(250);
	}
	return 0;
}

void AdjustMovements(){
	u8 buttonPressed = NO_PRESSED_KEY;
	buttonPressed = KPD_u8GetPressedKey();
	if(buttonPressed != NO_PRESSED_KEY){
		if(buttonPressed == 4){
			if(moveLeft){
				pad1X++;
				if(pad1X > 3){
					pad1X =1;
				}
			}
			else{
				ballX++;
				if(ballX > 3){
					ballX = 1;
				}
			}
		}
		else if(buttonPressed == '*'){
			if(moveLeft == 0){
				pad2X++;
				if(pad2X > 3){
					pad2X =1;
				}
			}
			else{
				ballX++;
				if(ballX > 3){
					ballX =1;
				}
			}
		}
		else if(buttonPressed == 7){
			if(moveLeft == 1){
				pad1X--;
				if(pad1X < 1){
					pad1X =3;
				}
			}
			else{
				ballX--;
				if(ballX < 1){
					ballX =3;
				}
			}
		}
		else if(buttonPressed == '/'){
			if(moveLeft == 0){
				pad2X--;
				if(pad2X < 1){
					pad2X =3;
				}
			}
			else{
				ballX--;
				if(ballX < 1){
					ballX =3;
				}
			}
		}
	}
}

