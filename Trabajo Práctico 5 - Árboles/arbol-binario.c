#include <stdlib.h>
#include <string.h>
#include "arbol-binario.h"
#include "nodo.h"

static const int TAMANIO_MAXIMO = 100;

struct ArbolBinarioRep {
    NodoArbol raiz;
    int cantidad_elementos;
};

ArbolBinario a_crear(){
    ArbolBinario nuevo_arbol = (ArbolBinario) malloc(sizeof(struct ArbolBinarioRep));
    nuevo_arbol->raiz = NULL;
    nuevo_arbol->cantidad_elementos = 0;
    return nuevo_arbol;
}

bool a_es_vacio(ArbolBinario arbol){
    return arbol->raiz == NULL;
}

bool a_es_lleno(ArbolBinario arbol){
    return(arbol->cantidad_elementos == TAMANIO_MAXIMO);
}

int a_cantidad_elementos(ArbolBinario arbol){
    return arbol->cantidad_elementos;
}

bool a_es_rama_nula(NodoArbol pa){
    return pa == NULL;
}

NodoArbol a_raiz(ArbolBinario arbol){
    return arbol->raiz;
}

NodoArbol a_establecer_raiz(ArbolBinario arbol, TipoElemento te){
    if(arbol->raiz != NULL){
        return arbol->raiz;
    } else {
        NodoArbol na = n_crear(te);
        arbol->raiz = na;
        arbol-> cantidad_elementos++;
        return na;
    }
}

NodoArbol a_conectar_hi (ArbolBinario arbol, NodoArbol pa, TipoElemento te){
    if (!a_es_rama_nula(pa)){
        if (pa->hi != NULL){
            return pa->hi;
        }
        
        NodoArbol na = n_crear(te);
        arbol->cantidad_elementos++;
        pa->hi = na;
        return na;
    }
}

NodoArbol a_conectar_hd (ArbolBinario a, NodoArbol pa, TipoElemento te){
    if (!a_es_rama_nula(pa)){
        if (pa->hd != NULL){
            return pa->hd;
        }
        NodoArbol na = n_crear(te);
        a->cantidad_elementos++;
        pa->hd = na;
        return na;
    }
}


