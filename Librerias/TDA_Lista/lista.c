#include "lista.h"

void crearLista(tLista *p)
{
    *p = NULL;
}
void vaciarLista(tLista *p)
{
    while(*p)
    {
        tNodo *aux = *p;
        *p = aux->sigN;

        free(aux->dato);
        free(aux);
    }
}
int listaLlena(const tLista *p)
{
    return TODO_OK;
}
int listaVacia(const tLista *p)
{
    return *p == NULL;
}
int insertarAlComienzo(tLista *p, const void *elem, unsigned tam)
{
    if(!p || !elem || tam == 0)
        return ERROR;

    tNodo *nue = crearNodo(elem, tam);
    if (!nue)
        return ERR_MEM;

    nue->sigN = *p;
    *p = nue;

    return TODO_OK;
}
int insertarAlFinal(tLista *p, const void *elem, unsigned tam)
{
    if(!p || !elem || tam == 0)
        return ERROR;

    tNodo *nue = crearNodo(elem, tam);
    if (!nue)
        return ERR_MEM;

    while(*p)
        p = &(*p)->sigN;
    *p = nue;

    return TODO_OK;
}
int insertarOrdenado(tLista *p, const void *elem, unsigned tam, int conDup, Comparar cmp, Accion acc)
{
    int res;

    while (*p && (res = cmp(elem, (*p)->dato)) > 0)
        p = &(*p)->sigN;

    if (*p && res == 0)
    {
        if (acc)
            acc((*p)->dato, elem);
        if (!conDup)
            return TODO_OK;
    }
    tNodo *nue = crearNodo(elem, tam);
    if (!nue)
        return ERR_MEM;

    nue->sigN = *p;
    *p = nue;

    return TODO_OK;
}
int eliminarPrimeroLista(tLista *p, void *elem, unsigned tam)
{
    if(!p || !*p || !elem || tam == 0)
        return ERROR;

    tNodo *elim  = *p;

    *p = elim->sigN;
    memcpy(elem, elim->dato, MIN(tam, elim->tam));

    free(elim->dato);
    free(elim);
    return TODO_OK;
}
int eliminarUltimoLista(tLista *p, void *elem, unsigned tam)
{
    if(!p || !*p || !elem || tam == 0)
        return ERROR;

    while((*p)->sigN)
        p = &(*p)->sigN;

    tNodo *elim = *p;
    memcpy(elem, elim->dato, MIN(tam, elim->tam));
    *p = NULL;

    free(elim->dato);
    free(elim);
    return TODO_OK;
}
int eliminarSinOrden(tLista *p, void *elem, Comparar cmp)
{
    if(!p || !cmp)
        return ERROR;

    tNodo *elim;

    while (*p)
    {
        if (cmp((*p)->dato, elem) == 0)
        {
            elim = *p;
            *p = elim->sigN;
            free(elim->dato);
            free(elim);
        }
        else
            p = &(*p)->sigN;
    }
    return TODO_OK;
}
int eliminarOrdenado(tLista *p, void *elem, Comparar cmp)
{
    if(!p || !cmp)
        return ERROR;

    tNodo *elim;
    int res;

    while (*p && (res = cmp((*p)->dato, elem)) <= 0)
    {
        if (res == 0)
        {
            elim = *p;
            *p = elim->sigN;
            free(elim->dato);
            free(elim);
        }
        else
            p = &(*p)->sigN;
    }
    return TODO_OK;
}
int ordenarLista(tLista *p, Comparar cmp)
{
    if(!p || *p == NULL || !cmp)
        return ERROR;

    tNodo *i, *j, *min;
    void *auxDato;

    for (i = *p; i->sigN; i = i->sigN)
    {
        min = i;
        for (j = i->sigN; j; j = j->sigN)
            if (cmp(min->dato, j->dato) > 0)
                min = j;

        if (min != i)
        {
            auxDato = i->dato;
            i->dato = min->dato;
            min->dato = auxDato;
        }
    }
    return TODO_OK;
}
int vecPrimeroLista(const tLista *p, void *elem, unsigned tam)
{
    if(!p || !*p || !elem || tam == 0)
        return ERROR;

    tNodo *aux  = *p;
    memcpy(elem, aux->dato, MIN(tam, aux->tam));

    return TODO_OK;
}
int vecUltimoLista(const tLista *p, void *elem, unsigned tam)
{
    if(!p || !*p || !elem || tam == 0)
        return ERROR;

    while((*p)->sigN)
        p = &(*p)->sigN;

    tNodo *aux = *p;
    memcpy(elem, aux->dato, MIN(tam, aux->tam));

    return TODO_OK;
}
void mostrarLista(const tLista *p, Mostrar f_Mostrar)
{
    if(!p)
        return;
    while((*p)->sigN)
    {
        f_Mostrar((*p)->dato);
        printf(" | ");
        p = &(*p)->sigN;
    }
    f_Mostrar((*p)->dato);
}


