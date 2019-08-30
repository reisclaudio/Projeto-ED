#include"muro.h"

struct StMuro {
    char cep [50], tipo;
    double x1, y1, x2, y2;
};

typedef struct StMuro *MuroImp;

Muro criaMuro (double x1, double y1, double x2, double y2)
{
    MuroImp novo;
    novo = (MuroImp) malloc (sizeof (struct StMuro));

    novo->tipo = 'm';
    novo->x1 = x1;
    novo->y1 = y1;
    novo->x2 = x2;
    novo->y2 = y2;

    return novo;
}

double getX1Muro (Muro muro)
{
    MuroImp m;
    m = (MuroImp) muro;
    return m->x1;
}

double getY1Muro (Muro muro)
{
    MuroImp m;
    m = (MuroImp) muro;
    return m->y1;
}

double getX2Muro (Muro muro)
{
    MuroImp m;
    m = (MuroImp) muro;
    return m->x2;
}

double getY2Muro (Muro muro)
{
    MuroImp m;
    m = (MuroImp) muro;
    return m->y2;
}

void freeMuro (Muro muro)
{
    MuroImp m;
    m = (MuroImp) muro;
    free (m);
}