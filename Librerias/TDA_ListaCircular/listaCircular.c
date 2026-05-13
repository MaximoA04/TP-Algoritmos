#include "listaCircular.h"

void crearListaC(tListaC *p)
{
    *p = NULL;
}
void vaciarListaC(tListaC *p)
{
    if(!*p)
        return;

    tNodo *act = (*p)->sigN;
    tNodo *aux;

    while(act != *p)
    {
        aux = act;
        act = aux->sigN;
        free(aux->dato);
        free(aux);
    }
    free(act->dato);
    free(act);
    *p = NULL;
}
int insertarEnListaC(tListaC *p, const void *elem, unsigned tam, Comparar cmp)
{
    tNodo *nue, *act, *ant;

    if(!*p || cmp(elem, (*p)->sigN->dato) < 0)
        return insertarPriC(p, elem, tam);

    if(cmp(elem, (*p)->dato) >= 0)
        return insertarUltC(p, elem, tam);

    ant = *p;
    act = (*p)->sigN;

    while(cmp(elem, act->dato) > 0)
    {
        ant = act;
        act = act->sigN;
    }

    nue = crearNodo(elem, tam);
    if(!nue)
        return ERR_MEM;

    nue->sigN = act;
    ant->sigN = nue;

    return TODO_OK;
}
int insertarPriC(tListaC *p, const void *elem, unsigned tam)
{
    tNodo *nue = crearNodo(elem, tam);
    if(!nue)
        return ERR_MEM;

    if(!*p)
    {
        nue->sigN = nue;
        *p = nue;
    }
    else
    {
        nue->sigN = (*p)->sigN;
        (*p)->sigN = nue;
    }
    return TODO_OK;
}
int insertarUltC(tListaC *p, const void *elem, unsigned tam)
{
    tNodo *nue = crearNodo(elem, tam);
    if(!nue) return ERR_MEM;

    if(!*p)
    {
        nue->sigN = nue;
    }
    else
    {
        nue->sigN = (*p)->sigN;
        (*p)->sigN = nue;
    }
    *p = nue;
    return TODO_OK;
}
int eliminarElemC(tListaC *p, void *elem, unsigned tam, Comparar cmp)
{
    if(!*p || !cmp)
        return ERROR;

    tNodo *ant = *p;
    tNodo *act = (*p)->sigN;
    int comp = cmp(elem, act->dato);

    while(act != *p && comp != 0)
    {
        ant = act;
        act = act->sigN;
        comp = cmp(elem, act->dato);
    }

    if(comp != 0)
        return NO_ENCONTRADO;

    if(elem)
        memcpy(elem, act->dato, MIN(tam, act->tam));

    if(act == ant)
        *p = NULL;
    else
    {
        if(act == *p)
            *p = ant;
        ant->sigN = act->sigN;
    }

    free(act->dato);
    free(act);
    return TODO_OK;
}
int eliminarPriC(tListaC *p, void *elem, unsigned tam)
{
    tNodo *aux;
    if(!*p)
        return ERROR;

    aux = (*p)->sigN;
    if(elem)
        memcpy(elem, aux->dato, MIN(tam, aux->tam));

    if(aux == *p)
        *p = NULL;
    else
        (*p)->sigN = aux->sigN;

    free(aux->dato);
    free(aux);
    return TODO_OK;
}
int eliminarUltC(tListaC *p, void *elem, unsigned tam)
{
    tNodo *ant, *act;
    if(!p || !*p)
        return ERROR;

    act = (*p)->sigN;
    ant = *p;

    if(act == ant)
    {
        if(elem)
            memcpy(elem, act->dato, MIN(tam, act->tam));
        *p = NULL;
    }
    else
    {
        while(act != *p)
        {
            ant = act;
            act = act->sigN;
        }

        if(elem)
            memcpy(elem, act->dato, MIN(tam, act->tam));

        ant->sigN = act->sigN;
        *p = ant;
    }

    free(act->dato);
    free(act);
    return TODO_OK;
}
int verPrimeroC(const tListaC *p, void *elem, unsigned tam)
{
    if(!*p)
        return ERROR;

    tNodo *primero = (*p)->sigN;
    memcpy(elem, primero->dato, MIN(tam, primero->tam));

    return TODO_OK;
}
int verUltimoC(const tListaC *p, void *elem, unsigned tam)
{
    if(!*p)
        return ERROR;

    memcpy(elem, (*p)->dato, MIN(tam, (*p)->tam));

    return TODO_OK;
}

////////////////////////////////////////////////////////////////////////

void mostrarListaC(tListaC *p, Mostrar mostrar)
{
    tNodo *aux;
    if(!p || !*p || !mostrar)
        return;

    aux = (*p)->sigN;

    while(aux != *p)
    {
        mostrar(aux->dato);
        printf(" | ");
        aux = aux->sigN;
    }
    mostrar(aux->dato);
}


