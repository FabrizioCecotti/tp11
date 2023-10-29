/*
 * switch.c
 *
 *  Created on: 28 oct. 2023
 *      Author: fabrizio
 */
#include "switch.h"
#include "puertos.h"

extern reg_t reg;

//FUNCION swit1
////Funcion encargada de encender el o los bits solicitados
void swit1(char port, int bit){
	switch(port){
		case 'a':	//Si se trabaja con el puerto A
			switch(bit){	//Casos bit a bit
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
		case 'b':	//Si se trabaja con el puerto B
			switch(bit){	//Casos bit a bit
				case 0:
					reg.AB.b.b0 = 1;
					break;
				case 1:
					reg.AB.b.b1 = 1;
					break;
				case 2:
					reg.AB.b.b2 = 1;
					break;
				case 3:
					reg.AB.b.b3 = 1;
					break;
				case 4:
					reg.AB.b.b4 = 1;
					break;
				case 5:
					reg.AB.b.b5 = 1;
					break;
				case 6:
					reg.AB.b.b6 = 1;
					break;
				case 7:
					reg.AB.b.b7 = 1;
					break;
				default:
					break;
				}
			break;
		default:
			break;
		}
}

//FUNCION swit0
////Funcion encargada de apagar el o los bits solicitados
void swit0(char port, int bit){

	switch(port){
		case 'a':	//Si se trabaja con el puerto A
			switch(bit){	//Casos bit a bit
			case 0:
				reg.AB.a.b0 = 0;
				break;
			case 1:
				reg.AB.a.b1 = 0;
				break;
			case 2:
				reg.AB.a.b2 = 0;
				break;
			case 3:
				reg.AB.a.b3 = 0;
				break;
			case 4:
				reg.AB.a.b4 = 0;
				break;
			case 5:
				reg.AB.a.b5 = 0;
				break;
			case 6:
				reg.AB.a.b6 = 0;
				break;
			case 7:
				reg.AB.a.b7 = 0;
				break;
			default:
				break;
			}
			break;
		case 'b':	//Si se trabaja con el puerto B
			switch(bit){		//Casos bit a bit
				case 0:
					reg.AB.b.b0 = 0;
					break;
				case 1:
					reg.AB.b.b1 = 0;
					break;
				case 2:
					reg.AB.b.b2 = 0;
					break;
				case 3:
					reg.AB.b.b3 = 0;
					break;
				case 4:
					reg.AB.b.b4 = 0;
					break;
				case 5:
					reg.AB.b.b5 = 0;
					break;
				case 6:
					reg.AB.b.b6 = 0;
					break;
				case 7:
					reg.AB.b.b7 = 0;
					break;
				default:
					break;
			}
			break;
		default:
			break;
		}
}

//FUNCION switGet
//Funcion encargada de devolver el estado del bit solicitado
int switGet(char port, int bit){
	int estado;

	switch(port){
		case 'a':		//Si se trabaja con el puerto A
			switch(bit){	//Casos bit a bit
				case 0:
					estado = reg.AB.a.b0;
					break;
				case 1:
					estado = reg.AB.a.b1;
					break;
				case 2:
					estado = reg.AB.a.b2;
					break;
				case 3:
					estado = reg.AB.a.b3;
					break;
				case 4:
					estado = reg.AB.a.b4;
					break;
				case 5:
					estado = reg.AB.a.b5;
					break;
				case 6:
					estado = reg.AB.a.b6;
					break;
				case 7:
					estado = reg.AB.a.b7;
					break;
				default:
					break;
			}
			break;
		case 'b':		//Si se trabaja con el puerto B
			switch(bit){	//Casos bit a bit
				case 0:
					estado = reg.AB.b.b0;
					break;
				case 1:
					estado = reg.AB.b.b1;
					break;
				case 2:
					estado = reg.AB.b.b2;
					break;
				case 3:
					estado = reg.AB.b.b3;
					break;
				case 4:
					estado = reg.AB.b.b4;
					break;
				case 5:
					estado = reg.AB.b.b5;
					break;
				case 6:
					estado = reg.AB.b.b6;
					break;
				case 7:
					estado = reg.AB.b.b7;
					break;
				default:
					break;
			}
			break;
		default:
			break;
		}
	return estado;
}
