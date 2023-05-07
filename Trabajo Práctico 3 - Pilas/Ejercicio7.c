#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tipo_elemento.h"
#include "pilas.h"
#include "Validaciones.h"
#include "pilas_utilidades.h"
#include "funcionesEjercicios.h"

/* Ejercicio 7 */
int main(){
    //Inicializaciones
    int numero, cantP1, cantP2;
    bool entrada = true;
    char num[TAMANO_NUM];
    Pila pila_1 = p_crear();
    Pila pila_2 = p_crear();

    //Presentacion
    printf("***Ejercicio 7***\n");
    printf("Elementos en comun entre dos pilas...\n\n");

    //Complejidad algoritmica...
    printf("------------------------------------------------------------------------------\nCOMPLEJIDAD ALGORITMICA: \n");
    printf("En este ejercicio  nos  encontramos  con  una  complejidad  del  tipo  O(n^3).\nEn  la  funcion  que creamos  para  resolver  el ejercicio vamos a recorrer la\nPILA1, y por cada elemento de ella vamos a recorrer la PILA2 para comparar sus\ncontenidos  y  asi  poder  determinar  si  estos elementos  son  iguales o no.\nEn caso de que  sean  iguales, vamos recorrer  la  PILA  que vamos a  retornar\n(pila donde se almacenan los elementos en comun)  y verificar que el  elemento\nNO se haya cargado anteriormente.\nDecimos que tenemos una complejidad del tipo  O(n^3)  ya que recorremos, en el\npeor de los casos, 3 pilas distintas N veces.");
    printf("\n------------------------------------------------------------------------------\n\n\n");
    
    //Funcion...
    //Cargo la PILA 1
    printf("\n**************************************************\n");
    printf("              Carga de la PILA 1...");
    cargarPila(pila_1);
    printf("\n++++++++++++++++++++++++++++++++++++++\n Pila 1 cargada/creada correctamente.\n++++++++++++++++++++++++++++++++++++++\n\n");
    
    //Cargo la PILA 2
    printf("\n**************************************************\n");
    printf("              Carga de la PILA 2...");
    cargarPila(pila_2);
    printf("\n++++++++++++++++++++++++++++++++++++++\nPila 2 cargada/creada correctamente.\n++++++++++++++++++++++++++++++++++++++\n\n");
    
    //Llamada de la funcion principal
    if (p_es_vacia(pila_1) && p_es_vacia(pila_2)) {
        printf("\n\n********************************************************\n");
        printf("---------****** Ambas pilas están VACIAS ******---------");
        printf("\n********************************************************\n\n");
    } else if (p_es_vacia(pila_1) || p_es_vacia(pila_2)) {
        printf("\n\n***************************************************************\n");
        printf("---------****** Una de las dos pilas está VACIA ******---------");
        printf("\n***************************************************************\n\n");
    } else {
        printf("\n"); 
        printf("---------Pilas originales---------\n");
        printf("                      ___ PILA 1 ___\n");
        p_mostrar(pila_1);
        printf("\n");
        printf("                      ___ PILA 2 ___\n");
        p_mostrar(pila_2);
        printf("\n");
        printf("***********************************************************\n");
        printf("---------Pila obtenida con los elementos repetidos---------\n");
        p_mostrar(elementosEnComun(pila_1, pila_2));
        printf("\n***********************************************************\n\n");
    }
    printf("Presione ENTER para finalizar el programa...");
    getchar();
    return 0;
}