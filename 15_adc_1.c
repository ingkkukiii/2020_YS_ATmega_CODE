//include "15_adc.h"

/*
int main()
{
	int cnt = 0; //unsigned char ���� 
	unsigned char i;

	DDRA = 0xFF;
	PORTA = 0x00;
		
	DDRC = 0xFF; //0x0F;//4���ڸ� ������� ���ϱ�
	PORTC = 0xFF; //array fnd�� ���ü��� 0�� enable�١١�//���þ��ϰڴ� ->FF

	DDRF = 0x00; //ADH //f0���� ���ϱ� ��ǻ� 0xFE��� �ĵ� ������� //0x11111110

	ADC_init();

	for(;;)
	{
		for(i=0;i<10;i++)
		{
			while((ADCSRA & 0x10) == 0x00); //while((ADCSRA & 0x10) != 0x10);//ADIF 4�� bit
			cnt = ADCH * 256 + ADCL; //analog 10�� bit�� 10������ �ٲ� ���� 
		}
		cnt = (int)(cnt / 10);

		DISP_FND(cnt); //������Ͽ� ���� �Լ� �ҷ�����
		cnt++;
		if(cnt > 9999) cnt = 0;
	}
	
	return 0;
}
*/
