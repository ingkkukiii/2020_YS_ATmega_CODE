
/*
//Timer/Counter �̿�
//1-2�� ���� ��� 

unsigned char tic_time = 0;  //�������� 

SIGNAL(SIG_OVERFLOW0)
{
	tic_time++;
	TCNT0 = 184;
}

void delay_10ms(unsigned char dsec)
{
	tic_time = 0;
	while(dsec > tic_time);
}

int main()   
{
	unsigned char mot[8] = {0x01, 0x03, 0x02, 0x06, 0x04, 0x0C, 0x08, 0x09}; 
	int i;
	int mot_cnt = 0;	

	DDRC = 0xFF;  //0x0F;

	TCCR0 = (1<<CS02) | (1<<CS01) | (1<<CS00);  //1024�б� 
	TIMSK = (0<<OCIE0) | (1<<TOIE0);
	TCNT0 = 184;
	
	sei();

	for(;;)
	{
		for(i=0;i<=192;i++)  //���� �ι��� 
		{
			PORTC = mot[mot_cnt]; 
			if(mot_cnt == 7)    
				mot_cnt = 0;
			else 
				mot_cnt++;

			delay_10ms(1);
		}

		for(i=0;i<=192;i++)  //������ �ι��� 
		{
			PORTC = mot[mot_cnt]; 
			if(mot_cnt == 0)    
				mot_cnt = 7;
			else 
				mot_cnt--;

			delay_10ms(1);  //_delay_ms(10);//1/1000 ��ſ� 
		}
	}
	return 0;
}*/ 
