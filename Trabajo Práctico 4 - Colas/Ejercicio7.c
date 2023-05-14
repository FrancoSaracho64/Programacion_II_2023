#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "tipo_elemento.h"
#include "colas.h"
#include "colas_utilidades.h"
#include "funcionesEjercicios.h"

//Limites de Q
const int limSupe = 480; // 8 horas
const int limInfe = 1;

int main () {
    //Variables que utilizaremos en el main
    Cola c1 = c_crear();
    Cola c2 = c_crear();
    Cola c3 = c_crear();

    TipoElemento te;

    int cantidadMinutos;

    //Presentacion visual del ejercicio
    printf("\n  ************************************************");
    printf("\n  *                                              *");
    printf("\n  *             *** Ejercicio 7 ***              *");
    printf("\n  *           Atencion a los clientes            *");
    printf("\n  *                                              *");
    printf("\n  ************************************************");
    printf ("\n\n");

    //Carga de las 3 colas de clientes
    printf("**************************************************\n\n  CARGA DE LA COLA 1\n");
    c_cargar_positivos(c1);
    printf ("\n\n");
    printf("**************************************************\n\n  CARGA DE LA COLA 2\n");
    c_cargar_positivos(c2);
    printf ("\n\n");
    printf("**************************************************\n\n  CARGA DE LA COLA 3\n");
    c_cargar_positivos(c3);
    printf ("\n\n");

    //Mostramos las 3 colas ya cargadas
    printf("--------------------------------------------------\nColas cargadas correctamente.\n\n");
    printf("\nCola 1 -> ");
    c_mostrar(c1);
    printf("\n");
    printf("\nCola 2 -> ");
    c_mostrar(c2);
    printf("\n");
    printf("\nCola 3 -> ");
    c_mostrar(c3);
    printf("\n");

    if (c_es_vacia(c1) && c_es_vacia(c2) && c_es_vacia(c3)) printf("\n********* LAS TRES COLAS ESTAN VACIAS!!! *********\n");
    else{
        //Pedimos al usuario el dato Q (Cantidad de minutos dedicados a cada cola)
        char tiempoTeclado[TAMANO_NUM];
        bool entradaA = true;
        do {
            do{
                printf("--------------------------------------------------\n");
                printf("TIEMPO...\n");
                printf("\nIngrese la cantidad de minutos que va a dedicar el empleado para atender a cada cola:  ");
                fflush(stdin);
                fgets(tiempoTeclado, TAMANO_NUM, stdin);
                entradaA = numEnteros(tiempoTeclado) && validarEnter(tiempoTeclado);
            } while (!entradaA);
        cantidadMinutos = pasaje_String_A_int(tiempoTeclado);
        entradaA = numeroRango(cantidadMinutos, limInfe, limSupe);
        } while (!entradaA);
        printf("\n--------------------------------------------------\n");
        //Printeamos el orden obtenido llamando a la funcion...
        printf("\nImprimiendo el resultado...");
        printf("\nOrden en el cual el empleado atiende a los clientes de las respectivas colas -> \n\n");
        atenderTresVentanillas(cantidadMinutos, c1, c2, c3);
    }
    printf("\n\nPresione ENTER para salir... ");
    getchar();
    return 0;
}