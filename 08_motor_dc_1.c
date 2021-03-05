////#include "08_motor.h"

/*
unsigned char flag = 1;  //0 or 1밖에 안쓰니 굳이 큰 타입 필요없음 

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
	DDRB = 0xF0;  //두개의 dc motor 사용가능 //오른쪽 dc모터 사용시
	PORTB = 0x00; //C번 포트가 array fnd에 연결되어있어서 B번포트 바꿈 
	DDRD = 0x00;  //0~3번 인터럽트 D번포트 4~7번 E번포트 

	EIMSK = (1<<INT1) | (1<<INT0);  //0x03
	EICRA = (1<<ISC11) | (1<<ISC11) | (1<<ISC01) | (1<<ISC00);  //0x0F
	
	sei();

	for(;;)
	{
		if(flag == 1)
			PORTB = 0x30; //4~7번 bit 0011 ->3 :정방향(오른쪽회전) //5번pin DIR2 : 1 //4번pin PWM2 : 입력신호 
		else
			PORTB = 0x10; //4~7번 bit 0001 ->1 :역방향(왼쪽회전) //5번pin DIR2 : 0 //6번pin /Enable2 : 사용신호
	}

	return 0;
}
*/
