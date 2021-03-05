#include "03_array_fnd.h"

/*
//array fnd�� "1234"�� ����غ���.(60p)

#define DDR_FND		DDRD
#define PORT_FND	PORTD

#define DDR_COM		DDRG
#define PORT_COM	PORTG

void main()
{
	unsigned char FND[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
		   				   0x6D, 0x7D, 0x27, 0x7F, 0x6F};

	DDR_FND = 0xFF; //8���� �� ���ϱ� 
	PORT_FND = 0x00;

	DDR_COM = 0x0F; //4���ڸ� ���ϱ� 
	PORT_COM = 0x0F;

	while(1)
	{
		PORT_COM = 0x0E;  //array_fnd 1��° ĭ 0000 1110
		PORT_FND = FND[1];
		_delay_ms(1000);

		PORT_COM = 0x0D;  //array_fnd 2��° ĭ 0000 1101
		PORT_FND = FND[2];
		_delay_ms(1000);

		PORT_COM = 0x0B;  //array_fnd 3��° ĭ 0000 1011
		PORT_FND = FND[3];
		_delay_ms(1000);

		PORT_COM = 0x07;  //array_fnd 4��° ĭ 0000 0111
		PORT_FND = FND[4];
		_delay_ms(1000);

}
*/


/*
//array_fnd�� 0~9999���� �����Ǵ� ���α׷��� �ۼ��Ѵ�, 9999�� �Ǹ� �ٽ� 0���� �ʱ�ȭ�ȴ�.(62p)
//0015�� �ƴ� xx15�� ����ϴ� ���//�ӵ�����

void main()
{
	unsigned char FND[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
		   				   0x6D, 0x7D, 0x27, 0x7F, 0x6F};
	int cnt = 0;
	int i;  

	DDRC = 0xFF;
	DDRG = 0xFF; 

	for(;;) 
	{
		for(i=0;i<50;i++)   
		{
			if(cnt >= 1000)
			{
				PORTC = FND[(cnt / 1000) % 10];
				PORTG = 0x0E; 
			}
			_delay_ms(5);
				
			if(cnt >= 100)
			{
				PORTC = FND[(cnt / 100) % 10];
				PORTG = 0x0D;
			}
			_delay_ms(5);

			if(cnt >= 10)
			{
				PORTC = FND[(cnt / 10) % 10];
				PORTG = 0x0B;
			}
			_delay_ms(5);

			PORTC = FND[(cnt / 1) % 10];
			PORTG = 0x07;
			_delay_ms(5);
		}

		cnt++;
		if(cnt > 9999) cnt = 0;
	}
}
*/


/*
//array_fnd�� 0~9999���� �����Ǵ� ���α׷��� �ۼ��Ѵ�, 9999�� �Ǹ� �ٽ� 0���� �ʱ�ȭ�ȴ�.(62p)

void main()  
{
	unsigned char FND[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
		   				   0x6D, 0x7D, 0x27, 0x7F, 0x6F};
	int cnt = 0;
	int i;  

	DDRC = 0xFF;
	DDRG = 0xFF; 

	for(;;) 
	{
		for(i=0;i<50;i++)  //(50ms*5ms)*4�� = ���� �������� 1�� 
		{
		
			PORTC = FND[(cnt / 1000) % 10];
			PORTG = 0x0E; 
			_delay_ms(5);
				
			PORTC = FND[(cnt / 100) % 10];
			PORTG = 0x0D;
			_delay_ms(5);

			PORTC = FND[(cnt / 10) % 10];
			PORTG = 0x0B;
			_delay_ms(5);

			PORTC = FND[(cnt / 1) % 10];
			PORTG = 0x07;
			_delay_ms(5);
		}

		cnt++;
		if(cnt > 9999) cnt = 0;
	}
}
*/


/*
//4���� fnd�� �� 2�ڸ��� �� 2�ڸ��� �и��Ͽ� ��,�� �ð踸���.(67p)

void main()  
{
	unsigned char FND[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
		   				   0x6D, 0x7D, 0x27, 0x7F, 0x6F};
	int count = 0;
	int countm = 0;
	int i;  

	DDRC = 0xFF; //���ü� 
	DDRA = 0xFF; //��Ʈ

	for(;;) 
	{	
 		for(i=0;i<5;i++) 
		{
		
			PORTA = FND[(countm / 10) % 10];//countm�� �������ִ� ���߿� 10���ڸ�
			PORTC = 0x0E; 
			_delay_ms(5);
				
			PORTA = FND[(countm / 1) % 10];//countm�� �������ִ� ���߿� 1���ڸ�
			PORTC = 0x0D;
			_delay_ms(5);

			PORTA = FND[(count / 10) % 10];
			PORTC = 0x0B;
			_delay_ms(5);

			PORTA = FND[(count / 1) % 10];
			PORTC = 0x07;
			_delay_ms(5);
		}

		count++;

		if(count > 59)
		{
	    	count = 0;
			countm++; 

			if(countm > 59) 
			{
				countm = 0;
			}
		}
	}
}
*/


/*
//4���� fnd�� �� 2�ڸ��� �� 2�ڸ��� �и��Ͽ� ��, ��,�� �ð踸���.(67p)
 
void main()  
{
	unsigned char FND[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
		   				   0x6D, 0x7D, 0x27, 0x7F, 0x6F};
	int count = 0;
	int countm = 0;
	int counth = 0;
	int i;  

	DDRC = 0xFF;
	DDRB = 0xFF;
	DDRD = 0xFF; 
	
	DDRG = 0xFF;

	for(;;) 
	{	
		PORTB = FND[(counth / 10) % 10];//ī��Ʈ h�� ������ �ִ¼����߿� 10�� �ڸ��� 
		PORTD = FND[(counth / 1) %  10];

		for(i=0;i<50;i++) //�ݺ� 50 �� 5 ���� �������� 1��//��,��,�ʽð� �����  
		{
		
			PORTC = FND[(countm / 10) % 10]; //countm�� �������ִ� ���߿� 10���ڸ�
			PORTG = 0x0E; 
			_delay_ms(5);
				
			PORTC = FND[(countm / 1) % 10]; //countm�� �������ִ� ���߿� 1���ڸ�
			PORTG = 0x0D;
			_delay_ms(5);

			PORTC = FND[(count / 10) % 10];
			PORTG = 0x0B;
			_delay_ms(5);

			PORTC = FND[(count / 1) % 10];
			PORTG = 0x07;
			_delay_ms(5);
		}

		count++;

		if(count > 59)
		{
	    	count = 0;
			
			countm++; //59��->60�� �Ǵ¼��� �а� 1�� ���� 
			
			if(countm > 59) //59��->60�� �Ǵ¼��� �а� ����
			{
				countm = 0;
			
				counth ++;
			
				if(counth > 23) counth = 0;
			}
		}
	}
}
*/

