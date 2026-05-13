#ifndef LISTACIRCULAR_H_INCLUDED
#define LISTACIRCULAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comun.h"

typedef tNodo* tListaC;

void crearListaC(tListaC *p);
void vaciarListaC(tListaC *p);
int insertarEnListaC(tListaC *p, const void *elem, unsigned tam, Comparar cmp);
int insertarPriC(tListaC *p, const void *elem, unsigned tam);
int insertarUltC(tListaC *p, const void *elem, unsigned tam);
int eliminarElemC(tListaC *p, void *elem, unsigned tam, Comparar cmp);
int eliminarPriC(tListaC *p, void *elem, unsigned tam);
int eliminarUltC(tListaC *p, void *elem, unsigned tam);
int verPrimeroC(const tListaC *p, void *elem, unsigned tam);
int verUltimoC(const tListaC *p, void *elem, unsigned tam);

////////////////////////////////////////////////////////////////////////

void mostrarListaC(tListaC *p, Mostrar mostrar);

#endif
