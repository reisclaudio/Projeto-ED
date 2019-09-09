#include"consultas.h"
#include"svgprint.h"
#include"arquivos.h"
#include"lista.h"
#include"utils.h"

typedef struct {
    int id;
    double x, y;
    double largura, altura;
    double raio;
} valores;

void consultaD (char* j, char* k,Lista listaFormas, FILE * nometxt, FILE * nomesvg)
{
    char strtexto[50];
    double dist, xline, yline;
    valores d[2];

    Elemento elemento1 = encontrarElemento (listaFormas, j);
    Elemento elemento2 = encontrarElemento (listaFormas, k);
        
    dist = distCentrosMassa (elemento1, elemento2);
    sprintf(strtexto, "%lf", dist);
    fprintf(nometxt, "%lf\n\n", dist);

    xline = (getXForma (elemento1) + getXForma (elemento2))/2;
    yline = (getYForma (elemento1) + getYForma (elemento2))/2;
      
    fprintf(nomesvg, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"black\" />\n", getXForma (elemento1), getYForma (elemento1), getXForma (elemento2), getYForma (elemento2));
    svgprinttext (strtexto, xline, yline, nomesvg);
}

void consultaO (char* j, char* k, Lista listaFormas, FILE * nometxt, FILE * nomesvg)
{
    double dist, h, w, x, y, xmin, xmax, ymin, ymax;
    double mx, mex, my, mey,mxr, mexr,myr, meyr, wm, hm;
    valores d[2];
    
    Elemento elemento1 = encontrarElemento (listaFormas, j);
    Elemento elemento2 = encontrarElemento (listaFormas, k);
    
    //Verifica se as duas figuras sao circulos, coleta os dados
    //E realiza os calculos da sobreposiçao
    if (getTipo (elemento1) == 'c' && getTipo (elemento2) == 'c'){
        
        //Define o menor e o maior x e y
        if (getXForma (elemento1) > getXForma (elemento2)){
            mx = getXForma (elemento1);
            mxr = getRaioForma (elemento1);
            mex = getXForma (elemento2);
            mexr = getRaioForma (elemento2);
        }
        else {
            mx = getXForma (elemento2);
            mxr = getRaioForma (elemento2);
            mex = getXForma (elemento1);
            mexr = getRaioForma (elemento1);
        }

        if (getYForma (elemento1) > getYForma (elemento2)){
            my = getYForma (elemento1);
            myr = getRaioForma (elemento1);
            mey = getYForma (elemento2);
            meyr = getRaioForma (elemento2);
        }
        else{
            my = getYForma (elemento2);
            myr = getRaioForma (elemento2);
            mey = getYForma (elemento1);
            meyr = getRaioForma (elemento1);
        }

        //Define a largura, altura, x e y do retangulo delimitador
        w = (mx + mxr) - (mex - mexr);
        h = (my + myr) - (mey - meyr);
        x = mex - mexr;
        y = mey - meyr;
        
        if (estaContidoCC (elemento1, elemento2)) { 
            fprintf (nometxt, "SIM\n\n");
            fprintf (nomesvg, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"none\" stroke=\"black\"/>\n",x, y, w, h);
        }
        else{
            fprintf (nometxt,"NAO\n\n");
            fprintf (nomesvg, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"none\" stroke=\"black\" stroke-dasharray=\"5\"/>\n",x, y, w, h);
        }
    }

    //Verifica se as duas figuras sao retangulos, coleta os dados
    //E realiza os calculos da sobreposiçao
    if (getTipo (elemento1) == 'r' && getTipo (elemento2) == 'r'){
                
        //Define o menor e o maior x e y
        if (getXForma (elemento1) > getXForma (elemento2)){
            mx = getXForma (elemento1);
            mex = getXForma (elemento2);
        }
        else {
            mx = getXForma (elemento2);
            mex = getXForma (elemento1);
        }
        
        if (getYForma (elemento1) > getYForma (elemento2)){
            my = getYForma (elemento1);
            mey = getYForma (elemento2);
        }
        else {
            my = getYForma (elemento2);
            mey = getYForma (elemento1);
        }

        if (getWForma (elemento1) > getWForma (elemento2))
            wm = getWForma (elemento1);
        else
            wm = getWForma (elemento2);

        if (getHForma (elemento1) > getHForma (elemento2))
            hm = getHForma (elemento1);
        else
            hm = getHForma (elemento2);

        //Define a largura, altura, x e y do retangulo delimitador
        w = mx + wm - mex;
        h = my + hm - mey;
        x = mex;
        y = mey;

        if (estaContidoRR (elemento1, elemento2)){
            fprintf (nometxt, "SIM\n\n");
            fprintf (nomesvg, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"none\" stroke=\"black\"/>\n",x,y, w, h);
        }
        else{
            fprintf (nometxt, "NAO\n\n");
            fprintf (nomesvg, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"none\" stroke=\"black\" stroke-dasharray=\"5\"/>\n",x,y, w, h);
        }
    }

    //Verifica se uma delas é circulo e a outa é retangulo, coleta os dados
    //E realiza os calculos da sobreposicao
    if ((getTipo (elemento1) =='c' && getTipo (elemento2) == 'r') || (getTipo (elemento1) == 'r' && getTipo (elemento2) == 'c')){

        //Define x e y maximo e x e y minimo
        if ((d[0].x - d[0].raio) < d[1].x) xmin = d[0].x - d[0].raio;
        else xmin = d[1].x;

        if ((d[0].x + d[0].raio) > (d[1].x + d[1].largura)) xmax = d[0].x + d[0].raio;
        else xmax = d[1].x + d[1].largura;

        if ((d[0].y - d[0].raio) < d[1].y) ymin = d[0].y - d[0].raio;
        else ymin = d[1].y;

        if ((d[0].y + d[0].raio) > (d[1].y + d[1].altura)) ymax = d[0].y + d[0].raio;
        else ymax = d[1].y + d[1].altura;

        //Define a largura e altura do retangulo delimitador                
        w = xmax - xmin;
        h = ymax - ymin;

        //Define o x mais proximo e y mais proximo
        double xmp = clamp (d[0].x, d[1].x, d[1].x + d[1].largura);
        double ymp = clamp (d[0].y, d[1].y, d[1].y + d[1].altura);

        if (estaContidoCR (elemento1, elemento2)){
            fprintf (nometxt, "SIM\n\n");
            fprintf (nomesvg, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"none\" stroke=\"black\"/>\n",xmin,ymin, w, h);
        }
        else {
            fprintf (nometxt, "NAO\n\n");
            fprintf (nomesvg, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"none\" stroke=\"black\" stroke-dasharray=\"5\"/>\n",xmin,ymin, w, h);
        }
    }
}

