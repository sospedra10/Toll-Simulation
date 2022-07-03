#ifndef JSL_RULETA_H
#define JSL_RULETA_H


/**
 *	MODULO: ruleta
 *	FICHERO: ruleta.h
 *	VERSION: 1.0.0
 *	HISTORICO:
 *		Creado por Javier Sospedra Legarda el 24/04/20.
 * DESCRIPCION: Este módulo permite generar números aleatorios de 
 *              acuerdo a distintas distribuciones y probabilidades.
 **/

// inicializa la ruleta
void iniciarRuleta();

// realiza una distribución exponencial a partir de una media
int distribucionExponencial(int media);

// realiza una distribución lineas a partir de un mínimo y un máximo
int distribucionLineal(int min, int max);

// realiza una elección con 3 distintas probabilidades
int eleccionCon3Probabilidades(float maxp, float medp, float minp);


#endif 
