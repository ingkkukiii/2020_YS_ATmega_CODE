//#include "02_fnd.h"

/*  //fnd에 1초 간격으로 0~F까지 변화되는 프로그램을 작성한다, F가 출력된 다음에는 다시 0으로 돌아간다.(55p)
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


/*  //2개의 1자리 fnd를 연동하여 1~99까지 값이 증가하는 프로그램을 작성하라, 99가 되면 다시 0으로 초기화되어 반복한다.(57p)

#define		DDR_FND0	DDRD
#define		PORT_FND0	PORTD

#define		DDR_FND1	DDRB
#define		PORT_FND1	PORTB

void main()  
{
	unsigned char FND[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
		   				   0x6D, 0x7D, 0x27, 0x7F, 0x6F};

	int cnt1 = 0;  //cnt 1의 자리 
	int cnt10 = 0; //cnt 10의 자리 
	
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
			
			cnt10++; //count1 이 9가 넘어가는순간 count10도 1씩 증가 
			
			if(cnt10 > 9) cnt10 = 0; //99초가 되는 순간 count10 0으로 리셋
		}
		_delay_ms(500); 	
	}
}
*/


/*
void main() // 초시계 만들기 
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

			cnt10++; //cnt1이 9가 넘어가는순간 cnt10도 1씩 증가 

			if(cnt10 > 5) cnt10 = 0; //60초가 되는 순간 cnt10이 0으로 리셋
		}
		_delay_ms(500); 	
	}
}
*/


/*
void main()  // 초시계 만들기2
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
