#include"leitura.h"
#include"arquivos.h"
#include"lista.h"
#include"./Elementos/forma.h"
#include"./Elementos/quadra.h"
#include"./Elementos/hidrante.h"
#include"./Elementos/semaforo.h"
#include"./Elementos/radioBase.h"

void leGEO (FILE * arqGeo, char * nomesvg)
{
    FILE * arqsvg;	
	arqsvg = fopen (nomesvg, "w+");
	verificaArquivo(arqsvg, nomesvg);
		
	fprintf (arqsvg, "<svg>\n");

	char tipo [10], barraN, texto[500], cep[50], cor1[24], cor2[24], id[50], c1q[24], c2q[24],
	c1h[24], c2h[24], c1t[24], c2t[24], c1s[24], c2s[24];
	char swq[20], swh[20], swt[20], sws[20], swc[20], swr[20];
	int nx = 1000, nq = 1000, nh = 1000, ns = 1000, nr = 1000;
	double x, y, w, h, r;

	//Atribui cores default
	strcpy (c1q, "blue");
	strcpy (c2q, "black");
	strcpy (c1h, "red");
	strcpy (c2h, "black");
	strcpy (c1s, "green");
	strcpy (c2s, "black");
	strcpy (c1t, "yellow");
	strcpy (c2t, "black");
	strcpy (swc, "1");
	strcpy (swr, "1");
	strcpy (swq, "1");
	strcpy (swh, "1");
	strcpy (sws, "1");
	strcpy (swt, "1");

	//Ponteiros void para cada estruturas
	Forma circulo;
	Forma retangulo;
	Quadra quadra;
	Hidrante hidrante;
	Semaforo semaforo;
	RadioBase radioBase;
	
	//Listas
	Lista listaFormas;
	Lista listaQuadra;
	Lista listaHid;
	Lista listaSema;
	Lista listaRB;

	while (1){
		fscanf (arqGeo, "%s", tipo);

		if (feof (arqGeo))
			break;

		if (strcmp (tipo, "nx") == 0){
			fscanf (arqGeo, "%d", &nx);
			fscanf (arqGeo, "%d", &nq);
			fscanf (arqGeo, "%d", &nh);
			fscanf (arqGeo, "%d", &ns);
			fscanf (arqGeo, "%d", &nr);

			fscanf (arqGeo, "%c", &barraN);
		}
	}

	listaFormas = iniciaLista (nx);
	listaQuadra = iniciaLista (nq);
	listaHid = iniciaLista (nh);
	listaSema = iniciaLista (ns);
	listaRB = iniciaLista (nr);

	rewind (arqGeo);
	
	// Faz a leitura de todo o .geo
	while (1){
		fscanf (arqGeo, "%s", tipo);

		if (feof(arqGeo)){
			break;
		}

		if (strcmp (tipo, "c") == 0){
			fscanf (arqGeo, "%s", id);
			fscanf (arqGeo, "%lf", &r);
			fscanf (arqGeo, "%lf", &x);
			fscanf (arqGeo, "%lf", &y);
			fscanf (arqGeo, "%s", cor1);
			fscanf (arqGeo, "%s", cor2);

			circulo = criaForma (id, 'c', x, y,r , 0, 0, cor1, cor2,swc);
			inserirElemento (listaFormas, circulo);

			fscanf (arqGeo, "%c", &barraN); //fscanf para pegar  "\n"
		}
		else if (strcmp (tipo, "r") == 0){
			fscanf (arqGeo, "%s", id);
			fscanf (arqGeo, "%lf", &w);	
			fscanf (arqGeo, "%lf", &h);
			fscanf (arqGeo, "%lf", &x);	
			fscanf (arqGeo, "%lf", &y);
			fscanf (arqGeo, "%s", cor1);
			fscanf (arqGeo, "%s", cor2);
			
			retangulo = criaForma (id, 'r', x, y, 0, w, h, cor1, cor2,swr);
			inserirElemento (listaFormas, retangulo);
			
			fscanf (arqGeo, "%c", &barraN); //fscanf para pegar  "\n"
		}

		else if (strcmp (tipo, "q") == 0){
			fscanf (arqGeo, "%s", cep);
			fscanf (arqGeo, "%lf", &x);
			fscanf (arqGeo, "%lf", &y);
			fscanf (arqGeo, "%lf", &w);
			fscanf (arqGeo, "%lf", &h);

			quadra = criaQuadra (cep, x, y, w, h, c1q, c2q, swq);
			inserirElemento (listaQuadra, quadra);

			fscanf (arqGeo, "%c", &barraN); //fscanf para pegar "/n"
		}

		else if (strcmp (tipo, "h") == 0){
			fscanf (arqGeo, "%s", id);
			fscanf (arqGeo, "%lf", &x);
			fscanf (arqGeo, "%lf", &y);

			hidrante = criaHidrante (id, x, y, c1h, c2h, swh);
			inserirElemento (listaHid, hidrante);

			fscanf (arqGeo, "%c", &barraN); //fscanf para pegar "/n"
		}

		else if (strcmp (tipo, "s") == 0){
			fscanf (arqGeo, "%s", id);
			fscanf (arqGeo, "%lf", &x);
			fscanf (arqGeo, "%lf", &y);

			semaforo = criaSemaforo (id, x, y, c1s, c2s, sws);
			inserirElemento (listaSema, semaforo);

			fscanf (arqGeo, "%c", &barraN); //fscanf para pegar "/n"
		}

		else if (strcmp (tipo, "rb") == 0){
			fscanf (arqGeo, "%s", id);
			fscanf (arqGeo, "%lf", &x);
			fscanf (arqGeo, "%lf", &y);

			radioBase = criaRadioBase (id, x, y, c1t, c2t, swt);
			inserirElemento (listaRB, radioBase);

			fscanf (arqGeo, "%c", &barraN); //fscanf para pegar "/n"
		}

		else if (strcmp (tipo, "t") == 0){
			fscanf (arqGeo, "%lf", &x);
			fscanf (arqGeo, "%lf", &y);
			fgets(texto, 500, arqGeo);
			svgprinttext(texto,x, y, arqsvg);
		}

		else if (strcmp (tipo, "cq") == 0){
			fscanf (arqGeo, "%s", c1q);
			fscanf (arqGeo, "%s", c2q);
			fscanf (arqGeo, "%s", swq);

			fscanf (arqGeo, "%c", &barraN); //fscanf para pegar "/n"
		}

		else if (strcmp (tipo, "ch") == 0){
			fscanf (arqGeo, "%s", c1h);
			fscanf (arqGeo, "%s", c2h);
			fscanf (arqGeo, "%s", swh);

			fscanf (arqGeo, "%c", &barraN); //fscanf para pegar "/n"
		}

		else if (strcmp (tipo, "cr") == 0){
			fscanf (arqGeo, "%s", c1t);
			fscanf (arqGeo, "%s", c2t);
			fscanf (arqGeo, "%s", swt);

			fscanf (arqGeo, "%c", &barraN); //fscanf para pegar "/n"
		}

		else if (strcmp (tipo, "cs") == 0){
			fscanf (arqGeo, "%s", c1s);
			fscanf (arqGeo, "%s", c2s);
			fscanf (arqGeo, "%s", sws);

			fscanf (arqGeo, "%c", &barraN); //fscanf para pegar "/n"
		}

		else if (strcmp (tipo, "sw") == 0){
			fscanf (arqGeo, "%s", swc);
			fscanf (arqGeo, "%s", swr);

			fscanf (arqGeo, "%c", &barraN); //fscanf para pegar "/n"
		}
	}

	
	imprimeListaSVG (listaFormas, arqsvg);
	imprimeListaSVG (listaQuadra, arqsvg);
	imprimeListaSVG (listaHid, arqsvg);
	imprimeListaSVG (listaSema, arqsvg);
	imprimeListaSVG (listaRB, arqsvg);
	fprintf (arqsvg, "</svg>\n");
	printf ("bana");

	desalocarLista (listaFormas, freeForma);
	desalocarLista (listaHid, freeHidrante);
	desalocarLista (listaQuadra, freeQuadra);
	desalocarLista (listaSema, freeSemaforo);
	desalocarLista (listaRB, freeRadioBase);
	
}

