//#include "LCD.h"

/*
//TEXT LCD에 "YSU Digital"를 표시하는프로그램을 작성하라 

#include "LCD.h"

int main(void) 
{
	portOut();		
    LCDInit();
	waitBusy();

	setPosition(0,0);
	waitBusy();

	writeChar('Y');
	writeChar('S');
	writeChar('U');
	writeChar(' ');

	writeSTR("Digital");
	return 0;
}
*/


/*
int main()
{
	unsigned char str[] = "Hello";

	portOut();
	LCDInit();
	waitBusy();

	/*entryShift();*/	

	setPosition(0, 0);
	waitBusy();

	writeSTR(str);
	/*_delay_ms(2000);
	
	entryReward();*/

	writeSTR("YSU");	
	/*_delay_ms(2000);

	entryForward();*/

	/*writeChar('A');
	writeChar('B');
	writeChar('C');
	writeChar('D');*/
	 
	/*_delay_ms(1000); //커서 이동 
	cursorShiftLeft();
	_delay_ms(1000);
	cursorShiftLeft();
	_delay_ms(1000);
	cursorShiftLeft();*/
	
	/*_delay_ms(1000); //글자 전체가 왼쪽으로 사라짐 
	dispShiftLeft();
	_delay_ms(1000);
	dispShiftLeft();
	_delay_ms(1000);
	dispShiftLeft();*/

	 return 0;
}
*/
