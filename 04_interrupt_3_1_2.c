/*
//BT0~BT03�� LED0~LED3�� 1:1�� ���� �����ǵ��� �Ͽ� �� ��ư�� ������ �� �����Ǵ� LED�� 1�ʰ� �����ٰ� �������� �Ѵ�.(89p)

SIGNAL(SIG_INTERRUPT0)  
{
	PORTA = 0x01; 
	_delay_ms(1000); 
	PORTA = 0x00;
}
SIGNAL(SIG_INTERRUPT1) 
{
	PORTA = 0x02; 
	_delay_ms(1000);
	PORTA = 0x00;
}
SIGNAL(SIG_INTERRUPT2)
{
	PORTA = 0x04; 
	_delay_ms(1000);
	PORTA = 0x00;
}
SIGNAL(SIG_INTERRUPT3)
{
	PORTA = 0x08; 
	_delay_ms(1000);
	PORTA = 0x00;
}

void main()
{
	DDRA = 0xFF;  //��¿� LED
	DDRD = 0x00;  //�Է¿� BT

	EIMSK = 0x0F;  //0,1,2,3�� ���ͷ�Ʈ ���
	EICRA = 0xFF; 

	sei();   
			 
	for(;;)
	{
		//�����Լ����� �ƹ��͵� �������� ���ͷ�Ʈ�� ��ٸ��� ���ͷ�Ʈ�� �ɷ�����, ���ʿ��� ó���϶� 
	}
}
*/
