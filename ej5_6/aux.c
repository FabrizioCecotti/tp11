/*
 * aux.c
 *
 *  Created on: 28 oct. 2023
 *      Author: fabrizio
 */

#include <stdio.h>
#include "aux.h"


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
void hex2bin(int largo, char hexa, int * bin){
	int i;

	switch (hexa) {
	        case '0':
	        	for( i = (largo-1) ; i != (largo - 4)  ; i-- ){
	        		bin[i] = 0;
	        	}
	        	largo -= 4;
	        	break;
	        case '1':
	        	bin[largo--] = 0;
	        	bin[largo--] = 0;
	        	bin[largo--] = 0;
	        	bin[largo--] = 1;
	        	break;
	        case '2':
	        	bin[largo--] = 0;
	        	bin[largo--] = 0;
	        	bin[largo--] = 1;
	        	bin[largo--] = 0;
	        	break;
	        case '3':
	        	for( i = largo ; i != (largo - 2)  ; i-- ){
	        		bin[i] = 0;
	        	}
	        	largo -= 2;
	        	for( i = largo ; i != (largo - 2)  ; i-- ){
	        		bin[i] = 1;
	        	}
	        	largo -= 2;
	        	break;
	        case '4':
	        	bin[largo--] = 0;
	        	bin[largo--] = 1;
	        	bin[largo--] = 0;
	        	bin[largo--] = 0;
	        	break;
	        case '5':
	        	bin[largo--] = 0;
	        	bin[largo--] = 1;
	        	bin[largo--] = 0;
	        	bin[largo--] = 1;
	        	break;
	        case '6':
	        	bin[largo--] = 0;
	        	bin[largo--] = 1;
	        	bin[largo--] = 1;
	        	bin[largo--] = 0;
	        	break;
	        case '7':
	        	bin[largo--] = 0;
	        	bin[largo--] = 1;
	        	bin[largo--] = 1;
	        	bin[largo--] = 1;
	        	break;
	        case '8':
	        	bin[largo--] = 1;
	        	bin[largo--] = 0;
	        	bin[largo--] = 0;
	        	bin[largo--] = 0;
	        	break;
	        case '9':
	        	bin[largo--] = 1;
	        	bin[largo--] = 0;
	        	bin[largo--] = 0;
	        	bin[largo--] = 1;
	        	break;
	        case 'A':
	        	bin[largo--] = 1;
	        	bin[largo--] = 0;
	        	bin[largo--] = 1;
	        	bin[largo--] = 0;
	        	break;
	        case 'B':
	        	bin[largo--] = 1;
	        	bin[largo--] = 0;
	        	bin[largo--] = 1;
	        	bin[largo--] = 1;
	        	break;
	        case 'C':
	        	bin[largo--] = 1;
	        	bin[largo--] = 1;
	        	bin[largo--] = 0;
	        	bin[largo--] = 0;
	        	break;
	        case 'D':
	        	bin[largo--] = 1;
	        	bin[largo--] = 1;
	        	bin[largo--] = 0;
	        	bin[largo--] = 1;
	        	break;
	        case 'E':
	        	bin[largo--] = 1;
	        	bin[largo--] = 1;
	        	bin[largo--] = 1;
	        	bin[largo--] = 0;
	        	break;
	        case 'F':
	        	bin[largo--] = 1;
	        	bin[largo--] = 1;
	        	bin[largo--] = 1;
	        	bin[largo--] = 1;
	        	break;
	        default:
	        	break;
	}
}
