/*
 * main.c
 * Created: 3/4/2022 1:04:06 PM
 * Author: Cuetorra
 * Program which turn on leds recurively
 */ 
#define F_CPU 16000000UL
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

int var = 1;
int flag = 0;


int main(void){

	DDRD = 0B00111111;		// d=63 , h=3F , b=0011 1111
	PORTD= 0B00111111;		// d=63 , h=3F , b=0011 1111
	
    while(1){
		
        if (flag == 0){ var *= 2;}
        else { var /= 2;}

        // Aquí debemos imprimir el resultado
		PORTD = var;
		
        if (var == 128)
        flag = 1;
        else if (var == 1)
        flag = 0;
		
		_delay_ms(20);
    }
}