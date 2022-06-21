/*
 * UART.c
 *
 * Created: 2022-06-21 오전 9:36:47
 * Author : PKNU
 */ 

#include <avr/io.h>

void putch(unsigned char data)
{
	while((UCSR0A & 0x20) == 0);		//전송준비가 될때까지 대기
	UDR0 = data;						//데이터를 UDR0에 쓰면 전송
	UCSR0A |= 0x20;
}

int main(void)
{
    unsigned char text[] = "Hello! World!! \r\n";
	unsigned char i = 0;
	
	DDRE = 0xfe;		//Rx(입력 0), Tx(출력 1)
	UCSR0A = 0x00;
	UCSR0B = 0x18;
	UCSR0C = 0x06;
	
	UBRR0H = 0x00;
	UBRR0L = 3;
	
    while (text[i] != '\0') 
    {
		putch(text[i++]);
    }
}

