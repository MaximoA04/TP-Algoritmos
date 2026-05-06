#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comun.h"

/*#define ESTATICA*/
#ifdef ESTATICA

typedef struct
{
    char cola[MAX_TAM];
    unsigned primero;
    unsigned ultimo;
    unsigned tam;
}
tCola;

#else

typedef struct
{
    tNodo* pri;
    tNodo* ult;
}
tCola;

#endif /*ESTATICA*/


void crearCola(tCola* cola);
void vaciarCola(tCola* cola);
int colaLlena(const tCola* cola);
int colaVacia(const tCola* cola);
int ponerEnCola(tCola* cola, const void* elem, unsigned tam);
int sacarDeCola(tCola* cola, void* elem, unsigned tam);
int vecPrimero(const tCola* cola, void* elem, unsigned tam);

#endif /*COLA_H_INCLUDED*/
