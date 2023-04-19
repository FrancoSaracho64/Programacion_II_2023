#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesRecursivas.h"
#include "Validaciones.h"
#define TAMANIO_CADENA 25
const int limSup = 5000;
const int limInf = 0;

int main () {
    //Presentacion
    system("cls");
    printf("***Ejercicio 10***\n");
    printf("Explosiones...\n\n");
    
    // Inicializaciones
    int cantidadPrueba = 0;
    char numeroExplosivoTeclado[TAMANIO_CADENA];
    char bombaTeclado[TAMANIO_CADENA];
    bool entrada = true;
    int numeroExplosivo;
    int bomba;

    do{    
        do{
            printf("Ingrese el numero explosivo: ");
            fflush(stdin);
            fgets(numeroExplosivoTeclado, TAMANIO_CADENA, stdin);
            entrada = numEnteros(numeroExplosivoTeclado) && validarEnter(numeroExplosivoTeclado);
        } while (!entrada);
        numeroExplosivo = pasaje_String_A_int(numeroExplosivoTeclado);
        entrada = numeroRango(numeroExplosivo, limInf, limSup);
    } while (!entrada);

    do{    
        do{
            printf("Ingrese la bomba: ");
            fflush(stdin);
            fgets(bombaTeclado, TAMANIO_CADENA, stdin);
            entrada = numEnteros(bombaTeclado) && validarEnter(bombaTeclado);
        } while (!entrada);
        bomba = pasaje_String_A_int(bombaTeclado);
        entrada = numeroRango(bomba, limInf, limSup);
    } while (!entrada);
    
    //Llamada a la funcion recursiva:
    int *res = Explosion(numeroExplosivo, bomba, &cantidadPrueba);

    //IMPRIMIMOS EL RESULTADO DE LA OPERACION
    printf("\n*********************************************************\n");
    printf("Resultado de la explosion:\n");
    printf("N => %d\n", numeroExplosivo);
    printf("B => %d\n", bomba);
    printf("Arreglo: [");
    for (int i = 0; i < cantidadPrueba; i++) {
        printf("%d", res[i]);
        if (i != cantidadPrueba - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    printf("*********************************************************\n");
    fflush(stdin);
    //  free(res);
    printf("\n\n Presione ENTER para finalizar la ejecucion...");
    getchar();
    return 0;
}
