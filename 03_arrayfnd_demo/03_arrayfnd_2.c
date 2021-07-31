/*
	title   : ArrayFND 동작 제어 2
	subject : ArrayFND를 2자리씩 분리하여(min, sec) 0~60까지 숫자를 1초 간격으로 출력하는 프로그램(59:59 -> 00:00) LV.3
	note    : 1. ArrayFND 선택선은 0일때 선택된다.
	          2. Atmega128 Kit에 ArrayFND 사용 시 data(데이터선):A PORT, com(선택선):C PORT 으로 셋팅되어있다.
*/
#include "03_arrayfnd.h"

void main(void)
{
	unsigned char min = 0;
	unsigned char sec = 0;
	unsigned char i;

	DDR_FND = 0xFF;
	PORT_FND = 0x00;

	DDR_COM = 0x0F; //4가닥만 사용하니까 
	PORT_COM = 0x0F; //초기값 1111 선택선x


	for(;;) 
	{
		for(i=0;i<50;i++) //(50ms*5ms)*4개 = 가장 안정적인 1초(1000ms)
		{		
			PORT_COM = 0x0E;
			PORT_FND = FND_DATA_TBL[(min / 10) % 10];
			_delay_ms(5);
				
			PORT_COM = 0x0D;
			PORT_FND = FND_DATA_TBL[(min / 1) % 10];
			_delay_ms(5);

			PORT_COM = 0x0B;
			PORT_FND = FND_DATA_TBL[(sec / 10) % 10];
			_delay_ms(5);

			PORT_COM = 0x07;
			PORT_FND = FND_DATA_TBL[(sec / 1) % 10];
			_delay_ms(5);
		}

		sec++;

		if(sec > 59)
		{
			sec = 0;
			min++;
			if(min > 59) min = 0;
		}
	}

	return 0;
}
 
