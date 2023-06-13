#include "colas.h"
/*Dar la cantidad de elementos de una cola, sin destruirla*/
int c_longitud(Cola);

/*Copiar el contenido de una Caux en C*/
void c_intercambiar(Cola c, Cola c_aux);

/*Cargar una cola*/
void c_cargar(Cola);
void c_cargar_positivos(Cola);
void c_cargar_sinRepetidos(Cola);
void c_cargar_sinRepetidosRango(Cola, int, int, int, int);

/*Buscar elemento repetido*/
bool c_elementoRepetido(Cola, int);