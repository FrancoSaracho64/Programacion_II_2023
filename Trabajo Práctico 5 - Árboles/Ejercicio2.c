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

int main() {
    //Presentacion
    system("cls");
    printf("***Ejercicio 2***\n");
    printf("Operaciones con un arbol binario no vacio...\n\n");

    // Inicializaciones
    int numero, opcion;
    bool entrada = true;
    char num[TAMANO_NUM];

    ArbolBinario arbolBinario = a_crear(); // Creamos el arbol
    a_cargar_binario(arbolBinario);

    Lista resultado_A = l_crear();
    Lista resultado_B = l_crear();
    Lista resultado_C = l_crear();
    
    do{
        do{
            menuPrincipalEjer2();
            fflush(stdin);
            fgets(num, TAMANO_NUM, stdin);
            entrada = numEnteros(num) && validarEnter(num);
        } while (!entrada);
        opcion = pasaje_String_A_int(num);
        switch (opcion) {
            case 1:
                //a.
                resultado_A = ejercicio2A(arbolBinario);
                l_mostrarLista(resultado_A);
                printf("\n********************************************\n\n");
                break;

            case 2:
                //b. 
                resultado_B = ejercicio2B(arbolBinario);
                l_mostrarLista(resultado_B);
                printf("\n********************************************\n\n");
                break;
            case 3:
                //c. 
                do{
                    fflush(stdin);
                    printf("Ingrese la clave que quiere buscar dentro del arbol: ");
                    fgets(num, TAMANO_NUM, stdin);
                    entrada = numEnteros(num) && validarEnter(num);
                } while (!entrada);
                numero = pasaje_String_A_int(num);
                TipoElemento elem = te_crear(numero);

                resultado_C = ejercicio2C(arbolBinario, elem);
                
                if (l_es_vacia(resultado_C)){
                    printf("LISTA VACIA!!! --- NO HAY COINCIDENCIAS.\n");
                }
                else{
                    printf("Contenido de la lista...\n");
                    Iterador iter = iterador(resultado_C);
                    while (hay_siguiente(iter)) {
                        elem = siguiente(iter);
                        printf("Clave: %d / Puntero: %p\n", elem->clave, elem->valor);
                    }
                }
                printf("\n********************************************\n\n");
                break;
            case 4:
                //d. 
                ejercicio2D();
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
                break;
        }
    } while  (opcion != 0);
    return 0;
}