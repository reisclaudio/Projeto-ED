#ifndef RADIOBASE__H
#define RADIOBASE__H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//TAD RADIO BASE
typedef void* RadioBase;

/* Funcao que cria uma radio base */
RadioBase criaRadioBase (char id[], double x, double y, char cor1[], char cor2[], char sw[]);

/* Funcoes que fazem o get dos elementos de uma radio base */
double getXRB (RadioBase radioBase);
double getYRB (RadioBase radioBase);
char* getIDRB (RadioBase radioBase);
char* getCor1RB (RadioBase radioBase);
char* getCor2RB (RadioBase radioBase);
char* getSWRB (RadioBase radioBase);

/* Funcoes que fazem o set dos elementos de uma radio base */
void setXRB (RadioBase radioBase, double x);
void setYRB (RadioBase radioBase, double y);

/* Funcao que da free em uma radio base */
void freeRadioBase (RadioBase radioBase);

#endif