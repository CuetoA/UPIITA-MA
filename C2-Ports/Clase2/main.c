/*
 * practica 328.c
 * Programa que saca puertos y cambia la salida por pérdida de tiempo
 * Created: 2/25/2022 4:38:36 PM
 *  Author: Cuetorra
 */ 


#define F_CPU 16000000UL		//#define
#include <avr/io.h>				//#include
#include <util/delay.h>

int i=0;						//Variables globales
int A = 0b10101010;				//b=10101010, d=170, h=AA
int B = 85;				//b=01010101, d=85, h=55
int C = 0X00;			//b=00000000, d=0, h=00

//cabecera de función
//funciones

int main(void)
{
	// configuración de máquina
	DDRB = 0X00;
	DDRD = 0XFF;
	
    while(1)
    {
        PORTB = A;
		PORTD = B;
		_delay_ms(1);
		PORTB = B;
		PORTD = A;
		_delay_ms(1);
		PORTB = C;
		PORTD = C;
		_delay_us(1);
    }
}