#include <avr/io.h>
#include <avr/delay.h> 

#define CPU_CLOCK 16000000
#define BAUD_RATE 19200
#define BAUD_RATE_H ((CPU_CLOCK/(16L*BAUD_RATE))-1)>>8
#define BAUD_RATE_L (CPU_CLOCK/(16L*BAUD_RATE))-1

#define BS 0x08  //backspace
#define CR 0x0D  //carrige return 

/* 
carrage return('\r')
: 커서의 위치를 현재 커서가 위치하고 있는 라인의
맨 앞으로 보낸다

line feed('\n')
: 커서를 다음 줄로 옮긴다(커서가 둘째 줄 셋째 칸에 있엇다면
셋째 줄 셋째 칸으로 이동
*/

// usart 초기화
void usart_init() 
{
	UBRR0H = (unsigned char)BAUD_RATE_H;
	UBRR0L = (unsigned char)BAUD_RATE_L;

	UCSR0B = (1<<TXEN) | (1<<RXEN) | (0<<UCSZ2); // 19200bps, no parity, 1-stop bit, 8-data bits
	UCSR0C = (0<<UPM1) | (0<<UPM0) | (0<<USBS) | (1<<UCSZ1) | (1<<UCSZ0);

}

// usart 문자 1byte 송신
void usart_send_byte(unsigned char byte)
{
	while (!(UCSR0A & (1<<UDRE0)));
	UDR0 = byte;
}

// usart usart_send_byte함수를 반복 처리하여 문자열 송신
void usart_send_string(unsigned char *str, unsigned char len)
{
	int i;

	for(i = 0; i < len; i++)
	{
		if(!(*(str + i)))
		{
			break;
		}
		usart_send_byte(*(str + i));
	}
}

// usart 문자 수신
unsigned char usart_recv_byte(void)
{
	while(!(UCSR0A&(1<<RXC0)));
	return UDR0;
}
