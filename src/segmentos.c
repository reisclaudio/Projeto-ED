#include"segmentos.h"

struct StSegmento {
    double x1, y1, x2, y2;
};

typedef struct StSegmento *SegmentoImp;


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