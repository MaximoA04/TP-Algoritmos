#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#include "cola.h"
#include "lista.h"
#include "listaCircular.h"
#include "listaDoble.h"

#ifdef _WIN32
#include <windows.h>
#define LIMPIAR_PANTALLA system("cls")
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
#else
#define LIMPIAR_PANTALLA system("clear")
#endif

/* DEFINES DE COLORES */
#define RESET  "\x1b[0m"
#define ROJO   "\x1b[31m"
#define VERDE  "\x1b[32m"
#define AMAR   "\x1b[33m"
#define AZUL   "\x1b[34m"
#define MAG    "\x1b[35m"
#define CYAN   "\x1b[36m"
#define BOLD   "\x1b[1m"

void subMenuPila();
void subMenuCola();
void subMenuLista();
void subMenuListaCircular();
void subMenuListaDoble();
void pausa();

int compararInt(const void* a, const void* b);
void mostrarInt(const void* a);

int main()
{
#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut != INVALID_HANDLE_VALUE)
    {
        DWORD dwMode = 0;
        if (GetConsoleMode(hOut, &dwMode))
        {
            dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
            SetConsoleMode(hOut, dwMode);
        }
    }
#endif

    int opcion = -1;
    int leidos;

    while (opcion != 0)
    {
        LIMPIAR_PANTALLA;
        printf(AZUL "=======================================");
        printf("\n            MENU DE PRUEBAS          \n");
        printf("=======================================\n" RESET);
        printf("\n" CYAN "1. PROBAR PILA" RESET);
        printf("\n" CYAN "2. PROBAR COLA" RESET);
        printf("\n" CYAN "3. PROBAR LISTA" RESET);
        printf("\n" CYAN "4. PROBAR LISTA CICULAR" RESET);
        printf("\n" CYAN "5. PROBAR LISTA DOBLE" RESET);
        printf("\n" ROJO "0. SALIR" RESET);
        printf("\n\nSeleccione una opcion: ");

        leidos = scanf("%d", &opcion);

        if (leidos != 1)
        {
            while(getchar() != '\n');
            opcion = -1;
        }

        switch (opcion)
        {
        case 1:
            subMenuPila();
            break;
        case 2:
            subMenuCola();
            break;
        case 3:
            subMenuLista();
            break;
        case 4:
            subMenuListaCircular();
            break;
        case 5:
            subMenuListaDoble();
            break;
        case 0:
            printf(MAG "\nFinalizando programa...\n" RESET);
            break;
        default:
            if(opcion != -1)
            {
                printf(ROJO "Opcion invalida.\n" RESET);
                pausa();
            }
        }
    }

    return TODO_OK;
}

