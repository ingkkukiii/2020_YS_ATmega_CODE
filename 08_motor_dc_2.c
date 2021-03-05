//#include "08_motor.h"

/*
unsigned char flag = 1;
//volatile : 버전이 낮으면 상관없지만 버전이 높을 경우를 대비해서, 
//무한이 빠지게되는 자동화되는 과정을 무시해버리고 내가 쓴대로 가라 
volatile unsigned int tic_time;   
int speed = 255; // 처음에는 멈추어있게 OCR값 최대치  255 //일단 멈춰있게 하기위해서 255

ISR(INT0_vect) //외부인터럽트 이용 //방향 전환 
{	
	flag = 0; 
}
ISR(INT1_vect) //방향 전환 
{	
	flag = 1; 
}
ISR(INT2_vect) //속도 조절//2.speed가 ocr에다 전달되니까, ocr이라하는 타이머카운터안에 들어가있는 레지스터는 8bit밖에 안됨. 즉, 255까지 밖에 표현이 안됨
{
	if((speed + 25) <= 255) //1.speed가 가질수있는 값은 굉장히 더 큰값도 되겠지만
		speed = speed + 25;
	else 
		speed = 255;  //3. 혹시라도 255를 넘어가는 값이라면 최대값을 255로 하겠다
}
ISR(INT3_vect) //속도 조절
{
	if((speed - 25) >= 0) 
		speed = speed - 25;
	else 
		speed = 0; 	
}
ISR(TIMER0_COMP_vect)//내부인터럽트, COMPARE MATCH기법 //1.조건이 맞으면 무조건 정해진시간만다 인터럽트가 발생함 
{
	tic_time++; //3. 인터럽트 걸릴때마다 tic_time을 하나씩 증가시키는 문장이 필요 
}
//내부적으로 인터럽트를 발생시키는데, 이왕이면 인터럽트에의한 시간지연함수까지 쓰자(기본적인 delay.h가 제공하는거 말구...)
//내부인터럽트에서 타이머카운트 쓸 때, 딜레이함수와 서로 맵핑 되도록하자
void delay_s(unsigned int dsec)  //너무 많은 숫자 줄게 아니고, 시간은 음수의시간은 없으니 unsigned int dsec라는 변수 사용하자 
{
	tic_time = 0;  //11.tic_time 일단0으로 놓고 시작을하고, 전달받은 dsec라는 변수가 내부적인 변수 tic_time보다 크면 while에 머물러있고    
	while(dsec > tic_time); //2. 그때마다 이 while문 딜레이함수를 빠져나가게끔 tic_time을 키워주는//22.tic_time++계속 해서 dsec보다 작다가 거짓되면 빠져나가게끔 만든 함수
}
int main() //방향전환, 속도조절, 내부적인 타이머카운터변수, PCPWM방식을 이용한 모터의 속도조절 프로그램 
{
	DDRB = 0xFF;
	PORTB = 0x00; //다 전원을 끄고 공급하기 시작하겠다.
	DDRD = 0x00; //입력용으로 하겠다.
	
	EIMSK = (1<<INT3) | (1<<INT2) | (1<<INT1) | (1<<INT0);
	EICRA = (1<<ISC31) | (1<<ISC30) | (1<<ISC21) | (1<<ISC20) | //상승엣지 누르는 순간 동작
			(1<<ISC11) | (1<<ISC10) | (1<<ISC01) | (1<<ISC00);
	
	TCCR0 = (1<FOC0) | (0<WGM01) | (1<WGM00) | (1<COM01) | (1<COM00) | (0<<CS02) | (0<<CS01) | (1<<CS00);
	TCNT0 = 0;
	
	OCR0 = 255;
	
	TIMSK = (1<<OCIE0) | (0<<TOIE0);//compare match
	
	sei();
	
	for(;;)
	{
		if(flag == 1)
			PORTB = 0x30;//정방향 
		else
			PORTB = 0x10;
	
		OCR0 = speed;  //ocr이라고 하는 값에 외부적인 버튼에서 셋팅된 값을(speed)전송만 시켜주면 됨
		delay_s(1);
	}
	
	return 0;
}
*/
