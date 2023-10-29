/*
 * puertos.c
 *
 *  Created on: 28 oct. 2023
 *      Author: fabrizio
 */
//INCLUDES
#include <stdio.h>
#include "puertos.h"
#include "switch.h"
#include "aux.h"

reg_t reg = {.D = 0}; // Crear una variable global de tipo reg_t para poder utilizarla en las funciones y macros

int main(void){
	return 0;
}


//FUNCION bitSet
//Encargada de encender bits individualmente
void bitSet(char port, int bit){
	if(port == 'd'){	//Si se quiere trabajar con el puerto D
		port = mod_regd(&bit);	//Analizamos si se trabaja con la parte que incluye el puerto A o el puerto B
	}
	swit1(port, bit); //Llama a la funcion swit1, que prende el bit solicitado
}

//FUNCION bitClr
//Encargada de apagar bits individualmente
void bitClr(char port, int bit){
	if(port == 'd'){			//Si se quiere trabajar con el puerto D
		port = mod_regd(&bit);	//Analizamos si se trabaja con la parte que incluye el puerto A o el puerto B
	}
	swit0(port, bit);			//Llama a la funcion swit0, que apaga el bit solicitado
}

//FUNCION bitGet
//Encargada de devolver el estado de un bit

int bitGet(char port, int bit){
	int estado;
	if(port == 'd'){ 			//Si se quiere trabajar con el puerto D
		port = mod_regd(&bit);	//Analizamos si se trabaja con la parte que incluye el puerto A o el puerto B
	}
	estado = switGet(port, bit); 	//Llama a la funcion switGet, que devuelve el estado del bit solicitado

	return estado;	//Devuelve el valor
}

//FUNCION bitToggle
//Encargada de cambiar los bits a su estado opuesto
void bitToggle(char port, int bit){
	int estado;
	if(port == 'd'){			//Si se quiere trabajar con el puerto D
		port = mod_regd(&bit);	//Analizamos si se trabaja con la parte que incluye el puerto A o el puerto B
	}
	estado = switGet(port, bit);	//Llama a la funcion switGet, que devuelve el estado del bit solicitado
	if(estado == 1){	//Si esta encendido
		swit0(port, bit);	//Llama a swit0 para apagarlo
	}
	else{
		swit1(port, bit);	//Llama a swit 1 para encenderlo
	}
}

//Funcion maskOn
//Encargada de encender los bits coincidentes con una mascara
void maskOn(char port, int mask){
	int nbit, bit , largo = 7, puntero[largo];
	if(port == 'd'){
		largo = 15;
	}
	hex2bin(largo, mask, puntero);
		for(nbit = 0 , bit = 7; nbit <= largo ; nbit++ , bit--){
			if(puntero[nbit] == 1){
				bitSet(port, bit);
			}
		}
}

//Funcion maskOff
//Encargada de apagar los bits coincidentes con una mascara
void maskOff(char port, int mask){
	int nbit, bit , largo = 7, puntero[largo];
	if(port == 'd'){
		largo = 15;
	}
	hex2bin(largo, mask, puntero);
	for(nbit = 0 , bit = 7; nbit <= largo ; nbit++ , bit--){
		if(puntero[nbit] == 1){
			bitClr(port, bit);
		}
	}
}

//Funcion maskToggle
//Encargada de cambiar el estado de los bits coincidentes con una mascara a su opuesto
void maskToggle(char port, int mask){
	int nbit, bit , largo = 7, puntero[largo];
	if(port == 'd'){
		largo = 15;
	}
	hex2bin(largo, mask, puntero);
		for(nbit = 0 , bit = 7; nbit <= largo ; nbit++ , bit--){
			if(puntero[nbit] == 1){
				bitToggle(port, bit);
			}
		}
}
