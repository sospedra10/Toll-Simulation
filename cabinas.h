#ifndef JSL_CABINAS_H
#define JSL_CABINAS_H

/**
 *	MODULO: cabinas
 *	FICHERO: cabinas.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Javier Sospedra Legarda el 24/04/20.
 * DESCRIPCION: Este módulo exporta las funcionalidades que realizan las cabinas en el peaje
 *              y su estructura
 **/

#include "colaDeTElems.h" 
#include "reloj.h"

// tipo cabina
typedef struct cabina {
    int nCoches; // coches esperando en la cabina
    int maxCoches; // máximo de coches esperando
    int servidos; // coches servidos
    int totalEsperado; // tiempo total de esperas
    int proxServ; // instante proximo servicio
    int minServ; // tiempo mínimo del servicio
    int maxServ; // tiempo máximo del servicio
    ColaDeTElems colaCoches; // cola de coches
} Cabina;

// inicializa las variables de la cabina y la cola de coches
void iniciarCab(Cabina *cab, int tmin, int tmax);

// cuenta los coches que llegan a la cabina y actualiza el número máximo de coches
void contarCoche(Cabina *cab, Reloj r);

// añade un nuevo coche a la cabina
void encolarCoche(Cabina *cab, Reloj r);

// devuelve el número de coches que se encuentran en la cabina
int cuantosCoches(Cabina cab);

// cuando le toca el turno a un coche de la cabina, lo trata, 
// de la cola actualiza el coche servido y lo elimina
void servCabina(Cabina *cab, Reloj r);

#endif