void consultaI (char* j, double x, double y, Lista listaFormas, FILE * nometxt, FILE * nomesvg)
{
    double dist;
    valores d;
    
    Elemento elemento = encontrarElemento (listaFormas, j);

    d.x = getXForma(elemento) + (getWForma (elemento)/2.0);
    d.y = getYForma (elemento) + (getHForma (elemento)/2.0);

    //Verifica se a figura é um circulo, coleta os dados
    //E realiza os calculos do inside/not inside

    if (pontoEstaContido (x, y, elemento)) {
        fprintf (nometxt, "INTERNO\n\n");
        fprintf (nomesvg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"2\" fill=\"green\" stroke=\"green\" />\n", x, y);
        fprintf(nomesvg, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"green\" />\n", x, y, getXForma (elemento), getYForma (elemento));
    }
    else{
        fprintf (nometxt, "NAO INTERNO\n\n");
        fprintf (nomesvg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"2\" fill=\"red\" stroke=\"red\" />\n", x, y);
        fprintf(nomesvg, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"red\" />\n", x, y, getXForma (elemento), getYForma (elemento));
    }
}

void consultaBB (char * sufixo, char * cor, char * nomesvg, Lista listaFormas, FILE * nomegeo)
{   
    char * arqsvg3;
    FILE * arqBB;
    arqsvg3 = criaSVG3 (nomesvg, sufixo);
    
    arqBB = fopen (arqsvg3, "w+");
    verificaArquivo (arqBB, arqsvg3);
    fprintf (arqBB, "<svg>\n");

    imprimeListaSVG (listaFormas, arqBB);
    for (int i = 0; i < getTamAtual (listaFormas); i++){
        Elemento forma = getElemento (listaFormas, i);
        if (getTipo (forma) == 'c'){
            double hr = 2*getRaioForma (forma);
			double wr = 2*getRaioForma (forma);
			double xr = getXForma (forma) - getRaioForma (forma);
			double yr = getYForma (forma) - getRaioForma (forma);

			Forma retangulo = criaForma ("0", 'r', xr, yr, 0, wr, hr, cor, "none", "1");
			svgprintrect (retangulo, arqBB);
        }
        else {
            double cx = getXForma (forma) + getWForma (forma)/2.0;
			double cy = getYForma (forma) + getHForma (forma)/2.0;
			double ry = getHForma (forma)/2;
			double rx = getWForma (forma)/2;

			svgprintellipse(cx, cy, rx, ry, cor, arqBB);
        }
    }
    fprintf (arqBB, "</svg>\n");
}

