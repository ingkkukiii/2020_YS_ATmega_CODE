//#include "02_fnd.h"

/*  
//fnd�� 1�� �������� 0~F���� ��ȭ�Ǵ� ���α׷��� �ۼ��Ѵ�, F�� ��µ� �������� �ٽ� 0���� ���ư���.(55p)

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


/*  
//fnd�� 1�� �������� 0~F���� ��ȭ�Ǵ� ���α׷��� �ۼ��Ѵ�, F�� ��µ� �������� �ٽ� 0���� ���ư���.(55p)
//fnd 2���� ǥ���غ��� 

void main(void)
{
	unsigned char FND[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
				 			0x6D, 0x7D, 0x27, 0x7F, 0x6F,
			   				0x77, 0x7C, 0x39, 0x5E, 0x79,
			   				0x71};

	unsigned char cnt = 0;
	
	DDRE = 0xFF;
	DDRD = 0xFF;

	PORTE = 0x00;
	PORTD = 0x00;

	for(;;)
	{
		PORTE = FND[cnt];
		PORTD = FND[cnt];

		cnt++;
		
		if(cnt>15) cnt = 0;

		_delay_ms(1000);		
	}
	return 0;
}
*/
