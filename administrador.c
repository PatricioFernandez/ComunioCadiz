#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "administrador.h"
#include "fichero.h"

static void listarEquipos(Equipo*, int*);
static void modificarEquipo(Equipo*, int*);
static void agregarEquipo(Equipo*, int*);
static void eliminarEquipo(Equipo*, int*);
static void menuUsuarios(Usuario*, int*);
static void listarUsuarios(Usuario*, int*);
static void modificarUsuario(Usuario*, int*);
static void agregarUsuario(Usuario*, int*);
static void eliminarUsuario(Usuario*, int*);
static void menuConfiguracion(Conf*);
static void verConfiguracion(Conf*);
static void cambiarMaxEquipos(Conf*);
static void cambiarPresupuestoDef(Conf*);
static void cambiarMaxJugadores(Conf*);
static void menuEquipos(Equipo*, int*);

// Cabecera: void menuAdministrador()
// Precondicion:
// Poscondicion: muestra menu inicial administrador
void menuAdministrador() {
    char opcion;
    Equipo *e = obtenerEquipos();
    Usuario *u = obtenerUsuarios();
    Conf *c = obtenerConfiguraciones();
    int numEq = nEquipos();
    int numUs = nUsuarios();
    do {
        printf("\n MENU ADMINISTRADOR \n");
        puts("");
        printf("1.- Equipos\n");
        printf("2.- Usuarios\n");
        printf("3.- Configuracion\n");
        printf("4.- Salir del programa\n");
        fflush(stdin);
        fpurge(stdin);
        opcion = getchar();

        if (opcion == '1') {
            menuEquipos(e, &numEq);
        } else if (opcion == '2') {
            menuUsuarios(u, &numUs);
        } else if (opcion == '3') {
            menuConfiguracion(c);
        }
    } while (opcion != '4');
    guardarDatosEquipo(e, numEq);
    guardarDatosUsuario(u, numUs);
    guardarDatosConf(c, 3);
    exit(0);
}

// Cabecera: void menuEquipos(Equipo *e, int* numEq)
// Precondicion:
// Poscondicion: muestra por pantalla menu equipos
static void menuEquipos(Equipo *e, int* numEq) {
    char opcion;
    do {
        printf("\n EQUIPOS \n");
        puts("");
        printf("1.- Listar\n");
        printf("2.- Modificar equipo\n");
        printf("3.- Agregar equipo\n");
        printf("4.- Eliminar equipo\n");
        printf("5.- Volver\n");
        fflush(stdin);
fpurge(stdin);
        opcion = getchar();

        if (opcion == '1') {
            listarEquipos(e, numEq);
        } else if (opcion == '2') {
            modificarEquipo(e, numEq);
        } else if (opcion == '3') {
            agregarEquipo(e, numEq);
        } else if (opcion == '4') {
            eliminarEquipo(e, numEq);
        }
    } while (opcion != '5');
}

// Cabecera: void listarEquipos(Equipo *e, int* numEq)
// Precondicion:
// Poscondicion: muestra por pantalla todos los equipos
static void listarEquipos(Equipo *e, int* numEq) {
    int i;
    puts("\n <### LISTANDO EQUIPOS ###>");
    for (i = 0; i < *numEq; i++) {
        printf("%s %s\n", e[i].codigo, e[i].nombre);
    }
}

// Cabecera: void modificarEquipo(Equipo *e, int* numEq)
// Precondicion:
// Poscondicion: actualiza los datos del equipo introducido si existe
static void modificarEquipo(Equipo *e, int* numEq) {
    char codigo[3];
    char nombre[21];
    fflush(stdin);fpurge(stdin);
    puts("Introduce codigo");
    fgets(codigo, 3, stdin);
    fflush(stdin);fpurge(stdin);
    puts("Introduce nombre");
    fgets(nombre, 21, stdin);
    strtok(nombre, "\n");
    int i;
    for (i = 0; i < *numEq; i++) {
        if (strcmp(e[i].codigo, codigo) == 0) {
            strcpy(e[i].nombre, nombre);
        }
    }
}

