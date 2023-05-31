#include <sys/time.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "arbol-binario.h"
#include "funcionesEjercicios.h"
#include "arbol-Utilidades.h"
#include "TADs_y_extras\colas.h"
#include "TADs_y_extras\colas_utilidades.h"
#include "TADs_y_extras\listas.h"
#include "TADs_y_extras\pilas.h"
#include "TADs_y_extras\Validaciones.h"
#include "TADs_y_extras\tipo_elemento.h"

int main(){
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
    printf(" Se observa que el promedio de alturas de los dos tipos de arboles va aumentando segun la cantidad de nodos ingresados \n y la diferencia entre las alturas maximas y minimas en avl son iguales o diferencia de 1. \n En el tipo abb la diferencia entre los extremos va variando segun la cantidad de nodos, arboles y en que orden se generan.\n");

    getchar();
}

Cola cargarColaAleatoriamente(int cantidadNodos, int maximo){
    int numero, i = 0;
    bool entrada;
    Cola cola = c_crear();
    TipoElemento elemento;

    //srand(time(NULL));

    struct timeval tv;
    gettimeofday(&tv, NULL);
    unsigned int seed = tv.tv_sec * 10 + tv.tv_usec / 100
    ;
    srand(seed);

    while (i < cantidadNodos) {
        numero = 1 + rand() % maximo;
        entrada = c_elementoRepetido(cola, numero);
        if (entrada){
            elemento = te_crear(numero);
            c_encolar(cola, elemento);
            i++;
        }
    }
    //sleep(0.5);
    return cola;
}
