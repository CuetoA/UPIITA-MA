/*
 * main.c
 *
 * Created: 5/18/2022 2:59:21 PM
 *  Author: Cuetorra
 */ 

#define F_CPU 16000000UL
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <lcdAB.h>
#include <util/delay.h>
#include <avr/interrupt.h>



short int hora = 0, minuto = 0, segundo = 0, i = 0;
ISR(TIMER0_OVF_vect){
	LIMPIA_LCD();
	ENVIA_DATO(i);
	i++;
	if(i==10){
		i = 0;
	}
}


int main(void)
{
	
	cli();
	DDRC  = 0xFF;	// Pantalla
	TCCR0B = (1<<CS02)|(1<<CS01)|(1<<CS00); // 1024 PRESCALE
	TIMSK0 = (1	<<TOIE0);					// TIMER 0 INTERRUPTION
	
	LCD_INICIALIZA();
	sei();
	
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}