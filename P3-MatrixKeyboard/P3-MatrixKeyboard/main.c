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
	//PORTD=0xF0;		// 5Volts in D
	DDRC =0xFF;		// Output in C
	char valor_teclado = ' ';
	LCD_INICIALIZA();
	CAR_ESP0();
	CAR_ESP1();
	CAR_ESP2();
	CAR_ESP3();
	CAR_ESP4();
	CAR_ESP5();
	CAR_ESP6();
	CAR_ESP7();
	_delay_ms(10);
	
    while(1)
    {
        BARRE_TECLADO();
		_delay_ms(40);
		valor_teclado = LEE_TECLADO();
		_delay_ms(10);
		
		switch(valor_teclado)
		{
			case '1':	ENVIA_DATO(4);	break;
			case '2':	ENVIA_DATO(5);	break;
			case '3':	ENVIA_DATO(6);	break;
			case '4':	ENVIA_DATO(7);	break;
		}
		
		
		//ENVIA_DATO(valor_teclado);
		//TODO:: Please write your application code 
		//_delay_ms(1000);
		LIMPIA_LCD();
    }
}