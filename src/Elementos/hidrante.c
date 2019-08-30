#include"hidrante.h"

struct StHidrante {
    char id[50], tipo;
    double x, y;
    char cor1[24],cor2[24], sw[20];
};

typedef struct StHidrante *HidranteImp;

Hidrante criaHidrante (char id[], double x, double y, char cor1[], char cor2[], char sw[])
{
    HidranteImp novo;
    novo = (HidranteImp) malloc (sizeof (struct StHidrante));

    strcpy (novo->id, id);
    novo->x = x;
    novo->y = y;
    novo->tipo = 'h';
    strcpy (novo->cor1, cor1);
    strcpy (novo->cor2, cor2);
    strcpy (novo->sw, sw);
    
    return novo;
}

double getXHid (Hidrante hidrante)
{
    HidranteImp h;
    h = (HidranteImp) hidrante;
    return h->x; 
}

double getYHid (Hidrante hidrante)
{
    HidranteImp h;
    h = (HidranteImp) hidrante;
    return h->y; 
}

char* getIDHid (Hidrante hidrante)
{
    HidranteImp h;
    h = (HidranteImp) hidrante;
    return h->id;
}

char* getCor1Hid (Hidrante hidrante)
{
    HidranteImp h;
    h = (HidranteImp) hidrante;
    return h->cor1;
}

char* getCor2Hid (Hidrante hidrante)
{
    HidranteImp h;
    h = (HidranteImp) hidrante;
    return h->cor2;
}

char* getSWHid (Hidrante hidrante)
{
    HidranteImp h;
    h = (HidranteImp) hidrante;
    return h->sw;
}

void setXHid (Hidrante hidrante, double x)
{
    HidranteImp h;
    h = (HidranteImp) hidrante;
    h->x = x;
}

void setYHid (Hidrante hidrante, double y)
{
    HidranteImp h;
    h = (HidranteImp) hidrante;
    h->y = y;
}

void freeHidrante (Hidrante hidrante)
{
    HidranteImp h;
    h = (HidranteImp) hidrante;
    free (h);
}
