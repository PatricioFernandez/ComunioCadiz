#include "fichero.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// CONSTANTES
int N_USUARIO = 0;
int N_EQUIPO = 0;
int N_JUGADOR = 0;
int N_PLANTILLA = 0;
int N_JUG_PLANT = 0;

// Cabecera: Equipo obtenerEquipo(char *cadena)
// Precondicion:
// Poscondicion:
Equipo obtenerEquipo(char *cadena){
    Equipo e;
    sscanf(cadena,"%s%s", e.codigo, e.nombre);
    return e;
}
// Cabecera: Jugador obtenerJugador(char *cadena)
// Precondicion:
// Poscondicion:
Jugador obtenerJugador(char *cadena){
    Jugador j;
    sscanf(cadena,"%s%s%s%d%d", j.codigo, j.codigo_equipo, j.nombre, &j.precio, &j.valoracion);
    return j;
}
// Cabecera: Usuario obtenerUsuario(char *cadena)
// Precondicion:
// Poscondicion:
Usuario obtenerUsuario(char *cadena){
    Usuario u;
    sscanf(cadena,"%s%s%s%s%s", u.codigo, u.nombre, u.tipo, u.login, u.pass);
    return u;
}
// Cabecera: Plantilla obtenerPlantilla(char* cadena)
// Precondicion:
// Poscondicion:
Plantilla obtenerPlantilla(char* cadena){
    Plantilla p;
    sscanf(cadena, "%s%s%s%d%d", p.codigo_usuario, p.codigo, p.nombre, &p.presupuesto, &p.puntuacion);
    return p;
}
// Cabecera: Jug_plan obtenerJugPlan(char* cadena)
// Precondicion:
// Poscondicion:
Jug_plan obtenerJugPlan(char* cadena){
    Jug_plan jp;
    sscanf(cadena, "%s%s", jp.codigo_jugador, jp.codigo_plantilla);
    return jp;
}
// Cabecera: Conf obtenerConfiguracion(char* cadena)
// Precondicion:
// Poscondicion:
Conf obtenerConfiguracion(char* cadena){
    Conf c;
    sscanf(cadena, "%s%d", c.campo, &c.valor);
    return c;
}
// FUNCIONES PUBLICAS


