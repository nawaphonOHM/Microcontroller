/*
 * GccApplication5.c
 *
 * Created: 4/20/2018 12:16:41 AM
 * Author : 5810110178
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>


int main(void)
{
    /* Replace with your application code */
	
	PORTC = 0b00000000;
	PORTB = 0b00111111;
	DDRC = 0b11111111;
	TCCR1A = 0b01000100;
	OCR1A = 3575;
	TIMSK1 = 0b00000010;
	TCCR1B = 0b00000001;
	sei ();
    while (1) 
    {
    }
}

ISR (TIMER1_COMPA_vect)
{
	PORTC = ~PORTC;
}

