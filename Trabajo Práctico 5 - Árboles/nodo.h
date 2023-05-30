#ifndef NODO_H
#define NODO_H
#include "TADs_y_extras\tipo_elemento.h"

struct NodoArbolRep {
    TipoElemento datos;
    struct NodoArbolRep *hi;
    struct NodoArbolRep *hd;
    int FE;   //Factor de Equilibro de Cada nodo para el autobalanceo
};
typedef struct NodoArbolRep *NodoArbol;

// retorna el hijo izquierdo
NodoArbol n_hijoizquierdo(NodoArbol N);

// retorna el hijo derecho
NodoArbol n_hijoderecho(NodoArbol N);

// Crea un Nodo y lo retorna
NodoArbol n_crear(TipoElemento te);

// Retorna el TE del nodo
TipoElemento n_recuperar(NodoArbol N);

#endif // NODO_H
