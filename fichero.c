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
// Poscondicion: devuelve una estructura de tipo equipo
Equipo obtenerEquipo(char *cadena){
    Equipo e;
    sscanf(cadena,"%s%s", e.codigo, e.nombre);
    return e;
}

// Cabecera: Jugador obtenerJugador(char *cadena)
// Precondicion:
// Poscondicion: devuelve una estructura de tipo jugador
Jugador obtenerJugador(char *cadena){
    Jugador j;
    sscanf(cadena,"%s%s%s%d%d", j.codigo, j.codigo_equipo, j.nombre, &j.precio, &j.valoracion);
    return j;
}

// Cabecera: Usuario obtenerUsuario(char *cadena)
// Precondicion:
// Poscondicion: devuelve una estructura de tipo usuario
Usuario obtenerUsuario(char *cadena){
    Usuario u;
    sscanf(cadena,"%s%s%s%s%s", u.codigo, u.nombre, u.tipo, u.login, u.pass);
    return u;
}

// Cabecera: Plantilla obtenerPlantilla(char* cadena)
// Precondicion:
// Poscondicion: devuelve una estructura de tipo plantilla
Plantilla obtenerPlantilla(char* cadena){
    Plantilla p;
    sscanf(cadena, "%s%s%s%d%d", p.codigo_usuario, p.codigo, p.nombre, &p.presupuesto, &p.puntuacion);
    return p;
}

// Cabecera: Jug_plan obtenerJugPlan(char* cadena)
// Precondicion:
// Poscondicion: devuelve una estructura de tipo jug_plan
Jug_plan obtenerJugPlan(char* cadena){
    Jug_plan jp;
    sscanf(cadena, "%s%s", jp.codigo_jugador, jp.codigo_plantilla);
    return jp;
}

// Cabecera: Conf obtenerConfiguracion(char* cadena)
// Precondicion:
// Poscondicion: devuelve una estructura de tipo conf
Conf obtenerConfiguracion(char* cadena){
    Conf c;
    sscanf(cadena, "%s%d", c.campo, &c.valor);
    return c;
}

// FUNCIONES PUBLICAS

// Cabecera: Equipo* obtenerEquipos()
// Precondicion:
// Poscondicion: devuelve un vector de equipo con los datos de equipos.txt
Equipo* obtenerEquipos() {
    N_EQUIPO = 0;
    FILE *FICHERO_EQUIPO = fopen("equipos.txt", "r");
    if (FICHERO_EQUIPO == NULL) {
        printf("Error al abrir fichero equipos.txt");
        exit(1);
    } else {
        char c;
        char *cadena = (char*) calloc(1, sizeof (char));
        int contadorChar = 0;
        Equipo *e = (Equipo*) calloc(1, sizeof (Equipo));
        while ((c = fgetc(FICHERO_EQUIPO)) != EOF) {
            if (c == '\n') {
                N_EQUIPO++;
                e = (Equipo*) realloc(e, N_EQUIPO * sizeof (Equipo));
                cadena = (char*) realloc(cadena, (contadorChar + 1) * sizeof (char));
                cadena[contadorChar] = '\0';
                e[N_EQUIPO - 1] = obtenerEquipo(cadena);
                contadorChar = 0;
                cadena = (char*) calloc(1, sizeof (char));
            } else {
                contadorChar++;
                cadena = (char*) realloc(cadena, (contadorChar) * sizeof (char));
                cadena[contadorChar - 1] = c;
            }
        }
        N_EQUIPO++;
        e = (Equipo*) realloc(e, N_EQUIPO * sizeof (Equipo));
        cadena = (char*) realloc(cadena, (contadorChar + 1) * sizeof (char));
        cadena[contadorChar] = '\0';
        e[N_EQUIPO - 1] = obtenerEquipo(cadena);
        contadorChar = 0;
        cadena = (char*) calloc(1, sizeof (char));
        fclose(FICHERO_EQUIPO);
        return e;
    }
}

