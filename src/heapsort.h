#ifndef HEAP_SORT_H
#define HEAP_SORT_H
/* Funcoes de ordenação usando heapsort */

#include <stdio.h>
#include "consultas.h"

typedef void *Dist;

/* Funcao que transforma em heap um vetor vet que alguma vez ja foi um heap (decrescente) */
void min_heapify(Dist vet[], int i, int heapSize);
/* Funcao que constroi um heap do vetor vet em ordem decrescente */
void min_build_heap(Dist vet[], int heapSize);
/* Funcao que ordena o vetor vet em ordem decrescente */
void min_heap_sort(Dist vet[], int heapSize, int k);
/* Funcao que transforma em heap um vetor vet que alguma vez ja foi um heap (crescente)*/

void max_heapify(Dist vet[], int i, int heapSize);
/* Funcao que constroi um heap do vetor vet em ordem crescente*/
void max_build_heap(Dist vet[], int heapSize);
/* Funcao que ordena o vetor vet em ordem crescente*/
void max_heap_sort(Dist vet[], int heapSize, int k);


/* Funcao que auxilia consultas em que é preciso ordenar distancias */
double getDist(Dist distAux);


#endif