//#include"Step_motor.h"
 
/*
int main() //���� 1ȸ��
{
	unsigned char moy_tbl[] = {0x99, 0xCC, 0x66, 0x33}//�ΰ��� �ߺ��Ǿ����ֵ��� �迭�Ȱ� Ư¡->�׷��� ������;
	int mot_cnt = 0; //���� ���� ������ 
	int i;

	DDRB = 0xFF;
	PORTB = 0x00;

	for(i = 0;i < 200;i++)
	{
		PORTB = moy_tbl[mot_cnt];
		mot_cnt++;
		if(mot_cnt > 3) mot_cnt = 0;
		_delay_ms(10); //speed
	}
	
	return 0;
}*/

/*int main() //������ 1ȸ��
{
	unsigned char moy_tbl[] = {0x99, 0xCC, 0x66, 0x33};
	int mot_cnt = 3; //������ ���� ������ 
	int i;

	DDRB = 0xFF;
	PORTB = 0x00;

	for(i = 0;i < 200;i++)
	{
		PORTB = moy_tbl[mot_cnt];
		mot_cnt--;
		if(mot_cnt < 0) mot_cnt = 3;
		_delay_ms(10); //speed
	}
	
	return 0;
}
*/
