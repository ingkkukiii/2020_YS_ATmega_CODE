/*

int main() 
{
	unsigned char temp;  //변수선언은 메인문 맨앞에다 둔다

	portOut();
	LCDInit();
	waitBusy();

	setPosition(0, 0);

	waitBusy();

	writeStr("123456789");

	entryReward();  //커서방향 바꾸기(역방향) 
	
	_delay_ms(1000);
	writeChar('A');  //(0x41);
	_delay_ms(1000);
	writeChar('B');	 //(66);
	_delay_ms(1000);
	writeChar('C'); 
	_delay_ms(1000);  //writeStr("ABC");

	entryForward();  //커서방향 바꾸기(정방향) 

	_delay_ms(1000);
	cursorShiftRight();  //커서가 오른쪽으로 1칸 이동 
	_delay_ms(1000);
	cursorShiftRight();  //커서가 오른쪽으로 1칸 이동 
	_delay_ms(1000);
 
	portIn();
	temp = readChar();  //읽어들이는 함수 
	portOut();
	

	cursorShiftRight();  //커서가 오른쪽으로 1칸 이동
	_delay_ms(1000);
 
	writeChar(temp);  //출력하기 

	return 0; 
}
*/
