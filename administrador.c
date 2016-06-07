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
void listarUsuarios();
void modificarUsuario();
void agregarUsuario();
void eliminarUsuario();
void menuConfiguracion();
void verConfiguracion();
void cambiarMaxEquipos();
void cambiarPresupuestoDef();
void cambiarMaxJugadores();
void menuEquipos();

void menuAdministrador(){
    printf("\n MENU ADMINISTRADOR \n");
    puts("");
    printf("1.- Equipos\n");
    printf("2.- Usuarios\n");
    printf("3.- Configuracion\n");
    printf("4.- Salir del programa\n");
    
    fpurge(stdin);
    fflush(stdin);
    
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
    puts("\n <### LISTANDO EQUIPOS ###>");
    for(i = 0; i < dimension; i++){
        printf("%s %s\n", e[i].codigo, e[i].nombre);
    }
    menuEquipos();
}

void modificarEquipo(){
    char codigo[3];
    char nombre[21];
    fpurge(stdin);
    puts("Introduce codigo");
    fgets(codigo, 3, stdin);
    fpurge(stdin);
    puts("Introduce nombre");
    fgets(nombre, 21, stdin);
    strtok(nombre, "\n");
    Equipo *e = obtenerEquipos();
    int dimension = nEquipos();
    int i;
    for(i = 0; i < dimension; i++){
        if(strcmp(e[i].codigo, codigo) == 0){
            strcpy(e[i].nombre, nombre);
        }
    }
    guardarDatosEquipo(e, i);
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
    printf("\n USUARIOS \n");
    puts("");
    printf("1.- Listar\n");
    printf("2.- Modificar usuario\n");
    printf("3.- Agregar usuario\n");
    printf("4.- Eliminar usuario\n");
    printf("5.- Volver\n");
    
    fpurge(stdin);
    fflush(stdin);
    
    char opcion = getchar();
    
    if(opcion == '1'){
        listarUsuarios();
    }else if(opcion == '2'){
        modificarUsuario();
    }else if(opcion == '3'){
        agregarUsuario();
    }else if(opcion == '4'){
        eliminarUsuario();
    }else if(opcion == '5'){
        menuAdministrador();
    }
}

void listarUsuarios(){
    
}

void modificarUsuario(){
    
}

void agregarUsuario(){
    
}

void eliminarUsuario(){
    
}

void menuConfiguracion(){
    printf("\n Configuracion \n");
    puts("");
    printf("1.- Ver configuracion actual\n");
    printf("2.- Cambiar equipos maximos\n");
    printf("3.- Cambiar presupuesto por defecto\n");
    printf("4.- Cambiar jugadores maximos\n");
    printf("5.- Volver\n");
    
    fpurge(stdin);
    fflush(stdin);
    
    char opcion = getchar();
    
    if(opcion == '1'){
        verConfiguracion();
    }else if(opcion == '2'){
        cambiarMaxEquipos();
    }else if(opcion == '3'){
        cambiarPresupuestoDef();
    }else if(opcion == '4'){
        cambiarMaxJugadores();
    }else if(opcion == '5'){
        menuAdministrador();
    }
}

void verConfiguracion(){
    Conf *config = obtenerConfiguraciones();
    printf("Numero maximo de equipos: %d\n", config[0].valor);
    printf("Presupuesto por defecto: %d\n", config[1].valor);
    printf("Numero maximo de jugadores: %d\n", config[2].valor);
    menuConfiguracion();
}

void cambiarMaxEquipos(){
    Conf *config = obtenerConfiguraciones();
    puts("Introduce numero maximo de equipos:");
    fpurge(stdin);
    fflush(stdin);
    scanf("%d", &config[0].valor);
    guardarDatosConf(config, 3);
    menuConfiguracion();
}

void cambiarPresupuestoDef(){
    Conf *config = obtenerConfiguraciones();
    puts("Introduce presupuesto por defecto:");
    fpurge(stdin);
    fflush(stdin);
    scanf("%d", &config[1].valor);
    guardarDatosConf(config, 3);
    menuConfiguracion();
}

void cambiarMaxJugadores(){
    Conf *config = obtenerConfiguraciones();
    puts("Introduce numero maximo de jugadores:");
    fpurge(stdin);
    fflush(stdin);
    scanf("%d", &config[2].valor);
    guardarDatosConf(config, 3);
    menuConfiguracion();
}