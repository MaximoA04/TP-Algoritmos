#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comun.h"


/*#define ESTATICA*/
#ifdef ESTATICA

typedef struct
{
    char pila[TAM_PILA];
    unsigned tope;
}
tPila;

#else

typedef tNodo* tPila;

#endif


void crearPila(tPila* p);
void destruirPila(tPila* p);
int pilaVacia(const tPila* p);
int pilaLlena(const tPila* p, unsigned tam);
int apilar(tPila* p, const void* elem, unsigned tam);
int desapilar(tPila* p, void* elem, unsigned tam);
int verTope(const tPila* p, void* elem, unsigned tam);

#endif /*PILA_H_INCLUDED*/
