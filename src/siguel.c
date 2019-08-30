#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"leitura.h"
#include"arquivos.h"

int main (int argc, char *argv[]){
	int i = 1;
	char *nomegeo = NULL;
	char *nomeqry = NULL;
	char *nomegeoN = NULL;
	char *nomeqryN = NULL;
	char *nomesvg = NULL;
	char *nometxt = NULL;
	char *nomesvg2 = NULL;
	char *dirEntrada = NULL;
	char *dirSaida = NULL;
	char *arqgeo = NULL;
	char *arqqry = NULL;
	char *arqsvg = NULL;
	char *arqtxt = NULL;
	char *arqsvg2 = NULL;
	
	FILE * geo;
	FILE * qry;

	//Leitura dos parametros do argv
	while (i < argc){
		if (strcmp("-f", argv[i]) == 0){	
			i++;
			nomegeo = (char*) malloc ((strlen (argv[i]) + 1)*sizeof(char));
			strcpy(nomegeo, argv[i]);
			nomegeoN = tratarNome(nomegeo, nomegeoN); //Nome do arquivo .geo tratado
		}
		else if (strcmp ("-e", argv[i])==0){
			i++;
			dirEntrada = (char*) malloc ((strlen (argv[i]) + 1)*sizeof(char));
			strcpy (dirEntrada, argv[i]);
		}
		else if (strcmp ("-q", argv[i])==0){
			i++;
			nomeqry = (char*) malloc ((strlen (argv[i]) + 1)*sizeof(char));
			strcpy (nomeqry, argv[i]);
			nomeqryN = tratarNome(nomeqry, nomeqryN); //Nome do arquivo .qry tratado
		}
		else if (strcmp ("-o", argv[i])==0){
			i++;
			dirSaida = (char*) malloc ((strlen (argv[i])+1)*sizeof(char));
			strcpy (dirSaida, argv[i]);
		}
		i++;
	}
	
	//Concatenaçao do .geo
	if (dirEntrada != NULL) {
		if(dirEntrada[strlen(dirEntrada) - 1] == '/'){
			arqgeo = (char*) malloc ((strlen(nomegeo)+strlen(dirEntrada)+1)*sizeof(char));
			sprintf (arqgeo, "%s%s", dirEntrada, nomegeo);
		}
		else{
			arqgeo = (char*) malloc ((strlen(nomegeo)+strlen(dirEntrada)+2)*sizeof(char));
			sprintf (arqgeo, "%s/%s", dirEntrada, nomegeo);
		}
		geo = fopen (arqgeo, "r");
		verificaArquivo (geo, nomegeo);
	}
	else{
		geo = fopen (nomegeo, "r");
		verificaArquivo (geo, nomegeo);
	}

	//Se o .qry existir é feita a concatenaçao
	if (nomeqry != NULL){
		if (dirEntrada != NULL){
			if(dirEntrada[strlen(dirEntrada) - 1] == '/'){
				arqqry = (char*) malloc ((strlen(nomeqry)+strlen(dirEntrada)+1)*sizeof(char));
				sprintf (arqqry, "%s%s", dirEntrada, nomeqry);
			}
			else{
				arqqry = (char*) malloc ((strlen(nomeqry)+strlen(dirEntrada)+2)*sizeof(char));
				sprintf (arqqry, "%s/%s", dirEntrada, nomeqry);
			}
			qry = fopen(arqqry, "r");
			verificaArquivo (qry, nomeqry);
		}
		else{
			qry = fopen (nomeqry, "r");
			verificaArquivo (qry, nomeqry);
		}
	}

	arqsvg = criaSVG(nomegeoN, dirSaida, arqsvg);	
	rewind (geo);

	if (nomeqry != NULL) {
		arqtxt = criaTXT(nomegeoN,nomeqryN, dirSaida, arqtxt);
		arqsvg2 = criaSVG2(nomegeoN, nomeqryN, dirSaida, arqsvg2);
		rewind (qry);
		leArquivos (geo,qry, arqsvg, arqtxt, arqsvg2);
	}
	else {
		leGEO (geo, arqsvg);
	}

	free(nomegeo);
	free(nomegeoN);
	free(nomeqry);
	free(nomeqryN);
	free(nomesvg);
	free(nometxt);
	free(nomesvg2);
	free(dirEntrada);
	free(dirSaida);
	free(arqgeo);
	free(arqqry);
	free(arqsvg);
	free(arqtxt);
	free(arqsvg2);	

	return 0;
}