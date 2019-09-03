#include"leitura.h"
#include"consultas.h"
#include"lista.h"
#include"utils.h"

void leQRY (FILE * nomearq,FILE * nomegeo,FILE * nometxt,FILE * nomesvg, char * svgBB, Lista Lformas, Lista Lquadra, Lista LHidrante,
Lista Lsemaforo, Lista LRadio, Lista Lextra)
{   
    char cond[20], metrica[5], aux, strtexto[50], sufixo[20], cor[24], cstrk[24], cep [32], face;
    char j[20], k[20];
    double x, y, w, h, r, num;
    double dx, dy, dist;
    int ns, ki;
    
    while (1){
        fscanf (nomearq, "%s", cond);

        if (feof(nomearq)){
            break;
        }

        if (strcmp (cond, "d?") == 0){
            fscanf(nomearq, "%s", j);
            fscanf(nomearq, "%s", k);

            fprintf(nometxt, "d? %s %s\n", j, k);
            consultaD (j, k, Lformas,nometxt, nomesvg);
            
            fscanf(nomearq, "%c", &aux);
        }

        else if (strcmp (cond, "o?") == 0){
            fscanf (nomearq, "%s", j);
            fscanf (nomearq, "%s", k);

            fprintf(nometxt, "o? %s %s\n", j, k);
            consultaO (j, k, Lformas, nometxt, nomesvg);
            
            fscanf(nomearq, "%c", &aux); 
        }

        else if (strcmp (cond, "i?") == 0){
            fscanf (nomearq, "%s", j);
            fscanf (nomearq, "%lf", &x);
            fscanf (nomearq, "%lf", &y);

            fprintf (nometxt, "i? %s %lf %lf\n", j, x, y);
            consultaI (j, x, y, Lformas, nometxt, nomesvg);

            fscanf (nomearq, "%c", &aux);
        }

        else if (strcmp (cond, "bb") == 0){
            fscanf (nomearq, "%s", sufixo);
            fscanf (nomearq, "%s", cor);

            consultaBB (sufixo, cor, svgBB,Lformas, nomegeo);

            fscanf (nomearq, "%c", &aux);
        }

        else if (strcmp (cond, "crd?") == 0){
            fscanf (nomearq, "%s", j);

            fprintf (nometxt, "crd? %s\n", j);            
            consultaCRD (j, Lquadra, LHidrante, Lsemaforo, LRadio, nometxt);

            fscanf (nomearq, "%c", &aux);
        }

        else if (strcmp (cond, "del") == 0){
            fscanf (nomearq, "%s", j);

            fprintf (nometxt, "del %s\n", j);
            consultaDEL (j, Lquadra, LHidrante, Lsemaforo, LRadio, nometxt);

            fscanf (nomearq, "%c", &aux);
        }

        else if (strcmp (cond, "cbq") == 0){
            fscanf (nomearq, "%lf", &x);
            fscanf (nomearq, "%lf", &y);
            fscanf (nomearq, "%lf", &r);
            fscanf (nomearq, "%s", cstrk);

            fprintf (nometxt, "cbq %lf %lf %lf %s\n", x, y, r, cstrk);
            consultaCBQ (x, y, r, cstrk, Lquadra, nometxt);

            fscanf (nomearq, "%c", &aux);
        }

        else if (strcmp (cond, "trns") == 0){
            fscanf (nomearq ,"%lf", &x);
            fscanf (nomearq ,"%lf", &y);
            fscanf (nomearq ,"%lf", &w);
            fscanf (nomearq ,"%lf", &h);
            fscanf (nomearq ,"%lf", &dx);
            fscanf (nomearq ,"%lf", &dy);

            fprintf (nometxt, "trns %lf %lf %lf %lf %lf %lf\n",x, y, w, h, dx, dy);
            consultaTRNS (x, y, w, h, dx, dy, Lquadra, LHidrante, Lsemaforo, LRadio, nometxt);

            fscanf (nomearq, "%c", &aux);
        }

        else if (strcmp (cond, "dq") == 0){
            fscanf (nomearq, "%s", metrica);
            fscanf (nomearq, "%s", j);
            fscanf (nomearq, "%lf", &dist);

            fprintf (nometxt, "dq %s %s %lf\n", metrica, j, dist);
            consultaDQ (j, metrica, dist, Lquadra, LHidrante, Lsemaforo, LRadio, nometxt, nomesvg);

            fscanf (nomearq, "%c", &aux);
        }

        else if (strcmp (cond, "fi") == 0){
            fscanf (nomearq, "%lf", &x);
            fscanf (nomearq, "%lf", &y);
            fscanf (nomearq, "%d", &ns);
            fscanf (nomearq, "%lf", &r);

            fprintf (nometxt, "fi %lf %lf %d %lf\n", x, y, ns, r);
            consultaFI (x, y, ns, r, LHidrante, Lsemaforo, Lextra, nomesvg, nometxt);

            fscanf (nomearq, "%c", &aux);
        }
        else if (strcmp (cond, "fs") == 0){
            fscanf (nomearq, "%d", &ki);
            fscanf (nomearq, "%s %c", cep, &face);
            //fscanf (nomearq, "%c", &face);
            fscanf (nomearq, "%lf", &num);

            fprintf (nometxt, "fs %d %s %c %lf\n",ki, cep, face, num);
            consultaFS (ki, cep, face, num, Lquadra, Lsemaforo, Lextra, nomesvg, nometxt);

            fscanf (nomearq, "%c", &aux);
        }
        else if (strcmp (cond, "fh") == 0){
            fscanf (nomearq, "%d", &ki);
            fscanf (nomearq, "%s %c", cep, &face);
            //fscanf (nomearq, "%c", &face);
            fscanf (nomearq, "%lf", &num);

            fprintf (nometxt, "fh %d %s %c %lf\n", ki, cep, face, num);
            consultaFH (ki, cep, face, num, Lquadra, LHidrante, Lextra, nomesvg, nometxt);

            fscanf (nomearq, "%c", &aux);
        }
        else if (strcmp (cond, "brl") == 0){
            fscanf (nomearq, "%lf", &x);
            fscanf (nomearq, "%lf", &y);

            
        }
    }
}
