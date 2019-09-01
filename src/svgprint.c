#include"leitura.h"
#include"lista.h"
#include"arquivos.h"
#include"./Elementos/forma.h"
#include"./Elementos/quadra.h"
#include"./Elementos/hidrante.h"
#include"./Elementos/semaforo.h"
#include"./Elementos/radioBase.h"
#include"./Elementos/predio.h"
#include"./Elementos/muro.h"
#include"lista.h"

void svgprintcircle (Forma forma, FILE * arqSVG)
{   
    fprintf (arqSVG, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" />\n", getXForma(forma), getYForma(forma), getRaioForma(forma), getCor2Forma(forma), getCor1Forma(forma), getSWForma (forma)); 
}

void svgprintCircleLine (Forma forma, FILE * arqSVG)
{
    fprintf (arqSVG, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" />\n", getXForma(forma), getYForma(forma), getRaioForma(forma), getCor2Forma(forma), getCor1Forma(forma), getSWForma (forma)); 
    fprintf(arqSVG, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"black\" />\n", getXForma (forma),getYForma (forma), getWForma (forma), getHForma (forma));
}

void svgprintrect (Forma forma, FILE * arqSVG)
{
    fprintf (arqSVG, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" />\n", getXForma (forma), getYForma (forma), getWForma (forma), getHForma (forma), getCor2Forma (forma), getCor1Forma (forma), getSWForma(forma));
}

void svgprinttext (char * text, double x, double y, FILE * arqSVG)
{
    fprintf (arqSVG, "<text x=\"%lf\" y=\"%lf\"> %s </text>\n", x, y, text);
}

void svgprintrectBB (double xr, double yr, double wr, double hr, char * cor, FILE * arqSVG)
{
    fprintf (arqSVG, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"none\" stroke=\"%s\"/>\n", xr, yr, wr, hr, cor);
}

void svgprintellipse (double cx, double cy, double rx, double ry, char * cor, FILE * arqSVG)
{
    fprintf (arqSVG, "<ellipse cx=\"%lf\" cy=\"%lf\" rx=\"%lf\" ry=\"%lf\" fill=\"none\" stroke=\"%s\"/>\n", cx, cy, rx, ry, cor);
}

