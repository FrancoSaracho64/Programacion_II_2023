#include "funcionesEjercicios.h"
int NRO_PRIMO = 0;
int funcionHash(int numero){
    return (numero % NRO_PRIMO);
}

int main(){
    //Presentacion
    system("cls");
    printf("***Ejercicio 5***\n");
    printf("Comparacion de tiempos/rendimiento...\n\n"); 
    //Inicializaciones importantes
    int cantidadClaves, maximo, minimo, repeticiones, cantidadClavesAleatorias;
    bool entrada; 
    char num[TAMANO_NUM];
    TipoElemento elemento, elementoBuscado;
    
    do{
        do{
            printf("Ingrese la cantidad de claves a generar/cargar: ");
            fflush(stdin);
            fgets(num, TAMANO_NUM, stdin);
            entrada = numEnteros(num) && validarEnter(num);
        } while (!entrada);
        cantidadClaves = pasaje_String_A_int(num);  
        entrada = numeroRango(cantidadClaves, 1, 2000);
    } while (!entrada);
    //Extraigo el NUM_PRIMO menor a la cantidad
    NRO_PRIMO = encontrarPrimoMasCercano(cantidadClaves);
    do{
        do{
            printf("\nIngrese la cantidad de veces que quiere repetir la operacion: ");
            fflush(stdin);
            fgets(num, TAMANO_NUM, stdin);
            entrada = numEnteros(num) && validarEnter(num);
        } while (!entrada);
        repeticiones = pasaje_String_A_int(num);  
        entrada = numeroRango(repeticiones, 1, 10000);
    } while (!entrada);
    do{
        do{
            printf("\nIngrese el valor MINIMO de las claves a generar/cargar: ");
            fflush(stdin);
            fgets(num, TAMANO_NUM, stdin);
            entrada = numEnteros(num) && validarEnter(num);
        } while (!entrada);
        minimo = pasaje_String_A_int(num);
        entrada = numeroRango(minimo, 0, 1000);
    } while (!entrada);  
    do{
        do{
            printf("\nIngrese el valor MAXIMO de las claves a generar/cargar: ");
            fflush(stdin);
            fgets(num, TAMANO_NUM, stdin);
            entrada = numEnteros(num) && validarEnter(num);
        } while (!entrada);
        maximo = pasaje_String_A_int(num);  
        entrada = numeroRango(maximo, minimo, 10000);
    } while (!entrada); 
    printf("\n");
    //Creo las estructuras
    ArbolAVL    arbol_avl   =   avl_crear();
    TablaHash   tabla_hash;          
    tabla_hash = th_crear(cantidadClaves, &funcionHash);

    srand(time(NULL));
    for (int i1 = 0; i1 < cantidadClaves; i1++){
        int numAle = minimo + rand() % maximo;
        TipoElemento elemento = te_crear(numAle);
        th_insertar(tabla_hash, elemento);
        avl_insertar(arbol_avl, elemento);
    }
    printf("\n********\nLas estructuras se cargaron correctamente.\n********\n\n");
    
    do{
        do{
            printf("Ingrese la cantidad de claves a buscar de forma aleatoria: ");
            fflush(stdin);
            fgets(num, TAMANO_NUM, stdin);
            entrada = numEnteros(num) && validarEnter(num);
        } while (!entrada);
        cantidadClavesAleatorias = pasaje_String_A_int(num);  
        entrada = numeroRango(cantidadClavesAleatorias, 1, 2000);
    } while (!entrada);

    printf("\n\nHaciendo las busquedas...\n");      
    //////////////////////////////////////////////////////////
    struct timeval inicio_avl, final_avl;
    struct timeval inicio_tabla, final_tabla;

    double tiempoTOTAL__AVL   = 0;
    double tiempoTOTAL__TABLA = 0;

    for (int i = 0; i < repeticiones; i++){
        //Busqueda dentro de un AVL
        gettimeofday(&inicio_avl, 0);
        for (int x = 0; x < cantidadClavesAleatorias; x++){
            int aleatorio = (rand() % (maximo + 1 - minimo)) + minimo; 
            elemento = avl_buscar(arbol_avl, aleatorio);
        }
        gettimeofday(&final_avl, 0);
        long int seconds = final_avl.tv_sec - inicio_avl.tv_sec;
        long int microseconds = final_avl.tv_usec - inicio_avl.tv_usec;
        double tiempoTotal_avl = (double)(seconds + microseconds*1e-6);
        printf("\nPasada: %d\n", i+1);
        printf("Tiempo transcurrido de las busquedas (Arbol AVL): %f segundos.\n", tiempoTotal_avl);
        tiempoTOTAL__AVL = tiempoTOTAL__AVL + tiempoTotal_avl;
    }
    for (int i = 0; i < repeticiones; i++){
        //Busqueda dentro de una TABLA HASH
        gettimeofday(&inicio_tabla, 0);
        for (int z = 0; z < cantidadClavesAleatorias; z++){
            int aleatorio2 = (rand() % (maximo + 1 - minimo)) + minimo; 
            elemento = th_recuperar(tabla_hash, aleatorio2);
        }
        gettimeofday(&final_tabla, 0);
        long int seconds1 = final_tabla.tv_sec - inicio_tabla.tv_sec;
        long int microseconds1 = final_tabla.tv_usec - inicio_tabla.tv_usec;
        double tiempoTotal_tabla = (double)(seconds1 + microseconds1*1e-6);
        printf("\nPasada: %d\n", i+1);
        printf("Tiempo transcurrido de las busquedas (TablaHash): %f segundos.\n", tiempoTotal_tabla);
        tiempoTOTAL__TABLA = tiempoTOTAL__TABLA + tiempoTotal_tabla;
    }
    printf("\n\nBusquedas finalizadas...");  

    //Calculo la diferencia de los tiempos... y hago una conclusion
    printf("\n\nTiempo transcurrido de las busquedas (Arbol AVL): %f segundos.\n", tiempoTOTAL__AVL);
    printf("Tiempo transcurrido de las busquedas (TablaHash): %f segundos.\n", tiempoTOTAL__TABLA);

    printf("\n\n\n               *** Conclusiones: ***\n");
    printf("CASO (1)... Implementando --- tabla_hash_lista_colisiones.c---\nAl medir el tiempo de ejecucion con esta implementacion, notamos que las busquedas con la\nTABLA HASH son mas rapidas que las busquedas dentro de un Arbol AVL.\nLa diferencia no suele ser mucha. Generalmente es menos de un segundo.\n\n");
    printf("CASO (2)... Implementando --- tabla_hash_zona_overflow.c\nAl medir el tiempo de ejecucion con esta implementacion, quedamos muy sorprendidos al ver\nque la busqueda dentro de un Arbol AVL fue muchisimo mas rapida que la busqueda dentro de\nuna TABLA HASH.\nLa diferencia puede ser mucha, y estamos hablando de segundos.\n\n");
    fflush(stdin);
    printf("\n\nPresione ENTER para salir...");
    getchar();
}