//#include "01_led.h"

/*
//2���� 

void main()
{
	DDRD = 0xFF;
	PORTD = 0x00;

	PORTD = 0b00000001;
	_delay_ms(1000);  //õ���� õ = 1��

	PORTD = 0b00000010;
	_delay_ms(1000);

	PORTD = 0b00000100;
	_delay_ms(1000);

	PORTD = 0b00001000;
	_delay_ms(1000);

	PORTD = 0b00010000;
	_delay_ms(1000);

    PORTD = 0b00100000;
	_delay_ms(1000);

    PORTD = 0b01000000;
	_delay_ms(1000);

	PORTD = 0b10000000;
	_delay_ms(1000);
}
*/


/*
//led 8���� ���ÿ� ������ 1���� ������ ���α׷� 

void main()  
{
	DDRD = 0xFF;


	PORTD = 0xFF;
	_delay_ms(1000);
	PORTD = 0x00;

}
*/


/*
//�ݺ��� while ����Ͽ� �ݺ��ؼ� ����ϱ� 
//led8���� 4���� ������ ������ ������ �ݺ��ϱ�

void main()  
{
	DDRD = 0xFF;

	while(1)
	{
	    PORTD = 0x0F;
		//������ Ȯ���Ҽ� ���� �ð�����
		PORTD = 0xF0;
	}
}
*/


/*
//�ݺ��� while ����Ͽ� �ݺ��ؼ� ����ϱ� 
//led8���� 4���� ������ ������ ������ �ݺ��ϱ�

void main()
{
	DDRD = 0xFF;

	while(1)
	{
	    PORTD = 0x0F;
		_delay_ms(500);  

		PORTD = 0xF0;
		_delay_ms(500); 
	}
}
*/


/*
//���� ����ϱ� 

void main()
{
    unsigned char a = 0xF0;

	DDRD = 0xFF;

	while(1)
	{
	    PORTD = a;
		_delay_ms(500);  

		PORTD = ~a;
		_delay_ms(500); 
	}
}
*/


/*
void main()
{
    unsigned char a = 0xF0;

	DDRD = 0xFF;

	while(1)
	{
		a = ~a;
		PORTD = a;
		_delay_ms(500);
	}
}
*/


/*
void main()
{
    unsigned char led_status = 0xF0;

	DDR_LED = 0xFF;

	while(1)
	{
	    PORT_LED = led_status;

		_delay_ms(500); 

		PORT_LED = ~led_status;

		_delay_ms(500); 
	}
}
*/


/*
void main()
{
    unsigned char led_status = 0xF0;

	DDR_LED = 0xFF;

	while(1)
	{
		led_status = ~led_status;

		PORT_LED = led_status;

		_delay_ms(500);
	}
}
*/

  


