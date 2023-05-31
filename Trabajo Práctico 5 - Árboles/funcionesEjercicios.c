#include "funcionesEjercicios.h"

/*Ejercicio 2 ---------------------------------------------------------------------------------- */
void menuPrincipalEjer2(){
    printf("                Menu principal\n\n");
    printf(" 1.  Mostrar los nodos HOJA del arbol.\n");
    printf(" 2.  Mostrar los nodos internos del arbol (NO raiz, NO hojas).\n");
    printf(" 3.  Mostrar coincidencias y posiciones de un elemento dado.\n");
    printf(" 4.  Complejidad algoritmica de los ejercicios.\n\n");
    printf(" 0.  Finalizar ejecucion...\n\n");
    printf("INGRESE UNA OPCION: ");
}
/*a*/
Lista ejercicio2A(ArbolBinario arbol){
    Lista listaHojas = l_crear();
    TipoElemento elem;
    ejercicio2A_1(listaHojas, a_raiz(arbol), elem);
    return listaHojas;
}
void ejercicio2A_1(Lista l, NodoArbol nodo, TipoElemento elem){
    if (a_es_rama_nula(nodo)) return;
    else { 
        if ((n_hijoizquierdo(nodo) == NULL) && (n_hijoderecho(nodo) == NULL)){
            elem = nodo->datos;
            l_agregar(l, elem);
        }
        ejercicio2A_1(l, n_hijoizquierdo(nodo), elem);
        ejercicio2A_1(l, n_hijoderecho(nodo), elem);
    }
}
/*b*/
Lista ejercicio2B(ArbolBinario arbol){
    Lista listaNodos = l_crear();
    TipoElemento elem;
    ejercicio2B_1(listaNodos, a_raiz(arbol), elem, 0);
    return listaNodos;
}
void ejercicio2B_1(Lista lista, NodoArbol nodo, TipoElemento elem, int nivel){
    if (nodo == NULL) return;
    else { 
        if (nivel != 0){
            if ((n_hijoizquierdo(nodo) != NULL) || (n_hijoderecho(nodo) != NULL)){
                elem = nodo->datos;
                l_agregar(lista, elem);
            }
        }
        ejercicio2B_1(lista, n_hijoizquierdo(nodo), elem, nivel+1);
        ejercicio2B_1(lista, n_hijoderecho(nodo), elem, nivel+1);
    }
}
/*c*/
Lista ejercicio2C(ArbolBinario arbol, TipoElemento elemUsuario){
    Lista listaOcurrencias = l_crear();
    TipoElemento elem;
    ejercicio2C_1(listaOcurrencias, a_raiz(arbol), elem, elemUsuario);
    return listaOcurrencias;
}
void ejercicio2C_1(Lista lista, NodoArbol nodo, TipoElemento elem, TipoElemento elemUsuario){
    if (nodo == NULL) return;
    else{
        elem = nodo->datos;
        if (elem->clave == elemUsuario->clave){
            elem->valor = &elem;
            l_agregar(lista, elem);
        }
        ejercicio2C_1(lista, n_hijoizquierdo(nodo), elem, elemUsuario);
        ejercicio2C_1(lista, n_hijoderecho(nodo), elem, elemUsuario);
    }
}

/*d*/
void ejercicio2D(){
    //Complejidad algoritmica
    printf("-------------------------------------------------------------------------------------------------\nCOMPLEJIDAD ALGORITMICA: \n");
    printf(" la complejidad algoritmica de las funciones a,b,c en el peor de los casos es O(n  log(2) n) \n ya que  se multiplica n que es la cantidad de niveles que tiene el arbol \n y  log(2) n  porque por cada llamada recursiva el problema se divide en dos  (log(2)) \n y el tiempo de cada nivel es n. esto quedaria O(n  log(2) n). ");
    printf("\n-------------------------------------------------------------------------------------------------\n\n\n");
}

