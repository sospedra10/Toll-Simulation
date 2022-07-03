#ifndef JSL_RELOJ_H
#define JSL_RELOJ_H

/**
 *	MODULO: reloj
 *	FICHERO: reloj.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Javier Sospedra Legarda el 24/04/20.
 * DESCRIPCION: Este módulo utiliza el tipo reloj para contar el tiempo transcurrido
 */

typedef int Reloj;

// inicia el reloj con el valor 0
void aCero(Reloj *r);

// avanza en uno el valor del reloj
void tic(Reloj *r);

// devuelve el valor del reloj
int instante(Reloj r);

#endif