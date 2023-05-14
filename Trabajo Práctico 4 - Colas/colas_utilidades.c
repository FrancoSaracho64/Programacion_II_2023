#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "colas.h"
#include "colas_utilidades.h"
#include "Validaciones.h"

int c_longitud(Cola c){
    int longitud = 0;
    TipoElemento elem;
    Cola c_aux = c_crear();

    while (!c_es_vacia(c)){
        elem = c_desencolar(c);
        c_encolar(c_aux, elem);
        longitud++;
    }
    c_intercambiar(c, c_aux);
    return longitud;
}

void c_intercambiar(Cola c, Cola c_aux){
    TipoElemento elem;
    while (!c_es_vacia(c_aux)){
        elem = c_desencolar(c_aux);
        c_encolar(c, elem);
    }
}

void c_cargar(Cola cola){
    //Inicializaciones
    bool entrada = true;
    char num[TAMANO_NUM];
    int cantidadElementos, opcion, numero, i = 0;
    TipoElemento elemento;
    do{
        do{
            printf("\n**************************************************\n¿Como quiere cargar la cola?\n1. Manualmente\n2. Aleatoriamente\n\n");
            printf("INGRESE UNA OPCION: ");
            fflush(stdin);
            fgets(num, TAMANO_NUM, stdin);
            entrada = numEnteros(num) && validarEnter(num);
        } while (!entrada);
        opcion = pasaje_String_A_int(num);
        switch (opcion) {
            case 1:
                do{
                    do{
                        printf("Ingrese la cantidad de elementos a cargar: ");
                        fflush(stdin);
                        fgets(num, TAMANO_NUM, stdin);
                        entrada = numEnteros(num) && validarEnter(num);
                    } while (!entrada);
                    cantidadElementos = pasaje_String_A_int(num);  
                    entrada = numeroRango(cantidadElementos,0,100);
                } while (!entrada);
                while (i < cantidadElementos){
                    do{
                        printf("Ingrese el elemento de posicion [%d]: ", i + 1);
                        fflush(stdin);
                        fgets(num, TAMANO_NUM, stdin);
                        entrada = numEnteros(num) && validarEnter(num);
                    } while (!entrada);
                    i++;
                    numero = pasaje_String_A_int(num);
                    elemento = te_crear(numero);
                    c_encolar(cola, elemento);
                }
                break;
            case 2:
                do{
                    do{
                        printf("Ingrese la cantidad de elementos a cargar: ");
                        fflush(stdin);
                        fgets(num, TAMANO_NUM, stdin);
                        entrada = numEnteros(num) && validarEnter(num);
                    } while (!entrada);
                    cantidadElementos = pasaje_String_A_int(num);  
                    entrada = numeroRango(cantidadElementos,0,100);
                } while (!entrada);
                srand(time(NULL));
                while (i < cantidadElementos) {
                    numero = rand() % 101;
                    elemento = te_crear(numero);
                    c_encolar(cola, elemento);
                    i++;
                }
                break;
            default:
                printf("\n\n***************************************************\n");
                printf("Ha introducido un valor erroneo. Vuelva a intentar.\n");
                printf("***************************************************\n\n");
                entrada = false;
                break;
        }
    } while (!entrada);
    return;
}

