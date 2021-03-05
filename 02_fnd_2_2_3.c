//#include "02_fnd.h"

/*  
//2개의 1자리 fnd를 연동하여 1~99까지 값이 증가하는 프로그램을 작성하라, 99가 되면 다시 0으로 초기화되어 반복한다.(57p)

#define		DDR_FND0	DDRD  //오른쪽 FND와 연결
#define		PORT_FND0	PORTD

#define		DDR_FND1	DDRB  //왼쪽 FND와 연결
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
//cnt 변수 1개를 사용해서 간단한 초시계 만들기

void main()  
{
	unsigned char FND[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
		   				   0x6D, 0x7D, 0x27, 0x7F, 0x6F};

	int cnt = 0;  
	
	DDRB = 0xFF;  //fnd 왼쪽 
	DDRD = 0xFF;  //fnd 오른쪽

	for(;;)
	{
		PORTB = FND[(cnt / 10) % 10];
		PORTD = FND[(cnt / 1) % 10];

		cnt++;
		
		if(cnt > 59) cnt = 0;

		_delay_ms(1000)
	}
}
