#include "funcionesEjercicios.h"

int main(){
    //Presentacion
    printf("****Ejercicio 2****\nOperaciones con conjuntos\n\n");

    //Creamos los conjuntos
    Conjunto cto1 = cto_crear();
    Conjunto cto2 = cto_crear();

    //Cargamos los conjuntos
    printf("Carga del conjunto <A>...\n");
    cto_cargar(cto1);
    printf("\n\n--------------------------------------------\n\n\n");
    printf("Carga del conjunto <B>...\n");
    cto_cargar(cto2);
    printf("\n\n--------------------------------------------\n\n\n");

    //Llamada al menu
    menuEj2(cto1, cto2);

    printf("\nPresione ENTER para finalizar...");
    getchar();
    return 0;
}