#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Alumno {
    char matricula[10];
    char *carrera;
    int semestre;
    char correoi[23];
    float calif[5][5];
};

struct Persona {
    char *nombre;
    int edad;
    char genero;
    char fn[8];
    struct Alumno *ptrAlum;
    struct Persona *ptrSig;
};

#include "lib/menus.h"
#include "lib/altas.h"
#include "lib/bajas.h"
#include "lib/mostrar.h"

int main(void) {
    struct Persona *ptr = NULL;
    int opcion;

    do {
        opcion = menuPrincipal();

        switch (opcion) {
        case 1:
            menuAltas(&ptr);
            break;
		case 2:
			menuBajas(&ptr);
            break;
		case 3:
            menuMostrar(ptr);
            break;
		case 4:
			menuFuncionesEspeciales(ptr);
			break;
        case 5:
            printf("Saliendo...\n");
			while (ptr != NULL) {
				struct Persona *temp = ptr;
				ptr = ptr->ptrSig;
				if (temp->nombre != NULL)
					free(temp->nombre);
				if (temp->ptrAlum != NULL)
					free(temp->ptrAlum);
				free(temp);
			}
            break;
        default:
		printf("Opcion no valida.\n");
        }
    } while (opcion != 5);

    return 0;
}
