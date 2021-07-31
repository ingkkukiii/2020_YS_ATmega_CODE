/*
	title   : Interrupt 동작 제어 1
	subject : External Interrupt를 사용하여 Button으로 LED를 제어하는 프로그램 LV.1
	note    : 1. 외부 인터럽트는 최대 8개 까지 처리가 가능하다. EICRA : BTN0~3, EICRB : BTN4~7번
	          2. 외부 인터럽트 사용시 PORT는 지정되어 있다. EICRA : BTN0~3 -> PORTD(0~3), EICRB : BTN4~7 -> PORTE(4~7)
*/
/*
#include "04_interrupt.h"

unsigned char flag;  

ISR(INT7_vect) //SIGNAL(SIG_INTERRUPT7)  
{
	flag = 7;
}  

int main(void)  
{
	unsigned char FND_DATA_TBL[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 
                                	0x6D, 0x7D, 0x27, 0x7F, 0x6F, 
									0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};
	unsigned char cnt = 0;

	DDRA = 0xFF;
	DDRC = 0x0F;
	DDRE = 0x00;   
	
	EIMSK = (1<<INT7);
	EICRB = (1<<ISC71) | (1<<ISC70); 
	
	sei();  
	
	for(;;)  
	{
		if(flag == 7)
		{
			PORTC = 0x07;
			PORTA = FND_DATA_TBL[cnt];
			cnt++;
			if(cnt > 15) { flag = 0; cnt = 0; }
			_delay_ms(500);
		}
	}

	return 1;
}  
*/
