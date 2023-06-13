#include "funcionesEjercicios.h"
//Ejercicio 2-------------------------------------------------------------------------------------
/*PDF*/
//Ejercicio 3-------------------------------------------------------------------------------------
/*PDF*/
//Ejercicio 4-------------------------------------------------------------------------------------
static const int NRO_PRIMO = 97;
int hashFunctionNP(int a) {
    return (a % NRO_PRIMO);
}

int TomarLegajo () {
    int legajo;
    char legajoTeclado[TAMANO_NUM];
    bool entrada = true;
    do {
        do{
            printf("\nIngresar legajo: ");
            fflush(stdin);
            fgets(legajoTeclado, TAMANO_NUM, stdin);
            entrada = numEnteros(legajoTeclado) && validarEnter(legajoTeclado);
        } while (!entrada);
    legajo = pasaje_String_A_int(legajoTeclado);
    entrada = numeroRango(legajo, 1, 999999);
    } while (!entrada); 

    return legajo;
}

char* TomarApellido () {
    char* apellido = malloc(sizeof(char) * 30);
    char apellidoTeclado[30];
    bool entrada = true;
    do{
        printf("\nIngresar apellido: ");
        fflush(stdin);
        fgets(apellidoTeclado, 30, stdin);
        entrada = validarEnter(apellidoTeclado) && soloLetras(apellidoTeclado);
    } while (!entrada);
    strcpy (apellido, apellidoTeclado);
    return apellido;
}

char* TomarNombres () {
    char* nombres = malloc(sizeof(char) * 40);
    char nombresTeclado[40];
    bool entrada = true;
    do{
        printf("\nIngresar nombres: ");
        fflush(stdin);
        fgets(nombresTeclado, 40, stdin);
        entrada = validarEnter(nombresTeclado) && soloLetras(nombresTeclado);
    } while (!entrada);
    strcpy (nombres, nombresTeclado);
    return nombres;
}

char* TomarDomicilio () {
    char* domicilio = malloc(sizeof(char) * 50);
    char domicilioTeclado[50];
    bool entrada = true;
    do{
        printf("\nIngresar domicilio: ");
        fflush(stdin);
        fgets(domicilioTeclado, 50, stdin);
        entrada = validarEnter(domicilioTeclado);
    } while (!entrada);
    strcpy (domicilio, domicilioTeclado);
    return domicilio;
}

char* TomarTelefono () {
    char* telefono = malloc(sizeof(char) * 18);
    char telefonoTeclado[18];
    bool entrada = true;
    do{
        printf("\nIngresar telefono: ");
        fflush(stdin);
        fgets(telefonoTeclado, 18, stdin);
        entrada = validarEnter(telefonoTeclado) && soloNumeros(telefonoTeclado);
    } while (!entrada);
    strcpy (telefono, telefonoTeclado);
    return telefono;
}

//----------------------------------------------------------------------------------------------------------------------------------
void mostrarArchivo(){
    struct Alumno alum;
    FILE *archivo;
    archivo = fopen("Alumnos.bin", "rb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
    } else {
        int contador = 1;
        while (!feof(archivo)) {
            if (fread(&alum, sizeof(struct Alumno), 1, archivo) == 1) {
                printf("\n\nALUMNO Nro: %d\n", contador);
                printf("Legajo: %d\n", alum.legajo);
                printf("Apellido: %s\n", alum.apellido);
                printf("Nombre: %s\n", alum.nombres);
                printf("Domicilio: %s\n", alum.domicilio);
                printf("Contacto: %s\n", alum.te);
                printf("ESTADO: %d", alum.activo);
                contador ++;
            }
            else {
                if (contador == 1) printf("\n\nEl archivo se encuentra VACIO!!!\n");
                else printf("\n\n*****Se ha llegado al final del archivo*****\n");
            }
        }
    }
    // Cerrar el archivo
    fclose(archivo);
    return;
}

