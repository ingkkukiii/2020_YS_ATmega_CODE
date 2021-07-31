/*
	title   : Internal Interrupt 동작 제어 2
	subject : Internal Interrupt의 PWM Mode 사용하여 LED를 제어하는 프로그램 LV.2
	note    : 1. PWM Mode에서는 외부로 신호를 내보내야 하니 Normal Mode가 아닌 CTC Mode(Compare Match)로 셋팅한다.
			  2. PWM(Phase Correct) Mode => TCCR0 = (1<<FOC0) | (0 << WGM01) | (1 << WGM00)
			  3. (1<<FOC0) : 외부로 신호를 내보내기 위해서는 무조건 1로 setting한다.
	          4. PWM(Phase Correct) Mode, Fast PWM Mode
*/
#include "05_internal_interrupt.h"

volatile unsigned int tic_time; //양부터 24억까지만 쓸게 unsigned
int bright = 0;

ISR(TIMER0_COMP_vect) //SIGNAL(SIG_OUTPUT_COMPARE0)
{
	tic_time++;
}
void delay_s(unsigned int dsec)
{
	tic_time = 0;
	while(dsec > tic_time);
}

ISR(INT7_vect) //SIGNAL(SIG_INTERRUPT7) 
{	
	if((bright + 25) <= 255) bright += 25;
	else bright = 255; 
}
ISR(INT6_vect) //SIGNAL(SIG_INTERRUPT6) 
{	
	if((bright - 25) >= 0) bright -= 25;
	else bright = 0; 
}

int main(void)
{
	unsigned char FND_DATA_TBL[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 
                                    0x6D, 0x7D, 0x27, 0x7F, 0x6F};
	unsigned int i;

	DDRA = 0xFF;
	PORTA = 0x00;
	DDRC = 0x0F;
	PORTC = 0x0F;
	DDRB = 0xFF; //0C0은 PB4 pin Fixed
	DDRE = 0x00;	

	EIMSK = (1 << INT7) | (1 << INT6);     
	EICRB = (1 << ISC71) | (1 << ISC70) | (1 << ISC61) | (1 << ISC60); 

	TCCR0 = (1 << FOC0) | (1 << WGM01) | (1 << WGM00) | //PWM(Phase Correct) Mode
			(1 << COM01) | (0 << COM00) |               //Set OC0 on compare match when up-counting, Clear OC0 on compare match when down-counting
			(0 << CS02) | (0 << CS01) | (1 << CS00);    //No prescalling
	OCR0 = 0; //0~255 
	TIMSK = (1 << OCIE0) | (0 << TOIE0); //Set Interrupt when Compare Match 

	sei();

	for(;;)
	{
		OCR0 = bright;
		_delay_ms(1); //0.1초
		
		PORTC = 0x0D;
		PORTA = FND_DATA_TBL[(bright / 100) % 10];
		_delay_ms(1);
		
		PORTC = 0x0B;
		PORTA = FND_DATA_TBL[(bright / 10) % 10];
		_delay_ms(1);


		PORTC = 0x07;
		PORTA = FND_DATA_TBL[(bright / 1) % 10];
		_delay_ms(1);

	}

	return 1;
}
