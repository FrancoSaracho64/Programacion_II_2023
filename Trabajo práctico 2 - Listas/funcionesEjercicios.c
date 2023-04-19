#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "funcionesEjercicios.h"
#include "Validaciones.h"

/*Ejercicio 1*/
// TAD de listas

/*Ejercicio 2*/
void menu(){
    printf("                Menu principal\n\n");
    printf(" 1.  Mostrar el dato menor de la lista y su posicion ordinal\n");
    printf(" 2.  Mostrar el dato mayor y las veces que aparece en la lista\n");
    printf(" 3.  Calcular el promedio de los elementos de una lista\n");
    printf(" 4.  Mostrar multiplos de un numero de una lista.\n\n");
    printf(" 0.  Finalizar ejecucion...\n\n");
    printf("INGRESE UNA OPCION: ");
}
//a. Que calcule el menor de los datos e indique la posición ordinal. 
void posicionDatoMenor(Lista List){
    // Inicializaciones
    int numMaximo = 0, posicion = 1, posiOrdinalMenor = 0;
    TipoElemento num = te_crear(0);
    Iterador iter = iterador(List);

    while (hay_siguiente(iter)){
        if (posicion == 1) {
            num = siguiente(iter);
            numMaximo = num->clave;
            posiOrdinalMenor = posicion;
            ++posicion;
        }
        else {    
            num = siguiente(iter);
            if (num->clave < numMaximo){
                numMaximo = num->clave;
                posiOrdinalMenor = posicion;
            }
            ++posicion;
        }
    }
    printf("El numero mas chico dentro de la lista es: %d\n", numMaximo);
    printf("Su posicion Ordinal es: %d", posiOrdinalMenor);
    return;
}
//b. Que calcule el dato máximo y cuente la cantidad de veces que se repite. 
void datoMaximoVeces(Lista List){
    // Inicializaciones
    int vecesRep = 0;    
    int numMaximo = 0, posicion = 1;
    TipoElemento num = te_crear(0);
    Iterador iter = iterador(List);
    while (hay_siguiente(iter)){
        if (posicion == 1) {
            num = siguiente(iter);
            numMaximo = num->clave;
            vecesRep = 1;
            ++posicion;
        }
        else {    
            num = siguiente(iter);
            if (num->clave > numMaximo){
                numMaximo = num->clave;
                vecesRep = 1;
            }
            else if (num->clave == numMaximo) vecesRep++;
        }
    }
    printf("El numero mas grande dentro de la lista es: %d\n", numMaximo);
    printf("La cantidad de veces que aparece es: %d", vecesRep);
    return;
}
//c. Que obtenga el promedio de los datos de una lista. El proceso debe ser recursivo.
float promedio(Lista list, int cont, float resultado){
    // Caso recursivo
    if (cont <= l_longitud(list)){
        TipoElemento elem = l_recuperar(list, cont);
        resultado = resultado + elem->clave;
        return promedio(list, cont + 1, resultado);
    }
    else{
        // Caso base
        return resultado/l_longitud(list);
    }
}
//d. Que retorne otra lista con los números múltiplos de otro número que recibe como parámetro.
Lista MultiplosDe(Lista lista, int numero){

    TipoElemento x = te_crear(0);
    Lista ListMultiplo = l_crear();
    Iterador itera = iterador(lista);
    // Ahora la recorro

    while (hay_siguiente(itera)) {
        x = siguiente(itera);
        if ((x->clave % numero) == 0) {
            l_agregar(ListMultiplo, x);
        }
    }
    return ListMultiplo;
}
// Funcion que se encarga de cargar la lista en cada caso.
void cargarLista(Lista List){
    bool entrada = true;
    char num[TAMANO_NUM];
    int i = 0, opcion, numero, tamanio_lista;
    TipoElemento elemento = te_crear(0);

    do{
        do{
            printf("¿Como quiere cargar la lista?\n1. Manualmente\n2. Aleatoriamente\n\n");
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
                    tamanio_lista = pasaje_String_A_int(num);  
                    entrada = numeroRango(tamanio_lista,1,100);
                } while (!entrada);

                while (l_longitud(List) < tamanio_lista){
                    do{
                        printf("Ingrese el elemento de posicion [%d]: ", i + 1);
                        fflush(stdin);
                        fgets(num, TAMANO_NUM, stdin);
                        entrada = numEnteros(num) && validarEnter(num);
                    } while (!entrada);
                    i++;
                    numero = pasaje_String_A_int(num);
                    elemento = te_crear(numero);
                    l_agregar(List, elemento);
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
                    tamanio_lista = pasaje_String_A_int(num);  
                    entrada = numeroRango(tamanio_lista,1,100);
                } while (!entrada);

                while (l_longitud(List) < tamanio_lista) {
                    numero = rand() % 1000;
                    elemento = te_crear(numero);
                    l_agregar(List, elemento);
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

/*Ejercicio 3*/
bool multiplo_listas(Lista L1, Lista L2)
{
    Iterador i1 = iterador(L1);
    Iterador i2 = iterador(L2);
    TipoElemento elemento1 = te_crear(0);
    TipoElemento elemento2 = te_crear(0);
    bool es_multiplo = true;
    int contador = 1;
    
    // Recorremos ambas listas al mismo tiempo
    while (hay_siguiente(i2) && hay_siguiente(i1) && es_multiplo)
    {
        int n2 = l_recuperar(L2, contador)->clave ;
        int n1 = l_recuperar(L1, contador)->clave;
        
        /*Calculamos si el resto de la division de ambos valores de la lista es 0
        // Division da resto "0", es multiplo
        // Division da distinto a resto "0", no es multiplo */
        
        if ( (n2 % n1) != 0)
        {
            //si existe una division la cual no da resto "0", L2 ya no seria multiplo de L1, entonces el ciclo para
            es_multiplo = false;
        }
        contador = contador + 1;
        elemento1 = siguiente(i1);
        elemento2 = siguiente(i2);
    }
    return es_multiplo;
}

int escalar_multiplo(Lista L1, Lista L2)
{
    Iterador iterador1 = iterador(L1);
    Iterador iterador2 = iterador(L2);
    TipoElemento element1 = te_crear(0);
    TipoElemento element2 = te_crear(0);
    bool es_escalador = true;
    int contador = 1;
    int numero_escalador = 0;
    int numero_escalador_ant = 0;
    
    //Comparamos los valores de las listas
    while (hay_siguiente(iterador2) && hay_siguiente(iterador1) && es_escalador)
    {
        numero_escalador = l_recuperar(L2, contador)->clave / l_recuperar(L1, contador)->clave;
        if (contador == 1)
        {
            numero_escalador_ant = numero_escalador;
        }
        //Si un divisor anterior coincide con el siguiente, no existe un numero escalar y se detiene el ciclo
        if (numero_escalador != numero_escalador_ant)
        {
            es_escalador = false;
            numero_escalador = 0;
        }
        contador = contador + 1;
        element1 = siguiente(iterador1);
        element2 = siguiente(iterador2);

    }
    return numero_escalador;
}

/*Ejercicio 4*/
void CompararL1L2(Lista ListaN1, Lista ListaN2 ){
        int l1Mayor =0,igual = 0,l1Menor =0,contador =1;
         Iterador iterador1 = iterador(ListaN1);
         Iterador iterador2 = iterador(ListaN2);
        while (hay_siguiente(iterador1) && hay_siguiente(iterador2) && contador <= (l_longitud(ListaN1))){
            if (l_recuperar(ListaN1,contador)->clave > l_recuperar(ListaN2,contador)->clave){
                ++l1Mayor;
            } else if (l_recuperar(ListaN1,contador)->clave == l_recuperar(ListaN2,contador)->clave){
                ++igual;
            }else{
                ++l1Menor;
            }
            ++contador;
        }
        
    if ((l1Mayor > l1Menor ) && (l1Mayor > igual)){
        printf("       La primera lista es MAYOR.\n");
    }else if (l1Menor > igual){
        printf("       La primera lista es MENOR.\n");
    }else{
        printf("       Las listas son IGUALES.\n");
    }
}
/* complejidad algoritmica es de O(n^2)*/

/*Ejercicio 5*/
//CALCULAR LA ECUACION PARA UN VALOR DE X
double CalculoValorDeX (double valorX, Lista l) {
    
    double sumaTerminos = 0;
    double termino;

    TipoElemento coeficienteLista;
    Iterador ite;
    int grado = 0;

    ite = iterador(l);
    while (hay_siguiente(ite)) {
        
        coeficienteLista = siguiente(ite);
        double * doublePtr = (double*) coeficienteLista->valor;
        double valor = *doublePtr;
        termino = valor * pow(valorX, grado);
        grado++;
        sumaTerminos += termino;
    }    
    return sumaTerminos;
}

//CALCULAR VALOR DE X PARA UN RANGO DE NUMEROS
Lista CalculoRango (double valor1, double valor2, Lista l) {   
    Lista Auxiliar;
    double calculoAuxiliar;
    int claveAuxiliar = 0;
    double calculoTamanio = ((valor2/0.5)-(valor1/0.5)) + 1;
    double * arregloAux = malloc(sizeof(double)*calculoTamanio);

    do {
        calculoAuxiliar = CalculoValorDeX(valor1, l);

        //agregar calculo auxiliar a arregloAux
        arregloAux[claveAuxiliar] = calculoAuxiliar;
        
        valor1 += 0.5;
        claveAuxiliar++;

    } while (valor1 <= valor2);
  
    Auxiliar = PasarALista(arregloAux, (int)calculoTamanio);

    return Auxiliar; 
}

//ARMAR LA LISTA DE RESULTADOS A DEVOLVER
Lista PasarALista(double * arr, int t) {
    Lista Auxiliar;
    Auxiliar = l_crear();
    TipoElemento CargaAuxiliar;
    for (int i = 0; i < t; i++) {
        void * cargaVoidAux = &arr[i];
        CargaAuxiliar = te_crear_con_valor(i, cargaVoidAux);
        l_agregar(Auxiliar, CargaAuxiliar);
    }
    return Auxiliar;
}

/*Ejercicio 6*/
// La funcion tiene dos listas vinculadas como input y retorna un boolean para indicar si L2 es o no sublista de L1. Utiliza 2 iteradores.
// Por cada elemento de lista1, busca en lista2 para encontrar uno igual. Si encuentra, entra a otro ciclo while que itera en paralelo las listas,
// hasta que encuentra una diferencia o llega al final de lista2.

bool es_sublista(Lista lista1, Lista lista2) {
    // Inicio iteradores.
    Iterador iter1 = iterador(lista1);
    Iterador iter2;

    // Si ambas están vacías, entonces lista2 es sublista de lista1.
    if (l_longitud(lista1) == 0 && l_longitud(lista2) == 0) {
        return true;
    }

    // Itero los elementos de la lista1.
    while (hay_siguiente(iter1)) {
        // Agarro el siguiente elemento de lista1.
        TipoElemento elemento1 = siguiente(iter1);

        // Itero los elementos de lista2 para encontrar el primero que coincida con elemento1.
        iter2 = iterador(lista2);
        while (hay_siguiente(iter2)) {
            TipoElemento elemento2 = siguiente(iter2);
            if (elemento1->clave == elemento2->clave) {
                // Si encuentro una coincidencia, sigo iterando ambas listas en paralelo hasta que encuentro una diferencia o hasta que llegue al final.
                TipoElemento elementoActual1 = elemento1;
                TipoElemento elementoActual2 = elemento2;
                while (elementoActual2 != NULL && elementoActual1 != NULL && elementoActual1->clave == elementoActual2->clave) {
                    elementoActual2 = hay_siguiente(iter2) ? siguiente(iter2) : NULL;
                    elementoActual1 = hay_siguiente(iter1) ? siguiente(iter1) : NULL;
                }
                // Si llego al final de lista2 entonces es sublista.
                if (elementoActual2 == NULL) {
                    return true;
                }
            }
        }
    }
    // Si recorrí toda la lista1 y no encontré coincidencias, no es sublista.
    return false;
}