/*
	title   : ArrayFND ���� ���� 1
	subject : ArrayFND�� 0~9999���� ���ڸ� 1�� �������� ����ϴ� ���α׷� LV.2
	note    : 1. ArrayFND ���ü��� 0�϶� ���õȴ�.
	          2. Atmega128 Kit�� ArrayFND ��� �� data(�����ͼ�):A PORT, com(���ü�):C PORT ���� ���õǾ��ִ�.
*/
/*
#include "03_arrayfnd.h"

void main(void)
{
	unsigned char i;
	int cnt = 0;

	DDR_FND = 0xFF;
	PORT_FND = 0x00;

	DDR_COM = 0x0F; //4���ڸ� ����ϴϱ� 
	PORT_COM = 0x0F; //�ʱⰪ 1111 ���ü�x


	for(;;) 
	{
		for(i=0;i<50;i++) //(50ms*5ms)*4�� = ���� �������� 1��(1000ms)
		{		
			PORT_COM = 0x0E;
			PORT_FND = FND_DATA_TBL[(cnt / 1000) % 10];
			_delay_ms(5);
				
			PORT_COM = 0x0D;
			PORT_FND = FND_DATA_TBL[(cnt / 100) % 10];
			_delay_ms(5);

			PORT_COM = 0x0B;
			PORT_FND = FND_DATA_TBL[(cnt / 10) % 10];
			_delay_ms(5);

			PORT_COM = 0x07;
			PORT_FND = FND_DATA_TBL[(cnt / 1) % 10];
			_delay_ms(5);
		}
		cnt++;
		if(cnt > 9999) cnt = 0;
	}

	return 0;
}
*/

