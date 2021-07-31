/*
	title   : Internal Interrupt ���� ���� 2
	subject : Internal Interrupt�� PWM Mode ����Ͽ� LED�� �����ϴ� ���α׷� LV.2
	note    : 1. PWM Mode������ �ܺη� ��ȣ�� �������� �ϴ� Normal Mode�� �ƴ� CTC Mode(Compare Match)�� �����Ѵ�.
			  2. PWM(Phase Correct) Mode => TCCR0 = (1<<FOC0) | (0 << WGM01) | (1 << WGM00)
			  3. (1<<FOC0) : �ܺη� ��ȣ�� �������� ���ؼ��� ������ 1�� setting�Ѵ�.
	          4. PWM(Phase Correct) Mode, Fast PWM Mode
*/
/*
#include "05_internal_interrupt.h"

volatile unsigned int tic_time; //����� 24������� ���� unsigned

ISR(TIMER0_COMP_vect) //SIGNAL(SIG_OUTPUT_COMPARE0)
{
	tic_time++;
}
void delay_s(unsigned int dsec)
{
	tic_time = 0;
	while(dsec > tic_time);
}

int main(void)
{
	unsigned int i;

	DDRB = 0xFF; //0C0�� PB4 pin Fixed
	
	TCCR0 = (1 << FOC0) | (0 << WGM01) | (1 << WGM00) | //PWM(Phase Correct) Mode
			(1 << COM01) | (1 << COM00) |               //Set OC0 on compare match when up-counting, Clear OC0 on compare match when down-counting
			(0 << CS02) | (0 << CS01) | (1 << CS00);    //No prescalling
	OCR0 = 1; //1~255 
	TIMSK = (1 << OCIE0) | (0 << TOIE0); //Set Interrupt when Compare Match 

	sei();

	for(;;)
	{
		for(i = 1; i < 256; i++)
		{
			OCR0 = i;
			delay_s(1000); //1��
		}

		for(i = 255; i > 0; i--)
		{
			OCR0 = i;
			delay_s(1000); //1��
		}
	}

	return 1;
}
*/
