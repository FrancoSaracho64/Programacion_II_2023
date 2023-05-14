#include "colas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static const int TAMANIO_MAXIMO = 100;

struct Nodo {
    TipoElemento datos;
    struct Nodo *siguiente;
};

struct ColaRep {
    struct Nodo *frente;
    struct Nodo *final;
    int cantidad;
};


Cola c_crear() {
    Cola nueva_cola = (Cola) malloc(sizeof(struct ColaRep));
    nueva_cola->frente = NULL;
    nueva_cola->final = NULL;
    nueva_cola->cantidad = 0;
    return nueva_cola;
}

// Operación encolar de complejidad constante. ¿ Porque ?
void c_encolar(Cola cola, TipoElemento elemento) {
    if (c_es_llena(cola)) return;
    else {
        struct Nodo *nuevo_nodo = malloc(sizeof(struct Nodo));
        nuevo_nodo->datos = elemento;
        nuevo_nodo->siguiente = NULL;
        if (c_es_vacia(cola)) {
            cola->frente = nuevo_nodo;
        } else {
            cola->final->siguiente = nuevo_nodo;
        }
        cola->final = nuevo_nodo;
        cola->cantidad++;
    }
    
}

TipoElemento c_desencolar(Cola cola) { 
    if (c_es_vacia(cola)) {
        return NULL;
    } else {
        struct Nodo *frente_actual = cola->frente;
        TipoElemento elemento = frente_actual->datos;
        cola->frente = frente_actual->siguiente;
        free(frente_actual);
        cola->cantidad--;
        return elemento;
    }
}

bool c_es_vacia(Cola cola) {
    return cola->cantidad == 0;
}

bool c_es_llena(Cola cola) {
    return (cola->cantidad == TAMANIO_MAXIMO);
}

TipoElemento c_recuperar(Cola cola) {
    TipoElemento elem;
    if (c_es_vacia(cola)) {
        elem = NULL;
    } else {
        elem = cola->frente->datos;
    }
    return elem;
}

void c_mostrar(Cola cola) {
    if (c_es_vacia(cola)) {
        printf("COLA VACIA !!! \n");
        return;
    }
    else {
        Cola Caux = c_crear();
        TipoElemento X = te_crear(0);
        printf("Imprimiendo las Claves de la Cola \n");

        // La cola se debe desencolar y guardar en una auxiliar
        while (!c_es_vacia(cola)) {
            X = c_desencolar(cola);
            printf("Clave: %d \n", X->clave);
            c_encolar(Caux, X);
        }
        // ahora paso la auxiliar a la cola de nuevo para dejarla como estaba
        while (!c_es_vacia(Caux)) {
            X = c_desencolar(Caux);
            c_encolar(cola, X);
        }
    }
}