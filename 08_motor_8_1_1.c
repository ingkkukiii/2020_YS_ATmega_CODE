//#include "20190610_2018100055.h"

/*
//1�� ���� ��� ���ܸ��� ȸ����Ű�� ���α׷� 

int main()  
{
	unsigned char mot[4] = {0x01, 0x02, 0x04, 0x08};  //8bit�ϱ� ��Ÿ���� �ִ� 10����(0~255) unsigned char
	unsigned char i;  //int�� �ᵵ ����

	DDRC = 0xFF; //0x0F;
	PORTC = 0x00; //C����Ʈ�� ���� �����Ʈ�� �������� ���� �ʱⰪ �ο� 

	for(i=0;i<=48;i++)  //1���� ���µ� 7.5���� 48�� ���°� �ѽ��� 
	{
		PORTC = mot[i % 4];  //0,1,2,3 �ݺ� 
		_delay_ms(100);  //0.1��//ª������ ������ 
	}

	return 0;
}
*/


/*
//1-2�� ���� ���

int main()  
{
	unsigned char mot[8] = {0x01, 0x03, 0x02, 0x06, 0x04, 0x0C, 0x08, 0x09};  
	int i;	

	DDRC = 0xFF; //0x0F;
	
	for(i=0;i<=96;i++)//1���� ���µ� 7.5���� 96�� ���°� �ѽ��� 
	{
		PORTC = mot[i % 8];//0~7 �ݺ� 
		_delay_ms(10);
	}

	return 0;
}
*/


/*
//1�� ���� ��� 
//���������� ������ ������

int main()  
{
	unsigned char mot[4] = {0x01, 0x02, 0x04, 0x08}; //8bit�ϱ� ������ unsigned char
	int i;	

	DDRC = 0xFF; //0x0F;
	
	for(i=48;i>=0;i--)//1���� ���µ� 7.5���� 48�� ���°� �ѽ��� 
	{
		PORTC = mot[i % 4];//0,1,2,3 �ݺ� 
		_delay_ms(100);//0.1��//ª������ ������ 
	}


	return 0;
}
*/

 
/*
//1-2�� ���� ��� 
//���������� ������ ������ 

int main()  
{
	unsigned char mot[8] = {0x01, 0x03, 0x02, 0x06, 0x04, 0x0C, 0x08, 0x09}; //8bit�ϱ� ������ unsigned char
	int i;	

	DDRC = 0xFF; //0x0F;
	
	for(i=96;i>=0;i--)//1���� ���µ� 7.5���� 96�� ���°� �ѽ��� 
	{
		PORTC = mot[i % 8];//0~7 �ݺ� 
		_delay_ms(10);
	}


	return 0;
}
*/


/*
//1�� ���ڹ���� �̿��Ͽ� 48���ܿ� 1�����ϴ� ���α׷��� ������
//1-2�� ���ڹ���� �̿��Ͽ� 96���ܿ� 1�����ϴ� ���α׷��� ������

int main()  
{
	unsigned char mot[8] = {0x01, 0x03, 0x02, 0x06, 0x04, 0x0C, 0x08, 0x09}; 
	int i;
	int mot_cnt = 0;	

	DDRC = 0xFF;  //0x0F;
	
	//1���� ���  for(i=0;i<=48;i++)
	for(i=0;i<=96;i++)  //1-2�� ���� ���
	{
		PORTC = mot[mot_cnt]; 

		if(mot_cnt == 7)  //1���� ��� mot_cnt = 3;
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
	
	//1���� ���  for(i=0;i<=48;i++)
	for(i=0;i<=96;i++)  //1-2�� ���� ��� 
	{
		PORTC = mot[mot_cnt]; 

		if(mot_cnt == 0)  //���������� ������   
			mot_cnt = 7;  //1���� ��� mot_cnt = 3;
		else 
			mot_cnt--;

		_delay_ms(10);
	}
	return 0;
}
*/
