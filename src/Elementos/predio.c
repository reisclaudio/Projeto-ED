#include"predio.h"

struct StPredio {
    char cep [50], tipo;
    char face;
    double num, f, p, mrg;
    double x, y;
    double hQ, wQ;
};

typedef struct StPredio *PredioImp;

Predio criaPredio (char cep[], char face, double num, double f, double p, double mrg, double x, double y, double hQ, double wQ)
{
    PredioImp novo;
    novo = (PredioImp) malloc (sizeof (struct StPredio));

    strcpy (novo->cep, cep);
    novo->tipo = 'p';
    novo->face = face;
    novo->num = num;
    novo->f = f;
    novo->p = p;
    novo->mrg = mrg;
    novo->x = x;
    novo->y = y;
    novo->hQ = hQ;
    novo->wQ = wQ;

    return novo;
}

char* getCEPPredio (Predio predio)
{
    PredioImp p;
    p = (PredioImp) predio;
    return p->cep;
}

char getFacePredio (Predio predio)
{
    PredioImp p;
    p = (PredioImp) predio;
    return p->face;
}

double getNumPredio (Predio predio)
{
    PredioImp p;
    p = (PredioImp) predio;
    return p->num;
}

double getFPredio (Predio predio)
{
    PredioImp p;
    p = (PredioImp) predio;
    return p->f;
}

double getPPredio (Predio predio)
{
    PredioImp p;
    p = (PredioImp) predio;
    return p->p;
}

double getMrgPredio (Predio predio)
{
    PredioImp p;
    p = (PredioImp) predio;
    return p->mrg;
}

void freePredio (Predio predio)
{
    PredioImp p;
    p = (PredioImp) predio;
    free (p);
}

double getXPredio (Predio predio)
{
    PredioImp p;
    p = (PredioImp) predio;
    return p->x;
}

double getYPredio (Predio predio)
{
    PredioImp p;
    p = (PredioImp) predio;
    return p->y;
}

double gethQPredio (Predio predio)
{
    PredioImp p;
    p = (PredioImp) predio;
    return p->hQ;
}

double getwQPredio (Predio predio)
{
    PredioImp p;
    p = (PredioImp) predio;
    return p->wQ;
}
