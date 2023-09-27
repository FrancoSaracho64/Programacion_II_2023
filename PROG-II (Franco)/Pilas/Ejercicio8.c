#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tipo_elemento.h"
#include "pilas.h"
#include "Validaciones.h"
#include "pilas_utilidades.h"
#include "funcionesEjercicios.h"

int main () {
    //Inicializaciones
    Pila p;
    p = p_crear();
    TipoElemento teR;

    //Presentacion
    printf("***Ejercicio 8***\n");
    printf("Pila con elementos repetidos...\n\n");

    //Complejidad algoritmica
    printf("------------------------------------------------------------------------------\nCOMPLEJIDAD ALGORITMICA: \n");
    printf("La  complejidad  algoritmica  en este programa es  del tipo cuadratica O(n^2).\nEsto  es asi dado que la  funcion  principal  ejecuta un ciclo  while y dentro\notro ciclo while, los cuales recorren la pila.\nDebido a esto,  a medida que los  elementos de la  pila tomen valores cada vez\nmas grandes,  la cantidad de  iteraciones del programa incrementa al cuadrado.\n");
    printf("\n------------------------------------------------------------------------------\n\n\n");

    //Funcion...
    //Cargamos la pila a tratar
    cargarPila(p);
    //Llamada a la funcion
    Pila resultado = ValoresYCantidad(p);
    
    //Mostramos los resultados
    printf("\nPila ingresada -> ");
    p_mostrar(p);
    printf("\n\nImprimiendo el resultado...");
    printf("\n\n                                *** NOTA: ***\n  La pila resultado se va a imprimir como se propuso en la consigna, mostrando\n  en cada parentesis los datos  --->  '(clave : cantidad de repeticiones)' ... ");
    printf("\n\n***********************************************************\n");
    printf("Resultado -> ");
    if (p_es_vacia(p)) {
        printf("La pila ingresada es vacia, por lo que el resultado tambien es una pila vacia. ");
        printf("\n***********************************************************");}
    else{
        //Printear los valores de la pila resultado
        while (p_es_vacia(resultado) == false) {
            teR = p_desapilar(resultado);
            int * mostrarValorPtr = (int*) teR->valor;
            int mostrarValor = *mostrarValorPtr;
            printf("(%d:%d)", teR->clave, mostrarValor);
        }
        printf("\n***********************************************************");
    }
    
    printf("\n\nPresione ENTER para finalizar el programa...");
    getchar();
    return 0;
}