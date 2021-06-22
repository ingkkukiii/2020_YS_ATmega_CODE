/*
	title   : LED 동작 제어 3
	subject : 반복문을 사용하여 led가 왼->오, 오->왼 왔다갔다 1칸씩 이동하면서 켜졌다 꺼지는 동작이 반복되는 프로그램 LV.2
*/
#include "02_led.h"

int main(void)  
{
	int k = 0;
	int flag = 0;

	DDR_LED = 0xFF;  
	PORT_LED = 0x00;   

	for(;;)	
	{
		PORT_LED = (1 << k);
		_delay_ms(500);

		if(flag == 0)
		{
			k++;
	    		if(k > 6) //k값 조절 
			{
				flag = 1;
			};
		}
		else
		{
			k--;
			if(k < 1) //k값 조절
			{
				flag = 0;
			}
		}
	}
}
