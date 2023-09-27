#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tipo_elemento.h"
#include "colas.h"
#include "Validaciones.h"
#include "funcionesEjercicios.h"
#include "colas_utilidades.h"

int main() {
    //Inicializaciones
    int numero_int, tamano, i;
    Cola resultado;
    bool entrada = true;
    char num[TAMANO_NUM];

    //Presentacion...
    printf("***Ejercicio 4***\n");
    printf("Elementos no repetidos de una cola...\n\n");

    //Complejidad
    printf("------------------------------------------------------------------------------\nCOMPLEJIDAD ALGORITMICA: \n");
    printf("La complejidad algoritmica de este ejercicio es del tipo O(n^2),  ya que vamos\na  recorrer  una  pila hasta que esta se encuentre vacia, y, por cada elemento\nde esta,  vamos  a  recorrer   otra   pila  (la copia de la original)  para ir\ncomparando sus elementos y determinar si son o no iguales.");
    printf("\n------------------------------------------------------------------------------\n\n\n");

    //Funcion...
    Cola cola = c_crear();
    c_cargar(cola);
    if (c_es_vacia(cola)){
        printf("\n\n**************************************************\n");
        printf("---------****** La cola está VACIA ******---------");
        printf("\n**************************************************\n\n");
    } else {
    // Llamada a la funcion del ejercicio.
    resultado = numerosSinRepetir(cola);
        if (c_es_vacia(resultado)){
            printf("\n\n********************************************************************************************\n");
            printf("---------****** La cola está VACIA debido a que NO hay elementos NO iguales. ******---------");
            printf("\n********************************************************************************************\n\n");
        } else{
            // Mostramos el contenido de las colas cargadas anteriormente.
            printf("\n\n---------Cola original---------\n");
            c_mostrar(cola);
            // Mostramos el resultado por pantalla.
            printf("\n\n******************************************\n");
            printf("\n---------Cola obtenida---------\n");
            c_mostrar(resultado);
            printf("\n******************************************\n");
        }
    }
    printf("\nPresione ENTER para finalizar el programa...");
    getchar();
    return 0;
}