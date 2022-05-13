/*
 * main.c
 *
 *  Created: 5/12/2022 10:16:45 AM
 *  Author: Cuetorra
 *  Program to use interruptions
 */ 

#define F_CPU 16000000UL
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include <lcdAB.h>
#include <avr/interrupt.h>



void settings();
void printInScreen();
void waitAndClear();


int main(void)
{
	settings();
	waitAndClear();
    while(1){        
		printInScreen();
    }	
}


void settings(){
	cli();
	DDRD  = 0x00;	// ENTRADAS - TECLADO
	PORTD = 0xFF;	// Pull up
	DDRB  = 0x00;	// ENTRADAS - BOTONES
	PORTB = 0xFF;	// Pull up
	DDRC  = 0xFF;	// Pantalla
	
	// Interrupciones internas
	EICRA  |= (1<<ISC01)|(1<<ISC01); // INT0 -> Flanco de subida
	EICRA  |= (1<<ISC11)|(0<<ISC10); // INT1 -> Flanco de bajada
	EIMSK  |= (1<<INT0) |(1<<INT1);
	// Interrupciones externas
	PCICR  |= (1<<PCIE2);
	PCMSK2 |= (1<<PCINT20)|(1<<PCINT21);

	LCD_INICIALIZA();
	CAR_ESP4();
	CAR_ESP5();
	CAR_ESP6();
	
	sei();
	
}


void printInScreen(){
	
	ENVIA_DATO(4);	// Imperial Destroyer
	waitAndClear();
	ENVIA_DATO(5);	// Rebel Destroyer
	waitAndClear();
	ENVIA_DATO(6);	// Imperial AT-AT
	waitAndClear();
	ENVIA_CADENA("Hola");
	waitAndClear();
}


void waitAndClear(){
	_delay_ms(1000);
	LIMPIA_LCD();
}


ISR(INT0_vect){
	LIMPIA_LCD();
	ENVIA_CADENA("INT0");
	waitAndClear();
};


ISR(INT1_vect){
	LIMPIA_LCD();
	ENVIA_CADENA("INT1");
	waitAndClear();
};

	
ISR(PCINT2_vect){
	LIMPIA_LCD();
	ENVIA_CADENA("PCINT18");
	_delay_ms(2000);
	//waitAndClear();
};