//#include "08_motor.h"

/*
unsigned char flag = 1;
//volatile : ������ ������ ��������� ������ ���� ��츦 ����ؼ�, 
//������ �����ԵǴ� �ڵ�ȭ�Ǵ� ������ �����ع����� ���� ����� ���� 
volatile unsigned int tic_time;   
int speed = 255; // ó������ ���߾��ְ� OCR�� �ִ�ġ  255 //�ϴ� �����ְ� �ϱ����ؼ� 255

ISR(INT0_vect) //�ܺ����ͷ�Ʈ �̿� //���� ��ȯ 
{	
	flag = 0; 
}
ISR(INT1_vect) //���� ��ȯ 
{	
	flag = 1; 
}
ISR(INT2_vect) //�ӵ� ����//2.speed�� ocr���� ���޵Ǵϱ�, ocr�̶��ϴ� Ÿ�̸�ī���;ȿ� ���ִ� �������ʹ� 8bit�ۿ� �ȵ�. ��, 255���� �ۿ� ǥ���� �ȵ�
{
	if((speed + 25) <= 255) //1.speed�� �������ִ� ���� ������ �� ū���� �ǰ�����
		speed = speed + 25;
	else 
		speed = 255;  //3. Ȥ�ö� 255�� �Ѿ�� ���̶�� �ִ밪�� 255�� �ϰڴ�
}
ISR(INT3_vect) //�ӵ� ����
{
	if((speed - 25) >= 0) 
		speed = speed - 25;
	else 
		speed = 0; 	
}
ISR(TIMER0_COMP_vect)//�������ͷ�Ʈ, COMPARE MATCH��� //1.������ ������ ������ �������ð����� ���ͷ�Ʈ�� �߻��� 
{
	tic_time++; //3. ���ͷ�Ʈ �ɸ������� tic_time�� �ϳ��� ������Ű�� ������ �ʿ� 
}
//���������� ���ͷ�Ʈ�� �߻���Ű�µ�, �̿��̸� ���ͷ�Ʈ������ �ð������Լ����� ����(�⺻���� delay.h�� �����ϴ°� ����...)
//�������ͷ�Ʈ���� Ÿ�̸�ī��Ʈ �� ��, �������Լ��� ���� ���� �ǵ�������
void delay_s(unsigned int dsec)  //�ʹ� ���� ���� �ٰ� �ƴϰ�, �ð��� �����ǽð��� ������ unsigned int dsec��� ���� ������� 
{
	tic_time = 0;  //11.tic_time �ϴ�0���� ���� �������ϰ�, ���޹��� dsec��� ������ �������� ���� tic_time���� ũ�� while�� �ӹ����ְ�    
	while(dsec > tic_time); //2. �׶����� �� while�� �������Լ��� ���������Բ� tic_time�� Ű���ִ�//22.tic_time++��� �ؼ� dsec���� �۴ٰ� �����Ǹ� ���������Բ� ���� �Լ�
}
int main() //������ȯ, �ӵ�����, �������� Ÿ�̸�ī���ͺ���, PCPWM����� �̿��� ������ �ӵ����� ���α׷� 
{
	DDRB = 0xFF;
	PORTB = 0x00; //�� ������ ���� �����ϱ� �����ϰڴ�.
	DDRD = 0x00; //�Է¿����� �ϰڴ�.
	
	EIMSK = (1<<INT3) | (1<<INT2) | (1<<INT1) | (1<<INT0);
	EICRA = (1<<ISC31) | (1<<ISC30) | (1<<ISC21) | (1<<ISC20) | //��¿��� ������ ���� ����
			(1<<ISC11) | (1<<ISC10) | (1<<ISC01) | (1<<ISC00);
	
	TCCR0 = (1<FOC0) | (0<WGM01) | (1<WGM00) | (1<COM01) | (1<COM00) | (0<<CS02) | (0<<CS01) | (1<<CS00);
	TCNT0 = 0;
	
	OCR0 = 255;
	
	TIMSK = (1<<OCIE0) | (0<<TOIE0);//compare match
	
	sei();
	
	for(;;)
	{
		if(flag == 1)
			PORTB = 0x30;//������ 
		else
			PORTB = 0x10;
	
		OCR0 = speed;  //ocr�̶�� �ϴ� ���� �ܺ����� ��ư���� ���õ� ����(speed)���۸� �����ָ� ��
		delay_s(1);
	}
	
	return 0;
}
*/