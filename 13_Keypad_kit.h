#include "LCD.h"
#include "uart.h"
#include "avr/interrupt.h" //4���� 

#define COL_1 0x01	//0b00000001
#define COL_2 0x02	//0b00000010
#define COL_3 0x04	//0b00000100

#define ROW_1 0x08	//0b00001000
#define ROW_2 0x10	//0b00010000
#define ROW_3 0x20	//0b00100000
#define ROW_4 0x40  //0b01000000

unsigned char FND_DATA_TBL[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7C,0x07,0x7F,
								0x67,0x77,0x7C,0x39,0x5E,0x79,0x71,0x08,0x80};//����*:A//�����#:b

unsigned char cnt = 0; //key ���� ���� Ȯ�κ���
unsigned char pass[4] = {0,0,0,0}; //key���������� �key�� ���ȴ��������� ����ó�����̴� �������¸� �����ϴ� �迭���� 
unsigned char PASSWD[] = "1234"; //��� 4�ڸ����ڸ� �迭�� ���ڿ��� ���� 
unsigned char loop = 1; //�������� pw�� ���ö����� ��� 1������ ->�ݺ� 

void Motor_drive() //motor �Լ� �����
{
	unsigned char moy_tbl[] = {0x99, 0xCC, 0x66, 0x33};
	int mot_cnt = 0;
	int i;

	for(i = 0;i < 200;i++) //���� 1ȸ�� 
	{
		PORTB = moy_tbl[mot_cnt];
		mot_cnt++;
		if(mot_cnt > 3) mot_cnt = 0;
		_delay_ms(10);
	}

	_delay_ms(2000); //2�� ��ٸ��� 

	mot_cnt = 3;

	for(i = 0;i < 200;i++) //������ 1ȸ��
	{
		PORTB = moy_tbl[mot_cnt];
		mot_cnt--;
		if(mot_cnt < 0) mot_cnt = 3;
		_delay_ms(10);
	}
}

void init_ext_int() //�ܺ����ͷ�Ʈ ���(�ۿ��� ���ᱸ�� ��ư)
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
	DDRA = 0x78; //0b01111000; //0bxRRRRCCC//7�� �Ⱦ��� �տ�4�� ��(��¿�),�ڿ� 3�� ��(�Է¿�) // Keypad port
	PORTA = 0x00; //Edit -> replace 

	DDRB = 0xFF;  //motor port
	PORTB = 0x00;

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

	while((PINA & 0x07) != 0);  //0�� �ƴϸ� key�� ���� ���� //key pad�� �� ���������� Ȯ���ϴ� ����
}

void reset_check() //*��ȣ:A
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

	cnt = 0; //� ���Դ��� ���� ���� ���� 
	loop = 1;
	
	while((PINA & 0x07) != 0);  //0�� �ƴϸ� key�� ���� ���� //key pad�� �� ���������� Ȯ���ϴ� ����
}


unsigned char passwd_check(unsigned char pass[]) //���� �Է��� ��й�ȣ�� �� 
{
	unsigned char error = 0; //error �� 0�� �ƴϸ� ��� ���� �ʴ� 
	unsigned char i;

	for(i=0;i<4;i++){
		if(pass[i] != PASSWD[i])
			error++;
	}

	return error;
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
		pass[cnt] = data;
	
		if(passwd_check(pass) != 0)  //password�� �߸� �Էµ� �ܿ� 
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
		else  //password�� �´� ��� 
		{
			clearLCD();
			setPosition(0,0);
			writeSTR("Hello MCU_WORLD");

			cnt = 0;
			loop = 0;	//�ݺ��� ���������� �� 

			Motor_drive(); //��� ������ ȸ����Ű�� 
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

