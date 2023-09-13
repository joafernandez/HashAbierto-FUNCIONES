
#include "hash.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Nodo * crearnodo(Nodo*siguiente, char *nombre){
    Nodo* nuevo= (Nodo*) malloc(sizeof (Nodo));
    if(nuevo==NULL){
        exit(-1);
    }
    strcpy(nuevo->nombre,nombre);
    nuevo->siguiente=NULL; //es lo q dice mi estruct
    return nuevo;
}
Tabla *crearTABLA( int tamanio) {
    Tabla *tabla = (Tabla *) malloc(sizeof(Tabla));  //creo  la tabla sola
    tabla->tamanio = tamanio;
    tabla->listas = (Nodo **) malloc(sizeof(Nodo *) * tamanio); //creo los nodos de la lista

    //recorro la tabla con i y la inicio,todavia esta vacia asiq se comporta como vector
    for (int i = 0; i < tamanio; i++) {
        tabla->listas[i] = NULL;
    }
    return tabla;
}
int hash(Tabla *tabla,char *nombre){
    int suma=0;
    for (int i = 0; nombre[i]!='\0'; ++i) {
                suma+= nombre[i];
    }
    return suma%tabla->tamanio;

}
//ubica los nodos primeros
void insertarPrimero( Nodo **nodo,char *nombre){  //le paso la ubicacion del 1er ndod
    *nodo= crearnodo(*nodo,nombre); //aca lo inserto primero
}
void insertarNOMBRE(Tabla* tabla, char *nombre){
   int pos= hash(tabla,nombre);
    insertarPrimero(&tabla->listas[pos],nombre); //le paso la direccion xq son muchas listas
}
int miembro(Tabla *tabla,char *nombre ){
    int posicion=hash(tabla,nombre);
    Nodo *aux = tabla->listas[posicion];
    while(aux !=NULL && strcpy(aux->nombre,nombre)!=0) {
        aux = aux->siguiente;
    }
    return aux != NULL;

}
void eliminarNODO( Nodo**nodo,char*nombre ) {
        if(*nodo != NULL) {  //*nodo es el primero
            if(strcmp((*nodo)->nombre, nombre) == 0) {
                Nodo  * eliminada = *nodo;
                *nodo = (*nodo)->siguiente;
                free(eliminada);
            } else {
                Nodo *act = *nodo;
                Nodo *siguiente = act->siguiente;
                while(siguiente != NULL && strcmp(siguiente->nombre, nombre) != 0) {
                    act = siguiente;
                    siguiente = act->siguiente;
                }
                if(siguiente != NULL) {
                    Nodo *eliminada = siguiente;
                    act->siguiente = siguiente->siguiente;
                    free(eliminada);

                }
            }
        }
    }

void eliminarNOMBRE(Tabla* tabla, char *nombre ) {
    int pos = hash(tabla,nombre);
    eliminarNODO(&tabla->listas[pos], nombre);
}

void imprimirTabla(Tabla*tabla) {//recorro como vector
    for (int i = 0; i<tabla->tamanio; i++) {
        printf("%d:", i);
        imprimirLista(tabla->listas[i]);
    }
}
void imprimirLista(Nodo *nodo) {
    while (nodo != NULL) {
        printf("%s\n", nodo->nombre);
        nodo = nodo->siguiente;
    }
    printf("\n");
}




