/*
	title   : Internal Interrupt 동작 제어 2
	subject : Internal Interrupt의 PWM Mode 사용하여 LED를 제어하는 프로그램 LV.2
	note    : 1. PWM Mode에서는 외부로 신호를 내보내야 하니 Normal Mode가 아닌 CTC Mode(Compare Match)로 셋팅한다.
			  2. PWM(Phase Correct) Mode => TCCR0 = (1<<FOC0) | (0 << WGM01) | (1 << WGM00)
			  3. (1<<FOC0) : 외부로 신호를 내보내기 위해서는 무조건 1로 setting한다.
	          4. PWM(Phase Correct) Mode, Fast PWM Mode
*/
/*
#include "05_internal_interrupt.h"

volatile unsigned int tic_time; //양부터 24억까지만 쓸게 unsigned

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

	DDRB = 0xFF; //0C0은 PB4 pin Fixed
	
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
			delay_s(1000); //1초
		}

		for(i = 255; i > 0; i--)
		{
			OCR0 = i;
			delay_s(1000); //1초
		}
	}

	return 1;
}
*/
