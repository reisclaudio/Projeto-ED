#ifndef ___VERTICE_H
#define ___VERTICE_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"math.h"
#include"./Elementos/ponto.h"
#include"segmento.h"

typedef void* Segmento;
typedef void* Vertice;

Vertice criaVertice (Ponto p, double xB, double yB);
Ponto getVVertice (Vertice vertice);
double getDistVertice (Vertice vertice);
double getAnguloVertice (Vertice vertice);
Segmento getSegmentoVertice(Vertice vertice);
bool getStartVertice (Vertice vertice);
void setSegmentoVertice (Vertice vertice, Segmento segmento);
void setStartVertice (Vertice vertice, bool start);
void setAnguloVertice (Vertice vertice, double angulo);
void freeVertice (Vertice vertice);
 



#endif