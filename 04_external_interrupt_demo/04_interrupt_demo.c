/*
	title   : External Interrupt ���� ���� demo
	subject : External Interrupt�� ����Ͽ� Button���� LED�� �����ϴ� ���α׷� LV.1
	note    : 1. �ܺ� ���ͷ�Ʈ�� �ִ� 8�� ���� ó���� �����ϴ�. EICRA : BTN0~3, EICRB : BTN4~7��
	          2. �ܺ� ���ͷ�Ʈ ���� PORT�� �����Ǿ� �ִ�. EICRA : BTN0~3 -> PORTD(0~3), EICRB : BTN4~7 -> PORTE(4~7)
*/
/*
#include "04_interrupt.h"

unsigned char flag;

ISR(INT7_vect) //SIGNAL(SIG_INTERRUPT7)
{
	flag = 7;
}
ISR(INT6_vect) //SIGNAL(SIG_INTERRUPT6)
{
	flag = 6;
}
ISR(INT5_vect) //SIGNAL(SIG_INTERRUPT5)
{
	flag = 5;
}
ISR(INT4_vect) //SIGNAL(SIG_INTERRUPT4)
{
	flag = 4;
}

int main(void)
{
	DDR_LED = 0x03;  //��¿� 
	DDR_BTN = 0x00;  //�Է¿�

	PORT_LED = 0x00;

	EIMSK = (1<<INT7) | (1<<INT6) | (1<<INT5) | (1<<INT4); //INTERRUPT BUTTON 7,6,5�� 
	EICRB = (1<<ISC71) | (1<<ISC70) | (1<<ISC61) | (1<<ISC60) | 
	        (1<<ISC51) | (1<<ISC50) | (1<<ISC41) | (1<<ISC40); //Rising Edge
	
	sei(); //���ͷ�Ʈ enable
 
	for(;;) 
	{
		 if(flag == 5) PORT_LED = 0x01;
		 else if(flag == 6) PORT_LED = 0x02;
		 else if(flag == 7) PORT_LED = 0x03;
		 else PORT_LED = 0x00;
	}

	return 0;
}
*/
