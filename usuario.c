#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include "fichero.h"


void tasar(Jugador *jugadores,char *codigoPlantilla,int *presupuesto,int *valoracion){
    Conf* configuracion=obtenerConfiguraciones();
    int valor;
    char codigo[3];
    int codigoEnNumero;
    int contadorJugadores=1;
    int *codigosSelect = (int*) malloc(sizeof(int));
    char eleccion;
    Jug_plan *jug_plan= (Jug_plan*) malloc(sizeof(Jug_plan));
    *valoracion=0;
    fflush(stdin);

    valor=configuracion[1].valor;
    do{


            printf("Introduce el codigo del jugador que deseas fichar ");
            fflush(stdin);
            fgets(codigo,3,stdin);
            codigoEnNumero=atoi(codigo);

            int precio=jugadores[codigoEnNumero-1].precio;
            *valoracion=jugadores[codigoEnNumero-1].valoracion;
            codigosSelect = (int*) realloc(codigosSelect, (contadorJugadores)*sizeof(int));
            jug_plan = (Jug_plan*) realloc(jug_plan, (contadorJugadores)*sizeof(Jug_plan));


            int sehaencontrado=comprobarQueNoEsta(codigoEnNumero,codigosSelect,contadorJugadores);
            if(sehaencontrado==0)
            {
                if(valor-precio>=0)
                {
                    codigosSelect[contadorJugadores-1]=codigoEnNumero;
                    strcpy(jug_plan[contadorJugadores-1].codigo_jugador,codigo);
                    strcpy(jug_plan[contadorJugadores-1].codigo_plantilla,codigoPlantilla);
                    contadorJugadores++;
                    valor=valor-precio;
                }
                else{
                    printf("No tienes dinero para ficharle",codigo);
                }

            }
            else{
                printf("Ya tienes al jugador %i en tu plantilla",codigo);
            }


        printf("Tienes %i euros \n\n",valor);
        puts("Introduce n si no desea seguir fichando en caso contrario introduzca otro caracter ");
        fflush(stdin);
        eleccion=getchar();

    }while(valor>0 && eleccion!='n');


    guardarDatosJugadorPlantilla(jug_plan,contadorJugadores-1);
    *presupuesto=valor;


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

void crearPlantilla(char *codigo)
{
    int cont;
    char nombre[60];
    int valor;
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


    strcpy(plantillas[numero+1].codigo_usuario,codigo);
    strcpy(plantillas[numero+1].codigo,codigoPlantilla);
    strcpy(plantillas[numero+1].nombre,nombre);

    Jugador *jugadores=obtenerJugadores();
    int numeroJugadores=nJugadores();
    int valoracion;
    int presupuesto;
    imprimirListaJugadores(jugadores,numeroJugadores);
    tasar(jugadores,codigoPlantilla,&presupuesto,&valoracion);
    plantillas[numero+1].presupuesto=valor;

}



