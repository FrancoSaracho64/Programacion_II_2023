#include "pilas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static const int TAMANIO_MAXIMO = 100;

struct Nodo {
    TipoElemento datos; // Concepto del Nodo
    struct Nodo *siguiente;
};

struct PilaRep {
    struct Nodo *tope;
    int cantidad;
};

Pila p_crear() {
    Pila nueva_pila = (Pila) malloc(sizeof(struct PilaRep));
    nueva_pila->tope = NULL;
    nueva_pila->cantidad = 0;
    return nueva_pila;
}

void p_apilar (Pila pila, TipoElemento elemento) {
    if (p_es_llena(pila)) return;
    else {
        struct Nodo *nuevo_nodo = malloc(sizeof(struct Nodo));
        nuevo_nodo->datos = elemento;
        nuevo_nodo->siguiente = pila->tope;
        pila->tope = nuevo_nodo;
        pila->cantidad++;
    }
}

TipoElemento p_desapilar (Pila pila) {
    struct Nodo *tope_actual = pila->tope;
    TipoElemento elemento = tope_actual->datos;
    pila->tope = tope_actual->siguiente;
    pila->cantidad--;
    free(tope_actual);
    return elemento;
}

TipoElemento p_tope (Pila pila) {
    struct Nodo *tope_actual = pila->tope;
    return tope_actual->datos;
}

bool p_es_vacia (Pila pila) {
    return pila->tope == NULL;
}

bool p_es_llena(Pila pila) {
    return (pila->cantidad == TAMANIO_MAXIMO);
}

void p_mostrar (Pila pila) {
    Pila Paux = p_crear();
    TipoElemento X;
    printf("Contenido de la pila: ");
    // Recorro la pila desopilándola y pasándola al auxiliar
    while (!p_es_vacia(pila)) {
        X = p_desapilar(pila);
        printf("%d ", X->clave);
        p_apilar(Paux, X);
    }
    // Recorro la pila auxiliar para pasarla a la original (o bien construyo la utilidad intercambiar)
    while (!p_es_vacia(Paux)) {
        X = p_desapilar(Paux);
        p_apilar(pila, X);
    }
    printf("\n");
}