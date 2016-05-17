#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include "fichero.h"

void crearPlantilla()
{
    char nombre[60];
    puts("¿Como desea llamar a la plantilla?");
    fgets(nombre, sizeof(nombre), stdin);
    printf("%s",nombre);
    Plantilla *plantillas=obtenerPlantillas();

}
