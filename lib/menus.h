#include <stdio.h>

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
    printf("\n--- Menú principal ---\n");
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
        printf("\n--- Altas ---\n");
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
        printf("\n--- Mostrar ---\n");
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
        printf("\n--- Bajas ---\n");
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
        printf("\n--- Funciones Especiales ---\n");
        printf("1. Modificar (por matricula)\n");
        printf("2. Calificaciones\n");
        printf("3. Volver\n");
        printf("Opcion: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
				printf("En mantenimiento, disculpe las molestias.\n");
				//menuModificar(ptr);
				break;
			case 2:
				printf("En mantenimiento, disculpe las molestias.\n");
				//menuCalificaciones(ptr);
				break;
            case 3:
				break;
            default:
				printf("Opcion no valida.\n");
        }
    } while (op != 3);
}

/*void menuModificar(struct Persona *ptr) {
    char matricula[10];
    struct Persona *alumno = NULL;

    printf("\nIngrese la matricula del alumno: ");
    scanf("%9s", matricula);

    alumno = buscarPorMatricula(ptr, matricula);

    if (alumno == NULL) {
        printf("No se encontro un alumno con matricula '%s'.\n", matricula);
        return;
    } else {
		printf("\n--- MODIFICAR ---\n");
		printf("Alumno: %s - %s\n", alumno->nombre, alumno->ptrAlum->matricula);    int op;

		do {
			printf("\n1. Calificaciones del alumno\n");
			printf("2. Datos\n");
			printf("3. Volver\n");
			printf("Opcion: ");
			scanf("%d", &op);
			switch (op) {
				case 1:
                	menuCalificacionesAlumno(alumno);
                	break;
				case 2:
                	menuDatos(alumno);
                	break;
				case 3:
                	break;
				default:
                	printf("Opcion no valida.\n");
			}
		} while (op != 3);
	}
}*/