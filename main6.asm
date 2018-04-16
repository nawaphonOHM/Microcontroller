;
; AssemblerApplication1.asm
;
; Created: 4/16/2018 9:55:21 PM
; Author : 5810110178
;


; Replace with your application code
.INCLUDE "m328pdef.inc"

.CSEG
		.ORG 0x0000
					RJMP START
		
		.ORG 0x0020
					RJMP OPERATED_INTERRUPT

		.ORG 0x0034

		START:
				LDI R16, 0b00000000
				OUT PORTC, R16
				LDI R16, 0b00111111
				OUT PORTB, R16
				LDI R16, 0b11111111
				OUT DDRC, R16

				LDI R16, 0b00000000
				OUT TCCR0A, R16
				LDI R17, 0b10111101 ;189
				OUT TCNT0, R17
				LDI R16, 0b00000001
				STS 0x6E, R16 ;0x6E is TIMSK0 location. 
				LDI R16, 0b00000011
				OUT TCCR0B, R16
				SEI

		INFINITYLOOP:
						RJMP INFINITYLOOP

		OPERATED_INTERRUPT:
							IN R16, PORTC
							COM R16
							OUT PORTC, R16
							OUT TCNT0, R17
							RETI														
