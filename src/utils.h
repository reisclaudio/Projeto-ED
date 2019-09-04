#ifndef ___UTILS_H
#define ___UTILS_H
//Contem as funcoes que fazem a leitura dos arquivos de entrada.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include"lista.h"
#include"heapsort.h"

typedef void* Dist;

double distanciaEuclidiana (double x1, double y1, double x2, double y2);
double manhattanDistance (double x1, double y1, double x2, double y2);
double clamp (double pc, double pmi, double pma);
double distCentrosMassa (Elemento elemento1, Elemento elemento2);
bool estaContidoCC (Elemento elemento1, Elemento elemento2);
bool estaContidoRR (Elemento elemento1, Elemento elemento2);
bool estaContidoCR (Elemento elemento1, Elemento elemento2);
bool pontoEstaContido (double x, double y, Elemento elemento);
void inverterVetor (Dist vet[], int tamanhoVetor);


#endif

