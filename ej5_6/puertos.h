/*
 * puertos.h
 *
 *  Created on: 28 oct. 2023
 *      Author: fabrizio
 */

#ifndef PUERTOS_H_
#define PUERTOS_H_

#include <stdint.h>

//ESTRUCTURAS Y UNIONES

//Estructura que forma bit a bit
typedef struct
{
    uint8_t b0 :1;
    uint8_t b1 :1;
    uint8_t b2 :1;
    uint8_t b3 :1;
    uint8_t b4 :1;
    uint8_t b5 :1;
    uint8_t b6 :1;
    uint8_t b7 :1;
} bit_a_bit_t;

//Estructura de los puertos A y B
typedef struct
{
    bit_a_bit_t a;
    bit_a_bit_t b;
} BAB;

//union entre la estructura de los puertos A y B y del puerto D
typedef union
{
    BAB AB;
    uint16_t D;
} reg_t;

//VARIABLE GLOBAL
reg_t reg = {.D = 0}; // Crear una variable global de tipo reg_t para poder utilizarla en las funciones y macros

//PROTOTIPOS

void bitSet(char port, int bit);		//Función encargada de prender bits individualmente
void bitClr(char port, int bit);		//Función encargada de apagar bits individualmente
int bitGet(char port, int bit);			//Función encargada de devolver el estado de un bit
void bitToggle(char port, int bit);		//Función encargada de cambiar los bits a su estado opuesto
void maskOn(char port, int mask);		//Función encargada de encender los bits coincidentes con una mascara
void maskOff(char port, int mask);		//Funcion encargada de apagar los bits coincidentes con una mascara
char mod_regd(int* bit);				//Función encargada de analizar si se trabaja con la parte A o B del puerto D
int* hex2bin(int largo, int hexa);		//Función encargada de pasar un hexadecimal a binario
void maskToggle(char port, int mask);	//Función encargada de cambiar el estado de los bits coincidentes con una mascara a su opuesto

#endif /* PUERTOS_H_ */
