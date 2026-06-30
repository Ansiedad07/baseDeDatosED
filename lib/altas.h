#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Altas(struct Persona **ptr){
    struct Persona *ptrNew;
    struct Persona *ptrAux = *ptr;

    char nombreTemp[100];
    char carreraTemp[100];

    ptrNew = malloc(sizeof(struct Persona));

    if(ptrNew == NULL){
        printf("Error al asignar memoria.\n");
        return;
    }

    ptrNew->ptrSig = NULL;

    ptrNew->ptrAlum = malloc(sizeof(struct Alumno));

    if(ptrNew->ptrAlum == NULL){
        printf("Error al asignar memoria para Alumno.\n");
        free(ptrNew);
        return;
    }

    /* Limpiar buffer antes de fgets */
    while(getchar() != '\n');

    /* Nombre */
    printf("\nNombre: ");
    fgets(nombreTemp, sizeof(nombreTemp), stdin);

    nombreTemp[strcspn(nombreTemp, "\n")] = '\0';

    ptrNew->nombre = malloc(strlen(nombreTemp)+1);

    if(ptrNew->nombre == NULL){
        printf("Error al asignar memoria.\n");
        free(ptrNew->ptrAlum);
        free(ptrNew);
        return;
    }

    strcpy(ptrNew->nombre, nombreTemp);

    printf("Edad: ");
    scanf("%d",&ptrNew->edad);

    printf("Genero (M/F): ");
    scanf(" %c",&ptrNew->genero);

    printf("Fecha nacimiento (DD/MM/AA): ");
    scanf("%s",ptrNew->fn);

    printf("Matricula: ");
    scanf("%s",ptrNew->ptrAlum->matricula);

    while(getchar()!='\n');

    /* Carrera */
    printf("Carrera: ");
    fgets(carreraTemp,sizeof(carreraTemp),stdin);
    carreraTemp[strcspn(carreraTemp,"\n")] = '\0';
    ptrNew->ptrAlum->carrera = malloc(strlen(carreraTemp)+1);

    if(ptrNew->ptrAlum->carrera == NULL){
        printf("Error al asignar memoria.\n");
        free(ptrNew->nombre);
        free(ptrNew->ptrAlum);
        free(ptrNew);
        return;
    }
    strcpy(ptrNew->ptrAlum->carrera,carreraTemp);

    printf("Semestre: ");
    scanf("%d",&ptrNew->ptrAlum->semestre);

    printf("Correo institucional: ");
    scanf("%s",ptrNew->ptrAlum->correoi);

    printf("\nCalificaciones:\n");
    for(int i=0;i<5;i++){
        printf("\nMateria %d\n",i+1);
        for(int j=0;j<5;j++){
            printf("Calificacion %d: ",j+1);
            scanf("%f",&ptrNew->ptrAlum->calif[i][j]);
        }
    }

    if(*ptr==NULL){
        *ptr=ptrNew;
    }else{
        while(ptrAux->ptrSig!=NULL){
            ptrAux=ptrAux->ptrSig;
        }
        ptrAux->ptrSig=ptrNew;
    }

    printf("\nRegistro agregado correctamente.\n");
}