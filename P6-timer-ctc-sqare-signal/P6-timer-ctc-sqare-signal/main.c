/*
 * main.c
 *
 * Created: 5/19/2022 12:22:22 PM
 *  Author: Cuetorra
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <lcdAB.h>
#include <util/delay.h>

int main(void)
{
	DDRD  = 0x00;						// ENTRADAS - INT0 Y 1
	PORTD = 0xFF;						// Pull up
	DDRC  = 0xFF;						// LCD
	LCD_INICIALIZA();
	_delay_ms(20);
	
	// CTC timer
	GTCCR = (1<<TSM) | (1<<PSRSYNC);	// STOP CLOCKS
	OCR1A  = 200;						// Ctc value
	DDRB   = (1<<DDB1);					// Output
	TCCR1A = (1<<COM1A0);				// Toggle when ctc
	TCCR1B = (1<<WGM12) | (1<<CS12);	// WMG12 to ctc && CS12 to 256 prescaler	
	GTCCR = 0;							// START CLOCLS

	// Int interruptions
	cli();								// CLEAR INTERRUPTIONS
	EICRA  |= (1<<ISC01)|(1<<ISC01); // INT0 -> Flanco de subida
	EICRA  |= (1<<ISC11)|(1<<ISC10); // INT1 -> Flanco de bajada
	EIMSK  |= (1<<INT0) |(1<<INT1);
	sei();								// ENABLE INTERRUPTIONS	
	
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}

ISR(INT0_vect){
	// Add
	ENVIA_CADENA("add == low freq");
	_delay_ms(1000);
	LIMPIA_LCD();
	if (OCR1A < 205){
		OCR1A += 50;
	}
};


ISR(INT1_vect){
	// Add
	ENVIA_CADENA("sub == up freq");
	_delay_ms(1000);
	LIMPIA_LCD();
	if (OCR1A > 50){
		OCR1A -= 50;
	}
};