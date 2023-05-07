#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "tipo_elemento.h"
#include "pilas.h"
#include "pilas_utilidades.h"
#include "funcionesEjercicios.h"

/* Ejercicio 2 */
//a. Buscar una clave y determinar si existe en la Pila (sin perder la pila).
bool BuscarClave (Pila p, int clave) {

    int ocurrencia = false; //bandera. TRUE si se haya la clave
    
    Pila paux;
    paux = p_crear();
    TipoElemento te;

    //usamos una pila auxiliar para no perder la original
    p_intercambiar(paux, p);

    while (p_es_vacia(paux) != true) {
        te = p_desapilar(paux);
        p_apilar(p, te);

        if (te->clave == clave) ocurrencia = true;
    }  

    return ocurrencia;
}

//b. Colocar en una posición ordinal determinada, recibida por parámetro, un nuevo elemento (Insertar un elemento nuevo).
Pila Insertar (Pila p, TipoElemento te, int pos) {

    Pila paux;
    paux = p_crear();

    Pila clonP;
    clonP = p_crear();
    Pila retorno;
    retorno = p_crear();

    TipoElemento teAux;

    int insercion = 1;

    if (p_es_vacia(p)) {
        p_apilar (paux, te);
    }
    if (p_es_llena(p)) {
        printf("\n\n\tNo se pudo completar la insercion dado que la pila posee el tamanio maximo\n\n");
    }

    while (p_es_vacia(p) != true && p_es_llena(p) != true) {

        if (insercion == pos) {
            p_apilar (paux, te);
        }

        teAux = p_desapilar(p);
        p_apilar(paux, teAux);
        p_apilar(clonP, teAux);

        insercion++;
    } 

    p_intercambiar(retorno, paux);
    p_intercambiar(p, clonP);

    return retorno;

}

//c. Eliminar de una pila un elemento dado (primera ocurrencia encontrada por la clave).
Pila EliminarClave (Pila p, TipoElemento te) {

    Pila paux;
    paux = p_crear();

    Pila clonP;
    clonP = p_crear();
    Pila retorno;
    retorno = p_crear();

    TipoElemento teAux;

    bool ocurrencia = false; // bandera que indica si ya fue eliminada la primera ocurrencia
                             // true: primera ocurrencia ya eliminada

    //usamos una pila auxiliar para no perder la original
    if (p_es_vacia(p) == true) printf("\n\n\tNo se pudo eliminar ningun elemento dado que la pila es vacia\n\n");
    while (p_es_vacia(p) != true) {
        teAux = p_desapilar(p);
        p_apilar(clonP, teAux);
        if (teAux->clave != te->clave || ocurrencia == true) {
            p_apilar(paux, teAux);
        }
        else {
            ocurrencia = true;
        }
    }

    p_intercambiar(retorno, paux);
    p_intercambiar(p, clonP);

    if (ocurrencia == false) {
        printf("\n\n\tNo se encontro ningun elemento con clave igual a la ingresada, por lo que no se pudo eliminar\n\n");
    }

    return retorno;
}

//d. Intercambiar los valores de 2 posiciones ordinales de la pila, por ejemplo la 2da con la 4ta.
Pila IntercambiarDosElementos (Pila p, int pos1, int pos2) {

    Pila paux;
    paux = p_crear();

    Pila clonP;
    clonP = p_crear();
    Pila retorno;
    retorno = p_crear();

    TipoElemento teAux;

    TipoElemento te1; // se guarda el elemento pos1 para intercambiar
    TipoElemento te2; // se guarda el elemento pos2 para intercambiar

    int ordinal = 1;

    while (p_es_vacia(p) != true) {

        teAux = p_desapilar(p);

        if (ordinal == pos1) {
            te1 = teAux;
        }
        if (ordinal == pos2) {
            te2 = teAux;
        }

        p_apilar(paux, teAux);
        p_apilar(clonP, teAux);
        ordinal++;
    }

    ordinal--;

    while (p_es_vacia(paux) != true) {

        if (ordinal == pos1) {
            p_apilar (retorno, te2);
        }
        else if (ordinal == pos2) {
            p_apilar (retorno, te1);
        }
        
        teAux = p_desapilar(paux);

        if (ordinal != pos1 && ordinal != pos2) {
            p_apilar(retorno, teAux);
        }   
        ordinal--;
    } 

    p_intercambiar(p, clonP);

    return retorno; 
}

