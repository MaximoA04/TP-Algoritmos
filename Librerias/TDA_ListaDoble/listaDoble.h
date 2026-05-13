////////////////////////////////////
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comun.h"

typedef tNodoD *tListaD;


void crearListaD(tListaD *p);
void vaciarListaD(tListaD *p);
int insertarEnListaD(tListaD *p, const void *elem, unsigned tam, int conDup, Comparar cmp, Accion acc);
int insertarPriListaD(tListaD *p, const void *elem, unsigned tam);
int insertarUltListaD(tListaD *p, const void *elem, unsigned tam);
int eliminarDeListaD(tListaD *p, void *elem, Comparar cmp);
int eliminarPriListaD(tListaD *p, void *elem, unsigned tam);
int eliminarUltListaD(tListaD *p, void *elem, unsigned tam);
int verActualD(const tListaD *p, void *elem, unsigned tam);
int irAlInicioD(tListaD *p);
int irAlFinalD(tListaD *p);

////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarListaD(tListaD *p, int orden, Mostrar mostrar);

#endif // FUNCIONES_H_INCLUDED
