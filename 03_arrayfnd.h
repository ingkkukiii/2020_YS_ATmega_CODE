#include <avr/io.h>
#include <avr/delay.h>

#define 	DDR_FND		DDRA //DATA¼± 8bit
#define		PORT_FND	PORTA

#define 	DDR_COM		DDRC //¼±ÅÃ¼± 4bit
#define		PORT_COM	PORTC

unsigned char FND_DATA_TBL[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 
                                0x6D, 0x7D, 0x27, 0x7F, 0x6F, 
				0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};
