#ifndef ___SEGMENTOS_H
#define ___SEGMENTOS_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"utils.h"
#include"math.h"
#include"heapsort.h"

typedef void* Segmento;
typedef void* Vertice;
typedef void* Dist;

Segmento criaSegmentos (int capacidade);
void inserirSegmento (Segmento aux, int* tamanho, double x1, double y1, double x2, double y2);
void imprimeSegmentos (Segmento aux, int tam, FILE * arqSVG);
void freeSegmentos (Segmento aux, int tamanho);
Vertice criaVertices (double x, double y, int capacidade, Segmento s, int tamanho, FILE * arqSVG);
int cmpVertices (const void *a, const void *b);
void sortVertices (Vertice v, int tamanho);











#endif