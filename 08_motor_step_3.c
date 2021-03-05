//#include "Step_motor.h"

/*
unsigned char flag = 9;
int speed = 50;  //_delay_ms()딜레이시간 ()안에들어가는 값을 1~100 10단위로  

ISR(INT0_vect)
{
	flag = 0;
}
ISR(INT1_vect)
{
	flag = 1;
}
ISR(INT2_vect) // 점점 느려짐 
{
	if(speed <= 90)
		speed =	speed +10;
	else
		speed = 100; //최대값을 100으로 두자
}
ISR(INT3_vect) // 점점 빨라짐
{
	if(speed > 10) //delay=0 방지를 위해 '>'만// 최소 1이라도 나올수 있게 
		speed =	speed -10;
	else
		speed = 1; //최소값을 1로 두자 
}

int main()
{
	unsigned char moy_tbl[] = {0x99, 0xCC, 0x66, 0x33};
	int mot_cnt = 3;
	int i;
	
	DDRB = 0xFF;
	PORTB = 0x00;
	DDRD = 0x00; //외부인터럽트 입력용 

	EIMSK = (1<<INT3) | (1<<INT2) | (1<<INT1) | (1<<INT0);
	EICRA = (1<<ISC31) | (1<<ISC30) | (1<<ISC21) | (1<<ISC20) |
			(1<<ISC11) | (1<<ISC10) | (1<<ISC01) | (1<<ISC00); //외부인터럽트에대한 기본적인 레지스터 셋팅 
	sei();

	for(;;)
	{
		if(flag == 0) //왼쪽으로 
		{
//			for(i = 0;i < 400;i++) //100 반바퀴, 200 1바퀴, 400 2바퀴 
//			{
				PORTB = moy_tbl[mot_cnt];
				mot_cnt++;
				if(mot_cnt > 3) mot_cnt = 0;
				_delay_ms(speed);
//			}
//			flag = 9; //버튼이 눌리지 않는 이상 n번씩만 돌리게 //걸린 인터럽트 해제하기 
		}
		else if(flag == 1) //오른쪽으로 
		{
//			for(i = 0;i < 400;i++)
//			{
				PORTB = moy_tbl[mot_cnt];
				mot_cnt--;
				if(mot_cnt < 0) mot_cnt = 3;
				_delay_ms(speed);
//			}
//			flag = 9; //버튼이 눌리지 않는 이상 n번씩만 돌리게 //걸린 인터럽트 해제하기 
		}
	}
	return 0;
}
*/
