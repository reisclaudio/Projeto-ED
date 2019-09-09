#ifndef ___ARQUIVOS_H
#define ___ARQUIVOS_H
//Contem as funcoes que criam e tratam arquivos

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#include"./Elementos/forma.h"
#include"./Elementos/quadra.h"
#include"./Elementos/hidrante.h"
#include"./Elementos/semaforo.h"
#include"./Elementos/radioBase.h"
#include"./Elementos/predio.h"
#include"./Elementos/muro.h"

/* Funcao que verifica se um arquivo foi realmente aberto */
void verificaArquivo (FILE * arquivo, char * nomeArquivo);
/* Funcao que trata o nome dos arquivos .geo e .qry caso seja passado um diretório realtivo no lugar */
char * tratarNome (char nomearq[], char * nomearq2);

/* Cria o arquivo .svg no diretório de saída (nomegeo.svg) */
char * criaSVG(char nomegeo[], char dirSaida[], char *arqsvg);
/* Funcao que cria o .txt no diretório de saída (nomegeo-nomeqry.txt) */
char * criaTXT (char nomegeo[], char nomeqry [], char dirSaida[], char *arqtxt);
/* Funcao que cria um segundo arquivo svg no diretorio de saida (nomegeo-nomeqry.svg) */
char * criaSVG2 (char nomegeo[], char nomeqry[], char dirSaida[], char *arqsvg2);
/* Funcao que cria um terceiro arquivo svg (BB) no diretório de saída (nomegeo-nomeqry-sufixo.svg) */
char * criaSVG3 (char * nomesvg, char * sufixo);


#endif
