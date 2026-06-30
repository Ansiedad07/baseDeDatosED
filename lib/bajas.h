#include <stdio.h>
#include <stdlib.h>

void Bajas(struct Persona **);
void bajaUnaPersona(struct Persona **);
void bajaVariasPersonas(struct Persona **);
void bajaTodasPersonas(struct Persona **);

void bajaUnaPersona(struct Persona **ptr) {
	if (*ptr == NULL) {
		printf("La cola esta vacia.\n");
		return;
	}

	struct Persona *temp = *ptr;
	*ptr = temp->ptrSig;

	printf("Eliminando a: %s\n", temp->nombre);

	if (temp->nombre != NULL)
		free(temp->nombre);
	if (temp->ptrAlum != NULL) {
		if (temp->ptrAlum->carrera != NULL)
			free(temp->ptrAlum->carrera);
		free(temp->ptrAlum);
	}
	free(temp);

	printf("Persona eliminada.\n");
}

void bajaVariasPersonas(struct Persona **ptr) {
	char continuar;
	do {
		bajaUnaPersona(ptr);
		if (*ptr != NULL) {
			printf("Desea eliminar otra persona? (s/n): ");
			scanf(" %c", &continuar);
		} else {
			printf("La cola esta vacia.\n");
			continuar = 'n';
		}
	} while ((continuar == 's' || continuar == 'S') && *ptr != NULL);
}

void bajaTodasPersonas(struct Persona **ptr) {
	if (*ptr == NULL) {
		printf("La cola esta vacia.\n");
		return;
	}

	while (*ptr != NULL) {
		struct Persona *temp = *ptr;
		*ptr = temp->ptrSig;

		if (temp->nombre != NULL)
			free(temp->nombre);
		if (temp->ptrAlum != NULL) {
			if (temp->ptrAlum->carrera != NULL)
				free(temp->ptrAlum->carrera);
			free(temp->ptrAlum);
		}
		free(temp);
	}

	printf("Todas las personas han sido eliminadas.\n");
}

void Bajas(struct Persona **ptr) {
	int op;
	do {
		op = menuBajas();
		switch (op) {
			case 1:
				bajaUnaPersona(ptr);
				break;
			case 2:
				bajaVariasPersonas(ptr);
				break;
			case 3:
				bajaTodasPersonas(ptr);
				break;
			case 4:
				break;
			default:
				printf("Opcion no valida.\n");
		}
	} while (op != 4);
}
