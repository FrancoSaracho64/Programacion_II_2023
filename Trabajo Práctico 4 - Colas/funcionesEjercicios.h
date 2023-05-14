#include <stdbool.h>
#include "colas.h"
#include "pilas.h"
#include "listas.h"

//Ejercicio 2------------------------------------------------------------------------------
bool c_contiene_elemento(Cola, TipoElemento);
Cola c_agregar_en_posicion(Cola, TipoElemento , int);
Cola c_eliminar_elemento(Cola, TipoElemento);
int c_contar_elementos(Cola);
Cola c_copiar(Cola);
Cola c_invertir_contenido(Cola);
//Ejercicio 3------------------------------------------------------------------------------
bool colas_iguales(Cola, Cola, int);
//Ejercicio 4------------------------------------------------------------------------------
Cola numerosSinRepetir(Cola);
//Ejercicio 5------------------------------------------------------------------------------
Cola divisor_total_parcial(Cola, int);
bool numRepetido(Cola, int);
//Ejercicio 6------------------------------------------------------------------------------
Lista busca_Pila_Cola(Pila, Cola);
//Ejercicio 7------------------------------------------------------------------------------
void mostrarClienteAtendido(int, int, int);
void atenderTresVentanillas (int , Cola , Cola , Cola );