//#include "01_led.h"

/* 
//8���� led�� ��->�� �� ���� ������ ������ �ٽ� ��->�� Ŀ���� �����⸦ �ݺ��ϴ� ���α׷�(51p)

void main()
{
	int k = 0; 
	int flag = 0;

	DDRD = 0xFF;
	PORTD = 0x00;

	for(;;)	
	{
		PORTD = (1 << k);
		_delay_ms(1000);

		if(flag == 0)
		{
			k++;
	    	if(k > 7) 
			{
				flag = 1;
			};
		}
		else
		{
			k--;
			if(k < 0)
			{
				flag = 0;
			}
		}
	}
}
*/