bool consultaCRD (char *j, Lista listaQuadras, Lista listaHidrantes, Lista listaSemaforos, Lista listaRadiosBase, FILE *nometxt)
{
    char tipo;
    Elemento elemento = encontrarElementoListas (j, listaQuadras, listaHidrantes, listaSemaforos, listaRadiosBase);

    if (elemento != NULL){
        tipo = getTipo (elemento);

        if (tipo == 'q')
            fprintf (nometxt, "Quadra x = %lf y = %lf w = %lf h = %lf\n\n", getXQuadra (elemento), getYQuadra (elemento), getWQuadra (elemento), getHQuadra (elemento));
        else if (tipo == 'h')
            fprintf (nometxt, "Hidrante x = %lf y = %lf\n\n", getXHid (elemento), getYHid (elemento));
        else if (tipo == 's')
            fprintf (nometxt, "Semaforo x = %lf y = %lf\n\n", getXSema (elemento), getYSema(elemento));
        else if (tipo == 'b')
            fprintf (nometxt, "Radio base x = %lf y = %lf\n\n", getXRB (elemento), getYRB(elemento));
    }
    else {
        fprintf (nometxt, "Elemento nao encontrado!\n\n");
    }
}

bool consultaDEL (char *j, Lista listaQuadras, Lista listaHidrantes, Lista listaSemaforos, Lista listaRadiosBase, FILE *nometxt)
{
    Elemento elemento = encontrarElementoListas (j, listaQuadras, listaHidrantes, listaSemaforos, listaRadiosBase);

    char tipo = getTipo (elemento);

    if (tipo == 'q'){
        fprintf (nometxt, "Quadra x = %lf y = %lf w = %lf h = %lf\n\n", getXQuadra (elemento), getYQuadra (elemento), getWQuadra (elemento), getHQuadra (elemento));
        excluirElemento (listaQuadras, j);
    }
    else if (tipo == 'h'){
        fprintf (nometxt, "Hidrante x = %lf y = %lf\n\n", getXHid (elemento), getYHid (elemento));
        excluirElemento (listaHidrantes, j);
    }
    else if (tipo == 's') {
        fprintf (nometxt, "Semaforo x = %lf y = %lf\n\n", getXSema (elemento), getYSema(elemento));
        excluirElemento (listaSemaforos, j);
    }
    else if (tipo == 'b'){
        fprintf (nometxt, "Radio base x = %lf y = %lf\n\n", getXRB (elemento), getYRB(elemento));
        excluirElemento (listaRadiosBase, j);
    }
}

