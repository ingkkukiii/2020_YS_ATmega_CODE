/*

#include <avr/io.h>
//#include <avr/delay.h>
#include <avr/interrupt.h>

volatile unsigned int tic_time; //양부터 24억까지만 쓸게 unsigned
SIGNAL(SIG_OUTPUT_COMPARE0)
{
	tic_time++;
}
void delay_s(unsigned int dsec)
{
	tic_time = 0;
	while(dsec>tic_time);
}
int main(void)
{
	unsigned int i;

	DDRB = 0x10;
	TCCR0 = (1<<FOC0)|(0<<WGM01)|(1<<WGM00)|(1<<COM01)|(1<COM00)//환했다 흐려지기//(0<com00)->흐렸다환해지기
			|(0<<CS02)|(0<<CS01)|(1<<CS00);//불빛 변화의 속도
	TCNT0 = 1;
	TIMSK = (1<<OCIE0)|(TOIE0);
	sei();

	for(;;)
	{
		for(i=1;i<255;i++)
		{
			OCR0=i;
			delay_s(100);
		}
		for(i=255;i>1;i--)
		{
			OCR0=i;
			delay_s(100);
		}
	}
	return 1;
}
*/
 
//

#include <avr/io.h>
//#include <avr/delay.h>
#include <avr/interrupt.h>

/*
volatile int bright;
volatile unsigned int tic_time; //양부터 24억까지만 쓸게 unsigned

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
SIGNAL(SIG_INTERRUPT0)
{
	if((bright+25)<=255)bright+=25;
	else bright=255;
}
SIGNAL(SIG_INTERRUPT1)
{
	if((bright-25)>=0)bright-=25;
	else bright=0;
}
int main(void)
{

	DDRB = 0x10;
	DDRD = 0x00;

	EIMSK=(1<<INT0)|(1<<INT1);
	EICRA=(1<<ISC01)|(1<<ISC00)|(1<<ISC11)|(1<<ISC10);

	TCCR0 = (0<<WGM01)|(1<<WGM00)|(1<<COM01)|(1<COM00)//환했다 흐려지기 
			|(0<<CS02)|(0<<CS01)|(1<<CS00);//불빛 변화의 속도 

	TCNT0 = 1;
	TIMSK = (0<<OCIE0)|(1<<TOIE0);
	sei();

	for(;;)
	{
		OCR0=bright;
		delay_s(10);
	}
	return 1;
}
*/

/*
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

SIGNAL(SIG_INTERRUPT0) {
	if((bright+25) <= 255) bright+=25;
	else bright=255;
}

SIGNAL(SIG_INTERRUPT1) {
	if((bright-25) >=0) bright-=25;
	else bright=0;
}

int main(void)
{
		unsigned char FND[]={0x3F, 0x06, 0x5B, 0x4F, 0x66,
		  				 0x6D, 0x7D, 0x27, 0x7F, 0x6F};

	int count = 0;
	int i;

	DDRB = 0x10;		// OC0를  출력 모드로 설정
	DDRD = 0x00;
 
	
	EIMSK=(1<<INT0) | (1<<INT1);     
	EICRA=(1<<ISC01) | (1<<ISC00) | (1<<ISC11) | (1<<ISC10); 

	TCCR0 = (0<<WGM01) | (1<<WGM00) | (1<<COM01) | (1<<COM00) | (0 << CS02) | (0 << CS01) | (1 << CS00);
	TCNT0 = 1;

	TIMSK = (0 << OCIE0) | (1 << TOIE0);	//(1 << OCIE0) | (0 << TOIE0);
	
	sei(); 
			
	for (;;)
	{
		OCR0 = bright;
		delay_s(10);
		for(i=0;i<25;i++) //count 변수 4자리를 하나로 출력 
		{
			PORTE = FND[(count / 1000) % 10];
			PORTG = 0x0E;
			delay_s(1);
	
			PORTE = FND[(count / 100) % 10];
			PORTG = 0x0D;
			delay_s(1);
	
			PORTE = FND[(count / 10) % 10];
			PORTG = 0x0B; 
			delay_s(1);
	
			PORTE = FND[(count / 1) % 10];
			PORTG = 0x07;
			delay_s(1);
		}	
		count++;
		if(count > 9999) count = 0;
	}
	
	return 1;
}
*/

//

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

SIGNAL(SIG_INTERRUPT0) {
	if((bright+25) <= 255) bright+=25;
	else bright=255;
}

SIGNAL(SIG_INTERRUPT1) {
	if((bright-25) >=0) bright-=25;
	else bright=0;
}

int main(void)
{
	unsigned char FND[]={0x3F, 0x06, 0x5B, 0x4F, 0x66,
		  				 0x6D, 0x7D, 0x27, 0x7F, 0x6F};

	int count = 0;
	int i;
	DDRB = 0x10;		// OC0를  출력 모드로 설정
	DDRD = 0x00;
	DDRC = 0xFF;
	DDRG = 0xFF;

	EIMSK=(1<<INT0) | (1<<INT1);     
	EICRA=(1<<ISC01) | (1<<ISC00) | (1<<ISC11) | (1<<ISC10); 

	TCCR0 = (0<<WGM01) | (1<<WGM00) | (1<<COM01) | (1<<COM00) | (0 << CS02) | (0 << CS01) | (1 << CS00);
	TCNT0 = 1;

	TIMSK = (0 << OCIE0) | (1 << TOIE0);	//(1 << OCIE0) | (0 << TOIE0);
	
	sei(); 
			
	for (;;)
	{
		OCR0 = bright;
		delay_s(10);
		for(i=0;i<25;i++) //count 변수 4자리를 하나로 출력 
		{
			PORTC = FND[(bright / 1000) % 10];
			PORTG = 0x0E;
			delay_s(1);
	
			PORTC = FND[(bright / 100) % 10];
			PORTG = 0x0D;
			delay_s(1);
	
			PORTC = FND[(bright / 10) % 10];
			PORTG = 0x0B; 
			delay_s(1);
	
			PORTC = FND[(bright / 1) % 10];
			PORTG = 0x07;
			delay_s(1);
		}	

	}
	return 1;
}