//e. Duplicar el contenido de una pila.
Pila DuplicarContenido (Pila p) {

    Pila paux;
    paux = p_crear();

    Pila clonP;
    clonP = p_crear();
    Pila retorno;
    retorno = p_crear();

    TipoElemento te;
    
    while (p_es_vacia(p) != true) {
        te = p_desapilar(p);
        p_apilar(paux, te);
        p_apilar(clonP, te);
    }

    p_intercambiar(retorno, paux);
    p_intercambiar(p, clonP);

    return retorno;
}

//f. Contar los elementos de la pila.
int ContarElementos (Pila p) {

    int contador = 0;
    
    Pila paux;
    paux = p_crear();
    TipoElemento te;

    //usamos una pila auxiliar para no perder la original
    p_intercambiar(paux, p);

    while (p_es_vacia(paux) != true) {
        te = p_desapilar(paux);
        p_apilar(p, te);
        contador++;
    }  

    return contador;
}

/* Ejercicio 3 */
//-----------------------------------------------------------------------------------------------------------
bool pilas_iguales(Pila p1, Pila p2, int tamano_pila){
    bool bandera_igual = true;
    int contador_igual = 0;
    TipoElemento x1;
    TipoElemento x2;
    //Creo una pilar auxiliar para acumular las claves que son iguales
    Pila p_aux = p_crear();
    //Recorro las pilas comparando sus claves
    /*
        La complejidad algoritmica del siguiente bloque de codigo es de O(n), ya que el peor de los casos
        es el while   
    */
    while (bandera_igual && contador_igual != tamano_pila){

        x1 = p_desapilar(p1);
        x2 = p_desapilar(p2);

        if (x1->clave != x2->clave){
            //Si encuentra una desigualdad, cambia la bandera a false
            bandera_igual = false;
        } else {
            //Si encuentra una igualdad, la bandera mantiene su valor y y x1 y x2 se apila en la pila auxiliar
            p_apilar(p_aux, x1);
            p_apilar(p_aux, x2);
            contador_igual = contador_igual + 1;
        }
    }
    //Si la desigualdad se encuentra en la primera comparacion
    if (p_es_vacia(p_aux) && !bandera_igual){   
        //Apila los valores desiguales a sus pilas originales
        p_apilar(p1, x1);
        p_apilar(p2, x2);
        return (bandera_igual);
    }
    else if (!p_es_vacia(p_aux) && !bandera_igual) //Si la desigualdad se encuentra en la mitad del recorrido
    {
        //Reapila a su forma original
        p_apilar(p1, x1);
        p_apilar(p2, x2);
        while (!p_es_vacia(p_aux)) {

            x1 = p_desapilar(p_aux);
            p_apilar(p1, x1);
            x2 = p_desapilar(p_aux);
            p_apilar(p2, x2);
        }
        return (bandera_igual);
    }
    else if (bandera_igual) //Si las pilas son iguales
    {
        //Reapila a su forma original
        while (!p_es_vacia(p_aux)){
            x1 = p_desapilar(p_aux);
            p_apilar(p1, x1);
            x2 = p_desapilar(p_aux);
            p_apilar(p2, x2);
        }
        return (bandera_igual);
    }
}

/* Ejercicio 4 */
//-----------------------------------------------------------------------------------------------------------

void decimal_Binario_Hexa(Pila pila, int decimal,int base){
    //Creo la pila y el TE
    TipoElemento resto;
    int aux;
    bool salida = false;
    while (!salida) {
        if (decimal < base) {
            resto = te_crear(decimal);
            p_apilar(pila,resto);
            salida = true;
        } else {
            resto = te_crear(decimal % base);
            p_apilar(pila,resto);
            decimal = decimal/base;
        }
    }
}

