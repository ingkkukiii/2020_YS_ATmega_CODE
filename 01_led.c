//#include "01_led.h"

/*
//2진수 

void main()
{
	DDRD = 0xFF;
	PORTD = 0x00;

	PORTD = 0b00000001;
	_delay_ms(1000);  //천분의 천 = 1초

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
//led 8개가 동시에 켜졌다 1초후 꺼지는 프로그램 

void main()  
{
	DDRD = 0xFF;


	PORTD = 0xFF;
	_delay_ms(1000);
	PORTD = 0x00;

}
*/


/*
//반복문 while 사용하여 반복해서 출력하기 
//led8개가 4개씩 나눠서 켜졌다 꺼졌다 반복하기

void main()  
{
	DDRD = 0xFF;

	while(1)
	{
	    PORTD = 0x0F;
		//눈으로 확인할수 없는 시간지연
		PORTD = 0xF0;
	}
}
*/


/*
//반복문 while 사용하여 반복해서 출력하기 
//led8개가 4개씩 나눠서 켜졌다 꺼졌다 반복하기

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
//변수 사용하기 

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

  


