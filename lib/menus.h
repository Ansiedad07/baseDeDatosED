#include <stdio.h>

int menuPrincipal(void);
void menuAltas(struct Persona **);
void menuMostrar(struct Persona *);
void menuBajas(struct Persona **);
void menuFuncionesEspeciales(struct Persona *);

int menuPrincipal(void) {
    int op;
    printf("Menú principal\n");
    printf("1. Altas\n");
    printf("2. Mostrar\n");
    printf("3. Bajas\n");
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
					printf("Otra? (S/N): ");
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
        printf("3. Reportes\n");
        printf("4. Volver\n");
        printf("Opcion: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
				menuCalificaciones(ptr);
				break;
            case 2:
				ModificarPorMatricula(ptr);
				break;
            case 3:
				menuReportes(ptr);
				break;
            case 4:
				break;
            default:
				printf("Opcion no valida.\n");
        }
    } while (op != 4);
}

void menuCalificaciones(struct Persona *ptr) {
    int op;
    do {
        printf("\n--- CALIFICACIONES ---\n");
        printf("1. Por Parcial\n");
        printf("2. Por Materia\n");
        printf("3. Datos de la Persona\n");
        printf("4. Datos del Alumno\n");
        printf("5. Volver\n");
        printf("Opcion: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
				CalificacionesPorParcial(ptr);
				break;
            case 2:
				CalificacionesPorMateria(ptr);
				break;
            case 3:
				DatosPersona(ptr);
				break;
            case 4:
				DatosAlumno(ptr);
				break;
            case 5:
				break;
            default:
				printf("Opcion no valida.\n");
        }
    } while (op != 5);
}

void menuReportes(struct Persona *ptr) {
    int op;
    do {
        printf("\n--- REPORTES ---\n");
        printf("1. Por Semestre\n");
        printf("2. Por Carrera\n");
        printf("3. Volver\n");
        printf("Opcion: ");
        scanf("%d", &op);
        switch (op) {
            case 1: menuReportesSemestre(ptr); break;
            case 2: menuReportesCarrera(ptr); break;
            case 3: break;
            default: printf("Opcion no valida.\n");
        }
    } while (op != 3);
}

void menuReportesSemestre(struct Persona *ptr) {
    int op;
    do {
        printf("\n--- REPORTES SEMESTRE ---\n");
        printf("1. Materia -> Aprobados/No Aprobados\n");
        printf("2. Materia -> Aprobaron parcial X\n");
        printf("3. Parcial -> Matricula + Materias aprobadas\n");
        printf("4. Parcial -> Alumnos sin materias reprobadas\n");
        printf("5. Volver\n");
        printf("Opcion: ");
        scanf("%d", &op);
        switch (op) {
            case 1: ReportesSemMateriaAprobados(ptr); break;
            case 2: ReportesSemMateriaParcial(ptr); break;
            case 3: ReportesSemParcialAprobadas(ptr); break;
            case 4: ReportesSemParcialSinReprobadas(ptr); break;
            case 5: break;
            default: printf("Opcion no valida.\n");
        }
    } while (op != 5);
}

void menuReportesCarrera(struct Persona *ptr) {
    int op;
    do {
        printf("\n--- REPORTES CARRERA ---\n");
        printf("1. Alumnos con 1 a 3 adeudos\n");
        printf("2. Alumnos con mas de 4 adeudos\n");
        printf("3. Volver\n");
        printf("Opcion: ");
        scanf("%d", &op);
        switch (op) {
            case 1: ReportesCarreraAdeudos1a3(ptr); break;
            case 2: ReportesCarreraAdeudosMas4(ptr); break;
            case 3: break;
            default: printf("Opcion no valida.\n");
        }
    } while (op != 3);
}