#ifndef ___SEGMENTO_H
#define ___SEGMENTO_H
//Funcoes que fazem procedimentos referentes a um segmento

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"utils.h"
#include"math.h"
#include"heapsort.h"
#include"vertice.h"

//TAD SEGMENTO
typedef void* Segmento;
typedef void* Vertice;

/* Funcao que cria um segmento */
Segmento criaSegmento (Vertice v1, Vertice v2);

/* Funcoes que retornam os dois vertices de um segmento */
Vertice getV1Segmento (Segmento segmento);
Vertice getV2Segmento (Segmento segmento);

/* Funcao que seta o vertice inicial de um segmento */
void setSegmentoStartVertice (Segmento segmento);
void freeSegmento (Segmento segmento);









#endif