//#include "13_Keypad_kit.h" 

/*
//블루투스모듈를 이용한 led on/off 하기 

unsigned char data;

int main()
{
	int i;
 
	DDRG = 0xFF;  //led 2개

	Init_USART();

	for(i = 0; i < 4 ;i ++ )
	{
		usart_send_byte('=');
		usart_send_byte('>');
		_delay_ms(100); //0.1초
	}

	usart_send_byte(0x0D); //CR
	usart_send_byte(0x0A); //LF //ENTER 키

	while(1)
	{
		data = usart_recv_byte(); //data 숫자 아님 문자임

		switch(data)
		{
			case '1' :  PORTG = 0x01; //문자기 때문에 '1'
						usart_send_byte('O');
						usart_send_byte('1');
						usart_send_byte(0x0D); //엔터키
						usart_send_byte(0x0A); //엔터키
						data = 0; // 아스키코드 숫자 0 = NULL
						break;

			case '2' :  PORTG = 0x02;
						usart_send_byte('O');
						usart_send_byte('2');
						usart_send_byte(0x0D);
						usart_send_byte(0x0A);
						data = 0;
						break;

			case '3' :  PORTG = 0x03;
						usart_send_byte('O');
						usart_send_byte('3');
						usart_send_byte(0x0D);
						usart_send_byte(0x0A);
						data = 0;
						break;

	 		default : break; //다른키 눌리면 아무것도 안함
		}
	}
	return 0;
}
*/
