#include"radioBase.h"

struct StRadioBase {
    char id[50], tipo;
    double x, y;
    char cor1[24],cor2[24], sw[20];
};

typedef struct StRadioBase *RadioBaseImp;

RadioBase criaRadioBase (char id[], double x, double y, char cor1[], char cor2[], char sw[])
{
    RadioBaseImp novo;
    novo = (RadioBaseImp) malloc (sizeof (struct StRadioBase));

    strcpy (novo->id, id);
    novo->x = x;
    novo->y = y;
    novo->tipo = 'b';
    strcpy (novo->cor1, cor1);
    strcpy (novo->cor2, cor2);
    strcpy (novo->sw, sw);

    return novo;
}

double getXRB (RadioBase radioBase)
{
    RadioBaseImp rb;
    rb = (RadioBaseImp) radioBase;
    return rb->x; 
}

double getYRB (RadioBase radioBase)
{
    RadioBaseImp rb;
    rb = (RadioBaseImp) radioBase;
    return rb->y; 
}

char* getIDRB (RadioBase radioBase)
{
    RadioBaseImp rb;
    rb = (RadioBaseImp) radioBase;
    return rb->id;
}

char* getCor1RB (RadioBase radioBase)
{
    RadioBaseImp rb;
    rb = (RadioBaseImp) radioBase;
    return rb->cor1;
}

char* getCor2RB (RadioBase radioBase)
{
    RadioBaseImp rb;
    rb = (RadioBaseImp) radioBase;
    return rb->cor2;
}

char* getSWRB (RadioBase radioBase)
{
    RadioBaseImp rb;
    rb = (RadioBaseImp) radioBase;
    return rb->sw;
}

void setXRB (RadioBase radioBase, double x)
{
    RadioBaseImp rb;
    rb = (RadioBaseImp) radioBase;
    rb->x = x;
}

void setYRB (RadioBase radioBase, double y)
{
    RadioBaseImp rb;
    rb = (RadioBaseImp) radioBase;
    rb->y = y;
}

void freeRadioBase (RadioBase radioBase)
{
    RadioBaseImp rb;
    rb = (RadioBaseImp) radioBase;
    free (rb);
}