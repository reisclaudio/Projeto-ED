#ifndef ___SEGMENTOS_H
#define ___SEGMENTOS_H

#include<stdio.h>
#include<stdlib.h>

typedef void* Segmento;

Segmento criaSegmentos (int capacidade);
void inserirSegmento (Segmento aux, int* tamanho, double x1, double y1, double x2, double y2);
void imprimeSegmentos (Segmento aux, int tam, FILE * arqSVG);
void freeSegmentos (Segmento aux, int tamanho);








#endif