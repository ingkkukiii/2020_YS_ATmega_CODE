//new3
/*
#include <avr/io.h>
#include <avr/delay.h>

int main()
{
	unsigned char FND[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
						 0x6D, 0x7D, 0x27, 0x7F, 0x67};

	int cnt = 0; //unsigned char ���� 
	unsigned char i;

	DDRA = 0xFF;
	PORTA = 0x00;
		
	DDRC = 0xFF; //0x0F;//4���ڸ� ������� ���ϱ�
	PORTC = 0xFF; //array fnd�� ���ü��� 0�� enable�١١�//���þ��ϰڴ� ->FF

	for(;;)
	{
			for(i=0;i<50;i++) //1�� ����� //���������� 1�ʰ� ���� //������ ��ȭ������� i����(�ð�����) 
			{
				PORTC = 0x0E;
				PORTA = FND[(cnt / 1000) % 10];
				_delay_ms(5);

				PORTC = 0x0D;
				PORTA = FND[(cnt / 100) % 10];
				_delay_ms(5);

				PORTC = 0x0B;
				PORTA = FND[(cnt / 10) % 10];
				_delay_ms(5);

				PORTC = 0x07;
				PORTA = FND[(cnt / 1) % 10];
				_delay_ms(5);
			}
		
			cnt++;
			if(cnt > 9999) cnt = 0;
	}
	return 0;
}
*/


/*
//���ôٹ������� �������� �ϵ��� �߻������� �ϳ��� �����Լ��� ����� ������Ͽ� �Űܵΰ� main�� �����ϰ� ���ش�

int main()
{
	int cnt = 0; //unsigned char ����  

	DDRA = 0xFF;
	PORTA = 0x00;
		
	DDRC = 0xFF; //0x0F;//4���ڸ� ������� ���ϱ�
	PORTC = 0xFF; //array fnd�� ���ü��� 0�� enable�١١�//���þ��ϰڴ� ->FF

	for(;;)
	{
		DISP_FND(cnt); //������Ͽ� ���� �Լ� �ҷ�����
		
		cnt++;
		if(cnt > 9999) cnt = 0;
	}
	return 0;
}
*/
 
 

// new

/*#include "20191128_2018100055.h"

unsigned char tic_time; //���������� ����ؼ� ������� 

SIGNAL(SIG_OVERFLOW0) //�Ʒ� while���� �������� �����Ǿ�  ���������� �ϴ� �Լ� 
{
	tic_time++;
	TCNT0 = 184;
}

void delay_10ms(unsigned char dsec)//delay ���õ� �� �Լ�����
{
	tic_time = 0;
	while(dsec > tic_time); //�ð��� �����ֱ����� ����ϴ� �Լ� while
}

int main()
{
	unsigned char FND[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
							0x6D, 0x7D, 0x27, 0x7F, 0x6F};
	
	unsigned char dbuf[4] = {0,0,0,0};

	int cnt = 0; //ó���� 0���� ����ϴ� 0���� ���� 
	unsigned char i; //�ݺ��� ������ ���� ���� 0~255 1����Ʈ  
	unsigned char digit = 0;

	DDRA = 0xFF; //��¿� 
	PORTA = 0x00; //�� ����

	DDRG = 0xFF; //0b00001111 = 0x0F ������ ���ɾ� 
	PORTG = 0xFF; // ���� Ư���� 1�� �Ⱥ����°� 0�� �帣�°� �ʹݿ� 1���صд�
	
	TCCR0 = (1 << CS02) | (1 << CS01) | (1 << CS00);
	TIMSK = (0 << OCIE0) | (1 << TOIE0);
	TCNT0 = 184;
	
	sei();
	 
	for(;;)
	{
		for(i=0; i<100; i++) //100���� 1�� x 100
		{
			dbuf[0] = (cnt / 1000) % 10;
			dbuf[1] = (cnt / 100) % 10;
			dbuf[2] = (cnt / 10) % 10;
			dbuf[3] = (cnt / 1) % 10;

			PORTA = FND[dbuf[digit]];
			PORTG = ~(1 << digit); 
			
			digit++;
			digit = digit % 4; //if(digit > 3) digit = 0;
			//�Ȱ��� ������ if���� �ƴ� ������ ���ʹ��� ��ȣ 

			delay_10ms(1); 

		}

		cnt++;
		if(cnt > 9999) cnt = 0;

	}


	return 0;
}*/

//new2

