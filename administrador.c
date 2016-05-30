#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "administrador.h"
#include "fichero.h"

void listarEquipos();
void modificarEquipo();
void modificarJugador();
void agregarEquipo();
void agregarJugador();
void eliminarEquipo();
void eliminarJugador();
void menuUsuarios();
void menuConfiguracion();
void menuEquipos();

void menuAdministrador(){
    printf("\n MENU ADMINISTRADOR \n");
    puts("");
    printf("1.- Equipos\n");
    printf("2.- Usuarios\n");
    printf("3.- Configuracion\n");
    printf("4.- Salir del programa\n");
    
    char opcion = getchar();
    
    if(opcion == '1'){
        menuEquipos();
    }else if(opcion == '2'){
        menuUsuarios();
    }else if(opcion == '3'){
        menuConfiguracion();
    }else{
        exit(0);
    }
}

void menuEquipos(){
    printf("\n EQUIPOS \n");
    puts("");
    printf("1.- Listar\n");
    printf("2.- Modificar equipo\n");
    printf("3.- Modificar jugador\n");
    printf("4.- Agregar equipo\n");
    printf("5.- Agregar jugador\n");
    printf("6.- Eliminar equipo\n");
    printf("7.- Eliminar jugador\n");
    printf("8.- Volver\n");
    
    fpurge(stdin);
    fflush(stdin);
    
    char opcion = getchar();
    
    if(opcion == '1'){
        listarEquipos();
    }else if(opcion == '2'){
        modificarEquipo();
    }else if(opcion == '3'){
        modificarJugador();
    }else if(opcion == '4'){
        agregarEquipo();
    }else if(opcion == '5'){
        agregarJugador();
    }else if(opcion == '6'){
        eliminarEquipo();
    }else if(opcion == '7'){
        eliminarJugador();
    }else if(opcion == '8'){
        menuAdministrador();
    }
}

void listarEquipos(){
    Equipo *e = obtenerEquipos();
    int dimension = nEquipos();
    int i;
    puts("\n LISTANDO EQUIPOS");
    for(i = 0; i < dimension; i++){
        printf("%s %s\n", e[i].codigo, e[i].nombre);
    }
    menuEquipos();
}

void modificarEquipo(){
    puts("Introduce codigo de equipo:");
    fflush(stdin);
    fpurge(stdin);
    char codigo[3];
    fgets(codigo, 3, stdin);
    puts("Introduce nuevo nombre para el equipo:");
    fflush(stdin);
    fpurge(stdin);
    char nombre[21];
    fgets(nombre, 21, stdin);
    Equipo *e = obtenerEquipos();
    int dimension = nEquipos();
    int i;
    for(i = 0; i < dimension; i++){
        if(strcmp(e[i].codigo, codigo) == 0)
            strcpy(e[i].nombre, nombre);
    }
    guardarDatosEquipo(e, dimension);
    menuEquipos();
}

void modificarJugador(){
    
}

void agregarEquipo(){
    
}

void agregarJugador(){
    
}

void eliminarEquipo(){
    
}

void eliminarJugador(){
    
}

void menuUsuarios(){
    
}

void menuConfiguracion(){
    
}