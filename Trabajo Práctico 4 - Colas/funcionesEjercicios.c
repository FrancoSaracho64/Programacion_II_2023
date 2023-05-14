#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "colas.h"
#include "pilas.h"
#include "listas.h"
#include "colas_utilidades.h"
#include "pilas_utilidades.h"

/*Ejercicio 2*/ //----------------------------------------------------------------------------------------
//PUNTO A
bool c_contiene_elemento(Cola cola, TipoElemento elemento) {
    Cola Caux = c_crear();
    bool contiene = false;
    while (!c_es_vacia(cola)) {
        TipoElemento X = c_desencolar(cola);
        c_encolar(Caux, X);
        if (X->clave == elemento->clave) {
            contiene = true;
        }
    }
    c_intercambiar(cola, Caux);
    return contiene;
}

//PUNTO B
Cola c_agregar_en_posicion(Cola cola, TipoElemento elemento, int posicion) {
    Cola Caux = c_crear();
    Cola retorno = c_crear();
    int posicion_actual = 1;

    if (c_es_vacia(cola)) {
        c_encolar (retorno, elemento);
    }
    if (c_es_llena(cola)) {
        printf("\n\n\tNo se pudo completar la insercion dado que la cola posee el tamanio maximo\n\n");
    }

    while (!c_es_vacia(cola)) {
        TipoElemento X = c_desencolar(cola);
        c_encolar(Caux, X);
        c_encolar(retorno, X);
    }
    c_intercambiar(cola, retorno);

    while (!c_es_vacia(Caux)) {
        TipoElemento X = c_desencolar(Caux);
        if (posicion_actual == posicion) {
            c_encolar(retorno, elemento);
        }
        c_encolar(retorno, X);
        posicion_actual++;
    }
    if (posicion == posicion_actual){
        c_encolar(retorno, elemento);
    }

    return retorno;
}

//PUNTO C
Cola c_eliminar_elemento(Cola cola, TipoElemento elemento) {
    Cola Caux = c_crear();
    Cola retorno = c_crear();

    bool ocurrencia = false; // bandera que indica si hubo elementos eliminados

    if (c_es_vacia(cola)) {
        printf("\n\n\tNo se pudo eliminar ningun elemento dado que la cola es vacia\n\n");
        ocurrencia = true;
    }
    while (!c_es_vacia(cola)) {
        TipoElemento X = c_desencolar(cola);
        c_encolar(Caux, X);
        c_encolar(retorno, X);
    }
    c_intercambiar(cola, retorno);

    while (!c_es_vacia(Caux)) {
        TipoElemento X = c_desencolar(Caux);
        if (X->clave != elemento->clave) {
            c_encolar(retorno, X);
        }
        else ocurrencia = true;
    }

    if (ocurrencia == false) {
        printf("\n\n\tNo se encontro ningun elemento con clave igual a la ingresada, por lo que no se pudo eliminar\n\n");
    }

    return retorno;
}

//PUNTO D
int c_contar_elementos(Cola cola) {
    int contador = 0;
    Cola Caux = c_crear();
    while (!c_es_vacia(cola)) {
        TipoElemento X = c_desencolar(cola);
        contador++;
        c_encolar(Caux, X);
    }
    c_intercambiar(cola, Caux);
    return contador;
}

//PUNTO E
Cola c_copiar(Cola cola) {
    Cola nueva_cola = c_crear();
    Cola Caux = c_crear();
    while (!c_es_vacia(cola)) {
        TipoElemento X = c_desencolar(cola);
        c_encolar(nueva_cola, X);
        c_encolar(Caux, X);
    }
    c_intercambiar(cola, Caux);
    return nueva_cola;
}

