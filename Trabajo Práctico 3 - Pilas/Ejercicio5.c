#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tipo_elemento.h"
#include "pilas.h"
#include "Validaciones.h"
#include "pilas_utilidades.h"
#include "funcionesEjercicios.h"

int main() {
    //Inicializaciones
    TipoElemento elemento;
    int n, clave;
    //Presentacion
    printf("***Ejercicio 5***\n");
    printf("Invertir una pila...\n\n");
    
    //Complejidad algoritmica
    printf("------------------------------------------------------------------------------\nCOMPLEJIDAD ALGORITMICA: \n");
    printf("La complejidad algorítmica es de  O(n),  ya que se realiza un bucle  while que\nrecorre los elementos de la  pila original (n)  y  apila y  desapila elementos\nde las pilas.");
    printf("\n------------------------------------------------------------------------------\n\n\n");

    //Funcion...
    //Creamos y cargamos la pila
    Pila pila_original = p_crear();
    cargarPila(pila_original);

    // Invierto la pila original y la guardo (a la invertida).
    Pila pila_invertida = p_invertir(pila_original);

    if (p_es_vacia(pila_invertida)){
        printf("\n\n**************************************************\n");
        printf("---------****** La pila está VACIA ******---------");
        printf("\n**************************************************\n\n");
    } else {
        printf("---------Pila original---------\n");
        p_mostrar(pila_original);
        printf("********************************************\n");
        printf("---------Pila obtenida---------\n");
        p_mostrar(p_invertir(pila_original));
        printf("\n********************************************\n\n");
    }
    printf("Presione ENTER para finalizar el programa...");
    getchar();
    
    return 0;
}