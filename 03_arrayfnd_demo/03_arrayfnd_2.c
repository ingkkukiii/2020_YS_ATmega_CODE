/*
	title   : ArrayFND ���� ���� 2
	subject : ArrayFND�� 2�ڸ��� �и��Ͽ�(min, sec) 0~60���� ���ڸ� 1�� �������� ����ϴ� ���α׷�(59:59 -> 00:00) LV.3
	note    : 1. ArrayFND ���ü��� 0�϶� ���õȴ�.
	          2. Atmega128 Kit�� ArrayFND ��� �� data(�����ͼ�):A PORT, com(���ü�):C PORT ���� ���õǾ��ִ�.
*/
#include "03_arrayfnd.h"

void main(void)
{
	unsigned char min = 0;
	unsigned char sec = 0;
	unsigned char i;

	DDR_FND = 0xFF;
	PORT_FND = 0x00;

	DDR_COM = 0x0F; //4���ڸ� ����ϴϱ� 
	PORT_COM = 0x0F; //�ʱⰪ 1111 ���ü�x


	for(;;) 
	{
		for(i=0;i<50;i++) //(50ms*5ms)*4�� = ���� �������� 1��(1000ms)
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
 
