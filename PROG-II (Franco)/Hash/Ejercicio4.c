#include "funcionesEjercicios.h"

int main () {
    //Presentacion
    printf("\n****************************************************************\n    NOTA: COMO MAXIMO SE PUEDEN CARGAR 100 ALUMNOS EN TOTAL\n****************************************************************\n\n");
    printf("\n\t-*-*-*-*- Tablas Hash -*-*-*-*-\n\n");
    printf("\t   -*-*-* Ejercicio 4 *-*-*-   \n\n\n");

    TablaHash th;
    ArbolAVL arbol_legajos = avl_crear();
    FILE * archivo;
    int opc;
    char opcTeclado[TAMANO_NUM];
    bool entrada = true;
    //Creamos el archivo
    archivo = fopen ("Alumnos.bin", "wb");
    fclose(archivo);
    //Menu Principal
    
    do {
        printf("\n\n\n   MENU PRINCIPAL   \n\n");
        printf("1- Dar de alta un alumno\n");
        printf("2- Dar de baja un alumno\n");
        printf("3- Modificar datos de un alumno\n");
        printf("4- Transformar el archivo de alumnos en una tabla hash\n");
        printf("5 (extra)- Mostrar estado actual del archivo.\n");
        printf("\n0- Salir del programa\n");
        
        do {
            do{
                printf("\nElija el punto al que desea acceder: ");
                fflush(stdin);
                fgets(opcTeclado, TAMANO_NUM, stdin);
                entrada = numEnteros(opcTeclado) && validarEnter(opcTeclado);
            } while (!entrada);
        opc = pasaje_String_A_int(opcTeclado);
        entrada = numeroRango(opc, 0, 5);
        } while (!entrada);

        switch (opc) {
            case 0:
                printf("\nFinalizando el programa...");
                break;
            case 1:
                //DAR DE ALTA UN ALUMNO
                AltaArchivo (arbol_legajos);
                break;
            case 2:
                //DAR DE BAJA UN ALUMNO
                BajaArchivo ();
                break;
            case 3:
                //MODIFICAR UN ALUMNO
                ModificacionArchivo ();
                break;
            case 4:
                //CREAR HASH EN BASE AL ARCHIVO
                th = GenerarHashAlumnos ();
                break;
            case 5:
                mostrarArchivo();
            default:
                break;
        }
    } while (opc != 0);
    printf("\n\nPresione ENTER para salir...");
    getchar();
    return 0;
}