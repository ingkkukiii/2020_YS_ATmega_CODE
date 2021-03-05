
/*
//ctc모드

#include <avr/io.h>
//#include <avr/delay.h>
#include <avr/interrupt.h>

volatile unsigned int tic_time; //양부터 24억까지만 쓸게 unsigned
SIGNAL(SIG_OUTPUT_COMPARE0) //ISR(TIMER0_COMP_vect) //133p
{
	tic_time++;
}
void delay_s(int dsec)
{
	tic_time = 0;
	while(dsec > tic_time);
}
int main()
{
	unsigned char FND[]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x6F};

	int count = 0;

	DDRB = 0xFF;
	
 	TCCR0 = (1<<WGM01) | (0<<WGM00) | (1<<CS02) | (1<<CS01) | (1<<CS00);
	TIMSK = (1<<OCIE0) | (0<<TOIE0);  //ctc 인터럽트 사용 
	OCR0 = 72; //0부터 72까지 //7372800/100/1024;
	
	sei();

	for(;;)
	{
 		PORTB = FND[count];
		count++;
		if(count > 9) count = 0;
		delay_s(100);
	}
		
	return 0;
}
*/
