#ifndef JSL_COLA_DE_TELEMS_H
#define JSL_COLA_DE_TELEMS_H

/**
 *	MODULO: colaDeElems
 *	FICHERO: colaDeElems.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Javier Sospedra Legarda el 25/04/20.
 * DESCRIPCION: Este módulo exporta la funcionalidad necesaria para implementar
 * 	            una cola de tElems. Utiliza una implementacion dinámica
 */

#include <stdbool.h>
#include "TElem.h" // para el tipo tElem

// tipo nodoDeColaDeTElems
typedef struct nodoDeColaDeTElems {
    tElem e;
    struct nodoDeColaDeTElems *s;
} NodoDeColaDeTElems;

// tipo ColaDeTElems
typedef struct colaDeTElems{
    NodoDeColaDeTElems *i;
    NodoDeColaDeTElems *f;
} ColaDeTElems;

// inicializa la cola
void nuevaColaDeTElems(ColaDeTElems *);

// añade un tElem a la cola
void pideTurnoColaDeTElems(ColaDeTElems *, tElem);

// avanza eliminando el primer TElem
void avanceColaDeTElems(ColaDeTElems *);

// devuelve en x el primer valor de la cola
void primeroColaDeTElems(ColaDeTElems, tElem *);

// devuelve si la cola es nula o no
bool esNulaColaDeTElems(ColaDeTElems);


#endif