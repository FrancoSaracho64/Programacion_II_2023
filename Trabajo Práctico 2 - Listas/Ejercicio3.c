// Importaciones
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "listas.h"
#include "tipo_elemento.h"
#include "funcionesEjercicios.h"
#include "Validaciones.h"

// Inicializaciones
bool entrada = true, completada, resultado;
int num_teclado, resultado_escalar, tamano_lista_int, n1_int;
char n1[25];
char tamano_lista[25];

int main(){   
    //Presentacion
    system("cls");
    printf("***Ejercicio 3***\n\n");

    // Creacion de listas
    Lista L1 = l_crear();
    Lista L2 = l_crear();
    // Preguntar cuantos valores tendra las listas
    do{   
        do{
            printf("===========================================================\n");
            printf("Ingrese el total de valores que quiere ingresar por lista:  ");
            fflush(stdin);
            fgets(tamano_lista, 25, stdin);
            entrada = numEnteros(tamano_lista) && validarEnter(tamano_lista);
        } while (!entrada);
        tamano_lista_int = pasaje_String_A_int(tamano_lista);
        entrada = esCero(tamano_lista_int);
    } while (!entrada);
    
    Iterador iter1 = iterador(L1);
    Iterador iter2 = iterador(L2);
    int i = 0;

    // Completo con valores a la lista 1
    printf("\n=====================================================\n");
    printf("Completar Lista 1 \n");
    while (l_longitud(L1) < tamano_lista_int){
        do{
            do{
                printf("\n");
                printf("Ingrese el elemento de posicion [%d]: ", i + 1);
                fflush(stdin);
                fgets(n1, 25, stdin);
                entrada = numEnteros(n1) && validarEnter(n1);
            } while (!entrada);
            n1_int = pasaje_String_A_int(n1);
            entrada = esCero(n1_int);
        } while (!entrada);
        i++;
        num_teclado = pasaje_String_A_int(n1);

        TipoElemento elem = te_crear(num_teclado);
        l_agregar(L1, elem);
    }
    printf("\n=====================================================\n");
    printf("Completar Lista 2 \n");
    i = 0;
    // Completo con valores a la lista 2
    while (l_longitud(L2) < tamano_lista_int){
        do{
            printf("\n");
            printf("Ingrese el elemento de posicion [%d]: ", i + 1);
            fflush(stdin);
            fgets(n1, 25, stdin); 
            entrada = numEnteros(n1) && validarEnter(n1);
        } while (!entrada);
        i++;
        num_teclado = pasaje_String_A_int(n1);
        TipoElemento elem = te_crear(num_teclado);
        l_agregar(L2, elem);
    }
    //Muestro lista 1
    printf("\n\n");
    printf("=====================================================\n");
    printf("Lista 1: ");
    l_mostrarLista(L1);
    printf("\n");
    //Muestro lista 2
    printf("Lista 2: ");
    l_mostrarLista(L2);
    printf("=====================================================\n");
    printf("\n");

    //LLamo a la funcion de multiplos de listas
    resultado = multiplo_listas(L1, L2);

    if (resultado){
        //Si "resultado" es True, muestro por pantalla que L2 es multiplo de L1
        printf("La lista 2 es multiplo de la lista 1 \n\n");
        resultado_escalar = escalar_multiplo(L1, L2);
        if (resultado_escalar != 0){
            //Si resultado escalar no retorna '0', tiene escalar, y se muestra por pantalla
            printf("%d, es el numero escalar de la lista 1 \n", resultado_escalar);
        }
        else{
            //Si retorna '0', no contiene escalar
            printf("No presenta ningun escalar \n");
        }
    }
    else{
        //Si resultado es False, la lista 2 no es multiplo de la lista 1
        printf("La lista 2 no es multiplo de la lista 1 \n");
    }
    printf("Presione ENTER para finalizar el programa...");
    getchar();
    return 0;
}
