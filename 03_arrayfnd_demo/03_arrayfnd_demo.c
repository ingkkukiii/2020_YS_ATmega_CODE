/*
	title   : ArrayFND ���� ���� demo
	subject : ArrayFND�� '2021' ���ڸ� ����ϴ� ���α׷� LV.1
	note    : 1. ArrayFND ���ü��� 0�϶� ���õȴ�.
	          2. Atmega128 Kit�� ArrayFND ��� �� data(�����ͼ�):A PORT, com(���ü�):C PORT ���� ���õǾ��ִ�.
*/
/*
#include "03_arrayfnd.h"

void main(void)
{
	DDR_FND = 0xFF;
	PORT_FND = 0x00;

	DDR_COM = 0x0F; //4���ڸ� ����ϴϱ� 
	PORT_COM = 0x0F; //�ʱⰪ 1111 ���ü�x

	while(1)
	{
		PORT_COM = 0x0E;  //array_fnd 1��° ĭ 0000 1110
		PORT_FND = FND_DATA_TBL[2];
		_delay_ms(1); //�ܻ�ȿ��
		PORT_COM = 0x0D;  //array_fnd 2��° ĭ 0000 1101
		PORT_FND = FND_DATA_TBL[0];
		_delay_ms(1);
		PORT_COM = 0x0B;  //array_fnd 3��° ĭ 0000 1011
		PORT_FND = FND_DATA_TBL[2];
		_delay_ms(1);
		PORT_COM = 0x07;  //array_fnd 4��° ĭ 0000 0111
		PORT_FND = FND_DATA_TBL[1];
		_delay_ms(1);
	}

	return 0;
}
*/
