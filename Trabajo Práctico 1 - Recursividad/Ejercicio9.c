#include <stdio.h>
#include <stdbool.h>
#include "FuncionesRecursivas.h"
#include "Validaciones.h"
#define TAMANIO_CADENA 25
const int limSup = 2000000000;
const int limInf = -2000000000;

int main(){
    // Presentacion
    system("cls");
    printf("***Ejercicio 9***\n");
    printf("Multiplo de 7...\n\n");

    // Inicializaciones
    char numeroTeclado[TAMANIO_CADENA];
    bool entrada = true;
    int numero;
    
    //Pedimos el numero y le realizamos las validaciones correspondientes.
    do{
        do{
            do{
                printf("Ingrese el numero: ");
                fflush(stdin);
                fgets(numeroTeclado, TAMANIO_CADENA, stdin);
                entrada = numEnteros(numeroTeclado) && validarEnter(numeroTeclado);
            } while (!entrada);
            entrada = cantCaracteres(numeroTeclado, 13);
        } while (!entrada); 
        numero = pasaje_String_A_int(numeroTeclado);
        entrada = numeroRango(numero, limInf, limSup);
    } while (!entrada);
    // Llamada a la funcion recursiva.
    bool multiplo_7 = divisiblePor7(numero);

    if (multiplo_7) {
        printf("\n*********************************\n");
        printf("%d es multiplo de 7\n", numero);
        printf("*********************************\n");
    }
    else{          
        printf("*********************************\n");
        printf("%d NO es multiplo de 7\n", numero);
        printf("*********************************\n");
    }
    fflush(stdin);
    printf("\n\n Presione ENTER para finalizar la ejecucion...");
    getchar();
    return 0;
}
