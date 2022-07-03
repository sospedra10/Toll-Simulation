/**
 *	MODULO: reloj
 *	FICHERO: reloj.c
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Javier Sospedra Legarda el 24/04/20.
 * DESCRIPCION: Este módulo utiliza el tipo reloj para contar el tiempo transucrrido
 */


#include "reloj.h"

// inicia el reloj con el valor 0
void aCero(Reloj *r){
    *r = 0;
}

// avanza en uno el valor del reloj
void tic(Reloj *r){
    *r = *r + 1;
}

// devuelve el valor del reloj
int instante(Reloj r){
    return r;
}