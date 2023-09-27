#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tipo_elemento.h"
#include "pilas.h"
#include "Validaciones.h"
#include "pilas_utilidades.h"

/* Ejercicio 2 */
bool BuscarClave (Pila p, int clave);
Pila Insertar (Pila p, TipoElemento te, int pos);
Pila EliminarClave (Pila p, TipoElemento te);
Pila IntercambiarDosElementos (Pila p, int pos1, int pos2);
Pila DuplicarContenido (Pila p);
int ContarElementos (Pila p);

/* Ejercicio 3 */
bool pilas_iguales(Pila ,Pila , int);
/* Ejercicio 4 */
void decimal_Binario_Hexa(Pila, int, int);
char *pasaje(Pila);

/* Ejercicio 5 */
Pila p_invertir(Pila);

/* Ejercicio 6 */
Pila eliminarElemento_iterativo(Pila, int);
Pila eliminarElemento_recursivo(Pila, Pila, Pila, bool, int);
void menu();

/* Ejercicio 7 */
Pila elementosEnComun(Pila, Pila);

/* Ejercicio 8 */
Pila ValoresYCantidad (Pila p);