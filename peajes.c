/**
 *	MODULO: peajes
 *	FICHERO: peajes.c
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Javier Sospedra Legarda el 24/04/20.
 * DESCRIPCION: Este módulo exporta las funciones que realiza el peaje
 *              y el tipo de peaje como una cola de cabinas
 **/


#include "peajes.h"
#include "ruleta.h"
#include <stdio.h>

#define PROB_MAX 0.6
#define PROB_MEDIA 0.3
#define PROB_MIN 0.1

// tipo pareja que almacena el número de coches de una determinada cabina y su número de cabina
typedef struct pareja{
    int can;
    int cab;
} Pareja;


typedef Pareja taux[NCAB];

// tipo intervalo que almacena un mínimo y un máximo 
typedef struct intervalo{
    int min;
    int max;
} Intervalo;

// tipocobro almcena los intervalos de tiempo en el cobro para cada cabina
Intervalo tipoCobro[NCAB] = {{15, 30}, {15, 30}, {15, 45}, {15, 45}, {30, 60}};


// ordena las cabinas del peaje de menor a mayor número de coches en cola
void ordenar(taux t){
    
    int i ,j;
    for(i = 0; i < NCAB-1; i++){
        for(j = i+1; j < NCAB; j++){
            if(t[j].can < t[i].can){
                int aux_can = t[j].can;
                int aux_cab = t[j].cab;

                t[j].can = t[i].can;
                t[j].cab = t[i].cab;

                t[i].can = aux_can;
                t[i].cab = aux_cab;
            }
        }
    }

}

// encola el coche recien llegado a la cabina con menor saturación
void guardaCola(Peaje p, int ncab, Reloj r){
    encolarCoche(&(p[ncab]), r);
}

// incializa las cabinas del peaje con sus respectivos mínimo y máximo del tipoCobro
void iniciarPeaje(Peaje p){
    int i;
    for (i = 0; i < NCAB; i++){
        iniciarCab(&(p[i]), tipoCobro[i].min, tipoCobro[i].max);
    }
}

// elige la cabina menos saturada con una probabilidad basada en el número de coches en cola
int eligeCabina(Peaje p){
    int x, i;
    taux t;
    for (i = 0; i < NCAB; i++){
        t[i].can = cuantosCoches(p[i]);
        t[i].cab = i;
    }
    ordenar(t);
    x = eleccionCon3Probabilidades(PROB_MAX, PROB_MEDIA, PROB_MIN);
    int n = t[x].cab;
    return n;
}

// todas las cabinas sirven los coches a los que les haya llegado el turno
void rondaCabinas(Peaje p, Reloj r){
    int i;
    for (i = 0; i< NCAB; i++){
        servCabina(&(p[i]), r);
    }
}
        
// muestra resultados de la simulación
void estado(Peaje p){
    float tEspera = 0.0;
    int cochesServidos = 0;
    for (int i = 0; i< NCAB; i++){
        printf("\nCabina %d:\n", i+1);
        if (p[i].servidos != 0)
            printf("    Tiempo medio esperado: %f segundos\n", (float)p[i].totalEsperado/p[i].servidos); 
        else
            printf("    Esta cabina no ha servido ningún coche\n");
        printf("    Máximo de coches: %d\n", p[i].maxCoches);
        tEspera += p[i].totalEsperado;
        cochesServidos += p[i].servidos;
    }
    if (cochesServidos == 0)
        printf("\nTiempo medio de espera en el peaje: 0 segundos\n");
    else
        printf("\nTiempo medio de espera en el peaje: %f segundos\n", tEspera/cochesServidos);
    printf("Total coches servidos en el peaje: %d\n\n", cochesServidos);
        
}