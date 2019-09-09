#ifndef PREDIO__H
#define PREDIO__H
//Funcoes que fazem procedimentos referentes a um predio

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//TAD PREDIO
typedef void* Predio;

/* Funcao que cria um predio */
Predio criaPredio (char cep[], char face, double num, double f, double p, double mrg, double x, double y, double hQ, double wQ);

/* Funcoes que fazem o get dos elementos de um predio */
char* getCEPPredio (Predio predio);
char getFacePredio (Predio predio);
double getNumPredio (Predio predio);
double getFPredio (Predio predio);
double getPPredio (Predio predio);
double getMrgPredio (Predio predio);
double getXPredio (Predio predio);
double getYPredio (Predio predio);
double gethQPredio (Predio predio); //get da altura da quadra em que o predio está localizado
double getwQPredio (Predio predio); //get da largura da quadra em que o predio está localizado

/* Funcao que da free em um predio */
void freePredio (Predio predio);






#endif