void consultaCBQ (double x, double y, double r, char* cstrk, Lista listaQuadras, FILE *nometxt)
{
    Elemento quadra;
    char cep[20];

    int contador = 0, i;
    fprintf (nometxt, "Quadras com bordas alteradas: ");

    for (i = 0; i < getTamAtual (listaQuadras);i++){
        quadra = getElemento (listaQuadras, i);

        if (distanciaEuclidiana (x, y, getXQuadra (quadra), getYQuadra (quadra)) <= r) 
            contador++;        
        if (distanciaEuclidiana (x, y, getXQuadra (quadra) + getWQuadra (quadra), getYQuadra (quadra)) <= r) 
            contador++;        
        if (distanciaEuclidiana (x, y, getXQuadra (quadra), getYQuadra (quadra) + getHQuadra (quadra)) <= r) 
            contador++;        
        if (distanciaEuclidiana (x, y, getXQuadra (quadra) + getWQuadra (quadra), getYQuadra (quadra) + getHQuadra (quadra)) <= r) 
            contador++;

        if (contador == 4){
            fprintf (nometxt, "%s ", getCEPQuadra (quadra));
            setCor2Quadra (quadra, cstrk);
        }
        contador = 0;     
    }
    fprintf (nometxt, "\n\n");
}

void consultaTRNS (double x, double y, double w, double h, double dx, double dy, Lista listaQuadras,Lista listaHidrantes, Lista listaSemaforos, Lista listaRadiosBase, FILE*nometxt)
{
    Elemento elemento;
    Elemento newElemento;
    char cep[20], id[20];
    int contador = 0, i=0;

    for (i = 0; i < getTamAtual (listaQuadras); i++){
        elemento = getElemento (listaQuadras, i);

        if (getXQuadra (elemento) > x && getXQuadra (elemento) < x + w && getYQuadra (elemento) > y && getYQuadra (elemento) < y + h) 
            contador++;
        if (getXQuadra (elemento) + getWQuadra (elemento) > x && getXQuadra (elemento) + getWQuadra (elemento) < x + w && getYQuadra (elemento) > y && getYQuadra (elemento) < y + h) 
            contador++;
        if (getXQuadra (elemento) > x && getXQuadra (elemento) < x + w && getYQuadra (elemento) + getHQuadra (elemento) > y && getYQuadra (elemento) + getHQuadra (elemento) < y + h) 
            contador++;
        if (getXQuadra (elemento) + getWQuadra (elemento) > x && getXQuadra (elemento) + getWQuadra (elemento) < x + w && getYQuadra (elemento) + getHQuadra (elemento) > y && getYQuadra (elemento) + getHQuadra (elemento) < y + h) 
            contador++;

        if (contador == 4){
            fprintf (nometxt, "%s: \n Posicao anterior: (%lf, %lf) \n Posicao atualizada: (%lf, %lf)\n", getCEPQuadra (elemento), getXQuadra (elemento), getYQuadra (elemento), getXQuadra (elemento) + dx, getYQuadra (elemento) + dy);

            setXQuadra (elemento, getXQuadra (elemento) + dx);
            setYQuadra (elemento, getYQuadra (elemento) + dy);
        }
        contador = 0;
    }

    for (i = 0; i<getTamAtual (listaHidrantes); i++){
        elemento = getElemento (listaHidrantes, i);

        if (getXHid (elemento) > x && getXHid (elemento) < x + w && getYHid (elemento) > y && getYHid (elemento) < y + h){
            fprintf (nometxt, "%s: \n Posicao anterior: (%lf, %lf) \n Posicao atualizada: (%lf, %lf)\n", getIDHid (elemento), getXHid (elemento), getYHid (elemento), getXHid (elemento) + dx, getYHid (elemento) + dy);

            setXHid (elemento, getXHid (elemento) + dx);
            setYHid (elemento, getYHid (elemento) + dy);
        }
    }

    for (i = 0; i<getTamAtual (listaSemaforos); i++){
        elemento = getElemento (listaSemaforos, i);

        if (getXSema (elemento) > x && getXSema (elemento) < x + w && getYSema (elemento) > y && getYSema (elemento) < y + h){
            fprintf (nometxt, "%s: \n Posicao anterior: (%lf, %lf) \n Posicao atualizada: (%lf, %lf)\n", getIDSema (elemento), getXSema (elemento), getYSema (elemento), getXSema (elemento) + dx, getYSema (elemento) + dy);

            setXSema (elemento, getXSema (elemento) + dx);
            setYSema (elemento, getYSema (elemento) + dy);
        }
    }

    for (i = 0; i<getTamAtual (listaRadiosBase); i++){
        elemento = getElemento (listaRadiosBase, i);

        if (getXRB (elemento) > x && getXRB (elemento) < x + w && getYRB (elemento) > y && getYRB (elemento) < y + h){
            fprintf (nometxt, "%s: \n Posicao anterior: (%lf, %lf) \n Posicao atualizada: (%lf, %lf)\n", getIDRB (elemento), getXRB (elemento), getYRB (elemento), getXRB (elemento) + dx, getYRB (elemento) + dy);

            setXRB (elemento, getXRB (elemento) + dx);
            setYRB (elemento, getYRB (elemento) + dy);
        }
    }
    fprintf (nometxt, "\n\n");
}

