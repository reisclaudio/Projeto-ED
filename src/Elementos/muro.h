#ifndef MURO__H
#define MURO__H
//Funcoes que fazem procedimentos referentes a um muro

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//TAD MURO
typedef void* Muro;

/* Funcao que cria um muro */
Muro criaMuro (double x1, double y1, double x2, double y2);

/* Funcoes que fazem o get dos elementos de um muro */
double getX1Muro (Muro muro);
double getY1Muro (Muro muro);
double getX2Muro (Muro muro);
double getY2Muro (Muro muro);

/* Funcao que da free em um muro */
void freeMuro (Muro muro);

#endif