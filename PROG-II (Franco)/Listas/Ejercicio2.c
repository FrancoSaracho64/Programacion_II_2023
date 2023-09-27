/* EJERCICIO 2 */
#include <stdio.h>
#include <stdlib.h>

#include "funcionesEjercicios.h"

// Programa principal
int main() {
    //Presentacion
    system("cls");
    printf("***Ejercicio 2***\n");
    printf("Calculos con elementos de una lista...\n\n");

    // Inicializaciones
    int i, numero = 0, tamano_lista, opcion, numeroMayor;
    float prom;
    bool entrada = true;
    char num[TAMANO_NUM];
    TipoElemento tipEle;
    Lista List = l_crear(); // Creamos la lista a utilizar
    do{
        do{
            menu();
            fflush(stdin);
            fgets(num, TAMANO_NUM, stdin);
            entrada = numEnteros(num) && validarEnter(num);
        } while (!entrada);
        opcion = pasaje_String_A_int(num);
        switch (opcion) {
            case 1:
                /* Carga de numeros */
                cargarLista(List);
                // Muestro la lista
                l_mostrarLista(List);
                printf("\n");
                printf("********************************************\n");
                posicionDatoMenor(List);
                numeroMayor = l_elementoMayor(List);
                printf("\n********************************************\n\n");
                printf("Presione ENTER para finalizar el programa...");
                getchar();
                break;
            case 2:
                //b. Que calcule el dato máximo y cuente la cantidad de veces que se repite. 
                /* Carga de numeros */
                cargarLista(List);
                // Muestro la lista
                l_mostrarLista(List);
                printf("\n");
                printf("********************************************\n");
                datoMaximoVeces(List);
                printf("\n********************************************\n\n");
                printf("Presione ENTER para finalizar el programa...");
                getchar();
                break;
            case 3:
                //c. Que obtenga el promedio de los datos de una lista. El proceso debe ser recursivo.
                /* Carga de numeros */
                cargarLista(List);
                // Muestro la lista
                l_mostrarLista(List);
                printf("\n");
                //Llamo a la funcion recursiva
                prom = promedio(List, 1, 0);
                printf("********************************************\n");
                printf("El promedio de la lista cargada es: %.2f", prom);
                printf("\n********************************************\n\n");
                printf("Presione ENTER para finalizar el programa...");
                getchar();
                break;
            case 4:
                //d. Que retorne otra lista con los números múltiplos de otro número que recibe como parámetro.
                cargarLista(List);
                // Muestro la lista
                l_mostrarLista(List);
                // Pido el numero para conocer sus multiplos
                do{
                    printf("Ingrese el numero para conocer sus multiplos: ");
                    fflush(stdin);
                    fgets(num, TAMANO_NUM, stdin);
                    entrada = numEnteros(num) && validarEnter(num);
                } while (!entrada);
                    int numMultiplo = pasaje_String_A_int(num);
                Lista listMultiplosDe = MultiplosDe(List, numMultiplo);
                if (l_es_vacia(listMultiplosDe)) printf("En la lista original no hay multiplos de %d.", numMultiplo);
                else{
                    // Muestro la lista
                    printf("\n\n*****************************************************************\n");
                    printf("                 Multiplos de %d .......... \n", numMultiplo);
                    l_mostrarLista(listMultiplosDe);
                    printf("\n*****************************************************************\n\n");
                }
                printf("\n");
                printf("Presione ENTER para finalizar el programa...");
                getchar();
                break;
            case 0:
                printf("Finalizando ejecucion del programa.\n");
                printf("Presione ENTER para finalizar el programa...");
                getchar();
                break;
            default:
                printf("\n\n*****************************************************************\n");
                printf("       Ha introducido un valor erroneo. Vuelva a intentar.\n");
                printf("*****************************************************************\n\n");
                entrada = false;
                break;
        }
    } while (!entrada);
    return 0;
}