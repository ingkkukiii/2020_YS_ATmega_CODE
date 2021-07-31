#include "06_usart.h"

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
