/*
	title   : Interrupt ���� ���� 1
	subject : External Interrupt�� ����Ͽ� Button���� LED�� �����ϴ� ���α׷� LV.1
	note    : 1. �ܺ� ���ͷ�Ʈ�� �ִ� 8�� ���� ó���� �����ϴ�. EICRA : BTN0~3, EICRB : BTN4~7��
	          2. �ܺ� ���ͷ�Ʈ ���� PORT�� �����Ǿ� �ִ�. EICRA : BTN0~3 -> PORTD(0~3), EICRB : BTN4~7 -> PORTE(4~7)
*/
/*
#include "04_interrupt.h"

unsigned char flag = 9;
int k;

ISR(INT7_vect) //SIGNAL(SIG_INTERRUPT7)
{
	flag = 7;
	k = 7;
}
ISR(INT6_vect) //SIGNAL(SIG_INTERRUPT6)
{
	flag = 6;
	k = 0;
}

int main(void)
{
	DDR_LED = 0xFF;  //��¿� 
	DDR_BTN = 0x00;  //�Է¿�

	PORT_LED = 0x00;

	EIMSK = (1<<INT7) | (1<<INT6); //INTERRUPT BUTTON 7,6�� 
	EICRB = (1<<ISC71) | (1<<ISC70) | (1<<ISC61) | (1<<ISC60); //Rising Edge
	
	sei(); //���ͷ�Ʈ enable
 
	for(;;) 
	{
		if(flag == 6)
		{
			PORT_LED = (1<<k);
			_delay_ms(500);

			k++;
			if(k > 7) k = 0;
		}
		else if(flag == 7) 
		{
			PORT_LED = (1<<k);
			_delay_ms(500);

			k--;
			if(k < 0) k = 7;
			//{
			//	PORT_LED = 0x00;
			//	flag = 8;
			//}
		}
	}

	return 0;
}
*/
