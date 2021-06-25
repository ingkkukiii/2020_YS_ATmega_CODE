#include "20190603_2018100055.h"

int main(void)
{
	int k = 0;
	unsigned char byte;
	
	unsigned char buf1[] = "1. LED동시 점등 TEST\r\n";
	unsigned char buf2[] = "2. LED동시 점등 TEST\r\n";
	unsigned char buf3[] = "Input number(1-2) : ";

	DDRA = 0xFF;  //LED출력포트
	PORTA = 0x00;
	
	usart_init();
	
   	for(;;)
	{
		usart_send_string(buf1, sizeof(buf1));   
	   	usart_send_string(buf2, sizeof(buf2));
	    	usart_send_string(buf3, sizeof(buf3));
	
		byte = usart_recv_byte();   
		
		usart_send_byte(byte); 
		
		if(byte == '1')
		{
			PORTA = 0xFF;
			_delay_ms(1000);
			PORTA = 0x00;
		}
		
		else if(byte == '2')
		{
			PORTA = 0x00;
			for(k = 0; k < 8; k++)
			{
				PORTA = (1 << k);
				_delay_ms(125);
			}
			PORTA = 0x00;
		}

		usart_send_byte('\r');
		usart_send_byte('\n');
	}
	
	return 1;
}

/*
//메뉴를 만들어 LED를 동작시키는 프로그램을 작성하라 

int main(void)
{
	unsigned char buf1[] = "1. LED동시 점등 TEST\r\n";
	unsigned char buf2[] = "2. LED동시 점등 TEST\r\n";
	unsigned char buf3[] = "Input number(1-2) : ";
    
	unsigned char byte; //1
	int i; 

	UBRR0L = (unsigned char)BAUD_RATE_L;
	UBRR0H = (unsigned char)BAUD_RATE_H;

	UCSR0B = (1<<TXEN) | (1<<RXEN) | (0<<UCSZ2);
	UCSR0C = (0<<UPM1) | (0<<UPM0) | (0<<USBS) | (1<<UCSZ1) | (1<<UCSZ0);

    DDRA = 0xFF;  //LED출력포트

    for(;;)
	{
		usart_send_string(buf1, sizeof(buf1));  //제목이 출력 
	    usart_send_string(buf2, sizeof(buf2));
	    usart_send_string(buf3, sizeof(buf3));
	
		byte = usart_recv_byte();  //들어오기만 한거 바이트에 저장  
		usart_send_byte(byte);  //숫자가 써짐 
	
		switch(byte)
		{
			case '1':  //키보드 문자 1
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
