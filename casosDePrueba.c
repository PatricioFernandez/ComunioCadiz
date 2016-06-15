#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "fichero.h"
/*


 */
int main(){

    puts("### MODULO: fichero, FUNCION: loguear ###");
    char *cod = loguear("admin","jp1234");
    if(strcmp(cod, "00") != 0){
        printf("Usaurio existente, contaseña correcta, resultado: OK\n");
    }else{
        printf("Usaurio existente, contaseña correcta, resultado: ERROR\n");
    }
    cod = loguear("admin","jp4321");
    if(strcmp(cod, "00") == 0){
        printf("Usaurio existente, contaseña erronea, resultado: OK\n");
    }else{
        printf("Usaurio existente, contaseña erronea, resultado: ERROR\n");
    }
    cod = loguear("croni","jp1234");
    if(strcmp(cod, "00") != 0){
        printf("Usaurio existente, contaseña de otro usuario, resultado: OK\n");
    }else{
        printf("Usaurio existente, contaseña de otro usuario, resultado: ERROR\n");
    }
    cod = loguear("croni","jp1234");
    if(strcmp(cod, "00") != 0){
        printf("Usaurio existente, contaseña de otro usuario, resultado: OK\n");
    }else{
        printf("Usaurio existente, contaseña de otro usuario, resultado: ERROR\n");
    }
    cod = loguear("","");
    if(strcmp(cod, "00") == 0){
        printf("Usaurio vacio, contaseña vacia, resultado: OK\n");
    }else{
        printf("Usaurio vacio, contaseña vacia, resultado: ERROR\n");
    }

    /*Estas interacciones no quedan guardadas en los archivos para guardarlo llamar al final a salvardatos()*/
    puts("### MODULO: usuario, FUNCION: crear plantilla ###");
    inicializarDatos();
    crearPlantilla('005');
    puts("###FUNCION: borrar plantilla ###");
    BorrarPlantilla();
    return 0;
}
