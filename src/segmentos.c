#include"segmentos.h"

#define PI 3.14159265

struct StSegmento {
    double x1, y1, x2, y2;
};

struct StVertice{
    double x, y, angulo, dist;
    bool start;
    Segmento segmento;
};

typedef struct StSegmento *SegmentoImp;
typedef struct StVertice *VerticeImp;

Segmento criaSegmento (double x1, double y1, double x2, double y2){
    SegmentoImp s = (SegmentoImp) malloc (sizeof (struct StSegmento));

    s->x1 = x1;
    s->y1 = y1;
    s->x2 = x2;
    s->y2 = y2;

    return s;
}

Segmento criaSegmentos (int capacidade)
{
    SegmentoImp *segmentos = (SegmentoImp *) malloc (capacidade * sizeof (SegmentoImp));

    return segmentos;
}

void inserirSegmento (Segmento aux, int* tamanho, double x1, double y1, double x2, double y2)
{
    SegmentoImp *segmentos = (SegmentoImp *) aux;

    segmentos[*tamanho] = (SegmentoImp) malloc(sizeof(struct StSegmento));
    segmentos[*tamanho]->x1 = x1;
    segmentos[*tamanho]->y1 = y1;
    segmentos[*tamanho]->x2 = x2;
    segmentos[*tamanho]->y2 = y2;

    *tamanho = *tamanho + 1;
}

void imprimeSegmentos (Segmento aux, int tamanho, FILE * arqSVG)
{
    int j = 0;
    SegmentoImp *segmentos = (SegmentoImp *) aux;

    for (int i = 0; i < tamanho; i++){
        fprintf (arqSVG, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"red\" />\n", segmentos[i]->x1, segmentos[i]->y1, segmentos[i]->x2, segmentos[i]->y2);
    }
}

void freeSegmentos (Segmento aux, int tamanho)
{
    SegmentoImp *segmentos = (SegmentoImp *) aux;

    for (int i = 0; i < tamanho; i++){
        free (segmentos[i]);
    }
    free (segmentos);
}

Vertice criaVertices (double x, double y, int capacidade, Segmento s, int tamanho, FILE * arqSVG)
{
    int j = 0, k = 1;
    SegmentoImp *segmentos = (SegmentoImp *) s;
    VerticeImp *vertices = (VerticeImp *) malloc (capacidade * sizeof (VerticeImp));

    for (int i = 0; i < tamanho; i++){
        vertices[j] = (VerticeImp) malloc (sizeof (struct StVertice));
        vertices[j]->x = segmentos[i]->x1;
        vertices[j]->y = segmentos[i]->y1;
        vertices[j]->dist = distanciaEuclidiana (x, y, vertices[j]->x, vertices[j]->y);
        vertices[j]->angulo = atan2 (vertices[j]->y - y, vertices[j]->x - x) * 180 / PI;

        vertices[k] = (VerticeImp) malloc (sizeof (struct StVertice));
        vertices[k]->x = segmentos[i]->x2;
        vertices[k]->y = segmentos[i]->y2;
        vertices[k]->dist = distanciaEuclidiana (x, y, vertices[k]->x, vertices[k]->y);
        vertices[k]->angulo = atan2 (vertices[k]->y - y, vertices[k]->x - x) * 180 / PI;

        if (vertices[j]->angulo < vertices[k]->angulo){
            vertices[j]->start = true;
            vertices[k]->start = false;
            Forma forma = criaForma (" ", 'c', vertices[j]->x, vertices[j]->y, 4, 0, 0, "green", "green", "1");
            Forma forma2 = criaForma (" ", 'c', vertices[k]->x, vertices[k]->y, 4, 0, 0, "red", "red", "1");
            svgprintcircle (forma, arqSVG);
            svgprintcircle (forma2, arqSVG);
        }
        else {
            vertices[j]->start = false;
            vertices[k]->start = true;
            Forma forma = criaForma (" ", 'c', vertices[k]->x, vertices[k]->y, 4, 0, 0, "green", "green", "1");
            Forma forma2 = criaForma (" ", 'c', vertices[j]->x, vertices[j]->y, 4, 0, 0, "red", "red", "1");
            svgprintcircle (forma, arqSVG);
            svgprintcircle (forma2, arqSVG);
        }
        
        j+=2;
        k+=2;
    }

    return vertices;

}

int cmpVertices (const void *a, const void *b)
{
    VerticeImp arg1 = * (const VerticeImp *) a;
    VerticeImp arg2 = * (const VerticeImp *) b;

    if (arg1->angulo < arg2->angulo) return -1;
    else if (arg1->angulo > arg2->angulo) return 1;

    else if (arg1->dist < arg2->dist) return -1;
    else if (arg1->dist > arg2->dist) return 1;

    else if (arg1->start && !arg2->start) return -1;
    else if (!arg1->start && arg2->start) return 1;

    return 0;
}

void sortVertices (Vertice v, int tamanho)
{
    VerticeImp *vertices = (VerticeImp *) v;

    qsort (vertices, tamanho, sizeof (VerticeImp), cmpVertices);
}

bool intersecSegmentos (Segmento s1, Segmento s2, double* x, double* y){
    SegmentoImp segmento1 = (SegmentoImp) s1;
    SegmentoImp segmento2 = (SegmentoImp) s2;
    double aX = segmento1->x1;
    double aY = segmento1->y1;
    double bX = segmento1->x2;
    double bY = segmento1->y2;

    double cX = segmento2->x1;
    double cY = segmento2->y1;
    double dX = segmento2->x2;
    double dY = segmento2->y2;

    double  distAB, theCos, theSin, newX, ABpos;

    if (((aX == bX) && (aY == bY)) || ((cX == dX) && (cY == dY))) return false;

    bX = bX - aX;
    bY = bY - aY;
    cX = cX - aX;
    cY = cY - aY;
    dX = dX - aX;
    dY = dY - aY;

    distAB = sqrt (bX*bX+bY*bY);

    theCos = bX/distAB;
    theSin = bY/distAB;
    newX = cX*theCos + cY*theSin;
    cY = cY*theCos - cX*theSin;
    cX = newX;
    newX = dX*theCos+dY*theSin;
    dY = dY*theCos-dX*theSin;
    dX = newX;

    if (cY == dY) return false;

    ABpos = dX + (cX-dX) + dY/(dY-cY);

    *x = aX+ABpos*theCos;
    *y = aY+ABpos*theSin;

    return true;
}