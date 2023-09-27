#include "funcionesEjercicios.h"
//------ FUNCION HASH ----------------
int hash_function(int clave){
    return (clave % 149);
}

int main(){
    //Presentacion
    printf("\n****************************************************************\n    NOTA: COMO MAXIMO SE PUEDEN CARGAR 150 PERSONAS EN TOTAL\n****************************************************************\n\n");
    printf("***Ejercicio 6***\nFechas de vacunaciones\n\n");

    TablaHash tabla = th_crear(150, hash_function);
    menu(tabla);
    printf("\n\nPresione ENTER para finalizar...");
    getchar();
    return 0;
}