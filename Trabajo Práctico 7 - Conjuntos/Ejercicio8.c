#include "funcionesEjercicios.h"

int main(){
    //Presentacion
    printf("****Ejercicio 8****\nOperaciones con conjuntos -- Conjuntos Iguales\n\n");
    printf("----------------------------------------------------------------------------------------\n");
    printf("    COMPLEJIDAD ALGORITMICA:\n    En el peor de los casos, la complejidad algoritmica del ejercicio es de tipo O(N^2).\n    Esto es asi ya que con la  funcion  'conjuntosIguales'  vamos  a  comparar  elemento\n    por elemento de cada conjunto para asi determinar si son  o  no iguales utilizando a\n    su vez la funcion  'cto_pertenece'  la cual tiene una complejidad del tipo  O(N). Al\n    sumar ambas complejidades obtenemos la complejidad del tipo O(N^2).\n    El N siempre ira variando segun la cantidad de elementos que tengan los conjuntos.\n\n    En  el  caso  de  que  la  cantidad de elementos de los  subconjuntos  sea distinta,\n    los conjuntos ya  NO son iguales, por lo que directamente NO se llama a  la  funcion\n    'conjuntosIguales'. Este caso nos arrojaria una complejidad del tipo O(1).");
    printf("\n----------------------------------------------------------------------------------------\n\n\n");
    
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

    //Obtengo la cantidad de elementos de cada conjunto.
    int cant1 = cto_cantidad_elementos(cto1);
    int cant2 = cto_cantidad_elementos(cto2);

    bool iguales = true;

    if (cant1 != cant2) iguales = false;

    if (iguales){
        iguales = conjuntosIguales(cto1, cto2);
    } 
     
    if (iguales){
        printf("Los conjuntos son IGUALES.\n");
    } else{
        printf("Los conjuntos son DIFERENTES.\n");
    }

    printf("\nPresione ENTER para finalizar...");
    getchar();
    return 0;
}