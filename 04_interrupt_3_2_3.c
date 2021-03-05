//#include "04_interrupt.h"

/*
// array fnd�� �̿��Ͽ� BT0�� �̿��Ͽ� INT0�� �߻��ϸ� 0~9999���� 1�ʰ������� �����ϰ�,
//BT1�� �̿��Ͽ� INT1�� �߻��ϸ� ������ ���߰��Ѵ�. �ٽ� BT0�� ������ 0�������� ���Ӱ� ī��Ʈ�ȴ�.
//��ư0: ��������->��ư1: ����->��ư0: 0���� �ٽ� ���� 

int flag = 0; 
int cnt = 0;  //���������� �����ؾ��� 

SIGNAL(SIG_INTERRUPT0)
{
	flag = 1;
	cnt = 0;  //���������� �����ؾ��� 
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

/*
//#include <avr/io.h> #include <avr/delay.h> #include <avr/interrupt.h>
//��ư0: ��������->��ư1: ����->��ư0: ���� ���ں��� �ٽ� ����   

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
			PORTG = 0X0E;//2000//4���� �� ���� õ���ڸ� 
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
//��ư0: ��������->��ư1: ����->��ư0: ���� ���ں��� �ٽ� ���� 
//��,��,�� 

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
