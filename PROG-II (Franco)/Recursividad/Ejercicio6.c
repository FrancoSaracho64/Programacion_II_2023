//DECLARAMOS LAS LIBRERIAS UTILIZADAS EN EL PROGRAMA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesRecursivas.h"
#include "Validaciones.h"
#define TAMANIO_CADENA 25
const int limSup = 25;
const int limInf = 1;

int main () {
    //Presentacion
    system("cls");
    printf("***Ejercicio 6***\n");
    printf("Reunion de la Mafia china...\n\n");

    //Inicializaciones
    bool entrada = true;
    char numeroIngresado[TAMANIO_CADENA];
    int nivelReunion;
    
    //Pedimos el nivel de la reunion y realizamos las validaciones correspondientes.
    do{    
        do{
            printf("Ingrese el nivel de reunion: ");
            fflush(stdin);
            fgets(numeroIngresado, TAMANIO_CADENA, stdin);
            entrada = numEnteros(numeroIngresado) && validarEnter(numeroIngresado);
        } while (!entrada);
        nivelReunion = pasaje_String_A_int(numeroIngresado);
        entrada = numeroRango(nivelReunion, limInf, limSup);
    } while (!entrada);

    // Llamada a la funcion recursiva
    char *res = reunionChinos(nivelReunion);

    //IMPRIMIMOS EL RESULTADO DE LA OPERACION
    printf("\n*******************************************************************************************************\n\n");
    printf("                                Resultado de la reunion de nivel: %d\n%s  \n\n", nivelReunion, res);
    printf("*******************************************************************************************************\n");
    free(res); 
    printf("\n\n Presione ENTER para finalizar la ejecucion...");
    getchar();
    return 0;
}