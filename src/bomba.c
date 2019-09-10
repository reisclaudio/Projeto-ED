#include"bomba.h"

int cmpVertices (const void *a, const void *b)
{
    Vertice arg1 = * (const Vertice *)a;
    Vertice arg2 = * (const Vertice *)b;

    if (getAnguloVertice (arg1) < getAnguloVertice (arg2)) return -1;
    else if (getAnguloVertice (arg1) > getAnguloVertice (arg2)) return 1;

    else if (getDistVertice (arg1) < getDistVertice (arg2)) return -1;
    else if (getDistVertice (arg1) > getDistVertice (arg2)) return 1;

    else if (!getStartVertice (arg1) && getStartVertice (arg2)) return -1;
    else if (getStartVertice (arg1) && !getStartVertice (arg2)) return 1;

    return 0;
}

Segmento buscarSegmentoFormadoComVertice(double xc, double yc, Vertice v, Ponto pontoMin, Ponto pontoMax) {
	double xv = getXPonto(getVVertice(v)), yv = getYPonto(getVVertice(v));
	double a, b;
    
	if(xv != xc) { // reta perpendicular ver dps
		a = (yv-yc)/(xv-xc);
		b = yc - a*xc;
	}

	double xq, yq;
	// y = ax + b
	// x = (y-b)/a
	if(xc < xv && yc > yv) { 
		xq = (getYPonto(pontoMin) - 50 - b)/a;
		yq = a*(getXPonto(pontoMax) + 50) + b;
		if(distanciaEuclidiana(xc, yc, xq, getYPonto(pontoMin) - 50) > distanciaEuclidiana(xc, yc, getXPonto(pontoMax) + 50, yq)) {
			yq = getYPonto(pontoMin) - 50;
		} else {
			xq = getXPonto(pontoMax) + 50;
		}
	} else if(xc < xv && yc == yv) { // certo
		xq = getXPonto(pontoMax) + 50;
		yq = yc;
	} else if(xc < xv && yc < yv) {
		xq = (yc + 50 - b)/a;
		yq = a*(getXPonto(pontoMax) + 50) + b;
		if(distanciaEuclidiana(xc, yc, xq, yc + 50) > distanciaEuclidiana(xc, yc, getXPonto(pontoMax) + 50, yq)) {
			yq = yc + 50;
		} else {
			xq = getXPonto(pontoMax) + 50;
		}
	} else if(xc > xv && yc > yv) {
		xq = (getXPonto(pontoMin) - 50 - b)/a;
		yq = a*(getXPonto(pontoMin) - 50) + b;
		if(distanciaEuclidiana(xc, yc, xq, getYPonto(pontoMin) - 50) > distanciaEuclidiana(xc, yc, getXPonto(pontoMin) - 50, yq)) {
			yq = getYPonto(pontoMin) - 50;
		} else {
			xq = getXPonto(pontoMin) - 50;
		}
	} else if(xc > xv && yc == yv) { // certo
		xq = getXPonto(pontoMin) - 50;
		yq = yc;
	} else if(xc > xv && yc < yv) {
		xq = (getYPonto(pontoMax) + 50 - b)/a;
		yq = a*(getXPonto(pontoMin) - 50) + b;
		if(distanciaEuclidiana(xc, yc, xq, getYPonto(pontoMax) + 50) > distanciaEuclidiana(xc, yc, getXPonto(pontoMin) - 50, yq)) {
			yq = getYPonto(pontoMax) + 50;
		} else {
			xq = getXPonto(pontoMin) - 50;
		}
	} else if(xc == xv && yc > yv) { // certo
		xq = xc;
		yq = getYPonto(pontoMin) - 50;
	} else if(xc == xv && yc < yv) { // certo
		xq = xc;
		yq = getYPonto(pontoMax) + 50;
	}

	// ver como vou dar free dps
    Vertice vc = criaVertice(criaPonto(xc, yc), xc, yc);
    Vertice vq = criaVertice(criaPonto(xq, yq), xc, yc);

	return criaSegmento(vc, vq);
}

