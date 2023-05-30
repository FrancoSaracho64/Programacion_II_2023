#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "arbol-binario.h"
#include "funcionesEjercicios.h"
#include "arbol-Utilidades.h"
#include "TADs_y_extras\colas.h"
#include "TADs_y_extras\listas.h"
#include "TADs_y_extras\pilas.h"
#include "TADs_y_extras\Validaciones.h"
#include "TADs_y_extras\tipo_elemento.h"

int main(){
//Presentacion
    system("cls");
    printf("***Ejercicio 4***\n");
    printf("Operaciones con arboles n-narios...\n\n");

    // Inicializaciones
    int opcion;
    bool entrada = true;
    char num[TAMANO_NUM];

    Lista resultado_A = l_crear();
    Lista resultado_E = l_crear();

    ArbolBinario arbol1 = a_crear();
    ArbolBinario arbol2 = a_crear();
    printf("\n***** ARBOL 1 *****\n\n");
    a_cargar_n_ario(arbol1);    
    int cant_hojas, clave;
    
    do{
        do{
            menuPrincipalEjer4();
            fflush(stdin);
            fgets(num, TAMANO_NUM, stdin);
            entrada = numEnteros(num) && validarEnter(num);
        } while (!entrada);
        opcion = pasaje_String_A_int(num);

        switch (opcion) {
            case 1:
                resultado_A = arbolEnlistado(a_raiz(arbol1));
                l_mostrarLista(resultado_A);
                printf("\n********************************************\n\n");
                break;
            case 2:
                cant_hojas = cantHojas_n_ario(arbol1);
                printf("El arbol tiene %d hojas.", cant_hojas);

                printf("\n********************************************\n\n");
                break;
            case 3:
                printf("El ARBOL 1 fue cargado previamente. A continuacion, debe cargar el ARBOL 2...\n\n");
                a_cargar_n_ario(arbol2);   
                //Llamamos a la funcion...
                if (sonSimilares(a_raiz(arbol1), a_raiz(arbol2))) {
                        printf("Arbol 1 y Arbol 2 son similares.\n");
                    } else {
                        printf("Arbol 1 y Arbol 2 -NO- son similares.\n");
                    }                
                printf("\n********************************************\n\n");
                break;
            case 4:
                do{
                    fflush(stdin);
                    printf("Ingrese la clave del nodo del cual quiera conocer su padre: ");
                    fgets(num, TAMANO_NUM, stdin);
                    entrada = numEnteros(num) && validarEnter(num);
                } while (!entrada);
                clave = pasaje_String_A_int(num);
                //Llamada a la funcion
                NodoArbol resultado = nodoPadre(arbol1, clave);
                if (resultado == NULL){
                    printf("Ha preguntado por el padre de la RAIZ... ---> No tiene padre.");
                } else {
                    printf("El padre del nodo ingresado es: %d", n_recuperar(resultado)->clave);
                }
                printf("\n********************************************\n\n");
                break;
            case 5:
                do{
                    fflush(stdin);
                    printf("Ingrese la clave del nodo del cual quiera conocer sus hermanos: ");
                    fgets(num, TAMANO_NUM, stdin);
                    entrada = numEnteros(num) && validarEnter(num);
                } while (!entrada);
                clave = pasaje_String_A_int(num);
                resultado_E = hermanosNodoNario(arbol1, clave);
                printf("Los hermanos del nodo ingresado son: \n");
                l_mostrarLista(resultado_E);
                printf("\n********************************************\n\n");
                break;
            case 0:
                printf("Finalizando ejecucion del programa.\n");
                printf("Presione ENTER para finalizar el programa...");
                getchar();
                break;
            default:
                printf("\n\n*****************************************************************\n");
                printf("       Ha introducido un valor erroneo. Vuelva a intentar.\n");
                printf("*****************************************************************\n\n");
                entrada = false;
                break;
        }
    } while (!entrada);
    
    printf("\nPresione ENTER para finalizar el programa...");
    getchar();
    return 0;
}