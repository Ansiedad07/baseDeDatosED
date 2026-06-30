#include <stdio.h>
void MostrarRegistro(struct Persona *ptr);
void MostrarTodas(struct Persona *ptr);
void MostrarPorCarrera(struct Persona *ptr);
void MostrarPorSemestre(struct Persona *ptr);
void MostrarPorCarreraYSemestre(struct Persona *ptr);
void MostrarPorNombre(struct Persona *ptr);
void MostrarPorMatricula(struct Persona *ptr);
void menuMostrar(struct Persona *ptr);

/* FUNCION AUXILIAR */

void MostrarRegistro(struct Persona *ptr){

    printf("\n----------------------------\n");

    printf("Nombre: %s\n", ptr->nombre);
    printf("Edad: %d\n", ptr->edad);
    printf("Genero: %c\n", ptr->genero);
    printf("Fecha de nacimiento: %s\n", ptr->fn);

    if(ptr->ptrAlum != NULL){

        printf("\n--- Datos del Alumno ---\n");

        printf("Matricula: %s\n", ptr->ptrAlum->matricula);
        printf("Carrera: %s\n", ptr->ptrAlum->carrera);
        printf("Semestre: %d\n", ptr->ptrAlum->semestre);
        printf("Correo: %s\n", ptr->ptrAlum->correoi);

        printf("\nCalificaciones:\n");

        for(int m = 0; m < 5; m++){

            printf("Materia %d: ", m + 1);

            for(int p = 0; p < 5; p++){
                printf("%.1f ", ptr->ptrAlum->calif[m][p]);
            }

            printf("\n");
        }
    }

    printf("----------------------------\n");
}

/* MOSTRAR TODAS */

void MostrarTodas(struct Persona *ptr){

    if(ptr == NULL){
        printf("La cola esta vacia.\n");
        return;
    }

    int i = 1;

    while(ptr != NULL){

        printf("\nRegistro %d\n", i);

        MostrarRegistro(ptr);

        ptr = ptr->ptrSig;
        i++;
    }
}

/* MOSTRAR POR CARRERA */

void MostrarPorCarrera(struct Persona *ptr){

    char carrera[100];
    int encontrado = 0;

    printf("Carrera a buscar: ");
    scanf(" %[^\n]", carrera);

    while(ptr != NULL){

        if(ptr->ptrAlum != NULL &&
           strcmp(ptr->ptrAlum->carrera, carrera) == 0){

            MostrarRegistro(ptr);
            encontrado = 1;
        }

        ptr = ptr->ptrSig;
    }

    if(!encontrado)
        printf("\nNo se encontraron registros.\n");
}

/* MOSTRAR POR SEMESTRE */

void MostrarPorSemestre(struct Persona *ptr){

    int semestre;
    int encontrado = 0;

    printf("Semestre a buscar: ");
    scanf("%d", &semestre);

    while(ptr != NULL){

        if(ptr->ptrAlum != NULL &&
           ptr->ptrAlum->semestre == semestre){

            MostrarRegistro(ptr);
            encontrado = 1;
        }

        ptr = ptr->ptrSig;
    }

    if(!encontrado)
        printf("\nNo se encontraron registros.\n");
}

/* MOSTRAR POR CARRERA Y SEMESTRE */

void MostrarPorCarreraYSemestre(struct Persona *ptr){

    char carrera[100];
    int semestre;
    int encontrado = 0;

    printf("Carrera: ");
    scanf(" %[^\n]", carrera);

    printf("Semestre: ");
    scanf("%d", &semestre);

    while(ptr != NULL){

        if(ptr->ptrAlum != NULL &&
           strcmp(ptr->ptrAlum->carrera, carrera) == 0 &&
           ptr->ptrAlum->semestre == semestre){

            MostrarRegistro(ptr);
            encontrado = 1;
        }

        ptr = ptr->ptrSig;
    }

    if(!encontrado)
        printf("\nNo se encontraron registros.\n");
}

/* MOSTRAR POR NOMBRE */

void MostrarPorNombre(struct Persona *ptr){

    char nombre[100];
    int encontrado = 0;

    printf("Nombre a buscar: ");
    scanf(" %[^\n]", nombre);

    while(ptr != NULL){

        if(strcmp(ptr->nombre, nombre) == 0){

            MostrarRegistro(ptr);
            encontrado = 1;
        }

        ptr = ptr->ptrSig;
    }

    if(!encontrado)
        printf("\nNo se encontraron registros.\n");
}

/* MOSTRAR POR MATRICULA */

void MostrarPorMatricula(struct Persona *ptr){

    char matricula[10];
    int encontrado = 0;

    printf("Matricula a buscar: ");
    scanf("%9s", matricula);

    while(ptr != NULL){

        if(ptr->ptrAlum != NULL &&
           strcmp(ptr->ptrAlum->matricula, matricula) == 0){

            MostrarRegistro(ptr);
            encontrado = 1;
        }

        ptr = ptr->ptrSig;
    }

    if(!encontrado)
        printf("\nNo se encontraron registros.\n");
}