#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tipo_elemento.h"
#include "pilas.h"
#include "Validaciones.h"
#include "pilas_utilidades.h"
#include "funcionesEjercicios.h"

/* Ejercicio 6 */
int main(){
    //Inicializaciones
    int opcion, numero;
    bool entrada = true;
    char num[TAMANO_NUM];
    //Presentacion
    printf("***Ejercicio 6***\n");
    printf("Eliminar un elemento/numero de una pila...\n\n");

    //Complejidad algoritmica...
    printf("------------------------------------------------------------------------------\nCOMPLEJIDAD ALGORITMICA: \n");
    printf("En este ejercicio, tanto la funcion iterativa como la funcion recursiva tienen\nuna complejidad algoritmica del tipo O(n) ya que ambas, en el peor de los casos\ntienen que recorrer una pila hasta que esta este totalmente vacia.\nDependiendo de la cantidad de elementos el trabajo sera mayor o menor.");
    printf("\n------------------------------------------------------------------------------\n\n\n");

    //Funcion...
    do{
        do{
            menu();
            fflush(stdin);
            fgets(num, TAMANO_NUM, stdin);
            entrada = numEnteros(num) && validarEnter(num);
        } while (!entrada);
        opcion = pasaje_String_A_int(num);

        // Creo la pila que van a recibir ambas funciones.
        Pila pila_Usuario = p_crear();
        Pila resultado = p_crear();
        //Creo pilas y variables para la funcion recursiva
        Pila pila_aux = p_crear();
        Pila pila_sinNumero = p_crear();
        bool encontrado = false;

        // Analizamos la opcion elegida por el usuario:
        switch (opcion) {
            case 1:
                /* Carga de PILA */
                cargarPila(pila_Usuario);
                // Pido el numero a buscar y eliminar
                if (!p_es_vacia(pila_Usuario)){
                    do{
                        do{
                            printf("\nIngrese el numero a buscar/eliminar de la pila creada: ");
                            fflush(stdin);
                            fgets(num, TAMANO_NUM, stdin);
                            entrada = numEnteros(num) && validarEnter(num);
                        } while (!entrada);
                        numero = pasaje_String_A_int(num);
                    entrada = numeroRango(numero,0,100);
                    } while (!entrada);
                    //Llamada a la funcion iterativa.
                    resultado = eliminarElemento_iterativo(pila_Usuario, numero);
                }

                if (p_es_vacia(resultado)){
                    printf("\n\n**************************************************\n");
                    printf("---------****** La pila está VACIA ******---------");
                    printf("\n**************************************************\n\n");
                } else {
                    printf("\n\n---------Pila original---------\n");
                    p_mostrar(pila_Usuario);
                    printf("\n********************************************\n\n");
                    printf("---------Pila obtenida---------\n");
                    p_mostrar(resultado);
                    printf("\n********************************************\n\n");
                }
                printf("Presione ENTER para finalizar el programa...");
                getchar();
                break;
            case 2:    
                /* Carga de PILA */
                cargarPila(pila_Usuario);
                if (!p_es_vacia(pila_Usuario)){
                    // Pido el numero a buscar y eliminar
                    do{
                        do{
                            printf("\nIngrese el numero a buscar/eliminar de la pila creada: ");
                            fflush(stdin);
                            fgets(num, TAMANO_NUM, stdin);
                            entrada = numEnteros(num) && validarEnter(num);
                        } while (!entrada);
                        numero = pasaje_String_A_int(num);
                        entrada = numeroRango(numero,0,100);
                    } while (!entrada);
                    //Llamada a la funcion recursiva.
                    resultado = eliminarElemento_recursivo(pila_Usuario, pila_aux, pila_sinNumero, encontrado, numero);
                }
                
                if (p_es_vacia(resultado)){
                    printf("\n\n**************************************************\n");
                    printf("---------****** La pila está VACIA ******---------");
                    printf("\n**************************************************\n\n");
                } else {
                    printf("\n\n---------Pila original---------\n");
                    p_mostrar(pila_Usuario);
                    printf("********************************************\n");
                    printf("---------Pila obtenida---------\n");
                    p_mostrar(resultado);
                    printf("\n********************************************\n\n");
                }
                printf("Presione ENTER para finalizar el programa...");
                getchar();
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
    
    return 0;
}