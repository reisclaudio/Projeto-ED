#include"semaforo.h"

struct StSemaforo {
    char id[50], tipo;
    double x, y;
    char cor1[24],cor2[24], sw[20];
};

typedef struct StSemaforo *SemaforoImp;

Semaforo criaSemaforo (char id[], double x, double y, char cor1[], char cor2[], char sw[])
{
    SemaforoImp novo;
    novo = (SemaforoImp) malloc (sizeof (struct StSemaforo));

    strcpy (novo->id, id);
    novo->x = x;
    novo->y = y;
    novo->tipo = 's';
    strcpy (novo->cor1, cor1);
    strcpy (novo->cor2, cor2);
    strcpy (novo->sw, sw);
    
    return novo;
}

double getXSema (Semaforo semaforo)
{
    SemaforoImp s;
    s = (SemaforoImp) semaforo;
    return s->x; 
}

double getYSema (Semaforo semaforo)
{
    SemaforoImp s;
    s = (SemaforoImp) semaforo;
    return s->y; 
}

char* getIDSema (Semaforo semaforo)
{
    SemaforoImp s;
    s = (SemaforoImp) semaforo;
    return s->id;
}

char* getCor1Sema (Semaforo semaforo)
{
    SemaforoImp s;
    s = (SemaforoImp) semaforo;
    return s->cor1;
}

char* getCor2Sema (Semaforo semaforo)
{
    SemaforoImp s;
    s = (SemaforoImp) semaforo;
    return s->cor2;
}

char* getSWSema (Semaforo semaforo)
{
    SemaforoImp s;
    s = (SemaforoImp) semaforo;
    return s->sw;
}

void setXSema (Semaforo semaforo, double x)
{
    SemaforoImp s;
    s = (SemaforoImp) semaforo;
    s->x = x;
}

void setYSema (Semaforo semaforo, double y)
{
    SemaforoImp s;
    s = (SemaforoImp) semaforo;
    s->y = y;
}

void freeSemaforo (Semaforo semaforo)
{
    SemaforoImp s;
    s = (SemaforoImp) semaforo;
    free (s);
}