// Cabecera: Jugador* obtenerJugadores()
// Precondicion:
// Poscondicion:devuelve un vector de jugador con los datos de futbolistas.txt
Jugador* obtenerJugadores() {
    N_JUGADOR = 0;
    FILE *FICHERO_JUGADOR = fopen("futbolistas.txt", "r");
    if (FICHERO_JUGADOR == NULL) {
        printf("Error al abrir fichero futbolistas.txt");
        exit(1);
    } else {
        char c;
        char *cadena = (char*) malloc(sizeof (char));
        int contadorChar = 0;
        Jugador *j = (Jugador*) malloc(sizeof (Jugador));
        while ((c = fgetc(FICHERO_JUGADOR)) != EOF) {
            if (c == '\n') {
                N_JUGADOR++;
                j = (Jugador*) realloc(j, N_JUGADOR * sizeof (Jugador));
                cadena = (char*) realloc(cadena, (contadorChar + 1) * sizeof (char));
                cadena[contadorChar] = '\0';
                j[N_JUGADOR - 1] = obtenerJugador(cadena);
                contadorChar = 0;
                cadena = (char*) calloc(1, sizeof (char));
            } else {
                contadorChar++;
                cadena = (char*) realloc(cadena, (contadorChar) * sizeof (char));
                cadena[contadorChar - 1] = c;
            }
        }
        N_JUGADOR++;
        j = (Jugador*) realloc(j, N_JUGADOR * sizeof (Jugador));
        cadena = (char*) realloc(cadena, (contadorChar + 1) * sizeof (char));
        cadena[contadorChar] = '\0';
        j[N_JUGADOR - 1] = obtenerJugador(cadena);
        contadorChar = 0;
        cadena = (char*) calloc(1, sizeof (char));
        fclose(FICHERO_JUGADOR);
        return j;
    }
}

// Cabecera: Usuario* obtenerUsuarios()
// Precondicion: devuelve un vector de usuario con los datos de usuarios.txt
// Poscondicion:
Usuario* obtenerUsuarios() {
    N_USUARIO = 0;
    FILE *FICHERO_USUARIO = fopen("usuarios.txt", "r");
    if (FICHERO_USUARIO == NULL) {
        printf("Error al abrir fichero usuarios.txt");
        exit(1);
    } else {
        char c;
        char *cadena = (char*) calloc(1, sizeof (char));
        int contadorChar = 0;
        Usuario *u = (Usuario*) calloc(1, sizeof (Usuario));
        while ((c = fgetc(FICHERO_USUARIO)) != EOF) {
            if (c == '\n') {
                N_USUARIO++;
                u = (Usuario*) realloc(u, N_USUARIO * sizeof (Usuario));
                cadena = (char*) realloc(cadena, (contadorChar + 1) * sizeof (char));
                cadena[contadorChar] = '\0';
                u[N_USUARIO - 1] = obtenerUsuario(cadena);
                contadorChar = 0;
                cadena = (char*) calloc(1, sizeof (char));
            } else {
                contadorChar++;
                cadena = (char*) realloc(cadena, (contadorChar) * sizeof (char));
                cadena[contadorChar - 1] = c;
            }
        }
        N_USUARIO++;
        u = (Usuario*) realloc(u, N_USUARIO * sizeof (Usuario));
        cadena = (char*) realloc(cadena, (contadorChar + 1) * sizeof (char));
        cadena[contadorChar] = '\0';
        u[N_USUARIO - 1] = obtenerUsuario(cadena);
        fclose(FICHERO_USUARIO);
        return u;
    }
}

