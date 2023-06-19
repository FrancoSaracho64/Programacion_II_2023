#include <sys/time.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "conjuntos.h"
#include "conjuntos_utilidades.h"
#include "TADs_y_extras\colas.h"
#include "TADs_y_extras\colas_utilidades.h"
#include "TADs_y_extras\listas.h"
#include "TADs_y_extras\pilas.h"
#include "TADs_y_extras\Validaciones.h"
#include "TADs_y_extras\tipo_elemento.h"
#include "TADs_y_extras\arbol-avl.h"

//Ejercicio2-----------------------------------------------------------------------------------
void menuEj2(Conjunto, Conjunto);

//Ejercicio3-----------------------------------------------------------------------------------
void menuEj3(Lista);

//Ejercicio4-----------------------------------------------------------------------------------
bool EsSubconjunto (Conjunto a, Conjunto b);
void Transitividad3Conjuntos (Conjunto a, Conjunto b, Conjunto c);

//Ejercicio5-----------------------------------------------------------------------------------
Conjunto diferenciaSimetrica (Conjunto cto_a, Conjunto cto_b);

//Ejercicio6-----------------------------------------------------------------------------------
//--- EsSubconjunto

//Ejercicio7-----------------------------------------------------------------------------------
int SubconjuntoParcialOTotal (Conjunto a, Conjunto b);
void SubconjuntoParcial3Conjuntos (Conjunto a, Conjunto b, Conjunto c);

//Ejercicio8-----------------------------------------------------------------------------------
bool conjuntosIguales(Conjunto, Conjunto);