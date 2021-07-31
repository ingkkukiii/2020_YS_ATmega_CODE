#include <avr/io.h>
#include <avr/delay.h>

#define LCD_DATA      PORTA     // LCD ������ ��Ʈ ����
#define LCD_INST      PORTA     // LCD ��ɾ� ��Ʈ ����
#define LCD_PIN 	  PINA      // LCD �Է� ��Ʈ ���� 

#define LCD_CTRL      PORTC     // LCD ������Ʈ ����

#define LCD_RS          0		// Register Select(0=instruction, 1=data) 
#define LCD_RW          1		// Read/Write (0 : write, 1: read)
#define LCD_EN          2  		// Enable Signal for Read/Write LCD

#define LCD_CLR             0      // DB0: clear display
#define LCD_HOME            1      // DB1: return to home position

#define LCD_ENTRY_MODE      2      // DB2: set entry mode
#define LCD_ENTRY_INC       1      // DB1: increment
#define LCD_ENTRY_SHIFT     0      // DB2: shift

#define LCD_ON_CTRL         3      // DB3: turn lcd/cursor on
#define LCD_ON_DISPLAY      2      // DB2: turn display on
#define LCD_ON_CURSOR       1      // DB1: turn cursor on
#define LCD_ON_BLINK        0      // DB0: blinking cursor

#define LCD_MOVE            4      // DB4: move cursor/display
#define LCD_MOVE_DISP       3      // DB3: move display (0-> move cursor)
#define LCD_MOVE_RIGHT      2      // DB2: move right (0-> left)

#define LCD_FUNCTION        5      // DB5: function set
#define LCD_FUNCTION_8BIT   4      // DB4: set 8BIT mode (0->4BIT mode)
#define LCD_FUNCTION_2LINES 3      // DB3: two lines (0->one line)
#define LCD_FUNCTION_10DOTS 2      // DB2: 5x10 font (0->5x7 font)

#define LCD_CGRAM           6      // DB6: set CG RAM address
#define LCD_DDRAM           7      // DB7: set DD RAM address
#define LCD_BUSY            7      // DB7: LCD is busy

#define BV(bit)			(1<<(bit))  	    //��� bit�� 1��Ʈ Shift ��Ű�� ����
#define cbi(reg,bit)	reg &= ~(BV(bit))  //Ư��(reg) bit�� 0���� ����� ��     
#define sbi(reg,bit)	reg |= (BV(bit))   //Ư��(reg) bit�� 1���� ����� ��

void portIn(void) //�Է¿� ��Ʈ���� �Լ�
{
      DDRA = 0x00;	// PORTA�� �Է�����
      DDRC = 0x0F;	// PORTG�� ���� 4��Ʈ�� ������� //0xFF
}

void portOut(void) //��¿� ��Ʈ���� �Լ�
{
      DDRA = 0xFF;	// PORTA�� �������
      DDRC = 0x0F;	// PORTG�� ���� 4��Ʈ�� ������� //0xFF
}

void writeCTRL(unsigned char ch) //LCD_IR�� ��ɾ� ���� 
{
	sbi(LCD_CTRL, LCD_EN); //LCD Enable 
	cbi(LCD_CTRL, LCD_RW); //write
	cbi(LCD_CTRL, LCD_RS); //instruction
	_delay_us(50);

	LCD_INST= ch; //PORTA -> instruction
	_delay_us(50);

	cbi(LCD_CTRL, LCD_EN); //LCD Disable	 
}

void writeChar(unsigned char ch) //LCD_DR�� ������ ���
{
	sbi(LCD_CTRL, LCD_EN); //LCD Enable
	cbi(LCD_CTRL, LCD_RW); //write
	sbi(LCD_CTRL, LCD_RS); //data
	_delay_us(50);

	LCD_DATA = ch;  //PORTA -> data
	_delay_us(50);

	cbi(LCD_CTRL, LCD_EN); //LCD Disable
	_delay_ms(1);
}

