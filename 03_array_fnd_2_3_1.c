//#include "03_array_fnd.h"

/*
//array fnd로 "1234"를 출력해본다.(60p)

#define DDR_FND		DDRD
#define PORT_FND	PORTD

#define DDR_COM		DDRG
#define PORT_COM	PORTG

void main()
{
	unsigned char FND[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
		   				   0x6D, 0x7D, 0x27, 0x7F, 0x6F};

	DDR_FND = 0xFF; //8가닥 다 쓰니까 
	PORT_FND = 0x00;

	DDR_COM = 0x0F; //4가닥만 쓰니까 
	PORT_COM = 0x0F;

	while(1)
	{
		PORT_COM = 0x0E;  //array_fnd 1번째 칸 0000 1110
		PORT_FND = FND[1];
		_delay_ms(1000);

		PORT_COM = 0x0D;  //array_fnd 2번째 칸 0000 1101
		PORT_FND = FND[2];
		_delay_ms(1000);

		PORT_COM = 0x0B;  //array_fnd 3번째 칸 0000 1011
		PORT_FND = FND[3];
		_delay_ms(1000);

		PORT_COM = 0x07;  //array_fnd 4번째 칸 0000 0111
		PORT_FND = FND[4];
		_delay_ms(1000);

}
*/


/*
int main()  
{
	unsigned char FND[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
							0x6D, 0x7D, 0x27, 0x7F, 0x6F};
	
	int cnt = 1234; //고정된 숫자로 출력 하는법  
	unsigned char i; //반복을 제어할 양의 정수 0~255 1바이트  

	DDRA = 0xFF; //출력용 
	PORTA = 0x00; //불 끈다

	DDRG = 0xFF; //0b00001111 = 0x0F 이지만 돈케어 
	PORTG = 0xFF; // 소자 특성상 1이 안보내는거 0이 흐르는거 초반엔 1로해둔다

	for(;;)
	{
		PORTA = FND[(cnt / 1000) % 10];
		PORTG = 0x0E; 
		_delay_ms(5);

        PORTA = FND[(cnt / 100) % 10];
		PORTG = 0x0D; 
		_delay_ms(5);

		PORTA = FND[(cnt / 10) % 10];
		PORTG = 0x0B; 
		_delay_ms(5);

		PORTA = FND[(cnt / 1) % 10];
		PORTG = 0x07; 
		_delay_ms(5);

		_delay_ms(100);
	}


	return 0;
}
*/
