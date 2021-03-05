#include "04_interrupt.h"

/*
//s0 누르면 led왼쪽 불, s1 누르면 led오른쪽 불 

void main()   
{
	DDRG = 0xFF;  //PORTG 출력, LED 
	DDRD = 0x00;  //PORTD 입력, 인터럽트 버튼KEY 

	PORTG = 0x00;  //LED 끄고 시작 

	for(;;)
	{
		if(PIND == 0b00000001)
		{
			PORTG = 0b00000001;
		}
		else if(PIND == 0b00000010)
		{	
		 	PORTG = 0b00000010;
		}
	}
}
*/


/*
//BT0~BT2에 LED0~LED1을 각각대응시켜 각 버튼을 누르면 각 대응되는 LED가 켜지도록 한다. (+array_fnd) 

int main(void)
{
	unsigned char FND[]={0x3F, 0x06, 0x5B, 0x4F, 0x66,
						0x6D, 0x7D, 0x27, 0x7F, 0x6F};

	int cnt0 = 0;
	int cnt1 = 0;
	int i;

	DDRC = 0xFF;  //시계
	DDRG = 0x0F;  //시계COM //4PIN //0xFF

	DDRA = 0xFF;  //LED
	DDRD = 0x00;  //BUTTON//입력용

	for(;;) //시계출력 
	{
		for(i=0;i<5;i++)
		{
			PORTC = FND[(cnt1 / 10) % 10];
			PORTG = 0x0E;  
			_delay_ms(5);
			
			PORTC = FND[(cnt1 / 1) % 10];
			PORTG = 0x0D;  
			_delay_ms(5);

			PORTC = FND[(cnt0 / 10) % 10];
			PORTG = 0x0B;  
			_delay_ms(5);

			PORTC = FND[(cnt0 / 1) % 10];
			PORTG = 0x07;  
			_delay_ms(5);
		}
		
		cnt0++;
		if(cnt0 > 59)
		{
			cnt0 = 0;
			cnt1++;

			if(cnt1 > 59) cnt1 = 0;
		}

		if(PIND == 0b00000001)  //0번버튼을 누르면 LED 0이 켜졌으면 좋겠다 
		{
			PORTA = 0b00000001;
		}
		else if(PIND == 0b00000010)  //1번버튼을 누르면 LED 1이 켜졌으면 좋겠다 
		{
			PORTA = 0b00000010;
		}
		else if(PIND == 0b00000100)  //2번버튼을 누르면 LED 0,1이 켜졌으면 좋겠다 
		{
			PORTA = 0b00000011;
		}
  	} 
	return 0;
}
*/


/*
//BT0~BT2에 LED0~LED1을 각각대응시켜 각 버튼을 누르면 각 대응되는 LED가 켜지도록 한다. (+array_fnd) 

ISR(INT0_vect)  //외부 인터럽트를 쓸때 써주는 함수.//ISR은 사용자 정의 함수가 아니라, 시스템이 이미 정해놓은걸 불러쓰는거임
{
	PORTA = 0b00000001; //led0에 불들어오기
}
ISR(INT1_vect)
{
	PORTA = 0b00000010; //led1에 불들어오기
}
ISR(INT2_vect)
{
	PORTA = 0b00000011; //led0,1에 불들어오기
}
	 
int main(void)
{
	unsigned char FND[]={0x3F, 0x06, 0x5B, 0x4F, 0x66,
			    		 0x6D, 0x7D, 0x27, 0x7F, 0x6F};
	int cnt0 = 0;
	int cnt1 = 0;
	int i;

	DDRC = 0xFF;  //시계
	DDRG = 0xFF;  //시계COM		
	DDRA = 0xFF;  //LED
	DDRD = 0x00;  //BUTTON
	
	EIMSK = 0b00000111;  //0,1,2번 인터럽트 사용 
	EICRA = 0b00101111;  //버튼 2번만 버튼띨때 반응 
	
	sei();  //인터럽트 enable //이순간부터 인터럽트 받아드릴수 있도록 해 //준비작업을 셋팅 시켜 놓기
			// <-> cli(); : 이때부터는 인터럽트 외부에서 아무리 들어오더라도 무시해 
	for(;;) //시계출력 
	{
		for(i=0;i<5;i++)
		{
			PORTC = FND[(cnt1 / 10) % 10];
			PORTG = 0x0E;  
			_delay_ms(5);
			
			PORTC = FND[(cnt1 / 1) % 10];
			PORTG = 0x0D;  
			_delay_ms(5);

			PORTC = FND[(cnt0 / 10) % 10];
			PORTG = 0x0B;  
			_delay_ms(5);

			PORTC = FND[(cnt0 / 1) % 10];
			PORTG = 0x07;  
			_delay_ms(5);
		}
		
		cnt0++;
		if(cnt0 > 59)
		{
			cnt0 = 0;
			cnt1++;

			if(cnt1 > 59) cnt1 = 0;
		}
  	} 
	return 0;
}
*/


 


