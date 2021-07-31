#include <avr/io.h>
#include <avr/delay.h>

#define LCD_DATA      PORTA     // LCD 데이터 포트 정의
#define LCD_INST      PORTA     // LCD 명령어 포트 정의
#define LCD_PIN 	  PINA      // LCD 입력 포트 정의 

#define LCD_CTRL      PORTC     // LCD 제어포트 정의

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

#define BV(bit)			(1<<(bit))  	    //어떠한 bit를 1비트 Shift 시키는 동작
#define cbi(reg,bit)	reg &= ~(BV(bit))  //특정(reg) bit를 0으로 만드는 것     
#define sbi(reg,bit)	reg |= (BV(bit))   //특정(reg) bit를 1으로 만드는 것

void portIn(void) //입력용 포트지정 함수
{
      DDRA = 0x00;	// PORTA를 입력으로
      DDRC = 0x0F;	// PORTG의 하위 4비트를 출력으로 //0xFF
}

void portOut(void) //출력용 포트지정 함수
{
      DDRA = 0xFF;	// PORTA를 출력으로
      DDRC = 0x0F;	// PORTG의 하위 4비트를 출력으로 //0xFF
}

void writeCTRL(unsigned char ch) //LCD_IR에 명령어 쓰기 
{
	sbi(LCD_CTRL, LCD_EN); //LCD Enable 
	cbi(LCD_CTRL, LCD_RW); //write
	cbi(LCD_CTRL, LCD_RS); //instruction
	_delay_us(50);

	LCD_INST= ch; //PORTA -> instruction
	_delay_us(50);

	cbi(LCD_CTRL, LCD_EN); //LCD Disable	 
}

void writeChar(unsigned char ch) //LCD_DR에 데이터 출력
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

void writeSTR(unsigned char str[])  //문자열 출력함수 
{
	unsigned char i = 0;
	
	while(str[i] != 0) //!= 같지 않다는 연산자 띄어쓰면 안돼 
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
	while((readBF() & (1<<LCD_BUSY)) != 0); //readBF가 1이면 바쁜것을 확인 가능 , 0이면 반복문 빠져나옴 
	portOut(); //LCD에 활용이 가능해져서 다시 PORTA를 출력용으로 지정하는 함수
}

void setPosition(unsigned char row, unsigned char col)  
{
	unsigned char addr; 
		
	if(row == 0)  //row = 문자행
		addr = col;
	else if(row == 1)  
		addr = 0x40 + col; //col = 문자열
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

//모든 디스플레이 상태를 지우고 cursor를 Home 위치에 돌려놓는다.
void clearLCD() //LCD Display Claer 함수
{
	writeCTRL(1 << LCD_CLR);
	_delay_ms(2);
}

//DDRAM의 내용은 변경하지 않고 cursor 만을 Home으로 위치시킨다.
void returnHome() //LCD Return Home 함수
{
	writeCTRL(1 << LCD_HOME);
	_delay_ms(2);
}

//LCD 화면을 왼쪽으로 1번 이동
void displayShiftLeft(void)
{
	writeCTRL(1 << LCD_MOVE | 1 << LCD_MOVE_DISP);
	_delay_ms(2);
}

//LCD 화면을 오른쪽으로 1번 이동
void displayShiftRight(void)
{
	writeCTRL(1 << LCD_MOVE | 1 << LCD_MOVE_DISP | 1 << LCD_MOVE_RIGHT);
	_delay_ms(2);
}

//커서를 왼쪽으로 1번 이동
void cursorShiftLeft()   
{
	writeCTRL((1<<LCD_MOVE) | (0<<LCD_MOVE_DISP) | (0<<LCD_MOVE_RIGHT)); 
	_delay_ms(2);
}

//커서를 오른쪽으로 1번 이동
void cursorShiftRight()  
{
	writeCTRL((1<<LCD_MOVE) | (0<<LCD_MOVE_DISP) | (1<<LCD_MOVE_RIGHT));
	_delay_ms(2);
}

void LCDInit()  //LCD 초기화
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
