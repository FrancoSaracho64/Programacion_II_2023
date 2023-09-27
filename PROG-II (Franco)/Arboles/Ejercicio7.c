#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "funcionesEjercicios.h"

int main(){
    ArbolBinario arbol1 = a_crear();
    ArbolBinario arbol2 = a_crear();

    printf("*** ARBOL 1... ***\n");
    a_cargar_binario(arbol1);
    printf("\n\n*** ARBOL 2... ***\n");
    a_cargar_binario(arbol2);   
    //Llamamos a la funcion...
    if (sonEquivalentes(a_raiz(arbol1), a_raiz(arbol2))) {
            printf("\nEl arbol 1 y el Arbol 2 ----> son EQUIVALENTES.\n");
        } else {
            printf("\nEl arbol 1 y el arbol 2 ----> NO son EQUIVALENTES.\n");
        }
    printf("\nPresione ENTER para salir...");
    getchar();
}