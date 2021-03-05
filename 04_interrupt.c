#include "04_interrupt.h"

/*
//s0 ������ led���� ��, s1 ������ led������ �� 

void main()   
{
	DDRG = 0xFF;  //PORTG ���, LED 
	DDRD = 0x00;  //PORTD �Է�, ���ͷ�Ʈ ��ưKEY 

	PORTG = 0x00;  //LED ���� ���� 

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
//BT0~BT2�� LED0~LED1�� ������������ �� ��ư�� ������ �� �����Ǵ� LED�� �������� �Ѵ�. (+array_fnd) 

int main(void)
{
	unsigned char FND[]={0x3F, 0x06, 0x5B, 0x4F, 0x66,
						0x6D, 0x7D, 0x27, 0x7F, 0x6F};

	int cnt0 = 0;
	int cnt1 = 0;
	int i;

	DDRC = 0xFF;  //�ð�
	DDRG = 0x0F;  //�ð�COM //4PIN //0xFF

	DDRA = 0xFF;  //LED
	DDRD = 0x00;  //BUTTON//�Է¿�

	for(;;) //�ð���� 
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

		if(PIND == 0b00000001)  //0����ư�� ������ LED 0�� �������� ���ڴ� 
		{
			PORTA = 0b00000001;
		}
		else if(PIND == 0b00000010)  //1����ư�� ������ LED 1�� �������� ���ڴ� 
		{
			PORTA = 0b00000010;
		}
		else if(PIND == 0b00000100)  //2����ư�� ������ LED 0,1�� �������� ���ڴ� 
		{
			PORTA = 0b00000011;
		}
  	} 
	return 0;
}
*/


/*
//BT0~BT2�� LED0~LED1�� ������������ �� ��ư�� ������ �� �����Ǵ� LED�� �������� �Ѵ�. (+array_fnd) 

ISR(INT0_vect)  //�ܺ� ���ͷ�Ʈ�� ���� ���ִ� �Լ�.//ISR�� ����� ���� �Լ��� �ƴ϶�, �ý����� �̹� ���س����� �ҷ����°���
{
	PORTA = 0b00000001; //led0�� �ҵ�����
}
ISR(INT1_vect)
{
	PORTA = 0b00000010; //led1�� �ҵ�����
}
ISR(INT2_vect)
{
	PORTA = 0b00000011; //led0,1�� �ҵ�����
}
	 
int main(void)
{
	unsigned char FND[]={0x3F, 0x06, 0x5B, 0x4F, 0x66,
			    		 0x6D, 0x7D, 0x27, 0x7F, 0x6F};
	int cnt0 = 0;
	int cnt1 = 0;
	int i;

	DDRC = 0xFF;  //�ð�
	DDRG = 0xFF;  //�ð�COM		
	DDRA = 0xFF;  //LED
	DDRD = 0x00;  //BUTTON
	
	EIMSK = 0b00000111;  //0,1,2�� ���ͷ�Ʈ ��� 
	EICRA = 0b00101111;  //��ư 2���� ��ư� ���� 
	
	sei();  //���ͷ�Ʈ enable //�̼������� ���ͷ�Ʈ �޾Ƶ帱�� �ֵ��� �� //�غ��۾��� ���� ���� ����
			// <-> cli(); : �̶����ʹ� ���ͷ�Ʈ �ܺο��� �ƹ��� �������� ������ 
	for(;;) //�ð���� 
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
//��ư 0���� ������ led 1���� ������ �ϱ� 

SIGNAL(SIG_INTERRUPT0)  //ISR(INT0_vect) //�ݵ�� �빮�� //�� Ű��
{
	PORT_LED = 0x01;
}
SIGNAL(SIG_INTERRUPT1)  //ISR(INT1_vect) //�� ���� 
{
	PORT_LED = 0x00;
}
void main()
{
	DDR_LED = 0xFF;  //��¿� 
	DDR_BTN = 0x00;  //�Է¿�

	EIMSK = 0b00000011; //�ܺ��Է� �����Լ� //= 0x03, = 3, = (1<<INT1)|(1<<INT0) //��ư0,1�� ���� 
	EICRA = 0b00001111; //�Ѵ� ��¿��� ��ư ������ �����϶� //=0x0F;

	sei();  //���ͷ�Ʈ enable
 

	for(;;)//�� ��� �ݺ� 
	{
		 
	}
}
*/


  

/*
//flag �Լ� ����Ͽ�, ��ư 0���� ������ led 1���� ������ �ϱ�
//flag ��� ���������� �Ἥ ���� ���� � ���ͷ�Ʈ ��Ȳ�̴ٶ�� �͸� main�Լ����� �Ѱ��ִ� ���

int flag = 9;
 
SIGNAL(SIG_INTERRUPT0)  //ISR(INT0_vect)//�� Ű��
{
	flag = 0; 
}
SIGNAL(SIG_INTERRUPT1) //ISR(INT1_vect)//�� ���� 
{
	flag = 1;
}

void main()
{
	DDR_LED = 0xFF;//��¿� 
	DDR_BTN = 0x00;//�Է¿�

	EIMSK = 0b00000011; //�ܺ��Է� �����Լ� //= 0x03, = 3, = (1<<INT1)|(1<<INT0) //��ư0,1�� ���� 
	EICRA = 0b00001111; //�Ѵ� ��¿��� ��ư ������ �����϶� //=0x0F;

	sei();    

	for(;;)//�� ��� �ݺ� 
	{
		if(flag == 0)
			PORT_LED = 0x01;
		else if(flag == 1)
			PORT_LED = 0x00;
	}
}
*/

//////////////

/*#include<avr/io.h> //BUTTON1���ʺ��� LED//BUTTON2�����ʺ��� LED
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

		EIMSK=(1<<INT7) | (1<<INT6); //INTERRUPT BUTTON4,5�� 
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
// array fnd�� �̿��Ͽ� BT0�� �̿��Ͽ� INT0�� �߻��ϸ� 0~9999���� 1�ʰ������� �����ϰ�,
BT1�� �̿��Ͽ� INT1�� �߻��ϸ� ������ ���߰��Ѵ�. �ٽ� BT0�� ������ 0�������� ���Ӱ� ī��Ʈ�ȴ�.

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
			PORTG = 0X0E;  //4���� �� ���� õ���ڸ� 
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
		//count ������ �������
		
		if(flag == 1)
		{
			cnt++;
			if(cnt > 9999) cnt = 0;
		}
	}
}  
*/



//��ư0: ��������->��ư1: ����->��ư0: ���� ���ں��� �ٽ� ���� 

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
	
	DDRC = 0xFF;  //Array FND A~H ����
	DDRG = 0xFF;  //Array FND C0~C3 ����
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
