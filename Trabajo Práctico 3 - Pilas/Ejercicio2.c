#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tipo_elemento.h"
#include "pilas.h"
#include "Validaciones.h"
#include "pilas_utilidades.h"
#include "funcionesEjercicios.h"
#include "funcionesMenu_Ejercicio2.h"

int main () {
    //Inicializaciones
    Pila p = p_crear();
    TipoElemento te;
    int opc;
    char opcTeclado[TAMANO_NUM];
    bool entrada = true;
    //Presentacion...
    printf("*** Ejercicio 2 ***\n");
    printf("Trabajando con las pilas...\n\n");
    // Funcion...
    //Cargamos la pila
    cargarPila(p);
    printf("\nPila ingresada -> ");
    p_mostrar(p);
    printf("--------------------------------------------------");
    
    do {
        //  MENU PROGRAMA -----------------------------------------------------
        printf("\n\n\t-*-*-* MENU PROGRAMA *-*-*-\n\n");
        printf("1- Ejercicio A: Buscar una clave y determinar si existe en la Pila\n");
        printf("2- Ejercicio B: Colocar en una posicion ordinal determinada un nuevo elemento\n");
        printf("3- Ejercicio C: Eliminar de una pila un elemento dado\n");
        printf("4- Ejercicio D: Intercambiar los valores de 2 posiciones ordinales de la pila\n");
        printf("5- Ejercicio E: Duplicar el contenido de una pila\n");
        printf("6- Ejercicio F: Contar los elementos de la pila\n");
        printf("\n0- Salir del programa\n");

        do {
            do{
                printf("\nElija el punto al que desea acceder: ");
                fflush(stdin);
                fgets(opcTeclado, TAMANO_NUM, stdin);
                entrada = numEnteros(opcTeclado) && validarEnter(opcTeclado);
            } while (!entrada);
        opc = pasaje_String_A_int(opcTeclado);
        } while (!entrada);

        switch (opc) {
            case 0:
                printf("\n¡Finalizando ejecucion!\n");
                printf("Presione ENTER para cerrar el programa.");
                getchar();
                break;
            case 1:
                Ejercicio1(p);
                printf("\nPila Original -> ");
                p_mostrar(p);
                break;
            case 2:
                Ejercicio2(p);
                printf("\nPila Original -> ");
                p_mostrar(p);
                break;
            case 3:
                Ejercicio3(p);
                printf("\nPila Original -> ");
                p_mostrar(p);
                break;
            case 4:
                Ejercicio4(p);
                printf("\nPila Original -> ");
                p_mostrar(p);
                break;
            case 5:
                Ejercicio5(p);
                printf("\nPila Original -> ");
                p_mostrar(p);
                break;
            case 6:
                Ejercicio6(p);
                printf("\nPila Original -> ");
                p_mostrar(p);
                break;
            default:
                printf("\n-------------------------ERROR-------------------------");
                printf("\nLa opcion ingresada es incorrecta. Vuelva a intentar...\n");
                printf("-------------------------------------------------------\n\n");
                break;
        }
    } while (opc != 0);
    return 0;
}