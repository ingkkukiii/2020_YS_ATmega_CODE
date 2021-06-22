/*
	title   : LED 동작 제어
	subject : 반복문을 사용하여 led 8개가 동시에 켜졌다 1초후 꺼지는 동작이 반복되는 프로그램 LV.1
*/
#include "02_led_demo.h"

int main(void)  
{
	DDR_LED = 0xFF;
	PORT_LED = 0x00;

	while(1)
	{
		PORT_LED = 0xFF;
		_delay_ms(1000);

		PORT_LED = 0x00;
		_delay_ms(1000);
	}

	return 0;
}
