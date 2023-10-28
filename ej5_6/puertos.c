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
	int nbit, bit , largo = 7;
	if(port == 'd'){
		largo = 15;
	}
	int *puntero = hex2bin(largo, mask);
		for(nbit = 0 , bit = 7; nbit <= largo ; nbit++ , bit--){
			if(puntero[nbit] == 1){
				bitSet(port, bit);
			}
		}
}

//Funcion maskOff
//Encargada de apagar los bits coincidentes con una mascara
void maskOff(char port, int mask){
	int nbit, bit , largo = 7;
	if(port == 'd'){
		largo = 15;
	}
	int *puntero = hex2bin(largo, mask);
		for(nbit = 0 , bit = 7; nbit <= largo ; nbit++ , bit--){
			if(puntero[nbit] == 1){
				bitClr(port, bit);
			}
		}
}

//Funcion maskToggle
//Encargada de cambiar el estado de los bits coincidentes con una mascara a su opuesto
void maskToggle(char port, int mask){
	int nbit, bit , largo = 7;
	if(port == 'd'){
		largo = 15;
	}
	int *puntero = hex2bin(largo, mask);
		for(nbit = 0 , bit = 7; nbit <= largo ; nbit++ , bit--){
			if(puntero[nbit] == 1){
				bitToggle(port, bit);
			}
		}
}




//FUNCIONES AUXILIARES

//FUNCION mod_regd
//Si se quiere modificar directamente el registro D
char mod_regd(int *bit){
    char a = 'a',b = 'b';
    //Si son los primeros 8 bits significa que se quiere modificar el registro A
    if((0 <= (*bit)) && ((*bit)<= 7)){
        return a;
    }
    //Si son los ultimos 8 bits significa que se quiere modificar el registro B
    else if((8 <= (*bit)) && ((*bit)<= 15)){
        (*bit) -= 8;
    	return b;
    }
    return 0;
}

//Funcion hex2bin
//Encargada de pasar un hexadecimal a binario
int* hex2bin(int largo,int hexa){
	int bin[largo];

	switch (hexDigit) {
	        case '0': bin[largo] = "0000";
	        case '1': bin[largo] = "0001";
	        case '2': bin[largo] = "0010";
	        case '3': bin[largo] = "0011";
	        case '4': bin[largo] = "0100";
	        case '5': bin[largo] = "0101";
	        case '6': bin[largo] = "0110";
	        case '7': bin[largo] = "0111";
	        case '8': bin[largo] = "1000";
	        case '9': bin[largo] = "1001";
	        case 'A': bin[largo] = "1010";
	        case 'B': bin[largo] = "1011";
	        case 'C': bin[largo] = "1100";
	        case 'D': bin[largo] = "1101";
	        case 'E': bin[largo] = "1110";
	        case 'F': bin[largo] = "1111";
	        default: return 0;
	    }
	}

	return bin;
}



