#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "funcionesEjercicios.h"

void alturaInt(NodoArbol nodo, int* alt, int actual){
    if (nodo == NULL){
        if (actual > *alt){
            *alt = actual;
        }
    } else {
        alturaInt(n_hijoizquierdo(nodo), alt, actual++);
        alturaInt(n_hijoderecho(nodo), alt, actual++);
    }
}

int altura(NodoArbol nodo){
    int alturaNodo = 0;
    alturaInt(nodo, &alturaNodo, 0);
    return alturaNodo;
}

void verifEquilibrado(NodoArbol nodo, bool *equilibrado){
    if (nodo != NULL){
        int altIZQ = 0;
        int altDER = 0;
        if (n_hijoizquierdo(nodo) != NULL){
            altIZQ = altura(n_hijoizquierdo(nodo));
        }
        
        if (n_hijoderecho(nodo) != NULL){
            altDER = altura(n_hijoderecho(nodo));
        }

        if((altIZQ - altDER) >= 2 || (altIZQ - altDER) <= -2){
            *equilibrado = false;
        }
        
        if (equilibrado == false){
            return;
        }
        verifEquilibrado(n_hijoizquierdo(nodo), equilibrado);
        verifEquilibrado(n_hijoderecho(nodo), equilibrado);
    }
}

bool ArbolEquilibrado(ArbolBinarioBusqueda arbol){
    bool equilibrado = true;

    verifEquilibrado(abb_raiz(arbol), &equilibrado);

    return equilibrado;
}

int main(){
    //Creacion y carga del arbol
    ArbolBinarioBusqueda arbolPrueba = abb_crear();
    TipoElemento x;

    x = te_crear(15);
    abb_insertar(arbolPrueba, x);

    x = te_crear(96);
    abb_insertar(arbolPrueba, x);

    x = te_crear(77);
    abb_insertar(arbolPrueba, x);

    x = te_crear(81);
    abb_insertar(arbolPrueba, x);
    
    x = te_crear(18);
    abb_insertar(arbolPrueba, x);

    x = te_crear(33);
    abb_insertar(arbolPrueba, x);

    x = te_crear(98);
    abb_insertar(arbolPrueba, x);

    bool equilibrio = ArbolEquilibrado(arbolPrueba);
    if (equilibrio) printf("Esta equilibrado");
    else printf("NO esta equilibrado");

    getchar();
    return 0;
}