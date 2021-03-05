
/*
//PC PWM을 이용하여 LED0를 버튼(BT0)을 클릭하면 10% 밝기가 감소하고,
버튼(BT1)을 누르면 10%밝기가 증가하는 프로그램 작성하라

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
SIGNAL(SIG_INTERRUPT0)  //밝기 감소 
{	
	if((bright+25)<=255) bright+=25;
	else bright=255;
}
SIGNAL(SIG_INTERRUPT1)  //밝기 증가 
{	
	if((bright-25)>=0) bright-=25;
	else bright=0;
}

int main(void)
{
	DDRB = 0x10;  //0b0001 0000//PORTB 4번 pin -> OC0를 출력모드로설정
	DDRD = 0x00;  //인터럽트 입력포트

	EIMSK=(1<<INT0)|(1<<INT1);
	EICRA=(1<<ISC01)|(1<<ISC00)|(1<<ISC11)|(1<<ISC10);

	TCCR0 = (0<<WGM01)|(1<<WGM00)|(1<<COM01)|(1<COM00)|(0<<CS02)|(0<<CS01)|(1<<CS00);
	TCNT0 = 1;
	TIMSK = (0<<OCIE0)|(1<<TOIE0);  //overflow 인터럽트 사용

	sei();

	for(;;)
	{
		OCR0=bright;
		delay_s(10);
	}
	return 1;
}
