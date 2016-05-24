#include "Cronista.h"
#include <stdio.h>
#include <stdlib.h>
#include "fichero.h"

void listarEquipos(Equipo *equipos){
int i,n;
n=nEquipos();

for(i=0;i<n;i++){
    printf("Equipo %s:",equipos[i].codigo);
    printf("%s\n",equipos[i].nombre);
}
}

void valorarEquipos(Equipo *equipos,Jugador *jugadores){
int i=0,n,t,p,valor;
char j[3],c[3],r;
n=nEquipos();
t=nJugadores();
for(i=0;i<n;i++){
    printf("Equipo %s:",equipos[i].codigo);
    printf("%s\n",equipos[i].nombre);
}
printf("Introduzca el codigo del equipo a valorar:");
gets(j);
for(p=0;p<t;){
    if(strcmp(jugadores[p].codigo_equipo,j)==0){
    printf("%s %s %d\n",jugadores[p].codigo,jugadores[p].nombre,jugadores[p].valoracion);
    p++;
}else{
p++;

}
}
do{
printf("\nIntroduzca el codigo del jugador,al que desea modificar la valoracion:");
fflush(stdin);
gets(c);
for(p=0;p<t;){
if(strcmp(jugadores[p].codigo_equipo,j)==0 && strcmp(jugadores[p].codigo,c)==0){
printf("Introduzca la nueva valoracion:");
scanf("%d",&valor);
jugadores[p].valoracion=jugadores[p].valoracion+valor;
//Insertar Nuevo Modulo de GUARDARDATOS//
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