void AltaArchivo (ArbolAVL arbol_legajos) {
    struct Alumno nuevoA;
    FILE *archivo;
    FILE *archivo2;
    int   legajoNuevo;
    char* apellidoNuevo;
    char* nombresNuevo;
    char* domicilioNuevo;
    char* teNuevo;        
    int resultadBusqueda = 0;              

    //Pedir los 5 datos
    bool encontrado;
    bool alta = false;
    TipoElemento legajo;

    archivo2 = fopen("Alumnos.bin", "rb+");
    if (archivo2 == NULL) {
        printf("\nError al abrir el archivo.\n");
    } else {
        do {
            encontrado = false;
            legajoNuevo = TomarLegajo ();
            // Tengo que buscar en los legajos YA cargados.
            legajo = avl_buscar(arbol_legajos, legajoNuevo);
            if (legajo == NULL) avl_insertar(arbol_legajos, te_crear(legajoNuevo));
            else {
                while (fread(&nuevoA, sizeof(struct Alumno), 1, archivo2) && resultadBusqueda == 0) {
                    if (nuevoA.legajo == legajoNuevo) {
                        resultadBusqueda = 1;
                        if (nuevoA.activo == false) nuevoA.activo = true;
                        //Sobreescribimos el registro
                        long posicion = ftell(archivo2) - sizeof(struct Alumno);
                        fseek(archivo2, posicion, SEEK_SET);
                        fwrite(&nuevoA, sizeof(struct Alumno), 1, archivo2);
                        fclose(archivo2);
                        printf("\nSe ha dado de alta nuevamente al legajo ingresado.\n");
                        alta = true;
                    }
                }
                if (!alta) printf("\nERROR:   El legajo ingresado ya esta cargado. Intente con otro.\n");
            }
        } while (encontrado && alta);
    

        if (!alta){
            apellidoNuevo = TomarApellido ();
            nombresNuevo = TomarNombres ();
            domicilioNuevo = TomarDomicilio ();
            teNuevo = TomarTelefono (); 

            //Crear la instancia del registro alumno
            nuevoA.legajo = legajoNuevo;
            nuevoA.apellido = apellidoNuevo;
            nuevoA.nombres = nombresNuevo;
            nuevoA.domicilio = domicilioNuevo;
            nuevoA.te = teNuevo;
            nuevoA.activo = true;

            //Abrir el archivo, hacer append del registro y cerrar el archivo
            archivo = fopen ("Alumnos.bin", "ab");
            if(archivo == NULL) { 
                printf("\nError al abrir el archivo.\n");
            }
            else{
                fwrite(&nuevoA, sizeof(struct Alumno), 1, archivo);
                printf("\n*****Alta completada*****\n");   
            }
            fclose(archivo);
            return;
        }
    }
}

void BajaArchivo () {
    int legajoABorrar;
    int resultadBusqueda = 0;
    struct Alumno alumnoABorrar;
    FILE *archivo;

    //Buscar segun el legajo
    legajoABorrar = TomarLegajo ();

    archivo = fopen("Alumnos.bin", "rb+");
    if (archivo == NULL) {
        printf("\nError al abrir el archivo.\n");
    } else {
        //Si se encuentra, borrar y avisar
        while (fread(&alumnoABorrar, sizeof(struct Alumno), 1, archivo) && resultadBusqueda == 0) {
            if (alumnoABorrar.legajo == legajoABorrar) {
                //Damos de baja el registro
                resultadBusqueda = 1;
                alumnoABorrar.activo = false;
                //Sobreescribimos el registro
                long posicion = ftell(archivo) - sizeof(struct Alumno);
                fseek(archivo, posicion, SEEK_SET);
                fwrite(&alumnoABorrar, sizeof(struct Alumno), 1, archivo);
                fclose(archivo);

                printf("\n*****Baja completada*****\n");
            }
        }
    }
    //Si NO se encuentra, avisar que no se encontro y no se pudo borrar
    if (resultadBusqueda == 0) {
        printf("\nNo se encuentra el registro... No se pudo completar la baja.\n\n");
        fclose(archivo);
    }
    return;
}

