/**
 *	MODULO: controles
 *	FICHERO: controles.c
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Javier Sospedra Legarda el 24/04/20.
 * DESCRIPCION: Este módulo exporta las funciones que realiza el control del peaje
 *              y el tipo de control contando con el tipo peaje y un controlador del trafico
 *              que evalua la simulación a través de un tMedio de llegada y el próximo tiempo
 *              de llegada
 **/

#include "controles.h"
#include "ruleta.h"
#include <stdio.h>

// inicializa el control pidiendo al usuario el tiempo medio de llegada
void iniciarControl(Control *c){
    // solicitar el tiempo medio entre llegadas (en segundos)
    printf("\nIntroduzca el tiempo medio de llegada: ");
    scanf("%d", &c->trafico.tMedio);
    c->trafico.tLlegada = distribucionExponencial(c->trafico.tMedio);
    iniciarPeaje(c->peaje);
}

// simula la llegada de un coche al control
void llegaCoche(Control *c, Reloj r){
    int n;
    if (instante(r) == c->trafico.tLlegada){
        n = eligeCabina(c->peaje);
        guardaCola(c->peaje, n, r);
        c->trafico.tLlegada = instante(r) + distribucionExponencial(c->trafico.tMedio);
    }
}

// simula la marcha de un coche del control
void marchaCoche(Control *c, Reloj r){
    rondaCabinas(c->peaje, r);
}

// muestra resultados
void mostrar(Control c){
    estado(c.peaje);
}