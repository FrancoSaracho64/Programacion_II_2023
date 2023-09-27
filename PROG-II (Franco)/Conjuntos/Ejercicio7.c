#include "funcionesEjercicios.h"

int main () {
    //CARATULA DEL EJERCICIO
    printf("\n");
    printf("-------------------------------------------------------------------------------------\n");
    printf("\t\t\t--- Ejercicio 7 ---\n\n");
    printf(" --- Subconjuntos parciales y totales entre 3 conjuntos (A, B, C) ---\n\n    COMPLEJIDAD ALGORITMICA:\n    La complejidad algoritmica del ejercicio es de tipo O(N). Esto es asi dado que al\n    llamar  a  la funcion   'SubconjuntoParcial3Conjuntos'   se  utiliza  la  funcion\n    'cto_diferencia',  la  cual  se encarga de recorrer  el  conjunto que recibe  por\n    parametro por completo, lo que nos da una complejidad del tipo O(N).\n");
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

    printf("\n\n");
    SubconjuntoParcial3Conjuntos (a, b, c);

    printf("\n\nPresione ENTER para salir...");
    getchar();
    return 0;
}