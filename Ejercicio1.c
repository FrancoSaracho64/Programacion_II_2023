#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "FuncionesRecursivas.h"
#include "Validaciones.h"
#define TAMANIO_CADENA 100

int main(){
    // Presentacion
    system("cls");
    printf("***Ejercicio 1***\n");
    printf("Palabras/frases de tipo palindromo...\n\n");

    // Inicializaciones
    bool estadoPalabra;
    bool entrada = true;
    char palabraIngresada[TAMANIO_CADENA];
    char cadenaFinal[TAMANIO_CADENA];
    
    // Pedimos que se ingrese una cadena de texto y realizamos las validaciones correspondientes.
    do {
        printf("Introduzca su palabra/texto: ");
        fflush(stdin);
        fgets(palabraIngresada, TAMANIO_CADENA ,stdin);
        entrada = validarEnter(palabraIngresada) && soloUnCaracter(palabraIngresada) ;
    } while (!entrada);

    // Reemplazamos el ultimo caracter '\n' de la cadena recibida por un '\0'
    int ultimoCaracter = strlen(palabraIngresada) - 1;
    palabraIngresada[ultimoCaracter] = '\0';
    
    /* Llamamos a la funcion recursiva con la cadena obtenida */
    estadoPalabra = palindromo(palabraIngresada, 0, ultimoCaracter-1);  // -1 por indice de vector.

    if (estadoPalabra == true) {
        printf("\n\n*************************************************************\n");
        printf("   La palabra/frase ingresada: '%s' corresponde a un palindromo.\n", palabraIngresada);
        printf("                               *************************************************************\n");
    } else {
        printf("\n\n*************************************************************\n");
        printf("   La palabra/frase ingresada: '%s' NO corresponde a un palindromo.\n", palabraIngresada);
        printf("                               *************************************************************\n");
        }
    fflush(stdin);
    printf("\n\n Presione ENTER para finalizar la ejecucion...");
    getchar();
    return 0;
}