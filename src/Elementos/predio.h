#ifndef PREDIO__H
#define PREDIO__H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//TAD PREDIO
typedef void* Predio;

Predio criaPredio (char cep[], char face, double num, double f, double p, double mrg, double x, double y, double hQ, double wQ);

char* getCEPPredio (Predio predio);
char getFacePredio (Predio predio);
double getNumPredio (Predio predio);
double getFPredio (Predio predio);
double getPPredio (Predio predio);
double getMrgPredio (Predio predio);
void freePredio (Predio predio);
double getXPredio (Predio predio);
double getYPredio (Predio predio);
double gethQPredio (Predio predio);
double getwQPredio (Predio predio);





#endif