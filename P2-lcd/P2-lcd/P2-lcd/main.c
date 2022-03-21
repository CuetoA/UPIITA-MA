/*
 * main.c
 * Created: 3/15/2022 8:52:37 PM
 * Author: Cuetorra
 * Program which turn on leds recurively
 */

#define F_CPU 16000000UL
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>


void reciveData();
void dataProcessing();
void characterSelection();
void characterEnv();

int val = 0;

int main(void)
{
	/*
	*	- PORTC ? Input
	*	- PORTD ? Output (LCD)
	*	- PORTB ? Others
	*/
	
	DDRC =0x00;		// Input  in C
	PORTC=0xFF;		// 5Volts in C
	DDRD =0xFF;		// Output in D
	
	while (1){
		reciveData();
		
	}
}

void reciveData(){
	val=PINC;	// Reciving value in C
	_delay_us(1000);
	PORTD=val;	// Delivering value in D
	_delay_ms(1000);
}