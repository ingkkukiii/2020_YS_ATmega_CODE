/*
	title   : LED ���� ����
	subject : �ݺ����� ����Ͽ� led 8���� ���ÿ� ������ 1���� ������ ������ �ݺ��Ǵ� ���α׷� LV.2
*/
/*
#include "02_led.h"

int main(void)  
{
	int i;
    unsigned char led_status = 0x00;

	DDR_LED = 0xFF;
	PORT_LED = led_status;

	for(i=0;i<10;i++)
	{
		led_status = ~led_status;

		PORT_LED = led_status;
		_delay_ms(1000);
	}

	return 0;
}
*/
