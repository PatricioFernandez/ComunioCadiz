#ifndef FICHERO_H
#define	FICHERO_H

// TIPOS
typedef struct{
    char codigo[3];
    char nombre[21];
    char tipo[14];
    char login[7];
    char pass[7];
}Usuario;

typedef struct{
    char codigo[3];
    char nombre[21];
}Equipo;

typedef struct{
    char codigo[4];
    char codigo_equipo[3];
    char nombre[21];
    int precio;
    int valoracion;
}Jugador;

typedef struct{
    char codigo_usuario[3];
    char codigo[4];
    char nombre[31];
    int presupuesto;
    int puntuacion;
}Plantilla;

typedef struct{
    char codigo_jugador[3];
    char codigo_plantilla[4];
}Jug_plan;

typedef struct{
    char campo[31];
    int valor;
}Conf;

Equipo* obtenerEquipos();
Jugador* obtenerJugadores();
Usuario* obtenerUsuarios();
Plantilla* obtenerPlantillas();
Jug_plan* obtenerJugadoresPlantillas();
Conf* obtenerConfiguraciones();
void guardarDatosEquipo(Equipo* equipos, int elementos);
void guardarDatosJugadores(Jugador* jugadores, int elementos);
void guardarDatosUsuario(Usuario* usuarios, int elementos);
void guardarDatosPlantilla(Plantilla* plantillas, int elementos);
void guardarDatosJugadorPlantilla(Jug_plan* jug_plan, int elementos);
void guardarDatosConf(Conf* conf, int elementos);
Usuario loguear(char* logUsuario, char* passUsuario);
int nUsuarios();
int nEquipos();
int nJugadores();
int nPlantillas();
int nJugPlants();

#endif	/* FICHERO_H */