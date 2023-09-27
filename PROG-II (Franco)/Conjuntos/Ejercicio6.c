#include "funcionesEjercicios.h"

int main(){
    //Presentacion
    printf("****Ejercicio 6****\nOperaciones con conjuntos -- SubConjuntos\n");
    printf("\n-------------------------------------------------------------------------------------\n");
    printf("    COMPLEJIDAD ALGORITMICA:\n    En el peor de los casos, la complejidad algoritmica del ejercicio es de tipo O(N^2).\n    Esto es asi ya que con la funcion  'EsSubconjunto'  vamos a llamar a  las  funciones\n    'cto_diferencia'  y  'cto_pertenece' las  cuales dentro tienen  una  complejidad del\n    tipo  O(N)  cada una, y al juntarlas obtenemos O(N^2).\n    Esta  complejidad  se genera  debido a que se  recorre el conjunto de punta a punta,\n    y N va variando segun la cantidad de elementos que tenga el conjunto.");
    printf("\n-------------------------------------------------------------------------------------\n\n\n");
    
    //Creamos los conjuntos
    Conjunto cto1 = cto_crear();
    Conjunto cto2 = cto_crear();

    //Cargamos los conjuntos
    printf("Carga del conjunto <A>...\n");
    cto_cargar_Naturales(cto1);
    printf("\n\n--------------------------------------------\n\n\n");
    printf("Carga del conjunto <B>...\n");
    cto_cargar_Naturales(cto2);
    printf("\n\n--------------------------------------------\n\n\n");

    bool subConjunto = EsSubconjunto(cto1, cto2);

    if (subConjunto)    printf("\nEl conjunto <A> es subConjunto del conjunto <B>.\n");
    else                printf("\nEl conjunto <A> NO es subConjunto del conjunto <B>.\n");

    printf("\nPresione ENTER para finalizar...");
    getchar();
    return 0;
}