/*Ejercicio 3 ---------------------------------------------------------------------------------- */
NodoArbol ejercicio3(NodoArbol nodo, int numero){
    /*a*/
    NodoArbol resultado_a;
    nodo_padre(nodo, numero, &resultado_a);
    printf("\n\n  ---A)   El padre del nodo ingresado es: %d\n\n", resultado_a->datos->clave);

    /*b*/
    Lista lista_hijos = l_crear();
    nodo_hijos(nodo, numero, lista_hijos);
    printf("  ---B)   Los hijos del nodo ingresado son (LISTA):\n\n");
    l_mostrarLista(lista_hijos);
    printf("\n");

    /*c*/
    Lista lista_hermano = l_crear();
    nodo_hermano(nodo, numero, lista_hermano);
    printf("  ---C)   Los hermanos del nodo ingresado son (LISTA):\n\n");
    l_mostrarLista(lista_hermano);
    printf("\n");

    /*d*/
    int nivel = -1;
    nivel_nodo(nodo, numero, &nivel, 0);
    if (nivel == -1)
        printf("  ---D)   La clave no se encuentra en el arbol.\n\n");
    else
        printf("  ---D)   La clave %d se encuentra en el nivel %d del arbol.\n\n", numero, nivel);

    /*e*/
    int altura;
    NodoArbol nodo_n = n_crear(NULL);
    nodo_n = altura_nodo_inicial(nodo, numero);
    altura = altura_nodo(nodo_n);
    printf("  ---E)   La altura del nodo ingresado es: %d\n\n", altura);

    /*f*/
    Lista res_f = l_crear();
    res_f = nodos_mismoNivel_inic(nodo);
    printf("  ---F)   Los nodos del nivel ingresado son:\n\n");
    l_mostrarLista(res_f);
}
//a
void nodo_padre(NodoArbol nodo, int numero, NodoArbol *x){
    if (!a_es_rama_nula(nodo)){
        if(n_recuperar(nodo)->clave == numero) return;
        else{
            if (!a_es_rama_nula(n_hijoizquierdo(nodo)) && !a_es_rama_nula(n_hijoderecho(nodo))) {
                if (n_hijoizquierdo(nodo)->datos->clave == numero || n_hijoderecho(nodo)->datos->clave == numero){
                    *x = nodo;

                }else{
                    nodo_padre(n_hijoizquierdo(nodo), numero, x);
                    nodo_padre(n_hijoderecho(nodo), numero, x );
                }
            }else if (a_es_rama_nula(n_hijoizquierdo(nodo)) && !a_es_rama_nula(n_hijoderecho(nodo))){
                if (n_hijoderecho(nodo)->datos->clave == numero){
                    *x = nodo;

                }
                else{
                    nodo_padre(n_hijoizquierdo(nodo), numero, x);
                    nodo_padre(n_hijoderecho(nodo), numero, x);
                }
            }else if (!a_es_rama_nula(n_hijoizquierdo(nodo)) && a_es_rama_nula(n_hijoderecho(nodo))){
                if (n_hijoizquierdo(nodo)->datos->clave == numero){
                    *x = nodo;

                }
                else{
                    nodo_padre(n_hijoizquierdo(nodo), numero, x);
                    nodo_padre(n_hijoderecho(nodo), numero, x);
                }
            }
        }
    }
}
//b
void nodo_hijos(NodoArbol nodo, int numero, Lista lista){
    TipoElemento elem;
    if (nodo->datos->clave == numero) {
        if (!a_es_rama_nula(n_hijoizquierdo(nodo))) {
            elem = n_hijoizquierdo(nodo)->datos;
            l_agregar(lista, elem);
        }
        if (!a_es_rama_nula(n_hijoderecho(nodo))) {
            elem = n_hijoderecho(nodo)->datos;
            l_agregar(lista, elem);
        }
    } else {
        if(!a_es_rama_nula(n_hijoizquierdo(nodo)))
        nodo_hijos(n_hijoizquierdo(nodo), numero, lista);
        if(!a_es_rama_nula(n_hijoderecho(nodo)))
        nodo_hijos(n_hijoderecho(nodo), numero, lista);
    }
}
//c
void nodo_hermano(NodoArbol nodo, int numero, Lista lista){
    TipoElemento elem;
    if (!a_es_rama_nula(nodo)){
        if (!a_es_rama_nula(n_hijoizquierdo(nodo))){
            if (n_recuperar(n_hijoizquierdo(nodo))->clave == numero){
                elem = n_recuperar(n_hijoderecho(nodo));
                if (elem != NULL)
                    l_agregar(lista, elem);
            }
        }
        if (!a_es_rama_nula(n_hijoderecho(nodo))){
            if (n_recuperar(n_hijoderecho(nodo))->clave == numero){
                elem = n_recuperar(n_hijoizquierdo(nodo));
                if (elem != NULL)
                    l_agregar(lista, elem);
            }
        }
        if (l_es_vacia(lista)) {
        nodo_hermano(n_hijoizquierdo(nodo), numero, lista);
        nodo_hermano(n_hijoderecho(nodo), numero, lista);
        }
    }
}
//d
void nivel_nodo(NodoArbol nodo, int numero, int *nivel, int c){
    TipoElemento X;
    if (nodo != NULL){
        X = n_recuperar(nodo);
        if (X->clave == numero){
            *nivel = c;
        } else {
            nivel_nodo(n_hijoizquierdo(nodo), numero, nivel, c + 1);
            nivel_nodo(n_hijoderecho(nodo), numero, nivel, c + 1);
        }
    }
}
//e
int altura_nodo(NodoArbol nodo){
    if (n_hijoizquierdo(nodo) == NULL && n_hijoderecho(nodo) == NULL)
        return 0; // Es una hoja
    int altIzq = -1, altDer = -1;
    if (n_hijoizquierdo(nodo) != NULL)
        altIzq = altura_nodo(n_hijoizquierdo(nodo)); // Altura del sub-árbol izquierdo (si existe)
    if (n_hijoderecho(nodo) != NULL)
        altDer = altura_nodo(n_hijoderecho(nodo)); // Altura del sub-árbol derecho (si existe)
    // Elegimos el mayor valor y le sumamos 1
    if (altIzq > altDer)
        return altIzq + 1;
    else
        return altDer + 1;
}
NodoArbol altura_nodo_inicial(NodoArbol nodo, int numero){
    if (nodo->datos->clave == numero){
        return nodo;
    } else{
        if(!a_es_rama_nula(n_hijoizquierdo(nodo)))
        altura_nodo_inicial(n_hijoizquierdo(nodo), numero);
        if(!a_es_rama_nula(n_hijoderecho(nodo)))
        altura_nodo_inicial(n_hijoderecho(nodo), numero);
    }
}
//f
void nodos_mismoNivel(NodoArbol nodo, Lista lista, int nivel, int cont){
    TipoElemento elem;
    if (nodo == NULL) return;
    else{
        if (nivel == cont){
            elem = n_recuperar(nodo);
            l_agregar(lista, elem);
        } else{
            nodos_mismoNivel(n_hijoizquierdo(nodo), lista, nivel, cont + 1);
            nodos_mismoNivel(n_hijoderecho(nodo), lista, nivel, cont + 1);  
        }
    }
}
Lista nodos_mismoNivel_inic(NodoArbol nodo){
    bool entrada = true;
    char num[TAMANO_NUM];
    int nivel;
    do {
        do {
            fflush(stdin);
            printf("Ingrese el nivel del arbol que quiere mirar: ");
            fgets(num, TAMANO_NUM, stdin);
            entrada = numEnteros(num) && validarEnter(num);
        } while (!entrada);
        nivel = pasaje_String_A_int(num);
        entrada = numeroRango(nivel, 0, altura_nodo(nodo));
    } while (!entrada);
    
    Lista listaResultado = l_crear();
    nodos_mismoNivel(nodo, listaResultado, nivel, 0);
}

