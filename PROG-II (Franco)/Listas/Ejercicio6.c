#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "funcionesEjercicios.h"

// COMPLEJIDAD ALGORÍTMICA DE "es_sublista" es del tipo cuadrática, siendo esta: O(n*m).

// Hago uso del strtok para partir el string en tokens, (POR ESO PIDO QUE SEPAREN CON ESPACIOS). Entonces, le hago parsing a esos dos inputs separados por espacios convirtiendolos a 
// integers y mandandolos a las listas, para después hacer el checkeo de si es o no sublista.
// Los ciclos while iteran por cada token, y adentro de este loop es donde los convierten en integers.

//Inicializaciones
bool entrada = true;
char input[25];
int cantList1;
int cantList2;
int i;
bool hayEnter;

int main() {
    Lista lista1 = l_crear();
    Lista lista2 = l_crear();

    // primera lista
    printf("Lista 1...\n");
    do{   
        do{
            printf("Ingrese la cantidad de elementos: ");
            fflush(stdin);
            fgets(input, 25, stdin);
            entrada = numEnteros(input) && validarEnter(input) ;
        } while (!entrada);

        cantList1 = pasaje_String_A_int(input);
        entrada = esCero(cantList1) && numeroRango(cantList1,1,100);
    } while (!entrada);

    // Cargar la lista 1
    i = 0;
    hayEnter = false;
    while (l_longitud(lista1) < cantList1){
        do{
            printf("Ingrese el elemento de posicion [%d]: ", i + 1);
            fflush(stdin);
            fgets(input, TAMANO_NUM, stdin);
            if  (input[0] == '\n'){
                    printf("El dato ingresado es 'VACIO'.\n");
                    hayEnter = true;
                    entrada = true;
            }
            else {
                entrada = numEnteros(input);
                hayEnter = false; 
            }
            if (!hayEnter){
                int valor = pasaje_String_A_int(input);
                if (l_buscar(lista1, valor) == NULL){
                    l_agregar(lista1, te_crear(valor));
                    i++;
                }
                else {
                    printf("\nEl dato ingresado ya se encuentra cargado en la lista.\n");
                    entrada = false;
                }
            }
            else{
                i++;
                l_agregar(lista1, NULL);
            }
        } while (!entrada);
    }
        
    // segunda lista
    printf("\n\nLista 2...\n");
    do{   
        do{
            printf("Ingrese la cantidad de elementos: ");
            fflush(stdin);
            fgets(input, 25, stdin);
            entrada = numEnteros(input) && validarEnter(input) ;
        } while (!entrada);
        cantList2 = pasaje_String_A_int(input);
        entrada = esCero(cantList2) && numeroRango(cantList2,1,100);
    } while (!entrada);

    // Cargar la lista 2
    i = 0;
    hayEnter = false;
    while (l_longitud(lista2) < cantList2){
        do{
            printf("Ingrese el elemento de posicion [%d]: ", i + 1);
            fflush(stdin);
            fgets(input, TAMANO_NUM, stdin);
            if  (input[0] == '\n'){
                    printf("El dato ingresado es 'VACIO'.\n");
                    hayEnter = true;
                    entrada = true;
            }
            else {
                entrada = numEnteros(input);
                hayEnter = false; 
            }
            if (!hayEnter){
                int valor = pasaje_String_A_int(input);
                if (l_buscar(lista2, valor) == NULL){
                    l_agregar(lista2, te_crear(valor));
                    i++;
                }
                else {
                    entrada = false;
                    printf("El dato ingresado ya se encuentra cargado en la lista.\n");
                }
            }
            else{
                i++;
                l_agregar(lista2, NULL);
            }
        } while (!entrada);
    }

    printf("\n\n");
    printf("*********************************************************\n");
    bool es_sub = es_sublista(lista1, lista2);
    if (es_sub) {
        printf("La lista 2 es una sublista de la lista 1.\n");
    } else {
        printf("La lista 2 no es una sublista de la lista 1.\n");
    }
    printf("*********************************************************\n");
    printf("Presione ENTER para finalizar el programa...");
    getchar();
    return 0;
}