#include <stdio.h>
#include <stdlib.h>

struct Persona{
	char *nombre;
	int edad;
	char genero;
	char fn[8];
	struct Alumno *alumno;
	struct Persona *persona;
};

struct Alumno{
	char matricula[10];
	char *carrera;
	int semestre;
	char correoi[23];
	float calif[5][5];
};

struct Persona * crearNodo(void);

int main(void){
	struct arbol *raiz = NULL, *ptrTemp = NULL, *ptrAux = NULL;
	int opcion, op2, insertado;

	do{
		opcion = menu();
		switch (opcion){
		case 1:
			break;
		default:
			break;
		}
	} while (opcion != 4);

	return 0;
}

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