//#include "20190610_2018100055.h"

/*
//1상 여자 방식 스텝모터 회전시키는 프로그램 

int main()  
{
	unsigned char mot[4] = {0x01, 0x02, 0x04, 0x08};  //8bit니까 나타낼수 있는 10진수(0~255) unsigned char
	unsigned char i;  //int로 써도 무방

	DDRC = 0xFF; //0x0F;
	PORTC = 0x00; //C번포트의 실제 출력포트로 내보내는 값의 초기값 부여 

	for(i=0;i<=48;i++)  //1바퀴 도는데 7.5도씩 48번 도는게 한스핀 
	{
		PORTC = mot[i % 4];  //0,1,2,3 반복 
		_delay_ms(100);  //0.1초//짧은수록 빨라짐 
	}

	return 0;
}
*/


/*
//1-2상 여상 방식

int main()  
{
	unsigned char mot[8] = {0x01, 0x03, 0x02, 0x06, 0x04, 0x0C, 0x08, 0x09};  
	int i;	

	DDRC = 0xFF; //0x0F;
	
	for(i=0;i<=96;i++)//1바퀴 도는데 7.5도씩 96번 도는게 한스핀 
	{
		PORTC = mot[i % 8];//0~7 반복 
		_delay_ms(10);
	}

	return 0;
}
*/


/*
//1상 여자 방식 
//오른쪽으로 돌리고 싶을때

int main()  
{
	unsigned char mot[4] = {0x01, 0x02, 0x04, 0x08}; //8bit니까 형식이 unsigned char
	int i;	

	DDRC = 0xFF; //0x0F;
	
	for(i=48;i>=0;i--)//1바퀴 도는데 7.5도씩 48번 도는게 한스핀 
	{
		PORTC = mot[i % 4];//0,1,2,3 반복 
		_delay_ms(100);//0.1초//짧은수록 빨라짐 
	}


	return 0;
}
*/

 
/*
//1-2상 여상 방식 
//오른쪽으로 돌리고 싶을때 

int main()  
{
	unsigned char mot[8] = {0x01, 0x03, 0x02, 0x06, 0x04, 0x0C, 0x08, 0x09}; //8bit니까 형식이 unsigned char
	int i;	

	DDRC = 0xFF; //0x0F;
	
	for(i=96;i>=0;i--)//1바퀴 도는데 7.5도씩 96번 도는게 한스핀 
	{
		PORTC = mot[i % 8];//0~7 반복 
		_delay_ms(10);
	}


	return 0;
}
*/


/*
//1상 여자방식을 이용하여 48스텝에 1히전하는 프로그램을 만들자
//1-2상 여자방식을 이용하여 96스텝에 1히전하는 프로그램을 만들자

int main()  
{
	unsigned char mot[8] = {0x01, 0x03, 0x02, 0x06, 0x04, 0x0C, 0x08, 0x09}; 
	int i;
	int mot_cnt = 0;	

	DDRC = 0xFF;  //0x0F;
	
	//1상인 경우  for(i=0;i<=48;i++)
	for(i=0;i<=96;i++)  //1-2상 여상 방식
	{
		PORTC = mot[mot_cnt]; 

		if(mot_cnt == 7)  //1상인 경우 mot_cnt = 3;
			mot_cnt = 0;
		else 
			mot_cnt++;

		_delay_ms(10);
	}
	return 0;
} 
 
int main()  
{
	unsigned char mot[8] = {0x01, 0x03, 0x02, 0x06, 0x04, 0x0C, 0x08, 0x09}; 
	int i;
	int mot_cnt = 0;	

	DDRC = 0xFF;  //0x0F;
	
	//1상인 경우  for(i=0;i<=48;i++)
	for(i=0;i<=96;i++)  //1-2상 여상 방식 
	{
		PORTC = mot[mot_cnt]; 

		if(mot_cnt == 0)  //오른쪽으로 돌릴때   
			mot_cnt = 7;  //1상인 경우 mot_cnt = 3;
		else 
			mot_cnt--;

		_delay_ms(10);
	}
	return 0;
}
*/
