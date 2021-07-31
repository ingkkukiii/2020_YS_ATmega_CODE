/*
	title   : Internal Interrupt 동작 제어 1
	subject : Internal Interrupt의 CTC Mode 사용하여 LED를 제어하는 프로그램 LV.1
	note    : 1. CTC Mode 사용시 OCRn 값을 셋팅하여 TCNTn 값과 비교 하게 된다.
	          2. TCCRn = (1 << WGM01) | (0 << WGM00) 셋팅이 필요하다.
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
	unsigned char led_status = 0x00;

	DDRD = 0xFF;
	PORTD = led_status;

	TCCR0 = (1 << WGM01) | (0 << WGM00) | (1 << CS02) | (0 << CS01) | (1 << CS00); //CTC Mode, 128 prescalling
	OCR0 = 125; //(16000000 / 128 / 1000), 1/1000초 마다 인터럽트 발생
	TIMSK = (1 << OCIE0) | (0 << TOIE0); //Set Interrupt when Compare Match 

	sei();

	for(;;)
	{
		led_status = ~led_status;
		PORTD = led_status;

		delay_s(1000); //1초
	}

	return 1;
}
*/
