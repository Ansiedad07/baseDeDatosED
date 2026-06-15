#include "arbolPersona.h"

int main(void) {
	struct Persona *raiz = NULL;
    int opcion;

    do {
        opcion = menu();

        switch (opcion) {
        case 1: {
            struct Persona *nuevo = crearPersona();
            if (nuevo != NULL) {
                printf("\nPersona creada:\n");
                printf("Nombre: %s | Edad: %d | Genero: %c\n",  nuevo->nombre, nuevo->edad, nuevo->genero);
                eliminarPersona(nuevo);
            }
            break;
        }
		case 2:
			printf("Personas en el arbol: ");
			if(raiz == NULL){
				printf("No hay personas para mostrar");
			} else {
				mostrarPersonas(raiz);
			}
			break;
        case 4:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion no valida.\n");
        }
    } while (opcion != 4);

    return 0;
}
