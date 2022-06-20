/*
 * input1.c
 *
 * Created: 2022-06-17 오후 3:20:07
 *  Author: PKNU
 */ 
#define  F_CPU 7432800UL
#include <avr/io.h>
#include <util/delay.h>

int main()
{
	DDRD = 0x00;		// 포트 D 입력으로 설정
	DDRA = 0xFF;		// 포트 A 출력으로 설정
	while(1)
	{
			 PORTA = PIND;	//포트D 입력값이 0x01이면 포트A의 0번비트를 출력
		
	}
	
	return 0;
}