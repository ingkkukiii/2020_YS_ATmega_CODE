#include "20190603_2018100055.h"

/*
//�޴��� ����� LED�� ���۽�Ű�� ���α׷��� �ۼ��϶� 

int main(void)
{
	unsigned char buf1[] = "1. LED���� ���� TEST\r\n";
	unsigned char buf2[] = "2. LED���� ���� TEST\r\n";
	unsigned char buf3[] = "Input number(1-2) : ";
    
	unsigned char byte; //1
	int i; 

	UBRR0L = (unsigned char)BAUD_RATE_L;
	UBRR0H = (unsigned char)BAUD_RATE_H;

	UCSR0B = (1<<TXEN) | (1<<RXEN) | (0<<UCSZ2);
	UCSR0C = (0<<UPM1) | (0<<UPM0) | (0<<USBS) | (1<<UCSZ1) | (1<<UCSZ0);

    DDRA = 0xFF;  //LED�����Ʈ

    for(;;)
	{
		usart_send_string(buf1, sizeof(buf1));  //������ ��� 
	    usart_send_string(buf2, sizeof(buf2));
	    usart_send_string(buf3, sizeof(buf3));
	
		byte = usart_recv_byte();  //�����⸸ �Ѱ� ����Ʈ�� ����  
		usart_send_byte(byte);  //���ڰ� ���� 
	
		switch(byte)
		{
			case '1':  //Ű���� ���� 1
				PORTA = 0xFF;
				_delay_ms(1000);
				PORTA = 0x00;
				break;
			case '2':
				PORTC = 0x00;
				for(i=0;i<8;i++)
				{
					PORTA = (1<<i);
					_delay_ms(500);
				}
				PORTC = 0x00;
				break;
			default:
				usart_send_byte(byte);
				break;
		}

		usart_send_byte('\r');
		usart_send_byte('\n');
	}
	return 1;
}
