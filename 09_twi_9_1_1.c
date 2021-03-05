//#include "09_twi.h"

 
/*
//�ܺ� EEPROM�� 'Hello, Yeonsung University!'�� ���� �о �������͹̳ο� ����ϴ� ���α׷��� �ۼ��϶�
//06_usart_6_1_1.c ����  

int main(void)
{
	unsigned char data;
	unsigned char buf[] = "Hello Yeonsung University!";  //���ۿ� data ���� 
	unsigned int i;

	UBRR0L = (unsigned char)BAUD_RATE_L;
	UBRR0H = (unsigned char)BAUD_RATE_H;				  

	UCSR0B = (1 << TXEN) | (1 << RXEN) | (0 << UCSZ2);	//USART Reg Setting	
	UCSR0C = (0 << UPM1) | (0 << UPM0) | (0 << USBS) | (1 << UCSZ1) | (1 << UCSZ0);

	TWBR = (CPU_CLOCK / TWI_FREQ - 16) / 2;				//�ӵ�
	TWSR = (0 << TWPS1) | (0 << TWPS0);					//TWI Reg Setting

	for(i = 0; i < sizeof(buf); i++)  //write data
	{
		TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
		while (!(TWCR&(1 << TWINT)) || TWSR != 0x08);
		//while ((TWCR & (1 << TWINT)) == 0 || TWSR != 0x08); 

		TWDR = 0xA0;
		TWCR = (1 << TWINT) | (1<< TWEN);
		while(!(TWCR & (1 << TWINT)) || TWSR != 0x18);

		TWDR = i & 0xFF;
		TWCR = (1 << TWINT) | (1<< TWEN);
		while(!(TWCR & (1 << TWINT)) || TWSR != 0x28);

		TWDR = buf[i];
		TWCR = (1 << TWINT) | (1<< TWEN);
		while(!(TWCR & (1 << TWINT)) || TWSR != 0x28);

		TWCR = (1 << TWINT) | (1 <<TWSTO) | (1<<TWEN);

		_delay_ms(10);
	}

	for ( i = 0; i < sizeof(buf); i++)  //read data
	{
		TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
		while (!(TWCR&(1 << TWINT)) || TWSR != 0x08);

		TWDR = 0xA0;
		TWCR = (1 << TWINT) | (1<< TWEN);
		while(!(TWCR & (1 << TWINT)) || TWSR != 0x18);

		TWDR = i & 0xFF;
		TWCR = (1 << TWINT) | (1<< TWEN);
		while(!(TWCR & (1 << TWINT)) || TWSR != 0x28);

		TWCR = (1 << TWINT) | (1 <<TWSTO) | (1<<TWEN);
		while(!(TWCR & (1 << TWINT)) || TWSR != 0x10);

		TWDR = 0x0A | 0x01;
		TWCR = (1<<TWINT) | (1<<TWEN);
		while(!(TWCR & (1 << TWINT)) || TWSR != 0x40);

		TWCR = (1 << TWINT) | (1 << TWEN);
		while(!(TWCR & (1 << TWINT)) || TWSR != 0x58);

		data = TWDR;

		TWCR = (1<<TWINT) | (1<<TWSTO) | (1<<TWEN);

		usart_send_byte(data);  //USART ���� 

	}

	return 1;
} 
*/

