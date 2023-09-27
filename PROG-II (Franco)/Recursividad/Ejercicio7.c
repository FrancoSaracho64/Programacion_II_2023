#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "FuncionesRecursivas.h"
#include "Validaciones.h"
#define TAMANIO_CADENA 100
const char caracter_h = 'h';
const char caracter_l = 'l';

int main(){
    // Presentacion
    system("cls");
    printf("***Ejercicio 7***\n");
    printf("Cadena de H y L...\n\n");

    // Inicializaciones
    char cadenaLetras[TAMANIO_CADENA];
    bool entrada = true;

    do{
        printf("Escribe una secuencia de señales utilizando 'H' o 'L': ");
        fflush(stdin);
        fgets(cadenaLetras, TAMANIO_CADENA, stdin);

        /* Reemplazamos el ultimo caracter '\n' de la cadena recibida por un '\0' */
        int ultimoCaracter = strlen(cadenaLetras) - 1;
        cadenaLetras[ultimoCaracter] = '\0';

        /* Convetimos todos los valores recibidos en minusculas para poder operar con ellos */
        pasajeMinusculas(cadenaLetras);

        // Verificamos que lo ingresado sea correcto 
        entrada = comparaCaracteres(cadenaLetras, caracter_h, caracter_l) && validarEnter(cadenaLetras);
    } while (!entrada);

    // Llamada a la funcion recursiva
    char *resultado = grafico_senales_inicializador(cadenaLetras, '\0');

    printf("\n\n*******************************************************************************************\n");
    printf("La cadena ingresada por el usuario es: %s\n", cadenaLetras);
    printf("La cadena transformada en picos de ondas es: ");

    // Mostramos por pantalla la cadena obtenida
    for (int i = 0; i < (strlen(resultado)); i++) {
        printf("%c", resultado[i]);
    }

    printf("\n*******************************************************************************************\n");
    free(resultado);
    fflush(stdin);
    printf("\n\n Presione ENTER para finalizar la ejecucion...");
    getchar();
    return 0;
}