/*
	title   : ArrayFND 동작 제어 demo
	subject : ArrayFND에 '2021' 숫자를 출력하는 프로그램 LV.1
	note    : 1. ArrayFND 선택선은 0일때 선택된다.
	          2. Atmega128 Kit에 ArrayFND 사용 시 data(데이터선):A PORT, com(선택선):C PORT 으로 셋팅되어있다.
*/
#include "03_arrayfnd.h"

void main(void)
{
	DDR_FND = 0xFF;
	PORT_FND = 0x00;

	DDR_COM = 0x0F; //4가닥만 사용하니까 
	PORT_COM = 0x0F; //초기값 1111 선택선x

	while(1)
	{
		PORT_COM = 0x0E;  //array_fnd 1번째 칸 0000 1110
		PORT_FND = FND_DATA_TBL[2];
		_delay_ms(1); //잔상효과
		PORT_COM = 0x0D;  //array_fnd 2번째 칸 0000 1101
		PORT_FND = FND_DATA_TBL[0];
		_delay_ms(1);
		PORT_COM = 0x0B;  //array_fnd 3번째 칸 0000 1011
		PORT_FND = FND_DATA_TBL[2];
		_delay_ms(1);
		PORT_COM = 0x07;  //array_fnd 4번째 칸 0000 0111
		PORT_FND = FND_DATA_TBL[1];
		_delay_ms(1);
	}

	return 0;
}