// Cabecera: Plantilla* obtenerPlantillas()
// Precondicion:
// Poscondicion: devuelve un vector de plantilla con los datos de plantillas.txt
Plantilla* obtenerPlantillas() {
    N_PLANTILLA = 0;
    FILE *FICHERO_PLANTILLA = fopen("plantillas.txt", "r");
    if (FICHERO_PLANTILLA == NULL) {
        printf("Error al abrir fichero plantillas.txt");
        exit(1);
    } else {
        char c;
        char *cadena = (char*) calloc(1, sizeof (char));
        int contadorChar = 0;
        Plantilla *p = (Plantilla*) calloc(1, sizeof (Plantilla));
        while ((c = fgetc(FICHERO_PLANTILLA)) != EOF) {
            if (c == '\n') {
                N_PLANTILLA++;
                p = (Plantilla*) realloc(p, N_PLANTILLA * sizeof (Plantilla));
                cadena = (char*) realloc(cadena, (contadorChar + 1) * sizeof (char));
                cadena[contadorChar] = '\0';
                p[N_PLANTILLA - 1] = obtenerPlantilla(cadena);
                contadorChar = 0;
                cadena = (char*) calloc(1, sizeof (char));
            } else {
                contadorChar++;
                cadena = (char*) realloc(cadena, (contadorChar) * sizeof (char));
                cadena[contadorChar - 1] = c;
            }
        }
        N_PLANTILLA++;
        p = (Plantilla*) realloc(p, N_PLANTILLA * sizeof (Plantilla));
        cadena = (char*) realloc(cadena, (contadorChar + 1) * sizeof (char));
        cadena[contadorChar] = '\0';
        p[N_PLANTILLA - 1] = obtenerPlantilla(cadena);
        contadorChar = 0;
        cadena = (char*) calloc(1, sizeof (char));
        fclose(FICHERO_PLANTILLA);
        return p;
    }
}

// Cabecera: Jug_plan* obtenerJugadoresPlantillas()
// Precondicion:
// Poscondicion: devuelve un vector de jug_plan con los datos de jugadores_plantillas.txt
Jug_plan* obtenerJugadoresPlantillas() {
    N_JUG_PLANT = 0;
    FILE *FICHERO_JUG_PLAN = fopen("jugadores_plantillas.txt", "r");
    if (FICHERO_JUG_PLAN == NULL) {
        printf("Error al abrir fichero jugadores_plantillas.txt");
        exit(1);
    } else {
        char c;
        char *cadena = (char*) malloc(sizeof (char));
        int contadorChar = 0;
        Jug_plan *p = (Jug_plan*) malloc(sizeof (Jug_plan));
        while ((c = fgetc(FICHERO_JUG_PLAN)) != EOF) {
            if (c == '\n') {
                N_JUG_PLANT++;
                p = (Jug_plan*) realloc(p, N_JUG_PLANT * sizeof (Jug_plan));
                cadena = (char*) realloc(cadena, (contadorChar + 1) * sizeof (char));
                cadena[contadorChar] = '\0';
                p[N_JUG_PLANT - 1] = obtenerJugPlan(cadena);
                contadorChar = 0;
                cadena = (char*) calloc(1, sizeof (char));
            } else {
                contadorChar++;
                cadena = (char*) realloc(cadena, (contadorChar) * sizeof (char));
                cadena[contadorChar - 1] = c;
            }
        }
        N_JUG_PLANT++;
        p = (Jug_plan*) realloc(p, N_JUG_PLANT * sizeof (Jug_plan));
        cadena = (char*) realloc(cadena, (contadorChar + 1) * sizeof (char));
        cadena[contadorChar] = '\0';
        p[N_JUG_PLANT - 1] = obtenerJugPlan(cadena);
        contadorChar = 0;
        cadena = (char*) calloc(1, sizeof (char));
        fclose(FICHERO_JUG_PLAN);
        return p;
    }
}

