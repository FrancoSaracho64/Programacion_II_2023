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
    ArbolBinario arbol_binario = a_crear();
    a_cargar_binario(arbol_binario);
    int numero;
    bool entrada = true;
    char num[TAMANO_NUM];
    printf("\n\n");

    if (a_es_vacio(arbol_binario)){
        printf("Ha cargado un arbol VACIO ( Raiz ---> NULL ), por lo que no se podran ejecutar las funciones...");
    } else {
        do{
            fflush(stdin);
            printf("Ingrese la clave que quiere buscar dentro del arbol: ");
            fgets(num, TAMANO_NUM, stdin);
            entrada = numEnteros(num) && validarEnter(num);
        } while (!entrada);
        numero = pasaje_String_A_int(num);
        
        //Llamo a la funcion que se encarga de ejecutar todas las funciones del ejercicio.
        ejercicio3(a_raiz(arbol_binario), numero);
    }
    printf("\n\nPresione ENTER para finalizar la ejecucion...");
    getchar();
}
