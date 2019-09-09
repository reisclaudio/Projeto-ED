#ifndef _LISTA_H
#define _LISTA_H
//Contem as funcoes que fazem a lista duplamente encadeada estatica

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"svgprint.h"

//TAD LISTA
typedef void *Elemento;
typedef void *Lista;

/* Funcao que inicia a lista com sua capacidade maxima */
Lista iniciaLista (int capac);
/* Funcao que retorna o tamanho maximo da lista */
int getTamMax (Lista lista);
/* Funcao que retorna o tamanho atual da lista */
int getTamAtual (Lista lista);
/* Funcao que acha a proxima posicao livre na lista */
int getLivre (Lista lista);
/* Funcao que insere um elemento na lista na proxima posicao livre */
void inserirElemento (Lista lista, Elemento elemento);
/* Funcao que insere um elemento na posicao anterior de posic */
void inserirAntes (Lista lista, Elemento elemento, int posic);
/* Funcao que insere um elemento na proxima posicao de posic */
void inserirDepois (Lista lista, Elemento elemento, int posic);
/* Funcao que exclue o elemento da lista com o id/cep passado */
void excluirElemento (Lista lista, char* id);
/* Funcao que retorna o elemento da posicao i da lista */
Elemento getElemento (Lista lista, int i);
/* Funcao que retorna o elemento da lista com o id/cep passado */
Elemento encontrarElemento (Lista lista, char* id);
/* Funcao que percorre todas as listas procurando o elemento com o id passado */
Elemento encontrarElementoListas (char* id, Lista lquadras, Lista lhidrantes, Lista Lsemaforos, Lista lrb);
/* Funcao que retorna o indicador do primeiro elemento da lista */
int getPrimeiro (Lista lista);
/* Funcao que retorna o indicador do elemento seguinte ao indicado por posic */
int getProximo (Lista lista, int posic);
/* Funcao que retorna o indicador do ultimo elemento da lista */
int getUltimo (Lista lista);
/* FUncao que retorna o indicador do elemento anterior ao indicado por posic */
int getAnterior (Lista lista, int posic);
/* Funcao que imprime a lista em um arquivo svg */
void imprimeListaSVG (Lista lista, FILE* arqSVG);
/* Funcao que desaloca a lista */
void desalocarLista (Lista lista, void (*destruirElemento)(Elemento elemento));
/* Funcao que retorna -1 (NULO) */
int getNulo();


#endif
