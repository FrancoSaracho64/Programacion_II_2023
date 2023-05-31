#include "arbol-Utilidades.h"


void a_cargar_binario(ArbolBinario arbol){
    printf("Carga de ARBOL BINARIO...\n\n *IMPORTANTE...\nInsertar un punto ' . ' para cargar un NULL.\n");
    printf("-----------------------------------------------------------\n");
    a_cargar_binario_Int(arbol, NULL, 0, 0);
}

void a_cargar_binario_Int(ArbolBinario A, NodoArbol nodo_1, int sa, int altura){
    TipoElemento X;
    NodoArbol nodo;
    int numero;
    bool entrada, nulo = false;
    char num [TAMANO_NUM];

    if(!a_es_lleno(A)){
        do{
            fflush(stdin);
            if (a_cantidad_elementos(A) == 0){
                printf("\nIngrese el elemento de la RAIZ del arbol: ");
            } else {
                if(sa == -1){
                    printf("Ingrese el hijo IZQUIERDO de %d  [NIVEL--> %d]: ",nodo_1->datos->clave , altura);
                } else printf("Ingrese el hijo DERECHO de %d  [NIVEL--> %d]: ",nodo_1->datos->clave , altura);
            }
            fgets(num, TAMANO_NUM, stdin);
            entrada = esUnNulo(num) && validarEnter(num);
            nulo = entrada;
            if (!entrada) entrada = numEnteros(num) && validarEnter(num);
        } while (!entrada);

        if (!nulo){
            numero = pasaje_String_A_int(num);
            if (entrada){
                X = te_crear(numero);
                
                if(sa == -1) nodo = a_conectar_hi(A, nodo_1, X);
                else if(sa == 1) nodo = a_conectar_hd(A, nodo_1, X);
                else nodo = a_establecer_raiz(A, X);

                a_cargar_binario_Int(A, nodo, -1, altura + 1);
                a_cargar_binario_Int(A, nodo, 1, altura + 1);
            }
        }
    }    
}

void a_cargar_n_ario(ArbolBinario arbol){
    printf("Carga de ARBOL n-ario...\n\n *IMPORTANTE...\nInsertar un punto ' . ' para cargar un NULL.\n");
    printf("-----------------------------------------------------------\n");
    a_cargar_n_ario_Int(arbol, NULL, 0, 0);
}

void a_cargar_n_ario_Int(ArbolBinario A, NodoArbol nodo_1, int sa, int altura){
    TipoElemento X;
    NodoArbol nodo;
    int numero;
    bool entrada, nulo = false;

    char num [TAMANO_NUM];

    if(!a_es_lleno(A)){

        do{
            fflush(stdin);
            if (a_cantidad_elementos(A) == 0){
                printf("\nIngrese el elemento de la RAIZ del arbol: ");
            } else {
                if (altura == 0 && sa == 1){
                    return;
                }

                if(sa == -1){
                    printf("Ingrese el elemento de IZQUIERDA [NIVEL--> %d]: ", altura);
                } else printf("Ingrese el elemento de DERECHA [NIVEL--> %d]: ", altura);
            }
            fgets(num, TAMANO_NUM, stdin);
            entrada = esUnNulo(num) && validarEnter(num);
            nulo = entrada;
            if (!entrada) entrada = numEnteros(num) && validarEnter(num);
        } while (!entrada);

        if (!nulo){
            numero = pasaje_String_A_int(num);
            if (entrada){
                X = te_crear(numero);
                
                if(sa == -1) nodo = a_conectar_hi(A, nodo_1, X);
                else if(sa == 1) nodo = a_conectar_hd(A, nodo_1, X);
                else nodo = a_establecer_raiz(A, X);

                a_cargar_n_ario_Int(A, nodo, -1, altura + 1);
                a_cargar_n_ario_Int(A, nodo, 1, altura);
            }
        }
    }    
}