//////////////////////////////////////////////////////////////////////////////////////////////
void pausa()
{
    printf(MAG "\nPresione Enter para continuar..." RESET);
    fflush(stdin);
    getchar();
    if(getchar()) {}
}
void subMenuPila()
{
    tPila pila;
    crearPila(&pila);
    int op, dato;

    do
    {
        LIMPIAR_PANTALLA;
        printf(AZUL "\n--- MODULO PILA ---\n" RESET);
        printf(CYAN "\n1. Apilar (int)"
               "\n2. Desapilar"
               "\n3. Ver Tope"
               "\n4. Vaciar Pila"
               "\n" ROJO "0. Volver" RESET
               "\n\nOpcion: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Ingrese entero: ");
            scanf("%d", &dato);
            if (apilar(&pila, &dato, sizeof(int)) == TODO_OK)
                printf(VERDE "Ok.\n" RESET);
            else
                printf(ROJO "Error (Pila llena).\n" RESET);
            pausa();
            break;
        case 2:
            if (desapilar(&pila, &dato, sizeof(int)) == TODO_OK)
                printf(VERDE "Sacado: %d\n" RESET, dato);
            else
                printf(AMAR "Pila vacia.\n" RESET);
            pausa();
            break;
        case 3:
            if (verTope(&pila, &dato, sizeof(int)) == TODO_OK)
                printf(VERDE "Tope: %d\n" RESET, dato);
            else
                printf(AMAR "Pila vacia.\n" RESET);
            pausa();
            break;
        case 4:
            destruirPila(&pila);
            printf(MAG "Pila destruida.\n" RESET);
            pausa();
            break;
        case 0:
            destruirPila(&pila);
            break;
        default:
            printf(ROJO "Opcion invalida.\n" RESET);
            pausa();
        }
    }
    while (op != 0);
}
void subMenuCola()
{
    tCola cola;
    crearCola(&cola);
    int op, dato;

    do
    {
        LIMPIAR_PANTALLA;
        printf(AZUL "\n--- MODULO COLA ---\n" RESET);
        printf(CYAN "\n1. Poner en Cola"
               "\n2. Sacar de Cola"
               "\n3. Ver Primero"
               "\n4. Vaciar Cola"
               "\n" ROJO "0. Volver" RESET
               "\n\nOpcion: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Ingrese entero: ");
            scanf("%d", &dato);
            if (ponerEnCola(&cola, &dato, sizeof(int)) == TODO_OK)
                printf(VERDE "Ok.\n" RESET);
            else
                printf(ROJO "Error (Cola llena).\n" RESET);
            pausa();
            break;
        case 2:
            if (sacarDeCola(&cola, &dato, sizeof(int)) == TODO_OK)
                printf(VERDE "Sacado: %d\n" RESET, dato);
            else
                printf(AMAR "Cola vacia.\n" RESET);
            pausa();
            break;
        case 3:
            if (vecPrimero(&cola, &dato, sizeof(int)) == TODO_OK)
                printf(VERDE "Primero: %d\n" RESET, dato);
            else
                printf(AMAR "Cola vacia.\n" RESET);
            pausa();
            break;
        case 4:
            vaciarCola(&cola);
            printf(MAG "Cola vaciada.\n" RESET);
            pausa();
            break;
        case 0:
            vaciarCola(&cola);
            break;
        default:
            printf(ROJO "Opcion invalida.\n" RESET);
            pausa();
        }
    }
    while (op != 0);
}
void subMenuLista()
{
    tLista lista;
    crearLista(&lista);
    int op, dato, clave;

    do
    {
        LIMPIAR_PANTALLA;
        printf(AZUL "\n--- MODULO LISTA ---\n" RESET);
        printf(CYAN "\n1. Insertar Comienzo"
               "\n2. Insertar Final"
               "\n3. Insertar Ordenado"
               "\n4. Eliminar Primero"
               "\n5. Eliminar Ultimo"
               "\n6. Eliminar Sin Orden"
               "\n7. Ordenar Lista"
               "\n8. Mostrar Lista"
               "\n9. Vaciar Lista"
               "\n" ROJO "0. Volver" RESET
               "\n\nOpcion: ");

        if (scanf("%d", &op) != 1)
        {
            while(getchar() != '\n');
            op = -1;
        }

        switch (op)
        {
        case 1:
            printf("Dato: ");
            scanf("%d", &dato);
            insertarAlComienzo(&lista, &dato, sizeof(int));
            printf(VERDE "Agregado.\n" RESET);
            pausa();
            break;
        case 2:
            printf("Dato: ");
            scanf("%d", &dato);
            insertarAlFinal(&lista, &dato, sizeof(int));
            printf(VERDE "Agregado.\n" RESET);
            pausa();
            break;
        case 3:
            printf("Dato: ");
            scanf("%d", &dato);
            insertarOrdenado(&lista, &dato, sizeof(int), 0, compararInt, NULL);
            printf(VERDE "Agregado.\n" RESET);
            pausa();
            break;
        case 4:
            if (eliminarPrimeroLista(&lista, &dato, sizeof(int)) == TODO_OK)
                printf(VERDE "Eliminado: %d\n" RESET, dato);
            else
                printf(AMAR "Vacia.\n" RESET);
            pausa();
            break;
        case 5:
            if (eliminarUltimoLista(&lista, &dato, sizeof(int)) == TODO_OK)
                printf(VERDE "Eliminado: %d\n" RESET, dato);
            else
                printf(AMAR "Vacia.\n" RESET);
            pausa();
            break;
        case 6:
            printf("Valor a eliminar: ");
            scanf("%d", &clave);
            if (eliminarSinOrden(&lista, &clave, compararInt) == TODO_OK)
                printf(VERDE "Eliminado.\n" RESET);
            else
                printf(AMAR "No encontrado.\n" RESET);
            pausa();
            break;
        case 7:
            if (ordenarLista(&lista, compararInt) == TODO_OK)
                printf(VERDE "Ordenada.\n" RESET);
            pausa();
            break;
        case 8:
            printf(VERDE "Lista: [ " RESET);
            mostrarLista(&lista, mostrarInt);
            printf(VERDE " ]\n" RESET);
            pausa();
            break;
        case 9:
            vaciarLista(&lista);
            printf(VERDE "Lista vaciada.\n" RESET);
            pausa();
            break;
        case 0:
            vaciarLista(&lista);
            break;
        default:
            printf(ROJO "Opcion invalida.\n" RESET);
        }
    }
    while (op != 0);
}
void subMenuListaCircular()
{
    tListaC listaC;
    crearListaC(&listaC);
    int op, dato, res;

    do
    {
        LIMPIAR_PANTALLA;
        printf(AZUL "\n--- MODULO LISTA CIRCULAR ---\n" RESET);
        printf(CYAN "\n1. Insertar Ordenado"
               "\n2. Insertar al Principio (Push Pila/Cola)"
               "\n3. Insertar al Final (Encolar)"
               "\n4. Eliminar Especifico"
               "\n5. Eliminar Primero (Pop Pila/Desacolar)"
               "\n6. Eliminar Ultimo"
               "\n7. Mostrar Lista"
               "\n8. Vaciar Lista"
               "\n" ROJO "0. Volver" RESET
               "\n\nOpcion: ");

        if (scanf("%d", &op) != 1)
        {
            while(getchar() != '\n');
            op = -1;
        }

        switch (op)
        {
        case 1:
            printf("Dato: ");
            scanf("%d", &dato);
            res = insertarEnListaC(&listaC, &dato, sizeof(int), compararInt);
            printf(res == TODO_OK ? VERDE "Agregado.\n" RESET : ROJO "Error en la insercion.\n" RESET);
            pausa();
            break;
        case 2:
            printf("Dato: ");
            scanf("%d", &dato);
            res = insertarPriC(&listaC, &dato, sizeof(int));
            printf(res == TODO_OK ? VERDE "Agregado.\n" RESET : ROJO "Error en la insercion.\n" RESET);
            pausa();
            break;
        case 3:
            printf("Dato: ");
            scanf("%d", &dato);
            res = insertarUltC(&listaC, &dato, sizeof(int));
            printf(res == TODO_OK ? VERDE "Agregado.\n" RESET : ROJO "Error en la insercion.\n" RESET);
            pausa();
            break;
        case 4:
            printf("Dato a eliminar: ");
            scanf("%d", &dato);
            res = eliminarElemC(&listaC, &dato, sizeof(int), compararInt);
            if(res == TODO_OK)
                printf(VERDE "Elemento %d eliminado.\n" RESET, dato);
            else
                printf(AMAR "No se encontro el dato.\n" RESET);
            pausa();
            break;
        case 5:
            res = eliminarPriC(&listaC, &dato, sizeof(int));
            if(res == TODO_OK)
                printf(VERDE "Eliminado primero: %d\n" RESET, dato);
            else
                printf(ROJO "Lista vacia.\n" RESET);
            pausa();
            break;
        case 6:
            res = eliminarUltC(&listaC, &dato, sizeof(int));
            if(res == TODO_OK)
                printf(VERDE "Eliminado ultimo: %d\n" RESET, dato);
            else
                printf(ROJO "Lista vacia.\n" RESET);
            pausa();
            break;
        case 7:
            printf(VERDE "Lista (ASCD): [ " RESET);
            mostrarListaC(&listaC, mostrarInt);
            printf(VERDE " ]\n" RESET);
            pausa();
            break;
        case 8:
            vaciarListaC(&listaC);
            printf(AMAR "Lista vaciada.\n" RESET);
            pausa();
            break;
        case 0:
            vaciarListaC(&listaC);
            break;
        default:
            printf(ROJO "Opcion invalida.\n" RESET);
            pausa();
        }
    }
    while (op != 0);
}
void subMenuListaDoble()
{
    tListaD listaD;
    crearListaD(&listaD);
    int op, dato, res;

    do
    {
        LIMPIAR_PANTALLA;
        printf(AZUL "\n--- MODULO LISTA ---\n" RESET);
        printf(CYAN "\n1. Insertar Ordenado"
               "\n2. Insertar al Principio"
               "\n3. Insertar al Final"
               "\n4. Eliminar Especifico"
               "\n5. Eliminar Primero"
               "\n6. Eliminar Ultimo"
               "\n7. Mostrar Ascendente"
               "\n8. Mostrar Descendente"
               "\n9. Vaciar Lista"
               "\n" ROJO "0. Volver" RESET
               "\n\nOpcion: ");

        if (scanf("%d", &op) != 1)
        {
            while(getchar() != '\n');
            op = -1;
        }

        switch (op)
        {
        case 1:
            printf("Dato: ");
            scanf("%d", &dato);
            res = insertarEnListaD(&listaD, &dato, sizeof(int), 1, compararInt, NULL);
            printf(res == TODO_OK ? VERDE "Agregado.\n" RESET : ROJO "Error en la insercion.\n" RESET);
            pausa();
            break;
        case 2:
            printf("Dato: ");
            scanf("%d", &dato);
            res = insertarPriListaD(&listaD, &dato, sizeof(int));
            printf(res == TODO_OK ? VERDE "Agregado al principio.\n" RESET : ROJO "Error en la insercion.\n" RESET);
            pausa();
            break;
        case 3:
            printf("Dato: ");
            scanf("%d", &dato);
            res = insertarUltListaD(&listaD, &dato, sizeof(int));
            printf(res == TODO_OK ? VERDE "Agregado al final.\n" RESET : ROJO "Error en la insercion.\n" RESET);
            pausa();
            break;
        case 4:
            printf("Dato a eliminar: ");
            scanf("%d", &dato);
            res = eliminarDeListaD(&listaD, &dato, compararInt);
            if(res == TODO_OK)
                printf(VERDE "Eliminado.\n" RESET);
            else
                printf(AMAR "No se encontro el dato.\n" RESET);
            pausa();
            break;
        case 5:
            res = eliminarPriListaD(&listaD, &dato, sizeof(int));
            if(res == TODO_OK)
                printf(VERDE "Se saco el primero: %d\n" RESET, dato);
            else
                printf(ROJO "Lista vacia.\n" RESET);
            pausa();
            break;
        case 6:
            res = eliminarUltListaD(&listaD, &dato, sizeof(int));
            if(res == TODO_OK)
                printf(VERDE "Se saco el ultimo: %d\n" RESET, dato);
            else
                printf(ROJO "Lista vacia.\n" RESET);
            pausa();
            break;
        case 7:
            printf(VERDE "Lista (ASCD): [ " RESET);
            mostrarListaD(&listaD, ASCD, mostrarInt);
            printf(VERDE " ]\n" RESET);
            pausa();
            break;
        case 8:
            printf(VERDE "Lista (DSCD): [ " RESET);
            mostrarListaD(&listaD, DSCD, mostrarInt);
            printf(VERDE " ]\n" RESET);
            pausa();
            break;
        case 9:
            vaciarListaD(&listaD);
            printf(AMAR "Lista vaciada.\n" RESET);
            pausa();
            break;
        case 0:
            vaciarListaD(&listaD);
            break;
        default:
            printf(ROJO "Opcion invalida.\n" RESET);
            pausa();
        }
    }
    while (op != 0);
}

//////////////////////////////////////////////////////////////////////////////////////////////
int compararInt(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}
void mostrarInt(const void* a)
{
    printf(AMAR "%d" RESET, *(int*)a);
}




