#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tipo_elemento.h"
#include "colas.h"
#include "pilas.h"
#include "listas.h"
#include "pilas_utilidades.h"
#include "Validaciones.h"
#include "funcionesEjercicios.h"
#include "colas_utilidades.h"

int main(){
    //Presentacion...
    printf("***Ejercicio 6***\n");
    printf("Elementos iguales entre una Pila y una Cola...\n\n");

    //Complejidad
    printf("------------------------------------------------------------------------------\nCOMPLEJIDAD ALGORITMICA: \n");
    printf("La complejidad algoritmica de este ejercicio es del tipo O(n^2)  ya que, en el peor de los casos se recorrera la cola por cada elemento que tiene la pila .");
    printf("\n------------------------------------------------------------------------------\n\n\n");

    //Funcion...
    //Crear estructuras
    Pila p = p_crear();
    Cola c = c_crear();
    
    // Cargar pila
    printf("\nCARGA DE LA PILA...");
    p_cargar_sinRepetidos(p);
    // Cargar cola
    printf("\n\nCARGA DE LA COLA...");
    c_cargar_sinRepetidos(c); 
    printf("\n----------------------------------------------------------------\n\n");

    //Mostramos la pila y la cola cargadas previamente
    printf("Pila cargada...\n");
    p_mostrar(p);
    printf("\n");
    printf("Cola cargada...\n");
    c_mostrar(c);
    printf("\n");   
    // Llamar a la funcion con los parametros correctos
    Lista lista_obtenida = busca_Pila_Cola(p,c);
    if (l_es_vacia(lista_obtenida)) printf("\n                La lista obtenida esta VACIA.\n --- NO hay elementos repetidos entre la pila y la cola ---\n");
    else {
        //Mostrar la lista cargada...
        Iterador iter = iterador(lista_obtenida);
        TipoElemento elem;
        int i = 0;
        printf("\n\n*****************************************************\n");
        printf("Elementos repetidos...\n");
        while (hay_siguiente(iter)) {
            elem = siguiente(iter);
            printf("Elemento: %d ** %s\n", elem->clave, elem->valor);
            i++;
        }
        printf("\nCantidad de elementos repetidos: %d\n", i);
        printf("*****************************************************");
    }
    printf("\n\nPresione ENTER para finalizar el ejercicio...");
    getchar();
    return 0;
}