//PUNTO F
Cola c_invertir_contenido(Cola cola) {
    TipoElemento teAux;
    Pila Paux = p_crear();
    Cola Caux = c_crear();
    Cola retorno = c_crear();

    while (!c_es_vacia(cola)) {
        teAux = c_desencolar(cola);
        p_apilar(Paux, teAux);
        c_encolar(Caux, teAux);
    }

    while (!p_es_vacia(Paux)) {
        teAux = p_desapilar(Paux);
        c_encolar(retorno, teAux);
    }
    c_intercambiar(cola, Caux);

    return retorno;
}
/*Ejercicio 3*/ //----------------------------------------------------------------------------------------
bool colas_iguales(Cola c1, Cola c2, int tamano_cola){
    bool bandera_igual = true;
    int contador_igual = 0, i = 0;
    TipoElemento x1;
    TipoElemento x2;
    TipoElemento x1_aux;
    TipoElemento x2_aux;
    //Creo una pilar auxiliar para acumular las claves que son iguales
    Cola c_aux = c_crear();
    //Recorro las pilas comparando sus claves

    while (bandera_igual && contador_igual != tamano_cola){
        x1 = c_desencolar(c1);
        x2 = c_desencolar(c2);
        if (x1->clave != x2->clave){
            //Si encuentra una desigualdad, cambia la bandera a false
            bandera_igual = false;
        } else {
            //Si encuentra una igualdad, la bandera mantiene su valor y y x1 y x2 se apila en la pila auxiliar
            c_encolar(c_aux, x1);
            c_encolar(c_aux, x2);
            contador_igual ++;
        }
    }
    //Si la desigualdad se encuentra en la primera comparacion
    if (c_es_vacia(c_aux) && !bandera_igual){   
        //Apila los valores desiguales a sus pilas originales
        while (!c_es_vacia(c1)) {
            x1_aux = c_desencolar(c1);
            c_encolar(c_aux, x1_aux);
            x2_aux = c_desencolar(c2);
            c_encolar(c_aux, x2_aux);
        }
        c_encolar(c1, x1);
        c_encolar(c2, x2);
        while (!c_es_vacia(c_aux)) {
            x1_aux = c_desencolar(c_aux);
            c_encolar(c1, x1_aux);
            x2_aux = c_desencolar(c_aux);
            c_encolar(c2, x2_aux);
        }
    }
    else if (!c_es_vacia(c_aux) && !bandera_igual && tamano_cola-1 != contador_igual) //Si la desigualdad se encuentra en la mitad del recorrido
    {
        //Reapila a su forma original
        while (!c_es_vacia(c1)) {
            x1_aux = c_desencolar(c1);
            c_encolar(c_aux, x1_aux);
            x2_aux = c_desencolar(c2);
            c_encolar(c_aux, x2_aux);
        }
        while (!c_es_vacia(c_aux)) {
            if (contador_igual == i){
                c_encolar(c1, x1);
                c_encolar(c2, x2);
            }
            else{
                x1_aux = c_desencolar(c_aux);
                c_encolar(c1, x1_aux);
                x2_aux = c_desencolar(c_aux);
                c_encolar(c2, x2_aux);
            }
            i++;
        }        
    }
    else if (!c_es_vacia(c_aux) && !bandera_igual && tamano_cola-1 == contador_igual) // Si la desigualdad esta en el ultimo elemento
    {
        while (!c_es_vacia(c_aux)) {
            x1_aux = c_desencolar(c_aux);
            c_encolar(c1, x1_aux);
            x2_aux = c_desencolar(c_aux);
            c_encolar(c2, x2_aux);
        }
        c_encolar(c1, x1);
        c_encolar(c2, x2);
    }
    
    else if (bandera_igual) //Si las pilas son iguales
    {
        //Reapila a su forma original
        while (!c_es_vacia(c_aux)){
            x1 = c_desencolar(c_aux);
            c_encolar(c1, x1);
            x2 = c_desencolar(c_aux);
            c_encolar(c2, x2);
        }
    }
    return bandera_igual;
}

