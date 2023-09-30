#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "funcionesEjercicios.h"

int main(){
    Lista my_list = l_crear();
    
    for (int i = 0; i < 5; i++)
    {
        int valorUsuario;
        printf("Introduzca un numero entero: ");
        scanf("%d", &valorUsuario);    
        TipoElemento elem = te_crear(valorUsuario);
        l_agregar(my_list, elem);
    }
    bool result = l_esta_ordenadaAscendentemente(my_list);
    if (result){
        printf("\n\nOrdenadaASC");
    }
    else{
        printf("\n\nDesordenadaASC");
    }


    bool result2 = l_esta_ordenadaDecrecientemente(my_list);
    if (result2){
        printf("\nOrdenadaDEC");
    }
    else{
        printf("\nDesordenadaDEC");
    }
    fflush(stdin);
    getchar();
    return 0;
}