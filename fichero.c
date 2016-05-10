#include "fichero.h"
#include <string.h>
#include <stdio.h>

// TIPOS

typedef struct{
    char codigo[2];
    char nombre[20];
    char tipo[13];
    char login[5];
    char pass[5];
}usuario;

typedef struct{
    char codigo[2];
    char nombre[20];
}equipo;

typedef struct{
    char codigo[2];
    char codigo_equipo[2];
    char nombre[20];
    int precio;
    int valoracion;
}jugador;

typedef struct{
    char codigo_usuario[2];
    char codigo[3];
    char nombre[30];
    int presupuesto;
    int puntuacion;
}plantilla;

typedef struct{
    char codigo_jugador[2];
    char codigo_plantilla[3];
}jugador;