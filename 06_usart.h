#include <avr/io.h>
#include <avr/delay.h>

#define CPU_CLOCK 16000000
#define BAUD_RATE 19200
#define BAUD_RATE_H ((CPU_CLOCK/(16L*BAUD_RATE))-1)>>8
#define BAUD_RATE_L (CPU_CLOCK/(16L*BAUD_RATE))-1

#define BS 0x08  //backspace
#define CR 0x0D  //carrige return 

void usart_init()
{
	UBRR0L = (unsigned char)BAUD_RATE_L;
	UBRR0H = (unsigned char)BAUD_RATE_H;
	
	UCSR0B = (1<<TXEN) | (1<<RXEN) | (0<<UCSZ2); //19200bps, no parity, 1-stop bit, 8-data bits
	UCSR0C = (0<<UPM1) | (0<<UPM0) | (0<<USBS) | (1<<UCSZ1) | (1<<UCSZ0);
}

void usart_send_byte(unsigned char byte)
{
	while (!(UCSR0A & (1<<UDRE0)));
	UDR0 = byte;
}

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

unsigned char usart_recv_byte(void)
{
	while(!(UCSR0A&(1<<RXC0)));
	return UDR0;
}
