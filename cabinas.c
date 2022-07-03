/**
 *	MODULO: cabinas
 *	FICHERO: cabinas.c
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Javier Sospedra Legarda el 24/04/20.
 * DESCRIPCION: Este módulo exporta las funcionalidades que realizan las cabinas en el peaje
 *              y su estructura
 **/


#include "cabinas.h"
#include "ruleta.h"

// inicializa las variables de la cabina y la cola de coches
void iniciarCab(Cabina *cab, int tmin, int tmax){
    cab->nCoches = 0; cab->maxCoches = 0; cab->servidos = 0;
    cab->totalEsperado = 0; cab->proxServ = 0;
    cab->minServ = tmin; cab->maxServ = tmax;
    nuevaColaDeTElems(&(cab->colaCoches));
}

// cuenta los coches que llegan a la cabina y actualiza el número máximo de coches
void contarCoche(Cabina *cab, Reloj r){
    if (cab->nCoches == 0) 
        cab->proxServ = instante(r) + distribucionLineal(cab->minServ, cab->maxServ);
    cab->nCoches = cab->nCoches + 1;
    if (cab->nCoches > cab->maxCoches)
        cab->maxCoches = cab->nCoches;
}

// añade un nuevo coche a la cabina
void encolarCoche(Cabina *cab, Reloj r){
    contarCoche(cab, r);
    pideTurnoColaDeTElems(&(cab->colaCoches), instante(r));
}

// devuelve el número de coches que se encuentran en la cabina
int cuantosCoches(Cabina cab) {
    int n = cab.nCoches;
    return n;
}

// cuando le toca el turno a un coche de la cabina, lo trata, 
// de la cola actualiza el coche servido y lo elimina
void servCabina(Cabina *cab, Reloj r){
    int x;
    if (cab->proxServ == instante(r)) {
        cab->servidos = cab->servidos + 1;
        primeroColaDeTElems(cab->colaCoches, &x); 
        avanceColaDeTElems(&(cab->colaCoches));
        cab->totalEsperado = cab->totalEsperado + (instante(r) - x);
        cab->nCoches = cab->nCoches - 1;

        if (cab->nCoches == 0) 
            cab->proxServ = 0;
        else 
            cab->proxServ = instante(r) + distribucionLineal(cab->minServ, cab->maxServ);
    }
}

