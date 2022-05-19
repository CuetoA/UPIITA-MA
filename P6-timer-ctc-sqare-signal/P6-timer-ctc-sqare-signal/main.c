/*
 * main.c
 *
 * Created: 5/19/2022 12:22:22 PM
 *  Author: Cuetorra
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	cli();
	GTCCR = (1<<TSM) | (1<<PSRSYNC);
	
	OCR1A = 200;					// Ctc value
	DDRB   = (1<<DDB1);				// Output
	TCCR1A = (1<<COM1A0);			// Toggle when ctc
	TCCR1B = (1<<WGM12) | (1<<CS10);// WMG12 to ctc && CS12 to 256 prescaler
	
	GTCCR = 0;
	sei();
	
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}