//#include "01_led.h"

/*  
//8���� led�� ���ʿ��� ���������� �̵��ϸ鼭 �ϳ��� �״� ������ ���� �����ִ� ���α׷�(49p)

void main()   
{
	int k = 0; 

	DDRD = 0xFF;  //led ��Ʈ�� ��¸��� set
	PORTD = 0x00;  //led ��Ʈ �ʱ�ȭ

	for(;;)	
	{
		PORTD = (1 << k);
		
//		k++;
//	    if(k > 7) k= 0;
		
		if(++k > 7) k = 0;

		_delay_ms(1000);
	}
}
*/


/*
void main()
{
	int k = 0;

	DDRD = 0xFF;
	PORTD = 0x00;

	for(k=0;k<8;k++)	
	{
		PORTD = (1 << k);
		_delay_ms(1000);
	}
	PORTD = 0x00;
}
*/
