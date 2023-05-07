#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "tipo_elemento.h"
#include "pilas.h"
#include "pilas_utilidades.h"
#include "funcionesEjercicios.h"

int main(){
    //Inicializaciones
    char num[TAMANO_NUM];
    char *numero_pasaje;
    Pila pila = p_crear();
    int numero;
    int base;
    bool entrada;
    char *numeroIngresado;

    //Presentacion
    printf("***Ejercicio 4***\n");
    printf("Pasaje de decimal a otra base...\n\n");

    //Complejidad algoritmica...
    printf("------------------------------------------------------------------------------\nCOMPLEJIDAD ALGORITMICA: \n");
    printf("En este ejercicio  nos  encontramos  con  una  complejidad  del  tipo  O(n).\nDependiendo  de  la  cantidad  de  divisiones  que  se tengan  que hacer, la\ncantidad  de  elementos de  la  lista  ira  variando.  Cuan  mas  elementos,\nmas iteraciones se tendran que hacer para recorrer la pila.");
    printf("\n------------------------------------------------------------------------------\n\n\n");
    
    //Funcion...
    /*Pedimos el numero DECIMAL*/
    do{
        printf("Ingrese el numero DECIMAL: ");
        fflush(stdin);
        fgets(num, TAMANO_NUM, stdin);
        entrada = numEnteros(num) && validarEnter(num);
    } while (!entrada);
    num[strlen(num)-1] = '\0';
    numeroIngresado = num;

    // Verificamos si es un numero negativo...
    bool validarNegativo = controlMenos(numeroIngresado);
    if (validarNegativo) numeroIngresado = truncarMenos(numeroIngresado);
    numeroIngresado = truncarCeros(numeroIngresado);
    numero = pasaje_String_A_int(numeroIngresado);
    
    /*Pedimos la BASE que se desea*/
    do{
        do{
            printf("Ingrese la BASE a la cual quiere transformar su numero: ");
            fflush(stdin);
            fgets(num, TAMANO_NUM, stdin);
            entrada = numEnteros(num) && validarEnter(num);
        } while (!entrada);
        base = pasaje_String_A_int(num);
    entrada = numeroRango(base,2,16);
    } while (!entrada);
    
    //Llamada a las funciones
    decimal_Binario_Hexa(pila, numero, base); // Cargamos la pila con los restos
    numero_pasaje = pasaje(pila); // Realizamos el pasaje de los restos a la base correspondiente.

    if (validarNegativo) {
        numero = numero*(-1);
        // Hay que pasar el *res a tipo --->   char[10 ... como? no se]
        char* guion = "-"; // cadena con guion
        char* auxiliar = malloc(sizeof(char) * strlen(numero_pasaje) + 2); // reserva memoria para la nueva cadena
        strcpy(auxiliar, guion); // agrega el guion al principio de la nueva cadena
        strcat(auxiliar,numero_pasaje);
        numero_pasaje = auxiliar;
    }
    printf("\n\n***********************************************************\n");
    printf("El pasaje del decimal '%d' a base '%d' es: %s", numero, base, numero_pasaje);
    printf("\n***********************************************************\n");
    printf("\nPresione ENTER para finalizar el programa...");
    getchar();
}