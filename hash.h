
#include "stdio.h"



typedef struct Nodo{
    char nombre[20];
    struct nodo *siguiente;
} Nodo;


typedef struct Tabla{
   Nodo * *listas; //coleccion de listas(punteros) a nodos
    int tamanio;
} Tabla;

Nodo  *crearnodo(Nodo *siguiente,char *nombre);

Tabla *crearTABLA( int tamanio);

int hash(Tabla *tabla,char *nombre);

void insertarPrimero( Nodo **nodo,char *nombre); //puedo unificar?

void insertarNOMBRE(Tabla* tabla, char *nombre);

int miembro(Tabla *tabla,char *nombre );

void eliminarNODO( Nodo**nodo,char*nombre );  //puedo unificar?

void eliminarNOMBRE(Tabla* tabla, char *nombre );

void imprimirTabla(Tabla*tabla);

void imprimirLista(Nodo *nodo);

#ifndef HASHABIERTO_FUNCIONES_HASH_H
#define HASHABIERTO_FUNCIONES_HASH_H

#endif //HASHABIERTO_FUNCIONES_HASH_H
