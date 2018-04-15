/*
 * GccApplication4.c
 *
 * Created: 4/15/2018 9:52:32 PM
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
	TCCR0A = 0b00000000;
	TCNT0 = 189;
	TIMSK0 = 0b00000001;
	sei ();
	TCCR0B = 0b00000011;
    while (1) 
    {
		
    }
}

ISR (TIMER0_OVF_vect)
{
	TCCR0B = 0b00000000;
	TCNT1 = 189;
	PORTC = ~PORTC;
	TCCR0B = 0b00000011;
}

