#include"quadra.h"

struct StQuadra {
    char cep[50], tipo;
    double x, y, w, h;
    char cor1[24],cor2[24], sw[20]; 
};

typedef struct StQuadra *QuadraImp;

Quadra criaQuadra (char cep[], double x, double y, double w, double h, char cor1[], char cor2[], char sw[])
{
    QuadraImp novo;
    novo = (QuadraImp) malloc (sizeof (struct StQuadra));

    strcpy (novo->cep, cep);
    novo->x = x;
    novo->y = y;
    novo->w = w;
    novo->h = h;
    novo->tipo = 'q';
    strcpy (novo->cor1, cor1);
    strcpy (novo->cor2, cor2);
    strcpy (novo->sw, sw);

    return novo;
}

char* getCor1Quadra (Quadra quadra)
{
    QuadraImp q;
    q = (QuadraImp) quadra;
    return q->cor1;
}

char* getCor2Quadra (Quadra quadra)
{
    QuadraImp q;
    q = (QuadraImp) quadra;
    return q->cor2;
}

char* getCEPQuadra (Quadra quadra)
{
    QuadraImp q;
    q = (QuadraImp) quadra;
    return q->cep;
}

double getXQuadra (Quadra quadra)
{
    QuadraImp q;
    q = (QuadraImp) quadra;
    return q->x; 
}

double getYQuadra (Quadra quadra)
{
    QuadraImp q;
    q = (QuadraImp) quadra;
    return q->y; 
}

double getWQuadra (Quadra quadra)
{
    QuadraImp q;
    q = (QuadraImp) quadra;
    return q->w; 
}

double getHQuadra (Quadra quadra)
{
    QuadraImp q;
    q = (QuadraImp) quadra;
    return q->h; 
}

char* getSWQuadra (Quadra quadra)
{
    QuadraImp q;
    q = (QuadraImp) quadra;
    return q->sw;
}

void setXQuadra (Quadra quadra, double x)
{
    QuadraImp q;
    q = (QuadraImp) quadra;
    q->x = x;
}

void setYQuadra (Quadra quadra, double y)
{
    QuadraImp q;
    q = (QuadraImp) quadra;
    q->y = y;
}

void setCor1Quadra (Quadra quadra, char* cor1)
{
    QuadraImp q;
    q = (QuadraImp) quadra;
    strcpy (q->cor1, cor1);
}

void setCor2Quadra (Quadra quadra, char* cor2)
{
    QuadraImp q;
    q = (QuadraImp) quadra;
    strcpy (q->cor2, cor2);
}

void freeQuadra (Quadra quadra)
{
    QuadraImp q;
    q = (QuadraImp) quadra;
    free (q);
}