// Cabecera: void agregarEquipo(Equipo *e, int* numEq)
// Precondicion:
// Poscondicion: agrega nuevo equipo al array e
static void agregarEquipo(Equipo *e, int* numEq) {
    char codigo[3];
    char nombre[21];
    fflush(stdin);fpurge(stdin);
    puts("Introduce codigo");
    fgets(codigo, 3, stdin);
    fflush(stdin);fpurge(stdin);
    puts("Introduce nombre");
    fgets(nombre, 21, stdin);
    strtok(nombre, "\n");
    strcpy(e[*numEq].codigo, codigo);
    strcpy(e[*numEq].nombre, nombre);
    *numEq = *numEq + 1;
}

// Cabecera: void eliminarEquipo(Equipo *e, int* numEq)
// Precondicion:
// Poscondicion: sustituye el codigo del equipo indicado por "xx"
static void eliminarEquipo(Equipo *e, int* numEq) {
    char codigo[3];
    int i;
    fpurge(stdin);fpurge(stdin);
    puts("Introduce codigo:");
    fgets(codigo, 3, stdin);
    for (i = 0; i < *numEq; i++) {
        if (strcmp(e[i].codigo, codigo) == 0) {
            strcpy(e[i].codigo, "xx\0");
            // Para eliminar se marca con "xx" el elemento que se quiere
            // eliminar. A la hora de escribir los datos en el fichero, aquellos
            // elementos que tengan codigo "xx" seran omitidos.
        }
    }
}

// Cabecera: void menuUsuarios(Usuario *u, int* numUs)
// Precondicion:
// Poscondicion: muestra por pantalla menu usuarios
static void menuUsuarios(Usuario *u, int* numUs) {
    char opcion;
    do {
        printf("\n USUARIOS \n");
        puts("");
        printf("1.- Listar\n");
        printf("2.- Modificar usuario\n");
        printf("3.- Agregar usuario\n");
        printf("4.- Eliminar usuario\n");
        printf("5.- Volver\n");
        fflush(stdin);fpurge(stdin);

        opcion = getchar();

        if (opcion == '1') {
            listarUsuarios(u, numUs);
        } else if (opcion == '2') {
            modificarUsuario(u, numUs);
        } else if (opcion == '3') {
            agregarUsuario(u, numUs);
        } else if (opcion == '4') {
            eliminarUsuario(u, numUs);
        }
    } while (opcion != '5');
}

// Cabecera: void listarUsuarios(Usuario *u, int* numUs)
// Precondicion:
// Poscondicion: muestra por pantalla todos los usuarios
static void listarUsuarios(Usuario *u, int* numUs) {
    int i;
    puts("\n <### LISTANDO USUARIOS ###>");
    for (i = 0; i < *numUs; i++) {
        printf("%s %s %s %s %s\n", u[i].codigo, u[i].nombre, u[i].tipo, u[i].login, u[i].pass);
    }
}

// Cabecera: void modificarUsuario(Usuario *u, int* numUs)
// Precondicion:
// Poscondicion: actualiza los datos del usuario introducido si existe
static void modificarUsuario(Usuario *u, int* numUs) {
    char codigo[3];
    char nombre[21];
    char login[6];
    char pass[6];
    char tipo[14];
    fflush(stdin);fpurge(stdin);
    puts("Introduce codigo");
    fgets(codigo, 3, stdin);
    fflush(stdin);fpurge(stdin);
    puts("Introduce nombre");
    fgets(nombre, 21, stdin);
    strtok(nombre, "\n");
    fflush(stdin);fpurge(stdin);
    puts("Introduce tipo");
    fgets(tipo, 14, stdin);
    strtok(tipo, "\n");
    fflush(stdin);fpurge(stdin);
    puts("Introduce login");
    fgets(login, 6, stdin);
    strtok(login, "\n");
    fflush(stdin);fpurge(stdin);
    puts("Introduce password");
    fgets(pass, 6, stdin);
    strtok(pass, "\n");
    int i;
    for (i = 0; i < *numUs; i++) {
        if (strcmp(u[i].codigo, codigo) == 0) {
            strcpy(u[i].nombre, nombre);
            strcpy(u[i].tipo, tipo);
            strcpy(u[i].login, login);
            strcpy(u[i].pass, pass);
        }
    }
}

