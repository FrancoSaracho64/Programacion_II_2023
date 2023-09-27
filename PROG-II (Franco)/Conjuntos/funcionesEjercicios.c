#include "funcionesEjercicios.h"
//Ejercicio2-----------------------------------------------------------------------------------
void menuEj2(Conjunto cto_1, Conjunto cto_2){
    bool entrada, pert1, pert2;
    char num[TAMANO_NUM];
    int opcion = 0, numero = 0;
    //Creamos el conjunto resultado.
    Conjunto resultado = cto_crear();

    do {
        system("cls");
        do {
            printf("\n\n\tOPERACIONES con conjuntos...\n1. Union\n2. Interseccion\n3. Diferencia\n4. Pertenencia\n5. Mostrar los conjuntos cargados previamente.\n\n0. Salir...\n\nOPCION ---> ");
            fflush(stdin);
            fgets(num, TAMANO_NUM, stdin);
            entrada = numEnteros(num) && validarEnter(num);
        } while (!entrada);
        opcion = pasaje_String_A_int(num);  
        printf("\n");

        switch (opcion) {
            case 1: // Union
                resultado = cto_union(cto_1, cto_2);
                printf("Conjunto resultante de la UNION del conjunto A y B...\n");
                cto_mostrar(resultado);
                printf("\n\nPresione ENTER para volver al menu de operaciones...");
                getchar();
                break;
            case 2: // Interseccion
                resultado = cto_interseccion(cto_1, cto_2);
                printf("Conjunto resultante de la INTERSECCION del conjunto A y B...\n");
                cto_mostrar(resultado);
                printf("\n\nPresione ENTER para volver al menu de operaciones...");
                getchar();
                break;
            case 3: // Diferencia
                resultado = cto_diferencia(cto_1, cto_2);
                printf("Conjunto resultante de la DIFERENCIA del conjunto A y B...\n");
                cto_mostrar(resultado);
                printf("\n\n\nPresione ENTER para volver al menu de operaciones...");
                getchar();
                break;
            case 4: // Pertenencia
                do{
                    printf("Ingrese el numero que quiere buscar ---> ");
                    fflush(stdin);
                    fgets(num, TAMANO_NUM, stdin);
                    entrada = numEnteros(num) && validarEnter(num);
                } while (!entrada);
                numero = pasaje_String_A_int(num);
                
                if (!cto_es_vacio(cto_1)) pert1 = cto_pertenece(cto_1, numero);
                else pert1 = false;
                if (!cto_es_vacio(cto_2)) pert2 = cto_pertenece(cto_2, numero);
                else pert2 = false;

                if (pert1 && pert2) printf("\n\nEl numero ingresado se encuentra en ambos conjuntos.");
                else if (pert1) printf("\n\nEl numero ingresado se encuentra en el conjunto <A>.");
                else if (pert2) printf("\n\nEl numero ingresado se encuentra en el conjunto <B>.");
                else printf("\n\nEl numero ingresado no se encuentra en ningun conjunto.");
                
                printf("\n\nPresione ENTER para volver al menu de operaciones...");
                getchar();
                break;
            case 5:
                printf("\nConjunto <A>:\n");
                cto_mostrar(cto_1);
                printf("\n\nConjunto <B>:\n");
                cto_mostrar(cto_2);
                printf("\n\nPresione ENTER para volver al menu de operaciones...");
                getchar();
            case 0:
                printf("\nSaliendo...\n");
                break;
            default:
                printf("\nHa introducido una opcion invalida. Vuelva a intentar...\n");
                break;
            }
    } while (opcion != 0);
}

