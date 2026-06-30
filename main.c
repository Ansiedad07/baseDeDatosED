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
            Altas(&ptr);
            break;
        case 2:
            Bajas(&ptr);
            break;
        case 3:
            Mostrar(ptr);
            break;
        case 4:
            printf("Funciones Especiales - En desarrollo\n");
            break;
        case 5:
            printf("Saliendo...\n");
            while (ptr != NULL) {
                struct Persona *temp = ptr;
                ptr = ptr->ptrSig;
                if (temp->nombre != NULL)
                    free(temp->nombre);
                if (temp->ptrAlum != NULL) {
                    if (temp->ptrAlum->carrera != NULL)
                        free(temp->ptrAlum->carrera);
                    free(temp->ptrAlum);
                }
                free(temp);
            }
            break;
        default:
            printf("Opcion no valida.\n");
        }
    } while (opcion != 5);

    return 0;
}
