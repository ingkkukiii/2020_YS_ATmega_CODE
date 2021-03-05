#include "LCD.h"

#define COL_1 0x01	//0b00000001
#define COL_2 0x02	//0b00000010
#define COL_3 0x04	//0b00000100

#define ROW_1 0x08	//0b00001000
#define ROW_2 0x10	//0b00010000
#define ROW_3 0x20	//0b00100000
#define ROW_4 0x40  //0b01000000

unsigned char FND_DATA_TBL[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7C,0x07,0x7F,
								0x67,0x77,0x7C,0x39,0x5E,0x79,0x71,0x08,0x80};//리셋*:A//지우기#:b

unsigned char cnt = 0; //key 들어온 갯수 확인변수 //비밀번호 4자리에 4개가 다들어왔느냐 그전까진 계속 key 입력을 받아야 함  
unsigned char pass[4] = {0,0,0,0}; //key누를때마다 어떤key가 눌렸는지에대한 숫자처럼보이는 문자형태를 저장하는 배열변수 
unsigned char PASSWD[] = "1234"; //비번 4자리문자를 배열로 문자열로 선언 
unsigned char loop = 1; //정상적인 pw가 들어올때까지 계속 1로유지 ->반복 

void init_keypad()
{
	DDRC = 0x78; //0b01111000; //0bxRRRRCCC//7번 안쓰고 앞에4개 행(출력용),뒤에 3개 열(입력용) // Keypad port
	PORTC = 0x00; //Edit -> replace 

	DDRE = 0xFF;  //fnd port
	PORTE = 0x00;

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

	while((PINC & 0x07) != 0);  //0이 아니면 key가 눌린 상태 //key pad가 다 떨어졌는지 확인하는 문장
}

void reset_check() //*기호:A
{
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
	
	while((PINC & 0x07) != 0);  //0이 아니면 key가 눌린 상태 //key pad가 다 떨어졌는지 확인하는 문장
}


unsigned char passwd_check(unsigned char pass[]) //내가 입력한 비밀번호와 비교 
{
	unsigned char error = 0; //error 가 0이 아니면 비번 맞지 않다 
	unsigned char i;

	for(i=0;i<4;i++){
		if(pass[i] != PASSWD[i])
			error++;
	}

	return error;  //반환값 error가 0이면 비번 맞아 다음진행, 0이아니면 비번 틀림
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
		pass[cnt] = data;  //passwd_check함수에 키패드로 입력한 pw값을 넘겨준다 
	
		if(passwd_check(pass) != 0)  //password가 잘못 입력된 겨우 //return 값이 0이아니면 error
		{
			setPosition(0,0);
			writeSTR("WrongPassWord!");
			setPosition(1,0);
			writeSTR("Plz Check U Pass");
		
			cnt=0; //틀렸으니 초기화 
			_delay_ms(1000);
			clearLCD();  //lcd도 초기화 
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
		}
	}
	while((PINC & 0x07) != 0);
}

void get_passwd()  //key scan 
{
	PORTC = ROW_1;
	_delay_ms(1);

	if((PINC & COL_1))
	{
		PORTE = FND_DATA_TBL[1];
		passcheck('1');
	}
	else if((PINC & COL_2))
	{
		PORTE = FND_DATA_TBL[2];
		passcheck('2');
	}
	else if((PINC & COL_3))
	{
		PORTE = FND_DATA_TBL[3];
		passcheck('3');
	}
	_delay_ms(10);

	PORTC = ROW_2;
	_delay_ms(1);

	if((PINC & COL_1))
	{
		PORTE = FND_DATA_TBL[4];
		passcheck('4');
	}
	else if((PINC & COL_2))
	{
		PORTE = FND_DATA_TBL[5];
		passcheck('5');
	}
	else if((PINC & COL_3))
	{
		PORTE = FND_DATA_TBL[6];
		passcheck('6');
	}
	_delay_ms(10);

	PORTC = ROW_3;
	_delay_ms(1);

	if((PINC & COL_1))
	{
		PORTE = FND_DATA_TBL[7];
		passcheck('7');
	}
	else if((PINC & COL_2))
	{
		PORTE = FND_DATA_TBL[8];
		passcheck('8');
	}
	else if((PINC & COL_3))
	{
		PORTE = FND_DATA_TBL[9];
		passcheck('9');
	}
	_delay_ms(10);

	PORTC = ROW_4;
	_delay_ms(1);

	if((PINC & COL_1))
	{
		PORTE = FND_DATA_TBL[10];
		reset_check();
	}
	else if((PINC & COL_2))
	{
		PORTE = FND_DATA_TBL[0];
		passcheck('0');
	}
	else if((PINC & COL_3))
	{
		PORTE = FND_DATA_TBL[11];
		back_pass();
	}
	_delay_ms(10);
}

