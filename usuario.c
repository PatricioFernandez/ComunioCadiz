#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include "fichero.h"

void crearPlantilla()
{
    char nombre[60];
    puts("¿Como desea llamar a la plantilla?");
    fgets(nombre, sizeof(nombre), stdin);

    Plantilla *plantillas=obtenerPlantillas();
    int numero= nPlantillas();
    printf("%i",numero);

    int contador;
    for (contador=0;contador<numero;contador++)
    {
        printf("%s\n CONTADOR %i",plantillas[contador].nombre,contador);
    }


}