// Cabecera: Conf* obtenerConfiguraciones()
// Precondicion:
// Poscondicion: devuelve un vector de conf con los datos de configuracion.txt
Conf* obtenerConfiguraciones() {
    FILE *FICHERO_CONF = fopen("configuracion.txt", "r");
    if (FICHERO_CONF == NULL) {
        printf("Error al abrir fichero configuracion.txt");
        exit(1);
    } else {
        char c;
        int n = 0;
        char *cadena = (char*) malloc(sizeof (char));
        int contadorChar = 0;
        Conf *p = (Conf*) malloc(sizeof (Conf));
        while ((c = fgetc(FICHERO_CONF)) != EOF) {
            if (c == '\n') {
                n++;
                p = (Conf*) realloc(p, n * sizeof (Conf));
                cadena = (char*) realloc(cadena, (contadorChar + 1) * sizeof (char));
                cadena[contadorChar] = '\0';
                p[n - 1] = obtenerConfiguracion(cadena);
                contadorChar = 0;
                cadena = (char*) calloc(1, sizeof (char));
            } else {
                contadorChar++;
                cadena = (char*) realloc(cadena, (contadorChar) * sizeof (char));
                cadena[contadorChar - 1] = c;
            }
        }
        n++;
        p = (Conf*) realloc(p, n * sizeof (Conf));
        cadena = (char*) realloc(cadena, (contadorChar + 1) * sizeof (char));
        cadena[contadorChar] = '\0';
        p[n - 1] = obtenerConfiguracion(cadena);
        contadorChar = 0;
        cadena = (char*) calloc(1, sizeof (char));
        fclose(FICHERO_CONF);
        return p;
    }
}

// Cabecera: void guardarDatosEquipo(Equipo* equipos, int elementos)
// Precondicion:
// Poscondicion: escribe en equipos.txt los datos del vector equipos
void guardarDatosEquipo(Equipo* equipos, int elementos) {
    int i;
    int primerElemento = 0;
    Equipo e;
    FILE *FICHERO_EQUIPO = fopen("equipos.txt", "w");
    for (i = 0; i < elementos; i++) {
        e = equipos[i];
        if (strcmp(e.codigo, "xx") != 0) {
            if (primerElemento == 0) {
                fprintf(FICHERO_EQUIPO, "%s %s", e.codigo, e.nombre);
                primerElemento = 1;
            } else {
                fprintf(FICHERO_EQUIPO, "\n%s %s", e.codigo, e.nombre);
            }
        }
    }
    fclose(FICHERO_EQUIPO);
}

// Cabecera: void guardarDatosJugador(Jugador* jugadores, int elementos)
// Precondicion:
// Poscondicion: escribe en futbolistas.txt los datos del vector jugadores
void guardarDatosJugador(Jugador* jugadores, int elementos) {
    int i;
    int primerElemento = 0;
    Jugador j;
    FILE *FICHERO_JUGADOR = fopen("futbolistas.txt", "w");
    for (i = 0; i < elementos; i++) {
        j = jugadores[i];
        if (strcmp(j.codigo, "xx") != 0) {
            if (primerElemento == 0) {
                fprintf(FICHERO_JUGADOR, "%s %s %s %d %d", j.codigo, j.codigo_equipo, j.nombre, j.precio, j.valoracion);
                primerElemento = 1;
            } else {
                fprintf(FICHERO_JUGADOR, "\n%s %s %s %d %d", j.codigo, j.codigo_equipo, j.nombre, j.precio, j.valoracion);
            }
        }
    }
    fclose(FICHERO_JUGADOR);
}

// Cabecera: void guardarDatosUsuario(Usuario* usuarios, int elementos)
// Precondicion:
// Poscondicion: escribe en usuarios.txt los datos del vector usuarios
void guardarDatosUsuario(Usuario* usuarios, int elementos) {
    int i;
    int primerElemento = 0;
    Usuario u;
    FILE *FICHERO_USUARIO = fopen("usuarios.txt", "w");
    for (i = 0; i < elementos; i++) {
        u = usuarios[i];
        if (strcmp(u.codigo, "xx")) {
            if (primerElemento == 0) {
                fprintf(FICHERO_USUARIO, "%s %s %s %s %s", u.codigo, u.nombre, u.tipo, u.login, u.pass);
                primerElemento = 1;
            } else {
                fprintf(FICHERO_USUARIO, "\n%s %s %s %s %s", u.codigo, u.nombre, u.tipo, u.login, u.pass);
            }
        }
    }
    fclose(FICHERO_USUARIO);
}

