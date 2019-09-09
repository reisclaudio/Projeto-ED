#ifndef ___SVGPRINT_H
#define ___SVGPRINT_H
// Contem as funcoes que imprimem os Elementos nos arquivos .svg

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

typedef void * Vertice;

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
/* Funcao que printa um predio nos arquivos .svg */
void svgprintPredio (Predio predio, FILE * arqSVG);
/* Funcao que printa um muro nos arquivos .svg */
void svgprintMuro (Muro muro, FILE * arqSVG);
/* Funcao que printa um circulo e uma linha nos arquivos .svg para auxiliar nas consultas FI, FH e FS */
void svgprintCircleLine (Forma forma, FILE * arqSVG);
/* Funcao que printa a bomba de radiacao luminosa no .svg */
void svgprintBomba (double x, double y, FILE * arqSVG);
void svgprintTriangulo(double x1, double y1, Vertice v2, Vertice v3, FILE * arqSVG);






#endif
