#include <stdio.h>
#include <stdbool.h>
#include "FuncionesRecursivas.h"
#include "Validaciones.h"
#define TAMANIO_CADENA 25
const int limSup = 40;
const int limInf = 0;

int main(){
    // Presentacion
    system("cls");
    printf("***Ejercicio 3***\n");
    printf("Serie de Fibonacci...\n\n");

    // Inicializaciones
    int numeroFibo;
    int resultado;
    bool entrada = true;
    char numeroTeclado[TAMANIO_CADENA];
    
    // Pedimos que ingrese un numero para aplicar la sucesion y realizamos las verificaciones correspondientes.
    do{
        do{
            printf("Ingrese un numero: ");
            fflush(stdin);
            fgets(numeroTeclado, TAMANIO_CADENA, stdin);
            entrada = numEnteros(numeroTeclado) && validarEnter(numeroTeclado);
        }while (!entrada);
        numeroFibo = pasaje_String_A_int(numeroTeclado);
        entrada = numeroRango(numeroFibo, limInf, limSup);
    } while (!entrada);

    // Llamada a la funcion recursiva
    resultado = fibonacci(numeroFibo);

    printf("*******************************************************************\n");
    printf("    El resultado de la sucesion de Fibonacci de %d es: %d\n", numeroFibo, resultado);
    printf("*******************************************************************\n");
    fflush(stdin);
    printf("\n\n Presione ENTER para finalizar la ejecucion...");
    getchar();
}