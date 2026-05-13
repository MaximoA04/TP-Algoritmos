#include "comun.h"

tNodo* crearNodo(const void *elem, unsigned tam)
{
    tNodo *nue = (tNodo*)malloc(sizeof(tNodo));
    if (!nue)
        return NULL;

    nue->dato = malloc(tam);
    if (!nue->dato)
    {
        free(nue);
        return NULL;
    }

    memcpy(nue->dato, elem, tam);
    nue->tam = tam;
    nue->sigN = NULL;

    return nue;
}

tNodoD* crearNodoDoble(const void *elem, unsigned tam)
{
    tNodoD *nue = (tNodoD*)malloc(sizeof(tNodoD));
    if (!nue)
        return NULL;

    nue->dato = malloc(tam);
    if (!nue->dato)
    {
        free(nue);
        return NULL;
    }

    memcpy(nue->dato, elem, tam);
    nue->tam = tam;
    nue->ant = NULL;
    nue->sig = NULL;

    return nue;
}
