#include "Cronista.h"
#include <stdio.h>
#include <stdlib.h>
#include "fichero.h"

void listarEquipos(Equipo *equipos){
int i,n;
n=nEquipos();

for(i=0;i<n;i++){
    printf("Equipo %s:",equipos[i].codigo);
    printf("%s",equipos[i].nombre);
}
}

void valorarEquipos(Equipo *equipos,Jugador *jugadores){
int i=0,n,t,j=0;
n=nEquipos();
t=nJugadores();
while(i<n && j<t){



}








}