/*#include "20191128_2018100055.h"

unsigned char tic_time; //���������� ����ؼ� ������� 
unsigned char FND[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
						0x6D, 0x7D, 0x27, 0x7F, 0x6F};

unsigned char dbuf[4] = {0,0,0,0}; 
unsigned char digit = 0;

SIGNAL(SIG_OVERFLOW0) //�Ʒ� while���� �������� �����Ǿ�  ���������� �ϴ� �Լ� 
{
	PORTA = FND[dbuf[digit]];
	PORTG = ~(1 << digit); 
	
	digit++;
	digit = digit % 4;

	tic_time++;
	TCNT0 = 184;
}

void delay_10ms(unsigned char dsec)//delay ���õ� �� �Լ�����
{
	tic_time = 0;
	while(dsec > tic_time); //�ð��� �����ֱ����� ����ϴ� �Լ� while
}

int main()
{
	int cnt = 0; //ó���� 0���� ����ϴ� 0���� ���� 
    unsigned char i; //�ݺ��� ������ ���� ���� 0~255 1����Ʈ  

	DDRA = 0xFF; //��¿� 
	PORTA = 0x00; //�� ����

	DDRG = 0xFF; //0b00001111 = 0x0F ������ ���ɾ� 
	PORTG = 0xFF; // ���� Ư���� 1�� �Ⱥ����°� 0�� �帣�°� �ʹݿ� 1���صд�
	
	TCCR0 = (1 << CS02) | (1 << CS01) | (1 << CS00);
	TIMSK = (0 << OCIE0) | (1 << TOIE0);
	TCNT0 = 184;
	
	sei();
	 
	for(;;)
	{
		for(i=0; i<100; i++) //100���� 1�� x 100
		{
			dbuf[0] = (cnt / 1000) % 10;
			dbuf[1] = (cnt / 100) % 10;
			dbuf[2] = (cnt / 10) % 10;
			dbuf[3] = (cnt / 1) % 10;

			delay_10ms(1); 

		}

		cnt++;
		if(cnt > 9999) cnt = 0;

	}

	return 0;
}*/

#include "20191128_2018100055.h"

unsigned char tic_time; //���������� ����ؼ� ������� 
unsigned char FND[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
						0x6D, 0x7D, 0x27, 0x7F, 0x6F};

unsigned char dbuf[4] = {0,0,0,0}; 
unsigned char digit = 0;

SIGNAL(SIG_OVERFLOW0) //�Ʒ� while���� �������� �����Ǿ�  ���������� �ϴ� �Լ� 
{
	PORTA = FND[dbuf[digit]];
	PORTG = ~(1 << digit); 
	
	digit++;
	digit = digit % 4;

	tic_time++;
	TCNT0 = 184;
}

void delay_10ms(unsigned char dsec)//delay ���õ� �� �Լ�����
{
	tic_time = 0;
	while(dsec > tic_time); //�ð��� �����ֱ����� ����ϴ� �Լ� while
}

int main()
{
	int cnt = 1234;   
    unsigned char i; //�ݺ��� ������ ���� ���� 0~255 1����Ʈ  

	DDRA = 0xFF; //��¿� 
	PORTA = 0x00; //�� ����

	DDRG = 0xFF; //0b00001111 = 0x0F ������ ���ɾ� 
	PORTG = 0xFF; // ���� Ư���� 1�� �Ⱥ����°� 0�� �帣�°� �ʹݿ� 1���صд�
	
	TCCR0 = (1 << CS02) | (1 << CS01) | (1 << CS00);
	TIMSK = (0 << OCIE0) | (1 << TOIE0);
	TCNT0 = 184;
	
	sei();
	 
	for(;;)
	{	 
		dbuf[0] = (cnt / 1000) % 10;
		dbuf[1] = (cnt / 100) % 10;
		dbuf[2] = (cnt / 10) % 10;
		dbuf[3] = (cnt / 1) % 10;

		delay_10ms(10); 
	}


	return 0;
}

//timer

/*#include "20191128_2018100055.h"

unsigned char tic_time; //���������� ����ؼ� ������� 

SIGNAL(SIG_OVERFLOW0) //�Ʒ� while���� �������� �����Ǿ�  ���������� �ϴ� �Լ� 
{
	tic_time++;
	TCNT0 = 184;
}

void delay_10ms(unsigned char dsec)//delay ���õ� �� �Լ�����
{
	tic_time = 0;
	while(dsec > tic_time); //�ð��� �����ֱ����� ����ϴ� �Լ� while
}

int main()
{
	unsigned char FND[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
							0x6D, 0x7D, 0x27, 0x7F, 0x6F};
	
	int cnt = 0; //ó���� 0���� ����ϴ� 0���� ���� 
	unsigned char i; //�ݺ��� ������ ���� ���� 0~255 1����Ʈ  

	DDRA = 0xFF; //��¿� 
	PORTA = 0x00; //�� ����

	DDRG = 0xFF; //0b00001111 = 0x0F ������ ���ɾ� 
	PORTG = 0xFF; // ���� Ư���� 1�� �Ⱥ����°� 0�� �帣�°� �ʹݿ� 1���صд�
	
	TCCR0 = (1 << CS02) | (1 << CS01) | (1 << CS00);
	TIMSK = (0 << OCIE0) | (1 << TOIE0);
	TCNT0 = 184;
	
	sei();
	 
	for(;;)
	{
		for(i=0; i<25; i++) //100���� 4�� x 25
		{
			PORTA = FND[(cnt / 1000) % 10];
			PORTG = 0x0E;//��� õ���ڸ� 16���� ��
			delay_10ms(1); //100���� 1�� 

	        PORTA = FND[(cnt / 100) % 10];
			PORTG = 0x0D;//��� �����ڸ� 16���� ��
			delay_10ms(1);

			PORTA = FND[(cnt / 10) % 10];
			PORTG = 0x0B;//��� �����ڸ� 16���� ��
			delay_10ms(1);

			PORTA = FND[(cnt / 1) % 10];
			PORTG = 0x07;//��� �����ڸ� 16���� ��
			delay_10ms(1);
		}

		cnt++;
		if(cnt > 9999) cnt = 0;

	}


	return 0;
}*/
