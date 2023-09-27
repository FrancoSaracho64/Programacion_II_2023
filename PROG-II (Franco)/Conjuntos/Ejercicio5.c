#include "funcionesEjercicios.h"

int main () {
    //CARATULA DEL EJERCICIO
    printf("\n");
    printf("-------------------------------------------------------------------------------------\n");
    printf("\t\t\t--- Ejercicio 5 ---\n");
    printf("\n\t--- Diferencia simetrica entre 2 conjuntos (A, B) ---\n");
    printf("\n");
    printf("-------------------------------------------------------------------------------------\n");

    Conjunto a = cto_crear();
    Conjunto b = cto_crear();

    Conjunto resultado = cto_crear();

    printf("\n\nConjunto < A >\n");
    cto_cargar(a);
    printf("\n\nConjunto < B >\n");
    cto_cargar(b);

    resultado = diferenciaSimetrica (a, b);

    printf("\n\n");
    printf("El conjunto resultante de la diferencia simetrica entre A y B es...\n");
    cto_mostrar(resultado);

    printf("\n\nPresione ENTER para salir...");
    getchar();
    return 0;
}