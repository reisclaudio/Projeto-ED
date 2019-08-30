#include"forma.h"

struct StForma {
    char id[50], tipo;
    double x, y, r, w, h;
    char cor1[24],cor2[24], sw[20];
};

typedef struct StForma *FormaImp;

Forma criaForma (char id[],char tipo, double x, double y, double r, double w,double h, char cor1[], char cor2[], char sw[])
{
    FormaImp novo;
    novo = (FormaImp) malloc (sizeof (struct StForma));

    strcpy (novo->id, id);
    novo->x = x;
    novo->y = y;
    novo->r = r;
    novo->w = w;
    novo->h = h;
    novo->tipo = tipo;
    strcpy (novo->cor1, cor1);
    strcpy (novo->cor2, cor2);
    strcpy (novo->sw, sw);

    return novo;
}

double getXForma (Forma forma)
{
    FormaImp f;
    f =  (FormaImp) forma;
    return f->x; 
}

double getYForma (Forma forma)
{
    FormaImp f;
    f =  (FormaImp) forma;
    return f->y; 
}

double getRaioForma (Forma forma)
{
    FormaImp f;
    f = (FormaImp) forma;
    return f->r;
}

double getWForma (Forma forma)
{
    FormaImp f;
    f =  (FormaImp) forma;
    return f->w; 
}

double getHForma (Forma forma)
{
    FormaImp f;
    f =  (FormaImp) forma;
    return f->h; 
}

char* getCor1Forma (Forma forma)
{
    FormaImp f;
    f =  (FormaImp) forma;
    return f->cor1; 
}

char* getCor2Forma (Forma forma)
{
    FormaImp f;
    f =  (FormaImp) forma;
    return f->cor2; 
}

char* getSWForma (Forma forma)
{
    FormaImp f;
    f =  (FormaImp) forma;
    return f->sw;
}

void freeForma (Forma forma)
{
    FormaImp f;
    f = (FormaImp) forma;
    free (f);
}

char getTipo (Forma forma)
{
    FormaImp f;
    f = (FormaImp) forma;
    return f->tipo;
}

