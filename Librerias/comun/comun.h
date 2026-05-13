#ifndef COMUN_H_INCLUDED
#define COMUN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TODO_OK 0
#define ERROR 1
#define ERR_MEM 2
#define ERR_ARCH 3
#define NO_ENCONTRADO 4

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX_TAM 81

#define ASCD 1
#define DSCD -1


typedef struct sNodo
{
    void *dato;
    unsigned tam;
    struct sNodo* sigN;
}
tNodo;
typedef struct sNodoD
{
    void *dato;
    unsigned tam;
    struct sNodoD *sig;
    struct sNodoD *ant;
}
tNodoD;

typedef int (*Comparar)(const void*, const void*);
typedef void (*Accion)(void*, const void *);
typedef void (*Mostrar)(const void*);

tNodo* crearNodo(const void *elem, unsigned tam);
tNodoD* crearNodoDoble(const void *elem, unsigned tam);

#endif /*COMUN_H_INCLUDED*/
