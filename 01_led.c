include "01_led.h"

//led 8개가 동시에 켜졌다 1초후 꺼지는 프로그램 LV.1 
int main(void)  
{
	DDR_LED = 0xFF;
	PORT_LED = 0x00;

	for(;;)
	{
		PORT_LED = 0xFF;
		_delay_ms(1000);

		PORT_LED = 0x00;
		_delay_ms(1000);
	}

	return 0;
}
