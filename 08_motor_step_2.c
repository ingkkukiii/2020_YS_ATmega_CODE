//#include "Step_motor.h"

//dc���Ϳ����� �ӵ������� 1�� 0�� ���̸� ������ 1�̱�� 0��ª���� �ӵ��� ������ ���°Ű� 
//1�� ª�� 0�� ��� �ӵ��� ������ ���� pwm������� �ӵ������� �̷��������
//�ݸ� step���ʹ� {0x99, 0xCC, 0x66, 0x33} �̷��� ������ �־� (��ȭ��Ű�� ��ġ�ǰ���)
//��ġ���� �ְ� �ٽ� �ö󰡼� ���� ��ġ���� �ٶ������� _delay_ms(10) �����̽ð� (��)�� ������ �ӵ������� 

//�ѹ����� step���� ŰƮ 1�� 48�� 1-2�� 96�� �ݺ��ؾ� 1ȸ���� �Ǵµ� ���⼭�� 200�� �ݺ��ؾ� 1ȸ�� 
//{0x99, 0xCC, 0x66, 0x33} ���� 50�� �� 200�� 

/*
unsigned char flag = 9;

ISR(INT0_vect)
{
	flag = 0;
}
ISR(INT1_vect)
{
	flag = 1;
}

int main()
{
	unsigned char moy_tbl[] = {0x99, 0xCC, 0x66, 0x33};
	int mot_cnt = 3;
	int i;
	
	DDRB = 0xFF;
	PORTB = 0x00;
	
	DDRD = 0x00; //�ܺ����ͷ�Ʈ �Է¿� 
	EIMSK = (1<<INT1) | (1<<INT0);
	EICRA = (1<<ISC11) | (1<<ISC10) | (1<<ISC01) | (1<<ISC00); //��¿������� ����

	sei();

	for(;;)
	{
		if(flag == 0) //�������� 
		{
			for(i = 0;i < 400;i++) //100 �ݹ���, 200 1����, 400 2���� 
			{
				PORTB = moy_tbl[mot_cnt];
				mot_cnt++;
				if(mot_cnt > 3) mot_cnt = 0;
				_delay_ms(10); //speed
			}
			flag = 9; //��ư�� ������ �ʴ� �̻� n������ ������ //�ɸ� ���ͷ�Ʈ �����ϱ� 
		}
		else if(flag == 1) //���������� 
		{
			for(i = 0;i < 400;i++)
			{
				PORTB = moy_tbl[mot_cnt];
				mot_cnt--;
				if(mot_cnt < 0) mot_cnt = 3;
				_delay_ms(10); //speed
			}
			flag = 9; //��ư�� ������ �ʴ� �̻� n������ ������ //�ɸ� ���ͷ�Ʈ �����ϱ� 
		}
	}
	return 0;
}
*/
