#ifndef ___VERTICE_H
#define ___VERTICE_H
//Funcoes que fazem procedimentos referentes a um vertice

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"math.h"
#include"./Elementos/ponto.h"
#include"segmento.h"

//TAD VERTICE
typedef void* Segmento;
typedef void* Vertice;

/* Funcao que cria um vertice */
Vertice criaVertice (Ponto p, double xB, double yB);

/* Funcoes que fazem o get dos elementos de um vertice */
Ponto getVVertice (Vertice vertice);
double getDistVertice (Vertice vertice);
double getAnguloVertice (Vertice vertice);
Segmento getSegmentoVertice(Vertice vertice);
bool getStartVertice (Vertice vertice);

/* Funcoes que fazem o set dos elementos de um ponto */
void setSegmentoVertice (Vertice vertice, Segmento segmento);
void setStartVertice (Vertice vertice, bool start);
void setAnguloVertice (Vertice vertice, double angulo);

/* Funcao que da o free em um vertice */
void freeVertice (Vertice vertice);
 



#endif