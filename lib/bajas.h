#include <stdio.h>
#include <stdlib.h>

/* PROTOTIPOS */

void BajaUna(struct Persona **ptr);
void BajaVarias(struct Persona **ptr);
void BajaTodas(struct Persona **ptr);

/* ELIMINAR UNA PERSONA */

void BajaUna(struct Persona **ptr){

    if(*ptr == NULL){
        printf("La cola esta vacia.\n");
        return;
    }

    struct Persona *temp = *ptr;

    *ptr = temp->ptrSig;

    printf("\nEliminando a: %s\n", temp->nombre);

    /* Liberar nombre */
    if(temp->nombre != NULL)
        free(temp->nombre);

    /* Liberar Alumno */
    if(temp->ptrAlum != NULL){

        if(temp->ptrAlum->carrera != NULL)
            free(temp->ptrAlum->carrera);

        free(temp->ptrAlum);
    }

    free(temp);

    printf("Persona eliminada correctamente.\n");
}

/* ELIMINAR VARIAS PERSONAS */

void BajaVarias(struct Persona **ptr){

    int cantidad;

    if(*ptr == NULL){
        printf("La cola esta vacia.\n");
        return;
    }

    printf("Cuantas personas desea eliminar: ");
    scanf("%d", &cantidad);

    if(cantidad <= 0){
        printf("Cantidad invalida.\n");
        return;
    }

    for(int i = 0; i < cantidad; i++){

        if(*ptr == NULL){
            printf("\nYa no hay mas personas en la cola.\n");
            break;
        }

        BajaUna(ptr);
    }
}

/* ELIMINAR TODA LA COLA */

void BajaTodas(struct Persona **ptr){

    if(*ptr == NULL){
        printf("La cola esta vacia.\n");
        return;
    }

    while(*ptr != NULL){
        BajaUna(ptr);
    }

    printf("\nToda la cola ha sido eliminada.\n");
}