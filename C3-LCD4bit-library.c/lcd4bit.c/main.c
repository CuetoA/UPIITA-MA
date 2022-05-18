/*
 * lcd4bits.c
 * librería para manejar el LCD que emplea el HDD44780
 * de 2 x 16
 * Created: 3/3/2022 7:56:44 PM
 *  Author: Cuetorra
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <inttypes.h>

#define LCD_PUERTO PORTC		// DEFINE EL PUERTO EN DONDE SERÁN CONECTADOS LOS PINES
#define LCD_RS PC0				//DEFINE EL PIN DEL MICROCONTROLADOR
#define  LCD_E PC1

// PROTOTIPOS DE FUNCIONES
void LCD_INICIALIZA();			// INICIALIZA EL LCD
void ENVIA_CMD(char dato);		
void ENVIA_DATO(char dato);
void ENVIA_CADENA(char *dato);
void LIMPIAR_LCD();
void CURSOR_IZQ();
void CURSOR_DER();
void REGRESO_CASA();
void POS_LINEA1(char posicion);
void POS_LINEA2(char posicion);
void POS_LINEA3(char posicion);
void POS_LINEA4(char posicion);


int myfunc(void)
{
	
    return 0;
}