void consultaDQ (char* id, char* metrica, double dist, Lista listaQuadras, Lista listaHidrantes, Lista listaSemaforos, Lista listaRadiosBase, FILE* nometxt, FILE* nomesvg)
{
    char cep [20];
    Elemento elemento = encontrarElementoListas (id, listaQuadras, listaHidrantes, listaSemaforos, listaRadiosBase);
    Elemento quadra;

    svgprintDoubleCircle (elemento, nomesvg);
    int tamanhoLista = getTamAtual (listaQuadras);
    fprintf (nometxt, "Equipamento Urbano: %s x = %lf y = %lf\nQuadras removidas: ", getIDHid (elemento), getXHid (elemento), getYHid (elemento));

    //L1: Manhattan Distance
    if (strcmp (metrica, "L1") == 0){
        int contador = 0;
        for (int i = 0; i < tamanhoLista; i++){
            quadra = getElemento (listaQuadras, i);

            if (manhattanDistance (getXHid (elemento), getYHid (elemento), getXQuadra (quadra), getYQuadra (quadra)) <= dist)
                contador++;
            if (manhattanDistance (getXHid (elemento), getYHid (elemento), getXQuadra (quadra) + getWQuadra (quadra), getYQuadra (quadra)) <= dist)
                contador++;
            if (manhattanDistance (getXHid (elemento), getYHid (elemento), getXQuadra (quadra), getYQuadra (quadra) + getHQuadra (quadra)) <= dist)
                contador++;
            if (manhattanDistance (getXHid (elemento), getYHid (elemento), getXQuadra (quadra) + getWQuadra (quadra), getYQuadra (quadra) + getHQuadra (quadra)) <= dist)
                contador++;

            if (contador == 4){
                fprintf (nometxt, "%s ", getCEPQuadra (quadra));
                excluirElemento (listaQuadras, getCEPQuadra (quadra));
            }
            contador = 0;
        }
    }

    //L2: Euclidian Distance
    else if (strcmp (metrica, "L2") == 0){
        int contador = 0;
        for (int i = 0; i < tamanhoLista; i++){
            quadra = getElemento (listaQuadras, i);

            if (distanciaEuclidiana (getXHid (elemento), getYHid (elemento), getXQuadra (quadra), getYQuadra (quadra)) <= dist) 
                contador++;        
            if (distanciaEuclidiana (getXHid (elemento), getYHid (elemento), getXQuadra (quadra) + getWQuadra (quadra), getYQuadra (quadra)) <= dist) 
                contador++;        
            if (distanciaEuclidiana (getXHid (elemento), getYHid (elemento), getXQuadra (quadra), getYQuadra (quadra) + getHQuadra (quadra)) <= dist) 
                contador++;        
            if (distanciaEuclidiana (getXHid (elemento), getYHid (elemento), getXQuadra (quadra) + getWQuadra (quadra), getYQuadra (quadra) + getHQuadra (quadra)) <= dist) 
                contador++;
            
            if (contador == 4){
                fprintf (nometxt, "%s ", getCEPQuadra (quadra));
                excluirElemento (listaQuadras, getCEPQuadra (quadra));
            }
            contador = 0;
        }
    }
    fprintf (nometxt, "\n\n");
}

typedef struct stDist{
    Elemento *elemento;
    double dist;
} *DistImp;

double getDist(Dist distAux){
    DistImp dist = (DistImp) distAux;

    return dist->dist;
}

Elemento getCep (Dist distAux){
    DistImp dist = (DistImp) distAux;

    return dist->elemento;
}


