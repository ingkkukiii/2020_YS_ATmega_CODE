
/*
//1-2상 여상 방식 

int dir = DIR_L;
int speed = 100;

SIGNAL(SIG_INTERRUPT0)
{
	dir = DIR_L;
}
SIGNAL(SIG_INTERRUPT1)
{
	dir = DIR_R;
}
SIGNAL(SIG_INTERRUPT2)
{
	if(speed > 1)
 		speed = (int)(speed * 0.9); //실수가 나와도 정수로 계산 
	else
		speed = 1;
}
SIGNAL(SIG_INTERRUPT3)
{
	if(speed < 500)
	 	speed = (int)(speed * 1.1);
 	else
		speed = 500; 
}

int main()  
{
	unsigned char mot[8] = {0x01, 0x03, 0x02, 0x06, 0x04, 0x0C, 0x08, 0x09}; 
	int i;
	int mot_cnt = 0;	

	DDRC = 0xFF;  //0x0F;
	DDRD = 0x00;  //BT 입력용 

	EIMSK = (1<<INT3) | (1<<INT2) | (1<<INT1) | (1<<INT0);
	EICRA = (1<<ISC31) | (1<<ISC30) |
			(1<<ISC21) | (1<<ISC20) |   
			(1<<ISC11) | (1<<ISC10) |  
			(1<<ISC01) | (1<<ISC00);
	
	sei();
	   
	for(;;)
	{
		PORTC = mot[mot_cnt]; 

		if(dir == DIR_L)
		{
			if(mot_cnt == 7)    
				mot_cnt = 0;
			else 
				mot_cnt++;
		}
		else
		{
			if(mot_cnt == 0)    
				mot_cnt = 7;
			else 
				mot_cnt--;
		}
		_delay_ms(speed);
	}
	return 0;
} 
