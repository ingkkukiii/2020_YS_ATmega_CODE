//#include "Step_motor.h"

//dc모터에서의 속도조절은 1과 0의 길이를 가지고 1이길고 0이짧으면 속도가 빠르게 도는거고 
//1이 짧고 0이 길면 속도가 느리게 도는 pwm방식으로 속도조절이 이루어져있음
//반면 step모터는 {0x99, 0xCC, 0x66, 0x33} 이러한 값들을 주어 (자화시키는 위치의값들)
//위치값을 주고 다시 올라가서 다음 위치값을 줄때까지의 _delay_ms(10) 딜레이시간 (값)을 가지고 속도조절함 

//한백전자 step모터 키트 1상 48번 1-2상 96번 반복해야 1회전이 되는데 여기서는 200번 반복해야 1회전 
//{0x99, 0xCC, 0x66, 0x33} 각각 50번 총 200번 

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
	
	DDRD = 0x00; //외부인터럽트 입력용 
	EIMSK = (1<<INT1) | (1<<INT0);
	EICRA = (1<<ISC11) | (1<<ISC10) | (1<<ISC01) | (1<<ISC00); //상승엣지에서 동작

	sei();

	for(;;)
	{
		if(flag == 0) //왼쪽으로 
		{
			for(i = 0;i < 400;i++) //100 반바퀴, 200 1바퀴, 400 2바퀴 
			{
				PORTB = moy_tbl[mot_cnt];
				mot_cnt++;
				if(mot_cnt > 3) mot_cnt = 0;
				_delay_ms(10); //speed
			}
			flag = 9; //버튼이 눌리지 않는 이상 n번씩만 돌리게 //걸린 인터럽트 해제하기 
		}
		else if(flag == 1) //오른쪽으로 
		{
			for(i = 0;i < 400;i++)
			{
				PORTB = moy_tbl[mot_cnt];
				mot_cnt--;
				if(mot_cnt < 0) mot_cnt = 3;
				_delay_ms(10); //speed
			}
			flag = 9; //버튼이 눌리지 않는 이상 n번씩만 돌리게 //걸린 인터럽트 해제하기 
		}
	}
	return 0;
}
*/
