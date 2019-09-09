#ifndef ___BOMBA_H
#define ___BOMBA_H
//Contem as funcoes que realizam a consulta "brl"

#include <stdio.h>
#include <stdlib.h>
#include "vertice.h"
#include "segmento.h"
#include "lista.h"
#include "./Elementos/ponto.h"
#include "./Elementos/muro.h"
#include "./Elementos/predio.h"

#define PI 3.14159265359

//TAD BOMBA
typedef void *Ponto;

/* Funcao que realiza a consulta "brl" do .qry */
void areaBomba (double x, double y, int capacidade, Lista listaMuros, Lista listaPredios, int *size, FILE * arqSVG);
Segmento buscarSegmentoFormadoComVertice(double xc, double yc, Vertice v, Ponto pontoMin, Ponto pontoMax);
int cmpVertices (const void *a, const void *b);



#endif