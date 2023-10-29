/*
 * testing.c
 *
 *  Created on: 28 oct. 2023
 *      Author: fabrizio
 */

#include "puertos.h"
#include "aux.h"
#include "switch.h"
#include <stdio.h>

extern reg_t reg;

void printear(void);

int main(void){

bitSet('a',0);
bitSet('a',2);
bitSet('d',3);
bitSet('a',4);
bitSet('a',5);
bitSet('a',6);
bitSet('a',7);
bitSet('b',7);
bitSet('b',0);
bitSet('d',13);

printear();
putchar('\n');

bitClr('a',4);
bitClr('d',8);

printear();
putchar('\n');

int x = bitGet('b',3);
int y = bitGet('a',3);

printf("b3 = %d y a3 = %d \n",x,y);

bitToggle('b',2);
bitToggle('b',7);

printear();
putchar('\n');

maskOn('b', 0x4A); //0100 1010
printear();
putchar('\n');

maskOff('a', 0xF1); //1111 0001
printear();
putchar('\n');

maskOn('d',0xFFFF); //1111 1111 1111 1111
printear();
putchar('\n');

maskToggle('d', 0xFFFF);	//1111 1111 1111 1111
printear();
putchar('\n');

	return 0;
}

void printear(void){
	printf("%2d", reg.AB.b.b7);
	printf("%2d", reg.AB.b.b6);
	printf("%2d", reg.AB.b.b5);
	printf("%2d", reg.AB.b.b4);
	printf("%2d", reg.AB.b.b3);
	printf("%2d", reg.AB.b.b2);
	printf("%2d", reg.AB.b.b1);
	printf("%2d", reg.AB.b.b0);
	printf("    ");
	printf("%2d", reg.AB.a.b7);
	printf("%2d", reg.AB.a.b6);
	printf("%2d", reg.AB.a.b5);
	printf("%2d", reg.AB.a.b4);
	printf("%2d", reg.AB.a.b3);
	printf("%2d", reg.AB.a.b2);
	printf("%2d", reg.AB.a.b1);
	printf("%2d", reg.AB.a.b0);

	//int i;
	/*for (i = 7; i >= 0; i--) {
        printf("%2d", (reg.AB.b.b7 >> i) & 0x01); // Imprimir bit de B desde el bit 7 al 0
    }

    for (i = 7; i >= 0; i--) {
        printf("%2d", (reg.AB.a.b7 >> i) & 0x01); // Imprimir bit de A desde el bit 7 al 0
    }*/

}

