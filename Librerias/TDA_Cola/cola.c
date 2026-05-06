#include "cola.h"

/*#define ESTATICA*/
#ifdef ESTATICA

void crearCola(tCola* cola)
{
    cola->primero = 0;
    cola->ultimo = 0;
    cola->tam = 0;
}
void vaciarCola(tCola* cola)
{
    cola->primero = 0;
    cola->ultimo = 0;
    cola->tam = 0;
}
int colaLlena(const tCola* cola)
{
    return cola->tam + sizeof(unsigned)>= MAX_TAM;
}
int colaVacia(const tCola* cola)
{
    return cola->tam == 0;
}
int ponerEnCola(tCola* cola, const void* elem, unsigned tam)
{
    if(!cola || !elem || tam == 0)
        return ERROR;

    if(cola->tam + sizeof(unsigned) + tam > MAX_TAM)
        return ERR_MEM;

    unsigned parte;

    parte = MIN(sizeof(unsigned), MAX_TAM - cola->ultimo);
    memcpy(cola->cola + cola->ultimo, (const char*)&tam, parte);
    if (parte != sizeof(unsigned))
        memcpy(cola->cola, (const char*)&tam + parte, sizeof(unsigned) - parte);

    cola->ultimo = (cola->ultimo + sizeof(unsigned)) % MAX_TAM;

    parte = MIN(tam, MAX_TAM - cola->ultimo);
    memcpy(cola->cola + cola->ultimo, (const char*)elem, parte);
    if (parte != tam)
        memcpy(cola->cola, (const char*)elem + parte, tam - parte);

    cola->ultimo = (cola->ultimo + tam) % MAX_TAM;
    cola->tam += (sizeof(unsigned) + tam);

    return TODO_OK;
}
int sacarDeCola(tCola* cola, void* elem, unsigned tam)
{
    if(!cola || !elem || tam == 0 || cola->tam == 0)
        return ERROR;

    unsigned tamElem, parte, aCopiar;

    parte = MIN(sizeof(unsigned), MAX_TAM - cola->primero);

    memcpy((char*)&tamElem, cola->cola + cola->primero, parte);
    if(parte != sizeof(unsigned))
        memcpy((char*)&tamElem + parte, cola->cola, sizeof(unsigned) - parte);

    cola->primero = (cola->primero + sizeof(unsigned)) % MAX_TAM;


    aCopiar = MIN(tam, tamElem);
    parte = MIN(tamElem, MAX_TAM - cola->primero);

    memcpy(elem, cola->cola + cola->primero, MIN(parte, aCopiar));
    if(parte != tamElem && aCopiar > parte)
        memcpy((char*)elem + parte, cola->cola, aCopiar - parte);

    cola->primero = (cola->primero + tamElem) % MAX_TAM;
    cola->tam -= (sizeof(unsigned) + tamElem);

    return TODO_OK;
}
int vecPrimero(const tCola* cola, void* elem, unsigned tam)
{
    if(!cola || !elem || tam == 0 || cola->tam == 0)
        return ERROR;

    unsigned tamElem, parte, aCopiar, posDato;

    parte = MIN(sizeof(unsigned), MAX_TAM - cola->primero);
    memcpy((char*)&tamElem, cola->cola + cola->primero, parte);
    if(parte != sizeof(unsigned))
        memcpy((char*)&tamElem + parte, cola->cola, sizeof(unsigned) - parte);

    posDato = (cola->primero + sizeof(unsigned)) % MAX_TAM;

    aCopiar = MIN(tam, tamElem);
    parte = MIN(tamElem, MAX_TAM - posDato);

    memcpy(elem, cola->cola + posDato, MIN(parte, aCopiar));
    if(parte != tamElem && aCopiar > parte)
        memcpy((char*)elem + parte, cola->cola, aCopiar - parte);

    return TODO_OK;
}

#else

void crearCola(tCola* cola)
{
    cola->pri = NULL;
}
void vaciarCola(tCola* cola)
{
    tNodo* elim;

    while(cola->pri != NULL)
    {
        elim = cola->pri;
        cola->pri = cola->pri->sigN;
        free(elim->dato);
        free(elim);
    }
    cola->ult = NULL;
}
int colaLlena(const tCola* cola)
{
    return TODO_OK;
}
int colaVacia(const tCola* cola)
{
    return cola->pri == NULL ? 1 : 0;
}
int ponerEnCola(tCola* cola, const void* elem, unsigned tam)
{
    if(!cola || !elem || tam == 0)
        return ERROR;

    tNodo* nuevo = malloc(sizeof(tNodo));
    if(!nuevo)
        return ERR_MEM;

    nuevo->dato = malloc(tam);
    if(!nuevo->dato)
    {
        free(nuevo);
        return ERR_MEM;
    }

    nuevo->tam = tam;
    nuevo->sigN = NULL;
    memcpy(nuevo->dato, elem, tam);

    if(cola->pri == NULL)
        cola->pri = nuevo;
    else
        cola->ult->sigN = nuevo;

    cola->ult = nuevo;

    return TODO_OK;
}
int sacarDeCola(tCola* cola, void* elem, unsigned tam)
{
    if(!cola || !elem || tam == 0 || cola->pri == NULL)
        return ERROR;

    tNodo* elim = cola->pri;
    memcpy(elem, elim->dato, MIN(tam, elim->tam));
    cola->pri = elim->sigN;

    if(cola->pri == NULL)
        cola->ult = NULL;

    free(elim->dato);
    free(elim);
    return TODO_OK;
}
int vecPrimero(const tCola* cola, void* elem, unsigned tam)
{
    if(!cola || !elem || tam == 0 || cola->pri == NULL)
        return ERROR;

    memcpy(elem, cola->pri->dato, MIN(tam, cola->pri->tam));

    return TODO_OK;
}

#endif /*ESTATICA*/


