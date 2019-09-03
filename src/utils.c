#include"utils.h"

typedef struct {
    int id;
    double x, y;
    double largura, altura;
    double raio;
} valores;

double distanciaEuclidiana (double x1, double y1, double x2, double y2)
{
    return sqrt((pow((x1-x2),2) + pow((y1-y2),2)));
}

double manhattanDistance (double x1, double y1, double x2, double y2)
{
    return fabs (x1-x2) + fabs (y1-y2);
}

double clamp (double pc, double pmi, double pma)
{
    if (pc > pma) return pma;
    else if (pc < pmi) return pmi;
    else return pc;
}

double distCentrosMassa (Elemento elemento1, Elemento elemento2)
{
    valores d[2];
    if (getTipo(elemento1) == 'c'){ 
        d[0].x = getXForma (elemento1);
        d[0].y = getYForma (elemento1);
    }
    else{
        d[0].x = getXForma (elemento1) + (getWForma (elemento1)/2.0);
        d[0].y = getYForma (elemento1) + (getHForma (elemento1)/2.0);
    }

    if (getTipo (elemento2) == 'c'){
        d[1].x = getXForma (elemento2);
        d[1].y = getYForma (elemento2);
    }
    else {
        d[1].x = getXForma (elemento2) + (getWForma (elemento2)/2.0);
        d[1].y = getYForma (elemento2) + (getHForma (elemento2)/2.0);
    }

    return distanciaEuclidiana (d[0].x, d[0].y, d[1].x, d[1].y);
}

bool estaContidoCC (Elemento elemento1, Elemento elemento2)
{
    valores d[2];
    d[0].x = getXForma (elemento1);
    d[0].y = getYForma (elemento1);
    d[1].x = getXForma (elemento2);
    d[1].y = getYForma (elemento2);

    double dist = distanciaEuclidiana (d[0].x, d[0].y, d[1].x, d[1].y);
    if (dist <=  getRaioForma (elemento1) + getRaioForma (elemento2))
        return true;
    return false;
}

bool estaContidoRR (Elemento elemento1, Elemento elemento2)
{
    valores d[2];
    d[0].x = getXForma (elemento1);
    d[0].y = getYForma (elemento1);
    d[1].x = getXForma (elemento2);
    d[1].y = getYForma (elemento2);

    if (getXForma (elemento1) <= getXForma (elemento2) + getWForma (elemento1) && getYForma (elemento1) <= getYForma (elemento2) + getHForma (elemento2) && 
    getXForma (elemento1) + getWForma (elemento1) >= getXForma (elemento2) && getYForma (elemento1) + getHForma (elemento1) >= getYForma (elemento2))
        return true;
    return false;
}

bool estaContidoCR (Elemento elemento1, Elemento elemento2)
{
    valores d[2];
    if (getTipo (elemento1) == 'c'){
        d[0].raio = getRaioForma (elemento1);
        d[0].x = getXForma (elemento1);
        d[0].y = getYForma (elemento1);
    }
    if (getTipo (elemento1) == 'r'){
        d[1].largura = getWForma (elemento1);
        d[1].altura = getHForma (elemento1);
        d[1].x = getXForma (elemento1);
        d[1].y = getYForma (elemento1);
    }
    if (getTipo (elemento2) == 'c'){
        d[0].raio = getRaioForma (elemento2);
        d[0].x = getXForma (elemento2);
        d[0].y = getYForma (elemento2);
    }
    if (getTipo (elemento2) == 'r'){
        d[1].largura = getWForma (elemento2);
        d[1].altura = getHForma (elemento2);
        d[1].x = getXForma (elemento2);
        d[1].y = getYForma (elemento2);
    }

    double xmp = clamp (d[0].x, d[1].x, d[1].x + d[1].largura);
    double ymp = clamp (d[0].y, d[1].y, d[1].y + d[1].altura);

    if ((distanciaEuclidiana (d[0].x, d[0].y, xmp, ymp)) <= d[0].raio)
        return true;
    return false;
}

bool pontoEstaContido (double x, double y, Elemento elemento)
{
    if (getTipo (elemento) == 'c'){
        double dist = distanciaEuclidiana(x, y, getXForma (elemento), getYForma (elemento));
        if (dist <= getRaioForma (elemento))
            return true;
        return false;
    }

    if (getTipo (elemento) == 'r'){
        if (x > getXForma (elemento) && x < getXForma (elemento) + getWForma (elemento) && y > getYForma (elemento) && y < getYForma (elemento) + getHForma (elemento))
            return true;
        return false;
    }
}

void inverterVetor (Dist vet[], int tamanhoVetor){
    Dist aux;
    int j = tamanhoVetor -1;
    for (int i = 0; i < tamanhoVetor/2; i++){
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
        j--;
    }
}

