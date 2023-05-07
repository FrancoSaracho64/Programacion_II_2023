#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "pilas_utilidades.h"
#include "Validaciones.h"

void p_intercambiar (Pila P, Pila Paux) {
    TipoElemento te;
    while (p_es_vacia(Paux) != true) {
        te = p_desapilar(Paux);
        p_apilar(P, te);
    }    
}

// Funcion que se encarga de cargar la lista en cada caso.
void cargarPila(Pila pila){
    //Inicializaciones
    bool entrada = true;
    char num[TAMANO_NUM];
    int cantidadElementos, opcion, numero, i = 0;
    TipoElemento elemento;

    do{
        do{
            printf("\n**************************************************\n¿Como quiere cargar la pila?\n1. Manualmente\n2. Aleatoriamente\n\n");
            printf("INGRESE UNA OPCION: ");
            fflush(stdin);
            fgets(num, TAMANO_NUM, stdin);
            entrada = numEnteros(num) && validarEnter(num);
        } while (!entrada);
        opcion = pasaje_String_A_int(num);
        switch (opcion) {
            case 1:
                do{
                    do{
                        printf("Ingrese la cantidad de elementos a cargar: ");
                        fflush(stdin);
                        fgets(num, TAMANO_NUM, stdin);
                        entrada = numEnteros(num) && validarEnter(num);
                    } while (!entrada);
                    cantidadElementos = pasaje_String_A_int(num);  
                    entrada = numeroRango(cantidadElementos,0,100);
                } while (!entrada);
                int x = cantidadElementos;
                while (i < cantidadElementos){
                    do{
                        printf("Ingrese el elemento de posicion [%d]: ", x);
                        fflush(stdin);
                        fgets(num, TAMANO_NUM, stdin);
                        entrada = numEnteros(num) && validarEnter(num);
                    } while (!entrada);
                    i++;
                    x--;
                    numero = pasaje_String_A_int(num);
                    elemento = te_crear(numero);
                    p_apilar(pila, elemento);
                }
                break;
            case 2:
                do{
                    do{
                        printf("Ingrese la cantidad de elementos a cargar: ");
                        fflush(stdin);
                        fgets(num, TAMANO_NUM, stdin);
                        entrada = numEnteros(num) && validarEnter(num);
                    } while (!entrada);
                    cantidadElementos = pasaje_String_A_int(num);  
                    entrada = numeroRango(cantidadElementos,0,100);
                } while (!entrada);
                srand(time(NULL));
                while (i < cantidadElementos) {
                    numero = rand() % 101;
                    elemento = te_crear(numero);
                    p_apilar(pila, elemento);
                    i++;
                }
                break;
            default:
                printf("\n\n***************************************************\n");
                printf("Ha introducido un valor erroneo. Vuelva a intentar.\n");
                printf("***************************************************\n\n");
                entrada = false;
                break;
        }
    } while (!entrada);
    return;
}