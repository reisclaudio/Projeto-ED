#ifndef ___UTILS_H
#define ___UTILS_H
//Contem funcoes uteis para a realizacao de procedimentos

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include"lista.h"
#include"heapsort.h"
#include"segmento.h"
#include"./Elementos/ponto.h"

typedef void* Dist;
typedef void* Segmento;
typedef void* Ponto;

/* Funcao que calcula a distancia euclidiana entre dois pontos */
double distanciaEuclidiana (double x1, double y1, double x2, double y2);
/* Funcao que calcula a distancia de Manhattan entre dois pontos */
double manhattanDistance (double x1, double y1, double x2, double y2);
/* Funcao que realiza o clam */
double clamp (double pc, double pmi, double pma);
/* Funcao que retorna a distancia entre os centros de massa de duas formas */
double distCentrosMassa (Elemento elemento1, Elemento elemento2);

/* Funcoes que verificam colisao entre duas formas */
bool estaContidoCC (Elemento elemento1, Elemento elemento2);
bool estaContidoRR (Elemento elemento1, Elemento elemento2);
bool estaContidoCR (Elemento elemento1, Elemento elemento2);

/* Funcoes que verificam se um ponto está dentro de uma forma */
bool pontoEstaContido (double x, double y, Elemento elemento);
/* Funcao que inverte um vetor de distancias */
void inverterVetor (Dist vet[], int tamanhoVetor);
/* Funcao que checa o lado esquerdo*/
bool checkLeftTurn(Ponto a, Ponto b, Ponto c);
/* Funcao que checa a interseccao de 2 segmentos */
bool checkInterseccaoSegmentos (Segmento s1, Segmento s2);
/* Funcao que retorna o ponto de interseccao de 2 segmentos */
void interseccaoSegmentos (Segmento s1, Segmento s2, double *x, double *y);


#endif

