#include "fichero.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// CONSTANTES

FILE *FICHERO_USUARIO;
FILE *FICHERO_EQUIPO;
FILE *FICHERO_JUGADOR;
FILE *FICHERO_PLANTILLA;
FILE *FICHERO_JUG_PLAN;

int N_USUARIO = 0;
int N_EQUIPO = 0;
int N_JUGADOR = 0;
int N_PLANTILLA = 0;
int N_JUG_PLANT = 0;

// FUNCIONES INTERNAS

// Cabecera: int abrirFicheros()
// Precondicion:
// Poscondicion:
int abrirFicheros(){
    int res = 0;
    FICHERO_USUARIO = fopen("usuarios.txt", "r+");
    FICHERO_EQUIPO = fopen("equipos.txt", "r+");
    FICHERO_JUGADOR = fopen("futbolistas.txt", "r+");
    FICHERO_PLANTILLA = fopen("plantillas.txt", "r+");
    FICHERO_JUG_PLAN = fopen("jugadores_plantillas.txt", "r+");
    if(FICHERO_USUARIO == NULL
            || FICHERO_EQUIPO == NULL
            || FICHERO_JUGADOR == NULL
            || FICHERO_PLANTILLA == NULL
            || FICHERO_JUG_PLAN == NULL) res = 1;
    return res;
}

// Cabecera: int abrirFicheros()
// Precondicion:
// Poscondicion:
void cerrarFicheros(){
    
    // ANTES DE CERRAR GUARDAR LOS CAMBIOS
    fclose(FICHERO_USUARIO);
    fclose(FICHERO_EQUIPO);
    fclose(FICHERO_JUGADOR);
    fclose(FICHERO_PLANTILLA);
    fclose(FICHERO_JUG_PLAN);
}

Equipo obtenerEquipo(char *cadena){
    Equipo e;
    sscanf(cadena,"%s%s", e.codigo, e.nombre);
    return e;
}

Jugador obtenerJugador(char *cadena){
    Jugador j;
    sscanf(cadena,"%s%s%s%d%d", j.codigo, j.codigo_equipo, j.nombre, &j.precio, &j.valoracion);
    return j;
}

Usuario obtenerUsuario(char *cadena){
    Usuario u;
    sscanf(cadena,"%s%s%s%s%s", u.codigo, u.login, u.nombre, u.pass, u.tipo);
    return u;
}

Plantilla obtenerPlantilla(char* cadena){
    Plantilla p;
    sscanf(cadena, "%s%s%s%d%d", p.codigo_usuario, p.codigo, p.nombre, &p.presupuesto, &p.puntuacion);
    return p;
}

Jug_plan obtenerJugPlan(char* cadena){
    Jug_plan jp;
    sscanf(cadena, "%s%s", jp.codigo_jugador, jp.codigo_plantilla);
    return jp;
}
// FUNCIONES PUBLICAS

// Cabecera: int empezar()
// Precondicion:
// Poscondicion:
int empezar(){
    int res = abrirFicheros();
    return res;
}

// Cabecera: Equipo* obtenerEquipos()
// Precondicion:
// Poscondicion:
Equipo* obtenerEquipos(){
    char c;
    char *cadena = (char*) malloc(sizeof(char));
    int contadorChar = 0;
    Equipo *e = (Equipo*) malloc(sizeof(Equipo));
    while((c = fgetc(FICHERO_EQUIPO))!=EOF){
        if(c == '\n'){
            N_EQUIPO++;
            e = (Equipo*) realloc(e, N_EQUIPO*sizeof(Equipo));
            e[N_EQUIPO-1] = obtenerEquipo(cadena);
            contadorChar = 0;
            cadena = (char*) calloc(1, sizeof(char));
        }else{
            contadorChar++;
            cadena = (char*) realloc(cadena, (contadorChar)*sizeof(char));
            cadena[contadorChar-1] = c;
        }
    }
    N_EQUIPO++;
    e = (Equipo*) realloc(e, N_EQUIPO*sizeof(Equipo));
    e[N_EQUIPO-1] = obtenerEquipo(cadena);
    contadorChar = 0;
    cadena = (char*) calloc(1, sizeof(char));
    return e;  
}

