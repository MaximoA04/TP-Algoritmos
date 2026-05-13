#include "listaDoble.h"

void crearListaD(tListaD *p)
{
    *p = NULL;
}
void vaciarListaD(tListaD *p)
{
    if (!p || !*p)
        return;

    while((*p)->ant)
        *p = (*p)->ant;

    while(*p)
    {
        tNodoD *aux = *p;
        *p = aux->sig;

        free(aux->dato);
        free(aux);
    }
}
int insertarEnListaD(tListaD *p, const void *elem, unsigned tam, int conDup, Comparar cmp, Accion acc)
{
    tNodoD *nAnt, *nSig, *nAct, *nue;
    int comp;

    if(!p || !elem || tam == 0 || !cmp)
        return ERROR;

    nAct = *p;

    if(*p == NULL)
    {
        nAnt = NULL;
        nSig = NULL;
    }
    else
    {
        while(nAct->sig != NULL && cmp(elem, nAct->dato) > 0)
            nAct = nAct->sig;
        while(nAct->ant != NULL && cmp(elem, nAct->dato) < 0)
            nAct = nAct->ant;

        comp = cmp(elem, nAct->dato);
        if(comp > 0)
        {
            nAnt = nAct;
            nSig = nAct->sig;
        }
        else if(comp < 0)
        {
            nAnt = nAct->ant;
            nSig = nAct;
        }
        else
        {
            if(!conDup)
            {
                if(acc)
                    acc(nAct->dato, elem);
                return TODO_OK;
            }
            nAnt = nAct;
            nSig = nAct->sig;
        }
    }

    nue = crearNodoDoble(elem, tam);
    if(nue == NULL)
        return ERR_MEM;

    if(nAnt)
        nAnt->sig = nue;
    if(nSig)
        nSig->ant = nue;

    nue->ant = nAnt;
    nue->sig = nSig;
    *p = nue;

    return TODO_OK;
}
int insertarPriListaD(tListaD *p, const void *elem, unsigned tam)
{
    tNodoD *nue;
    if(!p || !elem || tam == 0)
        return ERROR;

    nue = crearNodoDoble(elem, tam);
    if(!nue)
        return ERR_MEM;

    if(*p)
    {
        while((*p)->ant)
            *p = (*p)->ant;

        (*p)->ant = nue;
        nue->sig = *p;
    }
    *p = nue;

    return TODO_OK;
}
int insertarUltListaD(tListaD *p, const void *elem, unsigned tam)
{
    tNodoD *nue;
    if(!p || !elem || tam == 0) return ERROR;

    nue = crearNodoDoble(elem, tam);
    if(!nue) return ERR_MEM;

    if(*p)
    {
        while((*p)->sig)
            *p = (*p)->sig;

        (*p)->sig = nue;
        nue->ant = *p;
    }
    *p = nue;
    return TODO_OK;
}
int eliminarDeListaD(tListaD *p, void *elem, Comparar cmp)
{
    tNodoD *nAct;

    if(!p || !*p || !elem || !cmp)
        return ERROR;

    nAct = *p;
    while(nAct->sig != NULL && cmp(elem, nAct->dato) > 0)
        nAct = nAct->sig;
    while(nAct->ant != NULL && cmp(elem, nAct->dato) < 0)
        nAct = nAct->ant;

    if(cmp(elem, nAct->dato) != 0)
        return NO_ENCONTRADO;

    if(nAct->ant)
        nAct->ant->sig = nAct->sig;
    if(nAct->sig)
        nAct->sig->ant = nAct->ant;

    if(nAct->sig)
        *p = nAct->sig;
    else
        *p = nAct->ant;

    free(nAct->dato);
    free(nAct);
    return TODO_OK;
}
int eliminarPriListaD(tListaD *p, void *elem, unsigned tam)
{
    tNodoD *aux;
    if(!p || !*p)
        return ERROR;

    while((*p)->ant)
        *p = (*p)->ant;

    aux = *p;
    memcpy(elem, aux->dato, MIN(tam, aux->tam));
    *p = aux->sig;

    if(*p)
        (*p)->ant = NULL;

    free(aux->dato);
    free(aux);
    return TODO_OK;
}
int eliminarUltListaD(tListaD *p, void *elem, unsigned tam)
{
    tNodoD *aux;
    if(!p || !*p)
        return ERROR;

    while((*p)->sig)
        *p = (*p)->sig;

    aux = *p;
    memcpy(elem, aux->dato, MIN(tam, aux->tam));
    *p = aux->ant;

    if(*p)
        (*p)->sig = NULL;

    free(aux->dato);
    free(aux);
    return TODO_OK;
}
int irAlInicioD(tListaD *p)
{
    if(!p || !*p)
        return ERROR;

    while((*p)->ant)
        *p = (*p)->ant;

    return TODO_OK;
}
int irAlFinalD(tListaD *p)
{
    if(!p || !*p)
        return ERROR;

    while((*p)->sig)
        *p = (*p)->sig;

    return TODO_OK;
}
int verActualD(const tListaD *p, void *elem, unsigned tam)
{
    if(!p || !*p || !elem)
        return ERROR;

    memcpy(elem, (*p)->dato, MIN(tam, (*p)->tam));

    return TODO_OK;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarListaD(tListaD *p, int orden, Mostrar mostrar)
{
    tNodoD *aux;
    if(!p || !*p || !mostrar)
        return;

    aux = *p;

    if(orden == ASCD)
    {
        while(aux->ant)
            aux = aux->ant;
        while(aux->sig)
        {
            mostrar(aux->dato);
            printf(" | ");
            aux = aux->sig;
        }
        mostrar(aux->dato);
    }
    else
    {
        while(aux->sig)
            aux = aux->sig;
        while(aux->ant)
        {
            mostrar(aux->dato);
            printf(" | ");
            aux = aux->ant;
        }
        mostrar(aux->dato);
    }
}


