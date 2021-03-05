
/*
//2단계 실습 과제에 추가하여, 현재의 OCR0의 값을 Array FND에 출력하여 확인할 수 있는 프로그램 작성 

#include <avr/io.h>
//#include <avr/delay.h>
#include <avr/interrupt.h>

volatile int bright;
volatile unsigned int tic_time;

SIGNAL(SIG_OVERFLOW0) //SIGNAL(SIG_OUTPUT_COMPARE0)
{	
	tic_time++;
	TCNT0 = 1; 
}
void delay_s(unsigned int dsec)
{	
	tic_time = 0;
	while (dsec > tic_time); 
}
SIGNAL(SIG_INTERRUPT0) 
{	
	if((bright+25) <= 255) bright+=25;
	else bright=255; 
}
SIGNAL(SIG_INTERRUPT1) 
{	
	if((bright-25) >=0) bright-=25;
	else bright=0; 
}

int main(void)
{
	unsigned char FND[]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x6F};
	int cnt = 0; 
	int i;

	DDRB = 0x10;  //0b0001 0000//PORTB 4번 pin -> OC0를 출력모드로설정
	DDRD = 0x00;  //인터럽트 입력포트

	EIMSK=(1<<INT0) | (1<<INT1);     
	EICRA=(1<<ISC01) | (1<<ISC00) | (1<<ISC11) | (1<<ISC10); 

	TCCR0 = (0<<WGM01) | (1<<WGM00) | (1<<COM01) | (1<<COM00) | (0 << CS02) | (0 << CS01) | (1 << CS00);
	TCNT0 = 1;
	TIMSK = (0 << OCIE0) | (1 << TOIE0); //(1 << OCIE0) | (0 << TOIE0);

	sei();
	 
	for (;;)
	{	
		OCR0 = bright;
		delay_s(10);
		
		for(i=0;i<25;i++) //count 변수4자리를하나로출력
		{
			PORTE = FND[(bright / 1000) % 10];
			PORTG = 0x0E;
			delay_s(1);
			PORTE = FND[(bright / 100) % 10];
			PORTG = 0x0D;
			delay_s(1);
			PORTE = FND[(bright / 10) % 10];
			PORTG = 0x0B; 
			delay_s(1);
			PORTE = FND[(bright / 1) % 10];
			PORTG = 0x07;
			delay_s(1);
		}
		cnt++;
		if(cnt > 9999) cnt = 0;
	}
	return 1;
}
*/
