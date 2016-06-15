#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichero.h"
#include "administrador.h"

/*
 * 
 * 
 */

// Cabecera: void registrar()
// Precondicion:
// Poscondicion: agrega un nuevo usuario con los datos introducidos por teclado
void registrar() {
    Usuario* u = obtenerUsuarios();
    int elementos = nUsuarios();
    char codigo[3];
    char nombre[21];
    char login[7];
    char pass[7];
    fflush(stdin);
    puts("Introduce codigo");
    fgets(codigo, 3, stdin);
    fflush(stdin);
    puts("Introduce nombre");
    fgets(nombre, 21, stdin);
    strtok(nombre, "\n");
    fflush(stdin);
    puts("Introduce login");
    fgets(login, 7, stdin);
    strtok(login, "\n");
    fflush(stdin);
    puts("Introduce password");
    fgets(pass, 7, stdin);
    strtok(pass, "\n");
    strcpy(u[elementos].codigo, codigo);
    strcpy(u[elementos].nombre, nombre);
    strcpy(u[elementos].tipo, "participante");
    strcpy(u[elementos].login, login);
    strcpy(u[elementos].pass, pass);
    elementos++;
    guardarDatosUsuario(u, elementos);
}

// Cabecera: void acceder(Usuario usuario)
// Precondicion:
// Poscondicion: muestra el menu correspondiente al tipo de usuario
void acceder(Usuario usuario) {
    Usuario *u = obtenerUsuarios();
    int elementos = nUsuarios();
    for (int i = 0; i < elementos; i++) {
        if (strcmp(u[i].codigo, usuario.codigo) == 0 && strcmp(u[i].tipo, "administrador") == 0) {
            menuAdministrador();
        } else if (strcmp(u[i].codigo, usuario.codigo) == 0 && strcmp(u[i].tipo, "participante") == 0) {
            //MENU PRINCIPAL PARTICIPANTE
        } else if (strcmp(u[i].codigo, usuario.codigo) == 0 && strcmp(u[i].tipo, "cronista") == 0) {
            //MENU PRINCIPAL CRONISTA
        }
    }
}

int main() {
    char opcion;
    int continuar = 1;
    do {
        puts("MENU LFMP");
        printf("1.- Registrar\n");
        printf("2.- Acceder\n");
        opcion = getchar();
        if (opcion == '1') {
            registrar();
        } else {
            char login[7];
            char pass[7];
            Usuario usuario;
            fflush(stdin);
            puts("Introduce login");
            fgets(login, 7, stdin);
            strtok(login, "\n");
            fflush(stdin);
            puts("Introduce password");
            fgets(pass, 7, stdin);
            strtok(pass, "\n");
            usuario = loguear(login, pass);
            if (strcmp(usuario.codigo, "00") == 0) {
                puts("Error al auntentificar.");
            } else {
                acceder(usuario);
                continuar = 0;
            }
        }
    } while (continuar == 1);
}