/*Ejercicio 4 ---------------------------------------------------------------------------------- */
void menuPrincipalEjer4(){
    printf("                Menu principal\n\n");
    printf(" 1. (A) Recorrer un arbol mediante 'anchura' / 'niveles'.\n");
    printf(" 2. (B) Mostrar la cantidad de hojas de un arbol.\n");
    printf(" 3. (C) Determinar si dos arboles ingresados son o no SIMILARES.\n");
    printf(" 4. (D) Mostrar el padre de un nodo del arbol.\n");
    printf(" 5. (E) Mostrar los hermanos de un nodo del arbol.\n\n");
    printf(" 0.  Finalizar ejecucion...\n\n");
    printf("INGRESE UNA OPCION: ");
}

/*a*/
Lista arbolEnlistado(NodoArbol nodo){
    Lista listaResultado = l_crear();
    Cola colaAux = c_crear();
    enlistarArbolInt(listaResultado, colaAux, nodo, 0);
    return listaResultado;
}
void enlistarArbolInt(Lista lista, Cola cola, NodoArbol nodo, int nivel){
    if (a_es_rama_nula(nodo)) return;
    TipoElemento elem;
    NodoArbol nodoActual = n_crear(NULL), hijo = n_crear(NULL);
    elem = te_crear_con_valor(nodo->datos->clave, (NodoArbol) nodo);
    c_encolar(cola, elem);
    while (!c_es_vacia(cola)) {
        elem = c_desencolar(cola);
        nodoActual = (NodoArbol) elem->valor;
        l_agregar(lista, elem);
        hijo = n_hijoizquierdo(nodoActual);
        while (!a_es_rama_nula(hijo)) {
            elem = te_crear_con_valor(n_recuperar(hijo)->clave, (NodoArbol) hijo);
            c_encolar(cola, elem);
            hijo = n_hijoderecho(hijo);
        }
    }
}