//Ejercicio3-----------------------------------------------------------------------------------
void menuEj3(Lista lista_conjuntos){
    bool entrada, pert1, pert2;
    char num[TAMANO_NUM];
    int opcion = 0, numero = 0;
    int contador;
    int cantCtos = l_longitud(lista_conjuntos);
    TipoElemento elemento;
    Conjunto con1;
    Conjunto resultado;
    Iterador iter;
    
    do {
        system("cls");
        do {
            printf("\n\n\tOPERACIONES con conjuntos...\n1. Union\n2. Interseccion\n3. Mostrar los conjuntos cargados previamente.\n\n0. Salir...\n\nOPCION ---> ");
            fflush(stdin);
            fgets(num, TAMANO_NUM, stdin);
            entrada = numEnteros(num) && validarEnter(num);
        } while (!entrada);
        opcion = pasaje_String_A_int(num);  
        printf("\n");

        contador = 1;

        switch (opcion) {
            case 1: // Union
                while (contador <= cantCtos) {
                    //Caso para cuando es el primer elemento-
                    if (contador == 1){
                        elemento = l_buscar(lista_conjuntos, contador);
                        resultado = (Conjunto)elemento->valor;
                        contador++;
                    } 
                    //Caso para otro elemento distinto al primero.
                    else {
                        elemento = l_buscar(lista_conjuntos, contador);
                        con1 = (Conjunto)elemento->valor;
                        resultado = cto_union(resultado, con1);
                        contador++;
                    }
                }
                printf("Conjunto resultante de la UNION de los conjuntos...\n");
                cto_mostrar(resultado);
                printf("\n\nPresione ENTER para volver al menu de operaciones...");
                getchar();
                break;
            case 2: // Interseccion
                while (contador <= cantCtos) {
                    //Caso para cuando es el primer elemento-
                    if (contador == 1){
                        elemento = l_buscar(lista_conjuntos, contador);
                        resultado = (Conjunto)elemento->valor;
                        contador++;
                    } 
                    //Caso para otro elemento distinto al primero.
                    else {
                        elemento = l_buscar(lista_conjuntos, contador);
                        con1 = (Conjunto)elemento->valor;
                        resultado = cto_interseccion(resultado, con1);
                        contador++;
                    }
                }

                printf("Conjunto resultante de la INTERSECCION de los conjuntos...\n");
                cto_mostrar(resultado);
                printf("\n\nPresione ENTER para volver al menu de operaciones...");
                getchar();
                break;
            case 3: // Mostrar todos los conjuntos cargados
                iter = iterador(lista_conjuntos);
                while (hay_siguiente(iter)) {
                    elemento = siguiente(iter);
                    resultado = (Conjunto) elemento->valor;
                    printf("\nConjunto %d:\n", contador);
                    cto_mostrar(resultado);
                    printf("-------------------\n");
                    contador ++;
                }
                
                printf("\n\nPresione ENTER para volver al menu de operaciones...");
                getchar();
            case 0:
                printf("\nSaliendo...\n");
                break;
            default:
                printf("\nHa introducido una opcion invalida. Vuelva a intentar...\n");
                break;
            }
    } while (opcion != 0);
}

//Ejercicio4-----------------------------------------------------------------------------------
//Devuelve true si el conjunto a es subconjunto de b
bool EsSubconjunto (Conjunto a, Conjunto b) {
    Conjunto aux;
    aux = cto_diferencia(a, b);
    return cto_es_vacio(aux);
}

void Transitividad3Conjuntos (Conjunto a, Conjunto b, Conjunto c) {
    bool primer = EsSubconjunto(a, b);
    bool segund = EsSubconjunto(b, c);
    bool resultado = primer && segund;

    if (resultado) {
        printf("El conjunto A es subconjunto de B y B es subconjunto de C.\nAplicando la transitividad deducimos que A es subconjunto de C.");
    }
    else if (primer && !segund) {
        printf("El conjunto A <NO> es subconjunto de C debido a que el conjunto B <NO> es subconjunto de C.");
    } else if (!primer && segund) {
        printf("El conjunto A <NO> es subconjunto de C debido a que el conjunto A <NO> es subconjunto de B.");
    }
    else {
        printf("El conjunto A <NO> es subconjunto de C debido a que A <NO> es subconjunto de B y B tampoco es subconjunto de C.");
    }
    return;
}

