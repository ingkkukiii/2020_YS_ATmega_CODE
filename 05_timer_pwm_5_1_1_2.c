
/*
//Overflow Interrupt ���

#include <avr/io.h>
//#include <avr/delay.h>
#include <avr/interrupt.h>

volatile unsigned int tic_time;  

SIGNAL(SIG_OUTPUT_COMPARE0)
{
	tic_time++;
	TCNT0 = 1;
}
void delay_s(unsigned int dsec)
{	
	tic_time = 0;
	while(dsec>tic_time);
}

int main(void)
{
	unsigned int i;

	DDRB = 0x10;  //0b0001 0000//PORTB 4�� pin -> OC0�� ��¸��μ���

	TCCR0 = (1<<FOC0)|(0<<WGM01)|(1<<WGM00)|(1<<COM01)|(1<COM00)|(0<<CS02)|(0<<CS01)|(1<<CS00); 
	TCNT0 = 1;
	TIMSK = (0<<OCIE0)|(1<<TOIE0);

	sei();

	for(;;)
	{
		for(i=1;i<255;i++)  //ocr ���, ��Ƽ �ϰ� -> ��ο����� 
		{
			OCR0=i;
			delay_s(100);
		}
		for(i=255;i>1;i--)  //ocr �ϰ�, ��Ƽ ��� -> �������
		{
			OCR0=i;
			delay_s(100);
		}
	}
	return 1;
}
*/
