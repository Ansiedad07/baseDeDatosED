#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Altas(struct Persona **ptr);

void Altas(struct Persona **ptr){
    struct Persona *ptrNew;
    struct Persona *ptrAux = *ptr;

    char nombreTemp[100];
    char carreraTemp[100];

    ptrNew = (struct Persona *)malloc(sizeof(struct Persona));

    if(ptrNew == NULL){
        printf("Error al asignar memoria para Persona.\n");
        return;
    }

    ptrNew->ptrSig = NULL;

    /* Reservar memoria para Alumno */
    ptrNew->ptrAlum = (struct Alumno *)malloc(sizeof(struct Alumno));

    if(ptrNew->ptrAlum == NULL){
        printf("Error al asignar memoria para Alumno.\n");
        free(ptrNew);
        return;
    }

    /* ========= DATOS PERSONA ========= */

    printf("\nNombre: ");
    scanf(" %[^\n]", nombreTemp);
    ptrNew->nombre = (char *)malloc(strlen(nombreTemp) + 1);

    if(ptrNew->nombre == NULL){
        printf("Error al asignar memoria.\n");
        free(ptrNew->ptrAlum);
        free(ptrNew);
        return;
    }

    strcpy(ptrNew->nombre, nombreTemp);

   printf("Ingrese la edad: ");
	scanf("%d", &ptrNew->edad);

	printf("Ingrese el genero (M/F): ");
	scanf(" %c", &ptrNew->genero);

	printf("Ingrese la fecha de nacimiento (DD/MM/AA): ");
	scanf("%s", ptrNew->fn);

    /* ========= DATOS ALUMNO ========= */
    printf("Matricula: ");
    scanf("%s", ptrNew->ptrAlum->matricula);

    printf("Carrera: ");
    scanf(" %[^\n]", carreraTemp);

    ptrNew->ptrAlum->carrera = (char *)malloc(strlen(carreraTemp) + 1);

    if(ptrNew->ptrAlum->carrera == NULL){
        printf("Error al asignar memoria.\n");

        free(ptrNew->nombre);
        free(ptrNew->ptrAlum);
        free(ptrNew);
        return;
    }

    strcpy(ptrNew->ptrAlum->carrera, carreraTemp);

    printf("Semestre: ");
    scanf("%d", &ptrNew->ptrAlum->semestre);

    printf("Correo institucional: ");
    scanf("%22s", ptrNew->ptrAlum->correoi);

    /* ========= CALIFICACIONES ========= */

    printf("\nIngrese las calificaciones:\n");

    for(int i = 0; i < 5; i++){

        printf("\nMateria %d\n", i + 1);

        for(int j = 0; j < 5; j++){

            printf("Calificacion %d: ", j + 1);
            scanf("%f", &ptrNew->ptrAlum->calif[i][j]);
        }
    }

    /* ========= INSERTAR EN COLA ========= */

    if(*ptr == NULL){
        *ptr = ptrNew;
    } else {
        while(ptrAux->ptrSig != NULL){
            ptrAux = ptrAux->ptrSig;
        }
        ptrAux->ptrSig = ptrNew;
    }

    printf("\nRegistro agregado correctamente.\n");
}