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

Vertice criaVertices (double x, double y, int capacidade, Segmento s, int tamanho)
{
    int j = 0, k = 1;
    SegmentoImp *segmentos = (SegmentoImp *) s;
    VerticeImp *vertices = (VerticeImp *) malloc (capacidade * sizeof (VerticeImp));

    for (int i = 0; i < tamanho; i++){
        vertices[j] = (VerticeImp) malloc (sizeof (struct StVertice));
        vertices[j]->x = segmentos[i]->x1;
        vertices[j]->y = segmentos[i]->x2;
        vertices[j]->dist = distanciaEuclidiana (x, y, vertices[j]->x, vertices[j]->y);
        vertices[j]->angulo = atan2 (vertices[j]->y - y, vertices[j]->x - x) * 180 / PI;

        vertices[k] = (VerticeImp) malloc (sizeof (struct StVertice));
        vertices[k]->x = segmentos[i]->x1;
        vertices[k]->y = segmentos[i]->x2;
        vertices[k]->dist = distanciaEuclidiana (x, y, vertices[k]->x, vertices[k]->y);
        vertices[k]->angulo = atan2 (vertices[k]->y - y, vertices[k]->x - x) * 180 / PI;

        if (vertices[j]->angulo < vertices[k]->angulo){
            vertices[j]->start = true;
            vertices[k]->start = false;
        }
        else {
            vertices[j]->start = false;
            vertices[k]->start = true;
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


