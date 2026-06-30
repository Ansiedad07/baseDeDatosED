#include <stdio.h>
#include <string.h>

void MostrarRegistro(struct Persona *ptr);
void MostrarTodas(struct Persona *ptr);
void MostrarPorCarrera(struct Persona *ptr);
void MostrarPorSemestre(struct Persona *ptr);
void MostrarPorCarreraYSemestre(struct Persona *ptr);
void MostrarPorNombre(struct Persona *ptr);
void MostrarPorMatricula(struct Persona *ptr);

/* Función auxiliar */
void MostrarRegistro(struct Persona *ptr){
    printf("\n----------------------------\n");
    printf("Nombre: %s\n",ptr->nombre);
    printf("Edad: %d\n",ptr->edad);
    printf("Genero: %c\n",ptr->genero);
    printf("Fecha de nacimiento: %s\n",ptr->fn);

    if(ptr->ptrAlum!=NULL){
        printf("\n--- Datos del Alumno ---\n");
        printf("Matricula: %s\n",ptr->ptrAlum->matricula);
        printf("Carrera: %s\n",ptr->ptrAlum->carrera);
        printf("Semestre: %d\n",ptr->ptrAlum->semestre);
        printf("Correo: %s\n",ptr->ptrAlum->correoi);

        printf("\nCalificaciones:\n");
        for(int m=0;m<5;m++){
            printf("Materia %d: ",m+1);
            for(int p=0;p<5;p++){
                printf("| %.1f |",ptr->ptrAlum->calif[m][p]);
            }
            printf("\n");
        }
    }

    printf("----------------------------\n");
}

/* Mostrar todas */
void MostrarTodas(struct Persona *ptr){
    int i=1;
    if(ptr==NULL){
        printf("La cola esta vacia.\n");
        return;
    }

    while(ptr!=NULL){
        printf("\nRegistro %d\n",i);
        MostrarRegistro(ptr);
        ptr=ptr->ptrSig;
        i++;
    }
}

/* Mostrar por carrera */
void MostrarPorCarrera(struct Persona *ptr){
    char carrera[100];
    int encontrado=0;

    printf("Carrera a buscar: ");
    fgets(carrera,sizeof(carrera),stdin);
    carrera[strcspn(carrera,"\n")] = '\0';

    while(ptr!=NULL){
        if(ptr->ptrAlum!=NULL &&
           strcmp(ptr->ptrAlum->carrera,carrera)==0){
            MostrarRegistro(ptr);
            encontrado=1;
        }
        ptr=ptr->ptrSig;
    }

    if(!encontrado){
        printf("\nNo se encontraron registros.\n");
    }
}

/* Mostrar por semestre */
void MostrarPorSemestre(struct Persona *ptr){
    int semestre;
    int encontrado=0;

    printf("Semestre a buscar: ");
    scanf("%d",&semestre);

    while(ptr!=NULL){
        if(ptr->ptrAlum!=NULL &&
           ptr->ptrAlum->semestre==semestre){
            MostrarRegistro(ptr);
            encontrado=1;
        }

        ptr=ptr->ptrSig;
    }

    if(!encontrado){
        printf("\nNo se encontraron registros.\n");
    }

    while(getchar()!='\n');
}

/* Mostrar por carrera y semestre */
void MostrarPorCarreraYSemestre(struct Persona *ptr){
    char carrera[100];
    int semestre;
    int encontrado=0;

    printf("Carrera: ");
    fgets(carrera,sizeof(carrera),stdin);
    carrera[strcspn(carrera,"\n")] = '\0';

    printf("Semestre: ");
    scanf("%d",&semestre);
    while(ptr!=NULL){
        if(ptr->ptrAlum!=NULL &&
           strcmp(ptr->ptrAlum->carrera,carrera)==0 &&
           ptr->ptrAlum->semestre==semestre){
            MostrarRegistro(ptr);
            encontrado=1;
        }
        ptr=ptr->ptrSig;
    }

    if(!encontrado){
        printf("\nNo se encontraron registros.\n");
    }

    while(getchar()!='\n');
}

/* Mostrar por nombre */
void MostrarPorNombre(struct Persona *ptr){
    char nombre[100];
    int encontrado=0;

    printf("Nombre a buscar: ");
    fgets(nombre,sizeof(nombre),stdin);
    nombre[strcspn(nombre,"\n")] = '\0';

    while(ptr!=NULL){
        if(strcmp(ptr->nombre,nombre)==0){
            MostrarRegistro(ptr);
            encontrado=1;
        }
        ptr=ptr->ptrSig;
    }

    if(!encontrado){
        printf("\nNo se encontraron registros.\n");
    }
}

/* Mostrar por matricula */
void MostrarPorMatricula(struct Persona *ptr){
    char matricula[10];
    int encontrado=0;

    printf("Matricula a buscar: ");
    fgets(matricula,sizeof(matricula),stdin);
    matricula[strcspn(matricula,"\n")] = '\0';

    while(ptr!=NULL){
        if(ptr->ptrAlum!=NULL &&
           strcmp(ptr->ptrAlum->matricula,matricula)==0){
            MostrarRegistro(ptr);
            encontrado=1;
        }

        ptr=ptr->ptrSig;
    }

    if(!encontrado){
        printf("\nNo se encontraron registros.\n");
    }
}