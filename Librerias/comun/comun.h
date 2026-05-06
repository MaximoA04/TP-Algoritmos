#ifndef COMUN_H_INCLUDED
#define COMUN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TODO_OK 0
#define ERROR 1
#define ERR_MEM 2
#define ERR_ARCH 3

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX_TAM 81


typedef struct sNodo
{
    char* dato;
    unsigned tam;
    struct sNodo* sigN;
}
tNodo;

tNodo* crearNodo(const void *elem, unsigned tam);

#endif /*COMUN_H_INCLUDED*/
