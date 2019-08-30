#ifndef MURO__H
#define MURO__H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//TAD MURO
typedef void* Muro;

Muro criaMuro (double x1, double y1, double x2, double y2);
double getX1Muro (Muro muro);
double getY1Muro (Muro muro);
double getX2Muro (Muro muro);
double getY2Muro (Muro muro);
void freeMuro (Muro muro);

#endif