#ifndef ___PONTO_H
#define ___PONTO_H
//Funcoes que fazem procedimentos referentes a um ponto

#include<stdio.h>
#include<stdlib.h>

//TAD PONTO
typedef void *Ponto;

/* Funcao que cria um ponto */
Ponto criaPonto (double x, double y);

/* Funcoes que fazem o get dos elementos de um ponto */
double getXPonto (Ponto ponto);
double getYPonto (Ponto ponto);

/* Funcoes que fazem o set dos elementos de uma ponto */
void setPontoMin (Ponto ponto, double x, double y);
void setPontoMax (Ponto ponto, double x, double y);

/* Funcao que da o free em um ponto */
void freePonto (Ponto ponto);


#endif