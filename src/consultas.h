#ifndef ___CONSULTAS_H
#define ___CONSULTAS_H
//Contem as funcoes que fazem a leitura dos arquivos de entrada.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include"lista.h"
#include"heapsort.h"
#include"segmentos.h"

typedef void* Dist;

/* Funcao que realiza a consulta "d?" do .qry */
void consultaD (char* j, char* k,Lista lformas, FILE * nometxt, FILE * nomesvg);
/* Funcao que realiza a consulta "o?" do .qry */ 
void consultaO (char* j, char* k,Lista lformas, FILE * nometxt, FILE * nomesvg);
/* Funcao que realiza a consulta "i?" do .qry */ 
void consultaI (char* j, double x, double y, Lista lformas, FILE * nometxt, FILE * nomesvg);
/* Funcao que realiza a consulta "BB" do .qry */  
void consultaBB (char * sufixo, char * cor, char * nomesvg, Lista lformas, FILE * nomegeo);
/* Funcao que realiza a consulta "crd?" do .qry */  
bool consultaCRD (char *j, Lista lquadras, Lista lhidrantes, Lista lsemaforos, Lista lRB, FILE *nometxt);
/* Funcao que realiza a consulta "del" do .qry */  
bool consultaDEL (char *j, Lista lquadras, Lista lhidrantes, Lista lsemaforos, Lista lRB, FILE *nometxt);
/* Funcao que realiza a consulta "cbq" do .qry */  
void consultaCBQ (double x, double y, double r, char* cstrk, Lista lquadras, FILE *nometxt);
/* Funcao que realiza a consulta "trns" do .qry */  
void consultaTRNS (double x, double y, double w, double h, double dx, double dy, Lista lquadras,Lista lhidrantes, Lista lsemaforos, Lista lrb, FILE*nometxt);
/* Funcao que realiza a consulta "dq" do .qry */  
void consultaDQ (char* id, char* metrica, double dist, Lista lquadras, Lista lhidrantes, Lista lsemaforos, Lista lRB, FILE* nometxt, FILE* nomesvg);
void consultaFI (double x, double y, int ns, double r, Lista lhidrantes, Lista lsemaforos, Lista lextra,  FILE * arqSVG, FILE * arqTXT);
void consultaFS (int k, char* cep, char face, double num, Lista lquadras, Lista lsemaforos, Lista lextra, FILE * arqSVG, FILE * arqTXT);
void consultaFH (int k, char* cep, char face, double num, Lista lquadras, Lista lhidrantes, Lista lextra, FILE * arqSVG, FILE * arqTXT);
void consultaBRL (double x, double y, Lista lpredios, Lista lmuros, FILE * arqSVG);






#endif