void consultaFI (double x, double y, int ns, double r, Lista listaHidrantes, Lista listaSemaforos, Lista listaExtra,  FILE * arqSVG, FILE * arqTXT)
{
    double dist;
    Forma foco = criaForma (" ", 'c', x, y, 20, 0, 0, "orange", "red", "5");
    inserirElemento (listaExtra, foco);

    DistImp *distSemaforos = (DistImp *) malloc(getTamAtual (listaSemaforos) * sizeof(DistImp));

    int cont = 0;

    for (int i = getPrimeiro (listaSemaforos); i != getNulo (); i = getProximo (listaSemaforos, i)){        
        Elemento semaforo = getElemento (listaSemaforos, i);    

        distSemaforos[cont] = malloc(sizeof(struct stDist));
        distSemaforos[cont]->elemento = semaforo;
        distSemaforos[cont]->dist = distanciaEuclidiana (x, y, getXSema (semaforo), getYSema (semaforo));
        cont++;
    }

    min_heap_sort((void *) distSemaforos, getTamAtual (listaSemaforos) - 1, ns);
    inverterVetor ((void *) distSemaforos, getTamAtual (listaSemaforos));

    fprintf (arqTXT, "-ns Semaforos alterados:\n");
    for (int i = 0; i < ns; i++){
        fprintf (arqTXT, "%d - %s\n", i + 1, getIDSema(((Semaforo) distSemaforos[i]->elemento)));   
        Forma circulo = criaForma (" ", 'x', getXSema (((Semaforo) distSemaforos[i]->elemento)), getYSema (((Semaforo) distSemaforos[i]->elemento)) , 11, x, y, "orange", "none", "6");
        inserirElemento (listaExtra, circulo);
    }

    fprintf (arqTXT, "-Hidrantes ativados:\n");
    int j = 1;
    
    for (int i = getPrimeiro (listaHidrantes); i != getNulo (); i = getProximo (listaHidrantes, i)){        
        Elemento hidrante = getElemento (listaHidrantes, i);
        
        if ((distanciaEuclidiana (getXHid (hidrante), getYHid (hidrante), x, y)) <= r){
            fprintf (arqTXT, "%d - %s\n", j, getIDHid(hidrante));
            Forma circulo = criaForma (" ", 'x', getXHid (hidrante) + 5, getYHid (hidrante) + 5 , 11, x, y, "orange", "none", "6");
            inserirElemento (listaExtra, circulo);
            j++;
        }
    }
    fprintf (arqTXT, "\n");

    for (int i = 0; i < getTamAtual (listaSemaforos); i++){
        free (distSemaforos[i]);
    }
    free (distSemaforos);
    printf ("%d\n", getTamAtual (listaSemaforos));
}

void consultaFS (int k, char* cep, char face, double num, Lista listaQuadras, Lista listaSemaforos, Lista listaExtra, FILE * arqSVG, FILE * arqTXT)
{
    double x, y;
    Quadra quadra = encontrarElemento (listaQuadras, cep);

    if ((face == 'N') || (face == 'n')){  
        x = getXQuadra (quadra) + num;
        y = getYQuadra (quadra) + getHQuadra (quadra);
    }
    else if ((face == 'S') || (face == 's')){
        x = getXQuadra (quadra) + num;
        y = getYQuadra (quadra);
    }
    else if ((face == 'L') || (face == 'l')){
        x = getXQuadra (quadra);
        y = getYQuadra (quadra) + num;
    }
    else if ((face == 'O') || (face == 'o')){
        x = getXQuadra (quadra) + getWQuadra (quadra);
        y = getYQuadra (quadra) + num;
    }

    Forma ponto = criaForma (" ", 'c', x, y, 20, 0, 0, "green", "blue", "5");
    inserirElemento (listaExtra, ponto);

    DistImp *distSemaforos = (DistImp *) malloc(getTamAtual (listaSemaforos) * sizeof(DistImp));
    int cont = 0;

    for (int i = getPrimeiro (listaSemaforos); i != getNulo (); i = getProximo (listaSemaforos, i)){     
        Semaforo semaforo = getElemento (listaSemaforos, i);
        DistImp s = malloc(sizeof(struct stDist));
        s->elemento = semaforo;
        s->dist = distanciaEuclidiana (x, y, getXSema (semaforo), getYSema (semaforo));
        distSemaforos[cont] = s;
        cont++;
    }

    min_heap_sort((void *) distSemaforos, getTamAtual (listaSemaforos) - 1, k);
    inverterVetor ((void *) distSemaforos, getTamAtual (listaSemaforos));

    fprintf (arqTXT, "-k Semaforos mais proximos:\n");
    for (int i = 0; i < k; i++){
        fprintf (arqTXT, "%d - %s\n", i + 1, getIDSema(((Semaforo) distSemaforos[i]->elemento)));   
        Forma circulo = criaForma (" ", 'x', getXSema (((Semaforo) distSemaforos[i]->elemento)), getYSema (((Semaforo) distSemaforos[i]->elemento)) , 11, x, y, "green", "none", "6");
        inserirElemento (listaExtra, circulo);
    }
    fprintf (arqTXT, "\n");

    for (int i = 0; i < getTamAtual (listaSemaforos); i++){
        free (distSemaforos[i]);
    }
    free (distSemaforos);
}