void areaBomba(double x, double y, int capacidade, Lista listaMuros, Lista listaPredios, int *vectSize, FILE *arqSVG){
    Segmento *segmentos = (Segmento *) malloc(capacidade * sizeof(Segmento));
    Ponto pMin = criaPonto(x, y);
    Ponto pMax = criaPonto(x, y);
    int index = 0;

    for(int i = getPrimeiro(listaMuros); i != getNulo (); i = getProximo(listaMuros, i)){
        Muro muro = getElemento(listaMuros, i);
        
        Ponto p1 = criaPonto(getX1Muro(muro), getY1Muro(muro));
        Ponto p2 = criaPonto(getX2Muro(muro), getY2Muro(muro));

        setPontoMin(pMin, getXPonto(p1), getYPonto(p1));
        setPontoMin(pMin, getXPonto(p2), getYPonto(p2));
        setPontoMax(pMax, getXPonto(p1), getYPonto(p1));
        setPontoMax(pMax, getXPonto(p2), getYPonto(p2));

        if(getXPonto(p1) == x && getYPonto(p2) == x || getYPonto(p1) == y && getYPonto(p2) == y)
            continue;

        Vertice v1 = criaVertice (p1, x, y);
        Vertice v2 = criaVertice (p2, x, y);

        Segmento s = criaSegmento(v1, v2);

        setSegmentoStartVertice (s);

        segmentos[index] = s;
        index++;
    }
    
    for(int i = getPrimeiro(listaPredios); i != getNulo (); i = getProximo(listaPredios, i)){
        Predio predio = getElemento(listaPredios, i);
        printf ("%s\n", getCEPPredio (predio));

        Ponto pXY1 = criaPonto(getXPredio(predio), getYPredio(predio));
        Ponto pXY2 = criaPonto(getXPredio(predio), getYPredio(predio));
        Ponto pXWY1 = criaPonto(getXPredio(predio) + getFPredio(predio), getYPredio(predio));
        Ponto pXWY2 = criaPonto(getXPredio(predio) + getFPredio(predio), getYPredio(predio));
        Ponto pXYH1 = criaPonto(getXPredio(predio), getYPredio(predio) + getPPredio(predio));
        Ponto pXYH2 = criaPonto(getXPredio(predio), getYPredio(predio) + getPPredio(predio));
        Ponto pXWYH1 = criaPonto(getXPredio(predio) + getFPredio(predio), getYPredio(predio) + getPPredio(predio));
        Ponto pXWYH2 = criaPonto(getXPredio(predio) + getFPredio(predio), getYPredio(predio) + getPPredio(predio));

        setPontoMin(pMin, getXPonto(pXY1), getYPonto(pXY1));
        setPontoMin(pMin, getXPonto(pXWY1), getYPonto(pXWY1));
        setPontoMin(pMin, getXPonto(pXYH1), getYPonto(pXYH1));
        setPontoMin(pMin, getXPonto(pXWYH1), getYPonto(pXWYH1));
        setPontoMax(pMax, getXPonto(pXY2), getYPonto(pXY2));
        setPontoMax(pMax, getXPonto(pXWY2), getYPonto(pXWY2));
        setPontoMax(pMax, getXPonto(pXYH2), getYPonto(pXYH2));
        setPontoMax(pMax, getXPonto(pXWYH2), getYPonto(pXWYH2));

        Vertice vXY1 = criaVertice (pXY1, x, y);
        Vertice vXY2 = criaVertice (pXY2, x, y);
        Vertice vXWY1 = criaVertice (pXWY1, x, y);
        Vertice vXWY2 = criaVertice (pXWY2, x, y);
        Vertice vXYH1 = criaVertice (pXYH1, x, y);
        Vertice vXYH2 = criaVertice (pXYH2, x, y);
        Vertice vXWYH1 = criaVertice (pXWYH1, x, y);
        Vertice vXWYH2 = criaVertice (pXWYH2, x, y);

        Segmento sC = criaSegmento(vXY1, vXWY1);
        Segmento sD = criaSegmento(vXWY2, vXWYH1);
        Segmento sB = criaSegmento(vXWYH2, vXYH1);
        Segmento sE = criaSegmento(vXYH2, vXY2);

        setSegmentoStartVertice (sC);
        setSegmentoStartVertice (sD);
        setSegmentoStartVertice (sB);
        setSegmentoStartVertice (sE);

        segmentos[index] = sC;
        index++;
        segmentos[index] = sD;
        index++;
        segmentos[index] = sB;
        index++;
        segmentos[index] = sE;
        index++;
    }

    /*Criacao do retangulo que envolve todos os segmentos(borda)*/
   capacidade += 4;

    Ponto pXY1 = criaPonto(getXPonto(pMin) - 100, getYPonto(pMin) - 100);
    Ponto pXY2 = criaPonto(getXPonto(pMin) - 100, getYPonto(pMin) - 100);
    Ponto pXWY1 = criaPonto(getXPonto(pMax) + 100, getYPonto(pMin) - 100);
    Ponto pXWY2 = criaPonto(getXPonto(pMax) + 100, getYPonto(pMin) - 100);
    Ponto pXYH1 = criaPonto(getXPonto(pMin) - 100, getYPonto(pMax) + 100);
    Ponto pXYH2 = criaPonto(getXPonto(pMin) - 100, getYPonto(pMax) + 100);
    Ponto pXWYH1 = criaPonto(getXPonto(pMax) + 100, getYPonto(pMax) + 100);
    Ponto pXWYH2 = criaPonto(getXPonto(pMax) + 100, getYPonto(pMax) + 100);

    Vertice vXY1 = criaVertice (pXY1, x, y);
    Vertice vXY2 = criaVertice (pXY2, x, y);
    Vertice vXWY1 = criaVertice (pXWY1, x, y);
    Vertice vXWY2 = criaVertice (pXWY2, x, y);
    Vertice vXYH1 = criaVertice (pXYH1, x, y);
    Vertice vXYH2 = criaVertice (pXYH2, x, y);
    Vertice vXWYH1 = criaVertice (pXWYH1, x, y);
    Vertice vXWYH2 = criaVertice (pXWYH2, x, y);

    Segmento sC = criaSegmento(vXY1, vXWY1);
    Segmento sE = criaSegmento(vXWY2, vXWYH1);
    Segmento sB = criaSegmento(vXWYH2, vXYH1);
    Segmento sD = criaSegmento(vXYH2, vXY2);

    setSegmentoStartVertice (sC);
    setSegmentoStartVertice (sE);
    setSegmentoStartVertice (sB);
    setSegmentoStartVertice (sD);

    segmentos[index] = sC;
    index++;
    segmentos[index] = sE;
    index++;
    segmentos[index] = sB;
    index++;
    segmentos[index] = sD;
    index++;

    Ponto pBomb1 = criaPonto(x, y);
    Ponto pBomb2 = criaPonto(getXPonto(pMin) - 101, y);
    Vertice vStart = criaVertice (pBomb1, 0, 0);
    Vertice vEnd = criaVertice (pBomb2, 0, 0);
    Segmento segmentoInicial = criaSegmento(vStart, vEnd);
    setSegmentoVertice(vStart, segmentoInicial);
    setSegmentoVertice(vEnd, segmentoInicial);
    setStartVertice(vStart, true);
    setStartVertice(vEnd, false);

    svgprintBomba (x, y, arqSVG);

    int capacidadeSegmentos = index;

    int capacidadeVertices = capacidade * 2;
    index = 0;

    Vertice *vertices = (Vertice *) malloc(capacidadeVertices * sizeof(Vertice));

    for(int i = 0; i < capacidadeSegmentos; i++){
        if(checkInterseccaoSegmentos(segmentoInicial, segmentos[i])){
            capacidadeVertices += 2;
            vertices = (Vertice *) realloc(vertices, capacidadeVertices * sizeof(Vertice));

            double interX, interY;
            interseccaoSegmentos(segmentoInicial, segmentos[i], &interX, &interY);

            Vertice vStart = getStartVertice(getV1Segmento(segmentos[i])) ? getV1Segmento(segmentos[i]) : getV2Segmento(segmentos[i]);
            Vertice vEnd = getStartVertice(getV2Segmento(segmentos[i])) ? getV2Segmento(segmentos[i]) : getV1Segmento(segmentos[i]);

            Ponto pInter = criaPonto(interX, interY);
            Vertice vInterStart = criaVertice (pInter, x, y);
            setStartVertice(vInterStart, true);
            setAnguloVertice(vInterStart, -PI);

            Vertice vInterEnd = criaVertice (pInter, x, y);
            setStartVertice(vInterEnd, false);
            setAnguloVertice(vInterEnd, PI);

            Segmento s1 = criaSegmento(vStart, vInterEnd);
            Segmento s2 = criaSegmento(vInterStart, vEnd);

            setSegmentoVertice(vStart, s1);
            setSegmentoVertice(vInterEnd, s1);
            setSegmentoVertice(vInterStart, s2);
            setSegmentoVertice(vEnd, s2);

            vertices[index] = vStart;
            index++;
            vertices[index] = vInterEnd;
            index++;
            vertices[index] = vInterStart;
            index++;
            vertices[index] = vEnd;
            index++;
        }
        else{
            Vertice v1 = getV1Segmento(segmentos[i]);
            Vertice v2 = getV2Segmento(segmentos[i]);

            setSegmentoVertice(v1, segmentos[i]);
            setSegmentoVertice(v2, segmentos[i]);

            setSegmentoVertice(v1, segmentos[i]);
            setSegmentoVertice(v2, segmentos[i]);

            vertices[index] = v1;
            index++;
            vertices[index] = v2;
            index++;
        }
    }
    int tamanhoVertices = index;

    qsort(vertices, tamanhoVertices, sizeof(Vertice), cmpVertices);

    Lista segmentosAtivos = iniciaLista((int) (tamanhoVertices / 2));
    Vertice biombo = criaVertice (criaPonto(getXPonto(getVVertice(vertices[0])), getYPonto(getVVertice(vertices[0]))), x, y);
    setSegmentoVertice(biombo, getSegmentoVertice(vertices[0]));

    for(int i = 0; i < tamanhoVertices; i++){
        Vertice v = vertices[i];
        Segmento sv = getSegmentoVertice(v);
        Segmento s_v = buscarSegmentoFormadoComVertice(x, y, v, pMin, pMax);
        Segmento segmentoFechado = NULL;

        double dMin = __INT_MAX__;

        for(int j = getPrimeiro(segmentosAtivos); j != getNulo (); j = getProximo(segmentosAtivos, j)){
            Segmento s = getElemento(segmentosAtivos, j);

            if(s == sv) continue;

            if(checkInterseccaoSegmentos(s_v, s)){
                double xInter, yInter;
                interseccaoSegmentos(s_v, s, &xInter, &yInter);

                double distBombInter = distanciaEuclidiana(x, y, xInter, yInter);
                if(distBombInter < dMin){
                    dMin = distBombInter;
                    segmentoFechado = s;
                }
            }
        }

        if(getStartVertice(v)){
            bool ehSegmentoFechado;

            if(distanciaEuclidiana(x, y, getXPonto(getVVertice(v)), getYPonto(getVVertice(v))) < dMin)
                ehSegmentoFechado = true;
            else
                ehSegmentoFechado = false;

            if(ehSegmentoFechado){
                double biomboInterX, biomboInterY;

                interseccaoSegmentos(s_v, getSegmentoVertice(biombo), &biomboInterX, &biomboInterY);
                Vertice vInter = criaVertice (criaPonto(biomboInterX, biomboInterY), x, y);
                Segmento s1 = criaSegmento(biombo, vInter);
                Segmento s2 = criaSegmento(vInter, v);

                svgprintTriangulo (x, y, biombo, vInter, arqSVG);
                biombo = v;
            }     
            inserirElemento(segmentosAtivos, sv);       
        }
        else{
            bool ehSegmentoFechado;

            if(distanciaEuclidiana(x, y, getXPonto(getVVertice(v)), getYPonto(getVVertice(v))) <= dMin)
                ehSegmentoFechado = true;
            else
                ehSegmentoFechado = false;

            if(ehSegmentoFechado){
                if(segmentoFechado != NULL){
                    double biomboInterX, biomboInterY;
                    interseccaoSegmentos(s_v, segmentoFechado, &biomboInterX, &biomboInterY);
                    Vertice vInter = criaVertice (criaPonto(biomboInterX, biomboInterY), x, y);

                    Segmento s1 = criaSegmento(biombo, v);
                    Segmento s2 = criaSegmento(v, vInter);

                    svgprintTriangulo (x, y, v, vInter, arqSVG);
                    svgprintTriangulo (x, y, biombo, v, arqSVG);

                    biombo = vInter;
                    setSegmentoVertice(biombo, segmentoFechado);
                }
                else{
                    Segmento s = criaSegmento(biombo, v);
                    //svgprintTriangulo (x, y, biombo, v, arqSVG);
                    biombo = v;
                }
            }
            excluirElementoMemoria(segmentosAtivos, sv);
        }
    }

    for(int i = 0; i < capacidadeSegmentos; i++){
        Muro m = criaMuro(getXPonto(getVVertice(getV1Segmento((Segmento)segmentos[i]))), getYPonto(getVVertice(getV1Segmento((Segmento)segmentos[i]))), getXPonto(getVVertice(getV2Segmento((Segmento)segmentos[i]))), getYPonto(getVVertice(getV2Segmento((Segmento)segmentos[i]))));
        svgprintMuro(m, arqSVG);
        freeMuro(m);
    }

    for (int i = 0; i < tamanhoVertices; i++){
        Forma circulo;

        if (getStartVertice (vertices[i])){
            circulo = criaForma (" ", 'c', getXPonto (getVVertice (vertices[i])), getYPonto (getVVertice (vertices[i])), 3, 0, 0, "green", "green", "1");
        }
        else {
            circulo = criaForma (" ", 'c', getXPonto (getVVertice (vertices[i])), getYPonto (getVVertice (vertices[i])), 3, 0, 0, "red", "red", "1");
        }

        svgprintcircle (circulo, arqSVG);
        freeForma (circulo);
    }

    for(int i = 0; i < capacidadeSegmentos; i++){
        freeSegmento(segmentos[i]);
    }
    freePonto(pMin);
    freePonto(pMax);
    freeSegmento(segmentoInicial);
    free(segmentos);
    free(vertices);
}