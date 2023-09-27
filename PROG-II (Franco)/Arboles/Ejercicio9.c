#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcionesEjercicios.h"

int main(){

   ArbolBinario a = a_crear();
   ArbolAVL avl = avl_crear();
   TipoElemento x;
   NodoArbol N;

    int altura_ab  = 0;
    int altura_avl = 0;

   //CARATULA DEL EJERCICIO
   printf("\n");
   printf("-------------------------------------------------------------------------------------\n");
   printf("\t\t\t--- Ejercicio 9 ---\n");
   printf("\n");
   printf("    Complejidad algoritmica: La complejidad algoritmica del ejercicio es de tipo O(n).\n");
   printf("  Esto es asi dado que la funcion que construye el arbol AVL a partir de un binario,  \n");
   printf("  sera llamada recursivamente tantas veces como elementos tenga el arbol binario que  \n");
   printf("  va a transformado.\n");
   printf("\n");
   printf("-------------------------------------------------------------------------------------\n");
   printf("\n");

   //carga el arbol en PRE ORDEN !!!
   a_cargar_binario(a);

   printf("\nPresione ENTER para transformar el arbol binario ingresado en AVL...");
   getchar();

   //cambiamos el arbol binario a avl
   BinarioAvl (avl, a);
   printf("\n");
   printf("-----------------------------------------------------\n");
   printf("TRANSFORMANDO DE AB A AVL...\n");
   printf("-----------------------------------------------------\n");
   printf("\n");

   //COMPARAR ALTURA
   altura_ab =  altura_nodoBis(a_raiz(a));
   altura_avl = altura_nodoBis(avl_raiz(avl));

   printf("-----------------------------------------------------\n");
   printf("Altura del arbol binario -> %d\n", altura_ab);
   printf("Altura del arbol AVL -> %d\n", altura_avl);
   printf("-----------------------------------------------------\n");

   if (altura_ab > altura_avl) {
        printf("El arbol AVL generado es %d niveles mas bajo que el arbol binario ingresado en primera instancia.\n", (altura_ab - altura_avl));
   }
   else {
        printf("Los arboles binario y AVL tienen la misma altura\n");
   }

   printf("\nPresione ENTER para salir...");
   getchar();

   return 0;
}