#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "funcionesEjercicios.h"


int main(){
//Presentacion
    system("cls");
    printf("***Ejercicio 8***\n");
    printf("Operaciones con arboles n-narios...\n\n");

    // Inicializaciones
    int opcion, altura;
    bool entrada = true;
    char num[TAMANO_NUM];

    ArbolBinario arbol1 = a_crear();
    printf("\n***** ARBOL 1 *****\n\n");
    a_cargar_n_ario(arbol1);   
    printf("\n\n"); 
    Lista resultado_ejer3 = l_crear();
    bool resultado_4;
    
    do{
        do{
            menuPrincipalEjer8();
            fflush(stdin);
            fgets(num, TAMANO_NUM, stdin);
            entrada = numEnteros(num) && validarEnter(num);
        } while (!entrada);
        opcion = pasaje_String_A_int(num);

        switch (opcion) {
            case 1: // Determinar la altura del mismo. 
                if (!a_es_vacio(arbol1)){
                    altura = alturaArbolNario(arbol1);
                    printf("\nLa altura del arbol es: %d", altura);
                } else {
                    printf("El arbol no posee altura, debido a que el arbol ingresado esta vacio (Raiz ---> NULL)");
                }
                printf("\n********************************************\n\n");
                break;
            case 2: // Determinar el nivel de un nodo. 
                if (!a_es_vacio(arbol1)){
                    do{
                        fflush(stdin);
                        printf("Ingrese la clave del nodo del cual quiera conocer su nivel: ");
                        fgets(num, TAMANO_NUM, stdin);
                        entrada = numEnteros(num) && validarEnter(num);
                    } while (!entrada);
                    int clave = pasaje_String_A_int(num);
                    int altura_nodo = alturaNodoNario(arbol1, clave);
                    if (altura_nodo != -1)
                        printf("\nLa altura del nodo es: %d", altura_nodo);
                    else
                        printf("\nLa clave ingresada NO se ha encontrado dentro del arbol.");
                } else { 
                    printf("El arbol esta vacio. No se puede ejecutar este item.");
                    entrada = false;
                }
                printf("\n********************************************\n\n");
                break;
            case 3: // Listar todos los nodos internos (solo las claves). 
                //Si el hmno DERECHO es != NULL... entonces es un nodo INTERNO.
                resultado_ejer3 = nodosInternosNario(arbol1);
                if (!l_es_vacia(resultado_ejer3)){
                    printf("Los nodos internos del arbol son...\n");
                    l_mostrarLista(resultado_ejer3);
                } else {
                    printf("No hay nodos internos dentro del arbol.");
                }
                printf("\n********************************************\n\n");
                break;
            case 4: // Determinar si todas las hojas están al mismo nivel.
                resultado_4 = hojasMismoNivelNario(arbol1);
                if (resultado_4) 
                    printf("\nTodas las hojas del arbol tienen el mismo nivel.");
                else 
                    printf("\nLas hojas del arbol se encuentran en niveles variados.");
                printf("\n********************************************\n\n");
                break;
            case 0:
                printf("Finalizando ejecucion del programa.\n");
                printf("\n********************************************\n\n");
                break;
            default:
                printf("\n\n*****************************************************************\n");
                printf("       Ha introducido un valor erroneo. Vuelva a intentar.\n");
                printf("*****************************************************************\n\n");
                entrada = false;
                break;
        }
    } while  (!entrada);
    
    printf("\nPresione ENTER para finalizar el programa...");
    getchar();
    return 0;
}