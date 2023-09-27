#include "pilas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static const int TAMANIO_MAXIMO = 100;

struct PilaRep {
    TipoElemento *valores;
    int tope;
};

Pila p_crear() {
    Pila nueva_pila = (Pila)malloc(sizeof(struct PilaRep));
    nueva_pila->valores = calloc(TAMANIO_MAXIMO, sizeof(TipoElemento));
    nueva_pila->tope = 0;
    return nueva_pila;
}

void p_apilar (Pila pila, TipoElemento elemento) {
    if (p_es_llena(pila)) return;
    else{
        pila->valores[pila->tope] = elemento;
        pila->tope++; 
    }
}

TipoElemento p_desapilar (Pila pila) {
    TipoElemento elemento = pila->valores[pila->tope-1];
    pila->tope--; 
    return elemento;
}

TipoElemento p_tope (Pila pila) {
    TipoElemento elemento = pila->valores[pila->tope-1];
    return elemento;
}

bool p_es_vacia (Pila pila) {
    return (pila->tope == 0);
}

bool p_es_llena(Pila pila) {
    return (pila->tope == TAMANIO_MAXIMO);
}

void p_mostrar (Pila pila) {
    Pila Paux = p_crear();
    TipoElemento X;
    printf("Contenido de la pila: ");
    // Recorro la pila desopilándola y pasándola al auxiliar
    while (p_es_vacia(pila) != true) {
        X = p_desapilar(pila);
        printf("%d ", X->clave);
        p_apilar(Paux, X);
    }
    // Recorro la pila auxiliar para pasarla a la original (o bien construyo la utilidad intercambiar)
    while (p_es_vacia(Paux) != true) {
        X = p_desapilar(Paux);
        p_apilar(pila, X);
    }
    printf("\n");
}