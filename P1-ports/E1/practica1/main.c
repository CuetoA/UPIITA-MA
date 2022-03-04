/*
 * Author: Cuetorra
 * Practica1 - Exercise 1 328P.c
 * Created: 2/21/2022 5:56:23 PM
 * Turn on and of ports in ATMEGA328P
 */ 

// Defining CPU speed
#define F_CPU 16000000UL 
#include <avr/io.h>
#include <util/delay.h>

// Global variables
int i = 0;
int A = 0b10101010; // d=170 , h=AA , b=10101010
int B = 0b01010101; // d=85  , h=55 , b=01010101
int C = 0x00;


int main(void){
	// Port configuration
	// d= , h= , b=
	DDRB = 0B00111111;		// d=63 , h=3F , b=0011 1111
	PORTB= 0B00111111;		// d=63 , h=3F , b=0011 1111
	DDRD = 0B00111111;		// d=63 , h=3F , b=0011 1111
	PORTD= 0B00111111;		// d=63 , h=3F , b=0011 1111
	
	while (1){
		PORTB = A;
		PORTD = B;
		_delay_ms(1000);
		PORTB = B;
		PORTD = A;
		_delay_ms(1000);
		PORTB = C;
		PORTD = C;
		_delay_us(100);
	};
	return 0;
}