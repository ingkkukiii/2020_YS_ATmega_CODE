#include "07_textlcd.h"

int main(void) 
{
	portOut();		
    LCDInit();
	waitBusy();

	setPosition(0,0);
	waitBusy();

	//writeChar('Y');
	//writeChar('S');
	//writeChar('U');
	//writeChar(' ');

	//40ÀÚ 
	writeSTR("Yeonsung University Digital Electronic!!Depertment Hwang In Kuk");
	
	//setPosition(1,0);
	//writeSTR("Digital");

	while(1)
	{
		displayShiftLeft();
		_delay_ms(1000);
		//displayShiftRight();
		//_delay_ms(500);
	}
	return 0;
}
