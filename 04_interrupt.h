#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

//기호상수
#define DDR_LED    DDRA
#define PORT_LED   PORTA

#define DDR_BTN    DDRD
