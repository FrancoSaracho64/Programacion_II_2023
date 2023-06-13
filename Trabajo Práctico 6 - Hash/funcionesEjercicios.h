#include <sys/time.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tabla_hash.h"
#include "TADs_y_extras\colas.h"
#include "TADs_y_extras\colas_utilidades.h"
#include "TADs_y_extras\listas.h"
#include "TADs_y_extras\pilas.h"
#include "TADs_y_extras\Validaciones.h"
#include "TADs_y_extras\tipo_elemento.h"
#include "TADs_y_extras\arbol-avl.h"

#define MAX_LINE_LENGTH 100

//Ejercicio 4 
void mostrarArchivo();
void AltaArchivo (ArbolAVL);
void BajaArchivo ();
void ModificacionArchivo ();
TablaHash GenerarHashAlumnos ();
int TomarLegajo ();
char* TomarApellido ();
char* TomarNombres ();
char* TomarDomicilio ();
char* TomarTelefono ();
int hashFunctionNP(int);

//Estructura Alumno
struct Alumno {
    int legajo; // 6 dígitos (valores de 000001 a 999999)
    char* apellido;
    char* nombres;
    char* domicilio;
    char* te;
    bool activo;
};

//Ejercicio 5
int esPrimo(int numero);
int encontrarPrimoMasCercano(int numero);

//Ejercicio 6
struct Vacunado {
    char nombre[20];
    char apellido[20];
    char dni[11];
};
bool esFechaValida(int dia, int mes, int anio);
int obtenerFecha();
bool esBisiesto(int anio);
void carga_datos(TablaHash t);
void recuperar_por_fecha(TablaHash tabla);
int hash_function(int clave);
int pedir_fecha();
int pedir_DNI();
void menu(TablaHash t);