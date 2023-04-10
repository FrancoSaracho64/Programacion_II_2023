#include <stdio.h>
#include "FuncionesRecursivas.h"
#include "Validaciones.h"
#define TAMANIO_CADENA 25
const int limSup = 9999;
const int limInf = -9999;

int main(){
    // Presentacion
    system("cls");
    printf("***Ejercicio 4***\n");
    printf("Division de dos numeros...\n\n");

    // Inicializaciones
    char dividiendoTeclado[TAMANIO_CADENA];
    char divisorTeclado[TAMANIO_CADENA];
    int dividiendo, divisor;
    float resultado;
    bool entrada = true;
    
    // Pedimos los dos numeros para realizar la operacion y realizamos las validaciones correspondientes
    // Primer numero (dividiendo)
    do{    
        do{
            printf("Ingrese el dividiendo: ");
            fflush(stdin);
            fgets(dividiendoTeclado, TAMANIO_CADENA, stdin);
            entrada = numEnteros(dividiendoTeclado) && validarEnter(dividiendoTeclado);
        } while (!entrada);
        dividiendo = pasaje_String_A_int(dividiendoTeclado);
        entrada = numeroRango(dividiendo, limInf, limSup);
    } while (!entrada);
    
    // Segundo numero (divisor)
    do{
        do{
            do{
                printf("Ingrese el divisor: ");
                fflush(stdin);
                fgets(divisorTeclado, TAMANIO_CADENA, stdin);
                entrada = numEnteros(divisorTeclado) && validarEnter(divisorTeclado);
            } while (!entrada);
            divisor = pasaje_String_A_int(divisorTeclado);
            entrada = numeroRango(divisor, limInf, limSup);
        } while (!entrada);
        entrada = esCero(divisor);
    } while (!entrada);

    /* Creamos un puntero 'veces' el cual se encargara de almacenar el contador de las veces que se deben calcular
    los decimales, en caso de que la division no sea entera. */
    int *veces = malloc(sizeof(int));
    *veces = 5;          /* Le asignamos el valor 5 y no 4, para colocar un '0' en la posicion 5, despues de calcular 
                            el ultimo decimal (el cuarto). */

    // Llamada a la funcion recursiva con los numeros para realizar la division.
    resultado = division_restasSucesivas(dividiendo, divisor, veces);

    printf("***************************************************************\n");
    printf("  El resultado de dividir %d entre %d es:  %.4f\n", dividiendo, divisor, resultado);
    printf("***************************************************************\n");
    fflush(stdin);
    printf("\n\n Presione ENTER para finalizar la ejecucion...");
    getchar();
    return 0;
}