char *pasaje(Pila pila){
    Pila aux1 = p_crear();
    TipoElemento elemento;
    char auxiliar[10];
    char *numero = (char*)calloc(50,1);
    
    while (!p_es_vacia(pila)) {
        elemento = p_desapilar(pila);
        if (elemento->clave >= 10) {
            switch (elemento->clave) {
            case 10:
                strcat(numero,"A");
                break;
            case 11:
                strcat(numero,"B");
                break;
            case 12:
                strcat(numero,"C");
                break;
            case 13:
                strcat(numero,"D");
                break;
            case 14:
                strcat(numero,"E");
                break;
            case 15:
                strcat(numero,"F");
                break;
            default:
                break;
            }
        } else {
            sprintf(auxiliar,"%d",elemento->clave);
            strcat(numero, auxiliar);
        }
        p_apilar(aux1,elemento);
    }
    p_intercambiar(pila, aux1);
    return numero;
}

/* Ejercicio 5 */
//-----------------------------------------------------------------------------------------------------------
Pila p_invertir(Pila pila_original) {
    // Creo las pilas.
    Pila pila_invertida = p_crear();
    Pila pila_auxiliar = p_crear();
    TipoElemento elemento;

    // Desapilo elementos de la pila original y apilarlos en la invertida.
    while (!p_es_vacia(pila_original)) {
        elemento = p_desapilar(pila_original);
        p_apilar(pila_invertida, elemento);
        p_apilar(pila_auxiliar, elemento);
    }
    // Devuelvo los elementos de la auxiliar a la original
    p_intercambiar(pila_original, pila_auxiliar);
    return pila_invertida;
}

/* Ejercicio 6
-----------------------------------------------------------------------------------------------------------
PLANTEAMIENTO ---> forma iterativa */
Pila eliminarElemento_iterativo(Pila pila_user, int numero_user){
    Pila pila_aux = p_crear();
    Pila pila_sinNumero = p_crear();
    Pila pila_sinNumero_aux = p_crear();
    TipoElemento elemento;
    bool encontrado = false;

    while (!p_es_vacia(pila_user)) {
        elemento = p_desapilar(pila_user);
        if (elemento->clave != numero_user){
            p_apilar(pila_sinNumero_aux, elemento);
        } else encontrado = true;
        p_apilar(pila_aux, elemento);
    }
    p_intercambiar(pila_sinNumero, pila_sinNumero_aux);
    p_intercambiar(pila_user, pila_aux);
    if (!encontrado) printf("\n\n**** El numero ingresado NO se ha encontrado en la pila. ****\n\n");
    return pila_sinNumero;
}

/*
-----------------------------------------------------------------------------------------------------------
PLANTEAMIENTO ---> forma recursiva */
Pila eliminarElemento_recursivo(Pila pila_user, Pila pila_aux, Pila pila_sinNumeroAux, bool encontrado, int numero_user){
    // Caso base
    if (p_es_vacia(pila_user)){
        p_intercambiar(pila_user, pila_aux);
        Pila pila_sinNumero = p_crear();
        p_intercambiar(pila_sinNumero, pila_sinNumeroAux);
        if (!encontrado) printf("\n\n**** El numero ingresado NO se ha encontrado en la pila. ****\n\n");
        return pila_sinNumero;
    }
    // Caso recursivo
    else {
        TipoElemento elemento = p_desapilar(pila_user);
        if (elemento->clave != numero_user){
            p_apilar(pila_sinNumeroAux, elemento);
        } else encontrado = true;
        p_apilar(pila_aux, elemento);
        return eliminarElemento_recursivo(pila_user, pila_aux, pila_sinNumeroAux, encontrado, numero_user);
    }
}

void menu(){
    printf("        Menu principal\n\n");
    printf(" 1.  Ejecutar funcion ITERATIVA\n");
    printf(" 2.  Ejecutar funcion RECURSIVA\n");
    printf(" 0.  Finalizar ejecucion...\n\n");
    printf("INGRESE UNA OPCION: ");
}