/*Ejercicio 4*/ //----------------------------------------------------------------------------------------
Cola numerosSinRepetir(Cola cola){
    Cola c_sinNumRepetidos = c_crear();
    Cola cola_copia = c_crear();
    Cola c_aux = c_crear();
    Cola c_aux_copia = c_crear();

    TipoElemento x1, x2;

    bool enComun;
    int ocurrencias;

    while (!c_es_vacia(cola)){
        x1 = c_desencolar(cola);
        c_encolar(c_aux, x1);
        c_encolar(cola_copia, x1);
    }
    c_intercambiar(cola, c_aux); // Recupero la cola original.

    while (!c_es_vacia(cola)) {
        x1 = c_desencolar(cola);
        c_encolar(c_aux, x1);
        ocurrencias = 0;

        while (!c_es_vacia(cola_copia)) {
            x2 = c_desencolar(cola_copia);
            c_encolar(c_aux_copia, x2);
            if (x1->clave == x2->clave){
                ocurrencias ++;
            }
        }
        if (ocurrencias == 1){
            c_encolar(c_sinNumRepetidos, x1);
        }
        c_intercambiar(cola_copia, c_aux_copia);
    }
    c_intercambiar(cola, c_aux);

    return c_sinNumRepetidos;
}
/*Ejercicio 5*/ //----------------------------------------------------------------------------------------
Cola divisor_total_parcial(Cola colaP, int tamano){
    Cola cola_aux = c_crear();
    Cola cola_resultado = c_crear();
    TipoElemento numero_final;
    TipoElemento numero_principal;
    TipoElemento numero_a_dividir;
    
    int cont_max = 0;

    char *parcial;
    char *total;
    parcial = (char*)malloc(25);
    total = (char*)malloc(25);
    strcpy(parcial, "divisor parcial");
    strcpy(total, "divisor total");

    while (cont_max != tamano){
        //extraigo el primer numero de la cola principal
        numero_principal = c_desencolar(colaP);
        int cantidad_divisores = 1;
        int contador_tamano_division = 0;

        while (contador_tamano_division != (tamano - 1)) {
            //extraigo el siguiente numero a dividir
            numero_a_dividir = c_desencolar(colaP);
            if (numero_principal->clave != 0 && numero_a_dividir->clave != 0){
                if (numero_a_dividir->clave % numero_principal->clave  == 0) {
                    cantidad_divisores = cantidad_divisores + 1;
                }
            }
            contador_tamano_division = contador_tamano_division + 1;
            //coloco el numero en una cola auxiliar
            c_encolar(cola_aux, numero_a_dividir);   
        }
    
        if (cantidad_divisores == tamano) {
            //numero divisor total
            TipoElemento numero_final = te_crear_con_valor(numero_principal->clave, total);
            c_encolar(cola_resultado, numero_final);
        }

        if (tamano % 2 == 0){
            if (cantidad_divisores >= (tamano/2) && cantidad_divisores < tamano) {
                //numero divisor parcial
                TipoElemento numero_final = te_crear_con_valor(numero_principal->clave, parcial);
                c_encolar(cola_resultado, numero_final);
            }
        } else {
            if (cantidad_divisores >= (tamano/2)+1 && cantidad_divisores < tamano){

                //numero divisor parcial
                TipoElemento numero_final = te_crear_con_valor(numero_principal->clave, parcial);
                c_encolar(cola_resultado, numero_final);
            }
        }
        c_encolar(cola_aux, numero_principal);
        c_intercambiar(colaP, cola_aux);
        cont_max = cont_max + 1;
    }
    return cola_resultado;
}