// Cabecera: Jugador* obtenerJugadores()
// Precondicion:
// Poscondicion:
Jugador* obtenerJugadores(){
    char c;
    char *cadena = (char*) malloc(sizeof(char));
    int contadorChar = 0;
    Jugador *j = (Jugador*) malloc(sizeof(Jugador));
    while((c = fgetc(FICHERO_JUGADOR))!=EOF){
        if(c == '\n'){
            N_JUGADOR++;
            j = (Jugador*) realloc(j, N_JUGADOR*sizeof(Jugador));
            j[N_JUGADOR-1] = obtenerJugador(cadena);
            contadorChar = 0;
            cadena = (char*) calloc(1, sizeof(char));
        }else{
            contadorChar++;
            cadena = (char*) realloc(cadena, (contadorChar)*sizeof(char));
            cadena[contadorChar-1] = c;
        }
    }
    N_JUGADOR++;
    j = (Jugador*) realloc(j, N_JUGADOR*sizeof(Jugador));
    j[N_JUGADOR-1] = obtenerJugador(cadena);
    contadorChar = 0;
    cadena = (char*) calloc(1, sizeof(char));
    return j;  
}

// Cabecera: Usuario* obtenerUsuarios()
// Precondicion:
// Poscondicion:
Usuario* obtenerUsuarios(){
    char c;
    char *cadena = (char*) malloc(sizeof(char));
    int contadorChar = 0;
    Usuario *u = (Usuario*) malloc(sizeof(Usuario));
    while((c = fgetc(FICHERO_USUARIO))!=EOF){
        if(c == '\n'){
            N_USUARIO++;
            u = (Usuario*) realloc(u, N_USUARIO*sizeof(Usuario));
            u[N_USUARIO-1] = obtenerUsuario(cadena);
            contadorChar = 0;
            cadena = (char*) calloc(1, sizeof(char));
        }else{
            contadorChar++;
            cadena = (char*) realloc(cadena, (contadorChar)*sizeof(char));
            cadena[contadorChar-1] = c;
        }
    }
    N_USUARIO++;
    u = (Usuario*) realloc(u, N_USUARIO*sizeof(Usuario));
    u[N_USUARIO-1] = obtenerUsuario(cadena);
    contadorChar = 0;
    cadena = (char*) calloc(1, sizeof(char));
    return u;  
}

// Cabecera: Plantilla* obtenerPlantillas()
// Precondicion:
// Poscondicion:
Plantilla* obtenerPlantillas(){
    char c;
    char *cadena = (char*) malloc(sizeof(char));
    int contadorChar = 0;
    Plantilla *p = (Plantilla*) malloc(sizeof(Plantilla));
    while((c = fgetc(FICHERO_PLANTILLA))!=EOF){
        if(c == '\n'){
            N_PLANTILLA++;
            p = (Plantilla*) realloc(p, N_PLANTILLA*sizeof(Plantilla));
            p[N_PLANTILLA-1] = obtenerPlantilla(cadena);
            contadorChar = 0;
            cadena = (char*) calloc(1, sizeof(char));
        }else{
            contadorChar++;
            cadena = (char*) realloc(cadena, (contadorChar)*sizeof(char));
            cadena[contadorChar-1] = c;
        }
    }
    N_PLANTILLA++;
    p = (Plantilla*) realloc(p, N_PLANTILLA*sizeof(Plantilla));
    p[N_PLANTILLA-1] = obtenerPlantilla(cadena);
    contadorChar = 0;
    cadena = (char*) calloc(1, sizeof(char));
    return p; 
}

// Cabecera: Jug_plan* obtenerJugadoresPlantillas()
// Precondicion:
// Poscondicion:
Jug_plan* obtenerJugadoresPlantillas(){
    char c;
    char *cadena = (char*) malloc(sizeof(char));
    int contadorChar = 0;
    Jug_plan *p = (Jug_plan*) malloc(sizeof(Jug_plan));
    while((c = fgetc(FICHERO_JUG_PLAN))!=EOF){
        if(c == '\n'){
            N_JUG_PLANT++;
            p = (Jug_plan*) realloc(p, N_JUG_PLANT*sizeof(Jug_plan));
            p[N_JUG_PLANT-1] = obtenerJugPlan(cadena);
            contadorChar = 0;
            cadena = (char*) calloc(1, sizeof(char));
        }else{
            contadorChar++;
            cadena = (char*) realloc(cadena, (contadorChar)*sizeof(char));
            cadena[contadorChar-1] = c;
        }
    }
    N_JUG_PLANT++;
    p = (Jug_plan*) realloc(p, N_JUG_PLANT*sizeof(Jug_plan));
    p[N_JUG_PLANT-1] = obtenerJugPlan(cadena);
    contadorChar = 0;
    cadena = (char*) calloc(1, sizeof(char));
    return p; 
}

int nUsuarios(){
    return N_USUARIO;
}

int nEquipos(){
    return N_EQUIPO;
}

int nJugadores(){
    return N_JUGADOR;
}

int nPlantillas(){
    return N_PLANTILLA;
}

int nJugPlants(){
    return N_JUG_PLANT;
}

void guardarDatosEquipos(Equipo* equipos){
    
}