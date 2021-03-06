#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include "fichero.h"

static Equipo *equipos;
static Plantilla *plantillas;
static int nplantillas;
static Jugador *jugadores;
static int crearplant;
static Jug_plan *jug_plan;
static int contadorJugadores;
static Conf* configuracion;
static int tamanoequipos;


// Cabecera: void menuUsuario()
// Precondicion:
// Poscondicion: muestra menu inicial usuario
void menuUsuario(char *codigo) {
    char opcion;
    inicializarDatos();

    do {
        printf("\n MENU PARTICIPANTE \n");
        puts("");
        printf("1.- Crear Plantilla\n");
        printf("2.- Borrar Plantilla\n");
        printf("3.- Salir del programa\n");
        fflush(stdin);

        opcion = getchar();

        if (opcion == '1') {
            crearPlantilla(codigo);
        } else if (opcion == '2') {
            BorrarPlantilla();
        }
    } while (opcion != '3');
    salvarDatos();
    exit(0);
}

// Cabecera: void inicializarDatos()
// Precondicion:
// Poscondicion: inicializa todo los atributos
void inicializarDatos(){
    crearplant=0;
    plantillas=obtenerPlantillas();
    nplantillas= nPlantillas();
    jugadores=obtenerJugadores();
    configuracion=obtenerConfiguraciones();
    equipos=obtenerEquipos();
    tamanoequipos=nEquipos();
}

// Cabecera: void salvarDatos()
// Precondicion:
// Poscondicion: guarda los datos almacenados en los atributos
void salvarDatos(){
    guardarDatosPlantilla(plantillas,nplantillas);
    if(crearplant==1)
    {
            guardarDatosJugadorPlantilla(jug_plan,contadorJugadores-1);
            crearplant=0;
    }

}

// Cabecera: void tasar()
// Precondicion:
// Poscondicion: tasar los jugadores de las plantillas
void tasar(char *codigoPlantilla,int *presupuesto,int *valoracion){
    crearplant=1;
    int valor;
    char codigo[3];
    int codigoEnNumero;
    contadorJugadores=1;
    int *codigosSelect = (int*) malloc(sizeof(int));
    char eleccion;
    jug_plan= (Jug_plan*) malloc(sizeof(Jug_plan));
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


    *presupuesto=valor;


}

// Cabecera: void comprobarQueNoEsta()
// Precondicion:
// Poscondicion: Comprobar que un int no esta en un vector de int
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

// Cabecera: void imprimirListaJugadores(Jugador *jugadores,int tamano)
// Precondicion:
// Poscondicion: Lista todos los jugadores
void imprimirListaJugadores(int tamano){

    int contador,contadorEq;

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
// Cabecera: void crearPlantilla(char *codigo)
// Precondicion: codigo es el codigo de usuario
// Poscondicion: Crea una plantila
void crearPlantilla(char *codigo)
{
    int cont;
    char nombre[60];
    int valor;
    puts("¿Como desea llamar a la plantilla?");
    fgets(nombre, sizeof(nombre), stdin);

    char codigoPlantilla[4];
    int encontrado;

    plantillas = (Plantilla*) realloc(plantillas, (nplantillas)*sizeof(int));


        do{
        encontrado=0;
        puts("Introduce el codigo de la plantilla:");
        fgets(codigoPlantilla, sizeof(codigoPlantilla), stdin);
        for(cont=0;cont<nplantillas;cont++)
        {
            if(strcmp(codigoPlantilla,plantillas[cont].codigo)==0)
            {
                puts("Ese codigo ya existe Introduzca otro:");
                encontrado=1;
            }
        }
        fflush(stdin);
    }while(encontrado==1);



    strcpy(plantillas[nplantillas+1].codigo_usuario,codigo);
    strcpy(plantillas[nplantillas+1].codigo,codigoPlantilla);
    strcpy(plantillas[nplantillas+1].nombre,nombre);


    int numeroJugadores=nJugadores();
    int valoracion;
    int presupuesto;
    imprimirListaJugadores(numeroJugadores);
    tasar(codigoPlantilla,&presupuesto,&valoracion);

    plantillas[nplantillas+1].presupuesto=presupuesto;
    plantillas[nplantillas+1].puntuacion=valoracion;

    nplantillas=nplantillas+1;
}

// Cabecera: void BorrarPlantilla()
// Precondicion:
// Poscondicion: Borra una plantilla
void BorrarPlantilla(){
    int cont;

        char codigoPlantilla[4];
        int encontrado;

     do{
            encontrado=0;
            puts("Introduce el codigo de la plantilla:");
            fgets(codigoPlantilla, sizeof(codigoPlantilla), stdin);
            for(cont=0;cont<nplantillas;cont++)
            {
                if(strcmp(codigoPlantilla,plantillas[cont].codigo)==0)
                {
                    strcpy(plantillas[cont].codigo,"xx");
                    encontrado=1;
                    nplantillas=nplantillas-1;
                }
            }
            fflush(stdin);
        }while(encontrado==0);



}

