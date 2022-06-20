/*
 * led2.c
 *
 * Created: 2022-06-17 오후 1:54:38
 *  Author: PKNU
 */ 

#define  F_CPU	7432800
#include <avr/io.h>
#include <util/delay.h>

int main()
{
	DDRA = 0xff;
	DDRD = 0xff;
	
	int i;
		// 
	while(1)
	{
		int flag = 0x01;
		for (i=0;i<8;i++)
		{
			PORTD = ~(flag<<i);
			_delay_ms(100);
			
			if(i==7)
			{
				PORTD = 0xff;
			}
		}
		flag = 0x80;
		for (i=0;i<8;i++)
		{
			PORTD = ~(flag>>i);
			_delay_ms(100);
		}
		
		PORTA = 0x01;
		_delay_ms(100);
		PORTA = 0x02;
		_delay_ms(100);
		PORTA = 0x04;
		_delay_ms(100);
		PORTA = 0x08;
		_delay_ms(100)	;
		PORTA = 0x10;
		_delay_ms(100)	;
		PORTA = 0x20;
		_delay_ms(100)	;
		PORTA = 0x40;
		_delay_ms(100)	;
		PORTA = 0x80;
		_delay_ms(100)	;
		PORTA = 0x00;
		_delay_ms(100)	;
		//8421 8421
		PORTA = 0xff;
		_delay_ms(100)	;
		PORTA = 0xfe;
		_delay_ms(100)	;
		PORTA = 0xfc;
		_delay_ms(100)	;
		PORTA = 0xf8;
		_delay_ms(100)	;
		PORTA = 0xf0;
		_delay_ms(100)	;
		PORTA = 0xe0;
		_delay_ms(100)	;
		PORTA = 0xc0;
		_delay_ms(100)	;
		PORTA = 0x80;
		_delay_ms(100)	;
		PORTA = 0x00;
		_delay_ms(100)	;
		
		
	}
	
	return 0;
}