#ifndef QUADRA__H
#define QUADRA__H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//TAD QUADRA
typedef void* Quadra;

/* Funcao que cria uma quadra */
Quadra criaQuadra (char cep[], double x, double y, double w, double h, char cor1[], char cor2[], char sw[]);

/* Funcoes que fazem o get dos elementos de uma quadra */
char* getCEPQuadra (Quadra quadra);
double getXQuadra (Quadra quadra);
double getYQuadra (Quadra quadra);
double getWQuadra (Quadra quadra);
double getHQuadra (Quadra quadra);
char* getCor1Quadra (Quadra quadra);
char* getCor2Quadra (Quadra quadra);
char* getSWQuadra (Quadra quadra);

/* Funcoes que fazem o set dos elementos de uma quadra */
void setXQuadra (Quadra quadra, double x);
void setYQuadra (Quadra quadra, double y);
void setCor1Quadra (Quadra quadra, char* cor1);
void setCor2Quadra (Quadra quadra, char* cor2);

/* Funcao que da free em uma quadra */
void freeQuadra (Quadra quadra);

#endif