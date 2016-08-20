#include <stdio.h>
#include "list.h"

int main(int argc, char *argv[])
{
    List* lista = List_create();
    int i;
    for (i = 0; i < 1000000; ++i) {
        printf("%i\n", i);
        List_push(lista, (void*) i);
    }

    return 0;
}
