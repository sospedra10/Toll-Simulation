#ifndef JSL_CONTROLES_H
#define JSL_CONTROLES_H

/**
 *	MODULO: controles
 *	FICHERO: controles.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Javier Sospedra Legarda el 24/04/20.
 * DESCRIPCION: Este módulo exporta las funciones que realiza el control del peaje
 *              y el tipo de control contando con el tipo peaje y un controlador del trafico
 *              que evalua la simulación a través de un tMedio de llegada y el próximo tiempo
 *              de llegada
 **/

#include "reloj.h"
#include "peajes.h"

// tipo frecuencia con el cual contará el elemento trafico de control
typedef struct frecuencia {
    int tLlegada;
    int tMedio;
} Frecuencia;

// tipo control, cuenta con un peaje y un trafico tipo frecuencia
typedef struct control {
    Peaje peaje;
    Frecuencia trafico;
} Control;

// inicializa el control pidiendo al usuario el tiempo medio de llegada
void iniciarControl(Control *c);

// simula la llegada de un coche al control
void llegaCoche(Control *c, Reloj r);

// simula la marcha de un coche del control
void marchaCoche(Control *c, Reloj r);

// muestra resultados
void mostrar(Control c);

#endif