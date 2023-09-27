#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tipo_elemento.h"
#include "pilas.h"
#include "Validaciones.h"
#include "pilas_utilidades.h"
#include "funcionesEjercicios.h"

int main() {
    //Inicializaciones
    int numero_int, tamano, contador, i;
    bool resultado;
    bool entrada = true;
    char num[TAMANO_NUM];

    //Presentacion...
    printf("***Ejercicio 3***\n");
    printf("Pilas iguales o distintas...\n\n");

    //Complejidad
    printf("------------------------------------------------------------------------------\nCOMPLEJIDAD ALGORITMICA: \n");
    printf("Aqui la complejidad algoritmica es de  O(n^2),  ya que si nos quedamos con los\npeores casos, nos encontramos con  dos  whiles en  distintas condiciones, y al\nmultiplicarlos nos da n^2.");
    printf("\n------------------------------------------------------------------------------\n\n\n");

    //Funcion...
    Pila pila_1 = p_crear();
    Pila pila_2 = p_crear();

    // VALIDAR NUMERO TAMAÑO PILA                              
    do{
        do {
            printf("Ingrese el tamanio de las pilas: ");
            fflush(stdin);
            fgets(num, TAMANO_NUM, stdin);
            entrada = numEnteros(num) && validarEnter(num);
        } while (!entrada);
        tamano = pasaje_String_A_int(num);
        entrada = numeroRango(tamano,1,100);
    } while(!entrada);

    printf("\n\n*********************************************\n\n");
    
    if (tamano != 0){
        // VALIDAR NUMERO CLAVE Y AGREGAR A LA PILA 1
        contador = tamano;
        i = 0;
        printf("PILA 1...\n");
        do {
            do {
                printf("Ingrese el elemento '%d' para la pila 1: ", contador);
                fflush(stdin);
                fgets(num, TAMANO_NUM, stdin);
                entrada = numEnteros(num) && validarEnter(num);
            } while (!entrada);
            numero_int = pasaje_String_A_int(num);
            TipoElemento numero = te_crear(numero_int);
            p_apilar(pila_1, numero);
            contador--;
            i ++;
        } while (i < tamano);

        printf("\n\n*********************************************\n\n");

        // VALIDAR NUMERO CLAVE Y AGREGAR A LA PILA 2
        contador = tamano;
        i = 0;
        printf("PILA 2...\n");
        do{
            do{
                printf("Ingrese el elemento '%d' para la pila 2: ", contador);
                fflush(stdin);
                fgets(num, TAMANO_NUM, stdin);
                entrada = numEnteros(num) && validarEnter(num);
            } while (!entrada);
            numero_int = pasaje_String_A_int(num);
            TipoElemento numero = te_crear(numero_int);
            p_apilar(pila_2, numero);
            contador--;
            i++;
        } while (i < tamano);

        // Llamada a la funcion del ejercicio.
        resultado = pilas_iguales(pila_1, pila_2, tamano);
    }
    
    if (p_es_vacia(pila_1) && p_es_vacia(pila_2)){
        printf("\n\n*****************************************************\n");
        printf("---------****** Las pilas están VACIAS ******---------");
        printf("\n*****************************************************\n\n");
    } else {
        // Mostramos el contenido de las pilas cargadas anteriormente.
        printf("\n\n---------Pilas originales---------\n");
        printf("                      ___ PILA 1 ___\n");
        p_mostrar(pila_1);
        printf("                      ___ PILA 2 ___\n");
        p_mostrar(pila_2);
        // Mostramos el resultado por pantalla.
        printf("\n\n******************************************\n");
        if (resultado) {
            printf("  ------ Las pilas son IGUALES. ------");
        } else {
            printf("  ------ Las pilas son DISTINTAS. ------");
        }
        printf("\n******************************************\n");
    }
    printf("\nPresione ENTER para finalizar el programa...");
    getchar();
    return 0;
}