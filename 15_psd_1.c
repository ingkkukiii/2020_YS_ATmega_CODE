//include "15_adc.h"

/*
int main(void)
{
	int sum = 0;
	int disp = 0;
	int i;

	DDRF = 0x00;
	DDRA = 0xFF;
	DDRC = 0xFF;

	ADC_init();

	for(;;)
	{
		for(i=0; i<10; i++)
		{
		while((ADCSRA & 0x10) != 0x10);

		sum = ADCH*256+ADCL;
		}

		sum = (int)(sum / 10);
	
		if(sum > 188)
			//모터 종료
		else
			//모터 구동 

		if(sum > 745)
			dist = 10;
		else if(sum > 512)
			dist = 15;
		else if(sum > 397)
			dist = 20;
		else if(sum > 331)
			dist = 25;
		else if(sum > 283)
			dist = 30;
		else if(sum > 255)
			dist = 35;
		else if(sum > 224)
			dist = 40;
		else if(sum > 200)
			dist = 45;
		else if(sum > 188)
			dist = 50;
		else if(sum > 171)
			dist = 55;
		else if(sum > 164)
			dist = 60;
		else if(sum > 151)
			dist = 65;
		else if(sum > 116)
			dist = 70;
		else if(sum > 110)
			dist = 75;
		else 
			dist = 80;

		Disp_FND(sum);
	}
	return 0;
}
*/
