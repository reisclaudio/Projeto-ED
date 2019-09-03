#include"segmentos.h"

struct StSegmento {
    double x1, y1, x2, y2;
};

typedef struct StSegmento *SegmentoImp;


Segmento criaSegmentos (int capacidade)
{
    SegmentoImp segmentos = (SegmentoImp) malloc (capacidade * sizeof (SegmentoImp));

    return segmentos;
}

void inserirSegmento (Segmento aux, int* tamanho, double x1, double y1, double x2, double y2)
{
    SegmentoImp *segmentos = (SegmentoImp *) aux;

    segmentos[*tamanho]->x1 = x1;
    segmentos[*tamanho]->y1 = y1;
    segmentos[*tamanho]->x2 = x2;
    segmentos[*tamanho]->y2 = y2;

    *tamanho++;
}