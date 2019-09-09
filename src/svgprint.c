#include"svgprint.h"
#include"leitura.h"
#include"lista.h"
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

void svgprintPredio (Predio predio,  FILE * arqSVG)
{  
    char numeroPredio [10];
    sprintf (numeroPredio, "%.0lf", getNumPredio (predio));
    Forma p = criaForma (" ", 'p', getXPredio (predio), getYPredio (predio), 0, getFPredio (predio), getPPredio (predio), "black", "white", "1");
    
    svgprintrect (p, arqSVG);
    svgprinttext (numeroPredio, getXPredio (predio), getYPredio (predio) + getPPredio (predio) - 1, arqSVG);
    
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

void svgprintBomba (double x, double y, FILE * arqSVG)
{
    fprintf(arqSVG, "\n<g transform=\"translate (%lf %lf) scale(0.05 0.05)\"><path d=\"m419.922 511.794c-2.94 0-5.869-.863-8.395-2.568l-103.005-69.548c-4.131-2.789-6.606-7.448-6.606-12.432v-131.749c0-8.284 18.368-21.514 20.295-24.588 4.4-7.02 13.658-9.143 20.676-4.743l85 53.279c4.376 2.743 7.034 7.544 7.034 12.709v164.64c0 5.548-3.062 10.643-7.961 13.246-2.208 1.173-4.627 1.754-7.038 1.754z\" fill=\"#e0d2cd\"/><path d=\"m91.872 511.794c-2.412 0-4.83-.581-7.038-1.754-4.899-2.604-7.961-7.698-7.961-13.246v-164.64c0-5.165 2.657-9.967 7.034-12.709l85-53.279c5.736-3.596 13.17-2.903 18.143 1.689l18 16.622c3.075 2.84 4.823 6.834 4.823 11.02v131.749c0 4.984-2.476 9.643-6.606 12.431l-103 69.548c-2.526 1.706-5.455 2.569-8.395 2.569z\" fill=\"#eee1dc\"/><path d=\"m174.897 346.897-50.11-90.104c-11.683-20.983-16.893-39.479-16.893-59.974v-48.819c0-17.204 2.95-33.731 8.372-49.103 20.296-57.546 260.857-56.104 280.278 3 4.769 14.515 7.35 30.013 7.35 46.103v48.582c0 20.464-5.192 38.932-16.836 59.88l-50.162 90.436h-161.999z\" fill=\"#fff4f4\"/><path d=\"m396.544 101.897c-9.752-29.678-75.264-44.816-140.647-45.248v290.248h81l50.162-90.436c11.644-20.948 16.836-39.416 16.836-59.88v-48.581c0-16.09-2.581-31.589-7.351-46.103z\" fill=\"#f6efea\"/><path d=\"m116.278 98.897h279.232c-20.297-57.544-75.213-98.897-139.615-98.897s-119.319 41.353-139.617 98.897z\" fill=\"#ff1f3e\"/><path d=\"m171.601 340.897 28.986 52.075c.117.209.239.417.365.621l.245.395c2.737 4.405 7.555 7.084 12.741 7.084h.013l83.956-.072c5.442-.004 10.454-2.956 13.098-7.712l29.121-52.391z\" fill=\"#00347b\"/><path d=\"m255.897 98.897h139.614c-20.298-57.543-75.213-98.896-139.614-98.897z\" fill=\"#d10050\"/><path d=\"m255.897 340.897v60.138l42.01-.035c5.442-.004 10.454-2.956 13.098-7.712l29.121-52.391z\" fill=\"#001737\"/></g>\n", x, y);
}

void svgprintTriangulo(double x1, double y1, Vertice v2, Vertice v3, FILE * arqSVG) 
{
	//double x1 = Vertice_get_x(v1), y1 = Vertice_get_y(v1);
	double x2 = getXPonto(getVVertice(v2)), y2 = getYPonto(getVVertice(v2));
	double x3 = getXPonto(getVVertice(v3)), y3 = getYPonto(getVVertice(v3));
	fprintf(arqSVG, "<polygon points=\"%lf,%lf %lf,%lf %lf,%lf\" style=\"fill: orange; opacity: 0.5\"/>\n", x1, y1, x2, y2, x3, y3);
}

