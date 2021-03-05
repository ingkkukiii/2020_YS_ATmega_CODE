
/*
//PC PWM�� �̿��Ͽ� LED0�� ��ư(BT0)�� Ŭ���ϸ� 10% ��Ⱑ �����ϰ�,
��ư(BT1)�� ������ 10%��Ⱑ �����ϴ� ���α׷� �ۼ��϶�

#include <avr/io.h>
//#include <avr/delay.h>
#include <avr/interrupt.h>

volatile int bright;  //volatile unsigned int bright;
volatile unsigned int tic_time; 

SIGNAL(SIG_OVERFLOW0)
{	
	tic_time++;
	TCNT0 = 1;
}
void delay_s(unsigned int dsec)
{	
	tic_time = 0;
	while(dsec>tic_time);
}
SIGNAL(SIG_INTERRUPT0)  //��� ���� 
{	
	if((bright+25)<=255) bright+=25;
	else bright=255;
}
SIGNAL(SIG_INTERRUPT1)  //��� ���� 
{	
	if((bright-25)>=0) bright-=25;
	else bright=0;
}

int main(void)
{
	DDRB = 0x10;  //0b0001 0000//PORTB 4�� pin -> OC0�� ��¸��μ���
	DDRD = 0x00;  //���ͷ�Ʈ �Է���Ʈ

	EIMSK=(1<<INT0)|(1<<INT1);
	EICRA=(1<<ISC01)|(1<<ISC00)|(1<<ISC11)|(1<<ISC10);

	TCCR0 = (0<<WGM01)|(1<<WGM00)|(1<<COM01)|(1<COM00)|(0<<CS02)|(0<<CS01)|(1<<CS00);
	TCNT0 = 1;
	TIMSK = (0<<OCIE0)|(1<<TOIE0);  //overflow ���ͷ�Ʈ ���

	sei();

	for(;;)
	{
		OCR0=bright;
		delay_s(10);
	}
	return 1;
}
