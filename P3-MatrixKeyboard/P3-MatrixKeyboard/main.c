/*
 * main.c
 *
 * Created: 3/28/2022 5:33:47 PM
 *  Author: Cuetorra
 */ 

#define F_CPU 16000000UL
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include "Include/scaningKeyboard.h"
#include "Include/lcdLib.h"

int main(void)
{
	/*
	*	- PORTD ? Input
	*	- PORTC ? Output (LCD)
	*	- PORTB ? Others
	*/
	
	DDRD =0xF0;		// O / I  in D,   Output: High Nibble,	Input: Low Nibble
	PORTD=0xF0;		// 5Volts in D
	DDRC =0xFF;		// Output in C
	
    while(1)
    {
        BARRE_TECLADO();
		
		//TODO:: Please write your application code 
    }
}