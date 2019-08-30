#ifndef ___ARQUIVOS_H
#define ___ARQUIVOS_H
//Contem as funcoes que trabalham com arquivos do tipo txt ou svg.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#include"./Elementos/forma.h"
#include"./Elementos/quadra.h"
#include"./Elementos/hidrante.h"
#include"./Elementos/semaforo.h"
#include"./Elementos/radioBase.h"
#include"./Elementos/predio.h"
#include"./Elementos/muro.h"

/* Funcao que verifica se um arquivo foi realmente aberto */
void verificaArquivo (FILE * arquivo, char * nomeArquivo);
/* Funcao que trata o nome dos arquivos .geo e .qry caso seja passado um diretório realtivo no lugar */
char * tratarNome (char nomearq[], char * nomearq2);

/* Cria o arquivo .svg no diretório de saída (nomegeo.svg) */
char * criaSVG(char nomegeo[], char dirSaida[], char *arqsvg);
/* Funcao que cria o .txt no diretório de saída (nomegeo-nomeqry.txt) */
char * criaTXT (char nomegeo[], char nomeqry [], char dirSaida[], char *arqtxt);
/* Funcao que cria um segundo arquivo svg no diretorio de saida (nomegeo-nomeqry.svg) */
char * criaSVG2 (char nomegeo[], char nomeqry[], char dirSaida[], char *arqsvg2);
/* Funcao que cria um terceiro arquivo svg (BB) no diretório de saída (nomegeo-nomeqry-sufixo.svg) */
char * criaSVG3 (char * nomesvg, char * sufixo);

/* Funcao que printa um circulo nos arquivos .svg */
void svgprintcircle (Forma forma, FILE * arqSVG);
/* Funcao que printa um retangulo nos arquivos .svg */
void svgprintrect (Forma forma, FILE * arqSVG);
/* Funcao que printa um texto nos arquivos .svg */
void svgprinttext (char * text,double x, double y, FILE * arqSVG);
/* Funcao que printa um retangulo para auxiliar na consulta "bb" */
void svgprintrectBB (double xr, double yr, double wr, double hr, char * cor, FILE * arqSVG);
/* Funcao que printa uma elipse para auxiliar na consulta "bb" */
void svgprintellipse (double cx, double cy, double rx, double ry, char * cor, FILE * arqSVG);
/* Funcao que printa uma quadra nos arquivos .svg */
void svgprintQuadra (Quadra quadra, FILE * arqSVG);
/* Funcao que printa um hidrante nos arquivos .svg */
void svgprintHidrante (Hidrante hidrante, FILE * arqSVG);
/* Funcao que printa um semaforo nos arquivos .svg */
void svgprintSemaforo (Semaforo semaforo, FILE * arqSVG);
/* Funcao que printa uma radio base nos arquivos .svg */
void svgprintRadioBase (RadioBase radioBase, FILE * arqSVG);
/* Funcao que printa um circulo duplo (consulta dq) */
void svgprintDoubleCircle (Forma elemento, FILE* arqSVG);
void svgprintPredio (Predio predio, FILE * arqSVG);
void svgprintMuro (Muro muro, FILE * arqSVG);
void svgprintCircleLine (Forma forma, FILE * arqSVG);




#endif
