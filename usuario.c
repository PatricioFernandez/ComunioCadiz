#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include "fichero.h"


void tasar(Jugador *jugadores){
    Conf* configuracion=obtenerConfiguraciones();
    int valor;
    int codigo;
    int contadorJugadores=1;
    int *codigosSelect = (int*) malloc(sizeof(int));
    char eleccion;

    valor=configuracion[1].valor;
    do{


            printf("Introduce el codigo del jugador que deseas fichar ");
            fflush(stdin);
            scanf("%i",&codigo);
            int precio=jugadores[codigo-1].precio;
            codigosSelect = (int*) realloc(codigosSelect, (contadorJugadores)*sizeof(int));
            int sehaencontrado=comprobarQueNoEsta(codigo,codigosSelect,contadorJugadores);
            if(sehaencontrado==0)
            {
                if(valor-precio>=0)
                {
                    codigosSelect[contadorJugadores-1]=codigo;
                    contadorJugadores++;
                    valor=valor-precio;
                }
                else{
                    printf("No tienes dinero para ficharle \n",codigo);
                }

            }
            else{
                printf("Ya tienes al jugador %i en tu plantilla \n",codigo);
            }


        printf("Tienes %i euros \n",valor);
        puts("Introduce n si no desea seguir fichando en caso contrario introduzca otro caracter ");
        fflush(stdin);
        eleccion=getchar();

    }while(valor>0 && eleccion!='n');

}

int comprobarQueNoEsta(int codigo,int *vector,int tam)
{
    int i,sehaencontrado=0;
    for(i=0;i<tam;i++)
    {
        if(codigo==vector[i])
            sehaencontrado=1;
    }

    return sehaencontrado;
}

void imprimirListaJugadores(Jugador *jugadores,int tamano){

    int contador,contadorEq,tamanoequipos;
    Equipo *equipos=obtenerEquipos();
    tamanoequipos=nEquipos();
    int codigo_equipo;
    puts("---JUGADORES---");
    puts("Codigo Nombre Equipo Precio Valoracion");
    for(contador=0;contador<tamano;contador++){

        printf("%s ",jugadores[contador].codigo);
        printf("%s ",jugadores[contador].nombre);
        codigo_equipo=jugadores[contador].codigo_equipo;
            for(contadorEq=0;contadorEq<tamanoequipos;contadorEq++)
            {
                if(strcmp(codigo_equipo,equipos[contadorEq].codigo)==0)
                        printf("%s ",equipos[contadorEq].nombre);
            }
        contadorEq=0;
        printf("%i ",jugadores[contador].precio);
        printf("%i ",jugadores[contador].valoracion);
        puts("");
    }

}

void crearPlantilla()
{
    int cont;
    char nombre[60];
    puts("¿Como desea llamar a la plantilla?");
    fgets(nombre, sizeof(nombre), stdin);

    Plantilla *plantillas=obtenerPlantillas();
    int numero= nPlantillas();

    char codigoPlantilla[4];
    int encontrado;


    do{
        encontrado=0;
        puts("Introduce el codigo de la plantilla:");
        fgets(codigoPlantilla, sizeof(codigoPlantilla), stdin);
        for(cont=0;cont<numero;cont++)
        {
            if(strcmp(codigoPlantilla,plantillas[cont].codigo)==0)
            {
                puts("Ese codigo ya existe Introduzca otro:");
                encontrado=1;
            }
        }
        fflush(stdin);
    }while(encontrado==1);


    strcpy(plantillas[numero+1].codigo_usuario,"01");
    strcpy(plantillas[numero+1].codigo_usuario,codigoPlantilla);
    strcpy(plantillas[numero+1].nombre,nombre);

    Jugador *jugadores=obtenerJugadores();
    int numeroJugadores=nJugadores();
    imprimirListaJugadores(jugadores,numeroJugadores);
    tasar(jugadores);

}