void c_cargar_positivos(Cola cola){
    //Inicializaciones
    bool entrada = true;
    char num[TAMANO_NUM];
    int cantidadElementos, opcion, numero, i = 0;
    TipoElemento elemento;
    do{
        do{
            printf("\n**************************************************\n¿Como quiere cargar la cola?\n1. Manualmente\n2. Aleatoriamente\n\n");
            printf("INGRESE UNA OPCION: ");
            fflush(stdin);
            fgets(num, TAMANO_NUM, stdin);
            entrada = numEnteros(num) && validarEnter(num);
        } while (!entrada);
        opcion = pasaje_String_A_int(num);
        switch (opcion) {
            case 1:
                do{
                    do{
                        printf("Ingrese la cantidad de elementos a cargar: ");
                        fflush(stdin);
                        fgets(num, TAMANO_NUM, stdin);
                        entrada = numEnteros(num) && validarEnter(num);
                    } while (!entrada);
                    cantidadElementos = pasaje_String_A_int(num);  
                    entrada = numeroRango(cantidadElementos,0,100);
                } while (!entrada);
                while (i < cantidadElementos){
                    do{
                        do{
                            printf("Ingrese el elemento de posicion [%d]: ", i + 1);
                            fflush(stdin);
                            fgets(num, TAMANO_NUM, stdin);
                            entrada = numEnteros(num) && validarEnter(num);
                        } while (!entrada);
                        numero = pasaje_String_A_int(num);
                        entrada = numeroRango(numero,1,90);
                    }while (!entrada);
                    i++;
                    elemento = te_crear(numero);
                    c_encolar(cola, elemento);
                }
                break;
            case 2:
                do{
                    do{
                        printf("Ingrese la cantidad de elementos a cargar: ");
                        fflush(stdin);
                        fgets(num, TAMANO_NUM, stdin);
                        entrada = numEnteros(num) && validarEnter(num);
                    } while (!entrada);
                    cantidadElementos = pasaje_String_A_int(num);  
                    entrada = numeroRango(cantidadElementos,0,100);
                } while (!entrada);
                srand(time(NULL));
                while (i < cantidadElementos) {
                    numero = 1 + rand() % 90;
                    elemento = te_crear(numero);
                    c_encolar(cola, elemento);
                    i++;
                }
                break;
            default:
                printf("\n\n***************************************************\n");
                printf("Ha introducido un valor erroneo. Vuelva a intentar.\n");
                printf("***************************************************\n\n");
                entrada = false;
                break;
        }
    } while (!entrada);
    return;
}

void c_cargar_sinRepetidos(Cola cola){
    //Inicializaciones
    bool entrada = true;
    char num[TAMANO_NUM];
    int cantidadElementos, opcion, numero, i = 0;
    TipoElemento elemento;

    do{
        do{
            printf("\n**************************************************\n¿Como quiere cargar la cola?\n1. Manualmente\n2. Aleatoriamente\n\n");
            printf("INGRESE UNA OPCION: ");
            fflush(stdin);
            fgets(num, TAMANO_NUM, stdin);
            entrada = numEnteros(num) && validarEnter(num);
        } while (!entrada);
        opcion = pasaje_String_A_int(num);
        switch (opcion) {
            case 1:
                do{
                    do{
                        printf("Ingrese la cantidad de elementos a cargar: ");
                        fflush(stdin);
                        fgets(num, TAMANO_NUM, stdin);
                        entrada = numEnteros(num) && validarEnter(num);
                    } while (!entrada);
                    cantidadElementos = pasaje_String_A_int(num);  
                    entrada = numeroRango(cantidadElementos,0,100);
                } while (!entrada);
                while (i < cantidadElementos){
                    do{
                        do{
                            printf("Ingrese el elemento de posicion [%d]: ", i + 1);
                            fflush(stdin);
                            fgets(num, TAMANO_NUM, stdin);
                            entrada = numEnteros(num) && validarEnter(num);
                        } while (!entrada);
                        numero = pasaje_String_A_int(num);
                        entrada = c_elementoRepetido(cola, numero);
                        if (!entrada){
                            printf("\n****************************************************\n");
                            printf("Ha introducido un valor repetido. Vuelva a intentar.\n");
                            printf("****************************************************\n\n");
                        }
                    }while(!entrada);
                    i++;
                    elemento = te_crear(numero);
                    c_encolar(cola, elemento);
                }
                break;
            case 2:
                do{
                    do{
                        printf("Ingrese la cantidad de elementos a cargar: ");
                        fflush(stdin);
                        fgets(num, TAMANO_NUM, stdin);
                        entrada = numEnteros(num) && validarEnter(num);
                    } while (!entrada);
                    cantidadElementos = pasaje_String_A_int(num);  
                    entrada = numeroRango(cantidadElementos,0,100);
                } while (!entrada);

                srand(time(NULL));

                while (i < cantidadElementos) {
                    numero = 2 + rand() % 100;
                    entrada = c_elementoRepetido(cola, numero);
                    if (entrada){
                        elemento = te_crear(numero);
                        c_encolar(cola, elemento);
                        int k = c_longitud(cola);
                        i++;
                    }
                }
                break;
            default:
                printf("\n\n***************************************************\n");
                printf("Ha introducido un valor erroneo. Vuelva a intentar.\n");
                printf("***************************************************\n\n");
                entrada = false;
                break;
        }
    } while (!entrada);
    return;
}

