/**
 *	MODULO: simPeaje
 *	FICHERO: simPeaje.c
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Javier Sospedra Legarda el 24/04/20.
 * DESCRIPCION: Se realiza una simulación de un peaje
 **/

// tiempo para la simulación 3 horas = 10800 segundos

#define TSIM 10800
#include "reloj.h"
#include "controles.h"
#include "ruleta.h"
#include <stdio.h>

// inicializa la simulación incializando la ruleta y el control del peaje
void iniciarSimulacion(Control *c){
    iniciarRuleta();
    iniciarControl(c);
}

// trata los coches llegados y los coches servidos
void siguienteIteracion(Control *c, Reloj r){
    llegaCoche(c, r);
    marchaCoche(c, r);
}

// muestra resultados de la simulación
void mostrarResultados(Control c){
    mostrar(c);
}

// simulación
void main(void){
    Reloj r;
    Control c;
    aCero(&r);
    iniciarSimulacion(&c);
    
    while (instante(r) != TSIM){
        tic(&r);
        siguienteIteracion(&c, r);   
    }
    mostrarResultados(c);
}
