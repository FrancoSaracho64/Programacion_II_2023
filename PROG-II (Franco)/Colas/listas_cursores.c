#include <stdlib.h>
#include <stdio.h>
#include "listas.h"

static const int TAMANIO_MAXIMO = 100;
static const int NULO = -1;

struct Nodo
{
    TipoElemento datos;
    int siguiente; // Cambia el apuntador por un “int”
};

struct ListaRep
{
    struct Nodo *cursor; // Apuntador al Arreglo de Nodos
    int inicio;
    int libre; // Contendrá los nodos libres o disponibles
    int cantidad;
};

struct IteradorRep
{
    Lista lista;
    int posicionActual;
};

//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
// Rutinas del TAD
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------

Lista l_crear()
{
    Lista nueva_lista = (Lista)malloc(sizeof(struct ListaRep));
    nueva_lista->cursor = calloc(TAMANIO_MAXIMO, sizeof(struct Nodo));
    nueva_lista->cantidad = 0;
    nueva_lista->inicio = NULO;
    // Encadeno todos los libres
    for (int i = 0; i < TAMANIO_MAXIMO - 2; i++)
    {
        nueva_lista->cursor[i].siguiente = i + 1;
    }
    nueva_lista->libre = 0; // Toma todos los nodos como libres
    nueva_lista->inicio = NULO;
    nueva_lista->cursor[TAMANIO_MAXIMO - 1].siguiente = NULO;
    // retorno la lista creada
    return nueva_lista;
}

void l_agregar(Lista lista, TipoElemento elemento)
{
    if (l_es_llena(lista))
    {
        return;
    }
    //si esta vacia
    int p;
    p = lista->libre;//se le asigna el valor libre a p
    lista->libre = lista->cursor[p].siguiente;//
    lista->cursor[p].datos = elemento;//
    lista->cursor[p].siguiente = NULO;//

    if (lista->inicio == NULO)
    {
        lista->inicio = p;
    }
    else
    {
        int q = lista->inicio;
        while (lista->cursor[q].siguiente != NULO)
        {
            q = lista->cursor[q].siguiente;
        }
        lista->cursor[q].siguiente = p;
    }
    lista->cantidad++;
}

void l_borrar(Lista lista, int clave)
{
    if (l_es_vacia(lista))
    {
        return;
    } // Controlo la lista vacia
    int q;
    int p = lista->inicio;
    // borro las claves que coinciden con el inicio
    while ((p != NULO) && (lista->cursor[p].datos->clave == clave))
    {
        q = p;
        lista->inicio = lista->cursor[p].siguiente;
        // recupero el nodo en el libre para no perderlo
        lista->cursor[q].siguiente = lista->libre;
        lista->libre = q;
        // Descuento 1 y arranco de nuevo desde el inicio
        lista->cantidad--;
        p = lista->inicio; // Vuelvo a intentar desde el inicio
    }
    // Borro las claves en el resto de la lista
    p = lista->inicio;
    q = p;
    int temp=NULO;
    while ((p != NULO) && (lista->cursor[p].siguiente != NULO))
    {
        
        printf("%d",lista->cursor[p].datos->clave);//printf("%d",p);
        if (lista->cursor[p].datos->clave == clave)
        {
            temp=lista->cursor[q].siguiente;
            lista->cursor[q].siguiente = lista->cursor[p].siguiente;
            lista->cursor[p].siguiente = lista->libre;
            lista->libre=temp;
            //lista->cantidad--;
            p=NULO;
        }else{
            q=p;
            p = lista->cursor[p].siguiente;
        }
    }
}

void l_insertar(Lista lista, TipoElemento elemento, int pos)
{
    if (l_es_llena(lista))
    {
        return;
    }                     // Control de lista llena
    int p = lista->libre; // Toma la primer posición libre
    lista->libre = lista->cursor[p].siguiente;
    lista->cursor[p].datos = elemento;
    lista->cursor[p].siguiente = NULO;
    // Controla si cambia el INICIO
    if (pos == 1)
    {
        lista->cursor[p].siguiente = lista->inicio;
        lista->inicio = p;
    }
    else
    {
        int temp = lista->inicio; // Busca la posición del resto de la lista
        for (int i = 0; i < pos - 2; i++)
        {
            temp = lista->cursor[temp].siguiente;
        }
        lista->cursor[p].siguiente = lista->cursor[temp].siguiente;
        lista->cursor[temp].siguiente = p;
    }
    lista->cantidad++;
}

void l_eliminar(Lista lista, int pos)
{
    int p; // Falta controlar lista vacia
    int actual = lista->inicio;
    if (1 <= pos && pos <= l_longitud(lista))
    {
        if (pos == 1)
        { // borra la primer posicion hay que cambiar el Inicio
            p = actual;
            lista->inicio = lista->cursor[actual].siguiente;
            lista->cursor[p].siguiente = lista->libre;
            lista->libre = p; // Devuelvo al libre el nodo que elimine (saque de la lista)
        }
        else
        {
            for (int i = 0; i < pos - 2; i++)
            {
                actual = lista->cursor[actual].siguiente;
            }                                                             // actual apunta al nodo en posición (pos - 1)
            p = lista->cursor[actual].siguiente;                          // nodo en pos
            lista->cursor[actual].siguiente = lista->cursor[p].siguiente; // nodo en pos + 1
            lista->cursor[lista->libre].siguiente = p;
            lista->libre = p; // Devuelvo al libre el nodo que elimine (saque de la lista)
        }
        lista->cantidad--;
    }
}


//-----------------------LISTAS---------------------------------------------------------------------------------------------

bool l_es_vacia(Lista lista) {
    return (lista->cantidad == 0);
}

bool l_es_llena(Lista lista) {
    return (lista->cantidad == TAMANIO_MAXIMO);
}

TipoElemento l_recuperar(Lista lista, int pos) {
    if (pos < 1 || pos > l_longitud(lista)) {
        return NULL;
    }

    struct Nodo temp3 = lista->cursor[lista->inicio];
    for (int i = 0; i < pos - 1; i++) {
        temp3 = lista->cursor[temp3.siguiente];
    }
    return temp3.datos;

}

int l_longitud(Lista lista) {
    return lista->cantidad;
}

void l_mostrarLista(Lista lista) {
    printf("Contenido de la lista: \n");
    for (int i = 0; i < lista->cantidad; i++) {
          printf("%d ",lista->cursor[i].datos->clave);
    }

    printf("\n");
}

TipoElemento l_buscar(Lista lista, int clave) {
    struct Nodo temp3 = lista->cursor[lista->inicio];
    struct Nodo comp;
    for (int i = 0; i < lista->cantidad; i++) {
        comp = temp3;
        if (temp3.datos->clave == clave) {
            return temp3.datos;
        }
        temp3 = lista->cursor[temp3.siguiente];
    }
    return NULL;
}

//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
// Rutinas del Iterador
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------

Iterador iterador(Lista lista)
{
    Iterador iter = (Iterador)malloc(sizeof(struct IteradorRep));
    iter->lista = lista;
    iter->posicionActual = 0;
    return iter;
}

bool hay_siguiente(Iterador iterador)
{

    return iterador->posicionActual < iterador->lista->cantidad;
}

TipoElemento siguiente(Iterador iterador)
{
    return iterador->lista->cursor[iterador->posicionActual++].datos;
}