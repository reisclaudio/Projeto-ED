#include "lista.h"
#include "leitura.h"

#define LIVRE -2
#define NULO -1

struct StElemento {
    Elemento elemento;
    int ant, prox;
    char tipo;
};

typedef struct StElemento ElementoLista;

struct StLista {
    ElementoLista *v;
    int inicio, fim;
    int livre, tamMax, tamAtual;
};

typedef struct StLista *ListaImp;

Lista iniciaLista (int tamMax) 
{
    ListaImp aux;
    aux = (ListaImp) malloc (sizeof (struct StLista));

    aux->v = (ElementoLista*) malloc (tamMax * sizeof (ElementoLista));
    aux->tamMax = tamMax;

    for (int i = 0; i< tamMax-1; i++){
        aux->v[i].prox = i+1;
    }

    aux->v[tamMax-1].prox = NULO;
    aux->inicio = NULO;
    aux->fim = NULO;
    aux->livre = 0;
    aux->tamAtual = 0;

    return aux;
}

int getTamMax (Lista lista)
{
    ListaImp aux;
    aux = (ListaImp) lista;

    return aux->tamMax;
}

int getTamAtual (Lista lista)
{
    ListaImp aux;
    aux = (ListaImp) lista;

    return aux->tamAtual;
}

int getLivre (Lista lista)
{
    ListaImp aux = (ListaImp) lista;
    int iLivre = aux->livre;
    aux->livre = aux->v[aux->livre].prox;

    return iLivre;
}

void inserirElemento (Lista lista, Elemento elemento){
    ListaImp aux = (ListaImp) lista;
    int iLivre = getLivre (lista);

    if (aux->tamAtual <= aux->tamMax){
        if (aux->inicio == NULO){
            aux->v[iLivre].elemento = elemento;
            aux->v[iLivre].prox = NULO;
            aux->v[iLivre].ant = NULO;
            aux->inicio = 0;
            aux->fim = 0;
            aux->tamAtual++;
        }
        else {
            aux->v[aux->fim].prox = iLivre;
            aux->v[iLivre].elemento = elemento;
            aux->v[iLivre].prox = NULO;
            aux->v[iLivre].ant = aux->fim;
            aux->fim = iLivre;
            aux->tamAtual++;
        }
    }
}

void inserirAntes (Lista lista, Elemento elemento, int posic)
{
    ListaImp aux = (ListaImp) lista;
    int iLivre = getLivre (lista);

    if (iLivre == NULO){
        printf ("Impossivel inserir, lista cheia\n");
        return;
    }

    if (aux->tamAtual <= aux->tamMax){
        aux->v[iLivre].prox = posic;
        aux->v[iLivre].ant = aux->v[posic].ant;
        aux->v[iLivre].elemento = elemento;
        aux->v[aux->v[posic].ant].prox = iLivre;
        aux->v[posic].ant = iLivre;
        aux->tamAtual++;
        return;
    }
    return;
}

void inserirDepois (Lista lista, Elemento elemento, int posic)
{
    ListaImp aux = (ListaImp) lista;
    int iLivre = getLivre (lista);

    if (iLivre == NULO){
        printf ("Impossivel inserir, lista cheia\n");
        return;
    }

    if (aux->tamAtual <= aux->tamMax){
        aux->v[iLivre].prox = posic;
        aux->v[iLivre].ant = aux->v[posic].ant;
        aux->v[iLivre].elemento = elemento;
        aux->v[aux->v[posic].prox].ant = iLivre;
        aux->v[posic].prox = iLivre;
        aux->tamAtual++;
        return;
    }
    return;
}

void excluirElemento (Lista lista, char* id)
{
    int index;
    ListaImp aux = (ListaImp) lista;
    
    for (int i = aux->inicio; i != NULO ; i = aux->v[i].prox){
        if (strcmp (aux->v[i].elemento, id) == 0) {
            index =  i;
        }
    }

    if (index == aux->inicio){
        aux->inicio = aux->v[index].prox;
    }
    else if (aux->v[index].prox == NULO){
        aux->v[aux->v[index].ant].prox = NULO;
        aux->fim = aux->v[index].ant;
    }
    else {
        aux->v[aux->v[index].ant].prox = aux->v[index].prox;
        aux->v[aux->v[index].prox].ant = aux->v[index].ant;
    }
    aux->v[index].prox = aux->livre;
    aux->livre = index;
    aux->tamAtual--;
    free (aux->v[index].elemento);
}

