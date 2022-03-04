/*
 * practica1a 328P.c
 * main.c
 *
 * Created: 2/21/2022 5:56:23 PM
 *  Author: Cuetorra
 *	Programa para prender y apagar puertos del ATMEGA328P
 */ 

// Definimos la velocidad del CPU
#define F_CPU 16000000UL 

#include <avr/io.h>
#include <util/delay.h>

int i=0;

int main(void)
{
	
	DDRB=0B00111111 //En hex: 0X3F, En decimal: 63
	PORTB=0B00111111 //En hex: 0X3F, En decimal: 63
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}