/**
 *	MODULO: ruleta
 *	FICHERO: ruleta.c
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Javier Sospedra Legarda el 24/04/20.
 * DESCRIPCION: Este módulo permite generar números aleatorios de 
 *              acuerdo a distintas distribuciones y probabilidades.
 */


#include "ruleta.h"

#include <stdlib.h>
#include <time.h>
#include <math.h>

// inicializa la ruleta
void iniciarRuleta(){
    srand(time(NULL));
}

// realiza una distribución exponencial a partir de una media
int distribucionExponencial(int media){
    float x;
    int t;
    x = rand()/(float)RAND_MAX; // numero aleatorio en [0, 1)
    t = (int)(-log(1 - x) * media);
    while (t == 0) {
        x = rand()/(float)RAND_MAX;
        t = (int)(-log(1 - x) * media);
    }
    return t;
}

// realiza una distribución lineas a partir de un mínimo y un máximo
int distribucionLineal(int min, int max) {
    float x;
    int t;
    x = rand()/(float)RAND_MAX;
    t = (int)((max - min) * x) + min;
    return t;
}

// realiza una elección con 3 distintas probabilidades
int eleccionCon3Probabilidades(float maxp, float medp, float minp) {
    int n;
    float x;
    float elec[3];
    elec[0] = maxp;
    elec[1] = medp + maxp;
    elec[2] = 1;
    x = rand()/(float)RAND_MAX;
    n = 0;
    while ((elec[n] < x) && (n < 2)) {
        n = n + 1;
    }
    return n;
}