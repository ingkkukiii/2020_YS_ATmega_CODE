/*
	title   : LED ���� ���� 3
	subject : �ݺ����� ����Ͽ� led�� ��->��, ��->�� �Դٰ��� 1ĭ�� �̵��ϸ鼭 ������ ������ ������ �ݺ��Ǵ� ���α׷� LV.2
*/
#include "02_led.h"

int main(void)  
{
	int k = 0;
	int flag = 0;

	DDR_LED = 0xFF;  
	PORT_LED = 0x00;   

	for(;;)	
	{
		PORT_LED = (1 << k);
		_delay_ms(500);

		if(flag == 0)
		{
			k++;
	    	if(k > 6) //k�� ���� 
			{
				flag = 1;
			};
		}
		else
		{
			k--;
			if(k < 1) //k�� ����
			{
				flag = 0;
			}
		}
	}
}
