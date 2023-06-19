#include "funcionesEjercicios.h"

int main(){
    //Presentacion
    printf("****Ejercicio 3****\nOperaciones con conjuntos\n\n");

    //Inicializaciones
    bool entrada = true;
    char num[TAMANO_NUM];
    int cantidadConjuntos, opcion, numero, i = 1;
    TipoElemento elemento;
    
    //Creamos estructura para almacenar conjuntos
    Lista listaConjuntos = l_crear();

    //Pedimos cantidad de conjuntos
    do{
        do{
            printf("Indique la cantidad de conjuntos a generar: ");
            fflush(stdin);
            fgets(num, TAMANO_NUM, stdin);
            entrada = numEnteros(num) && validarEnter(num);
        } while (!entrada);
        cantidadConjuntos = pasaje_String_A_int(num);  
        entrada = numeroRango(cantidadConjuntos, 2, 100);
    } while (!entrada);
    printf("\n\n******* Carga de conjuntos *******\n\n");
    
    //Cargamos los conjuntos
    while (i < cantidadConjuntos + 1){
        printf("Cargando el conjunto [%d]: ", i);
        Conjunto conj = cto_crear();
        cto_cargar(conj);
        elemento = te_crear_con_valor(i, conj);
        l_agregar(listaConjuntos, elemento);
        i++;
        printf("\n-----------------------------------\n\n");
    }

    //Llamada al menu
    menuEj3(listaConjuntos);

    printf("\nPresione ENTER para finalizar...");
    getchar();
    return 0;
}