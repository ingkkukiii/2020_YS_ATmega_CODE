/*
	title   : ArrayFND 동작 제어 1(2)
	subject : ArrayFND에 0~9999까지 숫자를 1초 간격으로 출력하는 프로그램, (해당 숫자에만 불 들어오기) LV.2
	note    : 1. ArrayFND 선택선은 0일때 선택된다.
	          2. Atmega128 Kit에 ArrayFND 사용 시 data(데이터선):A PORT, com(선택선):C PORT 으로 셋팅되어있다.
*/
#include "03_arrayfnd.h"

void main(void)
{
	unsigned char i;
	int cnt = 0;

	DDR_FND = 0xFF;
	PORT_FND = 0x00;

	DDR_COM = 0x0F; //4가닥만 사용하니까 
	PORT_COM = 0x0F; //초기값 1111 선택선x


	for(;;) 
	{
		for(i=0;i<50;i++) //(50ms*5ms)*4개 = 가장 안정적인 1초(1000ms)
		{		
			if(cnt >= 1000)
			{
				PORT_COM = 0x0E;
				PORT_FND = FND_DATA_TBL[(cnt / 1000) % 10];
			}
			_delay_ms(5);
			
			if(cnt >= 100)
			{									
				PORT_COM = 0x0D;
				PORT_FND = FND_DATA_TBL[(cnt / 100) % 10];
			}
			_delay_ms(5);

			if(cnt >= 10)
			{
				PORT_COM = 0x0B;
				PORT_FND = FND_DATA_TBL[(cnt / 10) % 10];
			}
			_delay_ms(5);

			if(cnt >= 0)
			{
				PORT_COM = 0x07;
				PORT_FND = FND_DATA_TBL[(cnt / 1) % 10];
			}
			_delay_ms(5);
		}

		cnt++;
		if(cnt > 9999) cnt = 0;
	}

	return 0;
}