/*Ejercicio 6*/ //----------------------------------------------------------------------------------------
Lista busca_Pila_Cola(Pila p,Cola c){
    char auxiliar[10];
    Lista lista_obtenida = l_crear();
    Pila paux = p_crear();
    Cola caux = c_crear();
    TipoElemento elementoP;
    TipoElemento elementoC;
    int posicionP, posicionC;
    int i = 0, y = 0;
    while (!p_es_vacia(p)) {
        elementoP = p_desapilar(p);
        p_apilar(paux, elementoP);
        while (!c_es_vacia(c)) {
            elementoC = c_desencolar(c);
            c_encolar(caux,elementoC);
            if (elementoP->clave == elementoC->clave){
                posicionP = i + 1;
                posicionC = y + 1;
                char* posiciones;
                posiciones = (char*)malloc(100);
                strcpy(posiciones,"(P'");
                sprintf(auxiliar,"%d",posicionP);
                strcat(posiciones,auxiliar); 
                strcat(posiciones,"', C'");
                sprintf(auxiliar,"%d",posicionC);
                strcat(posiciones, auxiliar);
                strcat(posiciones, "')");
                TipoElemento elementoL = te_crear_con_valor(elementoC->clave, posiciones);
                l_agregar(lista_obtenida, elementoL);
            }
            y++;
        }
        c_intercambiar(c, caux);
        i++;
        y = 0; // Reiniciamos el contador
    }
    p_intercambiar(p, paux);
    return lista_obtenida;
}

