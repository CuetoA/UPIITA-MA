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
	cli();								// CLEAR INTERRUPTIONS
	GTCCR = (1<<TSM) | (1<<PSRSYNC);	// STOP CLOCKS
	
	
	DDRD  = 0x00;						// ENTRADAS - INT0 Y 1
	PORTD = 0xFF;						// Pull up
	DDRC  = 0xFF;						// LCD
	LCD_INICIALIZA();
	
	
	// CTC timer
	OCR1A = 200;					// Ctc value
	DDRB   = (1<<DDB1);				// Output
	TCCR1A = (1<<COM1A0);			// Toggle when ctc
	TCCR1B = (1<<WGM12) | (1<<CS12);// WMG12 to ctc && CS12 to 256 prescaler
	
	
	// Int interruptions
	EICRA  |= (1<<ISC01)|(1<<ISC01); // INT0 -> Flanco de subida
	EICRA  |= (1<<ISC11)|(0<<ISC10); // INT1 -> Flanco de bajada
	EIMSK  |= (1<<INT0) |(1<<INT1);
	
	
	
	GTCCR = 0;							// START CLOCLS
	sei();								// ENABLE INTERRUPTIONS
	
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}

ISR(INT0_vect){
	// Add
	LIMPIA_LCD();
	ENVIA_CADENA("sumando");
	_delay_ms(500);
	if (OCR1A < 200){
		OCR1A += 50;
	}
};


ISR(INT1_vect){
	// Add
	LIMPIA_LCD();
	ENVIA_CADENA("restando");
	_delay_ms(500);
	if (OCR1A > 50){
		OCR1A -= 50;
	}
	
};