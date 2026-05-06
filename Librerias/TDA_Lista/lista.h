#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comun.h"


typedef tNodo *tLista;
typedef int (*Comparar)(const void*, const void*);
typedef void (*Accion)(void*, const void *);
typedef void (*Mostrar)(const void*);

void crearLista(tLista *p);
void vaciarLista(tLista *p);
int listaLlena(const tLista *p);
int listaVacia(const tLista *p);
int ordenarLista(tLista *p, Comparar cmp);
int insertarAlComienzo(tLista *p, const void *elem, unsigned tam);
int insertarAlFinal(tLista *p, const void *elem, unsigned tam);
int insertarOrdenado(tLista *p, const void *elem, unsigned tam, int esDup, Comparar cmp, Accion acc);
int eliminarPrimeroLista(tLista *p, void *elem, unsigned tam);
int eliminarUltimoLista(tLista *p, void *elem, unsigned tam);
int eliminarSinOrden(tLista *p, void *elem, Comparar cmp);
int eliminarOrdenado(tLista *p, void *elem, Comparar cmp);
int vecPrimeroLista(const tLista *p, void *elem, unsigned tam);
int vecUltimoLista(const tLista *p, void *elem, unsigned tam);
void mostrarLista(const tLista *p, Mostrar f_Mostrar);


#endif /*LISTA_H_INCLUDED*/
