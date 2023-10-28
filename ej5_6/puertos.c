/*
 * puertos.c
 *
 *  Created on: 28 oct. 2023
 *      Author: fabrizio
 */

#include <stdio.h>
#include <stdint.h>
#include "puertos.h"

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

typedef struct
{
    bit_a_bit_t a;
    bit_a_bit_t b;
} BAB;

typedef union
{
    BAB AB;
    uint16_t D;
} reg_t;

reg_t reg = {.D = 0000000000000000};  // Crear una variable global de tipo reg_t para poder utilizarla en las funciones y macros
void bitSet(char port, int bit);
void bitClr(char port, int bit);
void bitToggle(char port, int bit);
void maskOn(char port, int mask);
char mod_regd(int* bit);

#define BIT(x) (b(x))
#define BIT_SET_AB(p, c) (reg.AB.(p).b(c) = 1)
#define BIT_CLR_AB(p, c) ( reg.AB.(p).b(c) = 0)
#define BIT_GET_AB(p, c) ( reg.AB.(p).b##(c))



void bitSet(char port, const int bit){
	int x;
	if(port == 'd'){
		port = mod_regd(&bit);
	}
	switch(port){
	case 'a':
		//BIT_GET_AB(a, bit) = 1;
		switch(bit){
		case 0:
			reg.AB.a.b0 = 1;
			break;
		case 1:
			reg.AB.a.b1 = 1;
			break;
		case 2:
			reg.AB.a.b2 = 1;
			break;
		case 3:
			reg.AB.a.b3 = 1;
			break;
		case 4:
			reg.AB.a.b4 = 1;
			break;
		case 5:
			reg.AB.a.b5 = 1;
			break;
		case 6:
			reg.AB.a.b6 = 1;
			break;
		case 7:
			reg.AB.a.b7 = 1;
			break;
		default:
			break;
		}
		break;
	case 'b':
		BIT_GET_AB('b', bit);
		break;
	default:
		break;

	}

}

void bitClr(char port, int bit){
	if(port == 'd'){
		port = mod_regd(&bit);
		BIT_CLR_AB(port, bit);
	}
	else{
		BIT_CLR_AB(port, bit);
	}
}

int bitGet(char port, int bit){
	int b;
	if(port == 'd'){
		port = mod_regd(&bit);
		b = BIT_GET_AB(port, bit);
	}
	else{
		b = BIT_GET_AB(port, bit);
	}
	return b;
}

void bitToggle(char port, int bit){
	char p;
	if(port == 'd'){
		p = mod_regd(&bit);
		if(BIT_GET_AB(p, bit) == 1){
			BIT_CLR_AB(p, bit);
		}
		else{
			BIT_SET_AB(p, bit);
		}
	}
	else{
		if(BIT_GET_AB(port, bit) == 1){
			BIT_CLR_AB(port, bit);
		}
		else{
			BIT_SET_AB(port, bit);
		}
	}
}

void maskOn(char port, int mask){
	if(port == 'a'){
		reg.AB.a |= mask;
	}
	else if(port == 'b'){
		reg.AB.b |= (bit_a_bit_t)mask;
	}
	else{
		reg.D |= mask;
	}
}


//FUNCIONES AUX
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
    return a;
}
