/*
 * lcdTest1.c
 *
 * Created: 2022-06-20 오후 2:54:58
 *  Author: PKNU
 */ 

#define  F_CPU 7372800UL
#include <avr/io.h>
#include "Lcd.h"
#include <util/delay.h>

int main()
{
	Byte *str1 = "LCD TEST";
	Byte *str2 = "ATmage 128A";
	

	DDRA = 0xff;
	DDRG = 0x0f;
	
	Lcd_Init();
	Lcd_Clear();
	//LcdInit_4bit();
	
	Byte temp[30] = "";
	int i,j,res;
	
	
	while(1)
	{
		for (i=2; i<=9; i++)
		{
			for(j=1; j<10; j++)
			{
				res = i*j;
				sprintf	(temp, "%d x %d = %d",i, j, res);
				Lcd_Pos(0, 0);
				Lcd_STR(temp);
				_delay_ms(1000);
			}
		}
		
			
			//Lcd_Pos(1, 0);
			//Lcd_STR(str2);
	}
	
	return 0;
}

/*
char gugu()
{
	char temp[256];
	int i,j,res;
	
	for (i=2; i<=9; i++)
	{
		for(j=1; j<10; j++)
		{
			res = i*j;
			sprintf	(temp, "%d x %d = %d",i, j, res);
			return temp;
		}
	}

}
*/