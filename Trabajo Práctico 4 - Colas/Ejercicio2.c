#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "tipo_elemento.h"
#include "colas.h"
#include "colas_utilidades.h"
#include "Validaciones.h"
#include "funcionesEjercicio2.h"
#include "pilas.h"
#include "pilas_utilidades.h"

const int limSupOPC = 6;
const int limInfOPC = 0;

int main () {
    //Bienvenida
    printf("*** Ejercicio 2 ***\n");
    printf("Operaciones con una Cola...\n\n");
    //Creamos la cola
    Cola c = c_crear();
    TipoElemento te;
    //Cargamos la cola
    c_cargar(c);
    printf("\n");
    //Mostramos la cola cargada
    printf("La cola obtenida es --> ");
    c_mostrar(c);

    //*-*-*-*-*-*-*-*-*-*-*- MENU PROGRAMA *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
    int opc;
    char opcTeclado[TAMANO_NUM];
    bool entrada = true;
    do {
        printf("\n\n                 -*-*-* Menu principal *-*-*-\n\n");
        printf("1 - Ejercicio A: Verificar si un elemento se encuentra en la cola.\n");
        printf("2 - Ejercicio B: Agregar un nuevo elemento en una posicion determinada.\n");
        printf("3 - Ejercicio C: Eliminar todas las ocurrencias de un elemento en la cola.\n");
        printf("4 - Ejercicio D: Contar los elementos de la cola.\n");
        printf("5 - Ejercicio E: Realizar una copia de una cola.\n");
        printf("6 - Ejercicio F: Invertir del contenido de una cola.\n\n");
        printf("0 - Salir del programa.\n");
        do {
            do {
                printf("\nElija el punto al que desea acceder: ");
                fflush(stdin);
                fgets(opcTeclado, TAMANO_NUM, stdin);
                entrada = numEnteros(opcTeclado) && validarEnter(opcTeclado);
            } while (!entrada);
        opc = pasaje_String_A_int(opcTeclado);
        entrada = numeroRango(opc, limInfOPC, limSupOPC);
        } while (!entrada);
        printf("\n\n");
        switch (opc) {
            case 0:
                printf("Finalizando ejecucion del programa...\nPresione ENTER para cerrar...");
                getchar();
                break;
            case 1:
                printf("************************************************************\n");
                Ejercicio1(c);
                printf("\n************************************************************\n");
                printf("\nCola Original -> ");
                c_mostrar(c);
                break;
            case 2:
                printf("************************************************************\n");
                Ejercicio2(c);
                printf("\n************************************************************\n");
                printf("\nCola Original -> ");
                c_mostrar(c);
                break;
            case 3:
                printf("************************************************************\n");
                Ejercicio3(c);
                printf("\n************************************************************\n");
                printf("\nCola Original -> ");
                c_mostrar(c);
                break;
            case 4:
                printf("************************************************************\n");
                Ejercicio4(c);
                printf("\n************************************************************\n");
                printf("\nCola Original -> ");
                c_mostrar(c);
                break;
            case 5:
                printf("************************************************************\n");
                Ejercicio5(c);
                printf("\n************************************************************\n");
                printf("\nCola Original -> ");
                c_mostrar(c);
                break;
            case 6:
                printf("************************************************************\n");
                Ejercicio6(c);
                printf("\n************************************************************\n");
                printf("\nCola Original -> ");
                c_mostrar(c);
                break;
            default:
                break;
        }
    } while (opc != 0);
    return 0;
}