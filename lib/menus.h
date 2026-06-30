#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menuPrincipal(void);
// Altas
void menuAltas(struct Persona **ptr);
void Altas(struct Persona **ptr);
// Bajas
void menuBajas(struct Persona **ptr);
void BajaUna(struct Persona **ptr);
void BajaVarias(struct Persona **ptr);
void BajaTodas(struct Persona **ptr);
// Mostrar
void menuMostrar(struct Persona *ptr);
void MostrarTodas(struct Persona *ptr);
void MostrarPorCarrera(struct Persona *ptr);
void MostrarPorSemestre(struct Persona *ptr);
void MostrarPorCarreraYSemestre(struct Persona *ptr);
void MostrarPorNombre(struct Persona *ptr);
void MostrarPorMatricula(struct Persona *ptr);
// Funciones Especiales
void menuFuncionesEspeciales(struct Persona *ptr);

int menuPrincipal(void) {
    int op;
    printf("Menú principal\n");
    printf("1. Altas\n");
    printf("2. Bajas\n");
    printf("3. Mostrar\n");
    printf("4. Funciones Especiales\n");
    printf("5. Salir\n");
    printf("Opcion: ");
    scanf("%d", &op);
    return op;
}

void menuAltas(struct Persona **ptr) {
    int op;
    do {
        printf("\n--- ALTAS ---\n");
        printf("1. Una Persona\n");
        printf("2. Varias Personas\n");
        printf("3. Volver\n");
        printf("Opcion: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
				Altas(ptr);
				break;
            case 2: {
                char cont;
                do {
					Altas(ptr);
					printf("¿Desea registrar otra persona? (S/N): ");
					scanf(" %c", &cont);
				}while (cont == 'S' || cont == 's');
                break;
            }
            case 3:
				break;
            default:
				printf("Opcion no valida.\n");
        }
    } while (op != 3);
}

void menuMostrar(struct Persona *ptr) {
    int op;
    do {
        printf("\n--- MOSTRAR ---\n");
        printf("1. Todas\n");
        printf("2. Por Carrera\n");
        printf("3. Por Semestre\n");
        printf("4. Por Carrera y Semestre\n");
        printf("5. Por Nombre\n");
        printf("6. Por Matricula\n");
        printf("7. Volver\n");
        printf("Opcion: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
				MostrarTodas(ptr);
				break;
            case 2:
				MostrarPorCarrera(ptr);
				break;
            case 3:
				MostrarPorSemestre(ptr);
				break;
            case 4:
				MostrarPorCarreraYSemestre(ptr);
				break;
            case 5:
				MostrarPorNombre(ptr);
				break;
            case 6:
				MostrarPorMatricula(ptr);
				break;
            case 7:
				break;
            default:
				printf("Opcion no valida.\n");
        }
    } while (op != 7);
}

void menuBajas(struct Persona **ptr) {
    int op;
    do {
        printf("\n--- BAJAS ---\n");
        printf("1. Una Persona (primera)\n");
        printf("2. Varias Personas\n");
        printf("3. Todas\n");
        printf("4. Volver\n");
        printf("Opcion: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
				BajaUna(ptr);
				break;
            case 2:
				BajaVarias(ptr);
				break;
            case 3:
				BajaTodas(ptr);
				break;
            case 4:
				break;
            default:
				printf("Opcion no valida.\n");
        }
    } while (op != 4);
}

void menuFuncionesEspeciales(struct Persona *ptr) {
    int op;
    do {
        printf("\n--- FUNCIONES ESPECIALES ---\n");
        printf("1. Calificaciones\n");
        printf("2. Modificar (por matricula)\n");
        printf("3. Volver\n");
        printf("Opcion: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
				//menuCalificaciones(ptr);
				break;
            case 2:
				//ModificarPorMatricula(ptr);
				break;
            case 3:
				break;
            default:
				printf("Opcion no valida.\n");
        }
    } while (op != 3);
}
