/*
	title   : Interrupt 동작 제어 1
	subject : External Interrupt를 사용하여 Button으로 LED를 제어하는 프로그램 LV.1
	note    : 1. 외부 인터럽트는 최대 8개 까지 처리가 가능하다. EICRA : BTN0~3, EICRB : BTN4~7번
	          2. 외부 인터럽트 사용시 PORT는 지정되어 있다. EICRA : BTN0~3 -> PORTD(0~3), EICRB : BTN4~7 -> PORTE(4~7)
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
	DDR_LED = 0xFF;  //출력용 
	DDR_BTN = 0x00;  //입력용

	PORT_LED = 0x00;

	EIMSK = (1<<INT7) | (1<<INT6); //INTERRUPT BUTTON 7,6번 
	EICRB = (1<<ISC71) | (1<<ISC70) | (1<<ISC61) | (1<<ISC60); //Rising Edge
	
	sei(); //인터럽트 enable
 
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
