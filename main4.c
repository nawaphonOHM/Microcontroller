/*
 * GccApplication3.c
 *
 * Created: 4/15/2018 1:23:53 PM
 * Author : 5810110178
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include <util/delay.h>

char status = 0b00000000;
char current_number = 0;

void add (void);
void reset (void);
void convertedDigiTo7Segment (void);

int main(void)
{
    /* Replace with your application code */
	DDRD = 0b11111011;
	DDRB = 0b11111111;
	PORTB = 0b00111111;
	PORTD = 0b00000000;
	EICRA = 0b00000001;
	EIMSK = 0b00000001;
	TCCR1A = 0b00000000;
	TCCR1B = 0b00000000;
	TCNT1 = 18661;
	TIMSK1 = 0b00000001;
	sei ();
    while (1) 
    {
		
    }
}

ISR (INT0_vect)
{
	if (TCCR1B == 0b00000000)
	{
		TCCR1B ^= 0b00000101;
		_delay_ms(100);
	}
	else
	{
		TCCR1B ^= 0b00000101;
		_delay_ms(100);
		add ();
		convertedDigiTo7Segment ();
		TCNT1 = 18661;
	}
}

ISR (TIMER1_OVF_vect)
{
	TCCR1B ^= 0b00000101;
	TCNT1 = 18661;
	reset ();
	convertedDigiTo7Segment ();
	while (PIND == 0b00000000)
	{
		
	}
}

void add (void)
{
	current_number++;
	current_number %= 16;
}

void reset (void)
{
	current_number = 0;
}

void convertedDigiTo7Segment (void)
{
	switch (current_number)
	{
		case 0 :
				PORTB = 0b00111111;
				break;
		case 1 :
				PORTB = 0b00000110;
				break;
		case 2 :
				PORTB = 0b01011011;
				break;
		case 3 :
				PORTB = 0b01001111;
				break;
		case 4 :
				PORTB = 0b01100110;
				break;
		case 5 :
				PORTB = 0b01101101;
				break;
		case 6 :
				PORTB = 0b01111101;
				break;
		case 7 :
				PORTB = 0b00000111;
				break;
		case 8 :
				PORTB = 0b01111111;
				break;
		case 9 :
				PORTB = 0b01100111;
				break;
		case 10 :
				PORTB = 0b01110111;
				break;
		case 11 :
				PORTB = 0b01111100;
				break;
		case 12 :
				PORTB = 0b00111001;
				break;
		case 13 :
				PORTB = 0b01011110;
				break;
		case 14 :
				PORTB = 0b01111001;
				break;
		case 15 :
				PORTB = 0b01110001;
				break;
	}
}
