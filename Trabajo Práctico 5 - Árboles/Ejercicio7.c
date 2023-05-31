#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "arbol-binario.h"
#include "funcionesEjercicios.h"
#include "arbol-Utilidades.h"
#include "TADs_y_extras\colas.h"
#include "TADs_y_extras\listas.h"
#include "TADs_y_extras\pilas.h"
#include "TADs_y_extras\Validaciones.h"
#include "TADs_y_extras\tipo_elemento.h"

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