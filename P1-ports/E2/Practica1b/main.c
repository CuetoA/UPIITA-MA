/*
 * main.c
 *
 * Created: 2/25/2022 5:23:55 PM
 *  Author: Cuetorra
 */ 
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>


int i=0, val=0;


#include <xc.h>

int main(void)
{
	DDRB=0X00;
	PORTB=0XFF;
	DDRD=0XFF;

	
	
    while(1)
    {
        val=PINB;
		_delay_us(500);
		PORTD=val;
		_delay_us(250);
		// cada 80 cambiar de operación
		// cero, dividir moltiplicar
    }
}