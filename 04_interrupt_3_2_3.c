//#include "04_interrupt.h"

/*
// array fnd를 이용하여 BT0를 이용하여 INT0이 발생하면 0~9999까지 1초간격으로 증가하고,
//BT1를 이용하여 INT1이 발생하면 증가를 멈추게한다. 다시 BT0를 누르면 0에서부터 새롭게 카운트된다.
//버튼0: 숫자증가->버튼1: 멈춤->버튼0: 0부터 다시 시작 

int flag = 0; 
int cnt = 0;  //전역변수로 선언해야함 

SIGNAL(SIG_INTERRUPT0)
{
	flag = 1;
	cnt = 0;  //전역변수로 선언해야함 
}
SIGNAL(SIG_INTERRUPT1)
{
	flag = 2; 
}

void main() 
{
	unsigned char FND[]={0x3F, 0x06, 0x5B, 0x4F, 0x66,
			             0x6D, 0x7D, 0x27, 0x7F, 0x6F};

	int i;	

	DDRC = 0xFF;
	DDRG = 0xFF;
	DDRD = 0x00; 

	EIMSK = (1<<INT1) | (1<<INT0);  //=0x03;
	EICRA = (1<<ISC11) | (1<<ISC10) | (1<<ISC01) | (1<<ISC00); //=0x0F;

	sei();   

	for(;;)
	{
		for(i=0;i<50;i++)
		{
			PORTC = FND[(cnt / 1000) % 10];
			PORTG = 0X0E;  //4중의 젤 왼쪽 천의자리 
			_delay_ms(5);

			PORTC = FND[(cnt / 100) % 10];
			PORTG = 0X0D;
			_delay_ms(5);

			PORTC = FND[(cnt / 10) % 10];
			PORTG = 0X0B;
			_delay_ms(5);

			PORTC = FND[(cnt / 1) % 10];
			PORTG = 0X07;
			_delay_ms(5);
		}
		//count 변수의 숫자출력
		
		if(flag == 1)
		{
			cnt++;
			if(cnt > 9999) cnt = 0;
		}
	}
}  
*/

/*
//#include <avr/io.h> #include <avr/delay.h> #include <avr/interrupt.h>
//버튼0: 숫자증가->버튼1: 멈춤->버튼0: 멈춘 숫자부터 다시 시작   

int flag = 0;  

SIGNAL(SIG_INTERRUPT0)  
{
	flag = 1;
}  
SIGNAL(SIG_INTERRUPT1)
{
	flag = 2; 
}

void main()  
{
	unsigned char FND[]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x6F};

	int i;	
	int count = 0;  

	DDRC = 0xFF;
	DDRG = 0xFF;
	DDRD = 0x00;   

	EIMSK = (1<<INT1) | (1<<INT0);  
	EICRA = (1<<ISC11) | (1<<ISC10) | (1<<ISC01) | (1<<ISC00); 

	sei();  

	for(;;)  
	{
		for(i=0;i<50;i++)
		{
			PORTC = FND[(count / 1000) % 10];
			PORTG = 0X0E;//2000//4중의 젤 왼쪽 천의자리 
			_delay_ms(5);
			PORTC = FND[(count / 100) % 10];
			PORTG = 0X0D;
			_delay_ms(5);
			PORTC = FND[(count / 10) % 10];
			PORTG = 0X0B;
			_delay_ms(5);
			PORTC = FND[(count / 1) % 10];
			PORTG = 0X07;
			_delay_ms(5);
		}  
		
		if(flag == 1) 
		{
			count++;
			if(count > 9999)
			count = 0;
		}
	}
}  
*/

/*
//버튼0: 숫자증가->버튼1: 멈춤->버튼0: 멈춘 숫자부터 다시 시작 
//시,분,초 

int flag = 0;  
SIGNAL(SIG_INTERRUPT0) 
{
	flag = 1;
}
SIGNAL(SIG_INTERRUPT1) 
{
	flag = 2;
}

void main()
{
	unsigned char FND[]={0x3F, 0x06, 0x5B, 0x4F, 0x66,0x6D, 0x7D, 0x27, 0x7F, 0x6F};

	int i; 
	int count = 0; int countm = 0; int counth = 0;
	
	DDRC = 0xFF; DDRG = 0xFF; DDRE = 0xFF; DDRA = 0xFF; DDRD = 0x00;
    	
	EIMSK = (1<<INT1) | (1<<INT0);
	EICRA = (1<<ISC11) | (1<<ISC10) | (1<<ISC01) | (1<<ISC00);
	
	sei();
	
	for(;;)
	{
			PORTE = FND [(counth / 10) % 10];
			PORTA = FND [(counth / 1) % 10];
			
			for(i=0;i<50;i++)
			{
				PORTC = FND[(countm / 10) %10];
				PORTG = 0x0E;		
				_delay_ms(5);
	 			PORTC = FND[(countm / 1) %10];
				PORTG = 0x0D;    			
				_delay_ms(5);
				PORTC = FND[(count / 10) %10];
				PORTG = 0x0B;   			
				_delay_ms(5);
				PORTC = FND[(count / 1) %10];
				PORTG = 0x07;    			
				_delay_ms(5);
			}
			if(flag == 1)
			{
	 			count++;
	       		
				if(count>59)
	   			{
					count = 0;
	       			countm++;
	 	   	 	
					if(countm > 59)
					{
						countm = 0;
	   					counth++;
	   			
						if(counth > 23) counth = 0;
	 				}
		  		}
	 		}
	}
}
*/