/*b*/
int cantHojas_n_ario(ArbolBinario arbol){
    int cantidadHojas = 0;
    cantHojas_n_ario_Int(a_raiz(arbol), &cantidadHojas);
    return cantidadHojas;
}
void cantHojas_n_ario_Int(NodoArbol nodo, int *cantHojas){
    if (a_es_rama_nula(nodo)) return;
    else { 
        if ((n_hijoizquierdo(nodo) == NULL)){
            *cantHojas = *cantHojas + 1;
        }
        cantHojas_n_ario_Int(n_hijoizquierdo(nodo), cantHojas);
        cantHojas_n_ario_Int(n_hijoderecho(nodo), cantHojas);
    }
}

/*c*/
bool sonSimilares(NodoArbol n_arbol1, NodoArbol n_arbol2) {
    if (n_arbol1 == NULL && n_arbol2 == NULL) {
        return true;
    }
    if (n_arbol1 == NULL || n_arbol2 == NULL) {
        return false;
    }
    bool mismaEstructuraIzquierda = sonSimilares(n_hijoizquierdo(n_arbol1), n_hijoizquierdo(n_arbol2));
    bool mismaEstructuraDerecha = sonSimilares(n_hijoderecho(n_arbol1), n_hijoderecho(n_arbol2));
    return mismaEstructuraIzquierda && mismaEstructuraDerecha;
}

/*d*/
NodoArbol nodoPadre(ArbolBinario arbol, int clave){
    NodoArbol nodoRetorno, raiz;
    TipoElemento elem = te_crear(0);
    nodoRetorno = n_crear(elem);
    raiz = a_raiz(arbol);
    if (n_recuperar(raiz)->clave == clave) return NULL;
    else {
        nodoPadreInt(raiz, NULL, clave, &nodoRetorno);
        return nodoRetorno;
    }
}
void nodoPadreInt(NodoArbol nodoActual, NodoArbol nodoPadre, int clave, NodoArbol* retorno){
    if (!a_es_rama_nula(nodoActual)){
        if (n_recuperar(nodoActual)->clave == clave) *retorno = nodoPadre;
        else{
            nodoPadreInt(n_hijoizquierdo(nodoActual), nodoActual, clave, retorno);
            nodoPadreInt(n_hijoderecho(nodoActual), nodoPadre, clave, retorno);
        }
    }
}

/*e*/
Lista hermanosNodoNario(ArbolBinario arbol, int clave){
    Lista hermanos = l_crear();
    NodoArbol padreNodo = nodoPadre(arbol, clave);
    hermanosNodoNario_int(arbol, a_raiz(arbol), padreNodo, hermanos, clave);
    return hermanos;
}
void hermanosNodoNario_int(ArbolBinario arbol, NodoArbol nodo, NodoArbol padreNodo, Lista hermanos, int elementoUsuario){
    if(!a_es_rama_nula(nodo)){
        if (n_recuperar(nodo)->clave != elementoUsuario){
            NodoArbol padreNodoActual = nodoPadre(arbol, n_recuperar(nodo)->clave);
            if ( padreNodo == padreNodoActual){
                l_agregar(hermanos, n_recuperar(nodo));
            }
        }
        hermanosNodoNario_int(arbol, n_hijoizquierdo(nodo), padreNodo, hermanos, elementoUsuario);
        hermanosNodoNario_int(arbol, n_hijoderecho(nodo), padreNodo, hermanos, elementoUsuario);
    }
}

/*Ejercicio 5 ---------------------------------------------------------------------------------- */
/*Ejercicio 6 ---------------------------------------------------------------------------------- */
/*Ejercicio 7 ---------------------------------------------------------------------------------- */
bool sonEquivalentes(NodoArbol n_arbol1, NodoArbol n_arbol2) {
    if (n_arbol1 == NULL && n_arbol2 == NULL) {
        return true;
    }
    if (n_arbol1 == NULL || n_arbol2 == NULL) {
        return false;
    }
    bool mismaContenido = (n_recuperar(n_arbol1)->clave == n_recuperar(n_arbol2)->clave);
    bool mismaEstructuraIzquierda = sonEquivalentes(n_hijoizquierdo(n_arbol1), n_hijoizquierdo(n_arbol2));
    bool mismaEstructuraDerecha = sonEquivalentes(n_hijoderecho(n_arbol1), n_hijoderecho(n_arbol2));

    return mismaContenido && mismaEstructuraIzquierda && mismaEstructuraDerecha;
}