/*Ejercicio 7*/ //----------------------------------------------------------------------------------------
void mostrarClienteAtendido(int posicion, int contador, int cola){
    if (posicion < 10)
        printf("Posicion [%d]    ... [Cliente %d : Cola %d]\n", posicion, contador, cola);
    else if (posicion < 100)
        printf("Posicion [%d]   ... [Cliente %d : Cola %d]\n", posicion, contador, cola);
    else
        printf("Posicion [%d]  ... [Cliente %d : Cola %d]\n", posicion, contador, cola);
}
void atenderTresVentanillas (int cantidadMinutos, Cola c1, Cola c2, Cola c3) {
    Cola c1Aux = c_crear();
    Cola c2Aux = c_crear();
    Cola c3Aux = c_crear();
    Cola c1Aux_1 = c_crear();
    Cola c2Aux_2 = c_crear();
    Cola c3Aux_3 = c_crear();
    TipoElemento elem;
    TipoElemento te1;
    TipoElemento te2;
    TipoElemento te3;
    int cont1 = 1;
    int cont2 = 1;
    int cont3 = 1;
    int diferencia;
    int contador = 1;
    //Trabajamos con las colas para hacer una copia y no perder las originales.
    while (!c_es_vacia(c1)){
        elem = c_desencolar(c1);
        c_encolar(c1Aux, elem);
        c_encolar(c1Aux_1, elem);
    }
    c_intercambiar(c1, c1Aux_1); /*Recuperamos la original*/
    while (!c_es_vacia(c2)){
        elem = c_desencolar(c2);
        c_encolar(c2Aux, elem);
        c_encolar(c2Aux_2, elem);
    }
    c_intercambiar(c2, c2Aux_2); /*Recuperamos la original*/
    while (!c_es_vacia(c3)){
        elem = c_desencolar(c3);
        c_encolar(c3Aux, elem);
        c_encolar(c3Aux_3, elem);
    }
    c_intercambiar(c3, c3Aux_3); /*Recuperamos la original*/

    // Mientras alguna de las colas tenga elementos...
    while (!c_es_vacia(c1Aux)  || !c_es_vacia(c2Aux) || !c_es_vacia(c3Aux)) {
        //Analizamos la situacion de cada cola...
        if (!c_es_vacia(c1Aux)) {
            te1 = c_recuperar(c1Aux);
            if (te1->clave >= cantidadMinutos) {
                te1->clave -= cantidadMinutos;
                if (te1->clave == 0){
                    c_desencolar(c1Aux);
                    mostrarClienteAtendido(contador, cont1, 1);
                    contador++;
                    cont1++;
                }
            }
            else {
                diferencia = te1->clave - cantidadMinutos;
                if (c_longitud(c1Aux) == 1){
                    if (te1->clave <= cantidadMinutos){
                        c_desencolar(c1Aux); 
                        mostrarClienteAtendido(contador, cont1, 1);
                        contador++;
                        cont1++;
                    }
                    if (te1->clave > cantidadMinutos){
                        te1->clave = te1->clave - diferencia;
                    }
                }
                else{
                    do {
                        c_desencolar(c1Aux);
                        mostrarClienteAtendido(contador, cont1, 1);
                        contador++;
                        cont1++;
                        if (!c_es_vacia(c1Aux)){
                            te1 = c_recuperar(c1Aux);
                            te1->clave = te1->clave + diferencia;
                            if (te1->clave < 0) {
                                diferencia = te1->clave;
                            }
                            else if (te1->clave == 0) {
                                c_desencolar(c1Aux);
                                mostrarClienteAtendido(contador, cont1, 1);
                                contador++;
                                cont1++;
                            }
                        }
                    } while (!c_es_vacia(c1Aux) && diferencia == te1->clave);   
                }
            }
        }
        if (!c_es_vacia(c2Aux)) {
            te2 = c_recuperar(c2Aux);
            if (te2->clave >= cantidadMinutos) {
                te2->clave -= cantidadMinutos;
                if (te2->clave == 0){
                    c_desencolar(c2Aux);
                    mostrarClienteAtendido(contador, cont2, 2);
                    contador++;
                    cont2++;
                }
            }
            else {
                diferencia = te2->clave - cantidadMinutos;
                if (c_longitud(c2Aux) == 1){
                    if (te2->clave <= cantidadMinutos){
                        c_desencolar(c2Aux); 
                        mostrarClienteAtendido(contador, cont2, 2);
                        contador++;
                        cont2++;
                    }
                    if (te2->clave > cantidadMinutos){
                        te2->clave = te2->clave - diferencia;
                    }
                }
                else{
                    do {
                        c_desencolar(c2Aux);
                        mostrarClienteAtendido(contador, cont2, 2);
                        contador++;
                        cont2++;
                        if (!c_es_vacia(c2Aux)){
                            te2 = c_recuperar(c2Aux);
                            te2->clave = te2->clave + diferencia;
                            if (te2->clave < 0) {
                                diferencia = te2->clave;
                            }
                            else if (te2->clave == 0)
                            {
                                c_desencolar(c2Aux);
                                mostrarClienteAtendido(contador, cont2, 2);
                                contador++;
                                cont2++;
                            }
                        }
                    } while (!c_es_vacia(c2Aux) && diferencia == te2->clave);   
                }
            }
        }
        if (!c_es_vacia(c3Aux)) {
            te3 = c_recuperar(c3Aux);
            if (te3->clave >= cantidadMinutos) {
                te3->clave -= cantidadMinutos;
                if (te3->clave == 0){
                    c_desencolar(c3Aux);
                    mostrarClienteAtendido(contador, cont3, 3);
                    contador++;
                    cont3++;
                }
            }
            else {
                diferencia = te3->clave - cantidadMinutos;
                if (c_longitud(c3Aux) == 1){
                    if (te3->clave <= cantidadMinutos){
                        c_desencolar(c3Aux); 
                        mostrarClienteAtendido(contador, cont3, 3);
                        contador++;
                        cont3++;
                    }
                    if (te3->clave > cantidadMinutos){
                        te3->clave = te3->clave - diferencia;
                    }
                }
                else{
                    do {
                        c_desencolar(c3Aux);
                        mostrarClienteAtendido(contador, cont3, 3);
                        contador++;
                        cont3++;
                        if (!c_es_vacia(c3Aux)){
                            te3 = c_recuperar(c3Aux);
                            te3->clave = te3->clave + diferencia;
                            if (te3->clave < 0) {
                                diferencia = te3->clave;
                            }
                            else if (te3->clave == 0)
                            {
                                c_desencolar(c3Aux);
                                mostrarClienteAtendido(contador, cont3, 3);
                                contador++;
                                cont3++;
                            }
                        }
                    } while (!c_es_vacia(c3Aux) && diferencia == te3->clave);   
                }
            }
        }
    }
}