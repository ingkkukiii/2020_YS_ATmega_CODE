#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

#define DDR_LED    DDRD
#define PORT_LED   PORTD

#define DDR_BTN    DDRE