// Cabecera: void agregarUsuario(Usuario *u, int* numUs)
// Precondicion:
// Poscondicion: agrega nuevo usuario al array u
static void agregarUsuario(Usuario *u, int* numUs) {
    char codigo[3];
    char nombre[21];
    char login[6];
    char pass[6];
    char tipo[14];
    fflush(stdin);fpurge(stdin);
    puts("Introduce codigo");
    fgets(codigo, 3, stdin);
    fflush(stdin);fpurge(stdin);
    puts("Introduce nombre");
    fgets(nombre, 21, stdin);
    strtok(nombre, "\n");
    fflush(stdin);fpurge(stdin);
    puts("Introduce tipo");
    fgets(tipo, 14, stdin);
    strtok(tipo, "\n");
    fflush(stdin);fpurge(stdin);
    puts("Introduce login");
    fgets(login, 6, stdin);
    strtok(login, "\n");
    fflush(stdin);fpurge(stdin);
    puts("Introduce password");
    fgets(pass, 6, stdin);
    strtok(pass, "\n");
    strcpy(u[*numUs].codigo, codigo);
    strcpy(u[*numUs].nombre, nombre);
    strcpy(u[*numUs].tipo, tipo);
    strcpy(u[*numUs].login, login);
    strcpy(u[*numUs].pass, pass);
    *numUs = *numUs + 1;
}

// Cabecera: void eliminarUsuario(Usuario *u, int* numUs)
// Precondicion:
// Poscondicion: sustituye el codigo del usuario indicado por "xx"
static void eliminarUsuario(Usuario *u, int* numUs) {
    char codigo[3];
    int i;
    fflush(stdin);fpurge(stdin);
    puts("Introduce codigo:");
    fgets(codigo, 3, stdin);
    for (i = 0; i < *numUs; i++) {
        if (strcmp(u[i].codigo, codigo) == 0) {
            strcpy(u[i].codigo, "xx\0");
            // Para eliminar se marca con "xx" el elemento que se quiere
            // eliminar. A la hora de escribir los datos en el fichero, aquellos
            // elementos que tengan codigo "xx" seran omitidos.
        }
    }
}

// Cabecera: void menuConfiguracion(Conf* c)
// Precondicion:
// Poscondicion: muestra por pantalla menu configuracion
static void menuConfiguracion(Conf* c) {
    char opcion;
    do {
        printf("\n Configuracion \n");
        puts("");
        printf("1.- Ver configuracion actual\n");
        printf("2.- Cambiar equipos maximos\n");
        printf("3.- Cambiar presupuesto por defecto\n");
        printf("4.- Cambiar jugadores maximos\n");
        printf("5.- Volver\n");
        fflush(stdin);fpurge(stdin);

        opcion = getchar();

        if (opcion == '1') {
            verConfiguracion(c);
        } else if (opcion == '2') {
            cambiarMaxEquipos(c);
        } else if (opcion == '3') {
            cambiarPresupuestoDef(c);
        } else if (opcion == '4') {
            cambiarMaxJugadores(c);
        }
    } while (opcion != '5');
}

// Cabecera: void verConfiguracion(Conf* c)
// Precondicion:
// Poscondicion: muestra por pantalla los parametros actuales
static void verConfiguracion(Conf* c) {
    printf("Numero maximo de equipos: %d\n", c[0].valor);
    printf("Presupuesto por defecto: %d\n", c[1].valor);
    printf("Numero maximo de jugadores: %d\n", c[2].valor);
}

// Cabecera: void cambiarMaxEquipos(Conf* c)
// Precondicion:
// Poscondicion: actualiza el parametro max equipos
static void cambiarMaxEquipos(Conf* c) {
    puts("Introduce numero maximo de equipos:");
    fflush(stdin);fpurge(stdin);
    scanf("%d", &c[0].valor);
}

// Cabecera: void cambiarPresupuestoDef(Conf* c)
// Precondicion:
// Poscondicion: actualiza el parametro presupuesto def
static void cambiarPresupuestoDef(Conf* c) {
    puts("Introduce presupuesto por defecto:");
    fflush(stdin);fpurge(stdin);
    scanf("%d", &c[1].valor);
}

// Cabecera: void cambiarMaxJugadores(Conf* c)
// Precondicion:
// Poscondicion: actualiza el parametro max jugadores
static void cambiarMaxJugadores(Conf* c) {
    puts("Introduce numero maximo de jugadores:");
    fflush(stdin);fpurge(stdin);
    scanf("%d", &c[2].valor);
}