//#include "20190610_2018100055.h"//5300

/*
//1상 여자 방식 

int main()  
{
	unsigned char mot[8] = {0x1, 0x2, 0x4, 0x8}; 
	int i;
	int mot_cnt = 0;	

	DDRC = 0xFF; //0x0F;

	for(;;)
	{
		for(i=0;i<=96;i++)  //왼쪽 두바퀴 
		{
			PORTC = mot[mot_cnt]; 
			if(mot_cnt == 7)    
				mot_cnt = 0;
			else 
				mot_cnt++;

			_delay_ms(10);
		}

		for(i=0;i<=96;i++)  //오른쪽 두바퀴 
		{
			PORTC = mot[mot_cnt]; 
			if(mot_cnt == 0)    
				mot_cnt = 7;
			else 
				mot_cnt--;

			_delay_ms(10);
		}
	}
	return 0;
}


/*
//1-2상 여상 방식 

int main()  
{
	unsigned char mot[8] = {0x01, 0x03, 0x02, 0x06, 0x04, 0x0C, 0x08, 0x09}; 
	int i;
	int mot_cnt = 0;	

	DDRC = 0xFF; //0x0F;

	for(;;)
	{
		for(i=0;i<=192;i++)//왼쪽 두바퀴 
		{
			PORTC = mot[mot_cnt]; 
			if(mot_cnt == 7)    
				mot_cnt = 0;
			else 
				mot_cnt++;

			_delay_ms(10);
		}

		for(i=0;i<=192;i++)//오른쪽 두바퀴 
		{
			PORTC = mot[mot_cnt]; 
			if(mot_cnt == 0)    
				mot_cnt = 7;
			else 
				mot_cnt--;

			_delay_ms(10);
		}
	}
	return 0;
} 

 
