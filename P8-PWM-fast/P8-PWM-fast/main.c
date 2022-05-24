/*
 * main.c
 *
 * Created: 5/24/2022 9:56:45 AM
 *  Author: Cuetorra
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <lcdAB.h>
#include <util/delay.h>

int step = 50;
int limit = 255;

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
	TCCR1B  = (0<<WGM13) | (1<<WGM12);				// Mode 1 fast PWM 8 bit
	TCCR1A  = (0<<WGM11) | (1<<WGM10);				// Mode 1 fast PWM 8 bit
	TCCR1B |= (0<<CS12) | (0<<CS11) | (1<<CS10);	// No pre-scaling
	TCCR1A |= (1<<COM1A1) | (1<<COM1A0);			// Toggle just for 9 and 11
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
	if (OCR1A < limit - step){
		OCR1A += step;
	}
	
	// Add
	ENVIA_CADENA("- % D.C. fast");
	_delay_ms(1000);
	LIMPIA_LCD();
};


ISR(INT1_vect){
	// Add
	if (OCR1A > step){
		OCR1A -= step;
	}
	
	ENVIA_CADENA("+ % D.C. fast");
	_delay_ms(1000);
	LIMPIA_LCD();
};
