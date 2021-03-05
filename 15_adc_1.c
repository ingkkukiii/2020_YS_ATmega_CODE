//include "15_adc.h"

/*
int main()
{
	int cnt = 0; //unsigned char 부족 
	unsigned char i;

	DDRA = 0xFF;
	PORTA = 0x00;
		
	DDRC = 0xFF; //0x0F;//4가닥만 출력으로 쓰니까
	PORTC = 0xFF; //array fnd의 선택선은 0이 enable☆☆☆//선택안하겠다 ->FF

	DDRF = 0x00; //ADH //f0번만 쓰니까 사실상 0xFE라고 쳐도 상관없음 //0x11111110

	ADC_init();

	for(;;)
	{
		for(i=0;i<10;i++)
		{
			while((ADCSRA & 0x10) == 0x00); //while((ADCSRA & 0x10) != 0x10);//ADIF 4번 bit
			cnt = ADCH * 256 + ADCL; //analog 10개 bit를 10진수로 바꾼 형태 
		}
		cnt = (int)(cnt / 10);

		DISP_FND(cnt); //헤더파일에 만든 함수 불러오기
		cnt++;
		if(cnt > 9999) cnt = 0;
	}
	
	return 0;
}
*/
