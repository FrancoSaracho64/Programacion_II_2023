#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "funcionesEjercicios.h"
int main(){
    //Presentacion
    system("cls");
    printf("***Ejercicio 10***\n");
    printf("Operaciones con arboles ABB y AVL...\n\n"); 
    //Inicializaciones importantes
    int cantidadNodos;
    int i = 0, x = 1;
    int numero;
    int maximo;
    int altura_abb = 0;
    int altura_avl = 0;
    int total_altura_abb = 0;
    int total_altura_avl = 0;
    int promedio_abb = 0;
    int promedio_avl = 0;
    int contador_arboles = 0;
    int cant_arboles;
    int altura_min_abb = 2002;
    int altura_max_abb = 0;
    int altura_min_avl = 2002;
    int altura_max_avl = 0;
    bool entrada; 
    char num[TAMANO_NUM];
    TipoElemento elemento;
    
    do{
        do{
            printf("Ingrese la cantidad de nodos a generar/cargar: ");
            fflush(stdin);
            fgets(num, TAMANO_NUM, stdin);
            entrada = numEnteros(num) && validarEnter(num);
        } while (!entrada);
        cantidadNodos = pasaje_String_A_int(num);  
        entrada = numeroRango(cantidadNodos, 0, 2000);
    } while (!entrada);

    printf("\n");

    do{
        do{
            printf("Ingrese el valor maximo de los numeros a generar/cargar: ");
            fflush(stdin);
            fgets(num, TAMANO_NUM, stdin);
            entrada = numEnteros(num) && validarEnter(num);
        } while (!entrada);
        maximo = pasaje_String_A_int(num);  
        entrada = numeroRango(maximo, cantidadNodos, 100000);
    } while (!entrada);
    printf("\n");

    do{
        do{
            printf("Ingrese la cantidad de arboles a generar/cargar: ");
            fflush(stdin);
            fgets(num, TAMANO_NUM, stdin);
            entrada = numEnteros(num) && validarEnter(num);
        } while (!entrada);
        cant_arboles = pasaje_String_A_int(num);  
        entrada = numeroRango(cant_arboles, 1, 200);
    } while (!entrada);
    
    Cola colaAleatoria = c_crear();
    do{
        ArbolBinarioBusqueda   arbol_binario_busqueda  =   abb_crear();
        ArbolAVL               arbol_binario_alv       =   avl_crear();
        colaAleatoria = cargarColaAleatoriamente(cantidadNodos, maximo);
        while (!c_es_vacia(colaAleatoria)) {
            elemento = c_recuperar(colaAleatoria);
            abb_insertar(arbol_binario_busqueda, elemento);
            avl_insertar(arbol_binario_alv, elemento);
            c_desencolar(colaAleatoria);
        }
        
        altura_abb =  altura_nodo(abb_raiz(arbol_binario_busqueda));
        altura_avl = altura_nodo(avl_raiz(arbol_binario_alv));

        total_altura_abb = total_altura_abb + altura_abb;
        total_altura_avl = total_altura_avl + altura_avl;

        if (altura_abb < altura_min_abb){
            altura_min_abb = altura_abb;
        }
        if (altura_abb > altura_max_abb){
            altura_max_abb = altura_abb;
        }
        if (altura_avl < altura_min_avl){
            altura_min_avl = altura_avl;
        }
        if (altura_avl > altura_max_avl){
            altura_max_avl = altura_avl;
        }
        contador_arboles++;
        free(arbol_binario_busqueda);
        free(arbol_binario_alv);
    } while(contador_arboles != cant_arboles);

    promedio_abb = (total_altura_abb/cant_arboles);
    promedio_avl = (total_altura_avl/cant_arboles);
    printf("Altura minima del binario de busqueda: %d\n", altura_min_abb);
    printf("Altura maxima del binario de busqueda: %d\n\n", altura_max_abb);
    
    printf("Altura minima del AVL: %d\n", altura_min_avl);
    printf("Altura maxima del AVL: %d\n\n", altura_max_avl);

    printf("El promedio de las alturas de todos los arboles ABB es: %d\n", promedio_abb);
    printf("El promedio de las alturas de todos los arboles AVL es: %d\n\n", promedio_avl);
    printf("\n");

    printf(" *** Conclusion: ***\n ");
    printf(" Se observa que, por un lado, la diferencia entre las alturas maximas y minimas en AVL son\n siempre iguales o tienen diferencia de 1.\n Por otro lado, en el tipo  ABB,  la  diferencia entre  los extremos  va  variando segun la\n cantidad de nodos, la cantidad de arboles y el orden en que se generan.\n");
    printf("\n\nPresione ENTER para salir...");
    getchar();
}