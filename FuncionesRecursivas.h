/* ######################################################################################################################### */
/* IMPORTACIONES de C*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Declaraciones de funciones */
/* Ejercicio 1*/
bool palindromo(char[], int, int);
/* Ejercicio 2*/
int producto_de_dos_numeros(int, int);
/* Ejercicio 3*/
int fibonacci(int);
/* Ejercicio 4*/
float division_restasSucesivas(int, int, int *);
/* Ejercicio 5*/
char *PuntosDeMil (char *);
/* Ejercicio 6*/
char *reunionChinos (int);
/* Ejercicio 7*/
char *grafico_senales_inicializador(char[], char);
char *graficoSenales(char[], char, int *, char *);
/* Ejercicio 8*/
//----
/* Ejercicio 9*/
bool divisiblePor7(int);
/* Ejercicio 10*/
int *Explosion (int, int, int *);

/* ######################################################################################################################### */
/* Ejercicio 1 */

/* La funcion se encarga de analizar si un String recibido por parametro es o no del tipo 'palindromo', es decir, una palabra/frase
que puede leerse de izquierda a derecha y de derecha a izquierda. 
En caso de que lo recibido sea un palindromo, se retornara TRUE, caso contrario, FALSE.*/

bool palindromo(char palabra[], int primero, int ultimo) {
    /* CASO BASE 
    Si se llega a este punto, es porque todos los caracteres analizados anteriormente son iguales. Esto nos da a saber
    que la palabra ES un palindromo, por lo que retornamos el valor TRUE. */
    if (primero > ultimo) {
        return true;
    }
    /* CASO RECURSIVO */
    else {
        /* Si nos encontramos con caracteres que son distintos, lo recibido por parametro NO corresponde a un palindromo,
        por lo que automaticamente retornamos un FALSE */
        if (palabra[primero] != palabra[ultimo]) {
            return false;
        }
        else{
            /* Si se encontro una igualdad de caracteres, vamos con el siguiente, incrementando en 1 el "primero" y decrementando
            en 1 el ultimo */
            return palindromo(palabra, primero + 1, ultimo - 1);
        }
    }
}
/* ######################################################################################################################### */
/* Ejercicio 2 */
//Funcion que calcula la multiplicacion de dos numeros mediante sumas sucesivas.

int producto_de_dos_numeros(int multiplicando, int multiplicador){
    // CASO BASE
    // Si el multiplicador llega a 0, retornamos el 0.
    if (multiplicador == 0) {
        return 0;
    } 
    // CASO RECURSIVO
    //Si el multiplicador es negativo, llamamos a la recursiva incrementando el multiplicador, para que llegue hasta 0.
    //Ademas, negamos el valor del multiplicando.
    else if (multiplicador < 0) {
        return (-multiplicando) + producto_de_dos_numeros(multiplicando, ++multiplicador);
    } else {
    //Si el multiplicador es positivo, llamamos a la recursiva decrementando el multiplicador, para que llegue hasta 0.
        return multiplicando + producto_de_dos_numeros(multiplicando, --multiplicador);
    }
}
/* ######################################################################################################################### */
/* Ejercicio 3 */
// Funcion que calcula la sucesion de Fibonnaci dado un numero que se recibe por parametro.

