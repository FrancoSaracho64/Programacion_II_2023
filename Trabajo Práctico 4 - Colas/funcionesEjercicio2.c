#include <stdio.h>
#include "colas.h"
#include "Validaciones.h"
#include "funcionesEjercicios.h"

const int limSup = 500;
const int limInf = -500;

void Ejercicio1 (Cola c){
    //INPUT TIPOELEMENTO
    int claveInsertar;
    char claveInsertarTeclado[TAMANO_NUM];
    bool entrada = true;

    do {
        do{
            printf("Ingrese la clave del elemento a buscar: ");
            fflush(stdin);
            fgets(claveInsertarTeclado, TAMANO_NUM, stdin);
            entrada = numEnteros(claveInsertarTeclado) && validarEnter(claveInsertarTeclado);
        } while (!entrada);
    claveInsertar = pasaje_String_A_int(claveInsertarTeclado);
    entrada = numeroRango(claveInsertar, limInf, limSup);
    } while (!entrada);

    //LLAMADA A LA FUNCION Y PRINT RESULTADO
    TipoElemento teEjemplo = te_crear(claveInsertar);
    bool resultadoA = c_contiene_elemento(c, teEjemplo);

    printf("\nResultado funcion A -> ");
    if (resultadoA) printf("VERDADERO: El elemento se encuentra en la cola");
    else printf("FALSO: El elemento NO se encuentra en la cola");
}

void Ejercicio2 (Cola c){
    //INPUT TIPOELEMENTO
    int claveInsertar;
    char claveInsertarTeclado[TAMANO_NUM];
    bool entrada = true;

    do {
        do{
            printf("Ingrese la clave del elemento a agregar: ");
            fflush(stdin);
            fgets(claveInsertarTeclado, TAMANO_NUM, stdin);
            entrada = numEnteros(claveInsertarTeclado) && validarEnter(claveInsertarTeclado);
        } while (!entrada);
    claveInsertar = pasaje_String_A_int(claveInsertarTeclado);
    entrada = numeroRango(claveInsertar, limInf, limSup);
    } while (!entrada);

    //INPUT POSICION
    int Posicion;
    char PosicionTeclado[TAMANO_NUM];
    int cantidadElementos = c_contar_elementos(c) + 1;
    if (cantidadElementos == 0) cantidadElementos++;

    do {
        do{
            printf("Ingrese la posicion donde se va a insertar el elemento: ");
            fflush(stdin);
            fgets(PosicionTeclado, TAMANO_NUM, stdin);
            entrada = numEnteros(PosicionTeclado) && validarEnter(PosicionTeclado);
        } while (!entrada);
    Posicion = pasaje_String_A_int(PosicionTeclado);
    entrada = numeroRango(Posicion, 1, cantidadElementos);
    } while (!entrada);

    //LLAMADA A LA FUNCION Y PRINT RESULTADO
    TipoElemento teEjemplo = te_crear(claveInsertar);
    Cola resultadoB = c_agregar_en_posicion(c, teEjemplo, Posicion);
    printf("\nResultado funcion B (Cola retornada)\n");
    c_mostrar(resultadoB);
}

void Ejercicio3 (Cola c){
    //INPUT TIPOELEMENTO
    int claveInsertar;
    char claveInsertarTeclado[TAMANO_NUM];
    bool entrada = true;
    do {
        do{
            printf("Ingrese la clave del elemento a eliminar en todas sus ocurrencias: ");
            fflush(stdin);
            fgets(claveInsertarTeclado, TAMANO_NUM, stdin);
            entrada = numEnteros(claveInsertarTeclado) && validarEnter(claveInsertarTeclado);
        } while (!entrada);
    claveInsertar = pasaje_String_A_int(claveInsertarTeclado);
    entrada = numeroRango(claveInsertar, limInf, limSup);
    } while (!entrada);

    //LLAMADA A LA FUNCION Y PRINT RESULTADO
    TipoElemento teEjemplo = te_crear(claveInsertar);
    Cola resultadoC = c_eliminar_elemento(c, teEjemplo);
    printf("\nResultado funcion C (Cola retornada)\n");
    c_mostrar(resultadoC);
}

void Ejercicio4 (Cola c){
    int resultadoD = c_contar_elementos(c);
    printf("\nResultado funcion D -> ");
    printf("Cantidad de elementos: %d\n", resultadoD);
}

void Ejercicio5 (Cola c){
    Cola resultadoE = c_copiar(c);
    printf("\nResultado funcion E (Cola retornada)\n");
    c_mostrar(resultadoE);
}

void Ejercicio6 (Cola c){
    Cola resultadoF = c_invertir_contenido(c);
    printf("\nResultado funcion F (Cola retornada)\n");
    c_mostrar(resultadoF);
}

