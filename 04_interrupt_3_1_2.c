/*
//BT0~BT03에 LED0~LED3을 1:1로 각각 대응되도록 하여 각 버튼을 누르면 각 대응되는 LED가 1초간 켜졌다가 꺼지도록 한다.(89p)

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
	DDRA = 0xFF;  //출력용 LED
	DDRD = 0x00;  //입력용 BT

	EIMSK = 0x0F;  //0,1,2,3번 인터럽트 사용
	EICRA = 0xFF; 

	sei();   
			 
	for(;;)
	{
		//메인함수에서 아무것도 하지말고 인터럽트만 기다리고 인터럽트가 걸렸을때, 그쪽에서 처리하라 
	}
}
*/
