//#include "02_fnd.h"

/*  
//2���� 1�ڸ� fnd�� �����Ͽ� 1~99���� ���� �����ϴ� ���α׷��� �ۼ��϶�, 99�� �Ǹ� �ٽ� 0���� �ʱ�ȭ�Ǿ� �ݺ��Ѵ�.(57p)

#define		DDR_FND0	DDRD  //������ FND�� ����
#define		PORT_FND0	PORTD

#define		DDR_FND1	DDRB  //���� FND�� ����
#define		PORT_FND1	PORTB

void main()  
{
	unsigned char FND[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
		   				   0x6D, 0x7D, 0x27, 0x7F, 0x6F};

	int cnt1 = 0;  //cnt 1�� �ڸ� 
	int cnt10 = 0; //cnt 10�� �ڸ� 
	
	DDR_FND0 = 0xFF;
	DDR_FND1 = 0xFF;
	
	for(;;)
	{
		PORT_FND0 = FND[cnt1];
		PORT_FND1 = FND[cnt10];

		cnt1++;

		if(cnt1 > 9) 
		{
			cnt1 = 0;
			
			cnt10++; //count1 �� 9�� �Ѿ�¼��� count10�� 1�� ���� 
			
			if(cnt10 > 9) cnt10 = 0; //99�ʰ� �Ǵ� ���� count10 0���� ����
		}
		_delay_ms(500); 	
	}
}
*/


/*
//cnt ���� 1���� ����ؼ� ������ �ʽð� �����

void main()  
{
	unsigned char FND[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
		   				   0x6D, 0x7D, 0x27, 0x7F, 0x6F};

	int cnt = 0;  
	
	DDRB = 0xFF;  //fnd ���� 
	DDRD = 0xFF;  //fnd ������

	for(;;)
	{
		PORTB = FND[(cnt / 10) % 10];
		PORTD = FND[(cnt / 1) % 10];

		cnt++;
		
		if(cnt > 59) cnt = 0;

		_delay_ms(1000)
	}
}
