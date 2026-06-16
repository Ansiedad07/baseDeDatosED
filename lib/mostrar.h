#include <stdio.h>

void Mostrar(struct Persona *);

void Mostrar(struct Persona *ptr){
	if (ptr == NULL) {
		printf("La cola esta vacia.\n");
		return;
	}

	printf("\n--- Cola de personas ---\n");
	int i = 1;
	while (ptr != NULL) {
		printf("%d. %s | Edad: %d | Genero: %c | FN: %s\n", i, ptr->nombre, ptr->edad, ptr->genero, ptr->fn);
		ptr = ptr->ptrSig;
		i++;
	}
}
