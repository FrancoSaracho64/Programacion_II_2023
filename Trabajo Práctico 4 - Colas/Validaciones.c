#include "Validaciones.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/* Validacion para SOLO numeros enteros */
bool numEnteros(char numIngresado[]){
    int verificacionNumero = 0;
    bool bandera = true;
    int posicion = 0;
    int cantNum = 0;

    while (cantNum < strlen(numIngresado)-1 && bandera){  // Le restamos 1 al largo del numero para no contar el ultimo caracter "\0"
        if ((numIngresado[posicion] == '-') && (posicion == 0)) {
            if (strlen(numIngresado)-1 == 1){
                printf("\n\n*******************************************************************************");
                printf("\n                                   ***ERROR***\n            El dato ingresado por teclado no corresponde a un numero.\n");
                printf("*******************************************************************************\n\n");
                bandera = false;
            }
            posicion ++;
            cantNum ++;
        }
        else if (numIngresado[posicion] == ' ') {
            printf("\n\n************************************************************");
            printf("\n                       ***ERROR***\n            No se admiten los espacios en blanco.\n");
            printf("************************************************************\n\n");
            bandera = false;
        }
        else if (numIngresado[posicion] == '\0' && (cantNum == strlen(numIngresado)))  {
            posicion++;
            cantNum ++;
        }
        else{
            verificacionNumero = isdigit(numIngresado[posicion]); // isdigit  >>>>>  Si es un numero, devuelve 1. Si no es un numero, devuelve 0.
            if (verificacionNumero != 0){
                posicion++;
                cantNum ++;
            } else {
                printf("\n\n*******************************************************************************");
                printf("\n                                   ***ERROR***\n            El dato ingresado por teclado no corresponde a un numero.\n");
                printf("*******************************************************************************\n\n");
                bandera = false;
            }
        }
    }
    return bandera;   // Si es TRUE, es un numero. Sino, no es un numero.
}

/* Validamos que un entero NO sea igual a cero */
bool esCero(int numero){
    bool bandera = true;
    if (numero == 0) {
        printf("\n\n**********************************************");
        printf("\n                 ***ERROR***\n         No se puede introducir un '0'.\n");
        printf("**********************************************\n\n");
        bandera = false;
    }
    return bandera;
}

/* Validad cantidad de elementos/caracteres de un String */
bool cantCaracteres(char cadena[], int limite){
    bool estado = true;
    if (strlen(cadena) > limite){
        printf("\n\n*******************************************************************************");
        printf("\n                              ***ERROR***\n               La cadena de texto ingresada es demasiado grande.\n");
        printf("*******************************************************************************\n\n");
        estado = false;
        }
    // }
    return estado;
}

/* Pasaje de un String A integer */
int pasaje_String_A_int(char numIngresado[]){
    int numero;
    numero = atoi(numIngresado);   // atoi     >>>>>  Le pasamos por parametro una cadena "String" y la transforma a un int.
    return numero;
}

/* Analizar si la cadena recibida solo tiene un caracter */
bool soloUnCaracter(char cadena[]){
    bool bandera = true;
    if ( strlen(cadena)-1 == 1) {
        printf("\n\n*****************************************************************************************");
        printf("\n                                     ***ERROR***\n        Para ejecutar el programa debe ingresar una palabra que posea mas de un caracter.\n\n");
        printf("*****************************************************************************************\n\n");
        bandera = false;
    }
    return bandera;
}

/* Analizar si el primer caracter de una cadena de texto es '\n' */
bool validarEnter(char cadena[]){
    bool bandera = true;
    if ((cadena[0] == '\n' || cadena[0]== '\0')) {
        printf("\n\n*******************************************************");
        printf("\n                   ***ERROR***\n            El dato ingresado no es valido.\n");
        printf("*******************************************************\n\n");
        bandera = false;
    }
    return bandera;
}

