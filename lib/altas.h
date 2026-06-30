#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Altas(struct Persona **);

void Altas(struct Persona **ptr){
	struct Persona *ptrAux = *ptr;
	struct Persona *ptrNew;
	char nombre[100];

	ptrNew = (struct Persona*)malloc(sizeof(struct Persona));
	if (ptrNew == NULL) {
		printf("Error: no se pudo asignar memoria.\n");
		return;
	}

	ptrNew->ptrAlum = NULL;
	ptrNew->ptrSig = NULL;

	printf("Ingrese el nombre: ");
	scanf(" %[^\n]", nombre);
	ptrNew->nombre = (char*)malloc(strlen(nombre) + 1);
	if (ptrNew->nombre == NULL) {
		printf("Error: no se pudo asignar memoria.\n");
		free(ptrNew);
		return;
	}
	strcpy(ptrNew->nombre, nombre);

	printf("Ingrese la edad: ");
	scanf("%d", &ptrNew->edad);

	printf("Ingrese el genero (M/F): ");
	scanf(" %c", &ptrNew->genero);

	printf("Ingrese la fecha de nacimiento (DD/MM/AA): ");
	scanf("%s", ptrNew->fn);

	if (*ptr == NULL) {
		*ptr = ptrNew;
	} else {
		while (ptrAux->ptrSig != NULL)
			ptrAux = ptrAux->ptrSig;
		ptrAux->ptrSig = ptrNew;
	}

	printf("Persona agregada a la cola.\n");
}