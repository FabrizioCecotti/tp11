/*
 * switch.h
 *
 *  Created on: 28 oct. 2023
 *      Author: fabrizio
 */

#ifndef SWITCH_H_
#define SWITCH_H_

//PROTOTIPOS

void swit1(char port, int bit);		//Funcion encargada de encender el o los bits solicitados
void swit0(char port, int bit);		//Funcion encargada de apagar el o los bits solicitados
int switGet(char port, int bit);	//Funcion encargada de devolver el estado del bit solicitado


#endif /* SWITCH_H_ */
