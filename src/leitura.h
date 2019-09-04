#ifndef ___LEITURA_H
#define ___LEITURA_H
//Contem as funcoes que fazem a leitura dos arquivos de entrada.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include"lista.h"
#include"segmentos.h"

/* Principal funcao do codigo, recebe varios parametros para alimentar outras funcoes */
void leArquivos (FILE * arqGeo,FILE * arqQry, char * nomesvg, char * nometxt, char * nomesvg2);
/* Funcao que le apenas o .geo, para o caso de o .qry ser nulo */
void leGEO (FILE * arqGeo, char * nomesvg);
/* Funcao que le as consultas do arquivo .qry */
void leQRY (FILE * nomearq,FILE * nomegeo,FILE * nometxt,FILE * nomesvg, char * svgBB, Lista listaFormas, Lista listaQuadras, Lista listaHidrantes,
Lista listaSemaforos, Lista listaRadiosBase, Lista listaMuros, Lista listaPredios, Lista listaExtra);  

#endif

