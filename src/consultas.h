#ifndef ___CONSULTAS_H
#define ___CONSULTAS_H
//Contem as funcoes que que realizam as consultas do arquivo .qry.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include"lista.h"
#include"heapsort.h"
#include"segmento.h"

typedef void* Dist;

/* Funcao que realiza a consulta "d?" do .qry */
void consultaD (char* j, char* k,Lista listaFormas, FILE * nometxt, FILE * nomesvg);
/* Funcao que realiza a consulta "o?" do .qry */ 
void consultaO (char* j, char* k,Lista listaFormas, FILE * nometxt, FILE * nomesvg);
/* Funcao que realiza a consulta "i?" do .qry */ 
void consultaI (char* j, double x, double y, Lista listaFormas, FILE * nometxt, FILE * nomesvg);
/* Funcao que realiza a consulta "BB" do .qry */  
void consultaBB (char * sufixo, char * cor, char * nomesvg, Lista listaFormas, FILE * nomegeo);
/* Funcao que realiza a consulta "crd?" do .qry */  
bool consultaCRD (char *j, Lista listaQuadras, Lista listaHidrantes, Lista listaSemaforos, Lista listaRadiosBase, FILE *nometxt);
/* Funcao que realiza a consulta "del" do .qry */  
bool consultaDEL (char *j, Lista listaQuadras, Lista listaHidrantes, Lista listaSemaforos, Lista listaRadiosBase, FILE *nometxt);
/* Funcao que realiza a consulta "cbq" do .qry */  
void consultaCBQ (double x, double y, double r, char* cstrk, Lista listaQuadras, FILE *nometxt);
/* Funcao que realiza a consulta "trns" do .qry */  
void consultaTRNS (double x, double y, double w, double h, double dx, double dy, Lista listaQuadras,Lista listaHidrantes, Lista listaSemaforos, Lista listaRadiosBase, FILE*nometxt);
/* Funcao que realiza a consulta "dq" do .qry */  
void consultaDQ (char* id, char* metrica, double dist, Lista listaQuadras, Lista listaHidrantes, Lista listaSemaforos, Lista listaRadiosBase, FILE* nometxt, FILE* nomesvg);
/* Funcao que realiza a consulta "fi" do .qry */  
void consultaFI (double x, double y, int ns, double r, Lista listaHidrantes, Lista listaSemaforos, Lista listaExtra,  FILE * arqSVG, FILE * arqTXT);
/* Funcao que realiza a consulta "fs" do .qry */  
void consultaFS (int k, char* cep, char face, double num, Lista listaQuadras, Lista listaSemaforos, Lista listaExtra, FILE * arqSVG, FILE * arqTXT);
/* Funcao que realiza a consulta "fh" do .qry */  
void consultaFH (int k, char* cep, char face, double num, Lista listaQuadras, Lista listaHidrantes, Lista listaExtra, FILE * arqSVG, FILE * arqTXT);






#endif

