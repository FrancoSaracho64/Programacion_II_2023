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

bool a_es_vacio(ArbolBinario a){
    return a->raiz == NULL;
}

bool a_es_lleno(ArbolBinario a){
    return(a->cantidad_elementos == TAMANIO_MAXIMO);
}

int a_cantidad_elementos(ArbolBinario a){
    return a->cantidad_elementos;
}

bool a_es_rama_nula(NodoArbol pa){
    return pa == NULL;
}

NodoArbol a_raiz(ArbolBinario a){
    return a->raiz;
}

NodoArbol a_establecer_raiz(ArbolBinario a, TipoElemento te){
    if(a->raiz != NULL){
        //todo aca deberia ser un error
        //no se puede establecer la raiz a un arbol que ya tiene raiz
        return a->raiz;
    } else {
        NodoArbol na = n_crear(te);
        a->raiz = na;
        a-> cantidad_elementos++;
        return na;
    }
}

NodoArbol a_conectar_hi (ArbolBinario a, NodoArbol pa, TipoElemento te){

    if (!a_es_rama_nula(pa)){
        //todo aca deberiamos chequear que la posicion arbol efectivamente esté en el rabol

        //chequeamos que la posicion arbol no tenga ya la rama que estan solicitancio l insertar
        if (pa->hi != NULL){
            //TODO deberiamos devolver error
            return pa->hi;
        }
        
        NodoArbol na = n_crear(te);
        a->cantidad_elementos++;

        pa->hi = na;

        return na;
    }
}


NodoArbol a_conectar_hd (ArbolBinario a, NodoArbol pa, TipoElemento te){
    if (!a_es_rama_nula(pa)){
        //todo aca deberiamos chequear que la posicion arbol efectivamente esté en el rabol

        //chequeamos que la posicion arbol no tenga ya la rama que estan solicitancio l insertar
        if (pa->hd != NULL){
            //TODO deberiamos devolver error
            return pa->hd;
        }
        
        NodoArbol na = n_crear(te);
        a->cantidad_elementos++;

        pa->hd = na;

        return na;
    }
}