//Ejercicio5-----------------------------------------------------------------------------------
Conjunto diferenciaSimetrica (Conjunto cto_a, Conjunto cto_b) {
    Conjunto unionAB;
    Conjunto interseccionAB;
    Conjunto retorno;

    unionAB = cto_union(cto_a, cto_b);
    interseccionAB = cto_interseccion (cto_a, cto_b);

    retorno = cto_diferencia(unionAB, interseccionAB);

    return retorno;
}

//Ejercicio6-----------------------------------------------------------------------------------
 // -----
//Ejercicio7-----------------------------------------------------------------------------------
    //Devuelve <2> si A es subconjunto TOTAL de B
    //         <1> si A es subconjunto PARCIAL de B
    //         <0> si A NO es subconjunto de B

int SubconjuntoParcialOTotal (Conjunto a, Conjunto b) {
    Conjunto aux;
    int mitadElementos = cto_cantidad_elementos(a) / 2; 
    int cantidadSubconjunto;                            

    aux = cto_diferencia(a, b);                         
    
    cantidadSubconjunto = cto_cantidad_elementos(aux);  

    if (cantidadSubconjunto == 0) return 2;             
    else if (cantidadSubconjunto <= mitadElementos) return 1;
    else return 0;

}

void SubconjuntoParcial3Conjuntos (Conjunto a, Conjunto b, Conjunto c) {
    switch (SubconjuntoParcialOTotal(a, b)) {
    case 1:
        printf ("-> El conjunto <A> es subconjunto PARCIAL de B\n");
        break;
    case 2:
        printf ("-> El conjunto <A> es subconjunto TOTAL de B\n");
        break;
    default:
        break;
    }

    switch (SubconjuntoParcialOTotal(b, a)) {
    case 1:
        printf ("-> El conjunto <B> es subconjunto PARCIAL de A\n");
        break;
    case 2:
        printf ("-> El conjunto <B> es subconjunto TOTAL de A\n");
        break;
    default:
        break;
    }

    switch (SubconjuntoParcialOTotal(a, c)) {
    case 1:
        printf ("-> El conjunto <A> es subconjunto PARCIAL de C\n");
        break;
    case 2:
        printf ("-> El conjunto <A> es subconjunto TOTAL de C\n");
        break;
    default:
        break;
    }

    switch (SubconjuntoParcialOTotal(c, a)) {
    case 1:
        printf ("-> El conjunto <C> es subconjunto PARCIAL de A\n");
        break;
    case 2:
        printf ("-> El conjunto <C> es subconjunto TOTAL de A\n");
        break;
    default:
        break;
    }

    switch (SubconjuntoParcialOTotal(b, c)) {
    case 1:
        printf ("-> El conjunto <B> es subconjunto PARCIAL de C\n");
        break;
    case 2:
        printf ("-> El conjunto <B> es subconjunto TOTAL de C\n");
        break;
    default:
        break;
    }

    switch (SubconjuntoParcialOTotal(c, b)) {
    case 1:
        printf ("-> El conjunto <C> es subconjunto PARCIAL de B\n");
        break;
    case 2:
        printf ("-> El conjunto <C> es subconjunto TOTAL de B\n");
        break;
    default:
        break;
    }
}
//Ejercicio8-----------------------------------------------------------------------------------
bool conjuntosIguales(Conjunto conjA, Conjunto conjB){
    bool iguales = true;
    int contador = 1;

    int cantA = cto_cantidad_elementos(conjA);

    TipoElemento elemento;
    while (iguales && contador <= cantA) {
        elemento = cto_recuperar(conjA, contador);
        iguales = cto_pertenece(conjB, elemento->clave);
        contador++;
    }
    return iguales;
}