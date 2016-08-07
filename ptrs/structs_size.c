#include <stdio.h>
#include <malloc.h>

typedef struct elnodo{
    int tipo;
    struct elnodo* nodo0;    
    struct elnodo* nodo1;
    struct elnodo* nodo2;
    struct elnodo* nodo3;
    struct elnodo* nodo4;
    struct elnodo* nodo5;
}elnodo;

typedef struct ast{
    int tipo;
    struct ast* nodo0;    
    struct ast* nodo1;
}ast;

typedef struct nodo_si{
    int tipo;
    struct ast* cond;    
    struct ast* verd;
    struct ast* fals;
}nodo_si;

int main(int argc, char *argv[])
{
    elnodo *n1 = malloc(sizeof(elnodo));
    ast *a = malloc(sizeof(ast));
    nodo_si *si = malloc(sizeof(nodo_si));

    printf("el tamaño es: %ld\n", sizeof(struct elnodo));
    printf("el tamaño es: %ld\n", sizeof(struct ast));
    printf("el tamaño es: %ld\n", sizeof(struct nodo_si));

    printf("n1 esta en %p\n", &n1);
    printf("a esta en %p\n", &a);
    printf("si esta en %p\n", &si);

    a = (ast*)si;
    printf("a esta en %p\n", &a);
    printf("si esta en %p\n", &si);
    printf("nodo0 esta en %p\n", &(a->nodo0));
    printf("cond esta en %p\n", &(a->cond));
    
    return 0;
}
