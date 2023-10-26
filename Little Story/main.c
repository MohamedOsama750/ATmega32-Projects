/*
 * Little Story.c
 *
 * Created: 10/25/2023 11:01:00 PM
 * Author : Mohamed osama
 */ 

#include "LCD/LCD.h"
#include <util/delay.h>
#include <stdarg.h>
#include <stdlib.h>

int main(void)
{
	
	DIO_Init();
	LCD_Init();

	char story[] = "Once upon a time, there was a boy named John.";
    char story1[] = " He loved to go on adventures in the forest near his house.";
	while(1)
	{
		LCD_Clear();
		for(int i=0; i<strlen(story); i+=20)
		{
			LCD_WriteString(story);
			LCD_WriteString(story1);
			_delay_ms(1000);
		}
	}

	return 0;
}