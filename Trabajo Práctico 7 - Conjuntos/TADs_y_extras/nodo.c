#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"


// retorna el hijo izquierdo
NodoArbol n_hijoizquierdo(NodoArbol N){
    if (N == NULL) return NULL;
    else return N->hi;
}

// retorna el hijo derecho
NodoArbol n_hijoderecho(NodoArbol N){
    if (N == NULL) return NULL;
    else return N->hd;
}

// Crea un Nodo y lo retorna
NodoArbol n_crear(TipoElemento te){
    NodoArbol nuevo_nodo = (NodoArbol)malloc(sizeof(struct NodoArbolRep));
    nuevo_nodo->datos = te;
    nuevo_nodo->hd = NULL;
    nuevo_nodo->hi = NULL;
    nuevo_nodo->FE = 0;
    return nuevo_nodo;
}

// Crea un Nodo y lo retorna
TipoElemento n_recuperar(NodoArbol N){
    if (N == NULL) return NULL;
    else return N->datos;
}