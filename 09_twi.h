//"07_text_lcd.h"


//twi.h
#include <avr/io.h>
#include <avr/delay.h>

#define CPU_CLOCK	7372800

#define BAUD_RATE	19200  //usart 전송속도 설정 //하이퍼터미널에서도 똑같은 값으로 설정 
#define BAUD_RATE_L	(CPU_CLOCK/(16L * BAUD_RATE))-1
#define BAUD_RATE_H	((CPU_CLOCK / (16L * BAUD_RATE))-1) >>8

#define TWI_FREQ	400000


////////////////////

void usart_send_byte(unsigned char byte)
{
	while (!(UCSR0A & (1<<UDRE0)));
	UDR0 = byte;
}

void usart_send_string(unsigned char *str, unsigned char len)
{
	int i;

	for ( i = 0; i < len; i++)
	{
		if(!(*(str + i)))
		{
			break;
		}

		usart_send_byte(*(str + i));
	}
}

unsigned char usart_recv_byte(void) //읽어드리는 함수 
{
	while (!(UCSR0A & (1 << RXC0)));

	return UDR0;

}

////////////////////

void mem_init()
{
	int i;

	for (i = 0 ; i <16 ; i++)
	{
		    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
		    while (!(TWCR & (1 << TWINT)) || TWSR != 0x08);

		    TWDR = 0xA0 | 0x08; //페이지 번호에 따라 바뀜
		    TWCR = (1 << TWINT) | (1 << TWEN);
		    while (!(TWCR & (1 << TWINT)) || TWSR != 0x18);

		    TWDR = i & 0xFF; //0xFF안써도 됨
		    TWCR = (1 << TWINT) | (1 << TWEN);
		    while (!(TWCR & (1 << TWINT)) || TWSR != 0x28);

		    TWDR =0x00; //null의 값을 써줌
		    TWCR = (1 << TWINT) | (1 << TWEN);
		    while (!(TWCR & (1 << TWINT)) || TWSR != 0x28);

		    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);

		    _delay_ms(10);
		}	
}
