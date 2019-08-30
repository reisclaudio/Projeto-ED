#ifndef PREDIO__H
#define PREDIO__H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//TAD PREDIO
typedef void* Predio;

Predio criaPredio (char cep[], char face, double num, double f, double p, double mrg, double xQ, double yQ, double hQ, double wQ);

char* getCEPPredio (Predio predio);
char getFacePredio (Predio predio);
double getNumPredio (Predio predio);
double getFPredio (Predio predio);
double getPPredio (Predio predio);
double getMrgPredio (Predio predio);
double getxQPredio (Predio predio);
double getyQPredio (Predio predio);
double gethQPredio (Predio predio);
double getwQPredio (Predio predio);
void freePredio (Predio predio);




#endif