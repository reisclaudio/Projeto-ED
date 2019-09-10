#include"segmento.h"

#define PI 3.14159265

struct StSegmento {
    Vertice v1;
    Vertice v2;
};
typedef struct StSegmento *SegmentoImp;

Segmento criaSegmento (Vertice v1, Vertice v2)
{
    SegmentoImp segmento = (SegmentoImp) malloc (sizeof (struct StSegmento));

    segmento->v1 = v1;
    segmento->v2 = v2;

    return segmento;
}

Vertice getV1Segmento (Segmento segmento)
{
    SegmentoImp s;
    s = (SegmentoImp) segmento;
    return s->v1;
}

Vertice getV2Segmento (Segmento segmento)
{
    SegmentoImp s;
    s = (SegmentoImp) segmento;
    return s->v2;
}

void setSegmentoStartVertice (Segmento segmento)
{
    SegmentoImp s;
    s = (SegmentoImp) segmento;

    if (getAnguloVertice (s->v1) < getAnguloVertice (s->v2)){
        setStartVertice (s->v1, true);
        setStartVertice (s->v2, false);
    }
    else if (getAnguloVertice (s->v2) < getAnguloVertice (s->v1)){
        setStartVertice (s->v1, false);
        setStartVertice (s->v2, true);
    }
    else if (getDistVertice (s->v1) < getDistVertice (s->v2)){
        setStartVertice (s->v1, true);
        setStartVertice (s->v2, false);
    }
    else {
        setStartVertice (s->v1, false);
        setStartVertice (s->v2, true);
    } 
}

void freeSegmento (Segmento segmento)
{
    SegmentoImp s;
    s = (SegmentoImp) segmento;
    free (s);
}