bool excluirElementoMemoria(Lista lista, Elemento elemento) {
    ListaImp l = (ListaImp) lista;
    for(int i = l->inicio; i != -1; i = l->v[i].prox) {
        if(l->v[i].elemento== elemento) {
            if(i == l->inicio) {
                l->inicio = l->v[i].prox;
                if(l->v[i].prox == -1) {
                    l->v[l->v[i].ant].prox = -1;
                    l->fim = l->v[i].ant;
                }
            } else if(l->v[i].prox == -1) {
                l->v[l->v[i].ant].prox = -1;
                l->fim = l->v[i].ant;
            } else {
                l->v[l->v[i].ant].prox = l->v[i].prox;
                l->v[l->v[i].prox].ant = l->v[i].ant;
            }
            l->tamAtual--;
            l->v[i].prox = l->livre;
            l->livre = i;
            return true;
        }
    }
    return false;
}

Elemento getElemento (Lista lista, int i)
{
    ListaImp aux = (ListaImp) lista;

    return aux->v[i].elemento;
}

Elemento encontrarElemento (Lista lista, char* id)
{
    ListaImp aux = (ListaImp) lista;
    for (int i = aux->inicio; i != NULO ; i = aux->v[i].prox){
        if (strcmp (aux->v[i].elemento, id) == 0) {
            return aux->v[i].elemento;
        }
    }
    return NULL;
}

Elemento encontrarElementoListas (char* id, Lista lquadras, Lista lhidrantes, Lista Lsemaforos, Lista lrb)
{
    Elemento elemento;
    elemento = encontrarElemento (lquadras, id);
    if (elemento == NULL) elemento = encontrarElemento (lhidrantes, id);
    else return elemento;
    if (elemento == NULL) elemento = encontrarElemento (Lsemaforos, id);
    else return elemento;
    if (elemento == NULL) elemento = encontrarElemento (lrb, id);
    else return elemento;
    return elemento;    
}

int getPrimeiro (Lista lista)
{
    ListaImp aux = (ListaImp) lista;

    if(!aux->tamAtual) return NULO;

    return aux->inicio;
}

int getProximo (Lista lista, int posic)
{   
    ListaImp aux = (ListaImp) lista;

    return aux->v[posic].prox;
}

int getUltimo (Lista lista)
{
    ListaImp aux = (ListaImp) lista;
    
    return aux->tamAtual;
}

int getAnterior (Lista lista, int posic)
{
    ListaImp aux = (ListaImp) lista;

    if (posic == aux->inicio) return NULO;
    return aux->v[posic].ant;
}

void imprimeListaSVG (Lista lista, FILE* arqSVG)
{
    ListaImp aux;
    aux = (ListaImp) lista;

    for (int i = aux->inicio; i != NULO; i = aux->v[i].prox){        
        if (getTipo (aux->v[i].elemento) == 'q') svgprintQuadra (aux->v[i].elemento, arqSVG);
        else if (getTipo (aux->v[i].elemento) == 'h') svgprintHidrante (aux->v[i].elemento, arqSVG);
        else if (getTipo (aux->v[i].elemento) == 's') svgprintSemaforo (aux->v[i].elemento, arqSVG);
        else if (getTipo (aux->v[i].elemento) == 'b') svgprintRadioBase (aux->v[i].elemento, arqSVG);
        else if (getTipo (aux->v[i].elemento) == 'c') svgprintcircle (aux->v[i].elemento, arqSVG);
        else if (getTipo (aux->v[i].elemento) == 'r') svgprintrect (aux->v[i].elemento, arqSVG);
        else if (getTipo (aux->v[i].elemento) == 'p') svgprintPredio (aux->v[i].elemento, arqSVG);
        else if (getTipo (aux->v[i].elemento) == 'm') svgprintMuro (aux->v[i].elemento, arqSVG);
        else if (getTipo (aux->v[i].elemento) == 'x') svgprintCircleLine (aux->v[i].elemento, arqSVG);
    }
}

void desalocarLista (Lista lista, void (*freeElemento)(Elemento elemento)){
    ListaImp aux = (ListaImp) lista;

    if (aux->inicio == NULO){
        free (aux->v);
        free (aux);
        return;
    }

    int i = aux->inicio;
    while (1){
        if (aux->v[i].prox == NULO){
            freeElemento (aux->v[i].elemento);
            free (aux->v);
            free (aux);
            break;
        }
        else {
            i = aux->v[i].prox;
            freeElemento (aux->v[aux->v[i].ant].elemento);
        }
    }
}

int getNulo()
{

    return NULO;
}




