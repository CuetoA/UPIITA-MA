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


void keyboardFunction(char valor_teclado);
void mostrandoDatoEnPantalla(char dato);
void memory_initialization();
void kernel();

int main(void)
{
	/*
	*	- PORTD ? Input
	*	- PORTC ? Output (LCD)
	*	- PORTB ? Others
	*/
	
	kernel();
	memory_initialization();
	char valor_teclado = ' ';
	
	
	
    while(1)
    {
        BARRE_TECLADO();
		_delay_ms(40);
		valor_teclado = LEE_TECLADO();
		_delay_ms(10);
		keyboardFunction(valor_teclado);
    }
}

void keyboardFunction(char valor_teclado){
	switch(valor_teclado)
	{
		case '0':	mostrandoDatoEnPantalla(0);	break;
		case '1':	mostrandoDatoEnPantalla(1);	break;
		case '2':	mostrandoDatoEnPantalla(2);	break;
		case '3':	mostrandoDatoEnPantalla(3);	break;
		case '4':	mostrandoDatoEnPantalla(4);	break;
		case '5':	mostrandoDatoEnPantalla(5);	break;
		case '6':	mostrandoDatoEnPantalla(6);	break;
		case '7':	mostrandoDatoEnPantalla(7);	break;
		case ' ':	break;
		default:	mostrandoDatoEnPantalla(valor_teclado);
	}
}

void mostrandoDatoEnPantalla(char dato){
	LIMPIA_LCD();
	ENVIA_DATO(dato);
}

void kernel(){
	DDRD =0xF0;		// Output: High Nibble,	Input: Low Nibble
	DDRC =0xFF;		// Output in C
	LCD_INICIALIZA();
}
void memory_initialization(){
	CAR_ESP0();
	CAR_ESP1();
	CAR_ESP2();
	CAR_ESP3();
	CAR_ESP4();
	CAR_ESP5();
	CAR_ESP6();
	CAR_ESP7();
	_delay_ms(10);
}