int fibonacci(int numero){
    //CASO BASE
    if (numero <= 1){
        return numero;
    } 
    //CASO RECURSIVO
    else {
        //Llamamos ala funcion recursiva aplicando el concepto/formula de la sucesion.
        return fibonacci(numero-1) + fibonacci(numero - 2);
    }
}
/* ######################################################################################################################### */
/* Ejercicio 4 */
float division_restasSucesivas(int dividiendo, int divisor, int *veces){
    /* CASO BASE :
        cuando 'dividiendo' es igual a 0, la division es entera 
        y cuando 'veces' es igual a 0 ya se obtienen los 4 decimales  */
    if (dividiendo == 0 || (*veces == 0)){
        return 0;
    }

    /* CASOS RECURSIVOS */
    else if ((dividiendo < 0) && (divisor < 0)) {
    /*  En este caso si el divisor y el dividiendo son negativos el resultado es positivo, entonces
        se les cambia el signo a positivo ya que la regla de los signos lo permite  (- * - = + )*/
        dividiendo = - dividiendo;   // Cambian de negativo a positivo 
        divisor = - divisor;       
        return division_restasSucesivas(dividiendo, divisor, veces);
    }

    else if (dividiendo < 0) {
    /* En este caso solamente se trata cuando el dividiendo es negativo. 
        La funcion 'division_restasSucesivas' recibe a dividiendo transformado a positivo 
        y la funcion se niega  */
    
        return - division_restasSucesivas(- dividiendo, divisor, veces);
    }
    else if (divisor < 0) {
        /* Se realiza exactamente lo mismo que el caso anterior solamente
            que en este caso es sobre el divisor*/
        return - division_restasSucesivas(dividiendo, - divisor, veces);
    }
    else if ((dividiendo < divisor) && (*veces != 0)) {
        /* Al cumplir esta condicion se comenzara a calcular la parte decimal */
    
        int resto = dividiendo * 10;    // Multiplicamos x 10 el resto     
        *veces = *veces - 1;            // restamos a veces 1, antes de llamar la funcion porque no es posible restarlo en otro momento 
        return (division_restasSucesivas(resto, divisor, veces)) / 10; // dividimos por 10 el resultado para mover hacia la izquierda la coma un lugar
    }
    else{
        /* Suma 1 por cada vuelta que realiza y llama la funcion para realizar la resta entre 'dividiendo' y 'divisor' */
        return 1 + division_restasSucesivas(dividiendo - divisor, divisor, veces); 
    }
}
/* ######################################################################################################################### */
/* Ejercicio 5 */

//FUNCION RECURSIVA
    /*
    Funcionamiento: La idea de la funcion es insertar un punto (".") en la cadena antes de los 3 ultimos digitos del numero ingresado.
    Ej: 1234567 -> 1234.567 // De ese numero, tomaremos la seccion que esta a la izquierda del punto (1234) y reinvocaremos la funcion con 
    este numero truncado como parametro. El proceso se repetirá hasta que el numero a la izquierda del punto tenga 3 digitos o menos (CASO
    BASE), siendo que ya no se deberían agregar mas puntos. Se retornan todos los valores, concatenandose sucesivamente las cadenas hasta 
    llegar a la cadena final.
*/

char *PuntosDeMil (char *num) {
    //CASO BASE
    if (strlen(num) < 4) { 
        char * cadenaNumero = malloc(sizeof(char) * strlen(num) + 1); // Asignamos la memoria del puntero a retornar
        strcpy (cadenaNumero, num);                                   // Asignamos la cadena ingresada dentro del puntero a retornar
        return cadenaNumero;                                          // Retornamos la cadena que fue ingresada como parametro
    }

    //CASO RECURSIVO
    else {
        int cantidadMenosTres = strlen(num) - 3;                      // Almacenamos la cantidad de digitos menos tres

        // Generamos una cadena con los tres ultimos digitos de la cadena ingresada como parametro
        char *tresUltimos = malloc(sizeof(char) * 3);
        strncpy(tresUltimos, num + (cantidadMenosTres), 3);
        tresUltimos[3] = '\0';                                        // Colocamos el fin de linea en la posicion 3 (4to elemento)
        
        // Generamos una cadena que consista en la cadena ingresada como parametro menos los ultimos tres digitos
        char *menosUltimosTres = malloc(sizeof(char) * (cantidadMenosTres)); 
        strncpy(menosUltimosTres, num, cantidadMenosTres); 
        menosUltimosTres[cantidadMenosTres] = '\0';                   // Colocamos el fin de linea en la ultima posicion.
        
        char *auxiliar = PuntosDeMil(menosUltimosTres);               // Cadena que almacena el resultado de la llamada recursiva de la funcion
        char *punto = ".";                                            // Guardamos el '.' para utilizarlo en el paso final

        // Se concatena el resultado de la llamada recursiva, con un punto y los tres ultimos digitos del numero ingresado como parametro
        strcat(strcat(auxiliar, punto), tresUltimos);
        
        // Retornamos este ultimo valor concatenado
        return auxiliar;
    }
}
/* ######################################################################################################################### */
/* Ejercicio 6*/

