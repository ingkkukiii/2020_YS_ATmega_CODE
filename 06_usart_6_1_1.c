//#include "20190603_2018100055.h"

/*
//하이퍼터미널에 'Hello Yeonsung University!'이란 문자를 출력한다(USART0 사용)

void usart_send_byte(unsigned char byte)
{
	while (!(UCSR0A & (1<<UDRE0)));
	UDR0 = byte;
}
void usart_send_string(unsigned char *str, unsigned char len)
{
	int i;

	for(i=0; i<len; i++)
	{
		usart_send_byte(str [i]);
	}
}

int main(void)
{
	unsigned char buf[] = "Hello Yeonsung University!";

	UBRR0L = (unsigned char)BAUD_RATE_L;
	UBRR0H = (unsigned char)BAUD_RATE_H;

	UCSR0B = (1<<TXEN) | (1<<RXEN) | (0<<UCSZ2);
	UCSR0C = (0<<UPM1) | (0<<UPM0) | (0<<USBS) | (1<<UCSZ1) | (1<<UCSZ0);

	usart_send_string(buf, sizeof(buf));

	return 1;
}
*/
