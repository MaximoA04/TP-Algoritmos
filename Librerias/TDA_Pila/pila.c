#include "pila.h"

/*#define ESTATICA*/

#ifdef ESTATICA

void crearPila(tPila* p)
{
    if (!p)
        return;
    p->tope = TAM_PILA;
}
void destruirPila(tPila* p)
{
    if(!p)
        return;
    p->tope = 0;
}
int pilaLlena(const tPila* p, unsigned tam)
{
    if(p->tope <= tam + sizeof(unsigned))
        return 1;
    return 0;
}
int pilaVacia(const tPila* p)
{
    if(p->tope == TAM_PILA)
        return 1;
    return 0;
}
int apilar(tPila* p, const void* elem, unsigned tam)
{
    if(!p || !elem || tam == 0 || p->tope < tam + sizeof(unsigned))
        return ERROR;

    p->tope -= tam;
    memcpy(p->pila + p->tope, elem, tam);
    p->tope -= sizeof(unsigned);
    memcpy(p->pila + p->tope, &tam, sizeof(unsigned));

    return TODO_OK;
}
int desapilar(tPila* p, void* elem, unsigned tam)
{
    if(!p || !elem || tam == 0 || p->tope == TAM_PILA)
        return ERROR;

    unsigned tamElemP;
    memcpy(&tamElemP, p->pila + p->tope, sizeof(unsigned));
    p->tope += sizeof(unsigned);
    memcpy(elem, p->pila + p->tope, MIN(tam, tamElemP));
    p->tope += tamElemP;

    return TODO_OK;
}
int verTope(const tPila* p, void* elem, unsigned tam)
{
    if(!p || !elem || tam == 0 || p->tope == TAM_PILA)
        return ERROR;

    unsigned tamElemP;
    memcpy(&tamElemP, p->pila + p->tope, sizeof(unsigned));
    memcpy(elem, p->pila + p->tope + sizeof(unsigned), MIN(tam, tamElemP));

    return TODO_OK;
}

#else

void crearPila(tPila* p)
{
    *p = NULL;
}
void destruirPila(tPila* p)
{
    tNodo* nodo;

    while(*p != NULL)
    {
        nodo = *p;
        *p = nodo->sigN;

        free(nodo->dato);
        free(nodo);
    }
}
int pilaLlena(const tPila* p, unsigned tam)
{
    void* nodo = malloc(sizeof(tNodo));
    void* dato = malloc(tam);

    if (nodo == NULL || dato == NULL)
    {
        free(nodo);
        free(dato);
        return ERROR;
    }

    free(nodo);
    free(dato);
    return TODO_OK;
}
int pilaVacia(const tPila* p)
{
    return *p == NULL;
}
int apilar(tPila* p, const void* elem, unsigned tam)
{
    tNodo* nuevo = malloc(sizeof(tNodo));
    if (!nuevo)
        return ERR_MEM;

    nuevo->dato = malloc(tam);
    if(!nuevo->dato)
        return ERR_MEM;

    memcpy(nuevo->dato, elem, tam);
    nuevo->tam = tam;
    nuevo->sigN = *p;
    *p = nuevo;

    return TODO_OK;
}
int desapilar(tPila* p, void* elem, unsigned tam)
{
    if(*p == NULL)
        return ERROR;

    tNodo* nodo = *p;

    memcpy(elem, nodo->dato, MIN(tam, nodo->tam));
    *p = nodo->sigN;

    free(nodo->dato);
    free(nodo);
    return TODO_OK;
}
int verTope(const tPila* p, void* elem, unsigned tam)
{
    if(*p == NULL)
        return ERROR;

    memcpy(elem, (*p)->dato, MIN(tam, (*p)->tam));

    return TODO_OK;
}

#endif /*ESTATICA*/