//VALORES DE LOS 3 TIPOS DE STRINGS QUE SE CONCATENARAN
#define CHINO_IZQ "(-."
#define CHINO_DER ".-)"
#define CHINO_CEN "(-.-)"

//FUNCION RECURSIVA
    /*
    Funcionamiento: La idea de la funcion es que en cada caso recursivo se agregue un chino a la izquierda y un chino a la derecha. 
    Este caso recursivo debera repetirse tantas veces como sea el nivel de reunion (parametro 'nivel'). Cuando se llegue al ultimo 
    nivel de reunion (caso base), se retorna el string chino centro, y se concatena sucesivamente hasta llegar a la 
    primera llamada recursiva. */

char *reunionChinos (int nivel) {
    // CASO BASE
    if (nivel == 1) {
        char *delegacion = malloc(sizeof(char) * strlen(CHINO_CEN)+1);     // Asignamos la memoria del puntero a retornar
        strcpy(delegacion, CHINO_CEN);                                     // Asignamos la cadena chino centro dentro del puntero a retornar
        return delegacion;                                                 // Retornamos el puntero
    }
    // CASO RECURSIVO
    else {
        char *delegacion = malloc(sizeof(char) * strlen(CHINO_IZQ)+1);     // Asignamos la memoria del puntero a retornar
        strcpy(delegacion, CHINO_IZQ);                                  // Asignamos la cadena chino izquierda dentro del puntero a retornar

        // Concatenamos un chino a la izquierda con la llamada recursiva y con un chino a la derecha
        strcat(strcat(delegacion, reunionChinos(--nivel)), CHINO_DER);

        // Retornamos la cadena con un chino a cada lado agregado
        return delegacion;
    }
}
/* ######################################################################################################################### */
/* Ejercicio 7*/
// Funcion 1
/* Funcion encargada de inicializar algunos valores necesarios para poder ejecutar la funcion recursiva */
char *grafico_senales_inicializador(char cadena_HL[], char anterior){
    /*Inicializo algunas variables*/
    int aux = 0;
    int *posicion;
    posicion = &aux;

    /* Reservo un espacio de memoria por el tamanio de mi vector original.
    Sabemos que esta cadena debe ser mas larga que la original, debido
    al agregar los IONES verticales. */
    char *vector_aux = (char *) malloc((strlen(cadena_HL)) * sizeof(char));
    /*Limpiamos el espacio reservado*/
    memset(vector_aux, '0', (strlen(cadena_HL)) * sizeof(char));

    return graficoSenales(cadena_HL, anterior, posicion, vector_aux);
}

// Funcion 2
/* Funcion que se encarga de transformar una cadena de 'H'-'L' en ondas de '¯'-'_'*/
char *graficoSenales(char cadena_HL[], char anterior, int *posicion, char *puntero_vector_aux){
    // CASO BASE: caracter leido llego al final del char
    if (cadena_HL[*posicion] == '\0'){
        return puntero_vector_aux;
    }

    //CASO RECURSIVO
    // Se coloca '|' cuando la letra anterior es distinta a la actual recibida por parametro
    else if ((cadena_HL[*posicion] != anterior) && ( anterior != '\0')) {
        if (anterior == 'h'){
            anterior = 'l';
        } else {
            anterior = 'h';
        }
        strcat (puntero_vector_aux, "|"); 
        return graficoSenales(cadena_HL, anterior, posicion, puntero_vector_aux);   
    }
    // Se coloca ¯ cuando el caracter sea 'H'
    else if (cadena_HL[*posicion] == 'h') {
        anterior = 'h';
        strcat (puntero_vector_aux, "¯"); 
        *posicion += 1;
        return graficoSenales(cadena_HL, anterior, posicion, puntero_vector_aux);
    }
    // Se coloca _ cuando el caracter sea 'L'
    else if (cadena_HL[*posicion] == 'l'){
        anterior = 'l';
        strcat (puntero_vector_aux, "_");
        *posicion += 1;
        return graficoSenales(cadena_HL, anterior, posicion, puntero_vector_aux);
    }
}
/* ######################################################################################################################### */
/* Ejercicio 8*/

