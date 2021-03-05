//#include "20190603_2018100055.h"

/*
//��ǻ�� Ű����� �Է��� ���ڸ� �������͹̳ο� �����ִ� ���α׷��� �ۼ��϶�

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
unsigned char usart_recv_byte(void)
{
	while(!(UCSR0A&(1<<RXC0)));

	return UDR0;
}

int main(void)
{
	unsigned char byte;

	UBRR0L = (unsigned char)BAUD_RATE_L;
	UBRR0H = (unsigned char)BAUD_RATE_H;

	UCSR0B = (1<<TXEN) | (1<<RXEN) | (0<<UCSZ2);
	UCSR0C = (0<<UPM1) | (0<<UPM0) | (0<<USBS) | (1<<UCSZ1) | (1<<UCSZ0);

	for(;;)
	{	
		byte = usart_recv_byte();
		switch(byte)
		{
			case CR:  //enter key 
				usart_send_byte('\r');
				usart_send_byte('\n');
				break;
			case BS:  //back space
				usart_send_byte(byte);
				usart_send_byte(' ');
				usart_send_byte(byte);
				break;
			default:
				usart_send_byte(byte);
				break;
		}
	}
	return 1;
}
*/
