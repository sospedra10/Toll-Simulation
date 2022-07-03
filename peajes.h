#ifndef JSL_PEAJES_H
#define JSL_PEAJES_H

/**
 *	MODULO: peajes
 *	FICHERO: peajes.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Javier Sospedra Legarda el 24/04/20.
 * DESCRIPCION: Este módulo exporta las funciones que realiza el peaje
 *              y el tipo de peaje como una cola de cabinas
 **/

#include "reloj.h"
#include "cabinas.h"

#define NCAB 5 // numero de cabinas
// tipo peaje
typedef Cabina Peaje[NCAB];

// incializa las cabinas del peaje con sus respectivos mínimo y máximo del tipoCobro
void iniciarPeaje(Peaje p);

// encola el coche recien llegado a la cabina con menor saturación
void guardaCola(Peaje p, int ncab, Reloj r);

// elige la cabina menos saturada con una probabilidad basada en el número de coches en cola
int eligeCabina(Peaje p);

// todas las cabinas sirven los coches a los que les haya llegado el turno
void rondaCabinas(Peaje p, Reloj r);

// muestra resultados de la simulación
void estado(Peaje p);

#endif