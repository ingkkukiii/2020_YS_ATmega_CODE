//new3
/*
#include <avr/io.h>
#include <avr/delay.h>

int main()
{
	unsigned char FND[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
						 0x6D, 0x7D, 0x27, 0x7F, 0x67};

	int cnt = 0; //unsigned char 부족 
	unsigned char i;

	DDRA = 0xFF;
	PORTA = 0x00;
		
	DDRC = 0xFF; //0x0F;//4가닥만 출력으로 쓰니까
	PORTC = 0xFF; //array fnd의 선택선은 0이 enable☆☆☆//선택안하겠다 ->FF

	for(;;)
	{
			for(i=0;i<50;i++) //1초 만들기 //조도센서값 1초간 유지 //빠르게 변화보고싶은 i단축(시간조절) 
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
//동시다발적으로 여러개의 일들이 발생했을때 하나의 별도함수를 만들어 헤더파일에 옮겨두고 main을 간략하게 해준다

int main()
{
	int cnt = 0; //unsigned char 부족  

	DDRA = 0xFF;
	PORTA = 0x00;
		
	DDRC = 0xFF; //0x0F;//4가닥만 출력으로 쓰니까
	PORTC = 0xFF; //array fnd의 선택선은 0이 enable☆☆☆//선택안하겠다 ->FF

	for(;;)
	{
		DISP_FND(cnt); //헤더파일에 만든 함수 불러오기
		
		cnt++;
		if(cnt > 9999) cnt = 0;
	}
	return 0;
}
*/
 
 

// new

/*#include "20191128_2018100055.h"

unsigned char tic_time; //전역변수로 사용해서 공동사용 

SIGNAL(SIG_OVERFLOW0) //아래 while문이 언젠가는 거짓되어  빠져나가게 하는 함수 
{
	tic_time++;
	TCNT0 = 184;
}

void delay_10ms(unsigned char dsec)//delay 관련된 초 함수지정
{
	tic_time = 0;
	while(dsec > tic_time); //시간을 끌어주기위해 사용하는 함수 while
}

int main()
{
	unsigned char FND[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
							0x6D, 0x7D, 0x27, 0x7F, 0x6F};
	
	unsigned char dbuf[4] = {0,0,0,0};

	int cnt = 0; //처음엔 0부터 출력하니 0으로 두자 
	unsigned char i; //반복을 제어할 양의 정수 0~255 1바이트  
	unsigned char digit = 0;

	DDRA = 0xFF; //출력용 
	PORTA = 0x00; //불 끈다

	DDRG = 0xFF; //0b00001111 = 0x0F 이지만 돈케어 
	PORTG = 0xFF; // 소자 특성상 1이 안보내는거 0이 흐르는거 초반엔 1로해둔다
	
	TCCR0 = (1 << CS02) | (1 << CS01) | (1 << CS00);
	TIMSK = (0 << OCIE0) | (1 << TOIE0);
	TCNT0 = 184;
	
	sei();
	 
	for(;;)
	{
		for(i=0; i<100; i++) //100분의 1초 x 100
		{
			dbuf[0] = (cnt / 1000) % 10;
			dbuf[1] = (cnt / 100) % 10;
			dbuf[2] = (cnt / 10) % 10;
			dbuf[3] = (cnt / 1) % 10;

			PORTA = FND[dbuf[digit]];
			PORTG = ~(1 << digit); 
			
			digit++;
			digit = digit % 4; //if(digit > 3) digit = 0;
			//똑같은 결과라면 if문이 아닌 연산자 왼쪽문을 선호 

			delay_10ms(1); 

		}

		cnt++;
		if(cnt > 9999) cnt = 0;

	}


	return 0;
}*/

//new2

