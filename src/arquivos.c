#include"leitura.h"
#include"arquivos.h"

void verificaArquivo (FILE * arquivo, char * nomeArquivo)
{
	if (arquivo == NULL){
		printf ("Erro ao abrir o arquivo %s\n", nomeArquivo);
		exit (1);
	}
}

char * tratarNome (char nomearq[], char * nomearq2)
{
	int i= 0, j = 0, save;
	bool valid = false;

	nomearq2 = (char*) malloc ((strlen(nomearq)+2) * sizeof(char));

	while (1){
		if (nomearq[i] == '/'){
			save = i;
			valid = true;
		}
		else if (nomearq[i] == '.' && i!= 0){
			if (valid){
				save++;
				break;
			}
			else {
				strcpy (nomearq2, nomearq);
				return nomearq2;
			}
		}
		i++;
	}
	while (nomearq[j] != '\0'){
		nomearq2[j] = nomearq[save];
		j++;
		save++;
	}
	return nomearq2;
}

char * criaSVG(char nomegeo[], char dirSaida[], char *arqsvg){
	char * nomesvg;
	int i = 0;
	nomesvg = (char *)malloc(strlen(nomegeo)+1* sizeof(char));

	while(nomegeo[i] != '.'){
		nomesvg[i] = nomegeo[i];
		i++;
	}

	strcat(nomesvg, ".svg");

	if(dirSaida[strlen(dirSaida) - 1] == '/'){
		arqsvg = (char *)malloc((strlen(dirSaida) + strlen(nomesvg) + 1) * sizeof(char));
		sprintf(arqsvg, "%s%s", dirSaida, nomesvg);
	}
	else{
		arqsvg = (char *)malloc((strlen(dirSaida) + strlen(nomesvg) + 2) * sizeof(char));
		sprintf(arqsvg, "%s/%s", dirSaida, nomesvg);
	}
	return arqsvg;
}

char * criaTXT (char nomegeo[], char nomeqry [], char dirSaida[], char *arqtxt){
	char * nometxt, c[500];
	int i = 0, j = 0;
	nometxt = (char*) malloc ((strlen(nomegeo) + strlen(nomeqry) + 1) * sizeof(char));

	while (nomegeo[i] != '.'){
		nometxt[i] = nomegeo[i];
		i++;
	}
	
	strcat(nometxt, "-");	
	i = i+1;

	while (nomeqry[j] != '.'){
		nometxt[i] = nomeqry[j];
		j++;
		i++;
	}

	strcat(nometxt, ".txt");

	if (dirSaida[strlen(dirSaida) - 1] == '/') {
		arqtxt = (char *)malloc((strlen(dirSaida) + strlen(nometxt) + 1) * sizeof(char));
		sprintf(arqtxt, "%s%s", dirSaida, nometxt);
	}
	else{
		arqtxt = (char *)malloc((strlen(dirSaida) + strlen(nometxt) + 2) * sizeof(char));
		sprintf(arqtxt, "%s/%s", dirSaida, nometxt);
	}
	return arqtxt;
}

char * criaSVG2 (char nomegeo[], char nomeqry[], char dirSaida[], char *arqsvg2){
	char * nomesvg2;
	int i = 0, j = 0, x, y, xy;
	x = strlen(nomegeo);
	y = strlen(nomeqry);
	xy = x+y+1;

	nomesvg2 = (char*) malloc (xy*sizeof(char));

	while (nomegeo[i] != '.'){
		nomesvg2[i] = nomegeo[i];
		i++;
	}
	
	strcat(nomesvg2, "-");
	i = i+1;

	while (nomeqry[j] != '.'){
		nomesvg2[i] = nomeqry[j];
		j++;
		i++;
	}
	
	strcat(nomesvg2, ".svg");

	if(dirSaida[strlen(dirSaida) - 1] == '/'){
		arqsvg2 = (char *)malloc((strlen(dirSaida) + strlen(nomesvg2) + 1) * sizeof(char));
		sprintf(arqsvg2, "%s%s", dirSaida, nomesvg2);
	}
	else{
		arqsvg2 = (char *)malloc((strlen(dirSaida) + strlen(nomesvg2) + 2) * sizeof(char));
		sprintf(arqsvg2, "%s/%s", dirSaida, nomesvg2);
	}
	return arqsvg2;
}

char * criaSVG3 (char * nomesvg, char * sufixo)
{
	char* nomesvg3;
	int i = 0, j = 0, x, y, xy;
	
	x = strlen (nomesvg);
	y = strlen (sufixo);
	xy = x+y+3;

	nomesvg3 = (char*) malloc (xy*sizeof(char));
	
	if (nomesvg[0] == '.' && nomesvg[1] == '.'){
		sprintf (nomesvg3, "..");
		i = 2;
	}

	if (nomesvg[0] == '.' && nomesvg[1] != '.'){
		sprintf (nomesvg3, ".");
		i = 1;
	}

	while (nomesvg[i] != '.'){
		nomesvg3[i] = nomesvg[i];
		i++;
	}	
	
	strcat(nomesvg3, "-");
	strcat (nomesvg3, sufixo);
	strcat(nomesvg3, ".svg");
	
	return nomesvg3;
}