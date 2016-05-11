#include "fichero.h"
#include <string.h>
#include <stdio.h>


// CONSTANTES

FILE *FICHERO_USUARIO;
FILE *FICHERO_EQUIPO;
FILE *FICHERO_JUGADOR;
FILE *FICHERO_PLANTILLA;
FILE *FICHERO_JUG_PLAN;

char *DATOS_USUARIO;
char *DATOS_EQUIPO;
char *DATOS_JUGADOR;
char *DATOS_PLANTILLA;
char *DATOS_JUG_PLAN;

// FUNCIONES INTERNAS

static int abrirFicheros(){
    int res = 0;
    FICHERO_USUARIO = fopen("usuarios.txt", "w");
    FICHERO_EQUIPO = fopen("equipos.txt", "w");
    FICHERO_JUGADOR = fopen("futbolistas.txt", "w");
    FICHERO_PLANTILLA = fopen("plantillas.txt", "w");
    FICHERO_JUG_PLAN = fopen("jugadores_plantillas.txt", "w");
    if(FICHERO_USUARIO == NULL) res = 1;
    if(FICHERO_EQUIPO == NULL) res = 1;
    if(FICHERO_JUGADOR == NULL) res = 1;
    if(FICHERO_PLANTILLA == NULL) res = 1;
    if(FICHERO_JUG_PLAN == NULL) res = 1;
    return res;
}

static void cargarDatos(){
    cargarDato(FICHERO_USUARIO, DATOS_USUARIO);
    cargarDato(FICHERO_EQUIPO, DATOS_EQUIPO);
    cargarDato(FICHERO_JUGADOR, DATOS_JUGADOR);
    cargarDato(FICHERO_PLANTILLA, DATOS_PLANTILLA);
    cargarDato(FICHERO_JUG_PLAN, DATOS_JUG_PLAN);
}

static void cargarDato(FILE f, char* datos){
    char c;
    int res = 0;
    int contador = 0;
    datos = (char*) malloc(sizeof(char));
    while((c = getc(f)) != EOF){
        contador++;
        datos = (char*) realloc(sizeof(char)*contador);
        daots[contador-1] = c;
    }
}

static void cerrarFicheros(){
    
    // ANTES DE CERRAR GUARDAR LOS CAMBIOS
    fclose(FICHERO_USUARIO);
    fclose(FICHERO_EQUIPO);
    fclose(FICHERO_JUGADOR);
    fclose(FICHERO_PLANTILLA);
    fclose(FICHERO_JUG_PLAN);
}

// FUNCIONES PUBLICAS

int empezar(){
    int res = abrirFicheros();
    return res;
}