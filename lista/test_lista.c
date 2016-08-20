#include <stdio.h>
#include <limits.h>
#include "lista.h"

typedef struct info{
    int entero;
}info;


static void lista_imprimir(lista_nodo* lista){
    lista_nodo* actual = lista;
    while(actual->siguiente != NULL){
        printf("%i\n", actual->info);
        actual = actual->siguiente;
    }
}

/*implementacion de lista muy ineficiente*/
int main(int argc, char *argv[])
{
    lista_nodo* lista = lista_nueva();
    //printf("longitud de la lista: %i\n", lista_longitud(lista));
    int i;
    printf("int_max: %i\n", INT_MAX);
    for (i = 0; i < 1000000; ++i) {
        lista_agregar(lista, (void*) i);
    }
    lista_imprimir(lista);
    printf("longitud de la lista: %i", lista_longitud(lista));
    return 0;
}
