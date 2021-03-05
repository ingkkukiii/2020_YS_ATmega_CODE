//#include "01_led.h"

/*  
//8개의 led가 왼쪽에서 오른쪽으로 이동하면서 하나씩 켰다 꺼지는 것을 보여주는 프로그램(49p)

void main()   
{
	int k = 0; 

	DDRD = 0xFF;  //led 포트를 출력모드로 set
	PORTD = 0x00;  //led 포트 초기화

	for(;;)	
	{
		PORTD = (1 << k);
		
//		k++;
//	    if(k > 7) k= 0;
		
		if(++k > 7) k = 0;

		_delay_ms(1000);
	}
}
*/


/*
void main()
{
	int k = 0;

	DDRD = 0xFF;
	PORTD = 0x00;

	for(k=0;k<8;k++)	
	{
		PORTD = (1 << k);
		_delay_ms(1000);
	}
	PORTD = 0x00;
}
*/
