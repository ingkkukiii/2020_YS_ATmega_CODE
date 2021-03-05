#include <avr/io.h>
#include <avr/delay.h>

void DISP_FND(int cnt) //함수만들기 
{
	unsigned char FND[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
						 0x6D, 0x7D, 0x27, 0x7F, 0x67};

	unsigned char i;

	for(i=0;i<50;i++) //1초 만들기 //조도센서값 1초간 유지 //빠르게 변화보고싶은 i단축(시간조절) 
	{
		PORTC = 0x0E;
		PORTA = FND[(cnt / 1000) % 10];
		_delay_ms(5);

		PORTC = 0x0D;
		PORTA = FND[(cnt / 100) % 10];
		_delay_ms(5);

		PORTC = 0x0B;
		PORTA = FND[(cnt / 10) % 10];
		_delay_ms(5);

		PORTC = 0x07;
		PORTA = FND[(cnt / 1) % 10];
		_delay_ms(5);
	}
}

void ADC_init(void)
{
	ADMUX = (1<<REFS1) | (1<<REFS0);
	ADCSRA = (1<<ADEN) | (1<<ADFR) | (0<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
	ADCSRA = ADCSRA | (1<<ADSC);
}
