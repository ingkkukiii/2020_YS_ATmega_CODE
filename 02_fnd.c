//#include "02_fnd.h"

/*  //fnd�� 1�� �������� 0~F���� ��ȭ�Ǵ� ���α׷��� �ۼ��Ѵ�, F�� ��µ� �������� �ٽ� 0���� ���ư���.(55p)
void main(void)
{
	unsigned char FND_DATA_TBL[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
		   				   			0x6D, 0x7D, 0x27, 0x7F, 0x6F,
						   			0x77, 0x7C, 0x39, 0x5E, 0x79,
						   			0x71};

	unsigned char cnt = 0;
	
	DDR_FND = 0xFF;
	PORT_FND = 0x00;

	while(1)
	{
		PORT_FND = FND_DATA_TBL[cnt];
		
		cnt++;
		
		if(cnt>15) cnt = 0;

		_delay_ms(1000);		
	}
	return 0;
}
*/


/*  //2���� 1�ڸ� fnd�� �����Ͽ� 1~99���� ���� �����ϴ� ���α׷��� �ۼ��϶�, 99�� �Ǹ� �ٽ� 0���� �ʱ�ȭ�Ǿ� �ݺ��Ѵ�.(57p)

#define		DDR_FND0	DDRD
#define		PORT_FND0	PORTD

#define		DDR_FND1	DDRB
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
void main() // �ʽð� ����� 
{
	unsigned char FND[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
		   				   0x6D, 0x7D, 0x27, 0x7F, 0x6F};

	int cnt1 = 0;  
	int cnt10 = 0; 
	
	DDRE = 0xFF;
	DDRD = 0xFF;
	
	for(;;)
	{
		PORTE = FND[cnt10];
		PORTD = FND[cnt1];

		count1++;

		if(cnt1 > 9) 
		{
			cnt1 = 0;

			cnt10++; //cnt1�� 9�� �Ѿ�¼��� cnt10�� 1�� ���� 

			if(cnt10 > 5) cnt10 = 0; //60�ʰ� �Ǵ� ���� cnt10�� 0���� ����
		}
		_delay_ms(500); 	
	}
}
*/


/*
void main()  // �ʽð� �����2
{
	unsigned char FND[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
		   				   0x6D, 0x7D, 0x27, 0x7F, 0x6F};

	int cnt1 = 0;  
 	
	DDRE = 0xFF;
	DDRD = 0xFF;
	
	for(;;)
	{
		PORTE = FND[(cnt1 / 10 ) % 10];
		PORTD = FND[(cnt1 / 1 ) % 10];

		count1++;

		if(cnt1 > 59) cnt1 = 0;

		_delay_ms(500); 	
	}
}
*/
