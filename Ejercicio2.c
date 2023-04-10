#include <stdio.h>
#include "FuncionesRecursivas.h"
#include "Validaciones.h"
#define TAMANIO_CADENA 25
const int limSup = 45000;
const int limInf = -45000;

int producto(int, int);

int main(){
    // Presentacion
    system("cls");
    printf("***Ejercicio 2***\n");
    printf("Multiplicacion de dos numeros...\n\n");

    // Inicializaciones
    char multiplicando[TAMANIO_CADENA];
    char multiplicador[TAMANIO_CADENA];
    int resultado;
    int num1, num2;
    bool entrada = true;

    /* Obtenemos los valores necesarios para la ejecucion y realizamos las validaciones correspondientes: */
    // Primer numero (multiplicando)
    do{    
        do{
            printf("Ingrese el primer numero: ");
            fflush(stdin);
            fgets(multiplicando, TAMANIO_CADENA, stdin);
            entrada = numEnteros(multiplicando) && validarEnter(multiplicando);
        }while (!entrada);
        num1 = pasaje_String_A_int(multiplicando);
        entrada = numeroRango(num1, limInf, limSup);
    } while (!entrada);
    
    // Segundo numero (multiplicador)
    do{
        do{
            printf("Ingrese el segundo numero: ");
            fflush(stdin);
            fgets(multiplicador, TAMANIO_CADENA, stdin);
            entrada = numEnteros(multiplicador) && validarEnter(multiplicador);
        } while (!entrada);
        num2 = pasaje_String_A_int(multiplicador);
        entrada = numeroRango(num2, limInf, limSup);
    } while (!entrada);

    // Llamada a la funcion recursiva con los numeros a multiplicar.
    resultado = producto_de_dos_numeros(num1, num2);

    printf("\n\n********************************************************************\n");
    printf("   El resultado de la operacion  '%d x %d'  es: %d\n", num1, num2, resultado);
    printf("********************************************************************\n");
    fflush(stdin);
    printf("\n\n Presione ENTER para finalizar la ejecucion...");
    getchar();
    return 0;
}