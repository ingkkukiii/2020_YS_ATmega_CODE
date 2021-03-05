/*

int main(void)
{
	unsigned char temp;
	int i;

	portOut();
	LCDInit();
	waitBusy();

	setPosition(0,0);
	waitBusy();

	writeStr("**********");
	_delay_ms(2);

	entryShift();

	temp=0x30;

	for(i=0;i<10;i++)
	{
		writeChar(temp+i);
		_delay_ms(1000);
	}
}
*/
