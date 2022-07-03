/**
 *	MODULO: colaDeElems
 *	FICHERO: colaDeElems.c
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Javier Sospedra Legarda el 25/04/20.
 * DESCRIPCION: Este módulo exporta la funcionalidad necesaria para implementar
 * 	            una cola de tElems. Utiliza una implementacion dinámica
 */


#include <stdlib.h> // para conocer exit y malloc
#include "colaDeTElems.h" 
#include <stdio.h>

// imprime en pantalla el tipo de error que ha ocurrido
void errorColaDeTElems(char s[]) {
    printf("\n\n\nERROR en el módulo colas: %s \n", s);
    while (true)
        exit(-1);
}

// inicializa la cola
void nuevaColaDeTElems(ColaDeTElems *c){
    c->i = NULL;
    c->f = NULL;
}

// añade un tElem a la cola
void pideTurnoColaDeTElems(ColaDeTElems *c, tElem x){
    NodoDeColaDeTElems *q;
    if ((q=malloc(sizeof(NodoDeColaDeTElems)))==NULL)
        errorColaDeTElems("no hay memoria para pideTurno");
    q->e = x;
    q->s = NULL;
    if (c->f == NULL)
        c->i = q;

    else
        c->f->s = q;
    c->f = q;
}

// devuelve si la cola es nula o no
bool esNulaColaDeTElems (ColaDeTElems c){
    return (c.i == NULL);
}

// avanza eliminando el primer TElem
void avanceColaDeTElems(ColaDeTElems *c){
    NodoDeColaDeTElems *q;
    if (esNulaColaDeTElems(*c))
        errorColaDeTElems("avanzando en cola nula");
    q = c->i;
    c->i = c->i->s;
    if (c->i == NULL)
        c->f = NULL;
    free(q);
}

// devuelve en x el primer valor de la cola
void primeroColaDeTElems (ColaDeTElems c, tElem *x){
    if (esNulaColaDeTElems(c))
        errorColaDeTElems("primero en cola nula");
    *x = c.i->e; 
}