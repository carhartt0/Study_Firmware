﻿/*
 * led1.c
 *
 * Created: 2022-06-17 오전 11:46:43
 *  Author: 임경길
 */ 

#define F_CPU 7372800
#include <avr/io.h>
#include <util/delay.h>

int main()
{
	DDRA = 0xFF;	//portA를 출력으로 설정		0b 1111 1111 (2진수로 표현)
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0xFF; 
	DDRE = 0xFF;
	DDRF = 0xFF;
	DDRG = 0xFF;
	while (1)
	{
		PORTA = 0xFF;	//PORTA의 각 비트에 5V 출력
		_delay_ms(1000);
		PORTA = 0x00;
		_delay_ms(1000);
		
		PORTB = 0xFF;
		PORTC = 0xFF;
		PORTD = 0x00;
		_delay_ms(1000);
		PORTD = 0xFF;
		_delay_ms(1000);
		
		PORTE = 0xFF;
		PORTF = 0xFF;
		PORTG = 0xFF;
	}
	
	return 0;
}