void svgprintQuadra (Quadra quadra, FILE * arqSVG)
{
    fprintf (arqSVG, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" />\n", getXQuadra (quadra), getYQuadra (quadra), getWQuadra (quadra), getHQuadra (quadra), getCor1Quadra (quadra), getCor2Quadra (quadra), getSWQuadra (quadra));
    fprintf (arqSVG, "<text x=\"%lf\" y=\"%lf\" font-size=\"12\" fill=\"%s\"> %s </text>\n", getXQuadra (quadra) + 3, getYQuadra (quadra) + 12, getCor2Quadra (quadra), getCEPQuadra (quadra));
}
void svgprintHidrante (Hidrante hidrante, FILE * arqSVG)
{
    fprintf (arqSVG, "<rect x=\"%lf\" y=\"%lf\" width=\"10\" height=\"10\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" />\n", getXHid (hidrante), getYHid (hidrante), getCor1Hid (hidrante), getCor2Hid (hidrante), getSWHid (hidrante));
    fprintf (arqSVG, "<text x=\"%lf\" y=\"%lf\" font-size=\"12\" fill=\"%s\"> H </text>\n", getXHid (hidrante)+0.5, getYHid (hidrante) + 9, getCor2Hid (hidrante));
}

void svgprintSemaforo (Semaforo semaforo, FILE * arqSVG)
{
    fprintf (arqSVG, "<circle cx=\"%lf\" cy=\"%lf\" r=\"6\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" /> \n", getXSema(semaforo), getYSema(semaforo),getCor1Sema (semaforo), getCor2Sema (semaforo), getSWSema (semaforo)); 
    fprintf (arqSVG, "<text x=\"%lf\" y=\"%lf\" font-size=\"13\" fill=\"%s\"> S </text>\n", getXSema (semaforo)-4, getYSema (semaforo)+4, getCor2Sema (semaforo));
}

void svgprintRadioBase (RadioBase radioBase, FILE * arqSVG)
{
    fprintf (arqSVG, "<rect x=\"%lf\" y=\"%lf\" width=\"5\" height=\"13\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" />\n", getXRB (radioBase), getYRB (radioBase), getCor1RB (radioBase), getCor2RB (radioBase), getSWRB (radioBase));
    fprintf (arqSVG, "<text x=\"%lf\" y=\"%lf\" font-size=\"5\" fill=\"%s\"> RB </text>\n", getXHid (radioBase)+3, getYHid (radioBase) + 4, getCor2RB (radioBase));
}

void svgprintPredio (Predio predio, FILE * arqSVG)
{
    Predio p;
    double xPredio, yPredio;

    if ((getFacePredio (predio) == 'N') || (getFacePredio (predio) == 'n')){
        xPredio = getxQPredio (predio) + getNumPredio (predio);
        yPredio = ((getyQPredio (predio) + gethQPredio (predio)) - getMrgPredio (predio)) - getPPredio (predio);
    }
    else if ((getFacePredio (predio) == 'S') || (getFacePredio (predio) == 's')){
        xPredio = getxQPredio (predio) + getNumPredio (predio);
        yPredio = getyQPredio (predio) + getMrgPredio (predio);
    }
    else if ((getFacePredio (predio) == 'L') || (getFacePredio (predio) == 'l')){
        xPredio = getxQPredio (predio) + getMrgPredio (predio);
        yPredio = getyQPredio (predio) + getNumPredio (predio);
    }
    else if ((getFacePredio (predio) == 'O') || (getFacePredio (predio) == 'o')){
        xPredio = ((getxQPredio (predio) + getwQPredio (predio)) - getMrgPredio (predio)) - getPPredio (predio);
        yPredio = getyQPredio (predio) + getNumPredio (predio);
    }
    
    p = criaForma (" ", 'p', xPredio, yPredio, 0, getFPredio (predio), getPPredio (predio), "black", "white", "1");
    svgprintrect (p, arqSVG);
    free (p); 
}

void svgprintMuro (Muro muro, FILE * arqSVG)
{
    fprintf (arqSVG, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"black\" />\n", getX1Muro (muro), getY1Muro (muro), getX2Muro (muro), getY2Muro (muro));
}

void svgprintDoubleCircle (Forma elemento, FILE* arqSVG){
    if (getTipo (elemento) == 's'){
        fprintf (arqSVG, "<circle cx=\"%lf\" cy=\"%lf\" r=\"10\" fill=\"none\" stroke=\"blue\" stroke-width=\"6\" />\n", getXHid (elemento), getYHid (elemento));
        fprintf (arqSVG, "<circle cx=\"%lf\" cy=\"%lf\" r=\"16\" fill=\"none\" stroke=\"green\" stroke-width=\"6\" />\n", getXHid (elemento), getYHid (elemento));
    }
    else if (getTipo (elemento) == 'h'){
        fprintf (arqSVG, "<circle cx=\"%lf\" cy=\"%lf\" r=\"10\" fill=\"none\" stroke=\"blue\" stroke-width=\"6\" />\n", getXHid (elemento) + 5, getYHid (elemento) + 5);
        fprintf (arqSVG, "<circle cx=\"%lf\" cy=\"%lf\" r=\"16\" fill=\"none\" stroke=\"green\" stroke-width=\"6\" />\n", getXHid (elemento) + 5, getYHid (elemento) + 5);
    }
    else if (getTipo (elemento) == 'b'){
        fprintf (arqSVG, "<circle cx=\"%lf\" cy=\"%lf\" r=\"10\" fill=\"none\" stroke=\"blue\" stroke-width=\"6\" />\n", getXHid (elemento) + 3, getYHid (elemento) + 4);
        fprintf (arqSVG, "<circle cx=\"%lf\" cy=\"%lf\" r=\"16\" fill=\"none\" stroke=\"green\" stroke-width=\"6\" />\n", getXHid (elemento) + 3, getYHid (elemento) + 4);
    }
}
