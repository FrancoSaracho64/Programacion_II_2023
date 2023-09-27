#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include "TADs_y_extras\colas_utilidades.h"
#include "TADs_y_extras\colas.h"
#include "TADs_y_extras\listas.h"
#include "TADs_y_extras\pilas.h"
#include "TADs_y_extras\Validaciones.h"
#include "TADs_y_extras\arbol-binario.h"
#include "TADs_y_extras\arbol-avl.h"
#include "TADs_y_extras\nodo.h"
#include "TADs_y_extras\arbol-Utilidades.h"
#include "TADs_y_extras\tipo_elemento.h"
#include "TADs_y_extras\arbol-binario-busqueda.h"

/*Ejercicio 2 ---------------------------------------------------------------------------------- */
void menuPrincipalEjer2();
Lista ejercicio2A(ArbolBinario);
void ejercicio2A_1(Lista, NodoArbol, TipoElemento);
Lista ejercicio2B();
void ejercicio2B_1(Lista, NodoArbol, TipoElemento, int);
Lista ejercicio2C(ArbolBinario, TipoElemento);
void ejercicio2C_1(Lista, NodoArbol, TipoElemento, TipoElemento);
void ejercicio2D();
/*Ejercicio 3 ---------------------------------------------------------------------------------- */
NodoArbol ejercicio3(NodoArbol, int);
void nodoEncontrado(NodoArbol, int, bool*, NodoArbol*);
//
void nodo_padre(NodoArbol, int, NodoArbol*);
//
void nodo_hijos(NodoArbol, int, Lista);
//
void nodo_hermano(NodoArbol, int, Lista);
//
void nivel_nodo(NodoArbol, int, int*, int);
//
int altura_nodo(NodoArbol);
//
void nodos_mismoNivel(NodoArbol, Lista, int, int);
Lista nodos_mismoNivel_inic(NodoArbol);

/*Ejercicio 4 ---------------------------------------------------------------------------------- */
void menuPrincipalEjer4();
//a
Lista arbolEnlistado(NodoArbol);
void enlistarArbolInt(Lista, Cola, NodoArbol, int);
//b
int cantHojas_n_ario(ArbolBinario);
void cantHojas_n_ario_Int(NodoArbol, int*);
//c
bool sonSimilares(NodoArbol, NodoArbol);
//d
NodoArbol nodoPadre(ArbolBinario, int);
void nodoPadreInt(NodoArbol, NodoArbol, int, NodoArbol*);
//e
Lista hermanosNodoNario(ArbolBinario, int);
void hermanosNodoNario_int(ArbolBinario, NodoArbol, NodoArbol, Lista, int);

/*Ejercicio 5 ---------------------------------------------------------------------------------- */
/*Ejercicio 6 ---------------------------------------------------------------------------------- */
/*Ejercicio 7 ---------------------------------------------------------------------------------- */
bool sonEquivalentes(NodoArbol, NodoArbol);
/*Ejercicio 8 ---------------------------------------------------------------------------------- */
void menuPrincipalEjer8();
//A
int alturaArbolNario(ArbolBinario);
void alturaArbolNarioInt(NodoArbol, int*, int);
//B
int alturaNodoNario(ArbolBinario, int);
void alturaNodoNarioInt(NodoArbol, int*, int, int);
//C
Lista nodosInternosNario(ArbolBinario);        
void nodosInternosNario_Int(Lista, NodoArbol, TipoElemento, int);
//D
bool hojasMismoNivelNario(ArbolBinario);
void hojasMismoNivelNario_int(NodoArbol, int*, bool*, bool*, int);

/*Ejercicio 9 ---------------------------------------------------------------------------------- */
void BinarioAvlInt (ArbolAVL retorno, NodoArbol q);
void BinarioAvl (ArbolAVL retorno, ArbolBinario a);
int  altura_nodoBis(NodoArbol nodo);
/*Ejercicio 10 --------------------------------------------------------------------------------- */

Cola cargarColaAleatoriamente(int, int);