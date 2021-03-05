//#include "03_array_fnd.h"

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
		for(i=0;i<50;i++)  //0015�� �ƴ� xx15�� ����ϴ� ���//�ӵ�����
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
