//#include "01_led.h"

/*  
//2.1.1 led가 동시에 일정한 간격으로 커졌다 꺼지는 것을 반복하는 것을 보여주는 프로그램(45p)
//for_반복문_1
void main()   
{
    unsigned char led_status = 0x00;

	DDR_LED = 0xFF;

	PORT_LED = led_status;

	for(;;)
	{
	    led_status = ~led_status;  //~(tild)
		
		PORT_LED = led_status;

		_delay_ms(500);  
	}
	return 0;
}
*/


/*  
//2.1.1 led가 동시에 일정한 간격으로 커졌다 꺼지는 것을 반복하는 것을 보여주는 프로그램(45p)
//for_제한반복문_1
void main()   
{
	int i;
    unsigned char led_status = 0x00;

	DDR_LED = 0xFF;

	PORT_LED = led_status;

	for(i=0;i<10;i++)
	{
	    led_status = ~led_status;  //~(tild)
		
		PORT_LED = led_status;

		_delay_ms(500);  
	}
	return 0;
}
*/


/*  
//led가 동시에 일정한 간격으로 커졌다 꺼지는 것을 반복하는 것을 보여주는 프로그램(45p)
//while_반복문_1

void main()   
{
    unsigned char led_status = 0xF0;

	DDR_LED = 0xFF;

	while(1)
	{
		led_status = ~led_status;  
		PORT_LED = led_status;
		_delay_ms(500);
	}
}
*/


/*  
//2.1.1 led가 동시에 일정한 간격으로 커졌다 꺼지는 것을 반복하는 것을 보여주는 프로그램(45p)
//while_반복문_2

void main()   
{
    unsigned char led_status = 0xF0;

	DDR_LED = 0xFF;

	while(1)
	{
	    PORT_LED = led_status;
		_delay_ms(500);  

		PORT_LED = ~led_status;
		_delay_ms(500);  

	}
}
*/


 
