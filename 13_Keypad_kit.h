#include "LCD.h"
#include "uart.h"
#include "avr/interrupt.h" //4교시 

#define COL_1 0x01	//0b00000001
#define COL_2 0x02	//0b00000010
#define COL_3 0x04	//0b00000100

#define ROW_1 0x08	//0b00001000
#define ROW_2 0x10	//0b00010000
#define ROW_3 0x20	//0b00100000
#define ROW_4 0x40  //0b01000000

unsigned char FND_DATA_TBL[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7C,0x07,0x7F,
								0x67,0x77,0x7C,0x39,0x5E,0x79,0x71,0x08,0x80};//리셋*:A//지우기#:b

unsigned char cnt = 0; //key 들어온 갯수 확인변수
unsigned char pass[4] = {0,0,0,0}; //key누를때마다 어떤key가 눌렸는지에대한 숫자처럼보이는 문자형태를 저장하는 배열변수 
unsigned char PASSWD[] = "1234"; //비번 4자리문자를 배열로 문자열로 선언 
unsigned char loop = 1; //정상적인 pw가 들어올때까지 계속 1로유지 ->반복 

void Motor_drive() //motor 함수 만들기
{
	unsigned char moy_tbl[] = {0x99, 0xCC, 0x66, 0x33};
	int mot_cnt = 0;
	int i;

	for(i = 0;i < 200;i++) //왼쪽 1회전 
	{
		PORTB = moy_tbl[mot_cnt];
		mot_cnt++;
		if(mot_cnt > 3) mot_cnt = 0;
		_delay_ms(10);
	}

	_delay_ms(2000); //2초 기다리기 

	mot_cnt = 3;

	for(i = 0;i < 200;i++) //오른쪽 1회전
	{
		PORTB = moy_tbl[mot_cnt];
		mot_cnt--;
		if(mot_cnt < 0) mot_cnt = 3;
		_delay_ms(10);
	}
}

void init_ext_int() //외부인터럽트 사용(밖에서 문잠구기 버튼)
{
	DDRD = 0x00;
	EIMSK = (1 << INT0);
	EICRA = (1 << ISC01) | (1 << ISC00);
}
	
ISR(INT0_vect)
{
	cli();
	Motor_drive();
	sei();
}

void init_keypad()
{
	DDRA = 0x78; //0b01111000; //0bxRRRRCCC//7번 안쓰고 앞에4개 행(출력용),뒤에 3개 열(입력용) // Keypad port
	PORTA = 0x00; //Edit -> replace 

	DDRB = 0xFF;  //motor port
	PORTB = 0x00;

	portOut();   //A,G 출력
	LCDInit();	//lcd 초기화
	waitBusy();

	setPosition(0, 0);
	writeSTR("PASSWORD?");

	setPosition(1, 0);
	writeChar('>');
}

void back_pass() //#기호:b
{
	if(cnt != 0) //정정을 하려면 최소한 1개 이상의 key가 입력된 경우 
	{
		setPosition(1, cnt);
		writeChar(' '); //스페이스 

		setPosition(1, cnt);
		cnt--;
	}

	while((PINA & 0x07) != 0);  //0이 아니면 key가 눌린 상태 //key pad가 다 떨어졌는지 확인하는 문장
}

void reset_check() //*기호:A
{
	unsigned char i;
	clearLCD();
	_delay_ms(10);

	setPosition(0,0);
	writeSTR("Reset!!");
	_delay_ms(1000);

	setPosition(0,0);
	writeSTR("PASSWORD?");

	setPosition(1,0);
	writeChar('>');

	cnt = 0; //몇개 들어왔는지 세는 갯수 리셋 
	loop = 1;
	
	while((PINA & 0x07) != 0);  //0이 아니면 key가 눌린 상태 //key pad가 다 떨어졌는지 확인하는 문장
}


unsigned char passwd_check(unsigned char pass[]) //내가 입력한 비밀번호와 비교 
{
	unsigned char error = 0; //error 가 0이 아니면 비번 맞지 않다 
	unsigned char i;

	for(i=0;i<4;i++){
		if(pass[i] != PASSWD[i])
			error++;
	}

	return error;
}

void passcheck(unsigned char data)
{
	if(cnt != 3)  //4번째 자릿수 key 입력이 아니면 '*'표시 
	{
		writeChar('*');
		pass[cnt++] = data;
	}
	else if(cnt == 3) //4번째 자릿수 key 입력인 경우 
	{
		writeChar('*');
		pass[cnt] = data;
	
		if(passwd_check(pass) != 0)  //password가 잘못 입력된 겨우 
		{
			setPosition(0,0);
			writeSTR("WrongPassWord!");
			setPosition(1,0);
			writeSTR("Plz Check U Pass");
		
			cnt=0;
			_delay_ms(1000);
			clearLCD();
			_delay_ms(50);

			setPosition(0,0);
			writeSTR("PASSWORD?");
			setPosition(1, 0);
			writeChar('>');
			
			loop = 1;
		}
		else  //password가 맞는 경우 
		{
			clearLCD();
			setPosition(0,0);
			writeSTR("Hello MCU_WORLD");

			cnt = 0;
			loop = 0;	//반복을 빠져나오게 함 

			Motor_drive(); //비번 맞으면 회전시키기 
		}
	}
	while((PINA & 0x07) != 0);
}

void get_passwd()  //key scan 
{
	PORTA = ROW_1;
	_delay_ms(1);

	if((PINA & COL_1))
	{
		PORTE = FND_DATA_TBL[1];
		passcheck('1');
	}
	else if((PINA & COL_2))
	{
		PORTE = FND_DATA_TBL[2];
		passcheck('2');
	}
	else if((PINA & COL_3))
	{
		PORTE = FND_DATA_TBL[3];
		passcheck('3');
	}
	_delay_ms(10);

	PORTA = ROW_2;
	_delay_ms(1);

	if((PINA & COL_1))
	{
		PORTE = FND_DATA_TBL[4];
		passcheck('4');
	}
	else if((PINA & COL_2))
	{
		PORTE = FND_DATA_TBL[5];
		passcheck('5');
	}
	else if((PINA & COL_3))
	{
		PORTE = FND_DATA_TBL[6];
		passcheck('6');
	}
	_delay_ms(10);

	PORTA = ROW_3;
	_delay_ms(1);

	if((PINA & COL_1))
	{
		PORTE = FND_DATA_TBL[7];
		passcheck('7');
	}
	else if((PINA & COL_2))
	{
		PORTE = FND_DATA_TBL[8];
		passcheck('8');
	}
	else if((PINA & COL_3))
	{
		PORTE = FND_DATA_TBL[9];
		passcheck('9');
	}
	_delay_ms(10);

	PORTA = ROW_4;
	_delay_ms(1);

	if((PINA & COL_1))
	{
		PORTE = FND_DATA_TBL[10];
		reset_check();
	}
	else if((PINA & COL_2))
	{
//		PORTE = FND_DATA_TBL[0];
		passcheck('0');
	}
	else if((PINA & COL_3))
	{
//		PORTE = FND_DATA_TBL[11];
		back_pass();
	}
	_delay_ms(10);
}

