/*
	title   : Internal Interrupt ���� ���� demo
	subject : Internal Interrupt�� Normal Mode(OVERFLOW) ����Ͽ� LED�� �����ϴ� ���α׷� LV.1
	note    : 1. Normal Mode ���� TCNTn ���� �����Ͽ� Overflow �� �� ���ͷ�Ʈ �Ǵ� ����̴�.
	          2. TIMSK = (0 << OCIE0) | (1 << TOIE0); //Normal Mode, 
			     TIMSK = (1 << OCIE0) | (0 << TOIE0); //CTC Mode
*/
/*
#include "05_internal_interrupt.h"

volatile unsigned int tic_time; //����� 24������� ���� unsigned

ISR(TIMER0_OVF_vect) //SIGNAL(SIG_OVERFLOW0)
{
	tic_time++;
	TCNT0 = 256 - (16000000 / 128 / 1000); //(125,000 / 1000) = 125 //TCNT0 �ʱⰪ : 131
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

	TCCR0 = (1 << CS02) | (0 << CS01) | (1 << CS00); //Normal Mode default, 128 prescalling
	TCNT0 = 256 - (16000000 / 128 / 1000); //131
	TIMSK = (0 << OCIE0) | (1 << TOIE0); //Set Interrupt when Overflow

	sei();

	for(;;)
	{
		led_status = ~led_status;
		PORTD = led_status;

		delay_s(1000); //1��
	}

	return 1;
}
*/
