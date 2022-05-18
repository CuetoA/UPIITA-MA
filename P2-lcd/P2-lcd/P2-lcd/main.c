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
	*	- PORTD ? Input
	*	- PORTC ? Output (LCD)
	*	- PORTB ? Others
	*/
	
	DDRD =0x00;		// Input  in D
	PORTD=0xFF;		// 5Volts in D
	DDRC =0xFF;		// Output in C
	LCD_INICIALIZA();
	CAR_ESP0();
	CAR_ESP1();
	CAR_ESP2();
	CAR_ESP3();
	CAR_ESP4();
	CAR_ESP5();
	CAR_ESP6();
	CAR_ESP7();
	
	
	while (1){
		//ENVIA_CADENA("Hello There ");
		
		ENVIA_DATO(0);	// Skull
		ENVIA_DATO(1);	// Three lines
		ENVIA_DATO(2);	// Spaceship
		ENVIA_DATO(3);	// A Kind of O
		//ENVIA_DATO(' ');
		ENVIA_DATO(4);	// Imperial Destroyer
		ENVIA_DATO(5);	// Rebel Destroyer
		ENVIA_DATO(6);	// Imperial AT-AT
		ENVIA_DATO(7);	// Laser Gunshot

		
		_delay_ms(2000);
		LIMPIA_LCD();
	}
}

void reciveData(){
	val=PINC;	// Receiving value in C
	_delay_us(1000);
	PORTD=val;	// Delivering value in D
	_delay_ms(1000);
}