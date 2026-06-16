#include "lib/menus.h"
#include "lib/altas.h"
#include "arbolPersona.h"
#include <stdio.h>

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

int main(void) {
    struct Persona *ptr = NULL;

    int opcion;

    do {
        opcion = menuPrincipal();

        switch (opcion) {
        case 1:
            Altas(&ptr);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion no valida.\n");
        }
    } while (opcion != 4);

    while (frente != NULL) {
        struct Persona *temp = frente;
        frente = frente->ptrSig;
        if (temp->nombre != NULL)
            free(temp->nombre);
        free(temp);
    }

    return 0;
}
