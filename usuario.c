#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include "fichero.h"

void crearPlantilla()
{
    int i,n;
    Equipo* equipo=obtenerEquipos();
    n=7;
    for(i=0;i<n;i++)
    {
        printf("\n%s",equipo[i].nombre);
    }
}
