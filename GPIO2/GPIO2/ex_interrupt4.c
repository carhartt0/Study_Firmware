/*
 * ex_interrupt4.c
 *
 * Created: 2022-06-20 오후 12:32:33
 *  Author: PKNU
 */ 
#define F_CPU 7432800UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile unsigned char Time_STOP = 0;
volatile unsigned char cnt = 0;

int main(void)
{
	
	unsigned char FND_DATA_TBL [] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x27,0x7F,0x6f};
									
	DDRA = 0xff;
	DDRE = 0x00;
	
	EICRB = 0x32;
	EIMSK = 0x50;
	EIFR = 0x50;
	sei();
	
	while(1)
	{
		PORTA = FND_DATA_TBL[cnt];
		if (Time_STOP == 0)
		{
			cnt++;
			if(cnt>17) cnt=0;
		}
		_delay_ms(500);
	}
}

SIGNAL(INT4_vect)
{
	cli();
	
	Time_STOP=1;
	cnt=0;
	
	sei();
}

SIGNAL(INT6_vect)
{
	cli();
	
	Time_STOP =0;
	
	sei();
}