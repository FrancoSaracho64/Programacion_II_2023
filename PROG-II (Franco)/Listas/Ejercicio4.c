#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "funcionesEjercicios.h"
#define MAX_LENGTH 100 // longitud máxima de las listas

bool entrada = true;
int num_teclado, tamano_lista_int, n1_int;
char n1[25];
char tamano_lista[25];

int main() {
    //Presentacion
    system("cls");
    printf("***Ejercicio 4***\n\n");

    //Creamos las listas:
    Lista L1 = l_crear();
    Lista L2 = l_crear();

    // Preguntar cuantos valores tendra las listas
    do{   
        do{
            printf("===========================================================\n");
            printf("Ingrese el total de valores que quiere ingresar por lista:  ");
            fflush(stdin);
            fgets(tamano_lista, 25, stdin);
            entrada = numEnteros(tamano_lista) && validarEnter(tamano_lista) ;
        } while (!entrada);
        tamano_lista_int = pasaje_String_A_int(tamano_lista);
        entrada = esCero(tamano_lista_int) && numeroRango(tamano_lista_int,1,MAX_LENGTH);
    } while (!entrada);    
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
    // se imprimen las listas ingresadas
    printf("\n\n=====================================================\n");
    printf("Lista 1:\n");
    l_mostrarLista(L1);
    printf("\n=====================================================\n");
    printf("Lista 2:\n");
    l_mostrarLista(L2);
    printf("\n\n#################-----------####################\n");

    CompararL1L2(L1,L2); //      complejidad algoritmica es de O(n^2)
    
    printf("#################-----------####################\n\n");
    printf("Presione ENTER para finalizar el programa...");
    getchar();
}