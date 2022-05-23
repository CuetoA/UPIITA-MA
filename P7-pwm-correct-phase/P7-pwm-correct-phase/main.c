/*
 * main.c
 *
 * Created: 5/23/2022 11:28:46 AM
 * Author: Cuetorra
 * Connect osciloscope to PB1 AT 9
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
	
	//// CTC timer
	GTCCR   = (1<<TSM) | (1<<PSRSYNC);				// STOP CLOCKS
	OCR1A   = 3000;									// Ctc value
	DDRB    = (1<<DDB1);							// Output
	TCCR1B  = (1<<WGM13) | (0<<WGM12);				// Mode 1 PWM correct phase 8 bit
	TCCR1A  = (1<<WGM11) | (1<<WGM10);				// Mode 1 PWM correct phase 8 bit
	TCCR1B |= (0<<CS12) | (0<<CS11) | (1<<CS10);	// No pre-escaling
	TCCR1A |= (0<<COM1A1) | (1<<COM1A0);			// Toggle just for 9 and 11
	GTCCR = 0;							// START CLOCLS

	// Int interruptions
	cli();								// CLEAR INTERRUPTIONS
	EICRA  |= (1<<ISC01)|(1<<ISC01); // INT0 -> Flanco de subida
	EICRA  |= (1<<ISC11)|(1<<ISC10); // INT1 -> Flanco de subida
	EIMSK  |= (1<<INT0) |(1<<INT1);
	sei();								// ENABLE INTERRUPTIONS
	
	
	while(1)
	{
		//TODO:: Please write your application code
	}
}

ISR(INT0_vect){
	// Add
	ENVIA_CADENA("OCR1A + 50");
	_delay_ms(1000);
	LIMPIA_LCD();
	
	if (OCR1A < 64000){
		OCR1A += 1000;
	}
};


ISR(INT1_vect){
	// Add
	ENVIA_CADENA("OCR1A - 50");
	_delay_ms(1000);
	LIMPIA_LCD();
	
	if (OCR1A > 1000){
		OCR1A -= 1000;
	}
};