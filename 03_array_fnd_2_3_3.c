/*
//array fnd 2자리씩 분리
//4개의 fnd를 앞 2자리와 뒤 2자리로 분리하여 분,초시계를 만들자 

#include <avr/io.h>
#include <util/delay.h>


#define DDR_FND		DDRC
#define PORT_FND	PORTC
#define PIN_FND		PINC


#define DDR_COM		DDRG
#define PORT_COM	PORTG
#define PIN_COM		PING

int main(void)
{
	unsigned char FND_DATA_TBL[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x27,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};

	unsigned char cnt=0,digit=0,i=0;

	DDR_FND = 0xFF;
	PORT_FND = 0x00;

	DDR_COM = 0x0F;
	PORT_COM = 0x0F;

	while(1){
		for(i=0;i<50;i++)
		{
		//	if(cnt>=1000){
						digit=cnt/1000;
						PORT_COM=0x0E;
						PORT_FND=FND_DATA_TBL[digit];
			//			}
						_delay_ms(5);
		//	if(cnt>=100){
						digit=(cnt/100)%10;
						PORT_COM=0x0D;
						PORT_FND=FND_DATA_TBL[digit];
			//			}
						_delay_ms(5);
		//	if(cnt>=10){
						digit=(cnt/10)%10;
						PORT_COM=0x0B;
						PORT_FND=FND_DATA_TBL[digit];
		//				}
						_delay_ms(5);
		//	if(cnt>=0){
						digit=cnt%10;
						PORT_COM=0x07;
						PORT_FND=FND_DATA_TBL[digit];
			//			}
						_delay_ms(5);
			}
						cnt++;
						if(cnt>9999)cnt=0;
			}
			return 0;
}
*/



#include "2014111064.h"

int main(void)
{
	unsigned char FND_DATA_TBL[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x27,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};

	unsigned int cnt0=0,cnt1=0,cnt2=0,cnt3=0,i;
	
	DDR_FND = 0xFF;
	PORT_FND = 0xFF;

	DDR_COM = 0x0F;
	PORT_COM = 0x0F;

	while(1)
		{
			for(i=0;i<10;i++)
			{
			PORT_COM=0x0E;
			PORT_FND=FND_DATA_TBL[cnt3];
			_delay_ms(5);
			
			PORT_COM=0x0D;
			PORT_FND=FND_DATA_TBL[cnt2];
			_delay_ms(5);
			
			PORT_COM=0x0B;
			PORT_FND=FND_DATA_TBL[cnt1];
			_delay_ms(5);
			
			PORT_COM=0x07;
			PORT_FND=FND_DATA_TBL[cnt0];
			_delay_ms(5);
			}
		cnt0++;
		if(cnt0>9)cnt0=0,cnt1++;
		if(cnt1>5)cnt1=0,cnt2++;
		if(cnt2>9)cnt2=0,cnt3++;
		if(cnt3>5)cnt3=0;
		}
		
		return 0;
		
}	
		

