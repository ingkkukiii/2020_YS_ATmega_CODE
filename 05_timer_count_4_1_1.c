
/*
//overflow모드 

#include <avr/io.h>
//#include <avr/delay.h>
#include <avr/interrupt.h>  
 
int tic_time;
SIGNAL(SIG_OUTPUT_COMPARE0) //ISR(TIMER0_COMP_vect)
{
	tic_time++;
	TCNT0 = 184; //256-72;//256-(cpu클락/100/1024);
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
	
 	TCCR0 = (1<<CS02) | (1<<CS01) | (1<<CS00);
	TIMSK = (0<<OCIE0) | (1<<TOIE0);  //overflow모드 
	TCNT0 = 184;         
	
	sei();

	for(;;)
	{
 		PORTB = FND[count];
		count++;
		if(count > 9) count = 0;
		delay_s(100); //1초마다 1씩증가
	}
		
	return 0;
}
*/
