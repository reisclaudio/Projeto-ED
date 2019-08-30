#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <stdio.h>
#include "consultas.h"

typedef void *Dist;

void heapify(Dist vet[], int i, int heapSize);

void build_heap(Dist vet[], int heapSize);

void heap_sort(Dist vet[], int heapSize, int k);

double getDist(Dist distAux);


#endif