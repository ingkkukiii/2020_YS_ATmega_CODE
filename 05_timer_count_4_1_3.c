
/*
//overflow 인터럽트를 이용하여 0~9999까지 1초 간격으로 증가하게 하라 
//9999가 되면 0에서부터 새롭게 카운트된다

#include <avr/io.h>
//#include <avr/delay.h>
#include <avr/interrupt.h>

int tic_time;
SIGNAL(SIG_OUTPUT_COMPARE0) //ISR(TIMER0_COMP_vect)
{	tic_time++;
	TCNT0 = 184; //256-72; 
}

void delay_s(int dsec)
{	tic_time = 0;
	while(dsec > tic_time); 
}

int main()
{
	unsigned char FND[]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x6F};
	int count = 0;
	int i;

	DDRC = 0xFF;  //PC0~PC7 과 Array FND A~H 연결
	DDRG = 0xFF;  //PG0~PG3 과 Array FND C0~C3 연결

 	TCCR0 = (1<<CS02) | (1<<CS01) | (1<<CS00);
	TIMSK = (0<<OCIE0) | (1<<TOIE0);  //overflow 인터럽트 사용 
	TCNT0 = 184;       
	
	sei();

	for(;;)
	{
 		for(i=0;i<25;i++) //count 변수 4자리를 하나로 출력 
		{	
			PORTC = FND[(count / 1000) % 10];
			PORTG = 0x0E;
			delay_s(1);
			PORTC = FND[(count / 100) % 10];
			PORTG = 0x0D;
			delay_s(1);
			PORTC = FND[(count / 10) % 10];
			PORTG = 0x0B; 
			delay_s(1);
			PORTC = FND[(count / 1) % 10];
			PORTG = 0x07;
			delay_s(1);
		}	
		count++;
		if(count > 9999) count = 0;
	}	
	return 0;
}
*/