void c_cargar_sinRepetidosRango(Cola cola, int infMax, int infMin, int supMin, int supMax){
    //Inicializaciones
    bool entrada = true;
    char num[TAMANO_NUM];
    int cantidadElementos, opcion, numero, i = 0;
    TipoElemento elemento;

    do{
        do{
            printf("\n**************************************************\n¿Como quiere cargar la cola?\n1. Manualmente\n2. Aleatoriamente\n\n");
            printf("INGRESE UNA OPCION: ");
            fflush(stdin);
            fgets(num, TAMANO_NUM, stdin);
            entrada = numEnteros(num) && validarEnter(num);
        } while (!entrada);
        opcion = pasaje_String_A_int(num);
        switch (opcion) {
            case 1:
                do{
                    do{
                        printf("Ingrese la cantidad de elementos a cargar: ");
                        fflush(stdin);
                        fgets(num, TAMANO_NUM, stdin);
                        entrada = numEnteros(num) && validarEnter(num);
                    } while (!entrada);
                    cantidadElementos = pasaje_String_A_int(num);  
                    entrada = numeroRango(cantidadElementos,0,100);
                } while (!entrada);
                while (i < cantidadElementos){
                    do{
                        do{
                            do{
                                printf("Ingrese el elemento de posicion [%d]: ", i + 1);
                                fflush(stdin);
                                fgets(num, TAMANO_NUM, stdin);
                                entrada = numEnteros(num) && validarEnter(num);
                            } while (!entrada);
                            numero = pasaje_String_A_int(num);
                            entrada = c_elementoRepetido(cola, numero);
                            if (!entrada){
                                printf("\n****************************************************\n");
                                printf("Ha introducido un valor repetido. Vuelva a intentar.\n");
                                printf("****************************************************\n\n");
                            }
                        }while(!entrada);
                        entrada = numeroRangoMedio(numero, infMax, infMin, supMin, supMax);
                    } while (!entrada);
                    
                    i++;
                    elemento = te_crear(numero);
                    c_encolar(cola, elemento);
                }
                break;
            case 2:
                do{
                    do{
                        printf("Ingrese la cantidad de elementos a cargar: ");
                        fflush(stdin);
                        fgets(num, TAMANO_NUM, stdin);
                        entrada = numEnteros(num) && validarEnter(num);
                    } while (!entrada);
                    cantidadElementos = pasaje_String_A_int(num);  
                    entrada = numeroRango(cantidadElementos,0,100);
                } while (!entrada);

                srand(time(NULL));

                while (i < cantidadElementos) {
                    numero = 2 + rand() % 100;
                    entrada = c_elementoRepetido(cola, numero);
                    if (entrada){
                        elemento = te_crear(numero);
                        c_encolar(cola, elemento);
                        int k = c_longitud(cola);
                        i++;
                    }
                }
                break;
            default:
                printf("\n\n***************************************************\n");
                printf("Ha introducido un valor erroneo. Vuelva a intentar.\n");
                printf("***************************************************\n\n");
                entrada = false;
                break;
        }
    } while (!entrada);
    return;
}

bool c_elementoRepetido(Cola cola, int numero){
    Cola cola_aux = c_crear();
    TipoElemento elem;
    bool encontrado = true;
    while (!c_es_vacia(cola)) {
        elem = c_desencolar(cola);
        if (elem->clave == numero){
            encontrado = false;
        }
        c_encolar(cola_aux, elem);
    }
    c_intercambiar(cola, cola_aux);
    return encontrado;
}
