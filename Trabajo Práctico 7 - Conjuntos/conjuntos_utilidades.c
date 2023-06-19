#include <stdio.h>
#include <stdlib.h>

#include "conjuntos.h"
#include "conjuntos_utilidades.h"
#include "TADs_y_extras\listas.h"
#include "TADs_y_extras\Validaciones.h"

/*Cargar un conjunto*/
void cto_cargar(Conjunto c) {

    //Inicializaciones
    bool entrada = true;
    char num[TAMANO_NUM];
    int cantidadElementos, opcion, numero, i = 0;
    TipoElemento elemento;

    printf("\n**************************************************\nCargar Conjunto\n\n");

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
    while (i < cantidadElementos){
        do{
            printf("Ingrese el elemento numero [%d]: ", i + 1);
            fflush(stdin);
            fgets(num, TAMANO_NUM, stdin);
            entrada = numEnteros(num) && validarEnter(num);
        } while (!entrada);
        i++;
        numero = pasaje_String_A_int(num);
        elemento = te_crear(numero);
        cto_agregar (c, elemento);
    }
}

void cto_cargar_Naturales(Conjunto c) {

    //Inicializaciones
    bool entrada = true;
    char num[TAMANO_NUM];
    int cantidadElementos, opcion, numero, i = 0;
    TipoElemento elemento;

    printf("\n**************************************************\nCargar Conjunto\n\n");

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
    while (i < cantidadElementos){
        do{
            do{
                printf("Ingrese el elemento numero [%d]: ", i + 1);
                fflush(stdin);
                fgets(num, TAMANO_NUM, stdin);
                entrada = numEnteros(num) && validarEnter(num);
            } while (!entrada);
            numero = pasaje_String_A_int(num);
            entrada = numeroRango(numero, 1, 2000000000);
        } while (!entrada);
        i++;
        
        elemento = te_crear(numero);
        cto_agregar (c, elemento);
    }
}