void writeSTR(unsigned char str[])  //���ڿ� ����Լ� 
{
	unsigned char i = 0;
	
	while(str[i] != 0) //!= ���� �ʴٴ� ������ ���� �ȵ� 
	{
		writeChar(str[i]);
		i++;
	}

}
//void writeSTR(unsigned char *str)
//{
//    while(*str != 0)
//	{
//		writeChar(*str);
//		str++;
//    }
//}

unsigned char readBF()
{
	unsigned char rlt;

	sbi(LCD_CTRL, LCD_EN);  //LCD Enable
	sbi(LCD_CTRL, LCD_RW);	//read
	cbi(LCD_CTRL, LCD_RS);  //instruction
	_delay_us(50);

	rlt = LCD_PIN;
	_delay_us(50);

	cbi(LCD_CTRL, LCD_EN);  //LCD Disable

	return rlt; 
}

void waitBusy() 
{
	portIn(); 
	while((readBF() & (1<<LCD_BUSY)) != 0); //readBF�� 1�̸� �ٻ۰��� Ȯ�� ���� , 0�̸� �ݺ��� �������� 
	portOut(); //LCD�� Ȱ���� ���������� �ٽ� PORTA�� ��¿����� �����ϴ� �Լ�
}

void setPosition(unsigned char row, unsigned char col)  
{
	unsigned char addr; 
		
	if(row == 0)  //row = ������
		addr = col;
	else if(row == 1)  
		addr = 0x40 + col; //col = ���ڿ�
	else 
		addr = 0;

	writeCTRL((1<<LCD_DDRAM) | addr);
	_delay_ms(2);
}
//void setPosition(unsigned char row, unsigned char col)
//{
//      unsigned char addr;
//
//	  switch(row)
//	  {
//	 	case 0: addr = 0x00 + col; break;
//		case 1: addr = 0x40 + col; break;
//		default: addr = 0x00 + col;
//	  }
//
//	  writeCTRL(1<<LCD_DDRAM | addr); 
//}

//��� ���÷��� ���¸� ����� cursor�� Home ��ġ�� �������´�.
void clearLCD() //LCD Display Claer �Լ�
{
	writeCTRL(1 << LCD_CLR);
	_delay_ms(2);
}

//DDRAM�� ������ �������� �ʰ� cursor ���� Home���� ��ġ��Ų��.
void returnHome() //LCD Return Home �Լ�
{
	writeCTRL(1 << LCD_HOME);
	_delay_ms(2);
}

//LCD ȭ���� �������� 1�� �̵�
void displayShiftLeft(void)
{
	writeCTRL(1 << LCD_MOVE | 1 << LCD_MOVE_DISP);
	_delay_ms(2);
}

//LCD ȭ���� ���������� 1�� �̵�
void displayShiftRight(void)
{
	writeCTRL(1 << LCD_MOVE | 1 << LCD_MOVE_DISP | 1 << LCD_MOVE_RIGHT);
	_delay_ms(2);
}

//Ŀ���� �������� 1�� �̵�
void cursorShiftLeft()   
{
	writeCTRL((1<<LCD_MOVE) | (0<<LCD_MOVE_DISP) | (0<<LCD_MOVE_RIGHT)); 
	_delay_ms(2);
}

//Ŀ���� ���������� 1�� �̵�
void cursorShiftRight()  
{
	writeCTRL((1<<LCD_MOVE) | (0<<LCD_MOVE_DISP) | (1<<LCD_MOVE_RIGHT));
	_delay_ms(2);
}

void LCDInit()  //LCD �ʱ�ȭ
{
	writeCTRL((1<<LCD_FUNCTION) | (1<<LCD_FUNCTION_8BIT) | (1<<LCD_FUNCTION_2LINES) | (0<<LCD_FUNCTION_10DOTS));
	_delay_ms(2);
	writeCTRL((1<<LCD_ON_CTRL) | (1<<LCD_ON_DISPLAY) | (1<<LCD_ON_CURSOR) | (0<<LCD_ON_BLINK));
	_delay_ms(2);
	writeCTRL(1<<LCD_CLR);
	_delay_ms(2);
	writeCTRL((1<<LCD_ENTRY_MODE) | (1<<LCD_ENTRY_INC) | (0<<LCD_ENTRY_SHIFT));
	_delay_ms(2);
}
