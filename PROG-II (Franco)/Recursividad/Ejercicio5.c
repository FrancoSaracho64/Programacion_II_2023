#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesRecursivas.h"
#include "Validaciones.h"
#define TAMANIO_CADENA 25

int main () {
    // Presentacion
    system("cls");
    printf("***Ejercicio 5***\n");
    printf("Insersion de puntos de miles...\n\n");

    //Inicializaciones  
    bool entrada = true;
    char numeroAux[TAMANIO_CADENA];
    char *numeroIngresado;

    // Pedimos el numero a procesar y realizamos las validaciones correspondientes
    do {
        printf("Ingrese el numero a procesar: ");
        fflush(stdin);
        fgets(numeroAux, TAMANIO_CADENA, stdin);
        entrada = numEnteros(numeroAux) && validarEnter(numeroAux);
    } while (!entrada);

    numeroAux[strlen(numeroAux)-1] = '\0';
    numeroIngresado = numeroAux;
    // Controlamos si el numero es negativo
    bool validoNegativo = controlMenos(numeroIngresado);

    if (validoNegativo) { // Si es un numero negativo, le quitamos el '-', luego lo reponemos.
        numeroIngresado = truncarMenos(numeroIngresado); 
    }
    // Controlamos si el numero tiene 0 por delante. Si los tiene, los eliminamos.
    numeroIngresado = truncarCeros(numeroIngresado);
    
    //Llamada a la funcion recursiva
    char *res = PuntosDeMil(numeroIngresado);
    // Si el numero es negativo, le reponemos el '-'.
    if (validoNegativo == true) {
        res = insertarMenos(res);
    }
    
    printf("\n\n*******************************************************************\n");
    printf("Se le colocan los puntos de mil a %s.\n", numeroIngresado);
    printf("Resultado: %s\n", res);
    printf("*******************************************************************");
    //free(res);  //Al intentar liberar la memoria obtenermos un error.
    fflush(stdin);
    printf("\n\n Presione ENTER para finalizar la ejecucion...");
    getchar();
    return 0;
}