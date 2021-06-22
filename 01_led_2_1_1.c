#include "02_led_demo.h"

//반복문을 사용하여 led 8개가 동시에 켜졌다 1초후 꺼지는 동작이 반복되는 프로그램 LV.2
int main(void)  
{
    int i;
    unsigned char led_status = 0x00;

    DDR_LED = 0xFF;
    PORT_LED = led_status;

    for(i=0;i<10;i++)
    {
        led_status = ~led_status;

	PORT_LED = led_status;
	_delay_ms(1000);
    }

    return 0;
}