void ModificacionArchivo () {
    int legajoAModificar;
    int resultadBusqueda = 0;
    struct Alumno alumnoAModificar;
    FILE *archivo;

    int legajoNuevo;
    char* apellidoNuevo;
    char* nombresNuevo;
    char* domicilioNuevo;
    char* teNuevo; 

    //Buscar segun el legajo
    legajoAModificar = TomarLegajo ();

    archivo = fopen("Alumnos.bin", "rb+");
    if (archivo == NULL) {
        printf("\nError al abrir el archivo.\n");
    } else{

        //Si se encuentra, preguntar que dato se quiere modificar
        while (fread(&alumnoAModificar, sizeof(struct Alumno), 1, archivo) && resultadBusqueda == 0) {
            if (alumnoAModificar.legajo == legajoAModificar) {
                
                if (alumnoAModificar.activo){
                    resultadBusqueda = 1;

                    int opc;
                    char opcTeclado[TAMANO_NUM];
                    bool entrada = true;
                    do {
                        printf("\n\n\t   -*-*-* Que dato quiere modificar del alumno %d? *-*-*-   \n\n", legajoAModificar);
                        printf("1- Legajo\n");
                        printf("2- Apellido\n");
                        printf("3- Nombres\n");
                        printf("4- Domicilio\n");
                        printf("5- Telefono\n");

                        printf("\n0- Volver al menu principal (Guardando los cambios realizados)\n");
                        
                        do {
                            do{
                                printf("\nElija el dato a modificar: ");
                                fflush(stdin);
                                fgets(opcTeclado, TAMANO_NUM, stdin);
                                entrada = numEnteros(opcTeclado) && validarEnter(opcTeclado);
                            } while (!entrada);
                        opc = pasaje_String_A_int(opcTeclado);
                        entrada = numeroRango(opc, 0, 5);
                        } while (!entrada);

                        switch (opc) {
                            
                            case 0:
                                break;

                            case 1:
                                printf ("Modificar legajo %d", alumnoAModificar.legajo);
                                legajoNuevo = TomarLegajo ();
                                alumnoAModificar.legajo = legajoNuevo;
                                break;

                            case 2:
                                printf ("Modificar apellido %s", alumnoAModificar.apellido);
                                apellidoNuevo = TomarApellido ();
                                alumnoAModificar.apellido = apellidoNuevo;
                                break;

                            case 3:
                                printf ("Modificar nombres %s", alumnoAModificar.nombres);
                                nombresNuevo = TomarNombres ();
                                alumnoAModificar.nombres = nombresNuevo;
                                break;

                            case 4:
                                printf ("Modificar domicilio %s", alumnoAModificar.domicilio);
                                domicilioNuevo = TomarDomicilio ();
                                alumnoAModificar.domicilio = domicilioNuevo;
                                break;

                            case 5:
                                printf ("Modificar telefono %s", alumnoAModificar.te);
                                teNuevo = TomarTelefono ();
                                alumnoAModificar.te = teNuevo; 
                                break;
                            
                            default:
                                break;
                        }
                    } while (opc != 0);
                } else {
                    printf("\n*****El legajo ingresado corresponde a un alumno dado de BAJA*****");
                    resultadBusqueda = -1;
                    fclose(archivo);
                    return;
                }
                //Sobreescribimos el registro
                long posicion = ftell(archivo) - sizeof(struct Alumno);
                fseek(archivo, posicion, SEEK_SET);
                fwrite(&alumnoAModificar, sizeof(struct Alumno), 1, archivo);
                printf("\n*****Modificacion completada*****\n");
                fclose(archivo);
            }
        }
    }
    //Si NO se encuentra, avisar que no se encontro y no se pudo modificar
    if (resultadBusqueda == 0) {
        printf("\nNo se encuentra el registro... No se pudo completar la modificacion.\n");
        fclose(archivo);
    }
    return;
}

