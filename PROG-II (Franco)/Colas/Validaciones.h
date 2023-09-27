#ifndef VALIDACIONES_H
#define VALIDACIONES_H
#include <stdbool.h>
/*
    Validaciones de entrada
*/
bool numEnteros(char[]);
bool esCero(int);
bool cantCaracteres(char[], int);
int pasaje_String_A_int(char[]);
bool soloUnCaracter(char[]);
bool validarEnter(char []);
bool validarEnterPuntero(char *);
bool numeroRango(int, int, int);
bool numeroRangoMedio(int, int, int, int, int);
void pasajeMinusculas(char []);
bool comparaCaracteres(char[], char, char);
char *truncarCeros (char *);
char *insertarMenos (char *);
char *truncarMenos (char *);
bool controlMenos (char*);

#define TAMANO_NUM 15
#endif // VALIDACIONES_H