/* Analizar si el primer caracter de una cadena de tipo puntero es '\n' */
bool validarEnterPuntero(char *cadena){
    bool bandera = true;
    if (*cadena == '\n' || *cadena== '\0') {
        printf("\n\n*******************************************************");
        printf("\n                   ***ERROR***\n            El dato ingresado no es valido.\n");
        printf("*******************************************************\n\n");
        bandera = false;
    }
    return bandera;
}

/* Validar un numero dentro de un rango recibido por parametro */
bool numeroRango(int numero, int limInf, int limSup){
    bool bandera = true;
    if (numero < limInf || numero > limSup){
        printf("\n\n*******************************************************");
        printf("\n                   ***ERROR***\n       El dato ingresado esta fuera de rango.\n       El intervalo permitido es [%d,%d].\n", limInf, limSup);
        printf("*******************************************************\n\n");
        bandera = false;
    }
    return bandera;
}
bool numeroRangoMedio(int numero, int infMax, int infMin, int supMin, int supMax){
    bool bandera = true;
    if ((numero > infMin && numero < supMin) || numero > supMax  ||  numero < infMax    ){
        printf("\n\n*******************************************************");
        printf("\n                     ***ERROR***\n        El dato ingresado esta fuera de rango.\n   El intervalo permitido es [%d,%d]...[%d,%d].\n", infMax, infMin, supMin, supMax);
        printf("*******************************************************\n\n");
        bandera = false;
    }
    return bandera;
}

/* Pasaje de caracteres de una cadena a minusculas */
void pasajeMinusculas(char cadena[]){
    int i;
        for (i = 0; i < strlen(cadena); i++) {
            cadena[i] = tolower(cadena[i]);
        }
}

/* Comparamos todos los caracteres de una cadena con dos que recibimos por parametro */
bool comparaCaracteres(char cadena[], char caracter_1, char caracter_2){
    bool bandera = true;
    int i = 0;
    while (i < strlen(cadena) && bandera){
        char caracter = cadena[i];
        if ((caracter != caracter_1) && (caracter != caracter_2)){
            printf("\n\n*******************************************************");
            printf("\n                   ***ERROR***\n          La cadena ingresada no es valida.\n           Solo se admiten '%c/%c' o '%c/%c'.\n",toupper(caracter_1),caracter_1,toupper(caracter_2),caracter_2);
            printf("*******************************************************\n\n");
            bandera = false;
        }
        i++;
    }
    return bandera;
}

// Funcion que trunca los 0 a la izquierda que tenga la cadena ingresada y retorna el numero
char *truncarCeros (char *dato) {
    //control de ceros a la izquierda
    while (*dato == '0') { // Comparamos el primer elemento del arreglo con el carácter '0'
        if (strlen(dato) > 1) { //verificamos que la cadena no esté vacía y que tenga un elemento siguiente donde truncar
            char * auxiliar = malloc(sizeof(char) * (strlen(dato)));
            strncpy(auxiliar, dato + 1, strlen(dato));
            dato = auxiliar;
        }
        else if (strlen(dato) == 1) { //si la cadena queda como un unico 0, lo retornamos para no destruir la cadena 
            return dato;
        }
    }  
    return dato;
}

//funcion que inserta el menos que se elimino previamente para los numeros negativos ingresados
char * insertarMenos (char * dato) {
    char* guion = "-"; // cadena con guion
    char* auxiliar = malloc(sizeof(char) * strlen(dato) + 2); // reserva memoria para la nueva cadena
    strcpy(auxiliar, guion); // agrega el guion al principio de la nueva cadena
    strcat(auxiliar,dato);
    return auxiliar;  
}

//funcion que trunca el signo negativo al numero ingresado
char *truncarMenos (char *dato) {
    char * auxiliar = malloc(sizeof(char) * (strlen(dato)));
    strncpy(auxiliar, dato + 1, strlen(dato));
    dato = auxiliar;
    return dato;
}

//funcion que retorna TRUE en caso que la cadena ingresada corresponda a un numero negativo y FALSE en que no lo sea
bool controlMenos (char *numero) {
    //control de menos
    if (*numero == '-') {
        return true;
    }
    else{
        return false;
    }
}