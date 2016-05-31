#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include "fichero.h"


void tasar(){
    Conf* configuracion=obtenerConfiguraciones();
    printf("%i ",configuracion[1].valor);
}

void imprimirListaJugadores(Jugador *jugadores,int tamano){

    int contador,contadorEq,tamanoequipos;
    Equipo *equipos=obtenerEquipos();
    tamanoequipos=nEquipos();
    int codigo_equipo;
    puts("---JUGADORES---");
    puts("Codigo Equipo Nombre Precio Valoracion");
    for(contador=0;contador<tamano;contador++){

        printf("%s ",jugadores[contador].codigo);
        codigo_equipo=jugadores[contador].codigo_equipo;
            for(contadorEq=0;contadorEq<tamanoequipos;contadorEq++)
            {
                if(strcmp(codigo_equipo,equipos[contadorEq].codigo)==0)
                        printf("%s ",equipos[contadorEq].nombre);
            }
        contadorEq=0;
        printf("%s ",jugadores[contador].nombre);
        printf("%i ",jugadores[contador].precio);
        printf("%i ",jugadores[contador].valoracion);
        puts("");
    }

}

void crearPlantilla()
{
    char nombre[60];
    puts("¿Como desea llamar a la plantilla?");
    fgets(nombre, sizeof(nombre), stdin);

    Plantilla *plantillas=obtenerPlantillas();
    int numero= nPlantillas();

    char codigoPlantilla[3];
    char numeroEnChar=numero+49;


    if(numero+1>10 && numero+1<100)
    {
         strcpy(codigoPlantilla,"0");

    }
    else if(numero+1>100)
    {
         strcpy(codigoPlantilla,"");
    }
    else{
         strcpy(codigoPlantilla,"00");
         codigoPlantilla[2]=numeroEnChar;
    }



    strcpy(plantillas[numero+1].codigo_usuario,"01");
    strcpy(plantillas[numero+1].codigo_usuario,codigoPlantilla);
    strcpy(plantillas[numero+1].nombre,nombre);

    Jugador *jugadores=obtenerJugadores();
    int numeroJugadores=nJugadores();
    imprimirListaJugadores(jugadores,numeroJugadores);

}



