#include <stdio.h>
#include <stdlib.h>
#include "FuncionesRecursivas.h"
#include "Validaciones.h"
#define TAMANIO_CADENA 25

int main() {
    //Presentacion
    system("cls");
    printf("***Ejercicio 8***\n");
    printf("Subconjuntos de sumas...\n\n");

    // Inicializaciones
    char CantElementosTeclado[TAMANIO_CADENA];
    char numeroTeclado[TAMANIO_CADENA];
    char sumaObjetivoTeclado[TAMANIO_CADENA];
    int sumaObjetivo, CantidadElementos, numeroConjunto;
    bool entrada = true;

    /* Pedimos y validamos la cantidad de elementos */
    do{    
        do{
            printf("Ingrese la cantidad de elementos: ");
            fflush(stdin);
            fgets(CantElementosTeclado, TAMANIO_CADENA, stdin);
            entrada = numEnteros(CantElementosTeclado) && validarEnter(CantElementosTeclado);
        } while (!entrada);
        CantidadElementos = pasaje_String_A_int(CantElementosTeclado);
        if (CantidadElementos <= 0){
            entrada = false;
            printf("\n************************************************************");
            printf("\n                      +++ERROR+++\n        El numero ingresado tiene que ser mayor a 0\n");
            printf("************************************************************\n\n");
        }
    } while (!entrada);
    printf("\n");

    int conjunto[CantidadElementos];
    
    // Llenamos el vector del conjuto
    for (int i = 0; i < CantidadElementos; i++) {
        do {
            printf("Ingrese el elemento de posicion [%d]: ",i+1);
            fflush(stdin);
            fgets(numeroTeclado, TAMANIO_CADENA, stdin);
            entrada = numEnteros(numeroTeclado) && validarEnter(numeroTeclado);
        } while (!entrada);
        numeroConjunto = pasaje_String_A_int(numeroTeclado);
        conjunto [i] = numeroConjunto;
    }
    printf("\n");

    /* Pedimos y validamos el numero para descomponer en conjuntos */
    do{    
        do{
            printf("Ingrese el numero a descomponer en conjuntos: ");
            fflush(stdin);
            fgets(sumaObjetivoTeclado, TAMANIO_CADENA, stdin);
            entrada = numEnteros(sumaObjetivoTeclado) && validarEnter(sumaObjetivoTeclado);
        } while (!entrada);
        sumaObjetivo = pasaje_String_A_int(sumaObjetivoTeclado);
        entrada = esCero(sumaObjetivo);
        if (sumaObjetivo < 0){
            entrada = false;
            printf("              +++ERROR+++\nEl numero ingresado tiene que ser mayor a 0\n\n");
        }
    } while (!entrada);
    printf("\n");

    //Llamada a la funcion recursiva
    subconjuntosQueSumanN(conjunto, CantidadElementos, sumaObjetivo);

    printf("Presione ENTER para finalizar la ejecucion...");
    getchar();
    return 0;
}