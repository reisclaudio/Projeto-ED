#include"leitura.h"
#include"svgprint.h"
#include"arquivos.h"
#include"lista.h"
#include"./Elementos/forma.h"
#include"./Elementos/quadra.h"
#include"./Elementos/hidrante.h"
#include"./Elementos/semaforo.h"
#include"./Elementos/radioBase.h"
#include"./Elementos/predio.h"
#include"./Elementos/muro.h"

void leArquivos (FILE * arqGeo,FILE * arqQry, char * nomesvg, char * nometxt, char * nomesvg2)
{	
	FILE * arqsvg;	
	arqsvg = fopen (nomesvg, "w+");
	verificaArquivo (arqsvg, nomesvg);
	fprintf (arqsvg, "<svg>\n");
	
	FILE * arqsvg2;
	arqsvg2 = fopen (nomesvg2, "w+");
	verificaArquivo (arqsvg2, nomesvg2);
	fprintf (arqsvg2, "<svg>\n");
	
	FILE * arqtxt;
	arqtxt = fopen (nometxt, "w+");
	verificaArquivo (arqtxt, nometxt);

	char tipo [10], barraN, face, texto[500], cep[50], cor1[24], cor2[24], id[50], c1q[24], c2q[24],
	c1h[24], c2h[24], c1t[24], c2t[24], c1s[24], c2s[24];
	char swq[20], swh[20], swt[20], sws[20], swc[20], swr[20];
	int nx = 1000, nq = 1000, nh = 1000, ns = 1000, nr = 1000, np = 1000, nm = 1000;
	double x, y, w, h, r, num, f, p, mrg, x1, y1, x2, y2;

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

	//Ponteiros void para cada estrutura
	Forma circulo;
	Forma retangulo;
	Quadra quadra;
	Hidrante hidrante;
	Semaforo semaforo;
	RadioBase radioBase;
	Predio predio;
	Muro muro;
	
	//Leitura dos parametros do nx para iniciar as listas
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
			fscanf (arqGeo, "%d", &np);
			fscanf (arqGeo, "%d", &nm);

			fscanf (arqGeo, "%c", &barraN);
		}
	}

	Lista listaFormas = iniciaLista (nx);
	Lista listaQuadras = iniciaLista (nq);
	Lista listaHidrantes = iniciaLista (nh);
	Lista listaSemaforos = iniciaLista (ns);
	Lista listaRadiosBase = iniciaLista (nr);
	Lista listaPredios = iniciaLista (np);
	Lista listaMuros = iniciaLista (nm);
	Lista listaExtra = iniciaLista (nx);

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

			circulo = criaForma (id, 'c', x, y, r, 0, 0, cor1, cor2, swc);
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
			inserirElemento (listaQuadras, quadra);

			fscanf (arqGeo, "%c", &barraN); //fscanf para pegar "/n"
		}

		else if (strcmp (tipo, "h") == 0){
			fscanf (arqGeo, "%s", id);
			fscanf (arqGeo, "%lf", &x);
			fscanf (arqGeo, "%lf", &y);

			hidrante = criaHidrante (id, x, y, c1h, c2h, swh);
			inserirElemento (listaHidrantes, hidrante);

			fscanf (arqGeo, "%c", &barraN); //fscanf para pegar "/n"
		}

		else if (strcmp (tipo, "s") == 0){
			fscanf (arqGeo, "%s", id);
			fscanf (arqGeo, "%lf", &x);
			fscanf (arqGeo, "%lf", &y);

			semaforo = criaSemaforo (id, x, y, c1s, c2s, sws);
			inserirElemento (listaSemaforos, semaforo);

			fscanf (arqGeo, "%c", &barraN); //fscanf para pegar "/n"
		}

		else if (strcmp (tipo, "rb") == 0){
			fscanf (arqGeo, "%s", id);
			fscanf (arqGeo, "%lf", &x);
			fscanf (arqGeo, "%lf", &y);

			radioBase = criaRadioBase (id, x, y, c1t, c2t, swt);
			inserirElemento (listaRadiosBase, radioBase);

			fscanf (arqGeo, "%c", &barraN); //fscanf para pegar "/n"
		}

		else if (strcmp (tipo, "prd") == 0){
			fscanf (arqGeo, "%s %c", cep, &face);
			//fscanf (arqGeo, "%c", &face);
			fscanf (arqGeo, "%lf", &num);
			fscanf (arqGeo, "%lf", &f);
			fscanf (arqGeo, "%lf", &p);
			fscanf (arqGeo, "%lf", &mrg);

			Quadra quadraPredio = encontrarElemento (listaQuadras, cep);
			double xQ = getXQuadra (quadraPredio);
			double yQ = getYQuadra (quadraPredio);
			double hQ = getHQuadra (quadraPredio);
			double wQ = getWQuadra (quadraPredio);

			if (face == 'N'){
				 x = xQ + num;
				 y = ((yQ + hQ)) - mrg - p; 
			}
			else if (face == 'S') {
				x = xQ + num;
				y = yQ + mrg;
			}
			else if (face == 'L'){
				x = xQ + mrg;
				y = yQ + num;
			}
			else if (face == 'O'){
				x = ((xQ + wQ)) - mrg - p;
				y = yQ + num;
			}

			predio = criaPredio (cep, face, num, f, p , mrg, x, y, hQ, wQ);
			inserirElemento (listaPredios, predio);
	
			fscanf (arqGeo, "%c", &barraN); //fscanf para pegar "/n"
		}

		else if (strcmp (tipo, "mur") == 0) {
			fscanf (arqGeo, "%lf", &x1);
			fscanf (arqGeo, "%lf", &y1);
			fscanf (arqGeo, "%lf", &x2);
			fscanf (arqGeo, "%lf", &y2);

			muro = criaMuro (x1, y1, x2, y2);
			inserirElemento (listaMuros, muro);

			fscanf (arqGeo, "%c", &barraN); //fscanf para pegar "/n"
		}

		else if (strcmp (tipo, "t") == 0){
			fscanf (arqGeo, "%lf", &x);
			fscanf (arqGeo, "%lf", &y);
			fgets(texto, 500, arqGeo);

			svgprinttext(texto,x, y, arqsvg);
			svgprinttext(texto,x, y, arqsvg2);
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

	//Imprime listas no svg do.geo
	imprimeListaSVG (listaFormas, arqsvg);
	imprimeListaSVG (listaFormas, arqsvg2);		
	imprimeListaSVG (listaQuadras, arqsvg);
	imprimeListaSVG (listaHidrantes, arqsvg);
	imprimeListaSVG (listaSemaforos, arqsvg);
	imprimeListaSVG (listaRadiosBase, arqsvg);
	imprimeListaSVG (listaPredios, arqsvg);	
	imprimeListaSVG (listaMuros, arqsvg);
		
	leQRY (arqQry,arqGeo,arqtxt,arqsvg2, nomesvg2, listaFormas, listaQuadras, listaHidrantes, listaSemaforos, listaRadiosBase, listaMuros, listaPredios, listaExtra);
	
	//Imprime listas no svg do .qry
	imprimeListaSVG (listaQuadras, arqsvg2);
	imprimeListaSVG (listaHidrantes, arqsvg2);
	imprimeListaSVG (listaSemaforos, arqsvg2);
	imprimeListaSVG (listaRadiosBase, arqsvg2);
	imprimeListaSVG (listaPredios, arqsvg2);
	imprimeListaSVG (listaMuros, arqsvg2);	
	imprimeListaSVG (listaExtra, arqsvg2);

	fprintf (arqsvg2, "</svg>\n");
	fprintf (arqsvg, "</svg>\n");

	desalocarLista (listaFormas, freeForma);
	desalocarLista (listaHidrantes, freeHidrante);
	desalocarLista (listaQuadras, freeQuadra);
	desalocarLista (listaSemaforos, freeSemaforo);
	desalocarLista (listaRadiosBase, freeRadioBase);
	desalocarLista (listaPredios, freePredio);
	desalocarLista (listaMuros, freeMuro);
	desalocarLista (listaExtra, freeForma);
	
	fclose(arqsvg);
	fclose(arqsvg2);
	fclose(arqtxt);	
}
