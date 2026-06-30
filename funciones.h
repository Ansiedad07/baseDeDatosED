#include <stdio.h>
#include <stdlib.h>

struct Persona * crearNodo(void){
	struct Persona *ptrTemp;
	ptrTemp = (struct Persona *)malloc(sizeof(struct Persona));
	if(ptrTemp == NULL){
		printf("Error al asignar memoria.\n");
		return NULL;
	} else {
		printf("Ingrese el nombre: ");
		scanf("%d", &ptrTemp->nombre);
		return ptrTemp;
	}
}