/*#include "20191128_2018100055.h"

unsigned char tic_time; //전역변수로 사용해서 공동사용 
unsigned char FND[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
						0x6D, 0x7D, 0x27, 0x7F, 0x6F};

unsigned char dbuf[4] = {0,0,0,0}; 
unsigned char digit = 0;

SIGNAL(SIG_OVERFLOW0) //아래 while문이 언젠가는 거짓되어  빠져나가게 하는 함수 
{
	PORTA = FND[dbuf[digit]];
	PORTG = ~(1 << digit); 
	
	digit++;
	digit = digit % 4;

	tic_time++;
	TCNT0 = 184;
}

void delay_10ms(unsigned char dsec)//delay 관련된 초 함수지정
{
	tic_time = 0;
	while(dsec > tic_time); //시간을 끌어주기위해 사용하는 함수 while
}

int main()
{
	int cnt = 0; //처음엔 0부터 출력하니 0으로 두자 
    unsigned char i; //반복을 제어할 양의 정수 0~255 1바이트  

	DDRA = 0xFF; //출력용 
	PORTA = 0x00; //불 끈다

	DDRG = 0xFF; //0b00001111 = 0x0F 이지만 돈케어 
	PORTG = 0xFF; // 소자 특성상 1이 안보내는거 0이 흐르는거 초반엔 1로해둔다
	
	TCCR0 = (1 << CS02) | (1 << CS01) | (1 << CS00);
	TIMSK = (0 << OCIE0) | (1 << TOIE0);
	TCNT0 = 184;
	
	sei();
	 
	for(;;)
	{
		for(i=0; i<100; i++) //100분의 1초 x 100
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

unsigned char tic_time; //전역변수로 사용해서 공동사용 
unsigned char FND[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
						0x6D, 0x7D, 0x27, 0x7F, 0x6F};

unsigned char dbuf[4] = {0,0,0,0}; 
unsigned char digit = 0;

SIGNAL(SIG_OVERFLOW0) //아래 while문이 언젠가는 거짓되어  빠져나가게 하는 함수 
{
	PORTA = FND[dbuf[digit]];
	PORTG = ~(1 << digit); 
	
	digit++;
	digit = digit % 4;

	tic_time++;
	TCNT0 = 184;
}

void delay_10ms(unsigned char dsec)//delay 관련된 초 함수지정
{
	tic_time = 0;
	while(dsec > tic_time); //시간을 끌어주기위해 사용하는 함수 while
}

int main()
{
	int cnt = 1234;   
    unsigned char i; //반복을 제어할 양의 정수 0~255 1바이트  

	DDRA = 0xFF; //출력용 
	PORTA = 0x00; //불 끈다

	DDRG = 0xFF; //0b00001111 = 0x0F 이지만 돈케어 
	PORTG = 0xFF; // 소자 특성상 1이 안보내는거 0이 흐르는거 초반엔 1로해둔다
	
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

unsigned char tic_time; //전역변수로 사용해서 공동사용 

SIGNAL(SIG_OVERFLOW0) //아래 while문이 언젠가는 거짓되어  빠져나가게 하는 함수 
{
	tic_time++;
	TCNT0 = 184;
}

void delay_10ms(unsigned char dsec)//delay 관련된 초 함수지정
{
	tic_time = 0;
	while(dsec > tic_time); //시간을 끌어주기위해 사용하는 함수 while
}

int main()
{
	unsigned char FND[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
							0x6D, 0x7D, 0x27, 0x7F, 0x6F};
	
	int cnt = 0; //처음엔 0부터 출력하니 0으로 두자 
	unsigned char i; //반복을 제어할 양의 정수 0~255 1바이트  

	DDRA = 0xFF; //출력용 
	PORTA = 0x00; //불 끈다

	DDRG = 0xFF; //0b00001111 = 0x0F 이지만 돈케어 
	PORTG = 0xFF; // 소자 특성상 1이 안보내는거 0이 흐르는거 초반엔 1로해둔다
	
	TCCR0 = (1 << CS02) | (1 << CS01) | (1 << CS00);
	TIMSK = (0 << OCIE0) | (1 << TOIE0);
	TCNT0 = 184;
	
	sei();
	 
	for(;;)
	{
		for(i=0; i<25; i++) //100분의 4초 x 25
		{
			PORTA = FND[(cnt / 1000) % 10];
			PORTG = 0x0E;//제어선 천의자리 16진수 값
			delay_10ms(1); //100분의 1초 

	        PORTA = FND[(cnt / 100) % 10];
			PORTG = 0x0D;//제어선 백의자리 16진수 값
			delay_10ms(1);

			PORTA = FND[(cnt / 10) % 10];
			PORTG = 0x0B;//제어선 십의자리 16진수 값
			delay_10ms(1);

			PORTA = FND[(cnt / 1) % 10];
			PORTG = 0x07;//제어선 일의자리 16진수 값
			delay_10ms(1);
		}

		cnt++;
		if(cnt > 9999) cnt = 0;

	}


	return 0;
}*/
