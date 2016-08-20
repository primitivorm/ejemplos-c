#include <stdio.h>
#include <stdbool.h>

struct foo1 {
    char *p;
    char c;
    long x;
};

struct foo2 {
    char c;      /* 1 byte */
    char pad[7]; /* 7 bytes */
    char *p;     /* 8 bytes */
    long x;      /* 8 bytes */
};

struct foo3 {
    char *p;     /* 8 bytes */
    char c;      /* 1 byte */
};

struct foo4 {
    short s;     /* 2 bytes */
    char c;      /* 1 byte */
};

struct foo5 {
    char c;
    struct foo5_inner {
        char *p;
        short x;
    } inner;
};

struct foo6 {
    short s;
    char c;
    int flip:1;
    int nybble:4;
    int septet:7;
};

struct foo7 {
    int bigfield:31;
    int littlefield:1;
};

struct foo8 {
    int bigfield1:31;
    int littlefield1:1;
    int bigfield2:31;
    int littlefield2:1;
};

struct foo9 {
    int bigfield1:31;
    int bigfield2:31;
    int littlefield1:1;
    int littlefield2:1;
};

struct foo10 {
    char c;
    struct foo10 *p;
    short x;
};

struct foo11 {
    struct foo11 *p;
    short x;
    char c;
};

struct foo12 {
    struct foo12_inner {
        char *p;
        short x;
    } inner;
    char c;
};

/** \brief Tipos de dato */
typedef enum {
    VALOR_NULO,    /**< Valor nulo */
    VALOR_LOGICO,  /**< Valor logico */
    VALOR_ENTERO,  /**< Valor entero */
    VALOR_LITERAL, /**< Valor literal */
    VALOR_DECIMAL, /**< Valor decimal */
    VALOR_CADENA   /**< Valor cadena */
} tipo_valor;

/** \brief Valores del dato */
typedef struct {
    tipo_valor t; /**< Nodo tipo valor */
    bool es_constante; /**< Para validar si es constante */
    int num_linea;     /**< Numero de linea */
    int num_columna;   /**< Numero de columna */
    /** Contiene los valores del dato*/
    union {
        int logico;    /**< Logico */
        long entero;   /**< Entero */
        double decimal; /**< Decimal */
        char* cadena;  /**< Cadena o literal */
    } vval;
} nodo_valor;

typedef enum {
    NODO_ASIGNACION,             /**< Nodo asignacion (variable = valor) */
    NODO_OPERADOR,               /**< Nodo operador (+ - * / % < <= > >= == != && ||) */
    NODO_IDENTIFICADOR,          /**< Nodo identificador */
    NODO_LOGICO,                 /**< Nodo logico */
    NODO_ENTERO,                 /**< Nodo entero */
    NODO_DECIMAL,                /**< Nodo decimal */
    NODO_CADENA,                 /**< Nodo cadena */
    NODO_LITERAL,                /**< Nodo literal */
    NODO_BLOQUE,                 /**< Nodo bloque */
    NODO_SI,                     /**< Nodo si */
    NODO_MIENTRAS,               /**< Nodo mientras */
    NODO_REPETIR,                /**< Nodo repetir */
    NODO_PORCADA,                /**< Nodo por cada */
    NODO_FUNCION_PARAMETROS,       /**< Nodo parametros (suma(a, b))*/
    NODO_FUNCION_ARGUMENTOS,     /**< Nodo argumentos de una funcion (funcion suma(1, b)) */
    NODO_FUNCION_LLAMADA,        /**< Nodo llamada a una funcion (suma(2,3)) */
    NODO_FUNCION_USUARIO,        /**< Nodo definicion de una funcion de usuario*/
    NODO_RETORNO,                /**< Nodo retorno */
    NODO_ROMPER,                 /**< Nodo romper */
    NODO_CONTINUAR,              /**< Nodo continuar */
    NODO_CONCATENAR,             /**< Nodo concatenar */
    NODO_LISTA,                  /**< Nodo lista nueva */
    NODO_LISTA_ASIGNAR_ELEMENTO, /**< Nodo asignar un nuevo valor a un elemento de la lista (lista[0] = 10)*/
    NODO_LISTA_AGREGAR_ELEMENTO, /**< Nodo agregar elemento a una lista (1,2,3,X)*/
    NODO_LISTA_OBTENER_ELEMENTO, /**< Nodo obtener un elemento de una lista (num = lista[0])*/
    NODO_DICCIONARIO,            /**< Nodo diccionario nuevo */
    NODO_DICC_ASIGNAR_ELEMENTO,  /**< Nodo un nuevo valor a un elemento del diccionario (dic["uno"] = valor)*/
    NODO_DICC_AGREGAR_ELEMENTO,  /**< Nodo agregar un elemento al diccionario {"uno":1, "dos":2, "tres":3, "xxx": n} */
    NODO_DICC_OBTENER_ELEMENTO,  /**< Nodo obtener un elemento del diccionario (valor = dic["uno"]) */
    NODO_DICC_ELEMENTO,          /**< Nodo par de llave valor del diccionario (key : value) */
    NODO_INCLUIR                 /**< Nodo para incluir codigo de otro archivo */
} nodo_tipo;

/** \brief Nodos en arbol abstacto de sintaxis (Abstract Syntax Tree).
  *
  * Todos los nodos son inicializados con un tipo de nodo */
typedef struct ast {
    nodo_tipo tipo;    /**< Tipo de nodo */
    nodo_valor* valor; /**< Valor del nodo */
    char* operador;    /**< operador en caso de que sea un nodo operador */
    struct ast* izquierdo;     /**< Nodo izquierdo */
    struct ast* derecho;     /**< Nodo derecho */
} ast;

main(int argc, char *argv)
{
    printf("sizeof(char *)        = %u\n", sizeof(char *));
    printf("sizeof(long)          = %u\n", sizeof(long));
    printf("sizeof(int)           = %u\n", sizeof(int));
    printf("sizeof(short)         = %u\n", sizeof(short));
    printf("sizeof(char)          = %u\n", sizeof(char));
    printf("sizeof(float)         = %u\n", sizeof(float));
    printf("sizeof(double)        = %u\n", sizeof(double));
    printf("sizeof(struct foo1)   = %u\n", sizeof(struct foo1));
    printf("sizeof(struct foo2)   = %u\n", sizeof(struct foo2));
    printf("sizeof(struct foo3)   = %u\n", sizeof(struct foo3));
    printf("sizeof(struct foo4)   = %u\n", sizeof(struct foo4));
    printf("sizeof(struct foo5)   = %u\n", sizeof(struct foo5));
    printf("sizeof(struct foo6)   = %u\n", sizeof(struct foo6));
    printf("sizeof(struct foo7)   = %u\n", sizeof(struct foo7));
    printf("sizeof(struct foo8)   = %u\n", sizeof(struct foo8));
    printf("sizeof(struct foo9)   = %u\n", sizeof(struct foo9));
    printf("sizeof(struct foo10)   = %u\n", sizeof(struct foo10));
    printf("sizeof(struct foo11)   = %u\n", sizeof(struct foo11));
    printf("sizeof(struct foo12)   = %u\n", sizeof(struct foo12));
    printf("sizeof(struct nodo_valor)   = %u\n", sizeof(nodo_valor));
    printf("sizeof(struct ast)   = %u\n", sizeof(ast));
}
