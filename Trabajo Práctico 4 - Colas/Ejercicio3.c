#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tipo_elemento.h"
#include "colas.h"
#include "Validaciones.h"
#include "funcionesEjercicios.h"

int main() {
    //Inicializaciones
    int numero_int, tamano, i;
    bool resultado;
    bool entrada = true;
    char num[TAMANO_NUM];

    //Presentacion...
    printf("***Ejercicio 3***\n");
    printf("Colas iguales o distintas...\n\n");

    //Complejidad
    printf("------------------------------------------------------------------------------\nCOMPLEJIDAD ALGORITMICA: \n");
    printf("Aqui la complejidad algoritmica es del tipo 'O(n)'  ya que en  el  peor de los\ncasos, nos encontramos con que vamos a recorrer las pilas hasta  que no tengan\nmas elementos disponibles.  Si bien el  proceso  de recorrer  la  cola se hace\nvarias veces, siempre se trata a una sola cola a la vez.");
    printf("\n------------------------------------------------------------------------------\n\n\n");

    //Funcion...
    Cola cola_1 = c_crear();
    Cola cola_2 = c_crear();

    // VALIDAR NUMERO TAMAÑO cola                              
    do{
        do {
            printf("Ingrese la cantidad de elementos de las colas: ");
            fflush(stdin);
            fgets(num, TAMANO_NUM, stdin);
            entrada = numEnteros(num) && validarEnter(num);
        } while (!entrada);
        tamano = pasaje_String_A_int(num);
        entrada = numeroRango(tamano,0,100);
    } while(!entrada);

    if (tamano == 0){
        printf("\n\n******************************************************\n");
        printf("---------****** Las colas están VACIAS ******---------");
        printf("\n******************************************************\n\n");
    } else {

        printf("\n\n*********************************************\n\n");
    
        // VALIDAR NUMERO CLAVE Y AGREGAR A LA cola 1
        i = 0;
        printf("Carga de la COLA 1...\n");
        do {
            do {
                printf("Ingrese el elemento '%d' para la cola 1: ", i + 1);
                fflush(stdin);
                fgets(num, TAMANO_NUM, stdin);
                entrada = numEnteros(num) && validarEnter(num);
            } while (!entrada);
            numero_int = pasaje_String_A_int(num);
            TipoElemento numero = te_crear(numero_int);
            c_encolar(cola_1, numero);
            i ++;
        } while (i < tamano);

        printf("\n\n*********************************************\n\n");

        // VALIDAR NUMERO CLAVE Y AGREGAR A LA cola 2
        i = 0;
        printf("Carga de la COLA 2...\n");
        do{
            do{
                printf("Ingrese el elemento '%d' para la cola 2: ", i + 1);
                fflush(stdin);
                fgets(num, TAMANO_NUM, stdin);
                entrada = numEnteros(num) && validarEnter(num);
            } while (!entrada);
            numero_int = pasaje_String_A_int(num);
            TipoElemento numero = te_crear(numero_int);
            c_encolar(cola_2, numero);
            i++;
        } while (i < tamano);

        printf("\n\n*********************************************\n");

        // Llamada a la funcion del ejercicio.
        resultado = colas_iguales(cola_1, cola_2, tamano);
        // Mostramos el contenido de las colas cargadas anteriormente.
        printf("\n\n---------Colas originales---------\n");
        printf("          --- Cola 1 ---\n");
        c_mostrar(cola_1);
        printf("          --- Cola 2 ---\n");
        c_mostrar(cola_2);
        // Mostramos el resultado por pantalla.
        printf("\n\n******************************************\n");
        if (resultado) {
            printf("  ------ Las colas son IGUALES. ------");
        } else {
            printf("  ------ Las colas son DISTINTAS. ------");
        }
        printf("\n******************************************\n");
    }
    printf("\nPresione ENTER para finalizar el programa...");
    getchar();
    return 0;
}