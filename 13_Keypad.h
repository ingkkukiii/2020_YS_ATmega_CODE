#include "LCD.h"

#define COL_1 0x01	//0b00000001
#define COL_2 0x02	//0b00000010
#define COL_3 0x04	//0b00000100

#define ROW_1 0x08	//0b00001000
#define ROW_2 0x10	//0b00010000
#define ROW_3 0x20	//0b00100000
#define ROW_4 0x40  //0b01000000

unsigned char FND_DATA_TBL[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7C,0x07,0x7F,
								0x67,0x77,0x7C,0x39,0x5E,0x79,0x71,0x08,0x80};//����*:A//�����#:b

unsigned char cnt = 0; //key ���� ���� Ȯ�κ��� //��й�ȣ 4�ڸ��� 4���� �ٵ��Դ��� �������� ��� key �Է��� �޾ƾ� ��  
unsigned char pass[4] = {0,0,0,0}; //key���������� �key�� ���ȴ��������� ����ó�����̴� �������¸� �����ϴ� �迭���� 
unsigned char PASSWD[] = "1234"; //��� 4�ڸ����ڸ� �迭�� ���ڿ��� ���� 
unsigned char loop = 1; //�������� pw�� ���ö����� ��� 1������ ->�ݺ� 

void init_keypad()
{
	DDRC = 0x78; //0b01111000; //0bxRRRRCCC//7�� �Ⱦ��� �տ�4�� ��(��¿�),�ڿ� 3�� ��(�Է¿�) // Keypad port
	PORTC = 0x00; //Edit -> replace 

	DDRE = 0xFF;  //fnd port
	PORTE = 0x00;

	portOut();   //A,G ���
	LCDInit();	//lcd �ʱ�ȭ
	waitBusy();
	setPosition(0, 0);
	writeSTR("PASSWORD?");

	setPosition(1, 0);
	writeChar('>');
}

void back_pass() //#��ȣ:b
{
	if(cnt != 0) //������ �Ϸ��� �ּ��� 1�� �̻��� key�� �Էµ� ��� 
	{
		setPosition(1, cnt);
		writeChar(' '); //�����̽� 

		setPosition(1, cnt);
		cnt--;
	}

	while((PINC & 0x07) != 0);  //0�� �ƴϸ� key�� ���� ���� //key pad�� �� ���������� Ȯ���ϴ� ����
}

void reset_check() //*��ȣ:A
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

	cnt = 0; //� ���Դ��� ���� ���� ���� 
	loop = 1;
	
	while((PINC & 0x07) != 0);  //0�� �ƴϸ� key�� ���� ���� //key pad�� �� ���������� Ȯ���ϴ� ����
}


unsigned char passwd_check(unsigned char pass[]) //���� �Է��� ��й�ȣ�� �� 
{
	unsigned char error = 0; //error �� 0�� �ƴϸ� ��� ���� �ʴ� 
	unsigned char i;

	for(i=0;i<4;i++){
		if(pass[i] != PASSWD[i])
			error++;
	}

	return error;  //��ȯ�� error�� 0�̸� ��� �¾� ��������, 0�̾ƴϸ� ��� Ʋ��
}

void passcheck(unsigned char data)
{
	if(cnt != 3)  //4��° �ڸ��� key �Է��� �ƴϸ� '*'ǥ�� 
	{
		writeChar('*');
		pass[cnt++] = data;
	}
	else if(cnt == 3) //4��° �ڸ��� key �Է��� ��� 
	{
		writeChar('*');
		pass[cnt] = data;  //passwd_check�Լ��� Ű�е�� �Է��� pw���� �Ѱ��ش� 
	
		if(passwd_check(pass) != 0)  //password�� �߸� �Էµ� �ܿ� //return ���� 0�̾ƴϸ� error
		{
			setPosition(0,0);
			writeSTR("WrongPassWord!");
			setPosition(1,0);
			writeSTR("Plz Check U Pass");
		
			cnt=0; //Ʋ������ �ʱ�ȭ 
			_delay_ms(1000);
			clearLCD();  //lcd�� �ʱ�ȭ 
			_delay_ms(50);

			setPosition(0,0);
			writeSTR("PASSWORD?");
			setPosition(1, 0);
			writeChar('>');
			
			loop = 1;
		}
		else  //password�� �´� ��� 
		{
			clearLCD();
			setPosition(0,0);
			writeSTR("Hello MCU_WORLD");

			cnt = 0;
			loop = 0;	//�ݺ��� ���������� �� 
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

