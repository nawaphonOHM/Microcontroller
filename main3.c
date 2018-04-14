/*
 * GccApplication2.c
 *
 * Created: 4/14/2018 8:36:42 PM
 * Author : 5810110178
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

void readInput (void);
void evaluatedInput (void);

char inputValue = 0;
char LEDLocatedChecked = 0b00000000;

int main(void)
{
    /* Replace with your application code */
	DDRC = 0b11111111;
	DDRB = 0b00000000;
	
	
	TCNT1 = 33536; 
	TCCR1A = 0b00000000;
	TIMSK1 = 0b00000001;
	TCCR1B = 0b00000001;
	sei ();
	
    while (1) 
    {
		
    }
}

void readInput ()
{
	inputValue = PINB;
	
	inputValue &= 0b00111111;
}

ISR (TIMER1_OVF_vect)
{
	TCCR1B = 0b00000000;
	TCNT1 = 35536;
	readInput ();
	evaluatedInput ();
	TCCR1B = 0b00000001;
}

void evaluatedInput ()
{
	LEDLocatedChecked << 1;
	LEDLocatedChecked &= 0b00111111;
	
	if (LEDLocatedChecked == 0b00000000)
	{
		LEDLocatedChecked = 0b00000001;
	}
	
	switch (LEDLocatedChecked)
	{
		case 0b00000001 :
							PORTC = 0b00000010;
							DDRC = 0b11111110;
							break;
		case 0b00000010 :
							PORTC = 0b00000001;
							DDRC = 0b11111101; 
							break;
		case 0b00000100 :
							PORTC = 0b00000100;
							DDRC = 0b11111101;
							break;
		case 0b00001000 :
							PORTC = 0b00000010;
							DDRC = 0b11111011;
							break;
		case 0b00010000 :
							PORTC = 0b00000100;
							DDRC = 0b11111110;
							break;
		case 0b00100000 :
							PORTC = 0b00000001;
							DDRC = 0b11111011;
							break;
	}
}

