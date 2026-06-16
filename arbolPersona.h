

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

struct Persona* crearPersona(void) {
    struct Persona *ptrTemp;
    char nombre[100];

    ptrTemp = (struct Persona*)malloc(sizeof(struct Persona));
    if (ptrTemp == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        return NULL;
    }

    ptrTemp->ptrAlum = NULL;
    ptrTemp->ptrSig = NULL;

    printf("Ingrese el nombre: ");
    while (getchar() != '\n');
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = '\0';
    ptrTemp->nombre = (char*)malloc((strlen(nombre) + 1) * sizeof(char));
    strcpy(ptrTemp->nombre, nombre);

    printf("Ingrese la edad: ");
    scanf("%d", &ptrTemp->edad);

    printf("Ingrese el genero (M/F): ");
    scanf(" %c", &ptrTemp->genero);

    printf("Ingrese la fecha de nacimiento (DD/MM/AA): ");
    scanf("%s", ptrTemp->fn);

    return ptrTemp;
}

void Altas(struct Persona **frente, struct Persona **final) {
    struct Persona *nuevo = crearPersona();
    if (nuevo == NULL) return;

    if (*final == NULL) {
        *frente = nuevo;
        *final = nuevo;
    } else {
        (*final)->ptrSig = nuevo;
        *final = nuevo;
    }
    printf("Persona agregada a la cola.\n");
}

void Mostrar(struct Persona *frente) {
    if (frente == NULL) {
        printf("La cola esta vacia.\n");
        return;
    }

    printf("\n--- Cola de personas ---\n");
    int i = 1;
    while (frente != NULL) {
        printf("%d. %s | Edad: %d | Genero: %c\n",
               i, frente->nombre, frente->edad, frente->genero);
        frente = frente->ptrSig;
        i++;
    }
}