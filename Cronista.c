#include "Cronista.h"
#include <stdio.h>
#include <stdlib.h>
#include "fichero.h"

int ppal(){
int op;
Equipo *equipo=obtenerEquipos();
Jugador *jugadores=obtenerJugadores();

printf("Introduzca la operacion a realizar:\n 1.-Listar Equipos.\n 2.-Valorar Jugadores.\n 3.-Salir del programa.\n");
scanf("%d",&op);
if(op==1) listarEquipos2(equipo);
if (op==2) valorarEquipos(equipo,jugadores);




return 0;
}

void listarEquipos2(Equipo *equipos){
int i,n;
n=nEquipos();

for(i=0;i<n;i++){
    printf("Equipo %s:",equipos[i].codigo);
    printf("%s\n",equipos[i].nombre);
}
}

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
printf("\nIntroduzca el codigo del jugador,al que desea modificar la valoracion:");
fflush(stdin);
gets(c);
for(p=0;p<t;){
if(strcmp(jugadores[p].codigo_equipo,j)==0 && strcmp(jugadores[p].codigo,c)==0){
printf("Introduzca la nueva valoracion:");
scanf("%d",&valor);
jugadores[p].valoracion=jugadores[p].valoracion+valor;
guardarDatosJugador(jugadores,n);
printf("%s %s %d\n",jugadores[p].codigo,jugadores[p].nombre,jugadores[p].valoracion);
p++;
}else{
p++;
}
}
fflush(stdin);
printf("¿Quieres valorar a otro jugador,S/N?");
r=getchar();
}while(r!='N');
}
