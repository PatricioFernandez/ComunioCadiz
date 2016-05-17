#ifndef FICHERO_H
#define	FICHERO_H

// TIPOS
typedef struct{
    char codigo[3];
    char nombre[21];
    char tipo[14];
    char login[6];
    char pass[6];
}Usuario;

typedef struct{
    char codigo[3];
    char nombre[21];
}Equipo;

typedef struct{
    char codigo[3];
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

int empezar();
Equipo* obtenerEquipos();
Jugador* obtenerJugadores();
Usuario* obtenerUsuarios();
Plantilla* obtenerPlantillas();
Jug_plan* obtenerJugadoresPlantillas();

#endif	/* FICHERO_H */