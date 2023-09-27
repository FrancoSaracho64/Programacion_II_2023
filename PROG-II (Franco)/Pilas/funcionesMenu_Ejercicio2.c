#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tipo_elemento.h"
#include "pilas.h"
#include "pilas_utilidades.h"
#include "funcionesEjercicios.h"

const int limSupOPC = 6;
const int limInfOPC = 0;
const int limSup = 500;
const int limInf = -500;

void Ejercicio1 (Pila p){ 
    int claveBusqueda;
    char claveBusquedaTeclado[TAMANO_NUM];
    bool entradaA = true;

    do {
        do{
            printf("Ingrese la clave que desea buscar: ");
            fflush(stdin);
            fgets(claveBusquedaTeclado, TAMANO_NUM, stdin);
            entradaA = numEnteros(claveBusquedaTeclado) && validarEnter(claveBusquedaTeclado);
        } while (!entradaA);
    claveBusqueda = pasaje_String_A_int(claveBusquedaTeclado);
    entradaA = numeroRango(claveBusqueda, limInf, limSup);
    } while (!entradaA);
    
    bool resultadoA = BuscarClave(p, claveBusqueda);

    printf("\nResultado funcion A -> ");
    if (resultadoA) printf("VERDADERO: La clave se encuentra en la pila");
    else printf("FALSO: La clave NO se encuentra en la pila");
}

void Ejercicio2 (Pila p){
    int claveInsertar;
    char claveInsertarTeclado[TAMANO_NUM];
    bool entradaB = true;

    do {
        do{
            printf("Ingrese la clave del elemento a insertar: ");
            fflush(stdin);
            fgets(claveInsertarTeclado, TAMANO_NUM, stdin);
            entradaB = numEnteros(claveInsertarTeclado) && validarEnter(claveInsertarTeclado);
        } while (!entradaB);
    claveInsertar = pasaje_String_A_int(claveInsertarTeclado);
    entradaB = numeroRango(claveInsertar, limInf, limSup);
    } while (!entradaB);

    int posInsertar;
    char posInsertarTeclado[TAMANO_NUM];
    bool entradaB2 = true;
    int cantidadElementos = ContarElementos(p);
    if (cantidadElementos == 0) {
        printf("\nLa pila esta vacia, por lo que se inserta en la primera posicion\n");
        posInsertar = 1;
    }
    else {
        do {
            do{
                printf("Ingrese la posicion de la pila donde insertar el elemento: ");
                fflush(stdin);
                fgets(posInsertarTeclado, TAMANO_NUM, stdin);
                entradaB2 = numEnteros(posInsertarTeclado) && validarEnter(posInsertarTeclado);
            } while (!entradaB2);
        posInsertar = pasaje_String_A_int(posInsertarTeclado);
        entradaB2 = numeroRango(posInsertar, 1, cantidadElementos);
        } while (!entradaB2);
    }

    TipoElemento teEjemplo = te_crear(claveInsertar);
    Pila resultadoB = Insertar(p, teEjemplo, posInsertar);

    printf("\nResultado funcion B (Pila retornada)\n");
    p_mostrar(resultadoB);
}

void Ejercicio3 (Pila p){
    int claveInsertarC;
    char claveInsertarTecladoC[TAMANO_NUM];
    bool entradaC = true;

    do {
        do{
            printf("Ingrese la clave del elemento a eliminar: ");
            fflush(stdin);
            fgets(claveInsertarTecladoC, TAMANO_NUM, stdin);
            entradaC = numEnteros(claveInsertarTecladoC) && validarEnter(claveInsertarTecladoC);
        } while (!entradaC);
    claveInsertarC = pasaje_String_A_int(claveInsertarTecladoC);
    entradaC = numeroRango(claveInsertarC, limInf, limSup);
    } while (!entradaC);

    TipoElemento teEjemplo2 = te_crear(claveInsertarC);

    Pila resultadoC = EliminarClave(p, teEjemplo2);
    printf("\nResultado funcion C (Pila retornada)\n");
    p_mostrar(resultadoC);
}

void Ejercicio4 (Pila p){
    int cantidadElementosD = ContarElementos(p);

    int posInsertarD;
    char posInsertarTecladoD[TAMANO_NUM];
    bool entradaD = true;
    
    if (p_es_vacia(p)) {
        printf("La pila esta vacia, por lo que se insertara en la primera posicion\n");
        posInsertarD = 1;
    }
    else {
        do {
            do{
                printf("Ingrese la posicion de la pila del primer elemento a intercambiar: ");
                fflush(stdin);
                fgets(posInsertarTecladoD, TAMANO_NUM, stdin);
                entradaD = numEnteros(posInsertarTecladoD) && validarEnter(posInsertarTecladoD);
            } while (!entradaD);
        posInsertarD = pasaje_String_A_int(posInsertarTecladoD);
        entradaD = numeroRango(posInsertarD, 1, cantidadElementosD);
        } while (!entradaD);
    }

    int posInsertarD2;
    char posInsertarTecladoD2[TAMANO_NUM];
    bool entradaD2 = true;
    
    if (p_es_vacia(p)) {
        printf("La pila esta vacia, por lo que se insertara en la primera posicion\n");
        posInsertarD2 = 1;
    }
    else {
        do {
            do{
                printf("Ingrese la posicion de la pila del segundo elemento a intercambiar: ");
                fflush(stdin);
                fgets(posInsertarTecladoD2, TAMANO_NUM, stdin);
                entradaD2 = numEnteros(posInsertarTecladoD2) && validarEnter(posInsertarTecladoD2);
            } while (!entradaD2);
        posInsertarD2 = pasaje_String_A_int(posInsertarTecladoD2);
        entradaD2 = numeroRango(posInsertarD2, 1, cantidadElementosD);
        } while (!entradaD2);
    }

    Pila resultadoD = IntercambiarDosElementos(p, posInsertarD, posInsertarD2);
    printf("\nResultado funcion D (Pila retornada)\n");
    p_mostrar(resultadoD);
}

void Ejercicio5 (Pila p){
    Pila resultadoE = DuplicarContenido(p);
    printf("\nResultado funcion E (Pila retornada)\n");
    p_mostrar(resultadoE);
}

void Ejercicio6 (Pila p){
    int resultadoF = ContarElementos(p);
    printf("\nResultado funcion F -> ");
    printf("Cantidad de elementos: %d\n", resultadoF);
}