/*

int main() 
{
	unsigned char temp;  //���������� ���ι� �Ǿտ��� �д�

	portOut();
	LCDInit();
	waitBusy();

	setPosition(0, 0);

	waitBusy();

	writeStr("123456789");

	entryReward();  //Ŀ������ �ٲٱ�(������) 
	
	_delay_ms(1000);
	writeChar('A');  //(0x41);
	_delay_ms(1000);
	writeChar('B');	 //(66);
	_delay_ms(1000);
	writeChar('C'); 
	_delay_ms(1000);  //writeStr("ABC");

	entryForward();  //Ŀ������ �ٲٱ�(������) 

	_delay_ms(1000);
	cursorShiftRight();  //Ŀ���� ���������� 1ĭ �̵� 
	_delay_ms(1000);
	cursorShiftRight();  //Ŀ���� ���������� 1ĭ �̵� 
	_delay_ms(1000);
 
	portIn();
	temp = readChar();  //�о���̴� �Լ� 
	portOut();
	

	cursorShiftRight();  //Ŀ���� ���������� 1ĭ �̵�
	_delay_ms(1000);
 
	writeChar(temp);  //����ϱ� 

	return 0; 
}
*/
