//#include "13_Keypad_kit.h" 

/*
//���������⸦ �̿��� led on/off �ϱ� 

unsigned char data;

int main()
{
	int i;
 
	DDRG = 0xFF;  //led 2��

	Init_USART();

	for(i = 0; i < 4 ;i ++ )
	{
		usart_send_byte('=');
		usart_send_byte('>');
		_delay_ms(100); //0.1��
	}

	usart_send_byte(0x0D); //CR
	usart_send_byte(0x0A); //LF //ENTER Ű

	while(1)
	{
		data = usart_recv_byte(); //data ���� �ƴ� ������

		switch(data)
		{
			case '1' :  PORTG = 0x01; //���ڱ� ������ '1'
						usart_send_byte('O');
						usart_send_byte('1');
						usart_send_byte(0x0D); //����Ű
						usart_send_byte(0x0A); //����Ű
						data = 0; // �ƽ�Ű�ڵ� ���� 0 = NULL
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

	 		default : break; //�ٸ�Ű ������ �ƹ��͵� ����
		}
	}
	return 0;
}
*/
