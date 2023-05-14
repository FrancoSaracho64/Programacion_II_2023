#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "tipo_elemento.h"
#include "colas.h"
#include "Validaciones.h"
#include "colas_utilidades.h"
#include "funcionesEjercicios.h"

int main(){
    //Presentacion...
    printf("***Ejercicio 5***\n");
    printf("Divisores parciales o totales...\n\n");

    //Complejidad algoritmica
    printf("------------------------------------------------------------------------------\nCOMPLEJIDAD ALGORITMICA: \n");
    printf("La complejidad algoritmica de este ejercicio seria O(n³), ya que en cierto punto del codigo podemos encontrar \n");
    printf("3 whiles anidados, dando asi esta complejidad. \n");
    printf("\n------------------------------------------------------------------------------\n\n\n");

    //Funcion...
    Cola cola = c_crear();
    Cola cola_final = c_crear();

    //Cargamos la cola
    c_cargar_sinRepetidosRango(cola, -9999, -2, 2, 9999);
    
    if (c_es_vacia(cola)){
        printf("\n\n****************************************************\n");
        printf("--------------** La cola está VACIA **--------------");
        printf("\n****************************************************\n\n");
    }
    else{
        //Mostrar cola cargada
        printf("\n\n****************************************************\nCola cargada...\n");
        c_mostrar(cola);
        printf("\n");

        //Llamada a la funcion
        cola_final = divisor_total_parcial(cola, c_longitud(cola));
        // Muestro por pantalla el resultado
        printf("****************************************************\n");
        if (!c_es_vacia(cola_final)) { 
            Cola Caux = c_crear();
            TipoElemento X;
            printf("Imprimiendo resultado de la cola obtenida...\n");
            // La cola se debe desencolar y guardar en una auxiliar
            while (!c_es_vacia(cola_final)){
                X = c_desencolar(cola_final);
                printf("Numero: %d --- Condicion: '%s'.\n", X->clave, X->valor);
                c_encolar(Caux, X);
            }
            c_intercambiar(cola, Caux);
        }
        else printf("\n        La cola a retornar esta VACIA\n --- No hay divisores parciales ni totales --- ");  
    }
    printf("\n\nPresione ENTER para finalizar el programa...");
    getchar();
}