/*Ejercicio 8 ---------------------------------------------------------------------------------- */
void menuPrincipalEjer8(){
    printf("                Menu principal\n\n");
    printf(" 1. (A) Altura de un arbol.\n");
    printf(" 2. (B) Mostrar el nivel de un nodo.\n");
    printf(" 3. (C) Listar todos los nodos internos (NO RAIZ, NO HOJAS).\n");
    printf(" 4. (D) Determinar si todas las hojas de un arbol estan al mismo nivel.\n");
    printf(" 0.  Finalizar ejecucion...\n\n");
    printf("INGRESE UNA OPCION: ");
}
/*a*/
int alturaArbolNario(ArbolBinario arbol){
    int altura = 0;
    alturaArbolNarioInt(a_raiz(arbol), &altura, 0);
    return altura;
}
void alturaArbolNarioInt(NodoArbol nodo, int* altura, int cont){
    if (!a_es_rama_nula(nodo)) {
        if (cont > *altura){
            *altura = cont;
        }
        alturaArbolNarioInt(n_hijoizquierdo(nodo), altura, cont + 1);
        alturaArbolNarioInt(n_hijoderecho(nodo), altura, cont);
    }
}
/*b*/
int alturaNodoNario(ArbolBinario arbol, int clave){
    int altura = 0, cont = 0;
    alturaNodoNarioInt(a_raiz(arbol), &altura, clave, cont);
    return altura;
}
void alturaNodoNarioInt(NodoArbol nodo, int *altura, int clave, int cont){
    if (!a_es_rama_nula(nodo)) {
        if (n_recuperar(nodo)->clave == clave){
            *altura = cont;
        }
        alturaNodoNarioInt(n_hijoizquierdo(nodo), altura, clave, cont + 1);
        alturaNodoNarioInt(n_hijoderecho(nodo), altura, clave, cont);
    }
}
/*c*/ 
    Lista nodosInternosNario(ArbolBinario arbol){
        Lista listaNodos = l_crear();
        TipoElemento elem;
        nodosInternosNario_Int(listaNodos, a_raiz(arbol), elem, 0);
        return listaNodos;
    }
    void nodosInternosNario_Int(Lista lista, NodoArbol nodo, TipoElemento elem, int nivel){
        if (nodo == NULL) return;
        else { 
            if (nivel != 0){
                if (n_hijoizquierdo(nodo) != NULL){
                    elem = n_recuperar(nodo);
                    l_agregar(lista, elem);
                }
            }
            nodosInternosNario_Int(lista, n_hijoizquierdo(nodo), elem, nivel+1);
            nodosInternosNario_Int(lista, n_hijoderecho(nodo), elem, nivel);
        }
    }
/*d*/
bool hojasMismoNivelNario(ArbolBinario arbol){
    bool resultado = true;
    bool primerHoja_Encontrada = false;
    int nivel_primerHoja = 0;
    hojasMismoNivelNario_int(a_raiz(arbol), &nivel_primerHoja, primerHoja_Encontrada, &resultado, 0); // El ultimo parametro lo uso para almacenar ahi el nivel de la hoja "actual"
    return resultado;
}
void hojasMismoNivelNario_int(NodoArbol nodo, int* nivel_primerHoja, bool primerHoja_Encontrada, bool* resultado, int nivel_hojaActual){
    if (!a_es_rama_nula(nodo)) { 
        if ((n_hijoizquierdo(nodo) == NULL)){
            if (!primerHoja_Encontrada){
                primerHoja_Encontrada = true;
                *nivel_primerHoja = nivel_hojaActual;
            }
            if (*nivel_primerHoja != nivel_hojaActual) *resultado = false;
        }
        hojasMismoNivelNario_int(n_hijoizquierdo(nodo), nivel_primerHoja, primerHoja_Encontrada, resultado, nivel_hojaActual + 1);
        hojasMismoNivelNario_int(n_hijoderecho(nodo), nivel_primerHoja, primerHoja_Encontrada, resultado, nivel_hojaActual);
    }
}

/*Ejercicio 9 ---------------------------------------------------------------------------------- */
/*Ejercicio 10 --------------------------------------------------------------------------------- */
