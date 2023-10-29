/*
 * aux.h
 *
 *  Created on: 28 oct. 2023
 *      Author: fabrizio
 */

#ifndef AUX_H_
#define AUX_H_

void hex2bin(int largo, char hexa, int * bin);		//Función encargada de pasar un hexadecimal a binario
void maskToggle(char port, int mask);	//Función encargada de cambiar el estado de los bits coincidentes con una mascara a su opuesto


#endif /* AUX_H_ */
