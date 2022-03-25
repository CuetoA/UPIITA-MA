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
#include <lcdAB.h>


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
	
	DDRD =0x00;		// Input  in D
	PORTD=0xFF;		// 5Volts in D
	DDRC =0xFF;		// Output in C
	LCD_INICIALIZA();
	
	while (1){
		//reciveData();
		ENVIA_DATO('a');
	}
}

void reciveData(){
	val=PINC;	// Receiving value in C
	_delay_us(1000);
	PORTD=val;	// Delivering value in D
	_delay_ms(1000);
}