void consultaFH (int k, char* cep, char face, double num, Lista listaQuadras, Lista listaHidrantes, Lista listaExtra, FILE * arqSVG, FILE * arqTXT)
{
    double x, y;
    Quadra quadra = encontrarElemento (listaQuadras, cep);

    if ((face == 'N') || (face == 'n')){  
        x = getXQuadra (quadra) + num;
        y = getYQuadra (quadra) + getHQuadra (quadra);
    }
    else if ((face == 'S') || (face == 's')){
        x = getXQuadra (quadra) + num;
        y = getYQuadra (quadra);
    }
    else if ((face == 'L') || (face == 'l')){
        x = getXQuadra (quadra);
        y = getYQuadra (quadra) + num;
    }
    else if ((face == 'O') || (face == 'o')){
        x = getXQuadra (quadra) + getWQuadra (quadra);
        y = getYQuadra (quadra) + num;
    }

    Forma ponto = criaForma (" ", 'c', x, y, 20, 0, 0, "pink", "yellow", "5");
    inserirElemento (listaExtra, ponto);

    DistImp *distHidrantes = (DistImp *) malloc(getTamAtual (listaHidrantes) * sizeof(DistImp));
    int cont = 0;

    for (int i = getPrimeiro (listaHidrantes); i != getNulo (); i = getProximo (listaHidrantes, i)){     
        Hidrante hidrante = getElemento (listaHidrantes, i);

        distHidrantes[cont] = malloc(sizeof(struct stDist));
        distHidrantes[cont]->elemento = hidrante;
        distHidrantes[cont]->dist = distanciaEuclidiana (x, y, getXHid (hidrante), getYSema (hidrante));
        cont++;
    }

    if (k < 0){
        k = k * -1;
        min_heap_sort((void *) distHidrantes, getTamAtual (listaHidrantes) - 1, k);
        fprintf (arqTXT, "-k Hidrantes mais proximos: \n");
    }
    else if (k > 0){
        max_heap_sort((void *) distHidrantes, getTamAtual (listaHidrantes) - 1, getTamAtual (listaHidrantes) - 1);
        fprintf (arqTXT, "-k Hidrantes mais distantes: \n"); 
    }

    inverterVetor ((void *) distHidrantes, getTamAtual (listaHidrantes));
    for (int i = 0; i < k; i++){
        fprintf (arqTXT, "%d - %s\n", i + 1, getIDHid(((Hidrante) distHidrantes[i]->elemento)));   
        Forma circulo = criaForma (" ", 'x', getXHid (((Semaforo) distHidrantes[i]->elemento)) + 5, getYHid (((Semaforo) distHidrantes[i]->elemento)) + 5, 11, x, y, "pink", "none", "6");
        inserirElemento (listaExtra, circulo);
    }
    fprintf (arqTXT, "\n");

    for (int i = 0; i < getTamAtual (listaHidrantes); i++){
        free (distHidrantes[i]);
    }
    free (distHidrantes);

}


    

