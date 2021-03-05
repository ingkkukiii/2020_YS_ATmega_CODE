//#include "04_interrupt.h"

/*
void main()
{
	int k = 0; 
	int flag = 0;

	DDRD = 0xFF;
	PORTD = 0x00;

	for(;;)	
	{
		PORTD = (1 << k);
		_delay_ms(1000);

		if(flag == 0)
		{
			k++;
	    	if(k > 7) 
			{
				flag = 1;
			};
		}
		else
		{
			k--;
			if(k < 0)
			{
				flag = 0;
			}
		}
	}
}
*/

/*
//BUTTONn왼쪽부터 LED가 순차적 점멸 , BUTTONn오른쪽부터 LED가 순차적 점멸
 
#define DDR_LED DDRC
#define PORT_LED PORTC
#define PIN_LED PINC

#define DDR_KEY DDRD
#define PORT_KEY PORTD
#define PIN_KEY PIND

volatile char int_flag;
volatile int k;

SIGNAL(SIG_INTERRUPT7) 
{
		int_flag=1;k=0;
}
SIGNAL(SIG_INTERRUPT6) 
{
		int_flag=2;k=7;
}

int main(void)
{
		DDR_LED=0xFF;
		PORT_LED=0x00;
		DDR_KEY=0x00;

		EIMSK=(1<<INT7) | (1<<INT6); 
		EICRB=(1<<ISC71) | (1<<ISC70) | (1<<ISC61) | (1<<ISC60);

		sei();

		for(;;)
		{
		  	if(int_flag==1)
			{
				PORT_LED=(1<<k);
				_delay_ms(1000);
				if(++k>8)
				{
					int_flag=0;
					PORT_LED=0x00;
				}
			}
			else if (int_flag ==2)
			{
				PORT_LED=(1<<k);
				_delay_ms(1000);
				if(--k<0)
				{
					int_flag=0;
					PORT_LED=0x00;
				}
			}
		
		}
		return 1;
}
