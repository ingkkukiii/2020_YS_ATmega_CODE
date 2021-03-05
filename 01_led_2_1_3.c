//#include "01_led.h"

/* 
//8개의 led가 왼->오 한 개씩 켜졌다 꺼진후 다시 오->왼 커졌다 꺼지기를 반복하는 프로그램(51p)

void main()
{
	int k = 0; 
	int flag = 0;

	DDRD = 0xFF;
	PORTD = 0x00;

	for(;;)	
	{
		PORTD = (1 << k);
		_delay_ms(1000);

		if(flag == 0)
		{
			k++;
	    	if(k > 7) 
			{
				flag = 1;
			};
		}
		else
		{
			k--;
			if(k < 0)
			{
				flag = 0;
			}
		}
	}
}
*/
