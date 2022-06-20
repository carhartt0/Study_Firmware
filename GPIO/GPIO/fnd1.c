/*
 * fnd1.c
 *
 * Created: 2022-06-17 오후 4:21:29
 *  Author: PKNU
 */ 

#define F_CPU 7432800UL
#include <avr/io.h>
#include <util/delay.h>

int main()
{
	DDRA = 0x00;
	DDRD = 0xff;
	
	char input[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7c,0x07};
	
		
	while(1)
	{
		switch(PINA)
		{
			case 0x01:
				PORTD = 0x3f;
				break;
			case 0x02:
				PORTD = 0x06;
				break;
			case 0x04:
				PORTD = 0x5b;
				break;
			case 0x08:
				PORTD = 0x4f;
				break;
			case 0x10:
				PORTD = 0x66;
				break;
			case 0x20:
				PORTD = 0x6d;
				break;
			case 0x40:
				PORTD = 0x7c;
				break;
			case 0x80:
				PORTD = 0x07;
				break;
		}
		
	}
	
	
		/*PORTD = 0x02;
		_delay_ms(2000);
				//0b 00111111
		_delay_ms(1000);
		PORTD = 0x06;
		_delay_ms(1000);
		PORTD = 0x5B;
		_delay_ms(1000);
		PORTD = 0x4f;
		_delay_ms(1000);
		PORTD = 0x66;
		_delay_ms(1000);
		PORTD = 0x6d;
		_delay_ms(1000);
		PORTD = 0x7d;
		_delay_ms(1000);
		PORTD = 0x27;
		_delay_ms(1000);
		PORTD = 0x7f;
		_delay_ms(1000);
		PORTD = 0x6f;
		_delay_ms(1000);
		PORTD = 0x01;
		_delay_ms(2000);*/
	
	
	return 0;
}
