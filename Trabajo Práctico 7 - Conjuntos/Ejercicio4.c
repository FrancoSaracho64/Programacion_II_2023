#include "funcionesEjercicios.h"

int main () {
    //CARATULA DEL EJERCICIO
    printf("\n");
    printf("-------------------------------------------------------------------------------------\n");
    printf("\t\t\t--- Ejercicio 4 ---\n");
    printf("\n\t  --- Transitividad entre 3 conjuntos (A, B, C) ---\n");
    printf("\n");
    printf("-------------------------------------------------------------------------------------\n");

    Conjunto a = cto_crear();
    Conjunto b = cto_crear();
    Conjunto c = cto_crear();

    bool resultado;

    printf("\n\nConjunto < A >\n");
    cto_cargar(a);
    printf("\n\nConjunto < B >\n");
    cto_cargar(b);
    printf("\n\nConjunto < C >\n");
    cto_cargar(c);

    //Llamada a la funcion
    printf("\n\n**** RESULTADO ****\n");
    Transitividad3Conjuntos (a, b, c);

    printf("\n\nPresione ENTER para salir...");
    getchar();

    return 0;
}