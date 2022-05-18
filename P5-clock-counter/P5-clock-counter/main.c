/*
 * main.c
 *
 * Created: 5/18/2022 2:59:21 PM
 *  Author: Cuetorra
 */ 

#define F_CPU 16000000UL
#include <stdio.h>
#include <stdlib.h> //para usar dtostrf
#include <avr/io.h>
#include <lcdAB.h>
#include <string.h>
#include <util/delay.h>
#include <avr/interrupt.h>


char	  hora_s[17], minuto_s[17], segundo_s[17], solver[17], time[8];
short int hora = 0, minuto = 0, segundo = 0, i = 0;
void count_time(){
	segundo++;
	if(segundo == 60){
		segundo = 0;
		minuto += 1;
	}
	if(minuto == 60){
		minuto = 0;
		hora = 24;
	}
	if(hora == 24 ){
		hora = 0;
	}
}

void print_string(){
	
	dtostrf(segundo,2,0,segundo_s);
	dtostrf(minuto,2,0,minuto_s);
	dtostrf(hora,2,0,hora_s);
	
	strcat(time,segundo_s);
	strcat(time," : ");
	strcat(time,minuto_s);
	strcat(time," : ");
	strcat(time,hora_s);
	ENVIA_CADENA(time);
}


ISR(TIMER0_OVF_vect){
	LIMPIA_LCD();
	
	count_time();
	print_string();
	//dtostrf(i,2,0,solver);
	
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