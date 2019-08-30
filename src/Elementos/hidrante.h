#ifndef HIDRANTE__H
#define HIDRANTE__H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//TAD HIDRANTE
typedef void* Hidrante;

/* Funcao que cria um hidrante */
Hidrante criaHidrante (char id[], double x, double y, char cor1[], char cor2[], char sw[]);

/* Funcoes que fazem o get dos elementos de um hidrante */
double getXHid (Hidrante hidrante);
double getYHid (Hidrante hidrante);
char* getIDHid (Hidrante hidrante);
char* getCor1Hid (Hidrante hidrante);
char* getCor2Hid (Hidrante hidrante);
char* getSWHid (Hidrante hidrante);

/* Funcoes que fazem o set de elementos de um hidrante */
void setXHid (Hidrante hidrante, double x);
void setYHid (Hidrante hidrante, double y);

/* Funcao que da free em um hidrante */
void freeHidrante (Hidrante hidrante);

#endif