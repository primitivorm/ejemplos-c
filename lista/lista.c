#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/*crea una lista vacia*/
lista_nodo* lista_nueva()
{
    //asigna memoria para el primer elemento de la lista
    lista_nodo* nodo = (lista_nodo*) malloc(sizeof(lista_nodo));
    nodo->previo = NULL;
    nodo->siguiente = NULL;
    nodo->info = NULL;
    return nodo;
}

/*Agrega al final de la lista*/
void lista_agregar(lista_nodo* nodo, void* info)
{
    printf("insertando %i\n", info);
    lista_nodo* actual = nodo;
    //si hay valores en la lista ir al ultimo elemento
    while(actual->siguiente != NULL){
        actual = actual->siguiente;
    }
    actual->info = info;
    actual->siguiente = (lista_nodo*) malloc(sizeof(lista_nodo));
    actual->siguiente->previo = actual->siguiente;
    actual->siguiente->siguiente = NULL;
    actual->siguiente->info = NULL;
}

void lista_eliminar(lista_nodo* nodo, void* info)
{

}

/*regresa el numero de elementos de la lista*/
int lista_longitud(lista_nodo* nodo)
{
    int num = 0;
    lista_nodo* actual = nodo;
    while (actual->siguiente != NULL)
    {
        num++;
        actual = actual->siguiente;
    }
    return num;
}