/* ######################################################################################################################### */
/* Ejercicio 9*/
// Funcion que se encarga de devolver si un numero recibido por parametro es o no multiplo de 7.

bool divisiblePor7(int numero){
    // CASO BASE
    if (numero < 70){
        if (numero % 7 == 0) return true;
        else                 return false;
    }
    // CASO RECURSIVO
    else {
        int ultimoNum = numero % 10;            // Extraemos el ultimo numero
        int ultimoRestaNum = ultimoNum * 2;     // Multiplicamos al ultimo numero por 2
        numero = numero / 10;                   // Movemos al numero un lugar a la derecha
        numero = numero - ultimoRestaNum;       /* Le restamos al numero principal, lo obtenido de multiplicar por
                                                   2 al ultimo numero que tenia antes*/
        return divisiblePor7(numero);           // Llamamos a la recursiva con el nuevo valor obtenido.
    }
}
/* ######################################################################################################################### */
/* Ejercicio 10*/
//FUNCION RECURSIVA
    /*
    Funcionamiento: La funcion buscara explotar multiplicador con bomba b hasta que multiplicador sea menor a b (caso base), donde se retornará este fragmento
    en caso que se pueda seguir explotando (caso recursivo), se guardaran en dos punteros los resultados de la llamada recursiva, tanto
    para el proceso de N1 como de N2 y ambos arreglos de enteros se combinaran dentro de un unico arreglo auxiliar, que sera el que se
    retornará como resultado. Es importante destacar el uso del parametro acumulador cantidad (de tipo puntro a int), el cual se usa
    para asignar la memoria del puntero auxiliar en cada vuelta, dado que este crecerá en cantidad de elementos con cada llamada recursiva.
*/

int *Explosion (int multiplicador, int b, int *cantidad) {
    //CASO BASE
    if (multiplicador <= b) {
        int * auxiliar = (int*)malloc(sizeof(int)); //asignamos la memoria del numero a retornar
        auxiliar[0] = multiplicador; //asignamos el numero dentro del puntero a retornar
        *cantidad = 1; //devolvemos la cantidad de elementos del arreglo retornado

        return auxiliar; //retornamos el puntero
    }

    //CASO RECURSIVO
    else {
        //calculamos el resultado de n1 y n2
        int n1 = multiplicador / b; 
        int n2 = multiplicador - (multiplicador / b);

        //obtenemos en un puntero el resultado de las llamadas recursivas en caso n1 y caso n2
        int * auxiliarN1 = Explosion(n1, b, cantidad);
        int * auxiliarN2 = Explosion(n2, b, cantidad);

        //unimos ambos arreglos obtenidos previamente en un arreglo
        int dimensionN1 = sizeof(auxiliarN1) / sizeof(auxiliarN1[0]);
        int dimensionN2 = sizeof(auxiliarN2) / sizeof(auxiliarN2[0]);
        int * auxiliar = (int*)malloc((*cantidad)*sizeof(int));  

        for (int i = 0; i < dimensionN1; i++) {
            auxiliar[i] = auxiliarN1[i];
        }
        for (int i = 0; i < dimensionN2 + *cantidad; i++) {  
            auxiliar[i + dimensionN1] = auxiliarN2[i];
        }

        //sumamos la cantidad de elementos del arreglo
        *cantidad += 1;

        //  free(auxiliarN1);
        //  free(auxiliarN2);  

        //retornamos el ultimo puntero generado, que contiene los elementos de los resultados de ambas llamadas recursivas
        return auxiliar;
    }
}
/* ######################################################################################################################### */
