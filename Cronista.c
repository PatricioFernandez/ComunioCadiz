#include "Cronista.h"
#include <stdio.h>
#include <stdlib.h>
#include "fichero.h"

/*cabecera: void menuCronista()
precondincion:Ser llamado por el usuario cronista.
postcondicion:Mostrar menu.*/


void menuCronista(){
int op;
Equipo *equipo=obtenerEquipos();
Jugador *jugadores=obtenerJugadores();
do{
printf("Introduzca la operacion a realizar:\n 1.-Listar Equipos.\n 2.-Valorar Jugadores.\n 3.-Salir del programa.\n");
scanf("%d",&op);
if(op==1) listarEquipos2(equipo);
if (op==2) valorarEquipos(equipo,jugadores);
}while(op!=3);
return 0;
}



/*cabecera: void listarEquipos2(Equipo *equipos)
precondicion: la funcion ppal, pasa el parametro que esta funcion requiere,siempre y cuando
se elija la opción de listar equipos.
postondicion:lista los equipos.*/

void listarEquipos2(Equipo *equipos){
fflush(stdin);
int i,n;
n=nEquipos();

for(i=0;i<n;i++){
    printf("Equipo %s:",equipos[i].codigo);
    printf("%s\n",equipos[i].nombre);
}
}

/*cabecera:void valorarEquipos(Equipo *equipos,Jugador *jugadores)
precondicion:la funccion ppal,pasa el parametro que esta función requiere, siempre y cuando
se elija la opción de valorar equipos.
postcondicion:lista los equipos, y nos muestra los jugadores al elegir el equipo deseado a valorar,
finalmente introducimos la nueva valoracion de los jugadores.*/

void valorarEquipos(Equipo *equipos,Jugador *jugadores){
fflush(stdin);
int i=0,n,t,p,valor;
char j[3],c[3],r;
n=nEquipos();
t=nJugadores();
for(i=0;i<n;i++){
    printf("Equipo %s:",equipos[i].codigo);
    printf("%s\n",equipos[i].nombre);
}
do{
printf("Introduzca el codigo del equipo a valorar:");
fflush(stdin);
gets(j);
for(p=0;p<t;){
    if(strcmp(jugadores[p].codigo_equipo,j)==0){
    printf("%s %s %d %d\n",jugadores[p].codigo,jugadores[p].nombre,jugadores[p].precio,jugadores[p].valoracion);
    p++;
}else{
p++;

}
}
fflush(stdin);
printf("\nIntroduzca el codigo del jugador,al que desea modificar la valoracion:");
gets(c);
for(p=0;p<t;p++){
if(strcmp(jugadores[p].codigo,c)==0){
printf("Introduzca la nueva valoracion:");
scanf("%d",&valor);
jugadores[p].valoracion=jugadores[p].valoracion+valor;
printf("%s %s %d\n",jugadores[p].codigo,jugadores[p].nombre,jugadores[p].valoracion);
    }
    }
fflush(stdin);
printf("¿Quieres valorar a otro jugador,S/N?");
r=getchar();
}while(r!='N');
}
