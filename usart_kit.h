#define CPU_CLOCK 16000000

#define BAUD_RATE 9600
#define BAUD_RATE_L (CPU_CLOCK / (16L * BAUD_RATE)) - 1
#define BAUD_RATE_H ((CPU_CLOCK / (16L * BAUD_RATE)) - 1) >> 8

unsigned char data; //4���� //�޴������� Ű�е� ���� //��й�ȣ data �ޱ� 

void Init_USART()
{
	UBRR0L = (unsigned char)BAUD_RATE_L;
	UBRR0H = (unsigned char)BAUD_RATE_H;
	UCSR0B = (1 << RXCIE0) | (1 << TXEN0) | (1 << RXEN0) | (0 << UCSZ02);
	UCSR0C = (0 << UPM01) | (0 << UPM00) | (0 << USBS0) | (1 << UCSZ01) | (1 << UCSZ00);
}

void usart_send_byte(unsigned char byte)
{
	while (!(UCSR0A & (1 << UDRE0)));
	UDR0 = byte;
}

void usart_send_string(unsigned char *str, unsigned char len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		if (!(*(str + i)))
		{
			break;
		}
		usart_send_byte(*(str + i));
	}
}

unsigned char usart_recv_byte(void)
{
	while (!(UCSR0A & (1 << RXC0)));
	return UDR0;
}


//4���� 
ISR(USART0_RX_vect) //SIGNAL(SIG_USART0_RECV) //������ ���� //�޴������� Ű�е� ����
{
	cli(); //���ͷ�Ʈ ��ø� ������ 

	data = UDR0; //UDRn : ����/���� ������ ���� �������� 

	if(data == '*')
		reset_check();
	else if(data == '#')
		back_pass();
	else
		passcheck(data);

	sei(); //���ͷ�Ʈ ���͵� ��
}
