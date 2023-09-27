#include "colas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static const int TAMANIO_MAXIMO = 100;

struct ColaRep {
    TipoElemento *valores;
    int frente;
    int final;
};

Cola c_crear() {
    Cola nueva_cola = (Cola)malloc(sizeof(struct ColaRep));
    nueva_cola->valores = calloc((TAMANIO_MAXIMO), sizeof(TipoElemento));
    nueva_cola->frente = 0;
    nueva_cola->final = 0;
    return nueva_cola;
}

// Operación encolar de complejidad constante. ¿ Porque ?
void c_encolar(Cola cola, TipoElemento elemento) {
    cola->valores[cola->final] = elemento;
    cola->final++;
}

// Cual es su complejidad ? de desencolar
TipoElemento c_desencolar(Cola cola) { 
    TipoElemento elemento = cola->valores[cola->frente];
    for(int i = 0; i <= cola->final - 1; i ++){
        cola->valores[i] = cola->valores[i + 1];
    }
    cola->final --;
    return elemento;
}

bool c_es_vacia(Cola cola) {
    return (cola->final == 0);
}

bool c_es_llena(Cola cola) {
    return (cola->final == TAMANIO_MAXIMO);
}

TipoElemento c_recuperar(Cola cola) {
    TipoElemento elemento;
    if (c_es_vacia(cola)) {
        elemento = NULL;
    }
    else {
        elemento = cola->valores[cola->frente];
    }
    return elemento;
}

void c_mostrar(Cola cola) {
    if (c_es_vacia(cola)) {
        printf("COLA VACIA !!! \n");
        return;
    } else {
        Cola Caux = c_crear();
        TipoElemento X = te_crear(0);
        printf("Imprimiendo las Claves de la Cola \n");
        // La cola se debe desencolar y guardar en una auxiliar
        while (c_es_vacia(cola) != true) {
            X = c_desencolar(cola);
            printf("Clave: %d \n", X->clave);
            c_encolar(Caux, X);
        }
        // ahora paso la auxiliar a la cola de nuevo para dejarla como estaba
        while (c_es_vacia(Caux) != true) {
            X = c_desencolar(Caux);
            c_encolar(cola, X);
        }
    }
}
