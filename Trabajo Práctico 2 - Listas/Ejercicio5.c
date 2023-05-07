//DECLARAMOS LAS LIBRERIAS UTILIZADAS EN EL PROGRAMA
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "listas.h"
#include "tipo_elemento.h"
#include "Validaciones.h"
#include "funcionesEjercicios.h"
//DECLARACIONES PARA LA VALIDACIÓN DE DATOS
#define TAMANIO_CADENA 25
const int limSup = 100;
const int limInf = -100;
const int limInfCero = 0;

//FUNCION PRINCIPAL
int main () {
    //Presentacion
    system("cls");
    printf("***Ejercicio 5***\n");
    printf("Calculo de un polinomio...\n\n");

    //Declaramos las variables que vamos a utilizar
    int cantidadCoeficientes;
    int cantidadPrueba = 0;
    double c, variable1, variable2;
    bool entrada = true;
    Lista Coeficientes;
    Coeficientes = l_crear();
    Lista Resultado;
    TipoElemento carga;
    char CantidadCoeficientesTeclado[TAMANIO_CADENA];
    char cTeclado[TAMANIO_CADENA];
    char variable1Teclado[TAMANIO_CADENA];
    char variable2Teclado[TAMANIO_CADENA];

    //Pedimos el grado del polinomio a ingresar
    do{    
        do{
            printf("Ingrese el grado del polinomio que desea ingresar:  ");
            fflush(stdin);
            fgets(CantidadCoeficientesTeclado, TAMANIO_CADENA, stdin);
            entrada = numEnteros(CantidadCoeficientesTeclado) && validarEnter(CantidadCoeficientesTeclado);
        } while (!entrada);
        cantidadCoeficientes = pasaje_String_A_int(CantidadCoeficientesTeclado);
        entrada = numeroRango(cantidadCoeficientes, limInfCero, limSup);
    } while (!entrada);

    //Pedimos los coeficientes del polinomio y los almacenamos en un arreglo
    double inputUsuario[cantidadCoeficientes];
    printf("\nCarga del polinomio...\n");
    for (int i = 0; i < cantidadCoeficientes+1; i++){
        do{    
            do{
                printf("Ingrese el coeficiente de X^%d =  ", cantidadCoeficientes-i);
                fflush(stdin);
                fgets(cTeclado, TAMANIO_CADENA, stdin);
                entrada = numEnteros(cTeclado) && validarEnter(cTeclado);
            } while (!entrada);
            c = pasaje_String_A_int(cTeclado);
            entrada = numeroRango(c, limInf, limSup);
        } while (!entrada);

        inputUsuario[i] = c;
    }
    printf("Polinomio cargado.\n\n");

    //Cargamos a la lista Coeficientes los coeficientes ingresados que actualmente están en el arreglo
    //Damos vuelta la lista, ya que esta se cargó de mayor a menor grado y debe estar de menor a mayor
    for (int i = cantidadCoeficientes; i >= 0; i--){
        void * cargaVoid = &inputUsuario[i];
        carga = te_crear_con_valor(i, cargaVoid);
        l_agregar(Coeficientes, carga);   
    }

    //Pedimos el rango numerico para el cual vamos a calcular el valor de x
    printf("Rango a calcular...\n");
    do{    
        do{
            printf("Ingrese la primera variable del rango de resultados a calcular:  ");
            fflush(stdin);
            fgets(variable1Teclado, TAMANIO_CADENA, stdin);
            entrada = numEnteros(variable1Teclado) && validarEnter(variable1Teclado);
        } while (!entrada);
        variable1 = pasaje_String_A_int(variable1Teclado);
        entrada = numeroRango(variable1, limInf, limSup);
    } while (!entrada);
    do{    
        do{
            printf("Ingrese la segunda variable del rango de resultados a calcular:  ");
            fflush(stdin);
            fgets(variable2Teclado, TAMANIO_CADENA, stdin);
            entrada = numEnteros(variable2Teclado) && validarEnter(variable2Teclado);
        } while (!entrada);
        variable2 = pasaje_String_A_int(variable2Teclado);
        entrada = numeroRango(variable2, limInf, limSup);
    } while (!entrada);

    //Nos aseguramos que variable1 contenga el numero mas chico y variable2 el numero mas grande del rango
    if (variable2 < variable1) {
        double c = variable2;
        variable2 = variable1;
        variable1 = c;
    }

    // Almacenamos en la lista 'Resultado' la lista de los valores de x en el rango    
    Resultado = CalculoRango(variable1, variable2, Coeficientes);

    printf("\n\n********************************************************************************************************************\n");
    printf("\nSe muestran los resultados de los polinomios en el rango (%0.lf, %0.lf):\n", variable1, variable2);

    // Printear los valores de la lista Auxiliar
    int cantidadAuxiliarLista = l_longitud(Resultado);
    int contadorDeComas = 1;
    TipoElemento MostrarAuxiliar;
    Iterador iteR = iterador(Resultado);

    printf("\n");
    while (hay_siguiente(iteR)) {
        MostrarAuxiliar = siguiente(iteR);
        double *doublePtrMostraAuxiliar = (double*) MostrarAuxiliar->valor;
        double valorMostrarAuxiliar = *doublePtrMostraAuxiliar;
        printf("X(%.2lf) =  %.4f\n", variable1, valorMostrarAuxiliar);
        variable1 = variable1 + 0.5;
        contadorDeComas++;
    }
    printf("\n\n");
    printf("********************************************************************************************************************\n");
    fflush(stdin);
    printf("\n\n Presione ENTER para finalizar la ejecucion...");
    getchar();

    //Final de la función principal
    return 0;
}