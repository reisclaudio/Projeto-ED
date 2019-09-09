#ifndef FORMA__H
#define FORMA__H
//Funcoes que fazem procedimentos referentes a uma forma (circulo ou retangulo)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//TAD FORMA
typedef void* Forma;

/* Funcao que cria uma forma (circulo ou retangulo) */
Forma criaForma (char id[], char tipo, double x, double y, double r, double w,double h, char cor1[], char cor2[], char sw[]);

/* Funcoes que fazem o get dos elementos de um Forma */
double getXForma  (Forma forma);
double getYForma  (Forma forma);
double getRaioForma (Forma forma);
double getWForma  (Forma forma);
double getHForma  (Forma forma);
char* getCor1Forma  (Forma forma);
char* getCor2Forma  (Forma forma);
char* getSWForma  (Forma forma);

/* Funcao que da free em um Forma */
void freeForma (Forma forma);


/* Funcao generica que retorna o tipo de um elemento */
char getTipo (Forma forma);

#endif