// Cabecera: Equipo* obtenerEquipos()
// Precondicion:
// Poscondicion:
Equipo* obtenerEquipos(){
    N_EQUIPO = 0;
    FILE *FICHERO_EQUIPO = fopen("equipos.txt", "r");
    char c;
    char *cadena = (char*) calloc(1,sizeof(char));
    int contadorChar = 0;
    Equipo *e = (Equipo*) calloc(1,sizeof(Equipo));
    while((c = fgetc(FICHERO_EQUIPO))!=EOF){
        if(c == '\n'){
            N_EQUIPO++;
            e = (Equipo*) realloc(e, N_EQUIPO*sizeof(Equipo));
            cadena = (char*) realloc(cadena, (contadorChar+1)*sizeof(char));
            cadena[contadorChar] = '\0';
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
    cadena = (char*) realloc(cadena, (contadorChar+1)*sizeof(char));
    cadena[contadorChar] = '\0';
    e[N_EQUIPO-1] = obtenerEquipo(cadena);
    contadorChar = 0;
    cadena = (char*) calloc(1, sizeof(char));
    fclose(FICHERO_EQUIPO);
    return e;  
}

// Cabecera: Jugador* obtenerJugadores()
// Precondicion:
// Poscondicion:
Jugador* obtenerJugadores(){
    N_JUGADOR = 0;
    FILE *FICHERO_JUGADOR = fopen("futbolistas.txt", "r");
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
    fclose(FICHERO_JUGADOR);
    return j;  
}

// Cabecera: Usuario* obtenerUsuarios()
// Precondicion:
// Poscondicion:
Usuario* obtenerUsuarios(){
    N_USUARIO = 0;
    FILE *FICHERO_USUARIO = fopen("usuarios.txt", "r");
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
    fclose(FICHERO_USUARIO);
    return u;  
}

// Cabecera: Plantilla* obtenerPlantillas()
// Precondicion:
// Poscondicion:
Plantilla* obtenerPlantillas(){
    N_PLANTILLA = 0;
    FILE *FICHERO_PLANTILLA = fopen("plantillas.txt", "r");
    char c;
    char *cadena = (char*) calloc(1,sizeof(char));
    int contadorChar = 0;
    Plantilla *p = (Plantilla*) calloc(1,sizeof(Plantilla));
    while((c = fgetc(FICHERO_PLANTILLA))!=EOF){
        if(c == '\n'){
            N_PLANTILLA++;
            p = (Plantilla*) realloc(p, N_PLANTILLA*sizeof(Plantilla));
            cadena = (char*) realloc(cadena, (contadorChar+1)*sizeof(char));
            cadena[contadorChar] = '\0';
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
    cadena = (char*) realloc(cadena, (contadorChar+1)*sizeof(char));
    cadena[contadorChar] = '\0';
    p[N_PLANTILLA-1] = obtenerPlantilla(cadena);
    contadorChar = 0;
    cadena = (char*) calloc(1, sizeof(char));
    fclose(FICHERO_PLANTILLA);
    return p; 
}

// Cabecera: Jug_plan* obtenerJugadoresPlantillas()
// Precondicion:
// Poscondicion:
Jug_plan* obtenerJugadoresPlantillas(){
    N_JUG_PLANT = 0;
    FILE *FICHERO_JUG_PLAN = fopen("jugadores_plantillas.txt", "r");
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
    fclose(FICHERO_JUG_PLAN);
    return p; 
}
// Cabecera: Conf* obtenerConfiguraciones()
// Precondicion:
// Poscondicion:
Conf* obtenerConfiguraciones(){
    FILE *FICHERO_CONF = fopen("configuracion.txt", "r");
    char c;
    int n = 0;
    char *cadena = (char*) malloc(sizeof(char));
    int contadorChar = 0;
    Conf *p = (Conf*) malloc(sizeof(Conf));
    while((c = fgetc(FICHERO_CONF))!=EOF){
        if(c == '\n'){
            n++;
            p = (Conf*) realloc(p, n*sizeof(Conf));
            p[n-1] = obtenerConfiguracion(cadena);
            contadorChar = 0;
            cadena = (char*) calloc(1, sizeof(char));
        }else{
            contadorChar++;
            cadena = (char*) realloc(cadena, (contadorChar)*sizeof(char));
            cadena[contadorChar-1] = c;
        }
    }
    n++;
    p = (Conf*) realloc(p, n*sizeof(Conf));
    p[n-1] = obtenerConfiguracion(cadena);
    contadorChar = 0;
    cadena = (char*) calloc(1, sizeof(char));
    fclose(FICHERO_CONF);
    return p; 
}
// Cabecera: void guardarDatosEquipo(Equipo* equipos, int elementos)
// Precondicion:
// Poscondicion:
void guardarDatosEquipo(Equipo* equipos, int elementos){
    int i;
    Equipo e;
    FILE *FICHERO_EQUIPO = fopen("equipos.txt", "w");
    for(i = 0; i < elementos; i++){
        e = equipos[i];
        if(i == 0){
            fprintf(FICHERO_EQUIPO, "%s %s", e.codigo, e.nombre);
        }else{
            fprintf(FICHERO_EQUIPO, "\n%s %s", e.codigo, e.nombre);
        }
    }
    fclose(FICHERO_EQUIPO);
}
// Cabecera: void guardarDatosJugador(Jugador* jugadores, int elementos)
// Precondicion:
// Poscondicion:
void guardarDatosJugador(Jugador* jugadores, int elementos){
    int i;
    Jugador j;
    FILE *FICHERO_JUGADOR = fopen("futbolistas.txt", "w");
    for(i = 0; i < elementos; i++){
        j = jugadores[i];
        if(i == 0){
            fprintf(FICHERO_JUGADOR, "%s %s %s %d %d", j.codigo, j.codigo_equipo, j.nombre, j.precio, j.valoracion);
        }else{
            fprintf(FICHERO_JUGADOR, "\n%s %s %s %d %d", j.codigo, j.codigo_equipo, j.nombre, j.precio, j.valoracion);
        }
    }
    fclose(FICHERO_JUGADOR);
}
// Cabecera: void guardarDatosUsuario(Usuario* usuarios, int elementos)
// Precondicion:
// Poscondicion:
void guardarDatosUsuario(Usuario* usuarios, int elementos){
    int i;
    Usuario u;
    FILE *FICHERO_USUARIO = fopen("usuarios.txt", "w");
    for(i = 0; i < elementos; i++){
        u = usuarios[i];
        if(i == 0){
            fprintf(FICHERO_USUARIO, "%s %s %s %s %s", u.codigo, u.nombre, u.tipo, u.login, u.pass);
        }else{
            fprintf(FICHERO_USUARIO, "\n%s %s %s %s %s", u.codigo, u.nombre, u.tipo, u.login, u.pass);
        }
    }
    fclose(FICHERO_USUARIO);
}
// Cabecera: void guardarDatosPlantilla(Plantilla* plantillas, int elementos)
// Precondicion:
// Poscondicion:
void guardarDatosPlantilla(Plantilla* plantillas, int elementos){
    int i;
    Plantilla p;
    FILE *FICHERO_PLANTILLA = fopen("plantillas.txt", "w");
    for(i = 0; i < elementos; i++){
        p = plantillas[i];
        if(i == 0){
            fprintf(FICHERO_PLANTILLA, "%s %s %s %d %d", p.codigo_usuario, p.codigo, p.nombre, p.presupuesto, p.puntuacion);
        }else{
            fprintf(FICHERO_PLANTILLA, "\n%s %s %s %d %d", p.codigo_usuario, p.codigo, p.nombre, p.presupuesto, p.puntuacion);
        }
    }
    fclose(FICHERO_PLANTILLA);
}
// Cabecera: void guardarDatosJugadorPlantilla(Jug_plan* jug_plan, int elementos)
// Precondicion:
// Poscondicion:
void guardarDatosJugadorPlantilla(Jug_plan* jug_plan, int elementos){
    int i;
    Jug_plan p;
    FILE *FICHERO_JUG_PLAN = fopen("jugadores_plantillas.txt", "w");
    for(i = 0; i < elementos; i++){
        p = jug_plan[i];
        if(i == 0){
            fprintf(FICHERO_JUG_PLAN, "%s %s", p.codigo_jugador, p.codigo_plantilla);
        }else{
            fprintf(FICHERO_JUG_PLAN, "\n%s %s", p.codigo_jugador, p.codigo_plantilla);
        }
    }
    fclose(FICHERO_JUG_PLAN);
}
// Cabecera: void guardarDatosConf(Conf* conf, int elementos)
// Precondicion:
// Poscondicion:
void guardarDatosConf(Conf* conf, int elementos){
    int i;
    Conf p;
    FILE *FICHERO_CONF = fopen("configuracion.txt", "w");
    for(i = 0; i < elementos; i++){
        p = conf[i];
        if(i == 0){
            fprintf(FICHERO_CONF, "%s %d", p.campo, p.valor);
        }else{
            fprintf(FICHERO_CONF, "\n%s %d", p.campo, p.valor);
        }
    }
    fclose(FICHERO_CONF);
}
// Cabecera: int nUsuarios()
// Precondicion:
// Poscondicion:
int nUsuarios(){
    return N_USUARIO;
}
// Cabecera: int nEquipos()
// Precondicion:
// Poscondicion:
int nEquipos(){
    return N_EQUIPO;
}
// Cabecera: int nJugadores()
// Precondicion:
// Poscondicion:
int nJugadores(){
    return N_JUGADOR;
}
// Cabecera: int nPlantillas()
// Precondicion:
// Poscondicion:
int nPlantillas(){
    return N_PLANTILLA;
}
// Cabecera: int nJugPlants()
// Precondicion:
// Poscondicion:
int nJugPlants(){
    return N_JUG_PLANT;
}

char* loguear(char* logUsuario, char* passUsuario){
    fpurge(stdin);
    Usuario *u = obtenerUsuarios();
    int dimension = nUsuarios();
    int cont = 0;
    char* codigo;
    strcpy(codigo, "00");
    while(cont < dimension && strcmp(codigo, "00") == 0){
        if(strcmp(logUsuario, u[cont].login) == 0 && strcmp(passUsuario, u[cont].pass)){
            strcpy(codigo, u[cont].codigo);
        }
        cont++;
    }
    return codigo;
}