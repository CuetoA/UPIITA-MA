/*
 * main.c
 *
 * Created: 5/23/2022 11:28:46 AM
 * Author: Cuetorra
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <lcdAB.h>
#include <util/delay.h>

int comparison = 250;


int main(void)
{
	DDRD  = (1<<DDD3) | (1<<DDD2);		// ENTRADAS - INT0 Y 1
	PORTD = 0b00001100;					// Pull up in PD3 & PD2 -> Int1 and 0
	DDRC  = 0xFF;						// LCD
	LCD_INICIALIZA();
	_delay_ms(50);
	
	// CTC timer0
	GTCCR = (1<<TSM) | (1<<PSRSYNC);	// STOP CLOCKS
	OCR0A = 250;						// Ctc value
	DDRD = (1<<DDD6) | (1<<DDD5);					// Output
	TCCR0B = (1<<WGM02);				// This and...
	TCCR0A = (0<<WGM01) | (1<<WGM00);	//		   ...and this to set PWM correct phase OCRA
	GTCCR = 0;							// START CLOCLS
	
	DDRB = (1<<DDB1) | (1<<DDB2) | (1<<DDB3);

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
	ENVIA_CADENA("OCR0A + 50");
	_delay_ms(1000);
	LIMPIA_LCD();
	
	if (OCR0A < 205){
		OCR0A += 50;
	}
};


ISR(INT1_vect){
	// Add
	ENVIA_CADENA("OCR0A - 50");
	_delay_ms(1000);
	LIMPIA_LCD();
	
	if (OCR0A > 50){
		OCR0A -= 50;
	}
};