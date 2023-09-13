
#include "hash.h"
#include <stdio.h>



int main() {
    int tamanio = 10;
    Tabla *tabla = crearTABLA(tamanio);


    insertarNOMBRE(tabla, "Juan");
    insertarNOMBRE(tabla, "Maria");
    insertarNOMBRE(tabla, "Carla");
    insertarNOMBRE(tabla,"Carla");

     char nombre[10] ="carla";

    if (miembro(tabla,nombre)) {
        printf(" %s se encuentra en la tabla.\n",nombre);
    } else {
        printf("%s No se encuentra en la tabla.\n",nombre);
    }

    imprimirTabla(tabla);
    eliminarNOMBRE(tabla,nombre);
    printf("LUEGO DE ELIMINAR:\n");
    imprimirTabla(tabla);


    return 0;
}










