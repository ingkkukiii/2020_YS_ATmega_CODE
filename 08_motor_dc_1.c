////#include "08_motor.h"

/*
unsigned char flag = 1;  //0 or 1�ۿ� �Ⱦ��� ���� ū Ÿ�� �ʿ���� 

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
	DDRB = 0xF0;  //�ΰ��� dc motor ��밡�� //������ dc���� ����
	PORTB = 0x00; //C�� ��Ʈ�� array fnd�� ����Ǿ��־ B����Ʈ �ٲ� 
	DDRD = 0x00;  //0~3�� ���ͷ�Ʈ D����Ʈ 4~7�� E����Ʈ 

	EIMSK = (1<<INT1) | (1<<INT0);  //0x03
	EICRA = (1<<ISC11) | (1<<ISC11) | (1<<ISC01) | (1<<ISC00);  //0x0F
	
	sei();

	for(;;)
	{
		if(flag == 1)
			PORTB = 0x30; //4~7�� bit 0011 ->3 :������(������ȸ��) //5��pin DIR2 : 1 //4��pin PWM2 : �Է½�ȣ 
		else
			PORTB = 0x10; //4~7�� bit 0001 ->1 :������(����ȸ��) //5��pin DIR2 : 0 //6��pin /Enable2 : ����ȣ
	}

	return 0;
}
*/