// Cabecera: void guardarDatosPlantilla(Plantilla* plantillas, int elementos)
// Precondicion:
// Poscondicion: escribe en plantillas.txt los datos del vector plantillas
void guardarDatosPlantilla(Plantilla* plantillas, int elementos) {
    int i;
    int primerElemento = 0;
    Plantilla p;
    FILE *FICHERO_PLANTILLA = fopen("plantillas.txt", "w");
    for (i = 0; i < elementos; i++) {
        p = plantillas[i];
        if (strcmp(p.codigo, "xx")) {
            if (primerElemento == 0) {
                fprintf(FICHERO_PLANTILLA, "%s %s %s %d %d", p.codigo_usuario, p.codigo, p.nombre, p.presupuesto, p.puntuacion);
                primerElemento = 1;
            } else {
                fprintf(FICHERO_PLANTILLA, "\n%s %s %s %d %d", p.codigo_usuario, p.codigo, p.nombre, p.presupuesto, p.puntuacion);
            }
        }
    }
    fclose(FICHERO_PLANTILLA);
}

// Cabecera: void guardarDatosJugadorPlantilla(Jug_plan* jug_plan, int elementos)
// Precondicion:
// Poscondicion: escribe en jugadores_plantillas.txt los datos del vector jug_plan
void guardarDatosJugadorPlantilla(Jug_plan* jug_plan, int elementos) {
    int i;
    int primerElemento = 0;
    Jug_plan p;
    FILE *FICHERO_JUG_PLAN = fopen("jugadores_plantillas.txt", "w");
    for (i = 0; i < elementos; i++) {
        p = jug_plan[i];
        if (strcmp(p.codigo_jugador, "xx") != 0 || strcmp(p.codigo_plantilla, "xx") != 0) {
            if (primerElemento == 0) {
                fprintf(FICHERO_JUG_PLAN, "%s %s", p.codigo_jugador, p.codigo_plantilla);
                primerElemento = 1;
            } else {
                fprintf(FICHERO_JUG_PLAN, "\n%s %s", p.codigo_jugador, p.codigo_plantilla);
            }
        }
    }
    fclose(FICHERO_JUG_PLAN);
}

// Cabecera: void guardarDatosConf(Conf* conf, int elementos)
// Precondicion:
// Poscondicion: escribe en configuracion.txt los datos del vector conf
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
// Poscondicion: devuelve N_USUARIO
int nUsuarios(){
    return N_USUARIO;
}

// Cabecera: int nEquipos()
// Precondicion:
// Poscondicion: devuelve N_EQUIPO
int nEquipos(){
    return N_EQUIPO;
}

// Cabecera: int nJugadores()
// Precondicion:
// Poscondicion: devuelve N_JUGADOR
int nJugadores(){
    return N_JUGADOR;
}

// Cabecera: int nPlantillas()
// Precondicion:
// Poscondicion: devuelve N_PLANTILLA
int nPlantillas(){
    return N_PLANTILLA;
}

// Cabecera: int nJugPlants()
// Precondicion:
// Poscondicion: devuelve N_JUG_PLANT
int nJugPlants(){
    return N_JUG_PLANT;
}

// Cabecera: int nJugPlants(char* logUsuario, char* passUsuario)
// Precondicion:
// Poscondicion: devuelve el usuario identificado si existe
Usuario loguear(char* logUsuario, char* passUsuario){
    Usuario *u = obtenerUsuarios();
    Usuario usuario;
    strcpy(usuario.codigo, "00");
    int dimension = nUsuarios();
    int encontrado = 0;
    int cont = 0;
    while(cont < dimension && encontrado == 0){
        if(strcmp(u[cont].login, logUsuario) == 0 && strcmp(u[cont].pass, passUsuario) == 0){
            encontrado = 1;
            usuario = u[cont];
        }
        cont++;
    }
    return usuario;
}
