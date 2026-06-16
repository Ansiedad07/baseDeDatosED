#include <stdio.h>
#include <stdlib.h>

void Bajas(struct Persona **);

void Bajas(struct Persona **ptr){
	if (*ptr == NULL) {
		printf("La cola esta vacia.\n");
		return;
	}

	struct Persona *temp = *ptr;
	*ptr = temp->ptrSig;

	printf("Eliminando a: %s\n", temp->nombre);

	if (temp->nombre != NULL)
		free(temp->nombre);
	if (temp->ptrAlum != NULL)
		free(temp->ptrAlum);
	free(temp);

	printf("Persona eliminada.\n");
}