void geoBB (FILE * arqGeo, FILE * nomesvg, Lista lformas, char * cor)
{
    char tipo[50], barran, texto[500], cor1[24], cor2[24];
	char id[50] ,swc[20], swr[20];
	double x, y, r, w, h, xr, yr, wr, hr, cx, cy, rx, ry;

	//Atribui sw default
	strcpy (swc, "1");
	strcpy (swr, "1");
	
	Forma circulo;
	Forma retangulo;

    fprintf (nomesvg, "<svg>\n");
	rewind (arqGeo);

	//Faz a leitura de todo o .geo 
	//Printa no svg3 o que a consulta "bb" pede
    while (1){
		fscanf (arqGeo, "%s", tipo);

        if (feof(arqGeo)){
			fprintf (nomesvg, "</svg>");
			break;
        }

		else if (strcmp (tipo, "sw") == 0){
			fscanf (arqGeo, "%s", swc);
			fscanf (arqGeo, "%s", swr);

			fscanf (arqGeo, "%c", &barran); //fscanf para pegar "/n"
		}

        if (strcmp (tipo, "c") == 0){
			fscanf (arqGeo, "%s", id);	
			fscanf (arqGeo, "%lf", &r);
			fscanf (arqGeo, "%lf", &x);
			fscanf (arqGeo, "%lf", &y);
			fscanf (arqGeo, "%s", cor1);
			fscanf (arqGeo, "%s", cor2);
			circulo = criaForma (id, 'c', x, y, r, 0, 0, cor1, cor2, swc);
			
			svgprintcircle(circulo, nomesvg);

			//Calculo da largura, altura, x e y do retangulo "bb"
			hr = 2*getRaioForma (circulo);
			wr = 2*getRaioForma (circulo);
			xr = getXForma (circulo) - getRaioForma (circulo);
			yr = getYForma (circulo) - getRaioForma (circulo);

			retangulo = criaForma ("0", 'r', xr, yr, 0, wr, hr, "none", cor, "1");
			svgprintrect (retangulo, nomesvg);
			//svgprintrectBB (xr, yr, wr, hr,cor,  nomesvg);

			fscanf (arqGeo, "%c", &barran); //fscanf para pegar "\n"
		}
		else if (strcmp (tipo, "r") == 0){
			fscanf (arqGeo, "%s", id);
			fscanf (arqGeo, "%lf", &w);	
			fscanf (arqGeo, "%lf", &h);
			fscanf (arqGeo, "%lf", &x);	
			fscanf (arqGeo, "%lf", &y);
			fscanf (arqGeo, "%s", cor1);
			fscanf (arqGeo, "%s", cor2);
			retangulo = criaForma (id, 'r', x, y, 0, w, h, cor1, cor2, swr);
			
			svgprintrect(retangulo, nomesvg);

			//Calculo do (centro x, centroy), do raio x e do raio y da elipse "bb"
			cx = getXForma (retangulo) + getWForma (retangulo)/2.0;
			cy = getYForma (retangulo) + getHForma (retangulo)/2.0;
			ry = getHForma (retangulo)/2;
			rx = getWForma (retangulo)/2;

			svgprintellipse(cx, cy, rx, ry, cor, nomesvg);

			fscanf (arqGeo, "%c", &barran); //fscanf para pegar  "\n"
        }
    }
}