TablaHash GenerarHashAlumnos () {
    FILE * archivo;
    struct Alumno AlumnoActual;
    TipoElemento te;
    
    TablaHash th = th_crear(100, &hashFunctionNP);

    // Abrir el archivo en modo lectura binaria
    archivo = fopen("Alumnos.bin", "rb");
    if (archivo == NULL) {
        printf("\nError al abrir el archivo.\n");
    } else {

        // Recorrer el archivo y por cada registro insertarlo en la tabla
            //clave -> legajo
            //valor -> direccion fisica del registro
        while (fread(&AlumnoActual, sizeof(struct Alumno), 1, archivo) == 1) {
            int legajoTH = AlumnoActual.legajo;
            bool estado = AlumnoActual.activo;
            if(estado){
                void * direccionATH = &AlumnoActual;
                te = te_crear_con_valor(legajoTH, direccionATH);
                th_insertar(th, te);
            }
        }
    }

    // Cerrar el archivo
    fclose(archivo);

    // Mostrar tabla
    th_mostrar(th);

    // Retornar tabla
    return th;

}

//Ejercicio 5-------------------------------------------------------------------------------------
int esPrimo(int numero) {
    if (numero <= 1) {
        return 0; // No es primo
    }
    int i;
    int limite = sqrt(numero);

    for (i = 2; i <= limite; i++) {
        if (numero % i == 0) {
            return 0; // No es primo
        }
    }
    return 1; // Es primo
}

int encontrarPrimoMasCercano(int numero) {
    int primoMasCercano = numero - 1;
    while (primoMasCercano >= 2) {
        if (esPrimo(primoMasCercano)) {
            return primoMasCercano;
        }
        primoMasCercano--;
    }
    return 1; // No se encontró un primo más cercano
}
//Ejercicio 6-------------------------------------------------------------------------------------
void carga_datos(TablaHash t){
    TipoElemento dato, valor;
    char fechaget[20];
    char fechasin[20];
    char opcTeclado[5];
    char nombre[20];
    char apellido[20];
    char DNIget[20];
    bool entrada;
    bool otraPersona;
    
    int fecha_int, opc, opcion, dni;

    // Pedimos que ingrese la fecha
    fecha_int = pedir_fecha();
    Lista listaDatos;

    TipoElemento auxiliar = th_recuperar(t, fecha_int);
    if (auxiliar == NULL){
        listaDatos = l_crear();
    } else {
        listaDatos = (Lista)auxiliar->valor;
    }    
    do{
        struct Vacunado *punteroPersona; 
        punteroPersona = (struct Vacunado*) malloc(sizeof(struct Vacunado));
        // Nombre
        do{
            printf("\n Ingrese el nombre: ");
            fflush(stdin);
            fgets(nombre, TAMANO_NUM, stdin);  
            entrada = soloLetras(nombre) && validarEnter(nombre);
        }while (!entrada);
        
        // Apellido
        do{
            printf("\n Ingrese el apellido: ");
            fflush(stdin);
            fgets(apellido, TAMANO_NUM, stdin);
            entrada = soloLetras(apellido) && validarEnter(nombre);
        }while(!entrada);
        
        // DNI
        bool valido = true;
        do {
            printf("\n Ingrese DNI (xxx.xxx.xxx) --->  ");
            fflush(stdin);
            fgets(DNIget, TAMANO_NUM, stdin);
            dni = pedir_DNI(DNIget);
            valido = numeroRango(dni, 1,999999999);
        } while (!valido);    

        strcpy(punteroPersona->nombre, nombre);
        strcpy(punteroPersona->apellido, apellido);
        strcpy(punteroPersona->dni, DNIget);

        dato = te_crear_con_valor (0, punteroPersona);
        l_agregar(listaDatos, dato);
        dato = te_crear_con_valor(fecha_int, listaDatos);
        th_insertar(t, dato);

        do {
            do {
                printf("¿Quiere cargar otra persona?   1 --> Si  ||  0 --> No\n");
                printf("Opcion: ");
                fflush(stdin);
                fgets(opcTeclado, TAMANO_NUM, stdin);
                entrada = numEnteros(opcTeclado) && validarEnter(opcTeclado);
            } while (!entrada);
        opcion = pasaje_String_A_int(opcTeclado);
        entrada = numeroRango(opcion, 0, 1);
        } while (!entrada);
        if (opcion == 0) otraPersona = false;
        else otraPersona = true;
    } while(otraPersona);
}

