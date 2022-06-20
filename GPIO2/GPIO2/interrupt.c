/*
 * interrupt.c
 *
 * Created: 2022-06-20 오전 9:57:30
 *  Author: 임경길
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

volatile unsigned char Time_STOP = 0;

//INT4
SIGNAL(INT4_vect)
{
	cli();
	if(Time_STOP == 0)
	{
		Time_STOP = 1;
	}
	else
	{
		Time_STOP = 0;
	}
	sei();
}

int main()
{
	unsigned char LED_Data = 0x01;
	
	DDRC = 0x0F;
	DDRE = 0x00;
	EIMSK = 0x10;		//INT 0 활성화
	EICRB = 0x03;		//0b 0000 0000
	EIFR = 0x10;
	sei();
	
	while(1)
	{
		PORTC = LED_Data;
		if(Time_STOP == 0)
			LED_Data = 0x01;
		else
			LED_Data <<=1;
		
		_delay_ms(1000);
	}
	
	return 0;
}