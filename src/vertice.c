#include "vertice.h"

struct StVertice {
    Ponto v;
    double dist, angulo;
    bool start;
    Segmento s;
};
typedef struct StVertice *VerticeImp;

Vertice criaVertice (Ponto p, double xB, double yB)
{
    VerticeImp vertice;
    vertice = (VerticeImp) malloc (sizeof (struct StVertice));

    vertice->v = p;
    vertice->dist = distanciaEuclidiana (getXPonto (p), getYPonto (p), xB, yB);
    vertice->angulo = atan2 (getYPonto (p) - yB, getYPonto(p) - xB);

    return vertice;
}

Ponto getVVertice (Vertice vertice)
{
    VerticeImp v;
    v = (VerticeImp) vertice;
    return v->v;
}

double getDistVertice (Vertice vertice)
{
    VerticeImp v;
    v = (VerticeImp) vertice;
    return v->dist;
}

double getAnguloVertice (Vertice vertice)
{
    VerticeImp v;
    v = (VerticeImp) vertice;
    return v->angulo;
}

bool getStartVertice (Vertice vertice)
{
    VerticeImp v;
    v = (VerticeImp) vertice;
    return v->start;
}

void setSegmentoVertice (Vertice vertice, Segmento segmento)
{
    VerticeImp v;
    v = (VerticeImp) vertice;
    v->s = segmento;
}

void setStartVertice (Vertice vertice, bool start)
{
    VerticeImp v;
    v = (VerticeImp) vertice;
    v->start = start;
}

void setAnguloVertice (Vertice vertice, double angulo)
{
    VerticeImp v;
    v = (VerticeImp) vertice;
    v->angulo = angulo;
}

void freeVertice (Vertice vertice)
{
    VerticeImp v;
    v = (VerticeImp) vertice;

    freePonto (v->v);
    freeSegmento (v->s);

    free (v);
}