/* Ejercicio 7 */
//-----------------------------------------------------------------------------------------------------------
Pila elementosEnComun(Pila pila_1, Pila pila_2){
    bool enComun = false, encontrado;
    
    Pila pila_en_comun = p_crear();
    Pila pila_en_comun_aux = p_crear();
    Pila p_aux1 = p_crear();
    Pila p_aux2 = p_crear();

    TipoElemento elemP1;
    TipoElemento elemP2;
    TipoElemento elemAux;

    while (!p_es_vacia(pila_1)) {
        elemP1 = p_desapilar(pila_1);
        p_apilar(p_aux1, elemP1);

        while (!p_es_vacia(pila_2)) {
            elemP2 = p_desapilar(pila_2);
            p_apilar(p_aux2, elemP2);
            if (elemP1->clave == elemP2->clave){
                // Si el elemento NO se encontro previamente...
                if (p_es_vacia(pila_en_comun)){
                    p_apilar(pila_en_comun, elemP1);
                    enComun = true;
                } else {
                    encontrado = false;
                    while (!p_es_vacia(pila_en_comun)) {
                        elemAux = p_desapilar(pila_en_comun);
                        if (elemAux->clave == elemP1->clave) encontrado = true;
                        p_apilar(pila_en_comun_aux, elemAux);
                    }
                    p_intercambiar(pila_en_comun, pila_en_comun_aux);
                    if (!encontrado) {
                        p_apilar(pila_en_comun, elemP1);
                        enComun = true; 
                    }
                }
            }
        }
        p_intercambiar(pila_2, p_aux2);
    }
    p_intercambiar(pila_1, p_aux1);
    p_intercambiar(pila_en_comun_aux, pila_en_comun);
    if (!enComun) printf("***** No hay elementos en comun entre ambas pilas *****\n\n");
    return pila_en_comun_aux;
}

/* Ejercicio 8 */
//-----------------------------------------------------------------------------------------------------------
Pila ValoresYCantidad (Pila p) {
    int ocurrencias;

    int longitudPila = ContarElementos(p); //cantidad de elementos de la pila ingresada
    int cont = 0;

    int * valores = malloc(sizeof(int) * longitudPila);
    int claves[longitudPila];

    Pila copia;
    copia = p_crear();
    Pila aux;
    aux = p_crear();
    Pila retorno;
    retorno = p_crear();

    TipoElemento te;
    TipoElemento te2;
    TipoElemento te3;

    //se clona la pila en 'copia' para no perder la original
    while (p_es_vacia(p) != true) {
        te = p_desapilar(p);
        p_apilar(aux, te);
        p_apilar(retorno, te);
    }
    p_intercambiar(p, aux);
    p_intercambiar(aux, retorno);
    p_intercambiar(copia, aux);

    while (p_es_vacia(copia) != true) {
        //hasta que la pila es vacÃ­a, se desapila el primer elemento de la lista
        te = p_desapilar(copia);
        ocurrencias = 1;

        while (p_es_vacia(copia) != true) {
            te2 = p_desapilar(copia);
            //se compara elemento desapilado a su vez con el resto de la pila, si coinciden en clave, no se apila y suma una ocurrencia
            if (te2->clave == te->clave) {
                ocurrencias++;
                //omito apilar
            }
            else {
                p_apilar(aux, te2);
            }
        }

        //se guarda la clave y la cantidad de ocurrencias de esta en la pila
        claves[cont] = te->clave;
        valores[cont] = ocurrencias;

        //y se apilan como clave y valor en la lista a devolver
        void * cargaVoidAux = &valores[cont];
        te3 = te_crear_con_valor(claves[cont], cargaVoidAux);
        p_apilar(retorno, te3);

        cont++;

        //a esta altura auxiliar posee los elementos de copia invertidos exceptuando las ocurrencias 
        //y el primer elemento desapilado al principio del ciclo

        //la pila auxiliar vuelve a copia, de donde se tomaran los datos en la proxima vuelta del ciclo.
        
        p_intercambiar(copia, aux);
    }
    return retorno;
}