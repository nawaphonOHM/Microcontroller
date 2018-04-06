/*
 * Microcontroller.c
 *
 * Created: 4/5/2018 5:54:07 PM
 * Author : 5810110178
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include <util/delay.h>

void detect_keypad (void);
void operated_LED (void);

int numberic = 0b00001111;
int loop_control;

int main (void)
{
	DDRB = 0b11110000;
	PORTB = 0b00001111;
	DDRD = 0b11111011;
	PORTD = 0b00000111;
	EICRA = 0b00000010;
	EIMSK = 0b00000001;
	sei();
	
	while (1)
	{
		
	}
}

ISR (INT0_vect)
{
	_delay_ms(100);
	detect_keypad();
	operated_LED();
	numberic = 0b00001111;
}

void detect_keypad (void)
{
	PORTB = 0b00111111;
	
	numberic = PINB;
	numberic &= 0b00001111;
	
	switch (numberic)
	{
		case 0b00000111 :
			numberic = 1;
			break;
		case 0b00001011 :
			numberic = 4;
			break;
		case 0b00001101 :
			numberic = 7;
			break;
		case 0b00001110 :
			numberic = 10;
			break;
	}
	
	if (numberic == 0b00001111)
	{
		PORTB = 0b01011111;
		
		numberic = PINB;
		numberic &= 0b00001111;
		
		switch (numberic)
		{
			case 0b00000111 :
				numberic = 2;
				break;
			case 0b00001011 :
				numberic = 5;
				break;
			case 0b00001101 :
				numberic = 8;
				break;
			case 0b00001110 :
				numberic = 0;
				break;
		}
	}
	
	if (numberic == 0b00001111)
	{
		PORTB = 0b01101111;
		
		numberic = PINB;
		numberic &= 0b00001111;
		
		switch (numberic)
		{
			case 0b00000111 :
				numberic = 3;
				break;
			case 0b00001011 :
				numberic = 6;
				break;
			case 0b00001101 :
				numberic = 9;
				break;
			case 0b00001110 :
				numberic = 11;
				break;
		}
	}
	
	PORTB = 0b00001111;
}

void operated_LED (void)
{
	if (numberic == 0)
	{
		for (loop_control = 5; loop_control > 0; loop_control--)
		{
			PORTD = 0b0000110;
			_delay_ms(200);
			PORTD = 0b00000111;
		}
	}
	else if (numberic < 0b00001111)
	{
		for (loop_control = numberic; loop_control > 0; loop_control--)
		{
			PORTD = 0b00000101;
			_delay_ms(200);
			PORTD = 0b00000111;
		}
	}
}



