/*
	title   : External Interrupt 동작 제어 demo
	subject : External Interrupt를 사용하여 Button으로 LED를 제어하는 프로그램 LV.1
	note    : 1. 외부 인터럽트는 최대 8개 까지 처리가 가능하다. EICRA : BTN0~3, EICRB : BTN4~7번
	          2. 외부 인터럽트 사용시 PORT는 지정되어 있다. EICRA : BTN0~3 -> PORTD(0~3), EICRB : BTN4~7 -> PORTE(4~7)
*/
#include "04_interrupt.h"

unsigned char flag;  
unsigned char min = 0; int sec = 0;

ISR(INT7_vect) //SIGNAL(SIG_INTERRUPT7) 
{
	//TIMER ADD
	flag = 7;
}
ISR(INT6_vect) //SIGNAL(SIG_INTERRUPT6) 
{
	//TIMER STOP	
	flag = 6; 
}
ISR(INT5_vect) //SIGNAL(SIG_INTERRUPT5) 
{
	//TIMER RESET
	flag = 5;
	min = 0; 
	sec = 0; 
}

void main()
{
	unsigned char FND_DATA_TBL[]={0x3F, 0x06, 0x5B, 0x4F, 0x66,0x6D, 0x7D, 0x27, 0x7F, 0x6F};
	unsigned char i; 
	
	DDRA = 0xFF; //ArrayFND DATA 
	DDRC = 0x0F; //ArrayFND COM

	DDRE = 0x00; //BTN(7,6,5)
    	
	EIMSK = (1<<INT7) | (1<<INT6) | (1<<INT5);
	EICRB = (1<<ISC71) | (1<<ISC70) | (1<<ISC61) | (1<<ISC60) | (1<<ISC51) | (1<<ISC50);
	
	sei();
	
	for(;;)
	{		
			for(i=0;i<50;i++)
			{
				PORTC = 0x0E;		
				PORTA = FND_DATA_TBL[(min / 10) %10];
				_delay_ms(5);

				PORTC = 0x0D;    			
	 			PORTA = FND_DATA_TBL[(min / 1) %10];
				_delay_ms(5);

				PORTC = 0x0B;
				PORTA = FND_DATA_TBL[(sec / 10) %10];
				_delay_ms(5);

				PORTC = 0x07;    			
				PORTA = FND_DATA_TBL[(sec / 1) %10];
				_delay_ms(5);
			}

			if(flag == 7)
			{
	 			sec++;
	       		
				if(sec>59)
	   			{
					sec = 0;
	       			min++;
	 	   	 	
					if(min > 59)
					{
						min = 0;
	   					//hour++;
						//if(hour > 23) hour = 0;
	 				}
		  		}
	 		}
	}
}
