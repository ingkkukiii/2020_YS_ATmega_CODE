#include "03_array_fnd.h"

/*
//array fnd로 "1234"를 출력해본다.(60p)

#define DDR_FND		DDRD
#define PORT_FND	PORTD

#define DDR_COM		DDRG
#define PORT_COM	PORTG

void main()
{
	unsigned char FND[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
		   				   0x6D, 0x7D, 0x27, 0x7F, 0x6F};

	DDR_FND = 0xFF; //8가닥 다 쓰니까 
	PORT_FND = 0x00;

	DDR_COM = 0x0F; //4가닥만 쓰니까 
	PORT_COM = 0x0F;

	while(1)
	{
		PORT_COM = 0x0E;  //array_fnd 1번째 칸 0000 1110
		PORT_FND = FND[1];
		_delay_ms(1000);

		PORT_COM = 0x0D;  //array_fnd 2번째 칸 0000 1101
		PORT_FND = FND[2];
		_delay_ms(1000);

		PORT_COM = 0x0B;  //array_fnd 3번째 칸 0000 1011
		PORT_FND = FND[3];
		_delay_ms(1000);

		PORT_COM = 0x07;  //array_fnd 4번째 칸 0000 0111
		PORT_FND = FND[4];
		_delay_ms(1000);

}
*/


/*
//array_fnd로 0~9999까지 증가되는 프로그램을 작성한다, 9999가 되면 다시 0으로 초기화된다.(62p)
//0015가 아닌 xx15로 출력하는 방법//속도일정

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
//array_fnd로 0~9999까지 증가되는 프로그램을 작성한다, 9999가 되면 다시 0으로 초기화된다.(62p)

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
		for(i=0;i<50;i++)  //(50ms*5ms)*4개 = 가장 안정적인 1초 
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
//4개의 fnd를 앞 2자리와 뒤 2자리로 분리하여 분,초 시계만들기.(67p)

void main()  
{
	unsigned char FND[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
		   				   0x6D, 0x7D, 0x27, 0x7F, 0x6F};
	int count = 0;
	int countm = 0;
	int i;  

	DDRC = 0xFF; //선택선 
	DDRA = 0xFF; //포트

	for(;;) 
	{	
 		for(i=0;i<5;i++) 
		{
		
			PORTA = FND[(countm / 10) % 10];//countm이 가지고있는 수중에 10의자리
			PORTC = 0x0E; 
			_delay_ms(5);
				
			PORTA = FND[(countm / 1) % 10];//countm이 가지고있는 수중에 1의자리
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
//4개의 fnd를 앞 2자리와 뒤 2자리로 분리하여 시, 분,초 시계만들기.(67p)
 
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
		PORTB = FND[(counth / 10) % 10];//카운트 h가 가지고 있는숫자중에 10의 자리수 
		PORTD = FND[(counth / 1) %  10];

		for(i=0;i<50;i++) //반복 50 초 5 가장 안정적인 1초//시,분,초시계 만들기  
		{
		
			PORTC = FND[(countm / 10) % 10]; //countm이 가지고있는 수중에 10의자리
			PORTG = 0x0E; 
			_delay_ms(5);
				
			PORTC = FND[(countm / 1) % 10]; //countm이 가지고있는 수중에 1의자리
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
			
			countm++; //59초->60초 되는순간 분값 1씩 증가 
			
			if(countm > 59) //59분->60분 되는순간 분값 리셋
			{
				countm = 0;
			
				counth ++;
			
				if(counth > 23) counth = 0;
			}
		}
	}
}
*/

