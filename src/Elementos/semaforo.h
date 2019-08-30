#ifndef SEMAFORO__H
#define SEMAFORO__H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//TAD SEMAFORO
typedef void* Semaforo;

/* Funcao que cria um semaforo */
Semaforo criaSemaforo (char id[], double x, double y, char cor1[], char cor2[], char sw[]);

/* Funcoes que fazem o get de elementos de um semaforo */
double getXSema (Semaforo semaforo);
double getYSema (Semaforo semaforo);
char* getIDSema (Semaforo semaforo);
char* getCor1Sema (Semaforo semaforo);
char* getCor2Sema (Semaforo semaforo);
char* getSWSema (Semaforo semaforo);

/* Funcoes que fazem o set de elementos de um semaforo */
void setXSema (Semaforo semaforo, double x);
void setYSema (Semaforo semaforo, double y);

/* Funcao que da free em um semaforo */
void freeSemaforo (Semaforo semaforo);

#endif