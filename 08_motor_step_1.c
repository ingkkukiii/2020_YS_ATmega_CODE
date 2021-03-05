//#include"Step_motor.h"
 
/*
int main() //왼쪽 1회전
{
	unsigned char moy_tbl[] = {0x99, 0xCC, 0x66, 0x33}//두개가 중복되어져있도록 배열된게 특징->그래야 구동됨;
	int mot_cnt = 0; //왼쪽 방향 돌리는 
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

/*int main() //오른쪽 1회전
{
	unsigned char moy_tbl[] = {0x99, 0xCC, 0x66, 0x33};
	int mot_cnt = 3; //오른쪽 방향 돌리는 
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