void recuperar_por_fecha(TablaHash tabla){
    TipoElemento dato;
    struct Vacunado *recuperado;
    recuperado = (struct Vacunado*) malloc(sizeof(struct Vacunado));
    int fecha_int = pedir_fecha();
    dato = th_recuperar(tabla, fecha_int);
    if (dato == NULL) {
        printf("\nNo se encontro la fecha ingresada.");

        return;
    }
    // Mostrar la lista cargada de registros...
    Iterador iter = iterador((Lista)(dato->valor));
    int i = 1;
    printf("\n\nPersonas vacunadas en la fecha ingresada...\n");
    while (hay_siguiente(iter)) {
        TipoElemento elem = siguiente(iter);
        recuperado = (struct Vacunado*) elem->valor;

        printf("Persona: %d\n", i);
        printf("         ** %s\n", recuperado->nombre);
        printf("         ** %s\n", recuperado->apellido);
        printf("         ** %s\n\n", recuperado->dni);
        i++;
    }   
}

int pedir_fecha(){
    int fecha;
    do {
        fecha = obtenerFecha();
        if (fecha == -1) {
            printf("La fecha ingresada NO es válida o es posterior al día de hoy.\n");
        }
    } while (fecha == -1);
    return fecha;
}

int obtenerFecha() {
    int dia, mes, anio;
    fflush(stdin);
    printf("\nIngrese una fecha (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &dia, &mes, &anio);

    if (esFechaValida(dia, mes, anio)) {
        return (anio * 10000) + (mes * 100) + dia;
    } else {
        return -1; // Valor de retorno indicando fecha inválida
    }
}

bool esFechaValida(int dia, int mes, int anio) {
    if (mes < 1 || mes > 12) {
        return false;
    }

    int diasEnMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (esBisiesto(anio)) {
        diasEnMes[1] = 29; // Febrero tiene 29 días en año bisiesto
    }

    if (dia < 1 || dia > diasEnMes[mes - 1]) {
        return false;
    }

    // Obtener la fecha de hoy
    time_t t = time(NULL);
    struct tm today = *localtime(&t);

    // Verificar si la fecha ingresada es posterior al día de hoy
    if (anio > today.tm_year + 1900 || anio < 2020) {
        return false;
    } else if (anio == today.tm_year + 1900) {
        if (mes > today.tm_mon + 1) {
            return false;
        } else if (mes == today.tm_mon + 1) {
            if (dia > today.tm_mday) {
                return false;
            }
        }
    }
}

bool esBisiesto(int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

int pedir_DNI(char DNIget[]){
    char DINsin[8];
    int DNI_int,i,j;
    for (i = 0, j = 0; j != 9; i++) {
        if (DNIget[i] != '.') {
            DINsin[j] = DNIget[i];
            j++;
        }
    }
    DINsin[j] = '\0';
    DNI_int = pasaje_String_A_int(DINsin);
    return DNI_int;
}

void menu(TablaHash tabla){
    int opc;
    char opcion[1];

    do {
        printf("\n\n   MENU PRINCIPAL\n1) Cargar vacunados por fecha\n2) Obtener datos por fecha\n\n0) Salir\n\nIngrese una opcion---> ");
        fflush(stdin);
        fgets(opcion, TAMANO_NUM, stdin);
        opc = pasaje_String_A_int(opcion);
        switch (opc){
            case 1:
                carga_datos(tabla);
                break;
            case 2:
                recuperar_por_fecha(tabla);
                break;
            case 0:
                printf("\nFinalizando ejecucion...");
                break;
            default:
                printf("Ha ingresado una opcion invalida. Vuelva a intentar.\n\n");
                break;
            }
    } while (opc != 0);
    return;
}