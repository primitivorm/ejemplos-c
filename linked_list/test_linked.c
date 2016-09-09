#include <stdio.h>
#include "list.h"

void list_print(List *list){
  LIST_FOREACH(list, first, next, cur) {
      printf("%i\n", (int)cur->value);
  }
}

int main(int argc, char *argv[])
{
    int val;
    List* lista = List_create();
    //test push
    printf("%s\n", "test push");
    List_push(lista, (void*) 0);
    List_push(lista, (void*) 1);
    List_push(lista, (void*) 2);
    List_push(lista, (void*) 3);
    List_push(lista, (void*) 4);
    List_push(lista, (void*) 5);
    list_print(lista);
    //test pop
    printf("%s\n", "test pop");
    val = (int) List_pop(lista);
    printf("pop value: %i\n", val);
    list_print(lista);
    printf("%s\n", "test unshift");
    List_unshift(lista, 6);
    list_print(lista);
    printf("%s\n", "test shift");
    val = (int) List_shift(lista);
    list_print(lista);
    printf("shift value: %i\n", val);
    printf("%s\n", "test remove");
    /*
    List_remove(lista, lista->first->next);
    List_remove(lista, lista->last->prev);
    list_print(lista);
    */
    LIST_FOREACH(list, first, next, cur) {
        List_remove(list, cur);
    }
    list_print(lista);

    int cnt = List_count(lista);
    printf("lista length: %i\n", cnt);

    List_destroy(lista);
    /*int i;
    for (i = 0; i < 1000000; ++i) {
        printf("%i\n", i);
        List_push(lista, (void*) i);
    }*/
    return 0;
}
