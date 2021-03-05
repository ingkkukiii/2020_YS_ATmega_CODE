/*
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

int cnts = 0;
int cntm = 0;
int cnth = 0;
int flag = 0;

SIGNAL(SIG_INTERRUPT4) // ISR(INT4_vect)
{
	flag = 4;
}
SIGNAL(SIG_INTERRUPT5) // ISR(INT5_vect)
{
	flag = 5;
}
SIGNAL(SIG_INTERRUPT6) // ISR(INT6_vect)
{
	flag = 6;
	cnts = 0;
	cntm = 0;
	cnth = 0;
}
int main()
{
 	unsigned char FND[]={0x3F, 0x06, 0x5B, 0x4F, 0x66,
		  				 0x6D, 0x7D, 0x27, 0x7F, 0x6F};
	
 
	int i ; 
	DDRC = 0xFF;
	DDRG = 0xFF;
	DDRA = 0xFF;
	DDRB = 0xFF;
	
	EIMSK = (1<<INT6) | (1<<INT5) | (1<<INT4); //0b01110000;
	EICRB = (1<<ISC61) | (1<<ISC60) | 
			(1<<ISC51) | (1<<ISC50) | 
			(1<<ISC41) | (1<<ISC40) ; 
	
	sei();

	for(;;)
	{
		PORTA = FND[(cnts / 10) % 10];
		PORTB = FND[(cnts / 1) % 10];
		 
		for(i=0;i<50;i++)
		{
			PORTC = FND[(cnth / 10) % 10];
			PORTG = 0x0E;
			_delay_ms(5);

			PORTC = FND[(cnth / 1) % 10];
			PORTG = 0x0D;
			_delay_ms(5);

			PORTC = FND[(cntm / 10) % 10];
			PORTG = 0x0B; 
			_delay_ms(5);

			PORTC = FND[(cntm / 1) % 10];
			PORTG = 0x07;
			_delay_ms(5);
		}

		if(flag == 4)
		{
			cnts++;
			if(cnts > 59)
			{
				cntm++;
				if(cntm > 59)
				{
				cnth++;
				if(cnt > 23)
						cnth =0;
				}			
			}
//			else if(flag == 6)
//			{ 
//	 			cnts = 0;
//				cnts = 0;
//				cnts = 0;
//			}
		}
	}
	return 0;
}
*/

/*

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

int cnts = 0;
int cntm = 0;
int cnth = 0;
int flag = 0;

SIGNAL(SIG_INTERRUPT4) // ISR(INT4_vect)
{
	flag = 4;
}
SIGNAL(SIG_INTERRUPT5) // ISR(INT5_vect)
{
	flag = 5;
}
SIGNAL(SIG_INTERRUPT6) // ISR(INT6_vect)
{
	flag = 6;
	cnts = 0;
	cntm = 0;
	cnth = 0;
}

int main()
{
 	unsigned char FND[]={0x3F, 0x06, 0x5B, 0x4F, 0x66,
		  				 0x6D, 0x7D, 0x27, 0x7F, 0x6F};
	
 
	int i ; 
	DDRC = 0xFF;
	DDRG = 0xFF;
	DDRA = 0xFF;
	DDRB = 0xFF;
	
	EIMSK = (1<<INT6) | (1<<INT5) | (1<<INT4); //0b01110000;
	EICRB = (1<<ISC61) | (1<<ISC60) | 
			(1<<ISC51) | (1<<ISC50) | 
			(1<<ISC41) | (1<<ISC40) ; 
	
	sei();

	for(;;)
	{

		if(flag != 0)
	    {
			for(i=0;i<50;i++)
			{
				PORTC = FND[(cnth / 10) % 10];
				PORTG = 0x0E;
				_delay_ms(5);
	
				PORTC = FND[(cnth / 1) % 10];
				PORTG = 0x0D;
				_delay_ms(5);
	
				PORTC = FND[(cntm / 10) % 10];
				PORTG = 0x0B; 
				_delay_ms(5);
	
				PORTC = FND[(cntm / 1) % 10];
				PORTG = 0x07;
				_delay_ms(5);
				
				PORTA = FND[(cnts / 10) % 10];
		        PORTB = FND[(cnts / 1) % 10];
			}
		}

		if(flag == 4)
		{
			cnts++;
			if(cnts > 59)
			{
				cntm++;
				if(cntm > 59)
				{
					cnth++;
				
					if(cnth > 23) cnth =0; 
					 
				}			
			}
//			else if(flag == 6)
//			{ 
//	 			cnts = 0;
//				cnts = 0;
//				cnts = 0;
//			}
		}
	}
	return 0;
}
*/
