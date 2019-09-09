#include"ponto.h"

struct StPonto {
    double x, y;
};
typedef struct StPonto *PontoImp;

Ponto criaPonto (double x, double y)
{
    PontoImp ponto = (PontoImp) malloc (sizeof (struct StPonto));

    ponto->x = x;
    ponto->y = y;

    return ponto;
}

double getXPonto (Ponto ponto)
{
    PontoImp p;
    p = (PontoImp) ponto;
    return p->x;
}

double getYPonto (Ponto ponto)
{
    PontoImp p;
    p = (PontoImp) ponto;
    return p->y;
}

void setPontoMin (Ponto ponto, double x, double y)
{
    PontoImp p;
    p = (PontoImp) p;

    if (x < p->x) p->x = x;
    if (y < p->y) p->y = y;
}

void setPontoMax (Ponto ponto, double x, double y)
{
    PontoImp p;
    p = (PontoImp) p;

    if (x > p->x) p->x = x;
    if (y > p->y) p->y = y;
}

void freePonto (Ponto ponto)
{
    PontoImp p;
    p = (PontoImp) ponto;
    free (p);
}
