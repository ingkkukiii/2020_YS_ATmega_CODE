//#include "Step_motor.h"

/*
unsigned char flag = 9;
int speed = 50;  //_delay_ms()�����̽ð� ()�ȿ����� ���� 1~100 10������  

ISR(INT0_vect)
{
	flag = 0;
}
ISR(INT1_vect)
{
	flag = 1;
}
ISR(INT2_vect) // ���� ������ 
{
	if(speed <= 90)
		speed =	speed +10;
	else
		speed = 100; //�ִ밪�� 100���� ����
}
ISR(INT3_vect) // ���� ������
{
	if(speed > 10) //delay=0 ������ ���� '>'��// �ּ� 1�̶� ���ü� �ְ� 
		speed =	speed -10;
	else
		speed = 1; //�ּҰ��� 1�� ���� 
}

int main()
{
	unsigned char moy_tbl[] = {0x99, 0xCC, 0x66, 0x33};
	int mot_cnt = 3;
	int i;
	
	DDRB = 0xFF;
	PORTB = 0x00;
	DDRD = 0x00; //�ܺ����ͷ�Ʈ �Է¿� 

	EIMSK = (1<<INT3) | (1<<INT2) | (1<<INT1) | (1<<INT0);
	EICRA = (1<<ISC31) | (1<<ISC30) | (1<<ISC21) | (1<<ISC20) |
			(1<<ISC11) | (1<<ISC10) | (1<<ISC01) | (1<<ISC00); //�ܺ����ͷ�Ʈ������ �⺻���� �������� ���� 
	sei();

	for(;;)
	{
		if(flag == 0) //�������� 
		{
//			for(i = 0;i < 400;i++) //100 �ݹ���, 200 1����, 400 2���� 
//			{
				PORTB = moy_tbl[mot_cnt];
				mot_cnt++;
				if(mot_cnt > 3) mot_cnt = 0;
				_delay_ms(speed);
//			}
//			flag = 9; //��ư�� ������ �ʴ� �̻� n������ ������ //�ɸ� ���ͷ�Ʈ �����ϱ� 
		}
		else if(flag == 1) //���������� 
		{
//			for(i = 0;i < 400;i++)
//			{
				PORTB = moy_tbl[mot_cnt];
				mot_cnt--;
				if(mot_cnt < 0) mot_cnt = 3;
				_delay_ms(speed);
//			}
//			flag = 9; //��ư�� ������ �ʴ� �̻� n������ ������ //�ɸ� ���ͷ�Ʈ �����ϱ� 
		}
	}
	return 0;
}
*/
