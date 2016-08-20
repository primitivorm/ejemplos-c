typedef struct lista_nodo
{
    struct lista_nodo* previo;   /**< Nodo previo*/
    struct lista_nodo* siguiente;   /**< Nodo siguiente*/
    void* info;   /**< Informacion del nodo*/
} lista_nodo;

lista_nodo* lista_nueva();
int lista_longitud(lista_nodo* nodo);
void lista_agregar(lista_nodo* nodo, void* info);
void lista_eliminar(lista_nodo* nodo, void* info);
