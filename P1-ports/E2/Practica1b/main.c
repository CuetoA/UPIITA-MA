/*
 * Author: Cuetorra
 * Practica1 - Exercise 1 328P.c
 * Created: 2/21/2022 5:56:23 PM
 * Send received data to other port
 */ 

// Defining CPU velocity
# define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int i = 0, val = 0;

int main(void){
	
	DDRB =0x00;
	PORTB=0xFF; 
	DDRD =0xFF;
	
	while (1){
		val=PINB;
		_delay_us(1000);
		PORTD=val;
		_delay_ms(1000);
		
	}
}