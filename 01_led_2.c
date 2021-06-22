/*
	title   : LED 동작 제어 2
	subject : 반복문을 사용하여 led가 왼쪽에서 오른쪽으로 1칸씩 이동하면서 켜졌다 꺼지는 동작이 반복되는 프로그램 LV.1
*/
#include "02_led_demo.h"

int main(void)  
{
	int k = 0; 
	DDR_LED = 0xFF;  
	PORT_LED = 0x00;   

	for(;;)	
	{
		for(k=0;k<8;k++)	
		{
			PORT_LED = (1 << k);
			_delay_ms(1000);
		}
		//PORT_LED = 0x00;
		//_delay_ms(1000);
	}
}
