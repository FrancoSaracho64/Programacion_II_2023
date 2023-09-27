#ifndef FUNCIONESEJERCICIOS_H
#define FUNCIONESEJERCICIOS_H
//Importaciones
#include "TADs_y_extras\tipo_elemento.h"
#include "TADs_y_extras\listas.h"
#include "TADs_y_extras\Validaciones.h"

/*Ejercicio 1*/
// TAD de listas
/*Ejercicio 2*/
// Declaraciones
void menu();
void cargarLista(Lista);
void posicionDatoMenor(Lista);
void datoMaximoVeces(Lista);
float promedio(Lista, int, float);
Lista MultiplosDe(Lista, int);

/*Ejercicio 3*/
bool multiplo_listas(Lista, Lista);
int escalar_multiplo(Lista, Lista);

/*Ejercicio 4*/
void CompararL1L2(Lista, Lista);

/*Ejercicio 5*/
double CalculoValorDeX (double, Lista);
Lista CalculoRango (double, double, Lista);
Lista PasarALista(double *, int);

/*Ejercicio 6*/
bool es_sublista(Lista, Lista); // COMPLEJIDAD ALGORÍTMICA DE "es_sublista" es del tipo cuadrática, siendo esta: O(n*m).

#endif // FUNCIONESEJERCICIOS_H