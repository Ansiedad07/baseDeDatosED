#ifndef ARBOLPERSONA_H
#define ARBOLPERSONA_H

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
    struct Alumno *alumno;
    struct Persona *izq;
    struct Persona *der;
};

int menu(void) {
    int op;
    printf("\n--- Menu Arbol de Personas ---\n");
    printf("1. Añadir persona\n");
	printf("2. Mostrar persona\n");
	printf("3. Eliminar persona\n");
    printf("4. Salir\n");
    printf("Opcion: ");
    scanf("%d", &op);
    return op;
}

struct Persona* crearPersona(void) {
    struct Persona *ptrTemp;
	char nombre[100];
    ptrTemp = (struct Persona*)malloc(sizeof(struct Persona));
    if (ptrTemp == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        return NULL;
    }

    ptrTemp->alumno = NULL;
    ptrTemp->izq = NULL;
    ptrTemp->der = NULL;

    printf("Ingrese el nombre: ");
	fgets(nombre, sizeof(nombre), stdin);
	ptrTemp->nombre = (char*)malloc(sizeof(strlen(nombre) + 1));

    printf("Ingrese la edad: ");
    scanf("%d", &ptrTemp->edad);

    printf("Ingrese el genero (M/F): ");
    scanf(" %c", &ptrTemp->genero);

    printf("Ingrese la fecha de nacimiento (DDMMAA): ");
    scanf("%s", ptrTemp->fn);

    return ptrTemp;
}

void mostrarPersonas(struct Persona *raiz) {
    if (raiz != NULL){
		mostrarPersonas(raiz->izq);
		printf("Nombre: %s | Edad: %d | Genero: %c\n", raiz->nombre, raiz->edad, raiz->genero);
		mostrarPersonas(raiz->der);
	}
}

void eliminarPersona(struct Persona *nodo) {
    if (nodo == NULL)
        return;

    eliminarPersona(nodo->izq);
    eliminarPersona(nodo->der);

    if (nodo->nombre != NULL)
        free(nodo->nombre);

    free(nodo);
}

#endif