/*
//버튼 0번이 눌리면 led 1개가 켜지게 하기 

SIGNAL(SIG_INTERRUPT0)  //ISR(INT0_vect) //반드시 대문자 //불 키기
{
	PORT_LED = 0x01;
}
SIGNAL(SIG_INTERRUPT1)  //ISR(INT1_vect) //불 끄기 
{
	PORT_LED = 0x00;
}
void main()
{
	DDR_LED = 0xFF;  //출력용 
	DDR_BTN = 0x00;  //입력용

	EIMSK = 0b00000011; //외부입력 지정함수 //= 0x03, = 3, = (1<<INT1)|(1<<INT0) //버튼0,1번 쓰기 
	EICRA = 0b00001111; //둘다 상승엣지 버튼 누를때 동작하라 //=0x0F;

	sei();  //인터럽트 enable
 

	for(;;)//걍 계속 반복 
	{
		 
	}
}
*/


  

/*
//flag 함수 사용하여, 버튼 0번이 눌리면 led 1개가 켜지게 하기
//flag 라는 전역변수를 써서 내가 지금 어떤 인터럽트 상황이다라는 것만 main함수한테 넘겨주는 방식

int flag = 9;
 
SIGNAL(SIG_INTERRUPT0)  //ISR(INT0_vect)//불 키기
{
	flag = 0; 
}
SIGNAL(SIG_INTERRUPT1) //ISR(INT1_vect)//불 끄기 
{
	flag = 1;
}

void main()
{
	DDR_LED = 0xFF;//출력용 
	DDR_BTN = 0x00;//입력용

	EIMSK = 0b00000011; //외부입력 지정함수 //= 0x03, = 3, = (1<<INT1)|(1<<INT0) //버튼0,1번 쓰기 
	EICRA = 0b00001111; //둘다 상승엣지 버튼 누를때 동작하라 //=0x0F;

	sei();    

	for(;;)//걍 계속 반복 
	{
		if(flag == 0)
			PORT_LED = 0x01;
		else if(flag == 1)
			PORT_LED = 0x00;
	}
}
*/

//////////////

/*#include<avr/io.h> //BUTTON1왼쪽부터 LED//BUTTON2오른쪽부터 LED
#include<util/delay.h>
#include<avr/interrupt.h>

#define DDR_LED DDRC
#define PORT_LED PORTC
#define PIN_LED PINC

#define DDR_KEY DDRD
#define PORT_KEY PORTD
#define PIN_KEY PIND

volatile char int_flag;
volatile int k;

SIGNAL(SIG_INTERRUPT7) //BUTTON0
{
		int_flag=1;k=0;
}
SIGNAL(SIG_INTERRUPT6)//BUTTON1
{
		int_flag=2;k=7;
}
int main(void)
{
		DDR_LED=0xFF;
		PORT_LED=0x00;
		DDR_KEY=0x00;

		EIMSK=(1<<INT7) | (1<<INT6); //INTERRUPT BUTTON4,5번 
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



//

//#include "04_interrupt.h"

/*
// array fnd를 이용하여 BT0를 이용하여 INT0이 발생하면 0~9999까지 1초간격으로 증가하고,
BT1를 이용하여 INT1이 발생하면 증가를 멈추게한다. 다시 BT0를 누르면 0에서부터 새롭게 카운트된다.

int flag = 0; 
int cnt = 0; 

SIGNAL(SIG_INTERRUPT0)
{
	flag = 1;
	cnt = 0;
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

	EIMSK = (1<<INT1) | (1<<INT0);
	EICRA = (1<<ISC11) | (1<<ISC10) | (1<<ISC01) | (1<<ISC00); 

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



//버튼0: 숫자증가->버튼1: 멈춤->버튼0: 멈춘 숫자부터 다시 시작 

/*
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
	unsigned char FND[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,0x6D, 0x7D, 0x27, 0x7F, 0x6F};
	
	int i; int count = 0; int countm = 0; int counth = 0;
	
	DDRC = 0xFF;  //Array FND A~H 연결
	DDRG = 0xFF;  //Array FND C0~C3 연결
	DDRE = 0xFF;  //FND [(counth / 10) % 10]
	DDRA = 0xFF;  //FND [(counth / 1) % 10]
	DDRD = 0x00;  ////BT0~BT3 
    	
		
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
